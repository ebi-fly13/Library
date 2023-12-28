---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_dual_segtree.hpp
    title: dynamic dual segtree
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\
    \n#line 2 \"data_structure/dynamic_dual_segtree.hpp\"\n\n#include <bit>\n#include\
    \ <cassert>\n#include <memory>\n\nnamespace ebi {\n\ntemplate <class F, F (*merge)(F,\
    \ F), F (*id)()> struct dynamice_dual_segtree {\n  private:\n    struct Node;\n\
    \    using node_ptr = std::shared_ptr<Node>;\n    struct Node {\n        node_ptr\
    \ lch = nullptr, rch = nullptr;\n        F f = id();\n    };\n\n    void all_apply(node_ptr\
    \ node, F f) {\n        node->f = merge(f, node->f);\n    }\n\n    void push(node_ptr\
    \ node) {\n        if (node->lch == nullptr) {\n            node->lch = std::make_shared<Node>();\n\
    \        }\n        node->lch->f = merge(node->f, node->lch->f);\n        if (node->rch\
    \ == nullptr) {\n            node->rch = std::make_shared<Node>();\n        }\n\
    \        node->rch->f = merge(node->f, node->rch->f);\n        node->f = id();\n\
    \    }\n\n    void _apply(node_ptr node, int l, int r, int tl, int tr, F f) {\n\
    \        if (tr <= l || r <= tl) return;\n        if (tl <= l && r <= tr) {\n\
    \            all_apply(node, f);\n            return;\n        }\n        push(node);\n\
    \        _apply(node->lch, l, (l + r) / 2, tl, tr, f);\n        _apply(node->rch,\
    \ (l + r) / 2, r, tl, tr, f);\n    }\n\n  public:\n    dynamice_dual_segtree(int\
    \ n_)\n        : n(n_),\n          sz(std::bit_ceil((unsigned int)(n))),\n   \
    \       lg2(std::countr_zero((unsigned int)(sz))),\n          root(std::make_shared<Node>())\
    \ {}\n\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        if (l == r) return;\n        _apply(root, 0, sz, l, r, f);\n\
    \    }\n\n    void set(int p, F f) {\n        assert(0 <= p && p < n);\n     \
    \   node_ptr node = root;\n        int l = 0, r = sz;\n        for (int i = 0;\
    \ i < lg2; i++) {\n            push(node);\n            int m = (l + r) / 2;\n\
    \            if (p < m) {\n                r = m;\n                node = node->lch;\n\
    \            } else {\n                l = m;\n                node = node->rch;\n\
    \            }\n        }\n        node->f = f;\n    }\n\n    F get(int p) {\n\
    \        assert(0 <= p && p < n);\n        node_ptr node = root;\n        int\
    \ l = 0, r = sz;\n        for (int i = 0; i < lg2; i++) {\n            push(node);\n\
    \            int m = (l + r) / 2;\n            if (p < m) {\n                r\
    \ = m;\n                node = node->lch;\n            } else {\n            \
    \    l = m;\n                node = node->rch;\n            }\n        }\n   \
    \     return node->f;\n    }\n\n  private:\n    int n, sz, lg2;\n    node_ptr\
    \ root;\n};\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#line 4\
    \ \"modint/modint.hpp\"\n#include <iostream>\r\n\r\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint\
    \ {\r\n  private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n  \
    \  static constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static\
    \ constexpr modint raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n\
    \        return x;\r\n    }\r\n\r\n    constexpr static_modint() : _v(0) {}\r\n\
    \r\n    constexpr static_modint(long long v) {\r\n        v %= (long long)umod();\r\
    \n        if (v < 0) v += (long long)umod();\r\n        _v = (unsigned int)v;\r\
    \n    }\r\n\r\n    constexpr unsigned int val() const {\r\n        return _v;\r\
    \n    }\r\n\r\n    constexpr unsigned int value() const {\r\n        return val();\r\
    \n    }\r\n\r\n    constexpr modint &operator++() {\r\n        _v++;\r\n     \
    \   if (_v == umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\
    \n        return *this;\r\n    }\r\n\r\n    constexpr modint operator++(int) {\r\
    \n        modint res = *this;\r\n        ++*this;\r\n        return res;\r\n \
    \   }\r\n    constexpr modint operator--(int) {\r\n        modint res = *this;\r\
    \n        --*this;\r\n        return res;\r\n    }\r\n\r\n    constexpr modint\
    \ &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v\
    \ >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\n       \
    \ if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator*=(const modint &rhs) {\r\n        unsigned long long x = _v;\r\
    \n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned long long)umod());\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator/=(const modint\
    \ &rhs) {\r\n        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr\
    \ modint operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\
    \n    constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n\
    \        modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n\
    \ & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\
    \n        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n     \
    \   assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend\
    \ modint operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ += rhs;\r\n    }\r\n    friend modint operator-(const modint &lhs, const modint\
    \ &rhs) {\r\n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const modint &lhs, const\
    \ modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend\
    \ bool operator==(const modint &lhs, const modint &rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\
    \n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\
    \n        return m;\r\n    }\r\n};\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 1 \"template/template.hpp\"\n#include <algorithm>\n#line 3 \"template/template.hpp\"\
    \n#include <bitset>\n#line 5 \"template/template.hpp\"\n#include <chrono>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <cstring>\n#include <functional>\n#include\
    \ <iomanip>\n#line 16 \"template/template.hpp\"\n#include <limits>\n#include <map>\n\
    #line 19 \"template/template.hpp\"\n#include <numbers>\n#include <numeric>\n#include\
    \ <optional>\n#include <queue>\n#include <random>\n#include <ranges>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#line 33 \"template/template.hpp\"\
    \n#include <vector>\n\n#define rep(i, a, n) for (int i = (int)(a); i < (int)(n);\
    \ i++)\n#define rrep(i, a, n) for (int i = ((int)(n)-1); i >= (int)(a); i--)\n\
    #define Rep(i, a, n) for (i64 i = (i64)(a); i < (i64)(n); i++)\n#define RRep(i,\
    \ a, n) for (i64 i = ((i64)(n)-i64(1)); i >= (i64)(a); i--)\n#define all(v) (v).begin(),\
    \ (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\
    \n\n#line 4 \"template/debug_template.hpp\"\n\nnamespace ebi {\n\n#ifdef LOCAL\n\
    #define debug(...)                                                      \\\n \
    \   std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\",\
    \ \\\n        debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid\
    \ debug_out() {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename...\
    \ Tail> void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n  \
    \  if (sizeof...(t) > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}  //\
    \ namespace ebi\n#line 2 \"template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\
    \n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\nusing i8 =\
    \ std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16\
    \ = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing\
    \ i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 2 \"template/io.hpp\"\n\
    \n#line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\ntemplate <typename T1, typename\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nstruct F {\n    mint a,\
    \ b;\n};\n\nF merge(F a, F b) {\n    return {a.a * b.a, a.b + a.a * b.b};\n}\n\
    \nF id() {\n    return {1, 0};\n}\n\nvoid main_() {\n    int n, q;\n    std::cin\
    \ >> n >> q;\n    dynamice_dual_segtree<F, merge, id> seg(1'000'000'000);\n  \
    \  rep(i, 0, n) {\n        int a;\n        std::cin >> a;\n        seg.set(i,\
    \ {0, a});\n    }\n    while (q--) {\n        int t;\n        std::cin >> t;\n\
    \        if (t == 0) {\n            int l, r, b, c;\n            std::cin >> l\
    \ >> r >> b >> c;\n            seg.apply(l, r, {b, c});\n        } else {\n  \
    \          int i;\n            std::cin >> i;\n            std::cout << seg.get(i).b\
    \ << '\\n';\n        }\n    }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"../../data_structure/dynamic_dual_segtree.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nnamespace ebi {\n\nusing mint =\
    \ modint998244353;\n\nstruct F {\n    mint a, b;\n};\n\nF merge(F a, F b) {\n\
    \    return {a.a * b.a, a.b + a.a * b.b};\n}\n\nF id() {\n    return {1, 0};\n\
    }\n\nvoid main_() {\n    int n, q;\n    std::cin >> n >> q;\n    dynamice_dual_segtree<F,\
    \ merge, id> seg(1'000'000'000);\n    rep(i, 0, n) {\n        int a;\n       \
    \ std::cin >> a;\n        seg.set(i, {0, a});\n    }\n    while (q--) {\n    \
    \    int t;\n        std::cin >> t;\n        if (t == 0) {\n            int l,\
    \ r, b, c;\n            std::cin >> l >> r >> b >> c;\n            seg.apply(l,\
    \ r, {b, c});\n        } else {\n            int i;\n            std::cin >> i;\n\
    \            std::cout << seg.get(i).b << '\\n';\n        }\n    }\n}\n\n}  //\
    \ namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin\
    \ >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/dynamic_dual_segtree.hpp
  - modint/modint.hpp
  - modint/base.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
  requiredBy: []
  timestamp: '2023-12-28 15:52:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
- /verify/test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp.html
title: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
---
