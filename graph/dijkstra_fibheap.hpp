#pragma once

#include "../data_structure/fibonacci_heap.hpp"
#include "../graph/template.hpp"

#include <limits>
#include <vector>

namespace ebi {

template <class T> bool op(T a, T b) {
    return a <= b;
}

template <class T> std::vector<T> dijkstra(int s, int n, const Graph<T> &g) {
    std::vector<T> d(n, std::numeric_limits<T>::max());
    fibonacci_heap<T, int, op> que;
    d[s] = 0;
    std::vector<internal::fibheap_node<T, int> *> p(n, nullptr);
    p[s] = que.push(0, s);
    while (!que.empty()) {
        que.is_valid();
        int v = que.top();
        // debug(v, d[v]);
        que.pop();
        for (auto e : g[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                if (p[e.to] == nullptr) {
                    p[e.to] = que.push(d[e.to], e.to);
                    continue;
                }
                que.prioritize(p[e.to], d[e.to]);
            }
        }
    }
    return d;
}

}  // namespace ebi