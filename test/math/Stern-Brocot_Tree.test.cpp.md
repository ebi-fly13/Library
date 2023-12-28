---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/stern_brocot_tree.hpp
    title: Stern-Brocot Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
  bundledCode: "#line 1 \"test/math/Stern-Brocot_Tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n#line 2 \"math/stern_brocot_tree.hpp\"\
    \n\n#include <cassert>\n#include <concepts>\n#include <iostream>\n#include <optional>\n\
    #include <vector>\n#include <cstdint>\n\nnamespace ebi {\n\nstruct stern_brocot_tree\
    \ {\n  private:\n    using value_type = std::int64_t;\n    using T = value_type;\n\
    \    using Fraction = std::pair<T, T>;\n\n  public:\n    stern_brocot_tree() =\
    \ default;\n\n    static std::vector<T> encode_path(const Fraction &f) {\n   \
    \     auto [x, y] = f;\n        std::vector<T> path;\n        while (x != y) {\n\
    \            T m = (x - 1) / y;\n            path.emplace_back(m);\n         \
    \   x -= m * y;\n            std::swap(x, y);\n        }\n        return path;\n\
    \    }\n\n    static std::pair<Fraction, Fraction> decode_path(\n        const\
    \ std::vector<T> &path) {\n        T lx = 0, ly = 1, rx = 1, ry = 0;\n       \
    \ for (bool is_right = true; auto n : path) {\n            if (is_right) {\n \
    \               lx += rx * n;\n                ly += ry * n;\n            } else\
    \ {\n                rx += lx * n;\n                ry += ly * n;\n          \
    \  }\n            is_right = !is_right;\n        }\n        return {{lx, ly},\
    \ {rx, ry}};\n    }\n\n    static std::pair<Fraction, Fraction> decode_path(\n\
    \        const std::vector<std::pair<char, T>> &path) {\n        if (path.empty())\
    \ {\n            return {{0, 1}, {1, 0}};\n        }\n        std::vector<T> p;\n\
    \        bool is_right = true;\n        if (path[0].first == 'L') {\n        \
    \    p.emplace_back(0);\n            is_right = !is_right;\n        }\n      \
    \  for (auto [c, n] : path) {\n            assert(c == (is_right ? 'R' : 'L'));\n\
    \            p.emplace_back(n);\n            is_right = !is_right;\n        }\n\
    \        return decode_path(p);\n    }\n\n    static Fraction lca(Fraction f,\
    \ Fraction g) {\n        auto path_f = encode_path(f);\n        auto path_g =\
    \ encode_path(g);\n        std::vector<T> path_h;\n        for (int i = 0; i <\
    \ (int)std::min(path_f.size(), path_g.size()); i++) {\n            int k = std::min(path_f[i],\
    \ path_g[i]);\n            path_h.emplace_back(k);\n            if (path_f[i]\
    \ != path_g[i]) {\n                break;\n            }\n        }\n        return\
    \ val(decode_path(path_h));\n    }\n\n    static std::optional<Fraction> ancestor(T\
    \ k, Fraction f) {\n        std::vector<T> path;\n        for (auto n : encode_path(f))\
    \ {\n            T m = std::min(k, n);\n            path.emplace_back(m);\n  \
    \          k -= m;\n            if (k == 0) break;\n        }\n        if (k >\
    \ 0) return std::nullopt;\n        return val(decode_path(path));\n    }\n\n \
    \   static std::pair<Fraction, Fraction> range(Fraction f) {\n        return decode_path(encode_path(f));\n\
    \    }\n\n    static Fraction val(std::pair<Fraction, Fraction> f) {\n       \
    \ auto [l, r] = f;\n        return {l.first + r.first, l.second + r.second};\n\
    \    }\n\n    static void print_path(const std::vector<T> &path) {\n        if\
    \ (path.empty()) {\n            std::cout << \"0\\n\";\n            return;\n\
    \        }\n        int k = path.size() - int(path[0] == 0);\n        std::cout\
    \ << k;\n        for (bool is_right = true; auto c : path) {\n            if (c\
    \ > 0) {\n                std::cout << \" \" << (is_right ? 'R' : 'L') << \" \"\
    \ << c;\n            }\n            is_right = !is_right;\n        }\n       \
    \ std::cout << '\\n';\n        return;\n    }\n};\n\n}  // namespace ebi\n#line\
    \ 1 \"template/template.hpp\"\n#include <algorithm>\n#include <bit>\n#include\
    \ <bitset>\n#line 5 \"template/template.hpp\"\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <complex>\n#include <cstddef>\n#line 11 \"template/template.hpp\"\
    \n#include <cstdlib>\n#include <cstring>\n#include <functional>\n#include <iomanip>\n\
    #line 16 \"template/template.hpp\"\n#include <limits>\n#include <map>\n#include\
    \ <memory>\n#include <numbers>\n#include <numeric>\n#line 22 \"template/template.hpp\"\
    \n#include <queue>\n#include <random>\n#include <ranges>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line 34 \"template/template.hpp\"\
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
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 5 \"test/math/Stern-Brocot_Tree.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    std::string type;\n    std::cin >>\
    \ type;\n    if (type == \"ENCODE_PATH\") {\n        i64 a, b;\n        std::cin\
    \ >> a >> b;\n        auto path = stern_brocot_tree::encode_path({a, b});\n  \
    \      stern_brocot_tree::print_path(path);\n    } else if (type == \"DECODE_PATH\"\
    ) {\n        int k;\n        std::cin >> k;\n        std::vector<std::pair<char,\
    \ i64>> path(k);\n        for (auto &[c, n] : path) {\n            std::cin >>\
    \ c >> n;\n        }\n        auto lr = stern_brocot_tree::decode_path(path);\n\
    \        auto f = stern_brocot_tree::val(lr);\n        std::cout << f << '\\n';\n\
    \    } else if (type == \"LCA\") {\n        i64 a, b, c, d;\n        std::cin\
    \ >> a >> b >> c >> d;\n        std::cout << stern_brocot_tree::lca({a, b}, {c,\
    \ d}) << '\\n';\n    } else if (type == \"ANCESTOR\") {\n        i64 k, a, b;\n\
    \        std::cin >> k >> a >> b;\n        auto f = stern_brocot_tree::ancestor(k,\
    \ {a, b});\n        if (f) {\n            std::cout << f.value() << '\\n';\n \
    \       } else {\n            std::cout << \"-1\\n\";\n        }\n    } else if\
    \ (type == \"RANGE\") {\n        i64 a, b;\n        std::cin >> a >> b;\n    \
    \    std::cout << stern_brocot_tree::range({a, b}) << '\\n';\n    }\n}\n\n}  //\
    \ namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    std::cin\
    \ >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n\
    #include \"../../math/stern_brocot_tree.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    std::string type;\n    std::cin >>\
    \ type;\n    if (type == \"ENCODE_PATH\") {\n        i64 a, b;\n        std::cin\
    \ >> a >> b;\n        auto path = stern_brocot_tree::encode_path({a, b});\n  \
    \      stern_brocot_tree::print_path(path);\n    } else if (type == \"DECODE_PATH\"\
    ) {\n        int k;\n        std::cin >> k;\n        std::vector<std::pair<char,\
    \ i64>> path(k);\n        for (auto &[c, n] : path) {\n            std::cin >>\
    \ c >> n;\n        }\n        auto lr = stern_brocot_tree::decode_path(path);\n\
    \        auto f = stern_brocot_tree::val(lr);\n        std::cout << f << '\\n';\n\
    \    } else if (type == \"LCA\") {\n        i64 a, b, c, d;\n        std::cin\
    \ >> a >> b >> c >> d;\n        std::cout << stern_brocot_tree::lca({a, b}, {c,\
    \ d}) << '\\n';\n    } else if (type == \"ANCESTOR\") {\n        i64 k, a, b;\n\
    \        std::cin >> k >> a >> b;\n        auto f = stern_brocot_tree::ancestor(k,\
    \ {a, b});\n        if (f) {\n            std::cout << f.value() << '\\n';\n \
    \       } else {\n            std::cout << \"-1\\n\";\n        }\n    } else if\
    \ (type == \"RANGE\") {\n        i64 a, b;\n        std::cin >> a >> b;\n    \
    \    std::cout << stern_brocot_tree::range({a, b}) << '\\n';\n    }\n}\n\n}  //\
    \ namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    std::cin\
    \ >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - math/stern_brocot_tree.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/math/Stern-Brocot_Tree.test.cpp
  requiredBy: []
  timestamp: '2023-12-28 11:38:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Stern-Brocot_Tree.test.cpp
layout: document
redirect_from:
- /verify/test/math/Stern-Brocot_Tree.test.cpp
- /verify/test/math/Stern-Brocot_Tree.test.cpp.html
title: test/math/Stern-Brocot_Tree.test.cpp
---
