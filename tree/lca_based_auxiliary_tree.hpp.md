---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_901.test.cpp
    title: test/yuki/yuki_901.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_901_2.test.cpp
    title: test/yuki/yuki_901_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/lca_based_auxiliary_tree.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <ranges>\n#include <stack>\n#include <vector>\n\n\
    #line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#line 6 \"tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace ebi {\n\nstruct heavy_light_decomposition {\n  private:\n    void\
    \ dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n            if (nv == par[v])\
    \ continue;\n            par[nv] = v;\n            depth[nv] = depth[v] + 1;\n\
    \            dfs_sz(nv);\n            sz[v] += sz[nv];\n            if (sz[nv]\
    \ > sz[g[v][0]] || g[v][0] == par[v])\n                std::swap(nv, g[v][0]);\n\
    \        }\n    }\n\n    void dfs_hld(int v) {\n        in[v] = num++;\n     \
    \   rev[in[v]] = v;\n        for (auto nv : g[v]) {\n            if (nv == par[v])\
    \ continue;\n            nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n          \
    \  dfs_hld(nv);\n        }\n        out[v] = num;\n    }\n\n    // [u, v) \u30D1\
    \u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {\n        std::vector<std::pair<int, int>>\
    \ res;\n        while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u],\
    \ in[nxt[u]]);\n            u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \  public:\n    heavy_light_decomposition(const std::vector<std::vector<int>>\
    \ &gh,\n                              int root = 0)\n        : n((int)gh.size()),\n\
    \          g(gh),\n          sz(n, 1),\n          in(n),\n          out(n),\n\
    \          nxt(n),\n          par(n, -1),\n          depth(n, 0),\n          rev(n)\
    \ {\n        nxt[root] = root;\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n\n    int idx(int u) const {\n        return in[u];\n    }\n\n    int\
    \ rev_idx(int i) const {\n        return rev[i];\n    }\n\n    int la(int v, int\
    \ k) const {\n        while (1) {\n            int u = nxt[v];\n            if\
    \ (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -= in[v] - in[u]\
    \ + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u, int v)\
    \ const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u] < in[v])\
    \ std::swap(u, v);\n            u = par[nxt[u]];\n        }\n        return depth[u]\
    \ < depth[v] ? u : v;\n    }\n\n    int jump(int s, int t, int i) const {\n  \
    \      if (i == 0) return s;\n        int l = lca(s, t);\n        int d = depth[s]\
    \ + depth[t] - depth[l] * 2;\n        if (d < i) return -1;\n        if (depth[s]\
    \ - depth[l] >= i) return la(s, i);\n        i = d - i;\n        return la(t,\
    \ i);\n    }\n\n    std::vector<int> path(int s, int t) const {\n        int l\
    \ = lca(s, t);\n        std::vector<int> a, b;\n        for (; s != l; s = par[s])\
    \ a.emplace_back(s);\n        for (; t != l; t = par[t]) b.emplace_back(t);\n\
    \        a.emplace_back(l);\n        std::reverse(b.begin(), b.end());\n     \
    \   a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n\n    int\
    \ parent(int u) const {\n        return par[u];\n    }\n\n    int distance(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\n    int distance_from_root(int v) const {\n        return depth[v];\n\
    \    }\n\n    bool at_path(int u, int v, int s) const {\n        return distance(u,\
    \ v) == distance(u, s) + distance(s, v);\n    }\n\n    template <class F>\n  \
    \  void path_noncommutative_query(int u, int v, bool vertex,\n               \
    \                    const F &f) const {\n        int l = lca(u, v);\n       \
    \ for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex) f(in[l],\
    \ in[l] + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\
    \n    std::vector<std::pair<int, int>> path_sections(int u, int v,\n         \
    \                                          bool vertex) const {\n        int l\
    \ = lca(u, v);\n        std::vector<std::pair<int, int>> sections;\n        for\
    \ (auto [a, b] : ascend(u, l)) sections.emplace_back(a + 1, b);\n        if (vertex)\
    \ sections.emplace_back(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l,\
    \ v)) sections.emplace_back(a, b + 1);\n        return sections;\n    }\n\n  \
    \  template <class F>\n    int max_path(int u, int v, bool vertex, F binary_search)\
    \ const {\n        int prev = -1;\n        int l = lca(u, v);\n        for (auto\
    \ [a, b] : ascend(u, l)) {\n            a++;\n            int m = binary_search(a,\
    \ b);\n            if (m == b) {\n                prev = rev[b];\n           \
    \ } else {\n                return (m == a ? prev : rev[m]);\n            }\n\
    \        }\n        if (vertex) {\n            int m = binary_search(in[l], in[l]\
    \ + 1);\n            if (m == in[l]) {\n                return prev;\n       \
    \     } else {\n                prev = l;\n            }\n        }\n        for\
    \ (auto [a, b] : descend(l, v)) {\n            b++;\n            int m = binary_search(a,\
    \ b);\n            if (m == b) {\n                prev = rev[b - 1];\n       \
    \     } else {\n                return m == a ? prev : rev[m - 1];\n         \
    \   }\n        }\n        return v;\n    }\n\n    template <class F> void subtree_query(int\
    \ u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex), out[u]);\n  \
    \  }\n\n    const std::vector<int> &dfs_order() const {\n        return rev;\n\
    \    }\n\n    std::vector<std::pair<int, int>> lca_based_auxiliary_tree_dfs_order(\n\
    \        std::vector<int> vs) const;\n\n    std::pair<std::vector<int>, std::vector<std::vector<int>>>\n\
    \    lca_based_auxiliary_tree(std::vector<int> vs) const;\n\n  private:\n    int\
    \ n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> sz, in, out,\
    \ nxt, par, depth, rev;\n\n    int num = 0;\n};\n\n}  // namespace ebi\n#line\
    \ 10 \"tree/lca_based_auxiliary_tree.hpp\"\n\nnamespace ebi {\n\nstd::vector<std::pair<int,\
    \ int>>\nheavy_light_decomposition::lca_based_auxiliary_tree_dfs_order(\n    std::vector<int>\
    \ vs) const {\n    if (vs.empty()) return {};\n    std::sort(vs.begin(), vs.end(),\n\
    \              [&](int u, int v) -> bool { return in[u] < in[v]; });\n    auto\
    \ s = vs;\n    for (int i = 1; i < int(vs.size()); i++) {\n        s.emplace_back(lca(vs[i\
    \ - 1], vs[i]));\n    }\n    std::sort(s.begin(), s.end(),\n              [&](int\
    \ u, int v) -> bool { return in[u] < in[v]; });\n    s.erase(std::unique(s.begin(),\
    \ s.end()), s.end());\n    std::stack<int> stack;\n    stack.push(s[0]);\n   \
    \ int sz = s.size();\n    std::vector<std::pair<int, int>> dfs_order(sz);\n  \
    \  dfs_order[0] = {s[0], -1};\n    for (int i = 1; i < int(s.size()); i++) {\n\
    \        int v = s[i];\n        while (!stack.empty()) {\n            int u =\
    \ stack.top();\n            if (in[u] <= in[v] && in[v] < out[u]) {\n        \
    \        break;\n            } else {\n                stack.pop();\n        \
    \    }\n        }\n        assert(!stack.empty());\n        int par = stack.top();\n\
    \        dfs_order[i] = {v, par};\n        stack.push(v);\n    }\n    return dfs_order;\n\
    }\n\nstd::pair<std::vector<int>, std::vector<std::vector<int>>>\nheavy_light_decomposition::lca_based_auxiliary_tree(std::vector<int>\
    \ vs) const {\n    static std::vector<int> a(n, -1), p(n, -1);\n    int k = vs.size();\n\
    \    if (k == 1) {\n        return {vs, std::vector(1, std::vector<int>())};\n\
    \    }\n    std::sort(vs.begin(), vs.end(),\n              [&](int v, int u) {\
    \ return in[v] < in[u]; });\n    std::stack<int> stack;\n    std::vector<int>\
    \ s;\n    stack.push(vs[0]);\n    for (int i : std::views::iota(1, k)) {\n   \
    \     int w = lca(vs[i - 1], vs[i]);\n        int prev = -1;\n        while (!stack.empty()\
    \ && depth[w] <= depth[stack.top()]) {\n            if (prev != -1) {\n      \
    \          s.emplace_back(prev);\n                p[prev] = stack.top();\n   \
    \         }\n            prev = stack.top();\n            stack.pop();\n     \
    \   }\n        if (prev != w) {\n            assert(prev != -1);\n           \
    \ s.emplace_back(prev);\n            p[prev] = w;\n        }\n        stack.push(w);\n\
    \        stack.push(vs[i]);\n    }\n    {\n        int prev = -1;\n        while\
    \ (!stack.empty()) {\n            int v = stack.top();\n            s.emplace_back(v);\n\
    \            if (prev != -1) p[prev] = v;\n            prev = v;\n           \
    \ stack.pop();\n        }\n    }\n    std::reverse(s.begin(), s.end());\n    int\
    \ m = s.size();\n    for (int i : std::views::iota(0, m)) {\n        a[s[i]] =\
    \ i;\n    }\n    std::vector tree(m, std::vector<int>());\n    for (auto v : s)\
    \ {\n        if (p[v] < 0) continue;\n        tree[a[p[v]]].emplace_back(a[v]);\n\
    \    }\n    for (auto v : s) {\n        a[v] = -1;\n        p[v] = -1;\n    }\n\
    \    return {s, tree};\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <ranges>\n\
    #include <stack>\n#include <vector>\n\n#include \"../tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace ebi {\n\nstd::vector<std::pair<int, int>>\nheavy_light_decomposition::lca_based_auxiliary_tree_dfs_order(\n\
    \    std::vector<int> vs) const {\n    if (vs.empty()) return {};\n    std::sort(vs.begin(),\
    \ vs.end(),\n              [&](int u, int v) -> bool { return in[u] < in[v]; });\n\
    \    auto s = vs;\n    for (int i = 1; i < int(vs.size()); i++) {\n        s.emplace_back(lca(vs[i\
    \ - 1], vs[i]));\n    }\n    std::sort(s.begin(), s.end(),\n              [&](int\
    \ u, int v) -> bool { return in[u] < in[v]; });\n    s.erase(std::unique(s.begin(),\
    \ s.end()), s.end());\n    std::stack<int> stack;\n    stack.push(s[0]);\n   \
    \ int sz = s.size();\n    std::vector<std::pair<int, int>> dfs_order(sz);\n  \
    \  dfs_order[0] = {s[0], -1};\n    for (int i = 1; i < int(s.size()); i++) {\n\
    \        int v = s[i];\n        while (!stack.empty()) {\n            int u =\
    \ stack.top();\n            if (in[u] <= in[v] && in[v] < out[u]) {\n        \
    \        break;\n            } else {\n                stack.pop();\n        \
    \    }\n        }\n        assert(!stack.empty());\n        int par = stack.top();\n\
    \        dfs_order[i] = {v, par};\n        stack.push(v);\n    }\n    return dfs_order;\n\
    }\n\nstd::pair<std::vector<int>, std::vector<std::vector<int>>>\nheavy_light_decomposition::lca_based_auxiliary_tree(std::vector<int>\
    \ vs) const {\n    static std::vector<int> a(n, -1), p(n, -1);\n    int k = vs.size();\n\
    \    if (k == 1) {\n        return {vs, std::vector(1, std::vector<int>())};\n\
    \    }\n    std::sort(vs.begin(), vs.end(),\n              [&](int v, int u) {\
    \ return in[v] < in[u]; });\n    std::stack<int> stack;\n    std::vector<int>\
    \ s;\n    stack.push(vs[0]);\n    for (int i : std::views::iota(1, k)) {\n   \
    \     int w = lca(vs[i - 1], vs[i]);\n        int prev = -1;\n        while (!stack.empty()\
    \ && depth[w] <= depth[stack.top()]) {\n            if (prev != -1) {\n      \
    \          s.emplace_back(prev);\n                p[prev] = stack.top();\n   \
    \         }\n            prev = stack.top();\n            stack.pop();\n     \
    \   }\n        if (prev != w) {\n            assert(prev != -1);\n           \
    \ s.emplace_back(prev);\n            p[prev] = w;\n        }\n        stack.push(w);\n\
    \        stack.push(vs[i]);\n    }\n    {\n        int prev = -1;\n        while\
    \ (!stack.empty()) {\n            int v = stack.top();\n            s.emplace_back(v);\n\
    \            if (prev != -1) p[prev] = v;\n            prev = v;\n           \
    \ stack.pop();\n        }\n    }\n    std::reverse(s.begin(), s.end());\n    int\
    \ m = s.size();\n    for (int i : std::views::iota(0, m)) {\n        a[s[i]] =\
    \ i;\n    }\n    std::vector tree(m, std::vector<int>());\n    for (auto v : s)\
    \ {\n        if (p[v] < 0) continue;\n        tree[a[p[v]]].emplace_back(a[v]);\n\
    \    }\n    for (auto v : s) {\n        a[v] = -1;\n        p[v] = -1;\n    }\n\
    \    return {s, tree};\n}\n\n}  // namespace ebi"
  dependsOn:
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: false
  path: tree/lca_based_auxiliary_tree.hpp
  requiredBy: []
  timestamp: '2023-11-13 18:22:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_901_2.test.cpp
  - test/yuki/yuki_901.test.cpp
documentation_of: tree/lca_based_auxiliary_tree.hpp
layout: document
title: LCA based Auxiliary Tree
---

## 説明

$k$ 頂点 $vs$ を与え、その頂点とそれらのLCAからなる補助的な木を構築する。

### lca_based_auxiliary_tree_dfs_order(std::vector<int> vs)

返り値として、auxiliary treeのノードとその親の組をdfs順で返す。根の親は $-1$ としている。

### lca_based_auxiliary_tree(std::vector<int> vs)

返り値で補助的な木での頂点番号と元の木の頂点番号の対応を格納した配列と、補助的な木のグラフを返す。