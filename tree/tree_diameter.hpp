#pragma once

#include <algorithm>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T>
std::pair<T, std::vector<int>> tree_diameter(const Graph<T> &g) {
    int n = g.size();
    std::vector<T> dp(n);
    std::vector<int> par(n, -1);
    dp[0] = 0;
    auto dfs = [&](auto &&self, int v) -> void {
        for (const auto e : g[v]) {
            if (e.to == par[v]) continue;
            par[e.to] = v;
            dp[e.to] = dp[v] + e.cost;
            self(self, e.to);
        }
    };
    dfs(dfs, 0);
    int u = std::max_element(dp.begin(), dp.end()) - dp.begin();
    par[u] = -1;
    dp[u] = 0;
    dfs(dfs, u);
    int v = std::max_element(dp.begin(), dp.end()) - dp.begin();
    std::vector<int> path;
    while (u != v) {
        path.emplace_back(v);
        v = par[v];
    }
    path.emplace_back(u);
    return {dp[*path.begin()], path};
}

}  // namespace ebi