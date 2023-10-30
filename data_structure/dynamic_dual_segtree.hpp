#pragma once

#include <bit>
#include <cassert>
#include <memory>

namespace ebi {

template <class F, F (*merge)(F, F), F (*id)()> struct dynamice_dual_segtree {
  private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;
    struct Node {
        node_ptr lch = nullptr, rch = nullptr;
        F f = id();
    };

    void all_apply(node_ptr node, F f) {
        node->f = merge(f, node->f);
    }

    void push(node_ptr node) {
        if (node->lch == nullptr) {
            node->lch = std::make_shared<Node>();
        }
        node->lch->f = merge(node->f, node->lch->f);
        if (node->rch == nullptr) {
            node->rch = std::make_shared<Node>();
        }
        node->rch->f = merge(node->f, node->rch->f);
        node->f = id();
    }

    void _apply(node_ptr node, int l, int r, int tl, int tr, F f) {
        if (tr <= l || r <= tl) return;
        if (tl <= l && r <= tr) {
            all_apply(node, f);
            return;
        }
        push(node);
        _apply(node->lch, l, (l + r) / 2, tl, tr, f);
        _apply(node->rch, (l + r) / 2, r, tl, tr, f);
    }

  public:
    dynamice_dual_segtree(int n_)
        : n(n_),
          sz(std::bit_ceil((unsigned int)(n))),
          lg2(std::countr_zero((unsigned int)(sz))),
          root(std::make_shared<Node>()) {}

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return;
        _apply(root, 0, sz, l, r, f);
    }

    void set(int p, F f) {
        assert(0 <= p && p < n);
        node_ptr node = root;
        int l = 0, r = sz;
        for (int i = 0; i < lg2; i++) {
            push(node);
            int m = (l + r) / 2;
            if (p < m) {
                r = m;
                node = node->lch;
            } else {
                l = m;
                node = node->rch;
            }
        }
        node->f = f;
    }

    F get(int p) {
        assert(0 <= p && p < n);
        node_ptr node = root;
        int l = 0, r = sz;
        for (int i = 0; i < lg2; i++) {
            push(node);
            int m = (l + r) / 2;
            if (p < m) {
                r = m;
                node = node->lch;
            } else {
                l = m;
                node = node->rch;
            }
        }
        return node->f;
    }

  private:
    int n, sz, lg2;
    node_ptr root;
};

}  // namespace ebi