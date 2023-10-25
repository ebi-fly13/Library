---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':question:'
    path: data_structure/fenwick_tree.hpp
    title: fenwick tree
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/Inversion_Number.test.cpp
    title: test/math/Inversion_Number.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/inversion_number.hpp\"\n\n#include <cassert>\n#include\
    \ <limits>\n#include <vector>\n\n#line 2 \"data_structure/compress.hpp\"\n\n#include\
    \ <algorithm>\n#line 6 \"data_structure/compress.hpp\"\n\nnamespace ebi {\n\n\
    template <class T> struct compress {\n  private:\n    std::vector<T> cp;\n\n \
    \ public:\n    compress() = default;\n\n    compress(std::vector<T> cp) : cp(cp)\
    \ {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi\n#line 2 \"data_structure/fenwick_tree.hpp\"\
    \n\r\n#line 5 \"data_structure/fenwick_tree.hpp\"\n\r\nnamespace ebi {\r\n\r\n\
    template <class T> struct fenwick_tree {\r\n  private:\r\n    int n;\r\n    std::vector<T>\
    \ data;\r\n\r\n  public:\r\n    fenwick_tree(int _n) : n(_n), data(std::vector<T>(_n\
    \ + 1, T(0))) {}\r\n\r\n    void add(int i, T val) {\r\n        i++;\r\n     \
    \   for (int x = i; x <= n; x += x & -x) {\r\n            data[x] += val;\r\n\
    \        }\r\n    }\r\n\r\n    T prefix_sum(int i) const {\r\n        assert(0\
    \ <= i && i <= n);\r\n        T ret = 0;\r\n        for (int x = i; x > 0; x -=\
    \ x & -x) {\r\n            ret += data[x];\r\n        }\r\n        return ret;\r\
    \n    }\r\n\r\n    T sum(int l, int r) const {\r\n        return prefix_sum(r)\
    \ - prefix_sum(l);\r\n    }\r\n\r\n    T all_sum() const {\r\n        return prefix_sum(n);\r\
    \n    }\r\n\r\n    // prefix_sum(x) >= key \u3068\u306A\u308B\u6700\u5C0F\u306E\
    x\u3092\u8FD4\u3059\u95A2\u6570 O(log N)\r\n    int lower_bound(T key) {\r\n \
    \       if (key <= 0) return 0;\r\n        int x = 0;\r\n        int max = 1;\r\
    \n        while ((max << 1) <= n) max <<= 1;\r\n        for (int k = max; k >\
    \ 0; k >>= 1) {\r\n            if (x + k <= n && data[x + k] < key) {\r\n    \
    \            x += k;\r\n                key -= data[x];\r\n            }\r\n \
    \       }\r\n        return x + 1;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n\
    #line 2 \"template/int_alias.hpp\"\n\n#include <cstdint>\n\nnamespace ebi {\n\n\
    using std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16\
    \ = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}  // namespace ebi\n#line\
    \ 10 \"math/inversion_number.hpp\"\n\nnamespace ebi {\n\ni64 inversion_number_max_n(const\
    \ std::vector<int> &a, int n = 200000) {\n    fenwick_tree<i64> fw(n);\n    i64\
    \ res = 0;\n    for (auto x : a) {\n        assert(0 <= x && x < n);\n       \
    \ res += fw.sum(x + 1, n);\n        fw.add(x, 1);\n    }\n    return res;\n}\n\
    \ntemplate <class T> i64 inversion_number(const std::vector<T> &a) {\n    compress<T>\
    \ cp;\n    for (const auto &x : a) {\n        cp.add(x);\n    }\n    cp.build();\n\
    \    std::vector<int> ca;\n    ca.reserve(a.size());\n    for (const auto &x :\
    \ a) {\n        ca.emplace_back(cp.get(x));\n    }\n    return inversion_number_max_n(ca,\
    \ cp.size());\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \n#include \"../data_structure/compress.hpp\"\n#include \"../data_structure/fenwick_tree.hpp\"\
    \n#include \"../template/int_alias.hpp\"\n\nnamespace ebi {\n\ni64 inversion_number_max_n(const\
    \ std::vector<int> &a, int n = 200000) {\n    fenwick_tree<i64> fw(n);\n    i64\
    \ res = 0;\n    for (auto x : a) {\n        assert(0 <= x && x < n);\n       \
    \ res += fw.sum(x + 1, n);\n        fw.add(x, 1);\n    }\n    return res;\n}\n\
    \ntemplate <class T> i64 inversion_number(const std::vector<T> &a) {\n    compress<T>\
    \ cp;\n    for (const auto &x : a) {\n        cp.add(x);\n    }\n    cp.build();\n\
    \    std::vector<int> ca;\n    ca.reserve(a.size());\n    for (const auto &x :\
    \ a) {\n        ca.emplace_back(cp.get(x));\n    }\n    return inversion_number_max_n(ca,\
    \ cp.size());\n}\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/compress.hpp
  - data_structure/fenwick_tree.hpp
  - template/int_alias.hpp
  isVerificationFile: false
  path: math/inversion_number.hpp
  requiredBy: []
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/Inversion_Number.test.cpp
documentation_of: math/inversion_number.hpp
layout: document
title: Inversion Number
---

## 説明

### inversion_number_max_n(std::vector<int> a, int n)

$0 \leq a_i < n$ であるような数列 $a$ に対して、転倒数を求める。 $O(N\log N)$

### inversion_number(std::vector<T> a)

数列 $a$ に対して、転倒数を求める。 $O(N\log N)$