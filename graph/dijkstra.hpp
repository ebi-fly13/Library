#pragma once

#include <limits>
#include <queue>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T> std::vector<T> dijkstra(int s, int n, const Graph<T> &g) {
    typedef std::pair<T, int> P;
    std::vector<T> d(n, std::numeric_limits<T>::max());
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    que.push(P(0, s));
    d[s] = 0;
    while (!que.empty()) {
        auto [ret, v] = que.top();
        que.pop();
        if (d[v] < ret) continue;
        for (auto e : g[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d;
}

}  // namespace ebi