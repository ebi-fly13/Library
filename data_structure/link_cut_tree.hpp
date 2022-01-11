#pragma once

#include <cassert>
#include <limits>
#include <memory>
#include <optional>

namespace ebi {

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct link_cut_tree {
   private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        int index;
        S val, sum, rev_sum;
        F lazy;
        node_ptr lch, rch, par;
        bool rev;

        Node(int _index, S _val)
            : index(_index),
              val(_val),
              sum(_val),
              rev_sum(_val),
              lazy(id()),
              lch(nullptr),
              rch(nullptr),
              par(nullptr),
              rev(false) {}

        Node(int _index)
            : index(_index),
              val(e()),
              sum(e()),
              rev_sum(e()),
              lazy(id()),
              lch(nullptr),
              rch(nullptr),
              par(nullptr),
              rev(false) {}

        bool is_root() {
            return !par || (par->lch.get() != this && par->rch.get() != this);
        }

        void set(S x) {
            val = sum = rev_sum = x;
            lazy = id();
        }

        void propagate(F f) {
            lazy = composition(f, lazy);
            val = mapping(f, val);
            sum = mapping(f, sum);
            rev_sum = mapping(f, rev_sum);
        }

        void update() {
            sum = val;
            rev_sum = val;
            if (lch) {
                sum = op(lch->sum, sum);
                rev_sum = op(rev_sum, lch->rev_sum);
            }
            if (rch) {
                sum = op(sum, rch->sum);
                rev_sum = op(rch->rev_sum, rev_sum);
            }
        }

        void toggle() {
            std::swap(lch, rch);
            std::swap(sum, rev_sum);
            rev ^= true;
        }

        void eval() {
            if (lch) {
                lch->lazy = composition(lazy, lch->lazy);
                lch->sum = mapping(lazy, lch->sum);
                lch->rev_sum = mapping(lazy, lch->rev_sum);
            }
            if (rch) {
                rch->lazy = composition(lazy, rch->lazy);
                rch->sum = mapping(lazy, rch->sum);
                rch->rev_sum = mapping(lazy, rch->rev_sum);
            }
            val = mapping(lazy, val);
            lazy = id();
            return;
        }

        void pushdown() {
            eval();
            if (rev) {
                rev = false;
                if (lch) lch->toggle();
                if (rch) rch->toggle();
            }
        }
    };

    void rot_L(node_ptr node) {
        assert(node->par);
        auto par = node->par;
        auto g = par->par;
        if ((par->rch = node->lch)) node->lch->par = par;
        node->lch = par;
        par->par = node;
        par->update();
        node->update();
        if ((node->par = g)) {
            if (g->lch == par) g->lch = node;
            if (g->rch == par) g->rch = node;
            g->update();
        }
        return;
    }

    void rot_R(node_ptr node) {
        assert(node->par);
        auto par = node->par;
        auto g = par->par;
        if ((par->lch = node->rch)) node->rch->par = par;
        node->rch = par;
        par->par = node;
        par->update();
        node->update();
        if ((node->par = g)) {
            if (g->lch == par) g->lch = node;
            if (g->rch == par) g->rch = node;
            g->update();
        }
        return;
    }

    void splay(node_ptr node) {
        if (!node) return;
        node->pushdown();
        while (!node->is_root()) {
            auto par = node->par;
            if (par->is_root()) {
                par->pushdown();
                node->pushdown();
                if (par->lch == node) rot_R(node);
                if (par->rch == node) rot_L(node);
            } else {
                auto g = par->par;
                g->pushdown();
                par->pushdown();
                node->pushdown();
                if (g->lch == par) {
                    if (par->lch == node) {
                        rot_R(par);
                        rot_R(node);
                    } else {
                        rot_L(node);
                        rot_R(node);
                    }
                } else {
                    assert(g->rch == par);
                    if (par->rch == node) {
                        rot_L(par);
                        rot_L(node);
                    } else {
                        rot_R(node);
                        rot_L(node);
                    }
                }
            }
        }
        return;
    }

    void make_node(int index, S val) {
        vertex[index] = std::make_shared<Node>(index, val);
        return;
    }

    void expose(node_ptr node) {
        node_ptr prev_rch = nullptr;
        for (node_ptr cur = node; cur; cur = cur->par) {
            splay(cur);
            cur->rch = prev_rch;
            cur->update();
            prev_rch = cur;
        }
        splay(node);
        return;
    }

    void link(node_ptr child, node_ptr parent) {
        expose(child);
        expose(parent);
        child->par = parent;
        parent->rch = child;
        return;
    }

    void cut(node_ptr child) {
        expose(child);
        assert(child->lch);
        auto parent = child->lch;
        child->lch = nullptr;
        parent->par = nullptr;
        return;
    }

    void evert(node_ptr node) {
        expose(node);
        node->toggle();
        node->pushdown();
        return;
    }

   public:
    link_cut_tree(int n) : vertex(n) {}

    link_cut_tree(const std::vector<S> &a) {
        int n = a.size();
        vertex.resize(n);
        for (int i = 0; i < n; i++) make_node(i, a[i]);
    }

    void add_edge(int i, int j) {
        evert(vertex[i]);
        link(vertex[i], vertex[j]);
        return;
    }

    void erase_edge(int i, int j) {
        evert(vertex[i]);
        cut(vertex[j]);
    }

    // s-tパスにfを作用させる
    void apply(int s, int t, F f) {
        evert(vertex[s]);
        expose(vertex[t]);
        vertex[s]->propagate(f);
        vertex[s]->pushdown();
    }

    void set(int v, S x) {
        evert(vertex[v]);
        expose(vertex[v]);
        vertex[v]->set(x);
    }

    S prod(int s, int t) {
        evert(vertex[s]);
        expose(vertex[t]);
        return vertex[t]->sum;
    }

    S get(int v) {
        expose(vertex[v]);
        return vertex[v]->val;
    }

    std::vector<int> get_path(int s, int t) {
        evert(vertex[s]);
        expose(vertex[t]);
        std::vector<int> vs;
        auto dfs = [&](auto &&self, node_ptr v) -> void {
            if (!v) return;
            self(self, v->rch);
            vs.emplace_back(v->index);
            self(self, v->lch);
            return;
        };
        dfs(dfs, vertex[t]);
        return vs;
    }

    void DEBUG() {
        for (auto node : vertex) {
            debug(node->index, node->val.value, node->sum.value);
            if (node->par) {
                debug(node->par->index);
            }
            if (node->lch) {
                debug(node->lch->index);
            }
            if (node->rch) {
                debug(node->rch->index);
            }
        }
    }

   private:
    std::vector<node_ptr> vertex;
};

}  // namespace ebi