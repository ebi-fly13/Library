---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/lowest_common_ancestor.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Rmq.test.cpp
    title: test/data_structure/Static_Rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/lowest_common_ancestor.test.cpp
    title: test/tree/lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://scrapbox.io/data-structures/Sparse_Table
  bundledCode: "#line 2 \"data_structure/sparse_table.hpp\"\n\r\n#include <vector>\r\
    \n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class Band, Band (*op)(Band, Band)>\
    \ struct sparse_table {\r\n  public:\r\n    sparse_table() = default;\r\n\r\n\
    \    sparse_table(const std::vector<Band> &a) : n(a.size()) {\r\n        table\
    \ = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n        for (int i\
    \ = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n        }\r\n     \
    \   for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int i = 0; i + (1\
    \ << k) <= n; i++) {\r\n                table[k][i] =\r\n                    op(table[k\
    \ - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n            }\r\n        }\r\n\
    \    }\r\n\r\n    void build(const std::vector<Band> &a) {\r\n        n = (int)a.size();\r\
    \n        table = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n   \
    \     for (int i = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n   \
    \     }\r\n        for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int\
    \ i = 0; i + (1 << k) <= n; i++) {\r\n                table[k][i] =\r\n      \
    \              op(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n    \
    \        }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Band fold(int l,\
    \ int r) {\r\n        int k = std::__lg(r - l);\r\n        return op(table[k][l],\
    \ table[k][r - (1 << k)]);\r\n    }\r\n\r\n  private:\r\n    int n;\r\n    std::vector<std::vector<Band>>\
    \ table;\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class Band, Band (*op)(Band, Band)>\
    \ struct sparse_table {\r\n  public:\r\n    sparse_table() = default;\r\n\r\n\
    \    sparse_table(const std::vector<Band> &a) : n(a.size()) {\r\n        table\
    \ = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n        for (int i\
    \ = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n        }\r\n     \
    \   for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int i = 0; i + (1\
    \ << k) <= n; i++) {\r\n                table[k][i] =\r\n                    op(table[k\
    \ - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n            }\r\n        }\r\n\
    \    }\r\n\r\n    void build(const std::vector<Band> &a) {\r\n        n = (int)a.size();\r\
    \n        table = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n   \
    \     for (int i = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n   \
    \     }\r\n        for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int\
    \ i = 0; i + (1 << k) <= n; i++) {\r\n                table[k][i] =\r\n      \
    \              op(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n    \
    \        }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Band fold(int l,\
    \ int r) {\r\n        int k = std::__lg(r - l);\r\n        return op(table[k][l],\
    \ table[k][r - (1 << k)]);\r\n    }\r\n\r\n  private:\r\n    int n;\r\n    std::vector<std::vector<Band>>\
    \ table;\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy:
  - tree/lowest_common_ancestor.hpp
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/lowest_common_ancestor.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
  - test/data_structure/Static_Rmq.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: data_structure/sparse_table.hpp
---
