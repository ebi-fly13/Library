#pragma once

#include <array>
#include <cassert>
#include <limits>
#include <memory>
#include <set>
#include <vector>

namespace ebi {

template <class T, int BIT_SIZE> struct range_query_binary_trie {
  private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;
    struct Node {
        std::array<node_ptr, 2> child;
        std::set<int> set = {1'000'000'000};

        Node() = default;
    };

    void insert(int idx) {
        T x = a[idx];
        node_ptr now = root;
        now->set.insert(idx);
        for (int i = BIT_SIZE - 1; i >= 0; i--) {
            int index = (x >> i) & 1;
            if (now->child[index] == nullptr) {
                now->child[index] = std::make_shared<Node>();
            }
            now = now->child[index];
            now->set.insert(idx);
        }
    }

    void erase(int idx) {
        T x = a[idx];
        node_ptr now = root;
        now->set.erase(idx);
        for (int i = BIT_SIZE - 1; i >= 0; i--) {
            int index = (x >> i) & 1;
            now = now->child[index];
            now->set.erase(idx);
        }
    }

  public:
    range_query_binary_trie(const std::vector<T> &a) : a(a) {
        for (int i = 0; i < (int)a.size(); i++) insert(i);
    }

    void set(int idx, T x) {
        erase(idx);
        a[idx] = x;
        insert(idx);
    }

    T get(int idx) const {
        return a[idx];
    }

    T min_element(int l, int r, T x) {
        T val = 0;
        node_ptr now = root;
        for (int i = BIT_SIZE - 1; i >= 0; i--) {
            int index = (x >> i) & 1;
            if (now->child[index] &&
                *now->child[index]->set.lower_bound(l) < r) {
                now = now->child[index];
            } else if (now->child[index ^ 1] &&
                       *now->child[index ^ 1]->set.lower_bound(l) < r) {
                now = now->child[index ^ 1];
                val |= T(1) << i;
            } else {
                assert(0);
            }
        }
        return val;
    }

  private:
    std::vector<T> a;
    node_ptr root = std::make_shared<Node>();
};

}  // namespace ebi