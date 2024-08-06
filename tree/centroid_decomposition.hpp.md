---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/contour_query_on_tree.hpp
    title: Contour Query on Tree
  - icon: ':heavy_check_mark:'
    path: tree/contour_query_on_weighted_tree.hpp
    title: Contour Query on Tree (Weighted)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Vertex_Add_Range_Contour_Sum_on_Tree.test.cpp
    title: test/tree/Vertex_Add_Range_Contour_Sum_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp
    title: test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Vertex_Get_Range_Contour_Add_on_Tree.test.cpp
    title: test/tree/Vertex_Get_Range_Contour_Add_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1038.test.cpp
    title: test/yuki/yuki_1038.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1796.test.cpp
    title: test/yuki/yuki_1796.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/centroid_decomposition.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <ranges>\n#include <vector>\n\nnamespace ebi {\n\n\
    namespace internal {\n\ntemplate <class F>\nvoid centroid_decomposition_dfs_naive(const\
    \ std::vector<int> &par,\n                                      const std::vector<int>\
    \ &original_vs,\n                                      F f) {\n    const int n\
    \ = (int)par.size();\n    assert(par.size() == original_vs.size());\n    int center\
    \ = -1;\n    std::vector<int> sz(n, 1);\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n    std::vector<int> color(n, -1);\n    std::vector<int> vs = {center};\n\
    \    color[center] = 0;\n    int c = 1;\n    for (const int v : std::views::iota(1,\
    \ n)) {\n        if (par[v] == center) {\n            vs.emplace_back(v);\n  \
    \          color[v] = c++;\n        }\n    }\n    if (center > 0) {\n        for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n            vs.emplace_back(v);\n\
    \            color[v] = c;\n        }\n        c++;\n    }\n    for (const int\
    \ v : std::views::iota(0, n)) {\n        if (color[v] == -1) {\n            vs.emplace_back(v);\n\
    \            color[v] = color[par[v]];\n        }\n    }\n    std::vector<int>\
    \ index_ptr(c + 1, 0);\n    for (const int v : std::views::iota(0, n)) {\n   \
    \     index_ptr[color[v] + 1]++;\n    }\n    for (const int i : std::views::iota(0,\
    \ c)) {\n        index_ptr[i + 1] += index_ptr[i];\n    }\n    auto counter =\
    \ index_ptr;\n    std::vector<int> ord(n);\n    for (auto v : vs) {\n        ord[counter[color[v]]++]\
    \ = v;\n    }\n    std::vector<int> relabel(n);\n    for (const int v : std::views::iota(0,\
    \ n)) {\n        relabel[ord[v]] = v;\n    }\n    std::vector<int> original_vs2(n);\n\
    \    for (const int v : std::views::iota(0, n)) {\n        original_vs2[relabel[v]]\
    \ = original_vs[v];\n    }\n    std::vector<int> relabel_par(n, -1);\n    for\
    \ (int v : std::views::iota(1, n)) {\n        int a = relabel[v];\n        int\
    \ b = relabel[par[v]];\n        if (a > b) std::swap(a, b);\n        relabel_par[b]\
    \ = a;\n    }\n    f(relabel_par, original_vs2, index_ptr);\n    for (const int\
    \ i : std::views::iota(1, c)) {\n        int l = index_ptr[i], r = index_ptr[i\
    \ + 1];\n        std::vector<int> par1(r - l, -1);\n        std::vector<int> original_vs1(r\
    \ - l, -1);\n        for (int v : std::views::iota(l, r)) {\n            par1[v\
    \ - l] = (relabel_par[v] == 0 ? -1 : relabel_par[v] - l);\n            original_vs1[v\
    \ - l] = original_vs2[v];\n        }\n        centroid_decomposition_dfs_naive(par1,\
    \ original_vs1, f);\n    }\n    return;\n}\n\ntemplate <class F>\nvoid one_third_centroid_decomposition(const\
    \ std::vector<int> &par,\n                                      const std::vector<int>\
    \ &original_vs,\n                                      F f) {\n    const int n\
    \ = (int)par.size();\n    assert(n > 1);\n    if (n == 2) return;\n    int center\
    \ = -1;\n    std::vector<int> sz(n, 1);\n\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n\n    std::vector<int> color(n, -1);\n    std::vector<int> ord(n, -1);\n\
    \    ord[center] = 0;\n    int t = 1;\n    int red = n - sz[center];\n    for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n        ord[v] = t++;\n      \
    \  color[v] = 0;\n    }\n    for (const int v : std::views::iota(1, n)) {\n  \
    \      if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {\n         \
    \   red += sz[v];\n            ord[v] = t++;\n            color[v] = 0;\n    \
    \    }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        if (v\
    \ != center && color[v] == -1 && color[par[v]] == 0) {\n            ord[v] = t++;\n\
    \            color[v] = 0;\n        }\n    }\n    const int n0 = t - 1;\n    for\
    \ (const int v : std::views::iota(1, n)) {\n        if (v != center && color[v]\
    \ == -1) {\n            ord[v] = t++;\n            color[v] = 1;\n        }\n\
    \    }\n    assert(t == n);\n    const int n1 = n - 1 - n0;\n    std::vector<int>\
    \ par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);\n    std::vector<int> original_vs0(n0\
    \ + 1), original_vs1(n1 + 1),\n        original_vs2(n);\n    for (const int i\
    \ : std::views::iota(0, n)) {\n        int v = ord[i];\n        original_vs2[v]\
    \ = original_vs[i];\n        if (color[i] != 1) {\n            original_vs0[v]\
    \ = original_vs[i];\n        }\n        if (color[i] != 0) {\n            int\
    \ idx = std::max(v - n0, 0);\n            original_vs1[idx] = original_vs[i];\n\
    \        }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        int\
    \ a = ord[v], b = ord[par[v]];\n        if (a > b) std::swap(a, b);\n        par2[b]\
    \ = a;\n        if (color[v] != 1 && color[par[v]] != 1) {\n            par0[b]\
    \ = a;\n        }\n        if (color[v] != 0 && color[par[v]] != 0) {\n      \
    \      par1[b - n0] = std::max(a - n0, 0);\n        }\n    }\n    f(par2, original_vs2,\
    \ n0, n1);\n    one_third_centroid_decomposition(par0, original_vs0, f);\n   \
    \ one_third_centroid_decomposition(par1, original_vs1, f);\n    return;\n}\n\n\
    template <class F>\nvoid one_third_centroid_decomposition_virtual_real(\n    const\
    \ std::vector<int> &par, const std::vector<int> &original_vs,\n    const std::vector<int>\
    \ &is_real, F f) {\n    const int n = (int)par.size();\n    assert(n > 1);\n \
    \   if (n == 2) {\n        if (is_real[0] && is_real[1]) {\n            f(par,\
    \ original_vs, {0, 1});\n        }\n        return;\n    }\n    int center = -1;\n\
    \    std::vector<int> sz(n, 1);\n\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n\n    std::vector<int> color(n, -1);\n    std::vector<int> ord(n, -1);\n\
    \    ord[center] = 0;\n    int t = 1;\n    int red = n - sz[center];\n    for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n        ord[v] = t++;\n      \
    \  color[v] = 0;\n    }\n    for (const int v : std::views::iota(1, n)) {\n  \
    \      if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {\n         \
    \   red += sz[v];\n            ord[v] = t++;\n            color[v] = 0;\n    \
    \    }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        if (v\
    \ != center && color[v] == -1 && color[par[v]] == 0) {\n            ord[v] = t++;\n\
    \            color[v] = 0;\n        }\n    }\n    const int n0 = t - 1;\n    for\
    \ (const int v : std::views::iota(1, n)) {\n        if (v != center && color[v]\
    \ == -1) {\n            ord[v] = t++;\n            color[v] = 1;\n        }\n\
    \    }\n    assert(t == n);\n    const int n1 = n - 1 - n0;\n    std::vector<int>\
    \ par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);\n    std::vector<int> original_vs0(n0\
    \ + 1), original_vs1(n1 + 1),\n        original_vs2(n);\n    std::vector<int>\
    \ is_real0(n0 + 1), is_real1(n1 + 1), is_real2(n);\n    for (const int i : std::views::iota(0,\
    \ n)) {\n        int v = ord[i];\n        original_vs2[v] = original_vs[i];\n\
    \        is_real2[v] = is_real[i];\n        if (color[i] != 1) {\n           \
    \ original_vs0[v] = original_vs[i];\n            is_real0[v] = is_real[i];\n \
    \       }\n        if (color[i] != 0) {\n            int idx = std::max(v - n0,\
    \ 0);\n            original_vs1[idx] = original_vs[i];\n            is_real1[idx]\
    \ = is_real[i];\n        }\n    }\n    for (const int v : std::views::iota(1,\
    \ n)) {\n        int a = ord[v], b = ord[par[v]];\n        if (a > b) std::swap(a,\
    \ b);\n        par2[b] = a;\n        if (color[v] != 1 && color[par[v]] != 1)\
    \ {\n            par0[b] = a;\n        }\n        if (color[v] != 0 && color[par[v]]\
    \ != 0) {\n            par1[b - n0] = std::max(a - n0, 0);\n        }\n    }\n\
    \    if (is_real[center]) {\n        color.assign(n, -1);\n        color[0] =\
    \ 0;\n        for (const int v : std::views::iota(1, n)) {\n            if (is_real2[v])\
    \ color[v] = 1;\n        }\n        f(par2, original_vs2, color);\n        is_real0[0]\
    \ = is_real1[0] = is_real2[0] = 0;\n    }\n    color.assign(n, -1);\n    for (const\
    \ int v : std::views::iota(1, n)) {\n        if (is_real2[v]) {\n            color[v]\
    \ = int(v > n0);\n        }\n    }\n    f(par2, original_vs2, color);\n    one_third_centroid_decomposition_virtual_real(par0,\
    \ original_vs0, is_real0,\n                                                  f);\n\
    \    one_third_centroid_decomposition_virtual_real(par1, original_vs1, is_real1,\n\
    \                                                  f);\n    return;\n}\n\n}  //\
    \ namespace internal\n\ntemplate <int MODE, class T, class F>\nvoid centroid_decomposition(const\
    \ Graph<T> &tree, F f) {\n    int n = (int)tree.size();\n    if (n == 1) return;\n\
    \    std::vector<int> bfs_order(n), par(n, -1);\n    bfs_order[0] = 0;\n    int\
    \ l = 0, r = 1;\n    while (l < r) {\n        int v = bfs_order[l++];\n      \
    \  for (auto e : tree[v]) {\n            int nv = e.to;\n            if (nv ==\
    \ par[v]) continue;\n            bfs_order[r++] = nv;\n            par[nv] = v;\n\
    \        }\n    }\n    assert(l == n && r == n);\n    {\n        std::vector<int>\
    \ relabel(n);\n        for (int i : std::views::iota(0, n)) {\n            relabel[bfs_order[i]]\
    \ = i;\n        }\n        std::vector<int> relabel_par(n, -1);\n        for (int\
    \ i : std::views::iota(1, n)) {\n            relabel_par[relabel[i]] = relabel[par[i]];\n\
    \        }\n        std::swap(par, relabel_par);\n    }\n    static_assert(MODE\
    \ == 0 || MODE == 1 || MODE == 2);\n    if constexpr (MODE == 0) {\n        internal::centroid_decomposition_dfs_naive(par,\
    \ bfs_order, f);\n    } else if constexpr (MODE == 1) {\n        internal::one_third_centroid_decomposition(par,\
    \ bfs_order, f);\n    } else {\n        internal::one_third_centroid_decomposition_virtual_real(\n\
    \            par, bfs_order, std::vector<int>(n, 1), f);\n    }\n}\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <ranges>\n\
    #include <vector>\n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <class\
    \ F>\nvoid centroid_decomposition_dfs_naive(const std::vector<int> &par,\n   \
    \                                   const std::vector<int> &original_vs,\n   \
    \                                   F f) {\n    const int n = (int)par.size();\n\
    \    assert(par.size() == original_vs.size());\n    int center = -1;\n    std::vector<int>\
    \ sz(n, 1);\n    for (const int v : std::views::iota(0, n) | std::views::reverse)\
    \ {\n        if (sz[v] >= (n + 1) / 2) {\n            center = v;\n          \
    \  break;\n        }\n        sz[par[v]] += sz[v];\n    }\n    std::vector<int>\
    \ color(n, -1);\n    std::vector<int> vs = {center};\n    color[center] = 0;\n\
    \    int c = 1;\n    for (const int v : std::views::iota(1, n)) {\n        if\
    \ (par[v] == center) {\n            vs.emplace_back(v);\n            color[v]\
    \ = c++;\n        }\n    }\n    if (center > 0) {\n        for (int v = par[center];\
    \ v != -1; v = par[v]) {\n            vs.emplace_back(v);\n            color[v]\
    \ = c;\n        }\n        c++;\n    }\n    for (const int v : std::views::iota(0,\
    \ n)) {\n        if (color[v] == -1) {\n            vs.emplace_back(v);\n    \
    \        color[v] = color[par[v]];\n        }\n    }\n    std::vector<int> index_ptr(c\
    \ + 1, 0);\n    for (const int v : std::views::iota(0, n)) {\n        index_ptr[color[v]\
    \ + 1]++;\n    }\n    for (const int i : std::views::iota(0, c)) {\n        index_ptr[i\
    \ + 1] += index_ptr[i];\n    }\n    auto counter = index_ptr;\n    std::vector<int>\
    \ ord(n);\n    for (auto v : vs) {\n        ord[counter[color[v]]++] = v;\n  \
    \  }\n    std::vector<int> relabel(n);\n    for (const int v : std::views::iota(0,\
    \ n)) {\n        relabel[ord[v]] = v;\n    }\n    std::vector<int> original_vs2(n);\n\
    \    for (const int v : std::views::iota(0, n)) {\n        original_vs2[relabel[v]]\
    \ = original_vs[v];\n    }\n    std::vector<int> relabel_par(n, -1);\n    for\
    \ (int v : std::views::iota(1, n)) {\n        int a = relabel[v];\n        int\
    \ b = relabel[par[v]];\n        if (a > b) std::swap(a, b);\n        relabel_par[b]\
    \ = a;\n    }\n    f(relabel_par, original_vs2, index_ptr);\n    for (const int\
    \ i : std::views::iota(1, c)) {\n        int l = index_ptr[i], r = index_ptr[i\
    \ + 1];\n        std::vector<int> par1(r - l, -1);\n        std::vector<int> original_vs1(r\
    \ - l, -1);\n        for (int v : std::views::iota(l, r)) {\n            par1[v\
    \ - l] = (relabel_par[v] == 0 ? -1 : relabel_par[v] - l);\n            original_vs1[v\
    \ - l] = original_vs2[v];\n        }\n        centroid_decomposition_dfs_naive(par1,\
    \ original_vs1, f);\n    }\n    return;\n}\n\ntemplate <class F>\nvoid one_third_centroid_decomposition(const\
    \ std::vector<int> &par,\n                                      const std::vector<int>\
    \ &original_vs,\n                                      F f) {\n    const int n\
    \ = (int)par.size();\n    assert(n > 1);\n    if (n == 2) return;\n    int center\
    \ = -1;\n    std::vector<int> sz(n, 1);\n\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n\n    std::vector<int> color(n, -1);\n    std::vector<int> ord(n, -1);\n\
    \    ord[center] = 0;\n    int t = 1;\n    int red = n - sz[center];\n    for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n        ord[v] = t++;\n      \
    \  color[v] = 0;\n    }\n    for (const int v : std::views::iota(1, n)) {\n  \
    \      if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {\n         \
    \   red += sz[v];\n            ord[v] = t++;\n            color[v] = 0;\n    \
    \    }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        if (v\
    \ != center && color[v] == -1 && color[par[v]] == 0) {\n            ord[v] = t++;\n\
    \            color[v] = 0;\n        }\n    }\n    const int n0 = t - 1;\n    for\
    \ (const int v : std::views::iota(1, n)) {\n        if (v != center && color[v]\
    \ == -1) {\n            ord[v] = t++;\n            color[v] = 1;\n        }\n\
    \    }\n    assert(t == n);\n    const int n1 = n - 1 - n0;\n    std::vector<int>\
    \ par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);\n    std::vector<int> original_vs0(n0\
    \ + 1), original_vs1(n1 + 1),\n        original_vs2(n);\n    for (const int i\
    \ : std::views::iota(0, n)) {\n        int v = ord[i];\n        original_vs2[v]\
    \ = original_vs[i];\n        if (color[i] != 1) {\n            original_vs0[v]\
    \ = original_vs[i];\n        }\n        if (color[i] != 0) {\n            int\
    \ idx = std::max(v - n0, 0);\n            original_vs1[idx] = original_vs[i];\n\
    \        }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        int\
    \ a = ord[v], b = ord[par[v]];\n        if (a > b) std::swap(a, b);\n        par2[b]\
    \ = a;\n        if (color[v] != 1 && color[par[v]] != 1) {\n            par0[b]\
    \ = a;\n        }\n        if (color[v] != 0 && color[par[v]] != 0) {\n      \
    \      par1[b - n0] = std::max(a - n0, 0);\n        }\n    }\n    f(par2, original_vs2,\
    \ n0, n1);\n    one_third_centroid_decomposition(par0, original_vs0, f);\n   \
    \ one_third_centroid_decomposition(par1, original_vs1, f);\n    return;\n}\n\n\
    template <class F>\nvoid one_third_centroid_decomposition_virtual_real(\n    const\
    \ std::vector<int> &par, const std::vector<int> &original_vs,\n    const std::vector<int>\
    \ &is_real, F f) {\n    const int n = (int)par.size();\n    assert(n > 1);\n \
    \   if (n == 2) {\n        if (is_real[0] && is_real[1]) {\n            f(par,\
    \ original_vs, {0, 1});\n        }\n        return;\n    }\n    int center = -1;\n\
    \    std::vector<int> sz(n, 1);\n\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n\n    std::vector<int> color(n, -1);\n    std::vector<int> ord(n, -1);\n\
    \    ord[center] = 0;\n    int t = 1;\n    int red = n - sz[center];\n    for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n        ord[v] = t++;\n      \
    \  color[v] = 0;\n    }\n    for (const int v : std::views::iota(1, n)) {\n  \
    \      if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {\n         \
    \   red += sz[v];\n            ord[v] = t++;\n            color[v] = 0;\n    \
    \    }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        if (v\
    \ != center && color[v] == -1 && color[par[v]] == 0) {\n            ord[v] = t++;\n\
    \            color[v] = 0;\n        }\n    }\n    const int n0 = t - 1;\n    for\
    \ (const int v : std::views::iota(1, n)) {\n        if (v != center && color[v]\
    \ == -1) {\n            ord[v] = t++;\n            color[v] = 1;\n        }\n\
    \    }\n    assert(t == n);\n    const int n1 = n - 1 - n0;\n    std::vector<int>\
    \ par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);\n    std::vector<int> original_vs0(n0\
    \ + 1), original_vs1(n1 + 1),\n        original_vs2(n);\n    std::vector<int>\
    \ is_real0(n0 + 1), is_real1(n1 + 1), is_real2(n);\n    for (const int i : std::views::iota(0,\
    \ n)) {\n        int v = ord[i];\n        original_vs2[v] = original_vs[i];\n\
    \        is_real2[v] = is_real[i];\n        if (color[i] != 1) {\n           \
    \ original_vs0[v] = original_vs[i];\n            is_real0[v] = is_real[i];\n \
    \       }\n        if (color[i] != 0) {\n            int idx = std::max(v - n0,\
    \ 0);\n            original_vs1[idx] = original_vs[i];\n            is_real1[idx]\
    \ = is_real[i];\n        }\n    }\n    for (const int v : std::views::iota(1,\
    \ n)) {\n        int a = ord[v], b = ord[par[v]];\n        if (a > b) std::swap(a,\
    \ b);\n        par2[b] = a;\n        if (color[v] != 1 && color[par[v]] != 1)\
    \ {\n            par0[b] = a;\n        }\n        if (color[v] != 0 && color[par[v]]\
    \ != 0) {\n            par1[b - n0] = std::max(a - n0, 0);\n        }\n    }\n\
    \    if (is_real[center]) {\n        color.assign(n, -1);\n        color[0] =\
    \ 0;\n        for (const int v : std::views::iota(1, n)) {\n            if (is_real2[v])\
    \ color[v] = 1;\n        }\n        f(par2, original_vs2, color);\n        is_real0[0]\
    \ = is_real1[0] = is_real2[0] = 0;\n    }\n    color.assign(n, -1);\n    for (const\
    \ int v : std::views::iota(1, n)) {\n        if (is_real2[v]) {\n            color[v]\
    \ = int(v > n0);\n        }\n    }\n    f(par2, original_vs2, color);\n    one_third_centroid_decomposition_virtual_real(par0,\
    \ original_vs0, is_real0,\n                                                  f);\n\
    \    one_third_centroid_decomposition_virtual_real(par1, original_vs1, is_real1,\n\
    \                                                  f);\n    return;\n}\n\n}  //\
    \ namespace internal\n\ntemplate <int MODE, class T, class F>\nvoid centroid_decomposition(const\
    \ Graph<T> &tree, F f) {\n    int n = (int)tree.size();\n    if (n == 1) return;\n\
    \    std::vector<int> bfs_order(n), par(n, -1);\n    bfs_order[0] = 0;\n    int\
    \ l = 0, r = 1;\n    while (l < r) {\n        int v = bfs_order[l++];\n      \
    \  for (auto e : tree[v]) {\n            int nv = e.to;\n            if (nv ==\
    \ par[v]) continue;\n            bfs_order[r++] = nv;\n            par[nv] = v;\n\
    \        }\n    }\n    assert(l == n && r == n);\n    {\n        std::vector<int>\
    \ relabel(n);\n        for (int i : std::views::iota(0, n)) {\n            relabel[bfs_order[i]]\
    \ = i;\n        }\n        std::vector<int> relabel_par(n, -1);\n        for (int\
    \ i : std::views::iota(1, n)) {\n            relabel_par[relabel[i]] = relabel[par[i]];\n\
    \        }\n        std::swap(par, relabel_par);\n    }\n    static_assert(MODE\
    \ == 0 || MODE == 1 || MODE == 2);\n    if constexpr (MODE == 0) {\n        internal::centroid_decomposition_dfs_naive(par,\
    \ bfs_order, f);\n    } else if constexpr (MODE == 1) {\n        internal::one_third_centroid_decomposition(par,\
    \ bfs_order, f);\n    } else {\n        internal::one_third_centroid_decomposition_virtual_real(\n\
    \            par, bfs_order, std::vector<int>(n, 1), f);\n    }\n}\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid_decomposition.hpp
  requiredBy:
  - tree/contour_query_on_tree.hpp
  - tree/contour_query_on_weighted_tree.hpp
  timestamp: '2024-03-12 17:35:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_1038.test.cpp
  - test/yuki/yuki_1796.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
  - test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
  - test/tree/Vertex_Add_Range_Contour_Sum_on_Tree.test.cpp
  - test/tree/Vertex_Get_Range_Contour_Add_on_Tree.test.cpp
documentation_of: tree/centroid_decomposition.hpp
layout: document
title: Centroid Decomposition
---

## 説明

重心分解を行い、重心分解後の各木に対して関数 $f$ を適用する。下記のように使用する。ここで `MODE` の値によって指定した MODE で実行される。

```
centroid_decomposition<MODE>(tree, f)
```

### 共通の仕様

重心分解後の木は $par$ で与えられ、頂点 $v$ の親が $par[v]$ となっている。また、重心分解後の頂点 $v$ の元の木の頂点番号は $vs[v]$ となっている。

### MODE 0

通常の重心分解をする。下記のような関数 $f$ を重心分解後の木について適用する。

```
f(const std::vector<int> &par, const std::vector<int> &vs, const std::vector<int> &index_ptr)
```

重心、重心の部分木をそれぞれ異なる色で塗る。ここで、重心の色は $0$ である。
色 $c$ の頂点数は $(index\\_ptr[c+1] - index\\_ptr[c])$ 個であり、頂点番号は $index\\_ptr[c]$ から $index\\_ptr[c+1]$ となっている。

### MODE 1

$\frac{1}{3}$ 重心分解を行う。下記のような関数 $f$ を重心分解後の木について適用する。パスの長さが $1$ のものについては処理しないため別途処理が必要。

```
f(const std::vector<int> &par, const std::vector<int> &vs, int n0, int n1)
```

重心の部分木を $2$ 色に塗り分ける。ここで、頂点 $0$ が重心、 $[1, 1 + n0)$ が色 $0$ 、 $[1 + n0, 1 + n0 + n2)$ が色 $1$ となっている。

辺の本数がだいたい $\frac{1}{2}$ になるように分割しているため、再帰の深さが $O(log{N})$ となる。一方で、各頂点の表れる回数は抑えられていないため注意。（スターグラフなど）

### MODE 2

$\frac{1}{3}$ 重心分解を行う。下記のような関数 $f$ を重心分解後の木について適用する。

```
f(const std::vector<int> &par, const std::vector<int> &vs, const std::vector<int> &color)
```

頂点には $virtual$ 属性と $real$ 属性があり、 $color[v] = -1$ のとき頂点 $v$ は $virtual$ 属性である。頂点は $2$ 色で塗られており、 $color$ に色が格納されている。

各頂点の $real$ 属性で表れる回数が $O(\log{N})$ となる。始点を固定した場合のパスの処理などで活用できる。なお、 $virtual$ 属性で表れる回数は抑えられていないため注意。

## reference

- [重心分解・1/3重心分解のお絵描き](https://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d)
- [Theoretically Faster HLD and Centroid Decomposition](https://codeforces.com/blog/entry/104997)