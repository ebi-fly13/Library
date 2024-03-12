#pragma once

#include <numeric>
#include <queue>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T, class F>
void complement_graph_bfs(int s, const Graph<T> &h, const F &func) {
    const int n = h.size();
    std::vector<int> not_visit;
    not_visit.reserve(n - 1);
    for (int i = 0; i < n; i++)
        if (i != s) not_visit.emplace_back(i);
    std::vector<bool> f(n, false);
    std::queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto e : h[v]) {
            f[e.to] = true;
        }
        std::vector<int> L;
        for (auto u : not_visit) {
            if (f[u])
                L.emplace_back(u);
            else {
                que.push(u);
                func(v, u);
            }
        }
        for (auto e : h[v]) {
            f[e.to] = false;
        }
        std::swap(not_visit, L);
    }
    return;
}

}  // namespace ebi