---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/hash.hpp
    title: Hash structure
  - icon: ':heavy_check_mark:'
    path: utility/modint61.hpp
    title: utility/modint61.hpp
  - icon: ':question:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  - icon: ':heavy_check_mark:'
    path: utility/random_number_generator_64.hpp
    title: utility/random_number_generator_64.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2444.test.cpp
    title: test/aoj/aoj_2444.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n\r\n#include <array>\r\n#include\
    \ <cassert>\r\n#include <cstdint>\r\n#include <vector>\r\n\r\n#line 2 \"utility/hash.hpp\"\
    \n\n#line 4 \"utility/hash.hpp\"\n\n#line 2 \"utility/modint61.hpp\"\n\n#line\
    \ 5 \"utility/modint61.hpp\"\n#include <iostream>\n\n#line 2 \"utility/modint_base.hpp\"\
    \n\n#include <type_traits>\n\nnamespace ebi {\n\nnamespace internal {\n\nstruct\
    \ modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint61.hpp\"\
    \n\nnamespace ebi {\n\nstruct modint61 : internal::modint_base {\n  private:\n\
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
    \ res -= umod();\n        return res;\n    }\n};\n\n}  // namespace ebi\n#line\
    \ 2 \"utility/random_number_generator_64.hpp\"\n\r\n#line 4 \"utility/random_number_generator_64.hpp\"\
    \n#include <random>\r\n\r\nnamespace ebi {\r\n\r\nstruct random_number_generator_64\
    \ {\r\n  private:\r\n    using u64 = std::uint64_t;\r\n    std::random_device\
    \ rnd;\r\n    std::mt19937_64 mt;\r\n\r\n  public:\r\n    random_number_generator_64()\
    \ : mt(rnd()) {}\r\n\r\n    u64 get(u64 a, u64 b) {\r\n        std::uniform_int_distribution<u64>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 7 \"utility/hash.hpp\"\n\nnamespace ebi {\n\ntemplate <int BASE_NUM>\
    \ struct Hash : std::array<modint61, BASE_NUM> {\n  private:\n    using std::array<modint61,\
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
    \n    static Hash get_basis_primitive() {\n        static random_number_generator_64\
    \ rng;\n        Hash h;\n        for (int i = 0; i < BASE_NUM; i++) {\n      \
    \      while (!is_primitive(\n                (h[i] = rng.get(0, modint61::mod()\
    \ - 1) + 1).val()))\n                ;\n        }\n        return h;\n    }\n\n\
    \  private:\n    static bool is_primitive(long long x) {\n        for (long long\
    \ d : {2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321}) {\n            if (modint61(x).pow((modint61::mod()\
    \ - 1) / d).val() <= 1)\n                return false;\n        }\n        return\
    \ true;\n    }\n};\n\n}  // namespace ebi\n#line 10 \"string/rolling_hash.hpp\"\
    \n\r\n/*\r\n    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate <int n> struct rolling_hash {\r\n\
    \  private:\r\n    using mint = modint61;\r\n    static constexpr mint h = 100;\r\
    \n\r\n  public:\r\n    rolling_hash(const std::string &s) : sz(s.size()) {\r\n\
    \        assert(n >= 0);\r\n        base_pow.reserve(sz + 1);\r\n        base_pow.emplace_back(Hash<n>::set(1));\r\
    \n        hash.reserve(sz + 1);\r\n        hash.emplace_back(Hash<n>::set(0));\r\
    \n        for (const auto &c : s) {\r\n            hash.emplace_back(hash.back()\
    \ * base + c + h);\r\n            base_pow.emplace_back(base_pow.back() * base);\r\
    \n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Hash<n> get_hash(int l, int r)\
    \ const {\r\n        assert(0 <= l && l <= r && r <= sz);\r\n        return hash[r]\
    \ - hash[l] * base_pow[r - l];\r\n    }\r\n\r\n    static Hash<n> get_hash(const\
    \ std::string &str, int l = 0, int r = -1) {\r\n        if (r < 0) r = int(str.size());\r\
    \n        Hash<n> res = Hash<n>::set(0);\r\n        for (int i = l; i < r; i++)\
    \ {\r\n            res = res * base + str[i] + h;\r\n        }\r\n        return\
    \ res;\r\n    }\r\n\r\n    Hash<n> concat(const Hash<n> &hash1, const Hash<n>\
    \ &hash2, int len2) {\r\n        return hash1 * base.pow(len2) + hash2;\r\n  \
    \  }\r\n\r\n    static void set_base() {\r\n        base = Hash<n>::get_basis_primitive();\r\
    \n    }\r\n\r\n  private:\r\n    int sz;\r\n    std::vector<Hash<n>> base_pow;\r\
    \n    std::vector<Hash<n>> hash;\r\n\r\n  public:\r\n    static Hash<n> base;\r\
    \n};\r\n\r\ntemplate <int n> Hash<n> rolling_hash<n>::base = {};\r\n\r\n}  //\
    \ namespace ebi\r\n"
  code: "#pragma once\r\n\r\n#include <array>\r\n#include <cassert>\r\n#include <cstdint>\r\
    \n#include <vector>\r\n\r\n#include \"../utility/hash.hpp\"\r\n#include \"../utility/modint61.hpp\"\
    \r\n\r\n/*\r\n    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate <int n> struct rolling_hash {\r\n\
    \  private:\r\n    using mint = modint61;\r\n    static constexpr mint h = 100;\r\
    \n\r\n  public:\r\n    rolling_hash(const std::string &s) : sz(s.size()) {\r\n\
    \        assert(n >= 0);\r\n        base_pow.reserve(sz + 1);\r\n        base_pow.emplace_back(Hash<n>::set(1));\r\
    \n        hash.reserve(sz + 1);\r\n        hash.emplace_back(Hash<n>::set(0));\r\
    \n        for (const auto &c : s) {\r\n            hash.emplace_back(hash.back()\
    \ * base + c + h);\r\n            base_pow.emplace_back(base_pow.back() * base);\r\
    \n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Hash<n> get_hash(int l, int r)\
    \ const {\r\n        assert(0 <= l && l <= r && r <= sz);\r\n        return hash[r]\
    \ - hash[l] * base_pow[r - l];\r\n    }\r\n\r\n    static Hash<n> get_hash(const\
    \ std::string &str, int l = 0, int r = -1) {\r\n        if (r < 0) r = int(str.size());\r\
    \n        Hash<n> res = Hash<n>::set(0);\r\n        for (int i = l; i < r; i++)\
    \ {\r\n            res = res * base + str[i] + h;\r\n        }\r\n        return\
    \ res;\r\n    }\r\n\r\n    Hash<n> concat(const Hash<n> &hash1, const Hash<n>\
    \ &hash2, int len2) {\r\n        return hash1 * base.pow(len2) + hash2;\r\n  \
    \  }\r\n\r\n    static void set_base() {\r\n        base = Hash<n>::get_basis_primitive();\r\
    \n    }\r\n\r\n  private:\r\n    int sz;\r\n    std::vector<Hash<n>> base_pow;\r\
    \n    std::vector<Hash<n>> hash;\r\n\r\n  public:\r\n    static Hash<n> base;\r\
    \n};\r\n\r\ntemplate <int n> Hash<n> rolling_hash<n>::base = {};\r\n\r\n}  //\
    \ namespace ebi\r\n"
  dependsOn:
  - utility/hash.hpp
  - utility/modint61.hpp
  - utility/modint_base.hpp
  - utility/random_number_generator_64.hpp
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-06-06 14:12:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2444.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
title: Rolling Hash
---

## 説明

文字列のハッシュを計算する。

### get_hash(int l, int r)

文字列の $[l, r)$ のハッシュを計算する。 $O(1)$

### get_hash(std::string str, int l, int r)

文字列 $str$ の $[l, r)$ のハッシュを計算する。デフォルトでは文字列全体となる。

### concat(Hash hash1, Hash hash2, int len2)

文字列 s1 のハッシュを hash1、文字列 s2 のハッシュを hash2として s1 + s2 のハッシュを計算する。len2 には s2 の長さを渡す。 $O(\log p)$