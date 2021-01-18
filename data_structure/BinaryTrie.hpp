#pragma once

/*
    reference: https://kazuma8128.hatenablog.com/entry/2018/05/06/022654
*/

#include <algorithm>

namespace ebi {

template<class T>
struct BinaryTrie {
private:
    struct Node {
        int cnt;
        Node *chr[2] = {nullptr, nullptr};
        Node(int c=0) : cnt(c) { }
    };

    using node_ptr = Node*;

    node_ptr root;

    int bit_size;
public:
    BinaryTrie(int bit_size = 32) : bit_size(bit_size) {
        root = new Node();
    } 

    void insert(T x) {
        node_ptr now = root;
        now->cnt++;
        for(int i = bit_size-1; i>=0; i--) {
            int p =  (x & ((T)1 << i))>0;
            if(!now->chr[p]) {
                now->chr[p] = new Node();
            }
            now = now->chr[p];
            now->cnt++;
        }
    }

    void erase(T x) {
        if(!find(x)) return;
        node_ptr now = root;
        now->cnt--;
        for(int i = bit_size-1; i>=0; i--) {
            int p = (x & ((T)1 << i)) > 0;
            if(!now->chr[p]) {
                return;
            }
            now = now->chr[p];
            now->cnt--;
        }
    }

    bool find(T x) const {
        node_ptr now = root;
        for(int i = bit_size-1; i>=0; i--) {
            int p = (x & ((T)1 << i)) > 0;
            if((!now->chr[p]) || now->chr[p]->cnt == 0) {
                return false;
            }
            now = now->chr[p];
        }
        return true;
    }

    T max_element() const {
        T val = 0;
        node_ptr now = root;
        for(int i = bit_size-1; i>=0; i--) {
            if(now->chr[1] && now->chr[1] > 0) {
                val |= (T)1 << i;
                now = now->chr[1];
            }
            else {
                now = now->chr[0];
            }
        }
        return val;
    }

    T min_element() const {
        T val = 0;
        node_ptr now = root;
        for(int i = bit_size-1; i>=0; i--) {
            if(now->chr[0] && now->chr[0] > 0) {
                now = now->chr[0];
            }
            else {
                val |= (T)1 << i;
                now = now->chr[1];
            }
        }
        return val;
    }

    T max_element(T x) const {
        node_ptr now = root;
        for(int i = bit_size-1; i>=0; i--) {
            int p = (x & ((T)1 << i)) > 0;
            int q = std::abs(p-1);
            if(now->chr[q] && now->chr[q]->cnt > 0) {
                if(q) x ^= ((T)1 << i);
                now = now->chr[q];
            }
            else {
                if(p) x ^= ((T)1 << i);
                now = now->chr[p];
            }
        }
        return x;
    }

    T min_element(T x) const {
        node_ptr now = root;
        for(int i = bit_size-1; i>=0; i--) {
            int p = (x & ((T)1 << i)) > 0;
            if(now->chr[p] && now->chr[p]->cnt > 0) {
                if(p) x ^= ((T)1 << i);
                now = now->chr[p];
            }
            else {
                if(p==0) x ^= (T)1 << i;
                now = now->chr[std::abs(p-1)];
            }
        }
        return x;
    }
};

} // namespace ebi