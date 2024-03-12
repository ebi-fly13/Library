---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: tree/centroid_decomposition.hpp
    title: Centroid Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/contour_query_on_weighted_tree.hpp\"\n\n#include <cassert>\n\
    #include <ranges>\n#include <tuple>\n#include <vector>\n\n#line 2 \"graph/base.hpp\"\
    \n\n#line 4 \"graph/base.hpp\"\n#include <iostream>\n#line 7 \"graph/base.hpp\"\
    \n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 4 \"data_structure/simple_csr.hpp\"\
    \n#include <utility>\n#line 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class E> struct simple_csr {\n    simple_csr() = default;\n\n\
    \    simple_csr(int n, const std::vector<std::pair<int, E>>& elements)\n     \
    \   : start(n + 1, 0), elist(elements.size()) {\n        for (auto e : elements)\
    \ {\n            start[e.first + 1]++;\n        }\n        for (auto i : std::views::iota(0,\
    \ n)) {\n            start[i + 1] += start[i];\n        }\n        auto counter\
    \ = start;\n        for (auto [i, e] : elements) {\n            elist[counter[i]++]\
    \ = e;\n        }\n    }\n\n    simple_csr(const std::vector<std::vector<E>>&\
    \ es)\n        : start(es.size() + 1, 0) {\n        int n = es.size();\n     \
    \   for (auto i : std::views::iota(0, n)) {\n            start[i + 1] = (int)es[i].size()\
    \ + start[i];\n        }\n        elist.resize(start.back());\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            std::copy(es[i].begin(), es[i].end(),\
    \ elist.begin() + start[i]);\n        }\n    }\n\n    int size() const {\n   \
    \     return (int)start.size() - 1;\n    }\n\n    const auto operator[](int i)\
    \ const {\n        return std::ranges::subrange(elist.begin() + start[i],\n  \
    \                                   elist.begin() + start[i + 1]);\n    }\n  \
    \  auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i],\n                                     elist.begin() + start[i +\
    \ 1]);\n    }\n\n    const auto operator()(int i, int l, int r) const {\n    \
    \    return std::ranges::subrange(elist.begin() + start[i] + l,\n            \
    \                         elist.begin() + start[i + 1] + r);\n    }\n    auto\
    \ operator()(int i, int l, int r) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i] + l,\n                                     elist.begin() + start[i\
    \ + 1] + r);\n    }\n\n  private:\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n};\n\n}  // namespace ebi\n#line 9 \"graph/base.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T> struct Edge {\n    int to;\n    T cost;\n    int id;\n\
    };\n\ntemplate <class E> struct Graph {\n  private:\n    using cost_type = E;\n\
    \    using edge_type = Edge<cost_type>;\n\n  public:\n    Graph(int n_) : n(n_)\
    \ {}\n\n    Graph() = default;\n\n    void add_edge(int u, int v, cost_type c)\
    \ {\n        edges.emplace_back(u, edge_type{v, c, m++});\n    }\n\n    void read_tree(int\
    \ offset = 1, bool is_weighted = false) {\n        read_graph(n - 1, offset, false,\
    \ is_weighted);\n    }\n\n    void read_parents(int offset = 1) {\n        for\
    \ (auto i : std::views::iota(1, n)) {\n            int p;\n            std::cin\
    \ >> p;\n            p -= offset;\n            add_edge(p, i, 1);\n          \
    \  add_edge(i, p, 1);\n        }\n        build();\n    }\n\n    void read_graph(int\
    \ e, int offset = 1, bool is_directed = false,\n                    bool is_weighted\
    \ = false) {\n        for (int i = 0; i < e; i++) {\n            int u, v;\n \
    \           std::cin >> u >> v;\n            u -= offset;\n            v -= offset;\n\
    \            if (is_weighted) {\n                cost_type c;\n              \
    \  std::cin >> c;\n                add_edge(u, v, c);\n                if (!is_directed)\
    \ {\n                    add_edge(v, u, c);\n                }\n            }\
    \ else {\n                add_edge(u, v, 1);\n                if (!is_directed)\
    \ {\n                    add_edge(v, u, 1);\n                }\n            }\n\
    \        }\n        build();\n    }\n\n    void build() {\n        assert(!prepared);\n\
    \        csr = simple_csr<edge_type>(n, edges);\n        edges.clear();\n    \
    \    prepared = true;\n    }\n\n    int size() const {\n        return n;\n  \
    \  }\n\n    const auto operator[](int i) const {\n        return csr[i];\n   \
    \ }\n    auto operator[](int i) {\n        return csr[i];\n    }\n\n  private:\n\
    \    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>> edges;\n    simple_csr<edge_type>\
    \ csr;\n    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 2 \"tree/centroid_decomposition.hpp\"\
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
    \ ebi\n#line 10 \"tree/contour_query_on_weighted_tree.hpp\"\n\nnamespace ebi {\n\
    \ntemplate <class T> struct contour_query_on_weighted_tree {\n    contour_query_on_weighted_tree(const\
    \ Graph<T> &tree) : n(int(tree.size())) {\n        int t = 0;\n        labels.resize(n);\n\
    \        range = {0};\n        std::vector<int> rev(n, -1);\n        auto f =\
    \ [&](const std::vector<int> &par, const std::vector<int> &vs,\n             \
    \        const std::vector<int> &color) -> void {\n            int sz = (int)par.size();\n\
    \            std::vector<T> depth(sz, -1);\n            depth[0] = 0;\n      \
    \      for (int i : std::views::iota(0, sz)) {\n                rev[vs[i]] = i;\n\
    \            }\n            for (int i : std::views::iota(0, sz)) {\n        \
    \        int v = vs[i];\n                for (auto e : tree[v]) {\n          \
    \          if (rev[e.to] == -1) continue;\n                    depth[rev[e.to]]\
    \ = depth[rev[v]] + e.cost;\n                }\n                rev[v] = -1;\n\
    \            }\n            std::vector<int> red, blue;\n            for (const\
    \ int v : std::views::iota(0, sz)) {\n                if (color[v] == 0) {\n \
    \                   red.emplace_back(v);\n                } else if (color[v]\
    \ == 1) {\n                    blue.emplace_back(v);\n                } else {\n\
    \                    assert(color[v] == -1);\n                }\n            }\n\
    \            if (red.empty() || blue.empty()) return;\n\n            auto update\
    \ = [&](std::vector<int> &s) -> void {\n                std::sort(s.begin(), s.end(),\
    \ [&](int i, int j) -> bool {\n                    return depth[i] < depth[j];\n\
    \                });\n                for (int i = 0; const int v : s) {\n   \
    \                 dist.emplace_back(depth[v]);\n                    labels[vs[v]].emplace_back(t,\
    \ i, depth[v]);\n                    i++;\n                }\n               \
    \ range.emplace_back(dist.size());\n                t++;\n            };\n   \
    \         update(red);\n            update(blue);\n        };\n        centroid_decomposition<2>(tree,\
    \ f);\n    }\n\n    std::size_t size() {\n        return dist.size();\n    }\n\
    \n    // [0, k)\n    std::vector<std::pair<std::size_t, std::size_t>>\n    get_range_less_than_k_from_v(int\
    \ v, T k) const {\n        std::vector<std::pair<std::size_t, std::size_t>> res;\n\
    \        for (auto [t, i, d] : labels[v]) {\n            t ^= 1;\n           \
    \ std::size_t id_l = range[t];\n            std::size_t id_r =\n             \
    \   std::lower_bound(dist.begin() + range[t],\n                              \
    \   dist.begin() + range[t + 1], k - d) -\n                dist.begin();\n   \
    \         res.emplace_back(id_l, id_r);\n        }\n        return res;\n    }\n\
    \n    // [k, infty)\n    std::vector<std::pair<std::size_t, std::size_t>> get_range_k_or_more_from_v(\n\
    \        int v, T k) const {\n        std::vector<std::pair<std::size_t, std::size_t>>\
    \ res;\n        for (auto [t, i, d] : labels[v]) {\n            t ^= 1;\n    \
    \        std::size_t id_l =\n                std::lower_bound(dist.begin() + range[t],\n\
    \                                 dist.begin() + range[t + 1], k - d) -\n    \
    \            dist.begin();\n            std::size_t id_r = range[t + 1];\n   \
    \         res.emplace_back(id_l, id_r);\n        }\n        return res;\n    }\n\
    \n    // [l, r)\n    std::vector<std::pair<std::size_t, std::size_t>> get_contour_from_vertex(\n\
    \        int v, T l, T r) const {\n        std::vector<std::pair<std::size_t,\
    \ std::size_t>> res;\n        for (auto [t, i, d] : labels[v]) {\n           \
    \ t ^= 1;\n            std::size_t id_l =\n                std::lower_bound(dist.begin()\
    \ + range[t],\n                                 dist.begin() + range[t + 1], l\
    \ - d) -\n                dist.begin();\n            std::size_t id_r =\n    \
    \            std::lower_bound(dist.begin() + range[t],\n                     \
    \            dist.begin() + range[t + 1], r - d) -\n                dist.begin();\n\
    \            res.emplace_back(id_l, id_r);\n        }\n        return res;\n \
    \   }\n\n    std::vector<std::size_t> get_vertex(int v) const {\n        assert(0\
    \ <= v && v < n);\n        std::vector<std::size_t> res;\n        for (auto [t,\
    \ i, _] : labels[v]) {\n            res.emplace_back(range[t] + i);\n        }\n\
    \        return res;\n    }\n\n    std::pair<int, int> sub_range(int i) const\
    \ {\n        return {range[i], range[i + 1]};\n    }\n\n  private:\n    int n;\n\
    \    std::vector<T> dist;\n    std::vector<int> range;\n    std::vector<std::vector<std::tuple<int,\
    \ int, T>>> labels;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <ranges>\n#include <tuple>\n\
    #include <vector>\n\n#include \"../graph/base.hpp\"\n#include \"../tree/centroid_decomposition.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct contour_query_on_weighted_tree\
    \ {\n    contour_query_on_weighted_tree(const Graph<T> &tree) : n(int(tree.size()))\
    \ {\n        int t = 0;\n        labels.resize(n);\n        range = {0};\n   \
    \     std::vector<int> rev(n, -1);\n        auto f = [&](const std::vector<int>\
    \ &par, const std::vector<int> &vs,\n                     const std::vector<int>\
    \ &color) -> void {\n            int sz = (int)par.size();\n            std::vector<T>\
    \ depth(sz, -1);\n            depth[0] = 0;\n            for (int i : std::views::iota(0,\
    \ sz)) {\n                rev[vs[i]] = i;\n            }\n            for (int\
    \ i : std::views::iota(0, sz)) {\n                int v = vs[i];\n           \
    \     for (auto e : tree[v]) {\n                    if (rev[e.to] == -1) continue;\n\
    \                    depth[rev[e.to]] = depth[rev[v]] + e.cost;\n            \
    \    }\n                rev[v] = -1;\n            }\n            std::vector<int>\
    \ red, blue;\n            for (const int v : std::views::iota(0, sz)) {\n    \
    \            if (color[v] == 0) {\n                    red.emplace_back(v);\n\
    \                } else if (color[v] == 1) {\n                    blue.emplace_back(v);\n\
    \                } else {\n                    assert(color[v] == -1);\n     \
    \           }\n            }\n            if (red.empty() || blue.empty()) return;\n\
    \n            auto update = [&](std::vector<int> &s) -> void {\n             \
    \   std::sort(s.begin(), s.end(), [&](int i, int j) -> bool {\n              \
    \      return depth[i] < depth[j];\n                });\n                for (int\
    \ i = 0; const int v : s) {\n                    dist.emplace_back(depth[v]);\n\
    \                    labels[vs[v]].emplace_back(t, i, depth[v]);\n           \
    \         i++;\n                }\n                range.emplace_back(dist.size());\n\
    \                t++;\n            };\n            update(red);\n            update(blue);\n\
    \        };\n        centroid_decomposition<2>(tree, f);\n    }\n\n    std::size_t\
    \ size() {\n        return dist.size();\n    }\n\n    // [0, k)\n    std::vector<std::pair<std::size_t,\
    \ std::size_t>>\n    get_range_less_than_k_from_v(int v, T k) const {\n      \
    \  std::vector<std::pair<std::size_t, std::size_t>> res;\n        for (auto [t,\
    \ i, d] : labels[v]) {\n            t ^= 1;\n            std::size_t id_l = range[t];\n\
    \            std::size_t id_r =\n                std::lower_bound(dist.begin()\
    \ + range[t],\n                                 dist.begin() + range[t + 1], k\
    \ - d) -\n                dist.begin();\n            res.emplace_back(id_l, id_r);\n\
    \        }\n        return res;\n    }\n\n    // [k, infty)\n    std::vector<std::pair<std::size_t,\
    \ std::size_t>> get_range_k_or_more_from_v(\n        int v, T k) const {\n   \
    \     std::vector<std::pair<std::size_t, std::size_t>> res;\n        for (auto\
    \ [t, i, d] : labels[v]) {\n            t ^= 1;\n            std::size_t id_l\
    \ =\n                std::lower_bound(dist.begin() + range[t],\n             \
    \                    dist.begin() + range[t + 1], k - d) -\n                dist.begin();\n\
    \            std::size_t id_r = range[t + 1];\n            res.emplace_back(id_l,\
    \ id_r);\n        }\n        return res;\n    }\n\n    // [l, r)\n    std::vector<std::pair<std::size_t,\
    \ std::size_t>> get_contour_from_vertex(\n        int v, T l, T r) const {\n \
    \       std::vector<std::pair<std::size_t, std::size_t>> res;\n        for (auto\
    \ [t, i, d] : labels[v]) {\n            t ^= 1;\n            std::size_t id_l\
    \ =\n                std::lower_bound(dist.begin() + range[t],\n             \
    \                    dist.begin() + range[t + 1], l - d) -\n                dist.begin();\n\
    \            std::size_t id_r =\n                std::lower_bound(dist.begin()\
    \ + range[t],\n                                 dist.begin() + range[t + 1], r\
    \ - d) -\n                dist.begin();\n            res.emplace_back(id_l, id_r);\n\
    \        }\n        return res;\n    }\n\n    std::vector<std::size_t> get_vertex(int\
    \ v) const {\n        assert(0 <= v && v < n);\n        std::vector<std::size_t>\
    \ res;\n        for (auto [t, i, _] : labels[v]) {\n            res.emplace_back(range[t]\
    \ + i);\n        }\n        return res;\n    }\n\n    std::pair<int, int> sub_range(int\
    \ i) const {\n        return {range[i], range[i + 1]};\n    }\n\n  private:\n\
    \    int n;\n    std::vector<T> dist;\n    std::vector<int> range;\n    std::vector<std::vector<std::tuple<int,\
    \ int, T>>> labels;\n};\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - tree/centroid_decomposition.hpp
  isVerificationFile: false
  path: tree/contour_query_on_weighted_tree.hpp
  requiredBy: []
  timestamp: '2024-03-12 17:35:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/contour_query_on_weighted_tree.hpp
layout: document
title: Contour Query on Tree (Weighted)
---

## 説明

頂点 $v$ と距離が $[l, r)$ である頂点に対するクエリを処理するための構造体。構築 $O(N\log{N})$

### できること

- [1点更新区間取得](https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree)
- [1点取得区間更新](https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree)

### できないこと

- 区間更新区間所得

頂点 $v$ への作用が頂点 $v$ に関わるインデックスすべてに対して行わないといけないため。 $1$ 点更新ならば、更新すべきノードが $O(\log{N})$ であるため可能。 $1$ 点取得ならば、所得の際に頂点 $v$ に関わるインデックスをなめることで可能。

### get_range_less_than_k_from_v(int v, T k)

頂点 $v$ と距離が $k$ 未満であるような頂点の属する区間を返す。 $O((\log{N})^2)$

距離が $0$ であるよう場合は含まれないので別途処理が必要。

### get_contour_from_vertex(int v, T l, T r)

頂点 $v$ から距離 $[l, r)$ の頂点の属する区間を返す。 $O((\log{N})^2)$

### get_vertex(int v)

頂点 $v$ に関わるインデックスを返す。 $O(\log{N})$
