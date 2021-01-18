#pragma once

/*
    reference: https://www.slideshare.net/iwiwi/2-12188757
               実装方法やTreapのアイデアなど.
               https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
               Treapをリストのように扱う方法や実装法, Monoidの載せ方など.
*/

#include <random>

namespace ebi {

template<
    class S,
    S (*op)(S, S),
    S (*e)(),
    class F,
    S (*mapping)(F, S),
    F (*composition)(F, F),
    F (*id)()>
struct ImplicitTreap {
private:
    struct Node {
        S val, acc;
        F lazy;
        int pri, cnt;
        bool rev;
        Node *lch, *rch;
        Node(S val, int pri) : val(val), acc(e()), lazy(id()), pri(pri), cnt(0),rev(false), lch(nullptr), rch(nullptr) { }
    };

    using node_ptr = Node*;

    node_ptr root;

    std::random_device rnd;
    std::mt19937 mt;
    std::uniform_int_distribution<> pri_rnd;

    int cnt(node_ptr t) {
        return t ? t->cnt : 0;
    }

    void update_cnt(node_ptr t) {
        if(t) {
            t->cnt = 1 + cnt(t->lch) + cnt(t->rch);
        }
    }

    S acc(node_ptr t) {
        return t ? t->acc : e();
    }

    void update_acc(node_ptr t) {
        if(t) {
            t->acc = op(acc(t->lch), t->val);
            t->acc = op(t->acc, acc(t->rch));
        }
    }

    void eval(node_ptr t) {
        if(t) {
            if(t->lch) {
                t->lch->lazy = composition(t->lazy, t->lch->lazy);
                t->lch->acc = mapping(t->lazy, t->lch->acc);
            }
            if(t->rch) {
                t->rch->lazy = composition(t->lazy, t->rch->lazy);
                t->rch->acc = mapping(t->lazy, t->rch->acc);
            }
            t->val = mapping(t->lazy, t->val);
            t->lazy = id();
        }
    }

    void pushdown(node_ptr t) {
        if(t && t->rev) {
            t->rev = false;
            std::swap(t->lch, t->rch);
            if(t->lch) t->lch->rev ^= 1;
            if(t->rch) t->rch->rev ^= 1;
        }
        eval(t);
        update(t);
    }

    void update(node_ptr t) {
        update_cnt(t);
        update_acc(t);
    }

    node_ptr merge(node_ptr l, node_ptr r) {
        pushdown(l);
        pushdown(r);
        if(!l || !r) {
            return !l ? r : l;
        }
        if(l->pri > r->pri) {
            l->rch = merge(l->rch, r);
            update(l);
            return l;
        }
        else {
            r->lch = merge(l, r->lch);
            update(r);
            return r;
        }
    }

    std::pair<node_ptr, node_ptr> split(node_ptr t, int key) {
        if(!t) return std::pair<node_ptr, node_ptr>(nullptr, nullptr);
        pushdown(t);
        if(key < cnt(t->lch) + 1) {
            auto [l, r] = split(t->lch, key);
            t->lch = r;
            update(t);
            return std::pair<node_ptr, node_ptr>(l, t);
        }
        else {
            auto [l, r] = split(t->rch, key-cnt(t->lch)-1);
            t->rch = l;
            update(t);
            return  std::pair<node_ptr, node_ptr>(t, r);
        }
    }
    
public:
    ImplicitTreap() : root(nullptr) {
        mt = std::mt19937(rnd());
        pri_rnd = std::uniform_int_distribution<>(0, 1e9);
    }

    void insert(int k, S x) {
        auto [l, r] = split(root, k);
        auto t = merge(l, new Node(x, pri_rnd(mt)));
        root = merge(t, r);
    }

    void erase(int k) {
        auto [l, r] = split(root, k+1);
        auto [nl, nr] = split(l, k);
        root = merge(nl, r);
    }

    void reverse(int l, int r) {
        auto [t1, t2] = split(root, l);
        auto [t3, t4] = split(t2, r-l);
        t3->rev ^= 1;
        t1 = merge(t1, t3);
        root = merge(t1, t4);
    }

    void apply(int l, int r, F x) {
        auto [t1, t2] = split(root, l);
        auto [t3, t4] = split(t2, r-l);
        t3->lazy = composition(x, t3->lazy);
        t3->acc = mapping(x, t3->acc);
        t1 = merge(t1, t3);
        root = merge(t1,t4);
    }

    S prod(int l, int r) {
        auto [t1, t2] = split(root, l);
        auto [t3, t4] = split(t2, r-l);
        S ret = t3->acc;
        t1 = merge(t1, t3);
        root = merge(t1, t4);
        return ret;
    }
};

} // namespace ebi