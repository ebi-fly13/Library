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
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/unicyclic_graph.hpp\"\n\n#include <queue>\n#include\
    \ <stack>\n\n#line 2 \"graph/base.hpp\"\n\n#include <cassert>\n#include <iostream>\n\
    #include <ranges>\n#include <vector>\n\n#line 2 \"data_structure/simple_csr.hpp\"\
    \n\n#line 4 \"data_structure/simple_csr.hpp\"\n#include <utility>\n#line 6 \"\
    data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class E> struct\
    \ simple_csr {\n    simple_csr() = default;\n\n    simple_csr(int n, const std::vector<std::pair<int,\
    \ E>>& elements)\n        : start(n + 1, 0), elist(elements.size()) {\n      \
    \  for (auto e : elements) {\n            start[e.first + 1]++;\n        }\n \
    \       for (auto i : std::views::iota(0, n)) {\n            start[i + 1] += start[i];\n\
    \        }\n        auto counter = start;\n        for (auto [i, e] : elements)\
    \ {\n            elist[counter[i]++] = e;\n        }\n    }\n\n    simple_csr(const\
    \ std::vector<std::vector<E>>& es)\n        : start(es.size() + 1, 0) {\n    \
    \    int n = es.size();\n        for (auto i : std::views::iota(0, n)) {\n   \
    \         start[i + 1] = (int)es[i].size() + start[i];\n        }\n        elist.resize(start.back());\n\
    \        for (auto i : std::views::iota(0, n)) {\n            std::copy(es[i].begin(),\
    \ es[i].end(), elist.begin() + start[i]);\n        }\n    }\n\n    int size()\
    \ const {\n        return (int)start.size() - 1;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        return std::ranges::subrange(elist.begin() + start[i],\n\
    \                                     elist.begin() + start[i + 1]);\n    }\n\
    \    auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i],\n                                     elist.begin() + start[i +\
    \ 1]);\n    }\n\n    const auto operator()(int i, int l, int r) const {\n    \
    \    return std::ranges::subrange(elist.begin() + start[i] + l,\n            \
    \                         elist.begin() + start[i + 1] + r);\n    }\n    auto\
    \ operator()(int i, int l, int r) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i] + l,\n                                     elist.begin() + start[i\
    \ + 1] + r);\n    }\n\n  private:\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n};\n\n}  // namespace ebi\n#line 9 \"graph/base.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n};\n\ntemplate <class E> struct Graph {\n    using cost_type = E;\n   \
    \ using edge_type = Edge<cost_type>;\n\n    Graph(int n_) : n(n_) {}\n\n    Graph()\
    \ = default;\n\n    void add_edge(int u, int v, cost_type c) {\n        assert(!prepared\
    \ && u < n && v < n);\n        buff.emplace_back(u, edge_type{u, v, c, m});\n\
    \        edges.emplace_back(edge_type{u, v, c, m++});\n    }\n\n    void add_undirected_edge(int\
    \ u, int v, cost_type c) {\n        assert(!prepared && u < n && v < n);\n   \
    \     buff.emplace_back(u, edge_type{u, v, c, m});\n        buff.emplace_back(v,\
    \ edge_type{v, u, c, m});\n        edges.emplace_back(edge_type{u, v, c, m});\n\
    \        m++;\n    }\n\n    void read_tree(int offset = 1, bool is_weighted =\
    \ false) {\n        read_graph(n - 1, offset, false, is_weighted);\n    }\n\n\
    \    void read_parents(int offset = 1) {\n        for (auto i : std::views::iota(1,\
    \ n)) {\n            int p;\n            std::cin >> p;\n            p -= offset;\n\
    \            add_undirected_edge(p, i, 1);\n        }\n        build();\n    }\n\
    \n    void read_graph(int e, int offset = 1, bool is_directed = false,\n     \
    \               bool is_weighted = false) {\n        for (int i = 0; i < e; i++)\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n            u -=\
    \ offset;\n            v -= offset;\n            if (is_weighted) {\n        \
    \        cost_type c;\n                std::cin >> c;\n                if (is_directed)\
    \ {\n                    add_edge(u, v, c);\n                } else {\n      \
    \              add_undirected_edge(u, v, c);\n                }\n            }\
    \ else {\n                if (is_directed) {\n                    add_edge(u,\
    \ v, 1);\n                } else {\n                    add_undirected_edge(u,\
    \ v, 1);\n                }\n            }\n        }\n        build();\n    }\n\
    \n    void build() {\n        assert(!prepared);\n        csr = simple_csr<edge_type>(n,\
    \ buff);\n        buff.clear();\n        prepared = true;\n    }\n\n    int size()\
    \ const {\n        return n;\n    }\n\n    int node_number() const {\n       \
    \ return n;\n    }\n\n    int edge_number() const {\n        return m;\n    }\n\
    \n    edge_type get_edge(int i) const {\n        assert(prepared);\n        return\
    \ edges[i];\n    }\n\n    std::vector<edge_type> get_edges() const {\n       \
    \ assert(prepared);\n        return edges;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        assert(prepared);\n        return csr[i];\n    }\n    auto\
    \ operator[](int i) {\n        assert(prepared);\n        return csr[i];\n   \
    \ }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>>\
    \ buff;\n\n    std::vector<edge_type> edges;\n    simple_csr<edge_type> csr;\n\
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 2 \"tree/heavy_light_decomposition.hpp\"\
    \n\n#include <algorithm>\n#line 6 \"tree/heavy_light_decomposition.hpp\"\n\n#line\
    \ 8 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T> struct heavy_light_decomposition {\n  private:\n    void dfs_sz(int v) {\n\
    \        for (auto &e : g[v]) {\n            if (e.to == par[v]) continue;\n \
    \           par[e.to] = v;\n            depth_[e.to] = depth_[v] + 1;\n      \
    \      dist[e.to] = dist[v] + e.cost;\n            dfs_sz(e.to);\n           \
    \ sz[v] += sz[e.to];\n            if (sz[e.to] > sz[g[v][0].to] || g[v][0].to\
    \ == par[v])\n                std::swap(e, g[v][0]);\n        }\n    }\n\n   \
    \ void dfs_hld(int v) {\n        in[v] = num++;\n        rev[in[v]] = v;\n   \
    \     for (auto e : g[v]) {\n            if (e.to == par[v]) continue;\n     \
    \       nxt[e.to] = (e.to == g[v][0].to ? nxt[v] : e.to);\n            dfs_hld(e.to);\n\
    \        }\n        out[v] = num;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\
    \u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u], in[nxt[u]]);\n   \
    \         u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \  public:\n    heavy_light_decomposition(const Graph<T> &gh, int root_ = 0)\n\
    \        : n(gh.size()),\n          root(root_),\n          g(gh),\n         \
    \ sz(n, 1),\n          in(n),\n          out(n),\n          nxt(n),\n        \
    \  par(n, -1),\n          depth_(n, 0),\n          rev(n),\n          dist(n,\
    \ 0) {\n        nxt[root] = root;\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n\n    int idx(int u) const {\n        return in[u];\n    }\n\n    int\
    \ rev_idx(int i) const {\n        return rev[i];\n    }\n\n    int la(int v, int\
    \ k) const {\n        while (1) {\n            int u = nxt[v];\n            if\
    \ (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -= in[v] - in[u]\
    \ + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u, int v)\
    \ const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u] < in[v])\
    \ std::swap(u, v);\n            u = par[nxt[u]];\n        }\n        return depth_[u]\
    \ < depth_[v] ? u : v;\n    }\n\n    int jump(int s, int t, int i) const {\n \
    \       if (i == 0) return s;\n        int l = lca(s, t);\n        int d = depth_[s]\
    \ + depth_[t] - depth_[l] * 2;\n        if (d < i) return -1;\n        if (depth_[s]\
    \ - depth_[l] >= i) return la(s, i);\n        i = d - i;\n        return la(t,\
    \ i);\n    }\n\n    std::vector<int> path(int s, int t) const {\n        int l\
    \ = lca(s, t);\n        std::vector<int> a, b;\n        for (; s != l; s = par[s])\
    \ a.emplace_back(s);\n        for (; t != l; t = par[t]) b.emplace_back(t);\n\
    \        a.emplace_back(l);\n        std::reverse(b.begin(), b.end());\n     \
    \   a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n\n    int\
    \ root_of_heavy_path(int u) const {\n        return nxt[u];\n    }\n\n    int\
    \ parent(int u) const {\n        return par[u];\n    }\n\n    T distance(int u,\
    \ int v) const {\n        return dist[u] + dist[v] - 2 * dist[lca(u, v)];\n  \
    \  }\n\n    T distance_from_root(int v) const {\n        return dist[v];\n   \
    \ }\n\n    T depth(int v) const {\n        return depth_[v];\n    }\n\n    bool\
    \ at_path(int u, int v, int s) const {\n        return distance(u, v) == distance(u,\
    \ s) + distance(s, v);\n    }\n\n    std::pair<int, int> subtree_section(int v)\
    \ const {\n        return {in[v], out[v]};\n    }\n\n    bool is_subtree(int u,\
    \ int v) const {\n        return in[u] <= in[v] && in[v] < out[u];\n    }\n\n\
    \    template <class F>\n    void path_noncommutative_query(int u, int v, bool\
    \ vertex,\n                                   const F &f) const {\n        int\
    \ l = lca(u, v);\n        for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n    \
    \    if (vertex) f(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l, v))\
    \ f(a, b + 1);\n    }\n\n    std::vector<std::pair<int, int>> path_sections(int\
    \ u, int v,\n                                                   bool vertex) const\
    \ {\n        int l = lca(u, v);\n        std::vector<std::pair<int, int>> sections;\n\
    \        for (auto [a, b] : ascend(u, l)) sections.emplace_back(a + 1, b);\n \
    \       if (vertex) sections.emplace_back(in[l], in[l] + 1);\n        for (auto\
    \ [a, b] : descend(l, v)) sections.emplace_back(a, b + 1);\n        return sections;\n\
    \    }\n\n    template <class F>\n    int max_path(int u, int v, bool vertex,\
    \ F binary_search) const {\n        int prev = -1;\n        int l = lca(u, v);\n\
    \        for (auto [a, b] : ascend(u, l)) {\n            a++;\n            int\
    \ m = binary_search(a, b);\n            if (m == b) {\n                prev =\
    \ rev[b];\n            } else {\n                return (m == a ? prev : rev[m]);\n\
    \            }\n        }\n        if (vertex) {\n            int m = binary_search(in[l],\
    \ in[l] + 1);\n            if (m == in[l]) {\n                return prev;\n \
    \           } else {\n                prev = l;\n            }\n        }\n  \
    \      for (auto [a, b] : descend(l, v)) {\n            b++;\n            int\
    \ m = binary_search(a, b);\n            if (m == b) {\n                prev =\
    \ rev[b - 1];\n            } else {\n                return m == a ? prev : rev[m\
    \ - 1];\n            }\n        }\n        return v;\n    }\n\n    template <class\
    \ F> void subtree_query(int u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex),\
    \ out[u]);\n    }\n\n    const std::vector<int> &dfs_order() const {\n       \
    \ return rev;\n    }\n\n    template <class ADD, class QUERY, class CLEAR, class\
    \ RESET>\n    void dsu_on_tree(const ADD &add, const QUERY &query, const CLEAR\
    \ &clear,\n                     const RESET &reset) const;\n\n    std::vector<std::pair<int,\
    \ int>> lca_based_auxiliary_tree_dfs_order(\n        std::vector<int> vs) const;\n\
    \n    std::pair<std::vector<int>, Graph<T>> lca_based_auxiliary_tree(\n      \
    \  std::vector<int> vs) const;\n\n  private:\n    int n, root;\n    Graph<T> g;\n\
    \    std::vector<int> sz, in, out, nxt, par, depth_, rev;\n    std::vector<T>\
    \ dist;\n\n    int num = 0;\n};\n\n}  // namespace ebi\n#line 8 \"graph/unicyclic_graph.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct unicyclic_graph {\n  private:\n\
    \    void build() {\n        assert(g.node_number() > 2);\n        assert(g.node_number()\
    \ == g.edge_number());\n        int n = g.node_number();\n        in_cycle.assign(n,\
    \ true);\n        parent.assign(n, -1);\n        cycle_root.assign(n, -1);\n \
    \       // \u30B5\u30A4\u30AF\u30EB\u306E\u691C\u51FA\n        {\n           \
    \ std::vector<int> deg(n);\n            std::stack<int> stack;\n            for\
    \ (auto i : std::views::iota(0, n)) {\n                deg[i] = g[i].size();\n\
    \                if (deg[i] == 1) {\n                    stack.push(i);\n    \
    \            }\n            }\n            while (!stack.empty()) {\n        \
    \        int v = stack.top();\n                stack.pop();\n                in_cycle[v]\
    \ = false;\n                for (auto e : g[v]) {\n                    if (deg[e.to]\
    \ == 1) continue;\n                    parent[v] = e.to;\n                   \
    \ deg[e.to]--;\n                    if (deg[e.to] == 1) {\n                  \
    \      stack.push(e.to);\n                    }\n                }\n         \
    \   }\n        }\n        // \u30B5\u30A4\u30AF\u30EB\u306E 1 \u8FBA\u3092\u5207\
    \u3063\u3066 root \u304B\u3089\u9806\u306B\u4E26\u3079\u308B\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            if (in_cycle[i]) {\n            \
    \    root = i;\n                for (auto e : g[i]) {\n                    if\
    \ (in_cycle[e.to]) {\n                        remove_edge_id = e.id;\n       \
    \                 break;\n                    }\n                }\n         \
    \       break;\n            }\n        }\n        std::vector<bool> valid(n, false);\n\
    \        cycle = {root};\n        while (!valid[cycle.back()]) {\n           \
    \ int v = cycle.back();\n            cycle_root[v] = v;\n            valid[v]\
    \ = true;\n            for (auto e : g[v]) {\n                if (e.id == remove_edge_id\
    \ || valid[e.to] || !in_cycle[e.to])\n                    continue;\n        \
    \        cycle.emplace_back(e.to);\n                parent[e.to] = v;\n      \
    \      }\n        }\n        std::queue<int> que;\n        for (auto v : cycle)\
    \ que.push(v);\n        while (!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            for (auto e : g[v]) {\n                if\
    \ (cycle_root[e.to] != -1) continue;\n                cycle_root[e.to] = cycle_root[v];\n\
    \                que.push(e.to);\n            }\n        }\n    }\n\n  public:\n\
    \    unicyclic_graph(const Graph<T> &g_) : g(g_) {\n        build();\n    }\n\n\
    \    Graph<T> get_tree() const {\n        Graph<T> tree(g.node_number());\n  \
    \      for (auto e : g.get_edges()) {\n            if (e.id == remove_edge_id)\
    \ continue;\n            tree.add_undirected_edge(e.from, e.to, e.cost);\n   \
    \     }\n        tree.build();\n        return tree;\n    }\n\n    std::vector<int>\
    \ get_cycle() const {\n        return cycle;\n    }\n\n    int get_root() const\
    \ {\n        return root;\n    }\n\n    int get_remove_edge_id() const {\n   \
    \     return remove_edge_id;\n    }\n\n    int get_cycle_root(int v) const {\n\
    \        return cycle_root[v];\n    }\n\n    T distance(const heavy_light_decomposition<T>\
    \ &hld, int u, int v) const {\n        if (cycle_root[u] == cycle_root[v]) return\
    \ hld.distance(u, v);\n        T loop =\n            hld.distance(root, cycle.back())\
    \ + g.get_edge(remove_edge_id).cost;\n        T d = hld.distance(cycle_root[u],\
    \ cycle_root[v]);\n        d = std::min<T>(d, loop - d);\n        return hld.distance(cycle_root[u],\
    \ u) + hld.distance(cycle_root[v], v) +\n               d;\n    }\n\n    bool\
    \ is_in_cycle(int v) const {\n        return in_cycle[v];\n    }\n\n  private:\n\
    \    int root;\n    int remove_edge_id;\n\n    Graph<T> g, tree;\n    std::vector<int>\
    \ cycle, parent, cycle_root;\n    std::vector<bool> in_cycle;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <queue>\n#include <stack>\n\n#include \"../graph/base.hpp\"\
    \n#include \"../tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T> struct unicyclic_graph {\n  private:\n    void build() {\n       \
    \ assert(g.node_number() > 2);\n        assert(g.node_number() == g.edge_number());\n\
    \        int n = g.node_number();\n        in_cycle.assign(n, true);\n       \
    \ parent.assign(n, -1);\n        cycle_root.assign(n, -1);\n        // \u30B5\u30A4\
    \u30AF\u30EB\u306E\u691C\u51FA\n        {\n            std::vector<int> deg(n);\n\
    \            std::stack<int> stack;\n            for (auto i : std::views::iota(0,\
    \ n)) {\n                deg[i] = g[i].size();\n                if (deg[i] ==\
    \ 1) {\n                    stack.push(i);\n                }\n            }\n\
    \            while (!stack.empty()) {\n                int v = stack.top();\n\
    \                stack.pop();\n                in_cycle[v] = false;\n        \
    \        for (auto e : g[v]) {\n                    if (deg[e.to] == 1) continue;\n\
    \                    parent[v] = e.to;\n                    deg[e.to]--;\n   \
    \                 if (deg[e.to] == 1) {\n                        stack.push(e.to);\n\
    \                    }\n                }\n            }\n        }\n        //\
    \ \u30B5\u30A4\u30AF\u30EB\u306E 1 \u8FBA\u3092\u5207\u3063\u3066 root \u304B\u3089\
    \u9806\u306B\u4E26\u3079\u308B\n        for (auto i : std::views::iota(0, n))\
    \ {\n            if (in_cycle[i]) {\n                root = i;\n             \
    \   for (auto e : g[i]) {\n                    if (in_cycle[e.to]) {\n       \
    \                 remove_edge_id = e.id;\n                        break;\n   \
    \                 }\n                }\n                break;\n            }\n\
    \        }\n        std::vector<bool> valid(n, false);\n        cycle = {root};\n\
    \        while (!valid[cycle.back()]) {\n            int v = cycle.back();\n \
    \           cycle_root[v] = v;\n            valid[v] = true;\n            for\
    \ (auto e : g[v]) {\n                if (e.id == remove_edge_id || valid[e.to]\
    \ || !in_cycle[e.to])\n                    continue;\n                cycle.emplace_back(e.to);\n\
    \                parent[e.to] = v;\n            }\n        }\n        std::queue<int>\
    \ que;\n        for (auto v : cycle) que.push(v);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (auto e : g[v]) {\n                if (cycle_root[e.to] != -1) continue;\n \
    \               cycle_root[e.to] = cycle_root[v];\n                que.push(e.to);\n\
    \            }\n        }\n    }\n\n  public:\n    unicyclic_graph(const Graph<T>\
    \ &g_) : g(g_) {\n        build();\n    }\n\n    Graph<T> get_tree() const {\n\
    \        Graph<T> tree(g.node_number());\n        for (auto e : g.get_edges())\
    \ {\n            if (e.id == remove_edge_id) continue;\n            tree.add_undirected_edge(e.from,\
    \ e.to, e.cost);\n        }\n        tree.build();\n        return tree;\n   \
    \ }\n\n    std::vector<int> get_cycle() const {\n        return cycle;\n    }\n\
    \n    int get_root() const {\n        return root;\n    }\n\n    int get_remove_edge_id()\
    \ const {\n        return remove_edge_id;\n    }\n\n    int get_cycle_root(int\
    \ v) const {\n        return cycle_root[v];\n    }\n\n    T distance(const heavy_light_decomposition<T>\
    \ &hld, int u, int v) const {\n        if (cycle_root[u] == cycle_root[v]) return\
    \ hld.distance(u, v);\n        T loop =\n            hld.distance(root, cycle.back())\
    \ + g.get_edge(remove_edge_id).cost;\n        T d = hld.distance(cycle_root[u],\
    \ cycle_root[v]);\n        d = std::min<T>(d, loop - d);\n        return hld.distance(cycle_root[u],\
    \ u) + hld.distance(cycle_root[v], v) +\n               d;\n    }\n\n    bool\
    \ is_in_cycle(int v) const {\n        return in_cycle[v];\n    }\n\n  private:\n\
    \    int root;\n    int remove_edge_id;\n\n    Graph<T> g, tree;\n    std::vector<int>\
    \ cycle, parent, cycle_root;\n    std::vector<bool> in_cycle;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: false
  path: graph/unicyclic_graph.hpp
  requiredBy: []
  timestamp: '2025-03-31 02:57:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/unicyclic_graph.hpp
layout: document
title: Unicyclic Graph
---

## 説明

Unicyclic graph（別名: なもりグラフ）を扱う。サイクルの辺を $1$ 辺取り除いて木にして管理する。

### get_tree()

サイクルの辺を $1$ 辺取り除いた木を返す。

### get_cycle()

サイクルの頂点番号の列を返す。取り除いた辺の両端が配列の先頭と末尾になっており、配列内の頂点は取り除いた端点のパスに登場する順序になっている。つまり、サイクルから $1$ 辺取り除いて切り開いた配列である。

### get_root()

取り除いた辺の一方の頂点番号を返す。

### get_remove_edge_id()

元のunicyclic graphにおける削除した辺の番号を返す。

### get_cycle_root(v)

頂点 $v$ に最も近いサイクル内の頂点番号を返す。

### distance(hld, u, v)

頂点 $u$, $v$ 間の距離を返す。HLDはサイクルから $1$ 辺取り除いた木のHLDである。

### is_in_cycle(v)

頂点 $v$ がサイクル内にあるか判定する。