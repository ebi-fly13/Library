#pragma once

#include <functional>
#include <limits>
#include <queue>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T>
std::vector<T> minimum_steiner_tree(const Graph<T> &g,
                                    const std::vector<int> &vs) {
    int n = g.node_number();
    int k = (int)vs.size();
    std::vector dp(1 << k, std::vector<T>(n, std::numeric_limits<T>::max()));
    for (int i = 0; auto v : vs) {
        dp[1 << i][v] = 0;
        i++;
    }
    for (int s = 1; s < (1 << k); s++) {
        for (int t = (s - 1) & s; t > 0; t = (t - 1) & s) {
            for (int i = 0; i < n; i++) {
                dp[s][i] = std::min(dp[s][i], dp[s ^ t][i] + dp[t][i]);
            }
        }
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,
                            std::greater<>>
            que;
        for (auto v : vs) {
            que.push({dp[s][v], v});
        }
        while (!que.empty()) {
            auto [ret, v] = que.top();
            que.pop();
            if (dp[s][v] < ret) continue;
            for (auto e : g[v]) {
                if (dp[s][e.to] > dp[s][v] + e.cost) {
                    dp[s][e.to] = dp[s][v] + e.cost;
                    que.push({dp[s][e.to], e.to});
                }
            }
        }
    }
    return dp[(1 << k) - 1];
}

}  // namespace ebi