#pragma once

#include <limits>
#include <memory>
#include <optional>

namespace ebi {

template <class T> struct splay_tree {
  private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;
    struct Node {
        int sz;
        T val;
        node_ptr lch, rch, par;

        Node(T _val)
            : sz(1), val(_val), lch(nullptr), rch(nullptr), par(nullptr) {}

        bool is_root() {
            return !par;
        }

        void update() {
            sz = 1;
            if (lch) {
                sz += lch->sz;
            }
            if (rch) {
                sz += rch->sz;
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
        node->update();
        par->update();
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
        node->update();
        par->update();
        if ((node->par = g)) {
            if (g->lch == par) g->lch = node;
            if (g->rch == par) g->rch = node;
            g->update();
        }
        return;
    }

    void splay(node_ptr node) {
        if (!node) return;
        while (!node->is_root()) {
            auto par = node->par;
            if (par->is_root()) {
                if (par->lch == node) rot_R(node);
                if (par->rch == node) rot_L(node);
            } else {
                auto g = par->par;
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

    void search(T x) {
        if (!root) return;
        node_ptr now = root;
        while (now) {
            if (now->val == x) {
                break;
            } else if (now->val < x) {
                if (!now->rch) break;
                now = now->rch;
            } else {
                if (!now->lch) break;
                now = now->lch;
            }
        }
        assert(now);
        splay(now);
        root = now;
        assert(root->is_root());
        return;
    }

  public:
    splay_tree() = default;

    bool find(T x) {
        search(x);
        if (!root || root->val != x) return false;
        return true;
    }

    void insert(T x) {
        if (!find(x)) {
            auto node = std::make_shared<Node>(x);
            if (!root)
                root = node;
            else if (root->val < x) {
                node->lch = root;
                root->par = node;
                node->rch = root->rch;
                root->rch = nullptr;
                if (node->rch) node->rch->par = node;
                root = node;
            } else {
                node->rch = root;
                root->par = node;
                node->lch = root->lch;
                root->lch = nullptr;
                if (node->lch) node->lch->par = node;
                root = node;
            }
        }
        return;
    }

    void erase(T x) {
        if (find(x)) {
            assert(root->val == x);
            if (!root->lch)
                root = root->rch;
            else if (!root->rch)
                root = root->lch;
            else {
                assert(root->lch && root->rch);
                root->lch->par = root->rch->par = nullptr;
                auto rch = root->rch;
                root = root->lch;
                search(x);
                root->rch = rch;
                rch->par = root;
            }
        }
        if (root) root->par = nullptr;
        return;
    }

    std::optional<T> lower_bound(T x) {
        if (!root) return std::nullopt;
        search(x);
        if (x <= root->val) return root->val;
        if (!root->rch) return std::nullopt;
        auto node = root->rch;
        while (node->lch) {
            node = node->lch;
        }
        return std::make_optional<T>(node->val);
    }

    std::optional<T> upper_bound(T x) {
        if (!root) return std::nullopt;
        search(x);
        if (x < root->val) return std::make_shared<T>(root->val);
        if (!root->rch) return std::nullopt;
        auto node = root->rch;
        while (node->lch) {
            node = node->lch;
        }
        return std::make_optional<T>(node->val);
    }

    int size() const {
        return root ? root->sz : 0;
    }

  private:
    node_ptr root = nullptr;
};

}  // namespace ebi