#pragma once

/*
    reference: https://kazuma8128.hatenablog.com/entry/2018/05/06/022654
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <memory>

namespace ebi {

template <class T>
struct binary_trie {
   private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;
    struct Node {
        int count = 0;
        std::array<node_ptr, 2> childs;
        Node() = default;
    };

   public:
    binary_trie() = default;

    void insert(const T x) {
        node_ptr now = root;
        now->count++;
        for (int i = bit_size - 1; i >= 0; i--) {
            int index = (x >> i) & 1;
            if (now->childs[index] == nullptr) {
                now->childs[index] = std::make_shared<Node>();
            }
            now = now->childs[index];
            now->count++;
        }
        return;
    }

    void erase(const T x) {
        if (find(x) == false) return;
        node_ptr now = root;
        now->count--;
        for (int i = bit_size - 1; i >= 0; i--) {
            int index = (x >> i) & 1;
            assert(now->childs[index]);
            now = now->childs[index];
            now->count--;
        }
        return;
    }

    bool find(const T x) const {
        node_ptr now = root;
        for (int i = bit_size - 1; i >= 0; i--) {
            int index = (x >> i) & 1;
            if (now->childs[index] == nullptr) {
                return false;
            }
            now = now->childs[index];
            if (now->count == 0) {
                return false;
            }
        }
        return true;
    }

    T min_element(const T x) const {
        T val = 0;
        node_ptr now = root;
        for (int i = bit_size - 1; i >= 0; i--) {
            int index = ((x >> i) & 1);
            if (now->childs[index] && now->childs[index]->count > 0) {
                now = now->childs[index];
            } else if (now->childs[index ^ 1] &&
                       now->childs[index ^ 1]->count > 0) {
                val |= T(1) << i;
                now = now->childs[index ^ 1];
            } else {
                assert(0);
            }
        }
        return val;
    }

    T max_element(const T x) const {
        T val = 0;
        node_ptr now = root;
        for (int i = bit_size - 1; i >= 0; i--) {
            int index = ((x >> i) & 1) ^ 1;
            if (now->childs[index] && now->childs[index]->count > 0) {
                val |= T(1) << i;
                now = now->childs[index];
            } else if (now->childs[index ^ 1] &&
                       now->childs[index ^ 1]->count > 0) {
                now = now->childs[index ^ 1];
            } else {
                assert(0);
            }
        }
    }

    int size() const { return root->count; }

   private:
    const size_t bit_size = sizeof(T) * CHAR_BIT;
    node_ptr root = std::make_shared<Node>();
};

}  // namespace ebi