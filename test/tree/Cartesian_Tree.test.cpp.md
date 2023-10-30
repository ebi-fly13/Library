---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: tree/cartesian_tree.hpp
    title: Cartesian Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/tree/Cartesian_Tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line 2 \"tree/cartesian_tree.hpp\"\
    \n\n#include <ranges>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class\
    \ T> std::vector<int> cartesian_tree(const std::vector<T> &a) {\n    int n = a.size();\n\
    \    std::vector<int> par(n, -1);\n    std::vector<int> stack;\n    stack.reserve(n);\n\
    \    for (int i : std::views::iota(0, n)) {\n        int prev = -1;\n        while\
    \ (!stack.empty() && a[i] < a[stack.back()]) {\n            prev = stack.back();\n\
    \            stack.pop_back();\n        }\n        if (prev != -1) {\n       \
    \     par[prev] = i;\n        }\n        if (!stack.empty()) {\n            par[i]\
    \ = stack.back();\n        }\n        stack.push_back(i);\n    }\n    return par;\n\
    }\n\n}  // namespace ebi\n#line 4 \"test/tree/Cartesian_Tree.test.cpp\"\n\n#line\
    \ 1 \"template/template.hpp\"\n#include <algorithm>\n#include <bit>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <limits>\n#include <map>\n#include <memory>\n#include <numbers>\n\
    #include <numeric>\n#include <optional>\n#include <queue>\n#include <random>\n\
    #line 25 \"template/template.hpp\"\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#line 34 \"template/template.hpp\"\
    \n\n#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i,\
    \ a, n) for (int i = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for\
    \ (i64 i = (i64)(a); i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1));\
    \ i >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v)\
    \ (v).rbegin(), (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line\
    \ 4 \"template/debug_template.hpp\"\n\nnamespace ebi {\n\n#ifdef LOCAL\n#define\
    \ debug(...)                                                      \\\n    std::cerr\
    \ << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\", \\\n       \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid debug_out()\
    \ {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename... Tail>\
    \ void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t)\
    \ > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n\
    #line 2 \"template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace\
    \ ebi {\n\nusing std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\n\
    using i16 = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
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
    \n\n#line 7 \"template/utility.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\
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
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/tree/Cartesian_Tree.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::vector<i64>\
    \ a(n);\n    std::cin >> a;\n    auto p = cartesian_tree(a);\n    rep(i, 0, n)\
    \ if (p[i] < 0) p[i] = i;\n    std::cout << p << '\\n';\n}\n\n}  // namespace\
    \ ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >>\
    \ t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"../../tree/cartesian_tree.hpp\"\n\n#include \"../../template/template.hpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::vector<i64>\
    \ a(n);\n    std::cin >> a;\n    auto p = cartesian_tree(a);\n    rep(i, 0, n)\
    \ if (p[i] < 0) p[i] = i;\n    std::cout << p << '\\n';\n}\n\n}  // namespace\
    \ ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >>\
    \ t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - tree/cartesian_tree.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/tree/Cartesian_Tree.test.cpp
  requiredBy: []
  timestamp: '2023-10-30 22:46:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Cartesian_Tree.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Cartesian_Tree.test.cpp
- /verify/test/tree/Cartesian_Tree.test.cpp.html
title: test/tree/Cartesian_Tree.test.cpp
---
