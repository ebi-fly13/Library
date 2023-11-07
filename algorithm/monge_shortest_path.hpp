#pragma once

#include <limits>
#include <vector>

namespace ebi {

template <class T, class F> std::vector<T> monge_shortest_path(int n, F f) {
    const T max = std::numeric_limits<T>::max();
    std::vector<int> argmin(n, 0);
    std::vector<T> dp(n, max);
    dp[0] = 0;
    auto get = [&](int i, int j) -> T {
        T val = f(j, i);
        if (val == max || dp[j] == max) return max;
        return dp[j] + val;
    };
    auto check = [&](int i, int j) -> void {
        T val = get(i, j);
        if (val < dp[i]) {
            dp[i] = val;
            argmin[i] = j;
        }
    };
    dp[n - 1] = get(n - 1, 0);
    auto dfs = [&](auto &&self, int l, int r) -> void {
        if (r - l == 1) return;
        int m = (l + r) >> 1;
        for (int i = argmin[l]; i <= argmin[r]; i++) {
            check(m, i);
        }
        self(self, l, m);
        for (int i = l + 1; i <= m; i++) {
            check(r, i);
        }
        self(self, m, r);
    };
    dfs(dfs, 0, n - 1);
    return dp;
}

}  // namespace ebi