---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/aoj/aoj_1068_2.cpp
    title: test/aoj/aoj_1068_2.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/sparse_table_2d.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace ebi {\n\ntemplate <class S, S (*op)(S, S)> struct\
    \ sparse_table_2d {\n    sparse_table_2d(const std::vector<std::vector<S>> &table)\
    \ {\n        h = table.size();\n        w = h > 0 ? table[0].size() : 0;\n   \
    \     lg_table.resize(std::max(h, w) + 1);\n        lg_table[0] = lg_table[1]\
    \ = 0;\n        for (int i = 2; i <= std::max(h, w); i++)\n            lg_table[i]\
    \ = lg_table[i >> 1] + 1;\n        lg_h = lg_table[h];\n        lg_w = lg_table[w];\n\
    \        st = std::vector(\n            lg_h + 1, std::vector(lg_w + 1, std::vector(h,\
    \ std::vector<S>(w))));\n        for (int i = 0; i < h; i++) {\n            for\
    \ (int j = 0; j < w; j++) {\n                st[0][0][i][j] = table[i][j];\n \
    \           }\n        }\n        for (int k = 0; (1 << k) <= h; k++) {\n    \
    \        for (int l = 0; (1 << l) <= w; l++) {\n                if (k == 0 &&\
    \ l == 0) continue;\n                for (int i = 0; i + (1 << k) <= h; i++) {\n\
    \                    for (int j = 0; j + (1 << l) <= w; j++) {\n             \
    \           if (k > 0)\n                            st[k][l][i][j] =\n       \
    \                         op(st[k - 1][l][i][j],\n                           \
    \        st[k - 1][l][i + (1 << (k - 1))][j]);\n                        else\n\
    \                            st[k][l][i][j] =\n                              \
    \  op(st[k][l - 1][i][j],\n                                   st[k][l - 1][i][j\
    \ + (1 << (l - 1))]);\n                    }\n                }\n            }\n\
    \        }\n    }\n\n    S prod(int l, int d, int r, int u) const {\n        assert(l\
    \ < r && d < u);\n        int lg_lr = lg_table[r - l];\n        int lg_du = lg_table[u\
    \ - d];\n        return op(\n            op(st[lg_lr][lg_du][l][d], st[lg_lr][lg_du][r\
    \ - (1 << lg_lr)][d]),\n            op(st[lg_lr][lg_du][l][u - (1 << lg_du)],\n\
    \               st[lg_lr][lg_du][r - (1 << lg_lr)][u - (1 << lg_du)]));\n    }\n\
    \n  private:\n    int h, w;\n    int lg_h, lg_w;\n    std::vector<int> lg_table;\n\
    \    std::vector<std::vector<std::vector<std::vector<S>>>> st;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nnamespace ebi {\n\
    \ntemplate <class S, S (*op)(S, S)> struct sparse_table_2d {\n    sparse_table_2d(const\
    \ std::vector<std::vector<S>> &table) {\n        h = table.size();\n        w\
    \ = h > 0 ? table[0].size() : 0;\n        lg_table.resize(std::max(h, w) + 1);\n\
    \        lg_table[0] = lg_table[1] = 0;\n        for (int i = 2; i <= std::max(h,\
    \ w); i++)\n            lg_table[i] = lg_table[i >> 1] + 1;\n        lg_h = lg_table[h];\n\
    \        lg_w = lg_table[w];\n        st = std::vector(\n            lg_h + 1,\
    \ std::vector(lg_w + 1, std::vector(h, std::vector<S>(w))));\n        for (int\
    \ i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n          \
    \      st[0][0][i][j] = table[i][j];\n            }\n        }\n        for (int\
    \ k = 0; (1 << k) <= h; k++) {\n            for (int l = 0; (1 << l) <= w; l++)\
    \ {\n                if (k == 0 && l == 0) continue;\n                for (int\
    \ i = 0; i + (1 << k) <= h; i++) {\n                    for (int j = 0; j + (1\
    \ << l) <= w; j++) {\n                        if (k > 0)\n                   \
    \         st[k][l][i][j] =\n                                op(st[k - 1][l][i][j],\n\
    \                                   st[k - 1][l][i + (1 << (k - 1))][j]);\n  \
    \                      else\n                            st[k][l][i][j] =\n  \
    \                              op(st[k][l - 1][i][j],\n                      \
    \             st[k][l - 1][i][j + (1 << (l - 1))]);\n                    }\n \
    \               }\n            }\n        }\n    }\n\n    S prod(int l, int d,\
    \ int r, int u) const {\n        assert(l < r && d < u);\n        int lg_lr =\
    \ lg_table[r - l];\n        int lg_du = lg_table[u - d];\n        return op(\n\
    \            op(st[lg_lr][lg_du][l][d], st[lg_lr][lg_du][r - (1 << lg_lr)][d]),\n\
    \            op(st[lg_lr][lg_du][l][u - (1 << lg_du)],\n               st[lg_lr][lg_du][r\
    \ - (1 << lg_lr)][u - (1 << lg_du)]));\n    }\n\n  private:\n    int h, w;\n \
    \   int lg_h, lg_w;\n    std::vector<int> lg_table;\n    std::vector<std::vector<std::vector<std::vector<S>>>>\
    \ st;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table_2d.hpp
  requiredBy:
  - test/aoj/aoj_1068_2.cpp
  timestamp: '2023-06-27 01:22:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sparse_table_2d.hpp
layout: document
title: 2D sparse table
---

## 説明

長方形領域のmax, minなどが行えるデータ構造。スパーステーブルに乗る構造なら乗る。
構築 $O(HW\log H \log W)$ / クエリ $O(1)$

### prod(l, d, r, u)

$[l, r) \times [d, u)$ の長方形に対してクエリを答える。 $O(1)$