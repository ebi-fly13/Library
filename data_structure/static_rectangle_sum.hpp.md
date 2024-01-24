---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: fenwick tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Rectangle_Sum.test.cpp
    title: test/data_structure/Static_Rectangle_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/static_rectangle_sum.hpp\"\n\n#include <array>\n\
    #include <tuple>\n#include <vector>\n\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#line 6 \"data_structure/compress.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp)\
    \ : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
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
    #line 9 \"data_structure/static_rectangle_sum.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class S, class T> struct static_rectangle_sum {\n  private:\n  public:\n  \
    \  static_rectangle_sum() = default;\n\n    void add_point(S x, S y, T val) {\n\
    \        p.emplace_back(x, y, val);\n        cp_x.add(x);\n        cp_y.add(y);\n\
    \    }\n\n    void add_query(S l, S d, S r, S u) {\n        q.push_back({l, d,\
    \ r, u});\n        cp_x.add(l);\n        cp_x.add(r);\n        cp_y.add(d);\n\
    \        cp_y.add(u);\n    }\n\n    std::vector<T> run() {\n        assert(is_first);\n\
    \        is_first = false;\n        cp_x.build();\n        cp_y.build();\n   \
    \     std::vector ptable(cp_x.size(), std::vector<int>());\n        std::vector\
    \ qtable(cp_x.size(), std::vector(2, std::vector<int>()));\n        for (int i\
    \ = 0; auto [x, y, val] : p) {\n            ptable[cp_x.get(x)].emplace_back(i);\n\
    \            i++;\n        }\n        for (int i = 0; auto [l, d, r, u] : q) {\n\
    \            qtable[cp_x.get(l)][0].emplace_back(i);\n            qtable[cp_x.get(r)][1].emplace_back(i);\n\
    \            i++;\n        }\n        std::vector<T> res(q.size(), 0);\n     \
    \   fenwick_tree<T> ftree(cp_y.size());\n        for (int i = 0; i < cp_x.size();\
    \ i++) {\n            for (int j = 0; j < 2; j++) {\n                for (auto\
    \ idx : qtable[i][j]) {\n                    int d = q[idx][1], u = q[idx][3];\n\
    \                    res[idx] +=\n                        (j == 0 ? -1 : 1) *\
    \ ftree.sum(cp_y.get(d), cp_y.get(u));\n                }\n            }\n   \
    \         for (auto idx : ptable[i]) {\n                auto [x, y, val] = p[idx];\n\
    \                ftree.add(cp_y.get(y), val);\n            }\n        }\n    \
    \    return res;\n    }\n\n  private:\n    bool is_first = true;\n    std::vector<std::tuple<S,\
    \ S, T>> p;\n    std::vector<std::array<S, 4>> q;\n    compress<S> cp_x, cp_y;\n\
    };\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <array>\n#include <tuple>\n#include <vector>\n\n\
    #include \"../data_structure/compress.hpp\"\n#include \"../data_structure/fenwick_tree.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class S, class T> struct static_rectangle_sum\
    \ {\n  private:\n  public:\n    static_rectangle_sum() = default;\n\n    void\
    \ add_point(S x, S y, T val) {\n        p.emplace_back(x, y, val);\n        cp_x.add(x);\n\
    \        cp_y.add(y);\n    }\n\n    void add_query(S l, S d, S r, S u) {\n   \
    \     q.push_back({l, d, r, u});\n        cp_x.add(l);\n        cp_x.add(r);\n\
    \        cp_y.add(d);\n        cp_y.add(u);\n    }\n\n    std::vector<T> run()\
    \ {\n        assert(is_first);\n        is_first = false;\n        cp_x.build();\n\
    \        cp_y.build();\n        std::vector ptable(cp_x.size(), std::vector<int>());\n\
    \        std::vector qtable(cp_x.size(), std::vector(2, std::vector<int>()));\n\
    \        for (int i = 0; auto [x, y, val] : p) {\n            ptable[cp_x.get(x)].emplace_back(i);\n\
    \            i++;\n        }\n        for (int i = 0; auto [l, d, r, u] : q) {\n\
    \            qtable[cp_x.get(l)][0].emplace_back(i);\n            qtable[cp_x.get(r)][1].emplace_back(i);\n\
    \            i++;\n        }\n        std::vector<T> res(q.size(), 0);\n     \
    \   fenwick_tree<T> ftree(cp_y.size());\n        for (int i = 0; i < cp_x.size();\
    \ i++) {\n            for (int j = 0; j < 2; j++) {\n                for (auto\
    \ idx : qtable[i][j]) {\n                    int d = q[idx][1], u = q[idx][3];\n\
    \                    res[idx] +=\n                        (j == 0 ? -1 : 1) *\
    \ ftree.sum(cp_y.get(d), cp_y.get(u));\n                }\n            }\n   \
    \         for (auto idx : ptable[i]) {\n                auto [x, y, val] = p[idx];\n\
    \                ftree.add(cp_y.get(y), val);\n            }\n        }\n    \
    \    return res;\n    }\n\n  private:\n    bool is_first = true;\n    std::vector<std::tuple<S,\
    \ S, T>> p;\n    std::vector<std::array<S, 4>> q;\n    compress<S> cp_x, cp_y;\n\
    };\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/compress.hpp
  - data_structure/fenwick_tree.hpp
  isVerificationFile: false
  path: data_structure/static_rectangle_sum.hpp
  requiredBy: []
  timestamp: '2024-01-24 18:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Static_Rectangle_Sum.test.cpp
documentation_of: data_structure/static_rectangle_sum.hpp
layout: document
title: Static Rectangle Sum
---

## 説明

2次元平面に値があり、長方形内に含まれる値の和を求めるクエリを静的に処理する。点の個数を $N$ 、クエリの個数を $Q$ としたとき、計算量は $O((N + Q)\log{N})$

### add_point(x, y, val)

$(x, y)$ に値 $val$ を加える。

### add_query(l, d, r, u)

$[l, r) \times [d, u)$ の長方形内に含まれる値の和を求めるクエリを追加する。

### run()

クエリを処理して、クエリを追加した順で処理結果を返す。
