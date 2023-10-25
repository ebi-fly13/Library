---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint61.hpp
    title: modint/modint61.hpp
  - icon: ':x:'
    path: tree/rooted_tree_hash.hpp
    title: Rooted Tree Hash
  - icon: ':question:'
    path: utility/hash.hpp
    title: Hash structure
  - icon: ':question:'
    path: utility/random_number_generator_64.hpp
    title: utility/random_number_generator_64.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include <iostream>\n#include <map>\n#include <vector>\n\n#line 2 \"tree/rooted_tree_hash.hpp\"\
    \n\n#line 4 \"tree/rooted_tree_hash.hpp\"\n\n#line 2 \"utility/hash.hpp\"\n\n\
    #include <array>\n\n#line 2 \"modint/modint61.hpp\"\n\n#include <cassert>\n#include\
    \ <cstdint>\n#line 6 \"modint/modint61.hpp\"\n\n#line 2 \"modint/base.hpp\"\n\n\
    #include <concepts>\n#line 5 \"modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nconcept modint = requires(T a, T b) {\n    a + b;\n    a - b;\n \
    \   a *b;\n    a / b;\n    a.inv();\n    a.val();\n    a.mod();\n};\n\ntemplate\
    \ <modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 8 \"modint/modint61.hpp\"\n\nnamespace\
    \ ebi {\n\nstruct modint61 {\n  private:\n    using mint = modint61;\n    using\
    \ u64 = std::uint64_t;\n    constexpr static u64 m = (1ull << 61) - 1;\n    constexpr\
    \ static u64 MASK31 = (1ull << 31) - 1;\n    constexpr static u64 MASK30 = (1ull\
    \ << 30) - 1;\n\n  public:\n    constexpr static u64 mod() {\n        return m;\n\
    \    }\n\n    constexpr modint61() : _v(0) {}\n\n    constexpr modint61(long long\
    \ v) {\n        v %= (long long)umod();\n        if (v < 0) v += (long long)umod();\n\
    \        _v = u64(v);\n    }\n\n    constexpr u64 val() const {\n        return\
    \ _v;\n    }\n\n    constexpr u64 value() const {\n        return val();\n   \
    \ }\n\n    constexpr mint &operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n\n    constexpr mint &operator--() {\n\
    \        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n   \
    \ }\n\n    constexpr mint &operator+=(const mint &rhs) {\n        _v += rhs._v;\n\
    \        _v = safe_mod(_v);\n        return *this;\n    }\n\n    constexpr mint\
    \ &operator-=(const mint &rhs) {\n        if (_v < rhs._v) _v += umod();\n   \
    \     assert(_v >= rhs._v);\n        _v -= rhs._v;\n        return *this;\n  \
    \  }\n\n    constexpr mint &operator*=(const mint &rhs) {\n        u64 au = _v\
    \ >> 31, ad = _v & MASK31;\n        u64 bu = rhs._v >> 31, bd = rhs._v & MASK31;\n\
    \        u64 mid = ad * bu + au * bd;\n        u64 midu = mid >> 30;\n       \
    \ u64 midd = mid & MASK30;\n        _v = (au * bu * 2 + midu + (midd << 31) +\
    \ ad * bd);\n        _v = safe_mod(_v);\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator/=(const mint &rhs) {\n        return *this *= rhs.inv();\n  \
    \  }\n\n    constexpr mint pow(long long n) const {\n        assert(0 <= n);\n\
    \        mint x = *this, res = 1;\n        while (n) {\n            if (n & 1)\
    \ res *= x;\n            x *= x;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    constexpr mint inv() const {\n        assert(_v);\n     \
    \   return pow(umod() - 2);\n    }\n\n    friend mint operator+(const mint &lhs,\
    \ const mint &rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint\
    \ operator-(const mint &lhs, const mint &rhs) {\n        return mint(lhs) -= rhs;\n\
    \    }\n    friend mint operator*(const mint &lhs, const mint &rhs) {\n      \
    \  return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const mint &lhs,\
    \ const mint &rhs) {\n        return mint(lhs) /= rhs;\n    }\n    friend bool\
    \ operator==(const mint &lhs, const mint &rhs) {\n        return lhs.val() ==\
    \ rhs.val();\n    }\n    friend bool operator!=(const mint &lhs, const mint &rhs)\
    \ {\n        return !(lhs == rhs);\n    }\n    friend bool operator<(const mint\
    \ &lhs, const mint &rhs) {\n        return lhs._v < rhs._v;\n    }\n    friend\
    \ bool operator>(const mint &lhs, const mint &rhs) {\n        return rhs < lhs;\n\
    \    }\n\n  private:\n    u64 _v = 0;\n\n    constexpr static u64 umod() {\n \
    \       return m;\n    }\n\n    constexpr u64 safe_mod(const u64 &a) {\n     \
    \   u64 au = a >> 61;\n        u64 ad = a & umod();\n        u64 res = au + ad;\n\
    \        if (res >= umod()) res -= umod();\n        return res;\n    }\n};\n\n\
    }  // namespace ebi\n#line 2 \"utility/random_number_generator_64.hpp\"\n\r\n\
    #line 4 \"utility/random_number_generator_64.hpp\"\n#include <random>\r\n\r\n\
    namespace ebi {\r\n\r\nstruct random_number_generator_64 {\r\n  private:\r\n \
    \   using u64 = std::uint64_t;\r\n    std::random_device rnd;\r\n    std::mt19937_64\
    \ mt;\r\n\r\n  public:\r\n    random_number_generator_64() : mt(rnd()) {}\r\n\r\
    \n    u64 get(u64 a, u64 b) {\r\n        std::uniform_int_distribution<u64> dist(a,\
    \ b - 1);\r\n        return dist(mt);\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n\
    #line 7 \"utility/hash.hpp\"\n\nnamespace ebi {\n\ntemplate <int BASE_NUM> struct\
    \ Hash : std::array<modint61, BASE_NUM> {\n  private:\n    using std::array<modint61,\
    \ BASE_NUM>::array;\n    using std::array<modint61, BASE_NUM>::operator=;\n\n\
    \  public:\n    Hash() : std::array<modint61, BASE_NUM>() {}\n\n    constexpr\
    \ static Hash set(const modint61 &a) {\n        Hash res;\n        std::fill(res.begin(),\
    \ res.end(), a);\n        return res;\n    }\n\n    constexpr Hash &operator+=(const\
    \ Hash &rhs) {\n        for (int i = 0; i < BASE_NUM; i++) {\n            (*this)[i]\
    \ += rhs[i];\n        }\n        return *this;\n    }\n    constexpr Hash &operator-=(const\
    \ Hash &rhs) {\n        for (int i = 0; i < BASE_NUM; i++) {\n            (*this)[i]\
    \ -= rhs[i];\n        }\n        return *this;\n    }\n    constexpr Hash &operator*=(const\
    \ Hash &rhs) {\n        for (int i = 0; i < BASE_NUM; i++) {\n            (*this)[i]\
    \ *= rhs[i];\n        }\n        return *this;\n    }\n\n    constexpr Hash &operator+=(const\
    \ modint61 &rhs) {\n        for (int i = 0; i < BASE_NUM; i++) {\n           \
    \ (*this)[i] += rhs;\n        }\n        return *this;\n    }\n    constexpr Hash\
    \ &operator-=(const modint61 &rhs) {\n        for (int i = 0; i < BASE_NUM; i++)\
    \ {\n            (*this)[i] -= rhs;\n        }\n        return *this;\n    }\n\
    \    constexpr Hash &operator*=(const modint61 &rhs) {\n        for (int i = 0;\
    \ i < BASE_NUM; i++) {\n            (*this)[i] *= rhs;\n        }\n        return\
    \ *this;\n    }\n\n    Hash operator+(const Hash &rhs) const {\n        return\
    \ Hash(*this) += rhs;\n    }\n    Hash operator-(const Hash &rhs) const {\n  \
    \      return Hash(*this) -= rhs;\n    }\n    Hash operator*(const Hash &rhs)\
    \ const {\n        return Hash(*this) *= rhs;\n    }\n\n    Hash operator+(const\
    \ modint61 &rhs) const {\n        return Hash(*this) += rhs;\n    }\n    Hash\
    \ operator-(const modint61 &rhs) const {\n        return Hash(*this) -= rhs;\n\
    \    }\n    Hash operator*(const modint61 &rhs) const {\n        return Hash(*this)\
    \ *= rhs;\n    }\n\n    Hash pow(long long n) const {\n        Hash a = *this,\
    \ res = set(1);\n        while (n) {\n            if (n & 1) res *= a;\n     \
    \       a *= a;\n            n >>= 1;\n        }\n        return res;\n    }\n\
    \n    static Hash get_basis() {\n        static random_number_generator_64 rng;\n\
    \        Hash h;\n        for (int i = 0; i < BASE_NUM; i++) {\n            h[i]\
    \ = rng.get(0, modint61::mod() - 1) + 1;\n        }\n        return h;\n    }\n\
    \n    Hash inv() const {\n        Hash h;\n        for (int i = 0; i < BASE_NUM;\
    \ i++) {\n            h[i] = (*this)[i].inv();\n        }\n        return h;\n\
    \    }\n\n    static Hash get_basis_primitive() {\n        static random_number_generator_64\
    \ rng;\n        Hash h;\n        for (int i = 0; i < BASE_NUM; i++) {\n      \
    \      while (!is_primitive(\n                (h[i] = rng.get(0, modint61::mod()\
    \ - 1) + 1).val()))\n                ;\n        }\n        return h;\n    }\n\n\
    \  private:\n    static bool is_primitive(long long x) {\n        for (long long\
    \ d : {2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321}) {\n            if (modint61(x).pow((modint61::mod()\
    \ - 1) / d).val() <= 1)\n                return false;\n        }\n        return\
    \ true;\n    }\n};\n\n}  // namespace ebi\n#line 6 \"tree/rooted_tree_hash.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <int BASE_NUM> struct rooted_tree_hash {\n  private:\n\
    \    using H = Hash<BASE_NUM>;\n\n    static H get_basis(int d) {\n        if\
    \ (int(_basis.size()) <= d) _basis.emplace_back(H::get_basis());\n        return\
    \ _basis[d];\n    }\n\n  public:\n    rooted_tree_hash() = default;\n\n    static\
    \ std::vector<H> subtree_hash(const std::vector<std::vector<int>> &g,\n      \
    \                                 int root = 0) {\n        int n = g.size();\n\
    \        std::vector<H> hash(n, H::set(1));\n        std::vector<int> depth(n,\
    \ 0);\n        auto dfs = [&](auto &&self, int v, int par = -1) -> void {\n  \
    \          for (auto nv : g[v]) {\n                if (nv == par) continue;\n\
    \                self(self, nv, v);\n                depth[v] = std::max(depth[v],\
    \ depth[nv] + 1);\n            }\n            for (auto nv : g[v]) {\n       \
    \         if (nv == par) continue;\n                hash[v] *= hash[nv];\n   \
    \         }\n            if (hash[v] == H::set(1)) hash[v] = H::set(0);\n    \
    \        hash[v] += get_basis(depth[v]);\n            return;\n        };\n  \
    \      dfs(dfs, root);\n        return hash;\n    }\n\n    static std::vector<H>\
    \ basis() {\n        return _basis;\n    }\n\n  private:\n    static std::vector<H>\
    \ _basis;\n};\n\ntemplate <int BASE_NUM>\nstd::vector<Hash<BASE_NUM>> rooted_tree_hash<BASE_NUM>::_basis\
    \ = {};\n\n}  // namespace ebi\n#line 10 \"test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<std::vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        std::cin >>\
    \ p;\n        g[p].emplace_back(i);\n    }\n    auto hash = ebi::rooted_tree_hash<2>::subtree_hash(g,\
    \ 0);\n    int k = 0;\n    std::map<ebi::Hash<2>, int> map;\n    for (auto h :\
    \ hash) {\n        if (map.find(h) == map.end()) map[h] = k++;\n    }\n    std::cout\
    \ << k << '\\n';\n    for (int i = 0; i < n; i++) {\n        std::cout << map[hash[i]]\
    \ << \" \\n\"[i == n - 1];\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include <iostream>\n#include <map>\n#include <vector>\n\n#include \"../../tree/rooted_tree_hash.hpp\"\
    \n#include \"../../utility/hash.hpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<std::vector<int>> g(n);\n    for (int i = 1; i < n; i++)\
    \ {\n        int p;\n        std::cin >> p;\n        g[p].emplace_back(i);\n \
    \   }\n    auto hash = ebi::rooted_tree_hash<2>::subtree_hash(g, 0);\n    int\
    \ k = 0;\n    std::map<ebi::Hash<2>, int> map;\n    for (auto h : hash) {\n  \
    \      if (map.find(h) == map.end()) map[h] = k++;\n    }\n    std::cout << k\
    \ << '\\n';\n    for (int i = 0; i < n; i++) {\n        std::cout << map[hash[i]]\
    \ << \" \\n\"[i == n - 1];\n    }\n}"
  dependsOn:
  - tree/rooted_tree_hash.hpp
  - utility/hash.hpp
  - modint/modint61.hpp
  - modint/base.hpp
  - utility/random_number_generator_64.hpp
  isVerificationFile: true
  path: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
- /verify/test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp.html
title: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
---
