#pragma once

/*
    reference:
   http://web.stanford.edu/class/archive/cs/cs166/cs166.1186/lectures/09/Slides09.pdf
               https://rsk0315.hatenablog.com/entry/2019/10/29/151823
               https://en.wikipedia.org/wiki/Fibonacci_heap
*/

#include <cassert>
#include <queue>
#include <vector>

namespace ebi {

namespace internal {

template <class K, class T> struct fibheap_node {
    fibheap_node *par, *prev, *next, *chr;
    int sz = 0;
    bool damaged = 0;
    K ord;
    T val;
    fibheap_node(K k, T val)
        : par(nullptr),
          prev(this),
          next(this),
          chr(nullptr),
          ord(k),
          val(val) {}

    void emplace_back(fibheap_node *e) {
        if (e == nullptr) return;
        prev->next = e;
        e->prev->next = this;
        std::swap(e->prev, prev);
    }

    void cut_par() {
        if (par == nullptr) return;
        par->sz--;
        if (par->sz == 0) {
            par->chr = nullptr;
        }
        if (par->chr == this) {
            par->chr = next;
        }
        cut();
        par = nullptr;
    }

    void cut() {
        next->prev = prev;
        prev->next = next;
        next = prev = this;
    }

    int size() const {
        return sz;
    }
};

}  // namespace internal

template <class K, class T, bool (*op)(K, K)> struct fibonacci_heap {
  private:
    using Node = internal::fibheap_node<K, T>;
    using node_ptr = Node *;

    node_ptr min = nullptr;
    node_ptr roots = nullptr;

    int sz = 0;

    void update(node_ptr a) {
        assert(a != nullptr);
        if (!min || op(a->ord, min->ord)) {
            min = a;
        }
    }

    void merge(node_ptr a, node_ptr b) {
        assert(a && b);
        assert(op(a->ord, b->ord));
        a->sz++;
        b->par = a;
        if (a->chr == nullptr)
            a->chr = b;
        else
            a->chr->emplace_back(b);
    }

    int log2ceil(int m) {
        int n = 1;
        while ((1 << n) < m) {
            n++;
        }
        return n;
    }

  public:
    node_ptr push(K k, T val) {
        node_ptr a = new Node(k, val);
        sz++;
        update(a);
        if (roots == nullptr) {
            roots = a;
            return a;
        }
        roots->emplace_back(a);
        is_valid();
        return a;
    }

    void pop() {
        assert(sz > 0);
        roots->emplace_back(min->chr);
        if (roots == min) {
            roots = roots->next;
            assert(roots->prev == min);
        }
        min->cut();
        delete min;
        min = nullptr;
        sz--;
        if (sz == 0) {
            roots = nullptr;
            return;
        }
        int n = log2ceil(size()) + 5;
        std::vector<std::queue<node_ptr>> que(n);
        que[roots->size()].push(roots);
        roots->par = nullptr;
        for (node_ptr ptr = roots->next; ptr != roots; ptr = ptr->next) {
            update(ptr);
            ptr->par = nullptr;
            que[ptr->size()].push(ptr);
        }
        roots = nullptr;
        for (int i = 0; i < n; i++) {
            while (que[i].size() > 1) {
                node_ptr first = que[i].front();
                que[i].pop();
                node_ptr second = que[i].front();
                que[i].pop();
                first->cut();
                second->cut();
                if (!op(first->ord, second->ord)) std::swap(first, second);
                merge(first, second);
                assert(first->sz == i + 1);
                que[first->size()].push(first);
            }
            if (que[i].size() == 1) {
                node_ptr ptr = que[i].front();
                que[i].pop();
                update(ptr);
                ptr->cut();
                if (roots == nullptr) {
                    roots = ptr;
                    continue;
                }
                roots->emplace_back(ptr);
            }
        }
    }

    T top() const {
        return min->val;
    }

    void prioritize(node_ptr e, K k) {
        assert(e && op(k, e->ord));
        e->ord = k;
        update(e);
        if (e->par == nullptr || op(e->par->ord, e->ord)) return;
        if (e->par->damaged && e->par->par != nullptr) {
            e->par->cut_par();
            roots->emplace_back(e->par);
        }
        e->par->damaged = true;
        e->cut_par();
        roots->emplace_back(e);
    }

    int size() const {
        return sz;
    }

    bool empty() const {
        return sz == 0;
    }

    void is_valid() const {
        K k = roots->ord;
        for (node_ptr ptr = roots->next; ptr != roots; ptr = ptr->next) {
            if (op(ptr->ord, k)) {
                k = ptr->ord;
            }
        }
        assert(k == min->ord);
    }
};

}  // namespace ebi
