#pragma once

#include <vector>
#include <cassert>

/*
    reference: https://37zigen.com/persistent-segment-tree/
*/

namespace ebi {

template<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
struct PersistentSegmentTree {
private:
    struct Node {
        Monoid val;
        Node *left, *right, *par;
        Node(Node *par = nullptr) : val(e()), left(nullptr), right(nullptr), par(par) { }
        void update() {
            val = e();
            if(left != nullptr) val = left->val;
            if(right != nullptr) val = op(val, right->val);
        }
    };

    using node_ptr = Node*;

    std::vector<node_ptr> roots;

    int n;
    int time;

    Monoid prod(int l, int r, int nl, int nr, node_ptr now) {
        if(now == nullptr || nr <= l || r<=nl) return e();
        if(l <= nl && nr <= r) return now->val;
        return op(prod(l, r, nl, (nl+nr)/2, now->left), prod(l, r, (nl+nr)/2, nr, now->right));
    }
public:
    PersistentSegmentTree(int _n) : n(1), time(1) {
        while(n < _n) {
            n <<= 1;
        }
        roots.emplace_back(new Node());

    }

    PersistentSegmentTree(std::vector<Monoid> v) : n(1), time(1) {
        int _n = v.size();
        while(n < _n) {
            n <<= 1;
        }
        auto dfs = [&](auto dfs, int l, int r, node_ptr now) -> void {
            assert(now != nullptr);
            if(_n <= l) return;
            if(r-l == 1) {
                now->val = v[l];
                return;
            }
            int mid = (l+r)/2;
            if(now->left == nullptr) now->left = new Node(now);
            if(now->right == nullptr) now->right = new Node(now);
            dfs(dfs, l, mid, now->left);
            dfs(dfs, mid, r, now->right);
            now->update();
        };
        node_ptr root = new Node();
        roots.emplace_back(root);
        dfs(dfs, 0, n, root);
    }

    void set(int ver, int i, Monoid x) {
        assert(0<= ver && ver<time);
        node_ptr now = new Node();
        node_ptr p = roots[ver];
        roots.emplace_back(now);
        time++;
        int l = 0, r = n;
        while(r-l > 1) {
            int mid = (r+l)/2;
            if(i<mid) {
                r = mid;
                now->left = new Node(now);
                if(p != nullptr) {
                    now->right = p->right;
                    p = p->left;
                }
                now = now->left;
            }
            else {
                l = mid;
                now->right = new Node(now);
                if(p != nullptr) {
                    now->left = p->left;
                    p = p->right;
                }
                now = now->right;
            }
        }
        now->val = x;
        while(now->par) {
            now = now->par;
            now->update();
        }
    }

    Monoid get(int ver, int i) {
        assert(0<= ver && ver<time);
        int l = 0, r = n;
        node_ptr now = roots[ver];
        while(r-l>1) {
            int mid = (l+r)/2;
            if(i<mid) {
                if(now->left == nullptr) return e();
                now = now->left;
                r = mid;
            }
            else {
                if(now->right == nullptr) return e();
                now = now->right;
                l = mid;
            }
        }
        return now->val;
    }

    Monoid prod(int ver, int l, int r) {
        assert(0<= ver && ver < time);
        return prod(l, r, 0, n, roots[ver]);
    }

    Monoid all_prod(int ver) {
        assert(ver<time);
        assert(roots[ver]->par == nullptr);
        return roots[ver]->val;
    }

    int latest() {
        return time-1;
    }
};

}