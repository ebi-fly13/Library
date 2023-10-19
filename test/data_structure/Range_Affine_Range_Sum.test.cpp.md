---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/lazy_segtree.hpp
    title: lazy segtree
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
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':question:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\r\n\
    \r\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n#include <bit>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <complex>\n#include <cstddef>\n#include <cstdint>\n\
    #include <cstdlib>\n#include <cstring>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <limits>\n#include <map>\n#include <memory>\n#include\
    \ <numbers>\n#include <numeric>\n#include <optional>\n#include <queue>\n#include\
    \ <random>\n#include <ranges>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n#define rep(i, a, n) for (int i = (int)(a);\
    \ i < (int)(n); i++)\n#define rrep(i, a, n) for (int i = ((int)(n)-1); i >= (int)(a);\
    \ i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a); i < (i64)(n); i++)\n#define\
    \ RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i >= (i64)(a); i--)\n#define all(v)\
    \ (v).begin(), (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\n#line 2\
    \ \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\n\
    \nnamespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                        \
    \                              \\\n    std::cerr << \"LINE: \" << __LINE__ <<\
    \ \"  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}\n#line 2 \"template/int_alias.hpp\"\n\n#line\
    \ 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing std::size_t;\nusing\
    \ i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing\
    \ u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}\n#line 2 \"template/io.hpp\"\n\n#line 7 \"template/io.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
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
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 4 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \n\r\n#line 2 \"data_structure/lazy_segtree.hpp\"\n\r\n/*\r\n    reference:\r\n\
    \   https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#line 11 \"data_structure/lazy_segtree.hpp\"\n\r\nnamespace ebi {\r\
    \n\r\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\r\
    \n          F (*composition)(F, F), F (*id)()>\r\nstruct lazy_segtree {\r\n  private:\r\
    \n    void update(int i) {\r\n        data[i] = op(data[2 * i], data[2 * i + 1]);\r\
    \n    }\r\n\r\n    void all_apply(int k, F f) {\r\n        data[k] = mapping(f,\
    \ data[k]);\r\n        if (k < sz) lazy[k] = composition(f, lazy[k]);\r\n    }\r\
    \n\r\n    void push(int i) {\r\n        all_apply(2 * i, lazy[i]);\r\n       \
    \ all_apply(2 * i + 1, lazy[i]);\r\n        lazy[i] = id();\r\n    }\r\n\r\n \
    \ public:\r\n    lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n, e()))\
    \ {}\r\n    lazy_segtree(const std::vector<S> &a)\r\n        : n(a.size()),\r\n\
    \          sz(std::bit_ceil(a.size())),\r\n          log(std::countr_zero(u32(sz)))\
    \ {\r\n        data = std::vector<S>(2 * sz, e());\r\n        lazy = std::vector<F>(sz,\
    \ id());\r\n        for (int i : std::views::iota(0, n)) {\r\n            data[sz\
    \ + i] = a[i];\r\n        }\r\n        for (int i : std::views::iota(1, sz) |\
    \ std::views::reverse) {\r\n            update(i);\r\n        }\r\n    }\r\n\r\
    \n    void set(int p, S x) {\r\n        assert(0 <= p && p < n);\r\n        p\
    \ += sz;\r\n        for (int i = log; i >= 1; i--) push(p >> i);\r\n        data[p]\
    \ = x;\r\n        for (int i = 1; i <= log; i++) update(p >> i);\r\n    }\r\n\r\
    \n    S get(int p) {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\
    \n        for (int i = log; i >= 1; i--) push(p >> i);\r\n        return data[p];\r\
    \n    }\r\n\r\n    S prod(int l, int r) {\r\n        assert(0 <= l && l <= r &&\
    \ r <= n);\r\n        if (l == r) return e();\r\n\r\n        l += sz;\r\n    \
    \    r += sz;\r\n\r\n        for (int i = log; i >= 1; i--) {\r\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\r\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\r\n        }\r\n\r\n        S sml = e(), smr = e();\r\n\
    \        while (l < r) {\r\n            if (l & 1) sml = op(sml, data[l++]);\r\
    \n            if (r & 1) smr = op(data[--r], smr);\r\n            l >>= 1;\r\n\
    \            r >>= 1;\r\n        }\r\n\r\n        return op(sml, smr);\r\n   \
    \ }\r\n\r\n    S all_prod() const {\r\n        return data[1];\r\n    }\r\n\r\n\
    \    void apply(int p, F f) {\r\n        assert(0 <= p && p < n);\r\n        p\
    \ += sz;\r\n        for (int i = log; i >= 1; i--) push(p >> i);\r\n        data[p]\
    \ = mapping(f, data[p]);\r\n        for (int i = 1; i <= log; i++) update(p >>\
    \ i);\r\n    }\r\n\r\n    void apply(int l, int r, F f) {\r\n        assert(0\
    \ <= l && l <= r && r <= n);\r\n        l += sz;\r\n        r += sz;\r\n     \
    \   for (int i = log; i >= 1; i--) {\r\n            if (((l >> i) << i) != l)\
    \ push(l >> i);\r\n            if (((r >> i) << i) != r) push((r - 1) >> i);\r\
    \n        }\r\n\r\n        {\r\n            int memo_l = l, memo_r = r;\r\n  \
    \          while (l < r) {\r\n                if (l & 1) all_apply(l++, f);\r\n\
    \                if (r & 1) all_apply(--r, f);\r\n                l >>= 1;\r\n\
    \                r >>= 1;\r\n            }\r\n            l = memo_l;\r\n    \
    \        r = memo_r;\r\n        }\r\n\r\n        for (int i = 1; i <= log; i++)\
    \ {\r\n            if (((l >> i) << i) != l) update(l >> i);\r\n            if\
    \ (((r >> i) << i) != r) update((r - 1) >> i);\r\n        }\r\n    }\r\n\r\n \
    \ private:\r\n    int n, sz, log;\r\n    std::vector<S> data;\r\n    std::vector<F>\
    \ lazy;\r\n};\r\n\r\n}  // namespace ebi\r\n#line 2 \"utility/modint.hpp\"\n\r\
    \n#line 6 \"utility/modint.hpp\"\n\r\n#line 2 \"utility/modint_base.hpp\"\n\n\
    #line 4 \"utility/modint_base.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\
    \nstruct modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \nstruct static_modint_base : modint_base {};\n\ntemplate <class T>\nusing is_static_modint\
    \ = std::is_base_of<internal::static_modint_base, T>;\n\ntemplate <class T>\n\
    using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\n}\
    \  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint : internal::static_modint_base\
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
    \n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 7 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \n\r\nusing mint = ebi::modint998244353;\r\n\r\nstruct S {\r\n    mint a;\r\n\
    \    int size;\r\n};\r\n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint\
    \ b) : a(a), b(b) {}\r\n};\r\n\r\nS op(S l, S r) {\r\n    return S{l.a + r.a,\
    \ l.size + r.size};\r\n}\r\n\r\nS e() {\r\n    return S{0, 0};\r\n}\r\n\r\nS mapping(F\
    \ l, S r) {\r\n    return S{r.a * l.a + (mint)r.size * l.b, r.size};\r\n}\r\n\r\
    \nF merge(F l, F r) {\r\n    return F{r.a * l.a, r.b * l.a + l.b};\r\n}\r\n\r\n\
    F id() {\r\n    return F{1, 0};\r\n}\r\n\r\nint main() {\r\n    int n, q;\r\n\
    \    std::cin >> n >> q;\r\n    std::vector<S> v(n);\r\n    for (int i = 0; i\
    \ < n; i++) {\r\n        int a;\r\n        std::cin >> a;\r\n        v[i] = {a,\
    \ 1};\r\n    }\r\n    ebi::lazy_segtree<S, op, e, F, mapping, merge, id> seg(v);\r\
    \n    while (q--) {\r\n        int t;\r\n        std::cin >> t;\r\n        if\
    \ (t == 0) {\r\n            int l, r, b, c;\r\n            std::cin >> l >> r\
    \ >> b >> c;\r\n            seg.apply(l, r, F(b, c));\r\n        } else {\r\n\
    \            int l, r;\r\n            std::cin >> l >> r;\r\n            std::cout\
    \ << seg.prod(l, r).a.value() << std::endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n\r\n#include \"../../template/template.hpp\"\r\n\r\n#include \"../../data_structure/lazy_segtree.hpp\"\
    \r\n#include \"../../utility/modint.hpp\"\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nstruct S {\r\n    mint a;\r\n    int size;\r\n};\r\n\r\nstruct F {\r\n \
    \   mint a, b;\r\n    F(mint a, mint b) : a(a), b(b) {}\r\n};\r\n\r\nS op(S l,\
    \ S r) {\r\n    return S{l.a + r.a, l.size + r.size};\r\n}\r\n\r\nS e() {\r\n\
    \    return S{0, 0};\r\n}\r\n\r\nS mapping(F l, S r) {\r\n    return S{r.a * l.a\
    \ + (mint)r.size * l.b, r.size};\r\n}\r\n\r\nF merge(F l, F r) {\r\n    return\
    \ F{r.a * l.a, r.b * l.a + l.b};\r\n}\r\n\r\nF id() {\r\n    return F{1, 0};\r\
    \n}\r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<S>\
    \ v(n);\r\n    for (int i = 0; i < n; i++) {\r\n        int a;\r\n        std::cin\
    \ >> a;\r\n        v[i] = {a, 1};\r\n    }\r\n    ebi::lazy_segtree<S, op, e,\
    \ F, mapping, merge, id> seg(v);\r\n    while (q--) {\r\n        int t;\r\n  \
    \      std::cin >> t;\r\n        if (t == 0) {\r\n            int l, r, b, c;\r\
    \n            std::cin >> l >> r >> b >> c;\r\n            seg.apply(l, r, F(b,\
    \ c));\r\n        } else {\r\n            int l, r;\r\n            std::cin >>\
    \ l >> r;\r\n            std::cout << seg.prod(l, r).a.value() << std::endl;\r\
    \n        }\r\n    }\r\n}"
  dependsOn:
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - data_structure/lazy_segtree.hpp
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-10-19 17:23:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/data_structure/Range_Affine_Range_Sum.test.cpp
---
