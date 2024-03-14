#pragma once

#include <cassert>
#include <functional>
#include <memory>
#include <vector>

namespace ebi {

template <class Key, class T, class Compare = std::less<Key>> struct skew_heap {
  private:
    using value_type = Key;
    using Self = skew_heap<Key, T, Compare>;

    struct Node;
    using iterator = std::shared_ptr<Node>;

    struct Node {
        Node(value_type x_, T info_) : x(x_), info(info_) {}

        void propagate() {
            if (lhs) lhs->lazy += lazy;
            if (rhs) rhs->lazy += lazy;
            x += lazy;
            lazy = value_type();
        }

        value_type x;
        T info;
        value_type lazy = value_type();
        iterator lhs = nullptr, rhs = nullptr;
    };

    iterator internal_meld(iterator lhs, iterator rhs) {
        if (lhs == nullptr) return rhs;
        if (rhs == nullptr) return lhs;
        lhs->propagate();
        rhs->propagate();
        if (Compare()(rhs->x, lhs->x)) {
            std::swap(lhs, rhs);
        }
        lhs->rhs = internal_meld(lhs->rhs, rhs);
        std::swap(lhs->lhs, lhs->rhs);
        return lhs;
    }

  public:
    skew_heap() = default;

    void push(value_type x, T info) {
        root = internal_meld(root, std::make_shared<Node>(x, info));
        sz++;
    }

    void pop() {
        assert(!empty());
        root = internal_meld(root->lhs, root->rhs);
        sz--;
    }

    void meld(Self &heap) {
        root = internal_meld(root, heap.root);
        sz += heap.sz;
    }

    void add(value_type lazy) {
        root->lazy += lazy;
    }

    bool empty() const {
        return root == nullptr;
    }

    std::pair<value_type, T> top() const {
        return {root->x, root->info};
    }

    int size() const {
        return sz;
    }

  private:
    iterator root = nullptr;
    int sz = 0;
};

}  // namespace ebi