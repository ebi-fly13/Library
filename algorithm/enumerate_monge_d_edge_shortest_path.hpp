#pragma once

#include <limits>
#include <utility>
#include <vector>

#include "../algorithm/monotone_minima.hpp"

namespace ebi {

template <class F, class T = decltype(std::declval<F>()(std::declval<int>(),
                                                        std::declval<int>()))>
std::vector<T> enumerate_monge_d_edge_shortest_path(int n, F f) {
    const T max = std::numeric_limits<T>::max();
    std::vector<T> res(n, max);
    std::vector<T> dp(n, max);
    dp[0] = 0;
    auto g = [&](int j, int i) -> T {
        if (dp[i] == max || i >= j) return max;
        return dp[i] + f(i, j);
    };
    for (int d = 1; d < n; d++) {
        std::vector<int> argmin = monotone_minima(n, n, g).first;
        for (int i = n - 1; i >= d; i--) dp[i] = g(i, argmin[i]);
        res[d] = dp[n - 1];
    }
    return res;
}

}  // namespace ebi