---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/enumerate_monge_d_edge_shortest_path.hpp
    title: Enumerate Monge d-edge shortest path
  - icon: ':question:'
    path: algorithm/monotone_minima.hpp
    title: Monotone Minima
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':question:'
    path: template/debug_template.hpp
    title: template/debug_template.hpp
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':question:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/952
    links:
    - https://yukicoder.me/problems/no/952
  bundledCode: "#line 1 \"test/yuki/yuki_952.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/952\"\
    \n\n#line 2 \"algorithm/enumerate_monge_d_edge_shortest_path.hpp\"\n\n#include\
    \ <limits>\n#include <utility>\n#include <vector>\n\n#line 2 \"algorithm/monotone_minima.hpp\"\
    \n\n#include <functional>\n#line 6 \"algorithm/monotone_minima.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class F,\n          class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                               std::declval<int>())),\n     \
    \     class Compare = std::less<T>>\nstd::pair<std::vector<int>, std::vector<T>>\
    \ monotone_minima(\n    int n, int m, F f, const Compare &compare = Compare())\
    \ {\n    std::vector<int> argmin(n);\n    std::vector<T> min_val(n);\n    auto\
    \ dfs = [&](auto &&self, int top, int bottom, int left,\n                   int\
    \ right) -> void {\n        if (top > bottom) return;\n        int mid = (top\
    \ + bottom) >> 1;\n        argmin[mid] = left;\n        min_val[mid] = f(mid,\
    \ left);\n        for (int i = left + 1; i <= right; i++) {\n            T val\
    \ = f(mid, i);\n            if (min_val[mid] == val || compare(val, min_val[mid]))\
    \ {\n                argmin[mid] = i;\n                min_val[mid] = val;\n \
    \           }\n        }\n        self(self, top, mid - 1, left, argmin[mid]);\n\
    \        self(self, mid + 1, bottom, argmin[mid], right);\n    };\n    dfs(dfs,\
    \ 0, n - 1, 0, m - 1);\n    return {argmin, min_val};\n}\n\ntemplate <class T,\
    \ class F, class Compare = std::less<T>>\nstd::pair<std::vector<int>, std::vector<T>>\
    \ slide_monotone_minima(\n    int n, int m, F f, const Compare &compare = Compare())\
    \ {\n    std::vector<int> argmin(n);\n    std::vector<T> min_val(n);\n    auto\
    \ dfs = [&](auto &&self, int top, int bottom, int left, int right,\n         \
    \          int depth) -> void {\n        if (top > bottom) return;\n        int\
    \ mid = (top + bottom) >> 1;\n        argmin[mid] = left;\n        min_val[mid]\
    \ = f(mid, left, depth);\n        for (int i = left + 1; i <= right; i++) {\n\
    \            T val = f(mid, i, depth);\n            if (min_val[mid] == val ||\
    \ compare(val, min_val[mid])) {\n                argmin[mid] = i;\n          \
    \      min_val[mid] = val;\n            }\n        }\n        self(self, top,\
    \ mid - 1, left, argmin[mid], depth + 1);\n        self(self, mid + 1, bottom,\
    \ argmin[mid], right, depth + 1);\n    };\n    dfs(dfs, 0, n - 1, 0, m - 1, 0);\n\
    \    return {argmin, min_val};\n}\n\n}  // namespace ebi\n#line 8 \"algorithm/enumerate_monge_d_edge_shortest_path.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class F, class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                                        std::declval<int>()))>\n\
    std::vector<T> enumerate_monge_d_edge_shortest_path(int n, F f) {\n    const T\
    \ max = std::numeric_limits<T>::max();\n    std::vector<T> res(n, max);\n    std::vector<T>\
    \ dp(n, max);\n    dp[0] = 0;\n    auto g = [&](int j, int i) -> T {\n       \
    \ if (dp[i] == max || i >= j) return max;\n        return dp[i] + f(i, j);\n \
    \   };\n    for (int d = 1; d < n; d++) {\n        std::vector<int> argmin = monotone_minima(n,\
    \ n, g).first;\n        for (int i = n - 1; i >= d; i--) dp[i] = g(i, argmin[i]);\n\
    \        res[d] = dp[n - 1];\n    }\n    return res;\n}\n\n}  // namespace ebi\n\
    #line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\n#define rep(i,\
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
    \n\n#line 5 \"template/utility.hpp\"\n\n#line 2 \"graph/template.hpp\"\n\r\n#line\
    \ 5 \"graph/template.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct\
    \ Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to),\
    \ cost(_cost) {}\r\n};\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n\r\n    void read_tree(int\
    \ offset = 1) {\r\n        read_graph((int)size()-1, offset);\r\n    }\r\n\r\n\
    \    void read_graph(int m, int offset = 1, bool directed = false) {\r\n     \
    \   for(int i = 0; i < m; i++) {\r\n            int u,v;\r\n            std::cin\
    \ >> u >> v;\r\n            u -= offset;\r\n            v -= offset;\r\n     \
    \       add_edge(u, v, directed);\r\n        }\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 8 \"template/utility.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n        a = b;\n      \
    \  return true;\n    }\n    return false;\n}\n\ntemplate <class T> inline bool\
    \ chmax(T &a, T b) {\n    if (a < b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\n\ntemplate <class T> T safe_ceil(T a, T b) {\n \
    \   if (a % b == 0)\n        return a / b;\n    else if (a >= 0)\n        return\
    \ (a / b) + 1;\n    else\n        return -((-a) / b);\n}\n\ntemplate <class T>\
    \ T safe_floor(T a, T b) {\n    if (a % b == 0)\n        return a / b;\n    else\
    \ if (a >= 0)\n        return a / b;\n    else\n        return -((-a) / b) - 1;\n\
    }\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max() / 4;\n\nconstexpr int\
    \ INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int> dy = {1,\
    \ 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1, 1, -1, 1,\
    \ -1};\n\n}  // namespace ebi\n#line 5 \"test/yuki/yuki_952.test.cpp\"\n\nnamespace\
    \ ebi {\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::vector<i64>\
    \ a(n);\n    std::cin >> a;\n    a.insert(a.begin(), 0);\n    n++;\n    std::vector<i64>\
    \ sum(n + 1, 0);\n    rep(i, 0, n) sum[i + 1] = sum[i] + a[i];\n    auto f = [&](int\
    \ i, int j) -> i64 {\n        return (sum[j] - sum[i + 1]) * (sum[j] - sum[i +\
    \ 1]);\n    };\n    auto ans = enumerate_monge_d_edge_shortest_path(n + 1, f);\n\
    \    rep(i, 1, n) {\n        std::cout << ans[n - i] << '\\n';\n    }\n}\n\n}\
    \  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n   \
    \ // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/952\"\n\n#include \"../../algorithm/enumerate_monge_d_edge_shortest_path.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nnamespace ebi {\n\nvoid main_()\
    \ {\n    int n;\n    std::cin >> n;\n    std::vector<i64> a(n);\n    std::cin\
    \ >> a;\n    a.insert(a.begin(), 0);\n    n++;\n    std::vector<i64> sum(n + 1,\
    \ 0);\n    rep(i, 0, n) sum[i + 1] = sum[i] + a[i];\n    auto f = [&](int i, int\
    \ j) -> i64 {\n        return (sum[j] - sum[i + 1]) * (sum[j] - sum[i + 1]);\n\
    \    };\n    auto ans = enumerate_monge_d_edge_shortest_path(n + 1, f);\n    rep(i,\
    \ 1, n) {\n        std::cout << ans[n - i] << '\\n';\n    }\n}\n\n}  // namespace\
    \ ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >>\
    \ t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - algorithm/enumerate_monge_d_edge_shortest_path.hpp
  - algorithm/monotone_minima.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/yuki/yuki_952.test.cpp
  requiredBy: []
  timestamp: '2024-03-08 14:06:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yuki/yuki_952.test.cpp
layout: document
redirect_from:
- /verify/test/yuki/yuki_952.test.cpp
- /verify/test/yuki/yuki_952.test.cpp.html
title: test/yuki/yuki_952.test.cpp
---
