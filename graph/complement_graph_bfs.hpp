#pragma once

#include <numeric>
#include <queue>
#include <vector>

namespace ebi {

template <class F>
void complement_graph_bfs(int s, const std::vector<std::vector<int>> &h,
                          const F &func) {
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
        for (auto nv : h[v]) {
            f[nv] = true;
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
        for (auto nv : h[v]) {
            f[nv] = false;
        }
        not_visit = L;
    }
    return;
}

}  // namespace ebi