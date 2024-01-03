---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree.test.cpp
    title: test/tree/Frequency_Table_of_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/centroid_decomposition.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <ranges>\n#include <vector>\n\nnamespace ebi {\n\n\
    namespace internal {\n\ntemplate <class F>\nvoid centroid_decomposition_dfs_0(const\
    \ std::vector<int> &par,\n                                  const std::vector<int>\
    \ &origin_vs, F f) {\n    const int n = (int)par.size();\n    assert(par.size()\
    \ == origin_vs.size());\n    int center = -1;\n    std::vector<int> sz(n, 1);\n\
    \    for (auto v : std::views::iota(0, n) | std::views::reverse) {\n        if\
    \ (sz[v] >= (n + 1) / 2) {\n            center = v;\n            break;\n    \
    \    }\n        sz[par[v]] += sz[v];\n    }\n    std::vector<int> color(n, -1);\n\
    \    std::vector<int> vs = {center};\n    color[center] = 0;\n    int c = 1;\n\
    \    for (int v : std::views::iota(1, n)) {\n        if (par[v] == center) {\n\
    \            vs.emplace_back(v);\n            color[v] = c++;\n        }\n   \
    \ }\n    if (center > 0) {\n        for (int v = par[center]; v != -1; v = par[v])\
    \ {\n            vs.emplace_back(v);\n            color[v] = c;\n        }\n \
    \       c++;\n    }\n    for (int v : std::views::iota(0, n)) {\n        if (color[v]\
    \ == -1) {\n            vs.emplace_back(v);\n            color[v] = color[par[v]];\n\
    \        }\n    }\n    std::vector<int> index_ptr(c + 1, 0);\n    for (int v :\
    \ std::views::iota(0, n)) {\n        index_ptr[color[v] + 1]++;\n    }\n    for\
    \ (int i : std::views::iota(0, c)) {\n        index_ptr[i + 1] += index_ptr[i];\n\
    \    }\n    auto counter = index_ptr;\n    std::vector<int> ord(n);\n    for (auto\
    \ v : vs) {\n        ord[counter[color[v]]++] = v;\n    }\n    std::vector<int>\
    \ relabel(n);\n    for (int v : std::views::iota(0, n)) {\n        relabel[ord[v]]\
    \ = v;\n    }\n    std::vector<int> origin_vs2(n);\n    for (int v : std::views::iota(0,\
    \ n)) {\n        origin_vs2[relabel[v]] = origin_vs[v];\n    }\n    std::vector<int>\
    \ relabel_par(n, -1);\n    for (int v : std::views::iota(1, n)) {\n        int\
    \ a = relabel[v];\n        int b = relabel[par[v]];\n        if (a > b) std::swap(a,\
    \ b);\n        relabel_par[b] = a;\n    }\n    f(relabel_par, origin_vs2, index_ptr);\n\
    \    for (int i : std::views::iota(1, c)) {\n        int l = index_ptr[i], r =\
    \ index_ptr[i + 1];\n        std::vector<int> par1(r - l, -1);\n        std::vector<int>\
    \ origin_vs1(r - l, -1);\n        for (int v : std::views::iota(l, r)) {\n   \
    \         par1[v - l] = (relabel_par[v] == 0 ? -1 : relabel_par[v] - l);\n   \
    \         origin_vs1[v - l] = origin_vs2[v];\n        }\n        centroid_decomposition_dfs_0(par1,\
    \ origin_vs1, f);\n    }\n    return;\n}\n\ntemplate <class F>\nvoid centroid_decomposition_dfs_1(const\
    \ std::vector<int> &par,\n                                  const std::vector<int>\
    \ &bfs_order, F f) {}\n\ntemplate <class F>\nvoid one_third_centroid_decomposition(const\
    \ std::vector<int> &par,\n                                      const std::vector<int>\
    \ &bfs_order, F f) {}\n\n}  // namespace internal\n\ntemplate <int MODE, class\
    \ F>\nvoid centroid_decomposition(const std::vector<std::vector<int>> &tree, F\
    \ f) {\n    int n = (int)tree.size();\n    if (n == 1) return;\n    std::vector<int>\
    \ bfs_order(n), par(n, -1);\n    bfs_order[0] = 0;\n    int l = 0, r = 1;\n  \
    \  while (l < r) {\n        int v = bfs_order[l++];\n        for (auto nv : tree[v])\
    \ {\n            if (nv == par[v]) continue;\n            bfs_order[r++] = nv;\n\
    \            par[nv] = v;\n        }\n    }\n    assert(l == n && r == n);\n \
    \   {\n        std::vector<int> relabel(n);\n        for (int i : std::views::iota(0,\
    \ n)) {\n            relabel[bfs_order[i]] = i;\n        }\n        std::vector<int>\
    \ relabel_par(n, -1);\n        for (int i : std::views::iota(1, n)) {\n      \
    \      relabel_par[relabel[i]] = relabel[par[i]];\n        }\n        std::swap(par,\
    \ relabel_par);\n    }\n    static_assert(MODE == 0 || MODE == 1 || MODE == 2);\n\
    \    if constexpr (MODE == 0) {\n        internal::centroid_decomposition_dfs_0(par,\
    \ bfs_order, f);\n    } else if constexpr (MODE == 1) {\n    } else {\n      \
    \  internal::one_third_centroid_decomposition(par, bfs_order, f);\n    }\n}\n\n\
    }  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <ranges>\n\
    #include <vector>\n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <class\
    \ F>\nvoid centroid_decomposition_dfs_0(const std::vector<int> &par,\n       \
    \                           const std::vector<int> &origin_vs, F f) {\n    const\
    \ int n = (int)par.size();\n    assert(par.size() == origin_vs.size());\n    int\
    \ center = -1;\n    std::vector<int> sz(n, 1);\n    for (auto v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n    std::vector<int> color(n, -1);\n    std::vector<int> vs = {center};\n\
    \    color[center] = 0;\n    int c = 1;\n    for (int v : std::views::iota(1,\
    \ n)) {\n        if (par[v] == center) {\n            vs.emplace_back(v);\n  \
    \          color[v] = c++;\n        }\n    }\n    if (center > 0) {\n        for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n            vs.emplace_back(v);\n\
    \            color[v] = c;\n        }\n        c++;\n    }\n    for (int v : std::views::iota(0,\
    \ n)) {\n        if (color[v] == -1) {\n            vs.emplace_back(v);\n    \
    \        color[v] = color[par[v]];\n        }\n    }\n    std::vector<int> index_ptr(c\
    \ + 1, 0);\n    for (int v : std::views::iota(0, n)) {\n        index_ptr[color[v]\
    \ + 1]++;\n    }\n    for (int i : std::views::iota(0, c)) {\n        index_ptr[i\
    \ + 1] += index_ptr[i];\n    }\n    auto counter = index_ptr;\n    std::vector<int>\
    \ ord(n);\n    for (auto v : vs) {\n        ord[counter[color[v]]++] = v;\n  \
    \  }\n    std::vector<int> relabel(n);\n    for (int v : std::views::iota(0, n))\
    \ {\n        relabel[ord[v]] = v;\n    }\n    std::vector<int> origin_vs2(n);\n\
    \    for (int v : std::views::iota(0, n)) {\n        origin_vs2[relabel[v]] =\
    \ origin_vs[v];\n    }\n    std::vector<int> relabel_par(n, -1);\n    for (int\
    \ v : std::views::iota(1, n)) {\n        int a = relabel[v];\n        int b =\
    \ relabel[par[v]];\n        if (a > b) std::swap(a, b);\n        relabel_par[b]\
    \ = a;\n    }\n    f(relabel_par, origin_vs2, index_ptr);\n    for (int i : std::views::iota(1,\
    \ c)) {\n        int l = index_ptr[i], r = index_ptr[i + 1];\n        std::vector<int>\
    \ par1(r - l, -1);\n        std::vector<int> origin_vs1(r - l, -1);\n        for\
    \ (int v : std::views::iota(l, r)) {\n            par1[v - l] = (relabel_par[v]\
    \ == 0 ? -1 : relabel_par[v] - l);\n            origin_vs1[v - l] = origin_vs2[v];\n\
    \        }\n        centroid_decomposition_dfs_0(par1, origin_vs1, f);\n    }\n\
    \    return;\n}\n\ntemplate <class F>\nvoid centroid_decomposition_dfs_1(const\
    \ std::vector<int> &par,\n                                  const std::vector<int>\
    \ &bfs_order, F f) {}\n\ntemplate <class F>\nvoid one_third_centroid_decomposition(const\
    \ std::vector<int> &par,\n                                      const std::vector<int>\
    \ &bfs_order, F f) {}\n\n}  // namespace internal\n\ntemplate <int MODE, class\
    \ F>\nvoid centroid_decomposition(const std::vector<std::vector<int>> &tree, F\
    \ f) {\n    int n = (int)tree.size();\n    if (n == 1) return;\n    std::vector<int>\
    \ bfs_order(n), par(n, -1);\n    bfs_order[0] = 0;\n    int l = 0, r = 1;\n  \
    \  while (l < r) {\n        int v = bfs_order[l++];\n        for (auto nv : tree[v])\
    \ {\n            if (nv == par[v]) continue;\n            bfs_order[r++] = nv;\n\
    \            par[nv] = v;\n        }\n    }\n    assert(l == n && r == n);\n \
    \   {\n        std::vector<int> relabel(n);\n        for (int i : std::views::iota(0,\
    \ n)) {\n            relabel[bfs_order[i]] = i;\n        }\n        std::vector<int>\
    \ relabel_par(n, -1);\n        for (int i : std::views::iota(1, n)) {\n      \
    \      relabel_par[relabel[i]] = relabel[par[i]];\n        }\n        std::swap(par,\
    \ relabel_par);\n    }\n    static_assert(MODE == 0 || MODE == 1 || MODE == 2);\n\
    \    if constexpr (MODE == 0) {\n        internal::centroid_decomposition_dfs_0(par,\
    \ bfs_order, f);\n    } else if constexpr (MODE == 1) {\n    } else {\n      \
    \  internal::one_third_centroid_decomposition(par, bfs_order, f);\n    }\n}\n\n\
    }  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-01-04 03:14:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Frequency_Table_of_Tree.test.cpp
documentation_of: tree/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/tree/centroid_decomposition.hpp
- /library/tree/centroid_decomposition.hpp.html
title: tree/centroid_decomposition.hpp
---
