---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/centroid_decomposition.hpp
    title: Centroid Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Vertex_Add_Range_Contour_Sum_on_Tree.test.cpp
    title: test/tree/Vertex_Add_Range_Contour_Sum_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Vertex_Get_Range_Contour_Add_on_Tree.test.cpp
    title: test/tree/Vertex_Get_Range_Contour_Add_on_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/contour_query_on_tree.hpp\"\n\n#include <cassert>\n\
    #include <ranges>\n#include <vector>\n\n#line 2 \"tree/centroid_decomposition.hpp\"\
    \n\n#include <algorithm>\n#line 7 \"tree/centroid_decomposition.hpp\"\n\nnamespace\
    \ ebi {\n\nnamespace internal {\n\ntemplate <class F>\nvoid centroid_decomposition_dfs_naive(const\
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
    \ namespace internal\n\ntemplate <int MODE, class F>\nvoid centroid_decomposition(const\
    \ std::vector<std::vector<int>> &tree, F f) {\n    int n = (int)tree.size();\n\
    \    if (n == 1) return;\n    std::vector<int> bfs_order(n), par(n, -1);\n   \
    \ bfs_order[0] = 0;\n    int l = 0, r = 1;\n    while (l < r) {\n        int v\
    \ = bfs_order[l++];\n        for (auto nv : tree[v]) {\n            if (nv ==\
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
    \ ebi\n#line 8 \"tree/contour_query_on_tree.hpp\"\n\nnamespace ebi {\n\nstruct\
    \ contour_query_on_tree {\n    contour_query_on_tree(const std::vector<std::vector<int>>\
    \ &tree)\n        : n(int(tree.size())) {\n        int t = 0;\n        range =\
    \ {0};\n        auto f = [&](const std::vector<int> &par, const std::vector<int>\
    \ &vs,\n                     const std::vector<int> &color) -> void {\n      \
    \      int sz = (int)par.size();\n            std::vector<int> depth(sz, 0);\n\
    \            for (const int v : std::views::iota(1, sz)) {\n                depth[v]\
    \ += depth[par[v]] + 1;\n            }\n            std::vector<int> red, blue;\n\
    \            for (const int v : std::views::iota(0, sz)) {\n                if\
    \ (color[v] == 0) {\n                    red.emplace_back(v);\n              \
    \  } else if (color[v] == 1) {\n                    blue.emplace_back(v);\n  \
    \              } else\n                    assert(color[v] == -1);\n         \
    \   }\n            if (red.empty() || blue.empty()) return;\n            int max_red\
    \ = -1;\n            for (const int v : red) {\n                vertexs.emplace_back(vs[v]);\n\
    \                number.emplace_back(t);\n                dep.emplace_back(depth[v]);\n\
    \                max_red = max_red < depth[v] ? depth[v] : max_red;\n        \
    \    }\n            range.emplace_back(range.back() + max_red + 1);\n        \
    \    t++;\n            int max_blue = -1;\n            for (const int v : blue)\
    \ {\n                vertexs.emplace_back(vs[v]);\n                number.emplace_back(t);\n\
    \                dep.emplace_back(depth[v]);\n                max_blue = max_blue\
    \ < depth[v] ? depth[v] : max_blue;\n            }\n            range.emplace_back(range.back()\
    \ + max_blue + 1);\n            t++;\n        };\n        centroid_decomposition<2>(tree,\
    \ f);\n        index_ptr.assign(n + 1, 0);\n        for (const int v : vertexs)\
    \ {\n            index_ptr[v + 1]++;\n        }\n        for (const int v : std::views::iota(0,\
    \ n)) {\n            index_ptr[v + 1] += index_ptr[v];\n        }\n        index.resize(index_ptr.back());\n\
    \        auto counter = index_ptr;\n        for (int i = 0; const int v : vertexs)\
    \ {\n            index[counter[v]++] = i;\n            i++;\n        }\n    }\n\
    \n    std::vector<std::pair<int, int>> get_contour_from_vertex(int v, int l,\n\
    \                                                             int r) const {\n\
    \        assert(0 <= v && v < n);\n        std::vector<std::pair<int, int>> res;\n\
    \        for (const int idx :\n             std::ranges::subrange(index.begin()\
    \ + index_ptr[v],\n                                   index.begin() + index_ptr[v\
    \ + 1])) {\n            int label = number[idx] ^ 1;\n            int left = l\
    \ - dep[idx], right = r - dep[idx];\n            int max = range[label + 1] -\
    \ range[label];\n            if (left < 0) left = 0;\n            if (right >\
    \ max) right = max;\n            if (left < right) {\n                res.emplace_back(range[label]\
    \ + left, range[label] + right);\n            }\n        }\n        return res;\n\
    \    }\n\n    std::vector<int> get_vertex(int v) const {\n        assert(0 <=\
    \ v && v < n);\n        std::vector<int> res;\n        for (const int idx :\n\
    \             std::ranges::subrange(index.begin() + index_ptr[v],\n          \
    \                         index.begin() + index_ptr[v + 1])) {\n            int\
    \ label = number[idx];\n            assert(range[label] + dep[idx] < range[label\
    \ + 1]);\n            res.emplace_back(range[label] + dep[idx]);\n        }\n\
    \        return res;\n    }\n\n    int size() const {\n        return range.back();\n\
    \    }\n\n  private:\n    int n;\n    std::vector<int> vertexs, number, dep;\n\
    \    std::vector<int> index, index_ptr;\n    std::vector<int> range;\n};\n\n}\
    \  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <ranges>\n#include <vector>\n\
    \n#include \"../tree/centroid_decomposition.hpp\"\n\nnamespace ebi {\n\nstruct\
    \ contour_query_on_tree {\n    contour_query_on_tree(const std::vector<std::vector<int>>\
    \ &tree)\n        : n(int(tree.size())) {\n        int t = 0;\n        range =\
    \ {0};\n        auto f = [&](const std::vector<int> &par, const std::vector<int>\
    \ &vs,\n                     const std::vector<int> &color) -> void {\n      \
    \      int sz = (int)par.size();\n            std::vector<int> depth(sz, 0);\n\
    \            for (const int v : std::views::iota(1, sz)) {\n                depth[v]\
    \ += depth[par[v]] + 1;\n            }\n            std::vector<int> red, blue;\n\
    \            for (const int v : std::views::iota(0, sz)) {\n                if\
    \ (color[v] == 0) {\n                    red.emplace_back(v);\n              \
    \  } else if (color[v] == 1) {\n                    blue.emplace_back(v);\n  \
    \              } else\n                    assert(color[v] == -1);\n         \
    \   }\n            if (red.empty() || blue.empty()) return;\n            int max_red\
    \ = -1;\n            for (const int v : red) {\n                vertexs.emplace_back(vs[v]);\n\
    \                number.emplace_back(t);\n                dep.emplace_back(depth[v]);\n\
    \                max_red = max_red < depth[v] ? depth[v] : max_red;\n        \
    \    }\n            range.emplace_back(range.back() + max_red + 1);\n        \
    \    t++;\n            int max_blue = -1;\n            for (const int v : blue)\
    \ {\n                vertexs.emplace_back(vs[v]);\n                number.emplace_back(t);\n\
    \                dep.emplace_back(depth[v]);\n                max_blue = max_blue\
    \ < depth[v] ? depth[v] : max_blue;\n            }\n            range.emplace_back(range.back()\
    \ + max_blue + 1);\n            t++;\n        };\n        centroid_decomposition<2>(tree,\
    \ f);\n        index_ptr.assign(n + 1, 0);\n        for (const int v : vertexs)\
    \ {\n            index_ptr[v + 1]++;\n        }\n        for (const int v : std::views::iota(0,\
    \ n)) {\n            index_ptr[v + 1] += index_ptr[v];\n        }\n        index.resize(index_ptr.back());\n\
    \        auto counter = index_ptr;\n        for (int i = 0; const int v : vertexs)\
    \ {\n            index[counter[v]++] = i;\n            i++;\n        }\n    }\n\
    \n    std::vector<std::pair<int, int>> get_contour_from_vertex(int v, int l,\n\
    \                                                             int r) const {\n\
    \        assert(0 <= v && v < n);\n        std::vector<std::pair<int, int>> res;\n\
    \        for (const int idx :\n             std::ranges::subrange(index.begin()\
    \ + index_ptr[v],\n                                   index.begin() + index_ptr[v\
    \ + 1])) {\n            int label = number[idx] ^ 1;\n            int left = l\
    \ - dep[idx], right = r - dep[idx];\n            int max = range[label + 1] -\
    \ range[label];\n            if (left < 0) left = 0;\n            if (right >\
    \ max) right = max;\n            if (left < right) {\n                res.emplace_back(range[label]\
    \ + left, range[label] + right);\n            }\n        }\n        return res;\n\
    \    }\n\n    std::vector<int> get_vertex(int v) const {\n        assert(0 <=\
    \ v && v < n);\n        std::vector<int> res;\n        for (const int idx :\n\
    \             std::ranges::subrange(index.begin() + index_ptr[v],\n          \
    \                         index.begin() + index_ptr[v + 1])) {\n            int\
    \ label = number[idx];\n            assert(range[label] + dep[idx] < range[label\
    \ + 1]);\n            res.emplace_back(range[label] + dep[idx]);\n        }\n\
    \        return res;\n    }\n\n    int size() const {\n        return range.back();\n\
    \    }\n\n  private:\n    int n;\n    std::vector<int> vertexs, number, dep;\n\
    \    std::vector<int> index, index_ptr;\n    std::vector<int> range;\n};\n\n}\
    \  // namespace ebi"
  dependsOn:
  - tree/centroid_decomposition.hpp
  isVerificationFile: false
  path: tree/contour_query_on_tree.hpp
  requiredBy: []
  timestamp: '2024-01-04 19:22:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Vertex_Add_Range_Contour_Sum_on_Tree.test.cpp
  - test/tree/Vertex_Get_Range_Contour_Add_on_Tree.test.cpp
documentation_of: tree/contour_query_on_tree.hpp
layout: document
title: Contour Query on Tree
---

## 説明

頂点 $v$ と距離が $[l, r)$ である頂点に対するクエリを処理するための構造体。構築 $O(N\log{N})$

### できること

- [1点更新区間取得](https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree)
- [1点取得区間更新](https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree)

### できないこと

- 区間更新区間所得
頂点 $v$ への作用が頂点 $v$ に関わるインデックスすべてに対して行わないといけないため。 $1$ 点更新ならば、更新すべきノードが $O(\log{N})$ であるため可能。 $1$ 点取得ならば、所得の際に頂点 $v$ に関わるインデックスをなめることで可能。

### get_contour_from_vertex(int v, int l, int r)

頂点 $v$ と距離が $[l, r)$ であるような頂点の属する区間を返す。 $O(\log{N})$

距離が $0$ であるよう場合は含まれないので別途処理が必要。

### get_vertex(int v)

頂点 $v$ に関わるインデックスを返す。 $O(\log{N})$