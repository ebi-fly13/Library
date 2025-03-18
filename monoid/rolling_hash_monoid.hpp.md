---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint61.hpp
    title: modint/modint61.hpp
  - icon: ':heavy_check_mark:'
    path: utility/random_number_generator.hpp
    title: Random Number Generator
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: Rolling Hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2444.test.cpp
    title: test/aoj/aoj_2444.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoid/rolling_hash_monoid.hpp\"\n\n#include <utility>\n\
    \n#line 2 \"modint/modint61.hpp\"\n\n#include <cassert>\n#include <cstdint>\n\
    #include <iostream>\n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line\
    \ 6 \"modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint\
    \ = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n   \
    \ a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n\
    };\n\ntemplate <Modint mint> std::istream &operator>>(std::istream &os, mint &a)\
    \ {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate\
    \ <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const mint &a) {\n\
    \    return os << a.val();\n}\n\n}  // namespace ebi\n#line 8 \"modint/modint61.hpp\"\
    \n\nnamespace ebi {\n\nstruct modint61 {\n  private:\n    using mint = modint61;\n\
    \    using u64 = std::uint64_t;\n    constexpr static u64 m = (1ull << 61) - 1;\n\
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
    \ res;\n    }\n};\n\n}  // namespace ebi\n#line 2 \"utility/random_number_generator.hpp\"\
    \n\r\n#include <algorithm>\r\n#line 5 \"utility/random_number_generator.hpp\"\n\
    #include <numeric>\r\n#include <random>\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nstruct random_number_generator {\r\n    random_number_generator(int\
    \ seed = -1) {\r\n        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\
    \n    }\r\n\r\n    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n   \
    \ }\r\n\r\n    template <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n    std::vector<int>\
    \ get_permutation(int n) {\r\n        std::vector<int> p(n);\r\n        std::iota(p.begin(),\
    \ p.end(), 0);\r\n        std::shuffle(p.begin(), p.end(), mt);\r\n        return\
    \ p;\r\n    }\r\n\r\n  private:\r\n    std::mt19937_64 mt;\r\n    std::random_device\
    \ rnd;\r\n};\r\n\r\n}  // namespace ebi\n#line 7 \"monoid/rolling_hash_monoid.hpp\"\
    \n\nnamespace ebi {\n\nstruct rolling_hash_monoid : std::pair<modint61, modint61>\
    \ {\n  private:\n    using Self = rolling_hash_monoid;\n    using std::pair<modint61,\
    \ modint61>::pair;\n\n  public:\n    template <class T> rolling_hash_monoid(T\
    \ x) {\n        this->first = get_base();\n        this->second = x;\n    }\n\n\
    \    modint61 get_hash() {\n        return this->second;\n    }\n\n    Self &operator+=(const\
    \ Self &rhs) {\n        this->first = this->first * rhs.first;\n        this->second\
    \ = this->second * rhs.first + rhs.second;\n        return *this;\n    }\n\n \
    \   friend Self operator+(const Self &lhs, const Self &rhs) {\n        return\
    \ Self(lhs) += rhs;\n    }\n\n    static Self e() {\n        return {1, 0};\n\
    \    }\n\n    static modint61 get_base() {\n        static modint61 base = 0;\n\
    \        static random_number_generator rng;\n        while (base == 0) {\n  \
    \          base = rng.get<std::uint64_t>(2, modint61::mod());\n        }\n   \
    \     return base;\n    }\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <utility>\n\n#include \"../modint/modint61.hpp\"\
    \n#include \"../utility/random_number_generator.hpp\"\n\nnamespace ebi {\n\nstruct\
    \ rolling_hash_monoid : std::pair<modint61, modint61> {\n  private:\n    using\
    \ Self = rolling_hash_monoid;\n    using std::pair<modint61, modint61>::pair;\n\
    \n  public:\n    template <class T> rolling_hash_monoid(T x) {\n        this->first\
    \ = get_base();\n        this->second = x;\n    }\n\n    modint61 get_hash() {\n\
    \        return this->second;\n    }\n\n    Self &operator+=(const Self &rhs)\
    \ {\n        this->first = this->first * rhs.first;\n        this->second = this->second\
    \ * rhs.first + rhs.second;\n        return *this;\n    }\n\n    friend Self operator+(const\
    \ Self &lhs, const Self &rhs) {\n        return Self(lhs) += rhs;\n    }\n\n \
    \   static Self e() {\n        return {1, 0};\n    }\n\n    static modint61 get_base()\
    \ {\n        static modint61 base = 0;\n        static random_number_generator\
    \ rng;\n        while (base == 0) {\n            base = rng.get<std::uint64_t>(2,\
    \ modint61::mod());\n        }\n        return base;\n    }\n};\n\n}  // namespace\
    \ ebi"
  dependsOn:
  - modint/modint61.hpp
  - modint/base.hpp
  - utility/random_number_generator.hpp
  isVerificationFile: false
  path: monoid/rolling_hash_monoid.hpp
  requiredBy:
  - string/rolling_hash.hpp
  timestamp: '2025-03-17 19:02:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2444.test.cpp
documentation_of: monoid/rolling_hash_monoid.hpp
layout: document
title: Rolling Hash Monoid
---

## 説明

ローリングハッシュのモノイド構造体。