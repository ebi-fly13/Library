---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algorithm/golden_section_search.hpp
    title: Golden section search
  - icon: ':heavy_check_mark:'
    path: algorithm/monge_shortest_path.hpp
    title: Monge shortest path
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/monge_d_edge_shortest_path.hpp\"\n\n#include <utility>\n\
    \n#line 2 \"algorithm/golden_section_search.hpp\"\n\n#include <cassert>\n#include\
    \ <concepts>\n#include <functional>\n#line 7 \"algorithm/golden_section_search.hpp\"\
    \n\n#line 2 \"template/int_alias.hpp\"\n\n#include <cstdint>\n\nnamespace ebi\
    \ {\n\nusing ld = long double;\nusing std::size_t;\nusing i8 = std::int8_t;\n\
    using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \n}  // namespace ebi\n#line 9 \"algorithm/golden_section_search.hpp\"\n\nnamespace\
    \ ebi {\n\n// ref: https://x.com/noshi91/status/1399003086362865673\ntemplate\
    \ <std::integral S, class F,\n          class T = decltype(std::declval<F>()(std::declval<S>())),\n\
    \          class Compare = std::less<T>>\nstd::pair<S, T> golden_section_search(F\
    \ f, S min, S max,\n                                      const Compare &compare\
    \ = Compare()) {\n    assert(min <= max);\n    S a = min - 1, x, b;\n    {\n \
    \       S s = 1, t = 2;\n        while (t < max - min + 2) {\n            std::swap(s\
    \ += t, t);\n        }\n        x = a + t - s;\n        b = a + t;\n    }\n  \
    \  T fx = f(x), fy;\n    while (a + b != 2 * x) {\n        S y = a + b - x;\n\
    \        if (max < y || compare(fx, (fy = f(y)))) {\n            b = a;\n    \
    \        a = y;\n        } else {\n            a = x;\n            x = y;\n  \
    \          fx = fy;\n        }\n    }\n    return {x, fx};\n}\n\n}  // namespace\
    \ ebi\n#line 2 \"algorithm/monge_shortest_path.hpp\"\n\n#include <limits>\n#include\
    \ <vector>\n\nnamespace ebi {\n\ntemplate <class F, class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                                        std::declval<int>()))>\n\
    std::vector<T> monge_shortest_path(int n, F f) {\n    const T max = std::numeric_limits<T>::max();\n\
    \    std::vector<int> argmin(n, 0);\n    std::vector<T> dp(n, max);\n    dp[0]\
    \ = 0;\n    auto get = [&](int i, int j) -> T {\n        T val = f(j, i);\n  \
    \      if (val == max || dp[j] == max) return max;\n        return dp[j] + val;\n\
    \    };\n    auto check = [&](int i, int j) -> void {\n        T val = get(i,\
    \ j);\n        if (val < dp[i]) {\n            dp[i] = val;\n            argmin[i]\
    \ = j;\n        }\n    };\n    dp[n - 1] = get(n - 1, 0);\n    auto dfs = [&](auto\
    \ &&self, int l, int r) -> void {\n        if (r - l == 1) return;\n        int\
    \ m = (l + r) >> 1;\n        for (int i = argmin[l]; i <= argmin[r]; i++) {\n\
    \            check(m, i);\n        }\n        self(self, l, m);\n        for (int\
    \ i = l + 1; i <= m; i++) {\n            check(r, i);\n        }\n        self(self,\
    \ m, r);\n    };\n    dfs(dfs, 0, n - 1);\n    return dp;\n}\n\n}  // namespace\
    \ ebi\n#line 7 \"algorithm/monge_d_edge_shortest_path.hpp\"\n\nnamespace ebi {\n\
    \ntemplate <std::integral S, class F,\n          class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                               std::declval<int>()))>\nT monge_d_edge_shortest_path(int\
    \ n, int d, S upper, F f) {\n    auto dp = [&](S x) -> T {\n        auto g = [&](int\
    \ i, int j) -> T { return f(i, j) + x; };\n        T c = monge_shortest_path(n,\
    \ g)[n - 1];\n        return c - T(1) * x * d;\n    };\n    return golden_section_search(dp,\
    \ -upper, upper, std::greater<T>()).second;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <utility>\n\n#include \"../algorithm/golden_section_search.hpp\"\
    \n#include \"../algorithm/monge_shortest_path.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <std::integral S, class F,\n          class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                               std::declval<int>()))>\nT monge_d_edge_shortest_path(int\
    \ n, int d, S upper, F f) {\n    auto dp = [&](S x) -> T {\n        auto g = [&](int\
    \ i, int j) -> T { return f(i, j) + x; };\n        T c = monge_shortest_path(n,\
    \ g)[n - 1];\n        return c - T(1) * x * d;\n    };\n    return golden_section_search(dp,\
    \ -upper, upper, std::greater<T>()).second;\n}\n\n}  // namespace ebi"
  dependsOn:
  - algorithm/golden_section_search.hpp
  - template/int_alias.hpp
  - algorithm/monge_shortest_path.hpp
  isVerificationFile: false
  path: algorithm/monge_d_edge_shortest_path.hpp
  requiredBy: []
  timestamp: '2023-12-28 15:52:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/monge_d_edge_shortest_path.hpp
layout: document
title: Monge d-edge shortest path
---

## 説明

辺の重みがMongeであるようなグラフに対して $0$ からスタートして、 $N-1$ へちょうど $d$ 辺使った場合の最短路の値を求める。 $O(N\log N \log (\max))$ 。 $\max$ は $1$ 辺の最大長。

reference: [Mongeグラフ上のd-辺最短路長を計算するアルゴリズム](https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge)