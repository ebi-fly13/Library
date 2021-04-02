#pragma once

#include <cstdint>
#include <vector>
#include <memory>
#include <cassert>

/*
    reference: https://37zigen.com/persistent-array/
*/

namespace ebi {

template<class T, std::size_t m>
struct persistent_array {
private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;
    using size_t = std::size_t;
    struct Node {
        T val;
        std::vector<node_ptr> chr;
        Node(T val, std::vector<node_ptr> chr = std::vector<node_ptr>(m)) : val(val), chr(chr) { }
        node_ptr get_chr(int i) {
            return chr[i];
        }
        void update_chr(int i, node_ptr node) {
            chr[i] = node;
        }
    };

    std::vector<node_ptr> root;
    int now;

public:
    persistent_array(std::size_t n, T val) : now(0) {
        root.emplace_back(std::make_shared<Node>(val));
        for(size_t i = 1; i < n; i++) {
            node_ptr node = root[0];
            size_t ret = i;
            while(ret > 0) {
                if(node->chr[ret%m] == nullptr) {
                    node->chr[ret%m] = std::make_shared<Node>(val);
                }
                node = node->chr[ret%m];
                ret /= m;
            }
            if(node == nullptr) {
                node = std::make_shared<Node>(val);
            }
        }
    }

    persistent_array(std::vector<T> a) : now(0) {
        size_t n = a.size();
        root.emplace_back(std::make_shared<Node>(a[0]));
        for(size_t i = 1; i < n; i++) {
            node_ptr node = root[0];
            size_t ret = i;
            while(ret > 0) {
                if(node->chr[ret%m] == nullptr) {
                    node->chr[ret%m] = std::make_shared<Node>(a[i]);
                }
                node = node->chr[ret%m];
                ret /= m;
            }
            if(node == nullptr) {
                node = std::make_shared<Node>(a[i]);
            }
        }
    }

    T get(size_t i, int time = -1) {
        assert(time <= now);
        if(time < 0) time = now;
        node_ptr node = root[time];
        while(i > 0) {
            node = node->chr[i%m];
            i /= m;
        }
        return node->val;
    }

    void set(size_t i, T val, int time = -1) {
        if(time < 0) time = now;
        assert(time <= now);
        node_ptr p = root[time];
        node_ptr node = std::make_shared<Node>(p->val, p->chr);
        root.emplace_back(node);
        while(i > 0) {
            p = p->chr[i%m];
            node->chr[i%m] = std::make_shared<Node>(p->val, p->chr);
            node = node->chr[i%m];
            i /= m;
        }
        node->val = val;
        now++;
    }

    void add(size_t i, T rhs, int time = -1) {
        if(time < 0) time = now;
        assert(time <= now);
        node_ptr p = root[time];
        node_ptr node = std::make_shared<Node>(p->val, p->chr);
        root.emplace_back(node);
        while(i > 0) {
            p = p->chr[i%m];
            node->chr[i%m] = std::make_shared<Node>(p->val, p->chr);
            node = node->chr[i%m];
            i /= m;
        }
        node->val += rhs;
        now++;
    } 

    void update(size_t i, T rhs, int time = -1) {
        if(time < 0) time = now;
        assert(time <= now);
        node_ptr node = root[time];
        node_ptr p = root[time];
        while(i > 0) {
            p = p->chr[i%m];
            node->chr[i%m] = std::make_shared<Node>(p->val, p->chr);
            node = node->chr[i%m];
            i /= m;
        }
        node->val = rhs;
    }
};

}