---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
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
  - icon: ':heavy_check_mark:'
    path: tree/common_interval_decomposition_tree.hpp
    title: Common Interval Decomposition Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/common_interval_decomposition_tree
    links:
    - https://judge.yosupo.jp/problem/common_interval_decomposition_tree
  bundledCode: "#line 1 \"test/tree/Common_Interval_Decomposition_Tree.test.cpp\"\n\
    #define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/common_interval_decomposition_tree\"\
    \n\n#line 2 \"tree/common_interval_decomposition_tree.hpp\"\n\n#include <cassert>\n\
    #include <numeric>\n#include <vector>\n\n#line 2 \"data_structure/sparse_table.hpp\"\
    \n\r\n#line 4 \"data_structure/sparse_table.hpp\"\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class Band, Band (*op)(Band, Band)>\
    \ struct sparse_table {\r\n  public:\r\n    sparse_table() = default;\r\n\r\n\
    \    sparse_table(const std::vector<Band> &a) : n(a.size()) {\r\n        table\
    \ = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n        for (int i\
    \ = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n        }\r\n     \
    \   for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int i = 0; i + (1\
    \ << k) <= n; i++) {\r\n                table[k][i] =\r\n                    op(table[k\
    \ - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n            }\r\n        }\r\n\
    \    }\r\n\r\n    void build(const std::vector<Band> &a) {\r\n        n = (int)a.size();\r\
    \n        table = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n   \
    \     for (int i = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n   \
    \     }\r\n        for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int\
    \ i = 0; i + (1 << k) <= n; i++) {\r\n                table[k][i] =\r\n      \
    \              op(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n    \
    \        }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Band fold(int l,\
    \ int r) {\r\n        int k = std::__lg(r - l);\r\n        return op(table[k][l],\
    \ table[k][r - (1 << k)]);\r\n    }\r\n\r\n  private:\r\n    int n;\r\n    std::vector<std::vector<Band>>\
    \ table;\r\n};\r\n\r\n}  // namespace ebi\n#line 8 \"tree/common_interval_decomposition_tree.hpp\"\
    \n\n/*\nreference: https://www.mathenachia.blog/permutation-tree/\n*/\n\nnamespace\
    \ ebi {\n\nstruct common_interval_decomposition_tree {\n  public:\n    enum NodeType\
    \ {\n        Prime,\n        Dec,\n        Inc,\n        One,\n    };\n\n    struct\
    \ Node {\n        int parent;\n        NodeType type;\n        int l, r;\n   \
    \ };\n\n  private:\n    static int op(int a, int b) {\n        return a < b ?\
    \ a : b;\n    }\n\n    void build(const std::vector<int> &p) {\n        int n\
    \ = (int)p.size();\n        std::vector<int> q(n, -1);\n        for (int i = 0;\
    \ i < n; i++) {\n            assert(0 <= p[i] && p[i] < n && q[p[i]] == -1);\n\
    \            q[p[i]] = i;\n        }\n        sparse_table<int, op> static_range_min(q);\n\
    \        struct LeftBase {\n            int l;\n            int vl, vr;\n    \
    \    };\n        struct Common {\n            int l, r, v;\n        };\n     \
    \   std::vector<LeftBase> stack;\n        std::vector<Common> commons;\n     \
    \   for (int r = 1; r <= n; r++) {\n            int a = p[r - 1];\n          \
    \  LeftBase y = {r - 1, a, a + 1};\n            while (!stack.empty()) {\n   \
    \             if (y.vl < stack.back().vl) stack.back().vl = y.vl;\n          \
    \      if (y.vr > stack.back().vr) stack.back().vr = y.vr;\n                auto\
    \ x = stack.back();\n                if (static_range_min.fold(x.vl, x.vr) < x.l)\
    \ {\n                    stack.pop_back();\n                    auto &new_x =\
    \ stack.back();\n                    if (x.vl < new_x.vl) new_x.vl = x.vl;\n \
    \                   if (x.vr > new_x.vr) new_x.vr = x.vr;\n                } else\
    \ if (x.vr - x.vl == r - x.l) {\n                    y = x;\n                \
    \    stack.pop_back();\n                    commons.emplace_back(x.l, r, x.vl);\n\
    \                } else {\n                    break;\n                }\n   \
    \         }\n            stack.push_back(y);\n        }\n        while (stack.size()\
    \ >= 2) {\n            auto x = stack.back();\n            stack.pop_back();\n\
    \            auto &new_x = stack.back();\n            if (x.vl < new_x.vl) new_x.vl\
    \ = x.vl;\n            if (x.vr > new_x.vr) new_x.vr = x.vr;\n            if (new_x.vr\
    \ - new_x.vl == n - new_x.l) {\n                commons.emplace_back(new_x.l,\
    \ n, new_x.vl);\n            }\n        }\n        assert(stack.size() == 1);\n\
    \        for (int i = 0; i < n; i++) tree.emplace_back(-1, One, i, i + 1);\n \
    \       std::vector<int> id(n);\n        std::iota(id.begin(), id.end(), 0);\n\
    \        std::vector<int> right_list(n);\n        std::iota(right_list.begin(),\
    \ right_list.end(), 1);\n        for (auto common : commons) {\n            int\
    \ m = right_list[common.l];\n            if (right_list[m] == common.r) {\n  \
    \              int a = id[common.l];\n                int b = id[m];\n       \
    \         right_list[common.l] = common.r;\n                auto t = p[common.l]\
    \ < p[common.r - 1] ? Inc : Dec;\n                if (tree[a].type == t) {\n \
    \                   tree[b].parent = a;\n                    tree[a].r = common.r;\n\
    \                } else {\n                    int c = (int)tree.size();\n   \
    \                 tree.emplace_back(-1, t, common.l, common.r);\n            \
    \        tree[a].parent = c;\n                    tree[b].parent = c;\n      \
    \              id[common.l] = c;\n                }\n            } else {\n  \
    \              int c = (int)tree.size();\n                tree.emplace_back(-1,\
    \ Prime, common.l, common.r);\n                for (int i = common.l; i < common.r;\
    \ i = right_list[i]) {\n                    tree[id[i]].parent = c;\n        \
    \        }\n                id[common.l] = c;\n                right_list[common.l]\
    \ = common.r;\n            }\n        }\n    }\n\n  public:\n    common_interval_decomposition_tree(const\
    \ std::vector<int> &p) {\n        build(p);\n    }\n\n    std::vector<Node> get_tree()\
    \ const {\n        return tree;\n    }\n\n  private:\n    std::vector<Node> tree;\n\
    };\n\n}  // namespace ebi\n#line 5 \"test/tree/Common_Interval_Decomposition_Tree.test.cpp\"\
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
    \ 2 \"template/io.hpp\"\n\n#line 5 \"template/io.hpp\"\n#include <optional>\n\
    #line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\ntemplate <typename T1, typename\
    \ T2>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa)\
    \ {\n    return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T1, typename T2>\nstd::istream &operator>>(std::istream &os, std::pair<T1, T2>\
    \ &pa) {\n    return os >> pa.first >> pa.second;\n}\n\ntemplate <typename T>\n\
    std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {\n    for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i] << (i + 1 ==\
    \ vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename T>\nstd::istream\
    \ &operator>>(std::istream &os, std::vector<T> &vec) {\n    for (T &e : vec) std::cin\
    \ >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::optional<T> &opt) {\n    if (opt) {\n        os << opt.value();\n\
    \    } else {\n        os << \"invalid value\";\n    }\n    return os;\n}\n\n\
    void fast_io() {\n    std::cout << std::fixed << std::setprecision(15);\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n}\n\n}  // namespace ebi\n#line 2 \"template/utility.hpp\"\
    \n\n#line 5 \"template/utility.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\n#line 5\
    \ \"graph/base.hpp\"\n#include <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2\
    \ \"data_structure/simple_csr.hpp\"\n\n#line 6 \"data_structure/simple_csr.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class E> struct simple_csr {\n    simple_csr()\
    \ = default;\n\n    simple_csr(int n, const std::vector<std::pair<int, E>>& elements)\n\
    \        : start(n + 1, 0), elist(elements.size()) {\n        for (auto e : elements)\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"template/utility.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> inline bool chmin(T &a, T b) {\n   \
    \ if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if (a < b) {\n   \
    \     a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <class\
    \ T> T safe_ceil(T a, T b) {\n    if (a % b == 0)\n        return a / b;\n   \
    \ else if (a >= 0)\n        return (a / b) + 1;\n    else\n        return -((-a)\
    \ / b);\n}\n\ntemplate <class T> T safe_floor(T a, T b) {\n    if (a % b == 0)\n\
    \        return a / b;\n    else if (a >= 0)\n        return a / b;\n    else\n\
    \        return -((-a) / b) - 1;\n}\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max()\
    \ / 4;\n\nconstexpr int INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int>\
    \ dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 7 \"test/tree/Common_Interval_Decomposition_Tree.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::vector<int>\
    \ p(n);\n    std::cin >> p;\n    common_interval_decomposition_tree permutation_tree(p);\n\
    \    auto tree = permutation_tree.get_tree();\n    std::cout << tree.size() <<\
    \ '\\n';\n    for (auto node : tree) {\n        std::cout << node.parent << \"\
    \ \" << node.l << \" \" << node.r - 1 << \" \"\n                  << (node.type\
    \ == common_interval_decomposition_tree::Prime\n                          ? \"\
    prime\"\n                          : \"linear\")\n                  << '\\n';\n\
    \    }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int\
    \ t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n  \
    \  }\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/common_interval_decomposition_tree\"\
    \n\n#include \"../../tree/common_interval_decomposition_tree.hpp\"\n\n#include\
    \ \"../../template/template.hpp\"\n\nnamespace ebi {\n\nvoid main_() {\n    int\
    \ n;\n    std::cin >> n;\n    std::vector<int> p(n);\n    std::cin >> p;\n   \
    \ common_interval_decomposition_tree permutation_tree(p);\n    auto tree = permutation_tree.get_tree();\n\
    \    std::cout << tree.size() << '\\n';\n    for (auto node : tree) {\n      \
    \  std::cout << node.parent << \" \" << node.l << \" \" << node.r - 1 << \" \"\
    \n                  << (node.type == common_interval_decomposition_tree::Prime\n\
    \                          ? \"prime\"\n                          : \"linear\"\
    )\n                  << '\\n';\n    }\n}\n\n}  // namespace ebi\n\nint main()\
    \ {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--)\
    \ {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - tree/common_interval_decomposition_tree.hpp
  - data_structure/sparse_table.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/tree/Common_Interval_Decomposition_Tree.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:45:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Common_Interval_Decomposition_Tree.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Common_Interval_Decomposition_Tree.test.cpp
- /verify/test/tree/Common_Interval_Decomposition_Tree.test.cpp.html
title: test/tree/Common_Interval_Decomposition_Tree.test.cpp
---
