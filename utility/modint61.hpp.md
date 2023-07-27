---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: tree/rooted_tree_hash.hpp
    title: Rooted Tree Hash
  - icon: ':heavy_check_mark:'
    path: utility/hash.hpp
    title: Hash structure
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2444.test.cpp
    title: test/aoj/aoj_2444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
    title: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/modint61.hpp\"\n\n#include <cassert>\n#include <cstdint>\n\
    #include <iostream>\n\n#line 2 \"utility/modint_base.hpp\"\n\n#include <type_traits>\n\
    \nnamespace ebi {\n\nnamespace internal {\n\nstruct modint_base {};\n\ntemplate\
    \ <class T> using is_modint = std::is_base_of<modint_base, T>;\ntemplate <class\
    \ T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\nstruct static_modint_base\
    \ : modint_base {};\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint61.hpp\"\
    \n\nnamespace ebi {\n\nstruct modint61 : internal::static_modint_base {\n  private:\n\
    \    using mint = modint61;\n    using u64 = std::uint64_t;\n    constexpr static\
    \ u64 m = (1ull << 61) - 1;\n    constexpr static u64 MASK31 = (1ull << 31) -\
    \ 1;\n    constexpr static u64 MASK30 = (1ull << 30) - 1;\n\n  public:\n    constexpr\
    \ static u64 mod() {\n        return m;\n    }\n\n    constexpr modint61() : _v(0)\
    \ {}\n\n    constexpr modint61(long long v) {\n        v %= (long long)umod();\n\
    \        if (v < 0) v += (long long)umod();\n        _v = u64(v);\n    }\n\n \
    \   constexpr u64 val() const {\n        return _v;\n    }\n\n    constexpr u64\
    \ value() const {\n        return val();\n    }\n\n    constexpr mint &operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n\n    constexpr mint &operator--() {\n        if (_v == 0) _v = umod();\n\
    \        _v--;\n        return *this;\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &rhs) {\n        _v += rhs._v;\n        _v = safe_mod(_v);\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator-=(const mint &rhs) {\n       \
    \ if (_v < rhs._v) _v += umod();\n        assert(_v >= rhs._v);\n        _v -=\
    \ rhs._v;\n        return *this;\n    }\n\n    constexpr mint &operator*=(const\
    \ mint &rhs) {\n        u64 au = _v >> 31, ad = _v & MASK31;\n        u64 bu =\
    \ rhs._v >> 31, bd = rhs._v & MASK31;\n        u64 mid = ad * bu + au * bd;\n\
    \        u64 midu = mid >> 30;\n        u64 midd = mid & MASK30;\n        _v =\
    \ (au * bu * 2 + midu + (midd << 31) + ad * bd);\n        _v = safe_mod(_v);\n\
    \        return *this;\n    }\n\n    constexpr mint &operator/=(const mint &rhs)\
    \ {\n        return *this *= rhs.inv();\n    }\n\n    constexpr mint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        mint x = *this, res = 1;\n\
    \        while (n) {\n            if (n & 1) res *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return res;\n    }\n\n    constexpr\
    \ mint inv() const {\n        assert(_v);\n        return pow(umod() - 2);\n \
    \   }\n\n    friend mint operator+(const mint &lhs, const mint &rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint &lhs,\
    \ const mint &rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint &lhs, const mint &rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint &lhs, const mint &rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint &lhs,\
    \ const mint &rhs) {\n        return lhs.val() == rhs.val();\n    }\n    friend\
    \ bool operator!=(const mint &lhs, const mint &rhs) {\n        return !(lhs ==\
    \ rhs);\n    }\n    friend bool operator<(const mint &lhs, const mint &rhs) {\n\
    \        return lhs._v < rhs._v;\n    }\n    friend bool operator>(const mint\
    \ &lhs, const mint &rhs) {\n        return rhs < lhs;\n    }\n\n  private:\n \
    \   u64 _v = 0;\n\n    constexpr static u64 umod() {\n        return m;\n    }\n\
    \n    constexpr u64 safe_mod(const u64 &a) {\n        u64 au = a >> 61;\n    \
    \    u64 ad = a & umod();\n        u64 res = au + ad;\n        if (res >= umod())\
    \ res -= umod();\n        return res;\n    }\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstdint>\n#include <iostream>\n\
    \n#include \"../utility/modint_base.hpp\"\n\nnamespace ebi {\n\nstruct modint61\
    \ : internal::static_modint_base {\n  private:\n    using mint = modint61;\n \
    \   using u64 = std::uint64_t;\n    constexpr static u64 m = (1ull << 61) - 1;\n\
    \    constexpr static u64 MASK31 = (1ull << 31) - 1;\n    constexpr static u64\
    \ MASK30 = (1ull << 30) - 1;\n\n  public:\n    constexpr static u64 mod() {\n\
    \        return m;\n    }\n\n    constexpr modint61() : _v(0) {}\n\n    constexpr\
    \ modint61(long long v) {\n        v %= (long long)umod();\n        if (v < 0)\
    \ v += (long long)umod();\n        _v = u64(v);\n    }\n\n    constexpr u64 val()\
    \ const {\n        return _v;\n    }\n\n    constexpr u64 value() const {\n  \
    \      return val();\n    }\n\n    constexpr mint &operator++() {\n        _v++;\n\
    \        if (_v == umod()) _v = 0;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n   \
    \     return *this;\n    }\n\n    constexpr mint &operator+=(const mint &rhs)\
    \ {\n        _v += rhs._v;\n        _v = safe_mod(_v);\n        return *this;\n\
    \    }\n\n    constexpr mint &operator-=(const mint &rhs) {\n        if (_v <\
    \ rhs._v) _v += umod();\n        assert(_v >= rhs._v);\n        _v -= rhs._v;\n\
    \        return *this;\n    }\n\n    constexpr mint &operator*=(const mint &rhs)\
    \ {\n        u64 au = _v >> 31, ad = _v & MASK31;\n        u64 bu = rhs._v >>\
    \ 31, bd = rhs._v & MASK31;\n        u64 mid = ad * bu + au * bd;\n        u64\
    \ midu = mid >> 30;\n        u64 midd = mid & MASK30;\n        _v = (au * bu *\
    \ 2 + midu + (midd << 31) + ad * bd);\n        _v = safe_mod(_v);\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator/=(const mint &rhs) {\n       \
    \ return *this *= rhs.inv();\n    }\n\n    constexpr mint pow(long long n) const\
    \ {\n        assert(0 <= n);\n        mint x = *this, res = 1;\n        while\
    \ (n) {\n            if (n & 1) res *= x;\n            x *= x;\n            n\
    \ >>= 1;\n        }\n        return res;\n    }\n\n    constexpr mint inv() const\
    \ {\n        assert(_v);\n        return pow(umod() - 2);\n    }\n\n    friend\
    \ mint operator+(const mint &lhs, const mint &rhs) {\n        return mint(lhs)\
    \ += rhs;\n    }\n    friend mint operator-(const mint &lhs, const mint &rhs)\
    \ {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint &lhs, const mint &rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint &lhs, const mint &rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint &lhs, const mint &rhs)\
    \ {\n        return lhs.val() == rhs.val();\n    }\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) {\n        return !(lhs == rhs);\n    }\n    friend\
    \ bool operator<(const mint &lhs, const mint &rhs) {\n        return lhs._v <\
    \ rhs._v;\n    }\n    friend bool operator>(const mint &lhs, const mint &rhs)\
    \ {\n        return rhs < lhs;\n    }\n\n  private:\n    u64 _v = 0;\n\n    constexpr\
    \ static u64 umod() {\n        return m;\n    }\n\n    constexpr u64 safe_mod(const\
    \ u64 &a) {\n        u64 au = a >> 61;\n        u64 ad = a & umod();\n       \
    \ u64 res = au + ad;\n        if (res >= umod()) res -= umod();\n        return\
    \ res;\n    }\n};\n\n}  // namespace ebi"
  dependsOn:
  - utility/modint_base.hpp
  isVerificationFile: false
  path: utility/modint61.hpp
  requiredBy:
  - string/rolling_hash.hpp
  - utility/hash.hpp
  - tree/rooted_tree_hash.hpp
  timestamp: '2023-07-17 11:19:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2444.test.cpp
  - test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
documentation_of: utility/modint61.hpp
layout: document
redirect_from:
- /library/utility/modint61.hpp
- /library/utility/modint61.hpp.html
title: utility/modint61.hpp
---