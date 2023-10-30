---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/lazy_segtree.hpp
    title: lazy segtree
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\r\n\
    \r\n#line 2 \"data_structure/lazy_segtree.hpp\"\n\r\n/*\r\n    reference:\r\n\
    \   https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#include <bit>\r\n#include <cassert>\r\n#include <cstdint>\r\n#include\
    \ <ranges>\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\r\n          F (*composition)(F,\
    \ F), F (*id)()>\r\nstruct lazy_segtree {\r\n  private:\r\n    void update(int\
    \ i) {\r\n        data[i] = op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n\
    \    void all_apply(int k, F f) {\r\n        data[k] = mapping(f, data[k]);\r\n\
    \        if (k < sz) lazy[k] = composition(f, lazy[k]);\r\n    }\r\n\r\n    void\
    \ push(int i) {\r\n        all_apply(2 * i, lazy[i]);\r\n        all_apply(2 *\
    \ i + 1, lazy[i]);\r\n        lazy[i] = id();\r\n    }\r\n\r\n  public:\r\n  \
    \  lazy_segtree(int n_) : lazy_segtree(std::vector<S>(n_, e())) {}\r\n    lazy_segtree(const\
    \ std::vector<S> &a)\r\n        : n(a.size()),\r\n          sz(std::bit_ceil(a.size())),\r\
    \n          lg2(std::countr_zero(std::uint32_t(sz))) {\r\n        data = std::vector<S>(2\
    \ * sz, e());\r\n        lazy = std::vector<F>(sz, id());\r\n        for (int\
    \ i : std::views::iota(0, n)) {\r\n            data[sz + i] = a[i];\r\n      \
    \  }\r\n        for (int i : std::views::iota(1, sz) | std::views::reverse) {\r\
    \n            update(i);\r\n        }\r\n    }\r\n\r\n    void set(int p, S x)\
    \ {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\n        for (int\
    \ i = lg2; i >= 1; i--) push(p >> i);\r\n        data[p] = x;\r\n        for (int\
    \ i = 1; i <= lg2; i++) update(p >> i);\r\n    }\r\n\r\n    S get(int p) {\r\n\
    \        assert(0 <= p && p < n);\r\n        p += sz;\r\n        for (int i =\
    \ lg2; i >= 1; i--) push(p >> i);\r\n        return data[p];\r\n    }\r\n\r\n\
    \    S prod(int l, int r) {\r\n        assert(0 <= l && l <= r && r <= n);\r\n\
    \        if (l == r) return e();\r\n\r\n        l += sz;\r\n        r += sz;\r\
    \n\r\n        for (int i = lg2; i >= 1; i--) {\r\n            if (((l >> i) <<\
    \ i) != l) push(l >> i);\r\n            if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\r\n        }\r\n\r\n        S sml = e(), smr = e();\r\n        while\
    \ (l < r) {\r\n            if (l & 1) sml = op(sml, data[l++]);\r\n          \
    \  if (r & 1) smr = op(data[--r], smr);\r\n            l >>= 1;\r\n          \
    \  r >>= 1;\r\n        }\r\n\r\n        return op(sml, smr);\r\n    }\r\n\r\n\
    \    S all_prod() const {\r\n        return data[1];\r\n    }\r\n\r\n    void\
    \ apply(int p, F f) {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\
    \n        for (int i = lg2; i >= 1; i--) push(p >> i);\r\n        data[p] = mapping(f,\
    \ data[p]);\r\n        for (int i = 1; i <= lg2; i++) update(p >> i);\r\n    }\r\
    \n\r\n    void apply(int l, int r, F f) {\r\n        assert(0 <= l && l <= r &&\
    \ r <= n);\r\n        l += sz;\r\n        r += sz;\r\n        for (int i = lg2;\
    \ i >= 1; i--) {\r\n            if (((l >> i) << i) != l) push(l >> i);\r\n  \
    \          if (((r >> i) << i) != r) push((r - 1) >> i);\r\n        }\r\n\r\n\
    \        {\r\n            int memo_l = l, memo_r = r;\r\n            while (l\
    \ < r) {\r\n                if (l & 1) all_apply(l++, f);\r\n                if\
    \ (r & 1) all_apply(--r, f);\r\n                l >>= 1;\r\n                r\
    \ >>= 1;\r\n            }\r\n            l = memo_l;\r\n            r = memo_r;\r\
    \n        }\r\n\r\n        for (int i = 1; i <= lg2; i++) {\r\n            if\
    \ (((l >> i) << i) != l) update(l >> i);\r\n            if (((r >> i) << i) !=\
    \ r) update((r - 1) >> i);\r\n        }\r\n    }\r\n\r\n    template <class G>\
    \ int max_right(int l, G g) {\r\n        assert(0 <= l && l <= n);\r\n       \
    \ assert(g(e()));\r\n        if (l == n) return n;\r\n        l += sz;\r\n   \
    \     for (int i = lg2; i >= 1; i--) push(l >> i);\r\n        S sm = e();\r\n\
    \        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!g(op(sm,\
    \ data[l]))) {\r\n                while (l < sz) {\r\n                    push(l);\r\
    \n                    l = l << 1;\r\n                    if (g(op(sm, data[l])))\
    \ {\r\n                        sm = op(sm, data[l]);\r\n                     \
    \   l++;\r\n                    }\r\n                }\r\n                return\
    \ l - sz;\r\n            }\r\n            sm = op(sm, data[l]);\r\n          \
    \  l++;\r\n        } while ((l & -l) != l);\r\n        return n;\r\n    }\r\n\r\
    \n    template <class G> int min_left(int r, G g) {\r\n        assert(0 <= r &&\
    \ r <= n);\r\n        assert(g(e()));\r\n        if (r == 0) return 0;\r\n   \
    \     r += sz;\r\n        for (int i = lg2; i >= 1; i--) push((r - 1) >> i);\r\
    \n        S sm = e();\r\n        do {\r\n            r--;\r\n            while\
    \ (r > 1 && r % 2) r >>= 1;\r\n            if (!g(op(data[r], sm))) {\r\n    \
    \            while (r < sz) {\r\n                    push(r);\r\n            \
    \        r = (r << 1) + 1;\r\n                    if (g(op(data[r], sm))) {\r\n\
    \                        sm = op(data[r], sm);\r\n                        r--;\r\
    \n                    }\r\n                }\r\n                return r + 1 -\
    \ sz;\r\n            }\r\n            sm = op(data[r], sm);\r\n        } while\
    \ ((r & -r) != r);\r\n        return 0;\r\n    }\r\n\r\n  private:\r\n    int\
    \ n, sz, lg2;\r\n    std::vector<S> data;\r\n    std::vector<F> lazy;\r\n};\r\n\
    \r\n}  // namespace ebi\r\n#line 2 \"modint/modint.hpp\"\n\r\n#line 4 \"modint/modint.hpp\"\
    \n#include <iostream>\r\n\r\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n\
    #line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n \
    \   a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
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
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <cstddef>\n#line 11\
    \ \"template/template.hpp\"\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <functional>\n#include <iomanip>\n#line 16 \"template/template.hpp\"\n#include\
    \ <limits>\n#include <map>\n#include <memory>\n#include <numbers>\n#include <numeric>\n\
    #include <optional>\n#include <queue>\n#include <random>\n#line 25 \"template/template.hpp\"\
    \n#include <set>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#line 34\
    \ \"template/template.hpp\"\n\n#define rep(i, a, n) for (int i = (int)(a); i <\
    \ (int)(n); i++)\n#define rrep(i, a, n) for (int i = ((int)(n)-1); i >= (int)(a);\
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
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n#line 2 \"template/int_alias.hpp\"\
    \n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing std::size_t;\n\
    using i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\
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
    \r\n\r\n#include \"../../data_structure/lazy_segtree.hpp\"\r\n#include \"../../modint/modint.hpp\"\
    \r\n#include \"../../template/template.hpp\"\r\n\r\nusing mint = ebi::modint998244353;\r\
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
  - data_structure/lazy_segtree.hpp
  - modint/modint.hpp
  - modint/base.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-10-31 01:56:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/data_structure/Range_Affine_Range_Sum.test.cpp
---
