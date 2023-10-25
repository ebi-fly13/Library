---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/Line_Add_Get_Min.test.cpp
    title: test/data_structure/Line_Add_Get_Min.test.cpp
  - icon: ':x:'
    path: test/data_structure/Segment_Add_Get_Min.test.cpp
    title: test/data_structure/Segment_Add_Get_Min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/li_chao_tree.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <utility>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class T> struct li_chao_tree {\n  private:\n  \
    \  T f(std::pair<T, T> y, T x) const {\n        return y.first * x + y.second;\n\
    \    }\n\n    void add(std::pair<T, T> y, int l, int r, int index) {\n       \
    \ while (l < r) {\n            bool left = f(y, xs[l]) < f(data[index], xs[l]);\n\
    \            bool mid = f(y, xs[(l + r) / 2]) < f(data[index], xs[(l + r) / 2]);\n\
    \            bool right = f(y, xs[r - 1]) < f(data[index], xs[r - 1]);\n     \
    \       if (left && right) {\n                data[index] = y;\n             \
    \   return;\n            }\n            if (!(left || right)) {\n            \
    \    return;\n            }\n            if (mid) {\n                std::swap(y,\
    \ data[index]);\n                left = !left;\n                right = !right;\n\
    \            }\n            if (left) {\n                r = (l + r) / 2;\n  \
    \              index *= 2;\n            } else {\n                l = (l + r)\
    \ / 2;\n                index = 2 * index + 1;\n            }\n        }\n   \
    \ }\n\n    int get_index(T x) const {\n        auto itr = std::lower_bound(xs.begin(),\
    \ xs.end(), x);\n        return itr - xs.begin();\n    }\n\n  public:\n    li_chao_tree(std::vector<T>\
    \ &_x) : xs(_x), sz(1) {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        while (sz < int(xs.size())) sz <<= 1;\n     \
    \   while (int(xs.size()) < sz) xs.emplace_back(xs.back() + 1);\n        data.assign(2\
    \ * sz, {0, std::numeric_limits<T>::max()});\n    }\n\n    void add_line(T a,\
    \ T b) {\n        add({a, b}, 0, sz, 1);\n    }\n\n    void add_segment(T a, T\
    \ b, T lx, T rx) {\n        int l = get_index(lx);\n        int r = get_index(rx);\n\
    \        assert(0 <= l && l <= r && r <= sz);\n        int il = l + sz;\n    \
    \    int ir = r + sz;\n        int rank = 0;\n        while (il < ir) {\n    \
    \        if (il & 1) {\n                add({a, b}, l, l + (1 << rank), il++);\n\
    \                l += (1 << rank);\n            }\n            if (ir & 1) {\n\
    \                add({a, b}, r - (1 << rank), r, --ir);\n                r -=\
    \ (1 << rank);\n            }\n            rank++;\n            il >>= 1;\n  \
    \          ir >>= 1;\n        }\n    }\n\n    T min(T x) {\n        int k = get_index(x)\
    \ + sz;\n        T val = std::numeric_limits<T>::max();\n        while (k > 0)\
    \ {\n            val = std::min(val, f(data[k], x));\n            k >>= 1;\n \
    \       }\n        return val;\n    }\n\n  private:\n    std::vector<std::pair<T,\
    \ T>> data;\n    std::vector<T> xs;\n    int sz;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <utility>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T>\
    \ struct li_chao_tree {\n  private:\n    T f(std::pair<T, T> y, T x) const {\n\
    \        return y.first * x + y.second;\n    }\n\n    void add(std::pair<T, T>\
    \ y, int l, int r, int index) {\n        while (l < r) {\n            bool left\
    \ = f(y, xs[l]) < f(data[index], xs[l]);\n            bool mid = f(y, xs[(l +\
    \ r) / 2]) < f(data[index], xs[(l + r) / 2]);\n            bool right = f(y, xs[r\
    \ - 1]) < f(data[index], xs[r - 1]);\n            if (left && right) {\n     \
    \           data[index] = y;\n                return;\n            }\n       \
    \     if (!(left || right)) {\n                return;\n            }\n      \
    \      if (mid) {\n                std::swap(y, data[index]);\n              \
    \  left = !left;\n                right = !right;\n            }\n           \
    \ if (left) {\n                r = (l + r) / 2;\n                index *= 2;\n\
    \            } else {\n                l = (l + r) / 2;\n                index\
    \ = 2 * index + 1;\n            }\n        }\n    }\n\n    int get_index(T x)\
    \ const {\n        auto itr = std::lower_bound(xs.begin(), xs.end(), x);\n   \
    \     return itr - xs.begin();\n    }\n\n  public:\n    li_chao_tree(std::vector<T>\
    \ &_x) : xs(_x), sz(1) {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        while (sz < int(xs.size())) sz <<= 1;\n     \
    \   while (int(xs.size()) < sz) xs.emplace_back(xs.back() + 1);\n        data.assign(2\
    \ * sz, {0, std::numeric_limits<T>::max()});\n    }\n\n    void add_line(T a,\
    \ T b) {\n        add({a, b}, 0, sz, 1);\n    }\n\n    void add_segment(T a, T\
    \ b, T lx, T rx) {\n        int l = get_index(lx);\n        int r = get_index(rx);\n\
    \        assert(0 <= l && l <= r && r <= sz);\n        int il = l + sz;\n    \
    \    int ir = r + sz;\n        int rank = 0;\n        while (il < ir) {\n    \
    \        if (il & 1) {\n                add({a, b}, l, l + (1 << rank), il++);\n\
    \                l += (1 << rank);\n            }\n            if (ir & 1) {\n\
    \                add({a, b}, r - (1 << rank), r, --ir);\n                r -=\
    \ (1 << rank);\n            }\n            rank++;\n            il >>= 1;\n  \
    \          ir >>= 1;\n        }\n    }\n\n    T min(T x) {\n        int k = get_index(x)\
    \ + sz;\n        T val = std::numeric_limits<T>::max();\n        while (k > 0)\
    \ {\n            val = std::min(val, f(data[k], x));\n            k >>= 1;\n \
    \       }\n        return val;\n    }\n\n  private:\n    std::vector<std::pair<T,\
    \ T>> data;\n    std::vector<T> xs;\n    int sz;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2023-07-10 17:44:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/data_structure/Line_Add_Get_Min.test.cpp
  - test/data_structure/Segment_Add_Get_Min.test.cpp
documentation_of: data_structure/li_chao_tree.hpp
layout: document
title: Li Chao Tree
---

## 説明

直線追加、線分追加、 $x$ における最小値を処理するデータ構造。 以下、 $N$ は処理する $x$ 座標の個数。

### add(a, b)

直線 $y = ax + b$ を追加。 $O(\log N)$

### add_segment(a, b, l, r)

$x$ 座標の区間 $[l, r)$ に、線分 $y = ax + b$ を追加する。 $O((\log N)^2)$

### min(x)

$x$ における最小値を返す。 $O(\log N)$