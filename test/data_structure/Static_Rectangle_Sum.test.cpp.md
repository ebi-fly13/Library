---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: fenwick tree
  - icon: ':heavy_check_mark:'
    path: data_structure/static_rectangle_sum.hpp
    title: Static Rectangle Sum
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/data_structure/Static_Rectangle_Sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 2 \"data_structure/static_rectangle_sum.hpp\"\
    \n\n#include <array>\n#include <tuple>\n#include <vector>\n\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#line 6 \"data_structure/compress.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp)\
    \ : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi\n#line 2 \"data_structure/fenwick_tree.hpp\"\
    \n\r\n#line 5 \"data_structure/fenwick_tree.hpp\"\n\r\nnamespace ebi {\r\n\r\n\
    template <class T> struct fenwick_tree {\r\n  private:\r\n    int n;\r\n    std::vector<T>\
    \ data;\r\n\r\n  public:\r\n    fenwick_tree(int _n) : n(_n), data(std::vector<T>(_n\
    \ + 1, T(0))) {}\r\n\r\n    void add(int i, T val) {\r\n        i++;\r\n     \
    \   for (int x = i; x <= n; x += x & -x) {\r\n            data[x] += val;\r\n\
    \        }\r\n    }\r\n\r\n    T prefix_sum(int i) const {\r\n        assert(0\
    \ <= i && i <= n);\r\n        T ret = 0;\r\n        for (int x = i; x > 0; x -=\
    \ x & -x) {\r\n            ret += data[x];\r\n        }\r\n        return ret;\r\
    \n    }\r\n\r\n    T sum(int l, int r) const {\r\n        return prefix_sum(r)\
    \ - prefix_sum(l);\r\n    }\r\n\r\n    T all_sum() const {\r\n        return prefix_sum(n);\r\
    \n    }\r\n\r\n    // prefix_sum(x) >= key \u3068\u306A\u308B\u6700\u5C0F\u306E\
    x\u3092\u8FD4\u3059\u95A2\u6570 O(log N)\r\n    int lower_bound(T key) {\r\n \
    \       if (key <= 0) return 0;\r\n        int x = 0;\r\n        int max = 1;\r\
    \n        while ((max << 1) <= n) max <<= 1;\r\n        for (int k = max; k >\
    \ 0; k >>= 1) {\r\n            if (x + k <= n && data[x + k] < key) {\r\n    \
    \            x += k;\r\n                key -= data[x];\r\n            }\r\n \
    \       }\r\n        return x + 1;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n\
    #line 9 \"data_structure/static_rectangle_sum.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class S, class T> struct static_rectangle_sum {\n  private:\n  public:\n  \
    \  static_rectangle_sum() = default;\n\n    void add_point(S x, S y, T val) {\n\
    \        p.emplace_back(x, y, val);\n        cp_x.add(x);\n        cp_y.add(y);\n\
    \    }\n\n    void add_query(S l, S d, S r, S u) {\n        q.push_back({l, d,\
    \ r, u});\n        cp_x.add(l);\n        cp_x.add(r);\n        cp_y.add(d);\n\
    \        cp_y.add(u);\n    }\n\n    std::vector<T> run() {\n        assert(is_first);\n\
    \        is_first = false;\n        cp_x.build();\n        cp_y.build();\n   \
    \     std::vector ptable(cp_x.size(), std::vector<int>());\n        std::vector\
    \ qtable(cp_x.size(), std::vector(2, std::vector<int>()));\n        for (int i\
    \ = 0; auto [x, y, val] : p) {\n            ptable[cp_x.get(x)].emplace_back(i);\n\
    \            i++;\n        }\n        for (int i = 0; auto [l, d, r, u] : q) {\n\
    \            qtable[cp_x.get(l)][0].emplace_back(i);\n            qtable[cp_x.get(r)][1].emplace_back(i);\n\
    \            i++;\n        }\n        std::vector<T> res(q.size(), 0);\n     \
    \   fenwick_tree<T> ftree(cp_y.size());\n        for (int i = 0; i < cp_x.size();\
    \ i++) {\n            for (int j = 0; j < 2; j++) {\n                for (auto\
    \ idx : qtable[i][j]) {\n                    int d = q[idx][1], u = q[idx][3];\n\
    \                    res[idx] +=\n                        (j == 0 ? -1 : 1) *\
    \ ftree.sum(cp_y.get(d), cp_y.get(u));\n                }\n            }\n   \
    \         for (auto idx : ptable[i]) {\n                auto [x, y, val] = p[idx];\n\
    \                ftree.add(cp_y.get(y), val);\n            }\n        }\n    \
    \    return res;\n    }\n\n  private:\n    bool is_first = true;\n    std::vector<std::tuple<S,\
    \ S, T>> p;\n    std::vector<std::array<S, 4>> q;\n    compress<S> cp_x, cp_y;\n\
    };\n\n}  // namespace ebi\n#line 4 \"test/data_structure/Static_Rectangle_Sum.test.cpp\"\
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
    \n\n#line 5 \"template/utility.hpp\"\n\n#line 7 \"template/utility.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n\
    \        a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate\
    \ <class T> inline bool chmax(T &a, T b) {\n    if (a < b) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\n\ntemplate <class T> T safe_ceil(T\
    \ a, T b) {\n    if (a % b == 0)\n        return a / b;\n    else if (a >= 0)\n\
    \        return (a / b) + 1;\n    else\n        return -((-a) / b);\n}\n\ntemplate\
    \ <class T> T safe_floor(T a, T b) {\n    if (a % b == 0)\n        return a /\
    \ b;\n    else if (a >= 0)\n        return a / b;\n    else\n        return -((-a)\
    \ / b) - 1;\n}\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max() / 4;\n\n\
    constexpr int INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int>\
    \ dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/data_structure/Static_Rectangle_Sum.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    static_rectangle_sum<int, i64> srs;\n    rep(i, 0, n) {\n        int x, y;\n\
    \        i64 w;\n        std::cin >> x >> y >> w;\n        srs.add_point(x, y,\
    \ w);\n    }\n    rep(i, 0, q) {\n        int l, d, r, u;\n        std::cin >>\
    \ l >> d >> r >> u;\n        srs.add_query(l, d, r, u);\n    }\n    std::cout\
    \ << srs.run() << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../../data_structure/static_rectangle_sum.hpp\"\n\n#include \"../../template/template.hpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    static_rectangle_sum<int, i64> srs;\n    rep(i, 0, n) {\n        int x, y;\n\
    \        i64 w;\n        std::cin >> x >> y >> w;\n        srs.add_point(x, y,\
    \ w);\n    }\n    rep(i, 0, q) {\n        int l, d, r, u;\n        std::cin >>\
    \ l >> d >> r >> u;\n        srs.add_query(l, d, r, u);\n    }\n    std::cout\
    \ << srs.run() << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - data_structure/static_rectangle_sum.hpp
  - data_structure/compress.hpp
  - data_structure/fenwick_tree.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/data_structure/Static_Rectangle_Sum.test.cpp
  requiredBy: []
  timestamp: '2024-02-03 03:29:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Static_Rectangle_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Static_Rectangle_Sum.test.cpp
- /verify/test/data_structure/Static_Rectangle_Sum.test.cpp.html
title: test/data_structure/Static_Rectangle_Sum.test.cpp
---
