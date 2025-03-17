---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: data_structure/skew_heap.hpp
    title: data_structure/skew_heap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: graph/directed_mst.hpp
    title: Directed MST
  - icon: ':heavy_check_mark:'
    path: template/debug_template.hpp
    title: template/debug_template.hpp
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/directedmst
    links:
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"test/graph/Directed_MST.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\
    \n\n#line 2 \"graph/directed_mst.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
    #include <optional>\n#include <ranges>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"data_structure/skew_heap.hpp\"\n\n#line 4 \"data_structure/skew_heap.hpp\"\
    \n#include <functional>\n#include <memory>\n#line 7 \"data_structure/skew_heap.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class Key, class T, class Compare = std::less<Key>>\
    \ struct skew_heap {\n  private:\n    using value_type = Key;\n    using Self\
    \ = skew_heap<Key, T, Compare>;\n\n    struct Node;\n    using iterator = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        Node(value_type x_, T info_) : x(x_), info(info_)\
    \ {}\n\n        void propagate() {\n            if (lhs) lhs->lazy += lazy;\n\
    \            if (rhs) rhs->lazy += lazy;\n            x += lazy;\n           \
    \ lazy = value_type();\n        }\n\n        value_type x;\n        T info;\n\
    \        value_type lazy = value_type();\n        iterator lhs = nullptr, rhs\
    \ = nullptr;\n    };\n\n    iterator internal_meld(iterator lhs, iterator rhs)\
    \ {\n        if (lhs == nullptr) return rhs;\n        if (rhs == nullptr) return\
    \ lhs;\n        lhs->propagate();\n        rhs->propagate();\n        if (Compare()(lhs->x,\
    \ rhs->x)) {\n            std::swap(lhs, rhs);\n        }\n        lhs->rhs =\
    \ internal_meld(lhs->rhs, rhs);\n        std::swap(lhs->lhs, lhs->rhs);\n    \
    \    return lhs;\n    }\n\n  public:\n    skew_heap() = default;\n\n    void push(value_type\
    \ x, T info) {\n        root = internal_meld(root, std::make_shared<Node>(x, info));\n\
    \        sz++;\n    }\n\n    void pop() {\n        assert(!empty());\n       \
    \ root = internal_meld(root->lhs, root->rhs);\n        sz--;\n    }\n\n    void\
    \ meld(Self &heap) {\n        root = internal_meld(root, heap.root);\n       \
    \ sz += heap.sz;\n    }\n\n    void add(value_type lazy) {\n        if (root ==\
    \ nullptr) return;\n        root->lazy += lazy;\n        root->propagate();\n\
    \    }\n\n    bool empty() const {\n        return root == nullptr;\n    }\n\n\
    \    std::pair<value_type, T> top() const {\n        return {root->x, root->info};\n\
    \    }\n\n    int size() const {\n        return sz;\n    }\n\n  private:\n  \
    \  iterator root = nullptr;\n    int sz = 0;\n};\n\n}  // namespace ebi\n#line\
    \ 2 \"graph/base.hpp\"\n\n#line 4 \"graph/base.hpp\"\n#include <iostream>\n#line\
    \ 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 6\
    \ \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class E> struct\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 12 \"graph/directed_mst.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\nstruct union_find_not_merge_tech\
    \ {\n  public:\n    union_find_not_merge_tech(int n_) : n(n_), data(n, -1) {}\n\
    \n    int leader(int u) {\n        if (data[u] < 0) return u;\n        return\
    \ data[u] = leader(data[u]);\n    }\n\n    bool merge(int u, int v) {\n      \
    \  u = leader(u);\n        v = leader(v);\n        if (u == v) return false;\n\
    \        data[u] += data[v];\n        data[v] = u;\n        return true;\n   \
    \ }\n\n    bool same(int u, int v) {\n        return leader(u) == leader(v);\n\
    \    }\n\n    int size(int u) {\n        u = leader(u);\n        return -data[u];\n\
    \    }\n\n  private:\n    int n;\n    std::vector<int> data;\n};\n\n}  // namespace\
    \ internal\n\ntemplate <class T>\nstd::optional<std::pair<T, std::vector<int>>>\
    \ directed_mst(int root,\n                                                   \
    \        const Graph<T> &g) {\n    using Heap = skew_heap<T, Edge<T>, std::greater<T>>;\n\
    \    int n = g.node_number();\n    std::vector<int> used(2 * n, 0);\n    std::vector<int>\
    \ par_node(2 * n, -1);\n    std::vector<int> best_id(2 * n, -1);\n    std::vector<T>\
    \ best_cost(2 * n);\n    internal::union_find_not_merge_tech uf(2 * n);\n    std::vector<Heap>\
    \ heap(2 * n);\n    int nxt = n;\n    used[root] = 2;\n    for (auto e : g.get_edges())\
    \ {\n        heap[e.to].push(e.cost, e);\n    }\n    T sum = 0;\n    for (auto\
    \ s : std::views::iota(0, n)) {\n        if (used[s]) continue;\n        std::vector<int>\
    \ path = {s};\n        while (1) {\n            int a = path.back();\n       \
    \     if (heap[a].empty()) return std::nullopt;\n            auto [c, e] = heap[a].top();\n\
    \            heap[a].pop();\n            int v = uf.leader(e.from);\n        \
    \    if (a == v) continue;\n            used[a] = 1;\n            best_id[a] =\
    \ e.id;\n            best_cost[a] = c;\n            sum += c;\n            if\
    \ (!used[v]) {\n                path.emplace_back(v);\n                continue;\n\
    \            } else if (used[v] == 1) {\n                int w = -1;\n       \
    \         int u = nxt++;\n                while (w != v) {\n                 \
    \   w = path.back();\n                    path.pop_back();\n                 \
    \   T sub = best_cost[w];\n                    heap[w].add(-sub);\n          \
    \          heap[u].meld(heap[w]);\n                    par_node[w] = u;\n    \
    \                uf.merge(u, w);\n                    used[w] = 2;\n         \
    \       }\n                path.emplace_back(u);\n            } else\n       \
    \         break;\n        }\n        for (auto v : path) used[v] = 2;\n    }\n\
    \    std::vector<int> par(n, -1);\n    std::vector<bool> done(nxt, false);\n \
    \   done[root] = true;\n    par[root] = root;\n    T ret = 0;\n    for (auto i\
    \ : std::views::iota(0, nxt) | std::views::reverse) {\n        if (done[i]) continue;\n\
    \        int id = best_id[i];\n        auto e = g.get_edge(id);\n        par[e.to]\
    \ = e.from;\n        ret += e.cost;\n        int x = e.to;\n        while (x !=\
    \ -1 && !done[x]) {\n            done[x] = true;\n            x = par_node[x];\n\
    \        }\n    }\n    assert(sum == ret);\n    return std::pair<T, std::vector<int>>{sum,\
    \ par};\n}\n\n}  // namespace ebi\n#line 4 \"test/graph/Directed_MST.test.cpp\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ a, n) for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i, a, n) for (int\
    \ i = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a);\
    \ i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i\
    \ >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(),\
    \ (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\
    \n\nnamespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                      \
    \                                \\\n    std::cerr << \"LINE: \" << __LINE__ <<\
    \ \"  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n#line 2 \"template/int_alias.hpp\"\
    \n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing ld = long double;\n\
    using std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16\
    \ = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}  // namespace ebi\n#line\
    \ 2 \"template/io.hpp\"\n\n#line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\n\
    template <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
    }\n\ntemplate <typename T1, typename T2>\nstd::istream &operator>>(std::istream\
    \ &os, std::pair<T1, T2> &pa) {\n    return os >> pa.first >> pa.second;\n}\n\n\
    template <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &vec) {\n    for (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i]\
    \ << (i + 1 == vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename\
    \ T>\nstd::istream &operator>>(std::istream &os, std::vector<T> &vec) {\n    for\
    \ (T &e : vec) std::cin >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::optional<T> &opt) {\n    if (opt) {\n\
    \        os << opt.value();\n    } else {\n        os << \"invalid value\";\n\
    \    }\n    return os;\n}\n\nvoid fast_io() {\n    std::cout << std::fixed <<\
    \ std::setprecision(15);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    }\n\n}  // namespace ebi\n#line 2 \"template/utility.hpp\"\n\n#line 5 \"template/utility.hpp\"\
    \n\n#line 8 \"template/utility.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\
    \ inline bool chmin(T &a, T b) {\n    if (a > b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ntemplate <class T> inline bool chmax(T\
    \ &a, T b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\n\ntemplate <class T> T safe_ceil(T a, T b) {\n    if (a\
    \ % b == 0)\n        return a / b;\n    else if (a >= 0)\n        return (a /\
    \ b) + 1;\n    else\n        return -((-a) / b);\n}\n\ntemplate <class T> T safe_floor(T\
    \ a, T b) {\n    if (a % b == 0)\n        return a / b;\n    else if (a >= 0)\n\
    \        return a / b;\n    else\n        return -((-a) / b) - 1;\n}\n\nconstexpr\
    \ i64 LNF = std::numeric_limits<i64>::max() / 4;\n\nconstexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\n\nconst std::vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int>\
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/graph/Directed_MST.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n, m, s;\n    std::cin >> n >>\
    \ m >> s;\n    Graph<i64> g(n);\n    g.read_graph(m, 0, true, true);\n    auto\
    \ res = directed_mst(s, g);\n    if (res) {\n        auto [x, p] = res.value();\n\
    \        std::cout << x << '\\n';\n        std::cout << p << '\\n';\n    } else\
    \ {\n        std::cout << \"-1\\n\";\n    }\n}\n\n}  // namespace ebi\n\nint main()\
    \ {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--)\
    \ {\n        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n\n#include\
    \ \"../../graph/directed_mst.hpp\"\n\n#include \"../../template/template.hpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n, m, s;\n    std::cin >> n >>\
    \ m >> s;\n    Graph<i64> g(n);\n    g.read_graph(m, 0, true, true);\n    auto\
    \ res = directed_mst(s, g);\n    if (res) {\n        auto [x, p] = res.value();\n\
    \        std::cout << x << '\\n';\n        std::cout << p << '\\n';\n    } else\
    \ {\n        std::cout << \"-1\\n\";\n    }\n}\n\n}  // namespace ebi\n\nint main()\
    \ {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--)\
    \ {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - graph/directed_mst.hpp
  - data_structure/skew_heap.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/graph/Directed_MST.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 03:40:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Directed_MST.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Directed_MST.test.cpp
- /verify/test/graph/Directed_MST.test.cpp.html
title: test/graph/Directed_MST.test.cpp
---
