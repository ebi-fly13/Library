#pragma once

#include <algorithm>
#include <vector>

#include "../graph/template.hpp"

namespace ebi {

template <class T>
std::pair<T, std::vector<int>> tree_diameter(const Graph<T> &g) {
    int n = g.size();
    std::vector<T> dp(n);
    std::vector<int> par(n, -1);
    dp[0] = 0;
    auto dfs = [&](auto &&self, int v) -> void {
        for (const auto &[nv, cost] : g[v]) {
            if (nv == par[v]) continue;
            par[nv] = v;
            dp[nv] = dp[v] + cost;
            self(self, nv);
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

std::pair<int, std::vector<int>> tree_diameter(const graph &g) {
    int n = g.size();
    std::vector<int> dp(n);
    std::vector<int> par(n, -1);
    dp[0] = 0;
    auto dfs = [&](auto &&self, int v) -> void {
        for (const auto &nv : g[v]) {
            if (nv == par[v]) continue;
            par[nv] = v;
            dp[nv] = dp[v] + 1;
            self(self, nv);
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