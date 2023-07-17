---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/data_structure/Static_Rmq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include <iostream>\r\n\
    #include <vector>\r\n\r\n#line 2 \"data_structure/sparse_table.hpp\"\n\r\n#line\
    \ 4 \"data_structure/sparse_table.hpp\"\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\
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
    \ table;\r\n};\r\n\r\n}  // namespace ebi\n#line 7 \"test/data_structure/Static_Rmq.test.cpp\"\
    \n\r\nint op(int a, int b) {\r\n    return a < b ? a : b;\r\n}\r\n\r\nint main()\
    \ {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<int> a(n);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        std::cin >> a[i];\r\n    }\r\n\
    \    ebi::sparse_table<int, op> st(a);\r\n    while (q--) {\r\n        int l,\
    \ r;\r\n        std::cin >> l >> r;\r\n        std::cout << st.fold(l, r) << std::endl;\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n\r\n#include \"../../data_structure/sparse_table.hpp\"\
    \r\n\r\nint op(int a, int b) {\r\n    return a < b ? a : b;\r\n}\r\n\r\nint main()\
    \ {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<int> a(n);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        std::cin >> a[i];\r\n    }\r\n\
    \    ebi::sparse_table<int, op> st(a);\r\n    while (q--) {\r\n        int l,\
    \ r;\r\n        std::cin >> l >> r;\r\n        std::cout << st.fold(l, r) << std::endl;\r\
    \n    }\r\n}"
  dependsOn:
  - data_structure/sparse_table.hpp
  isVerificationFile: true
  path: test/data_structure/Static_Rmq.test.cpp
  requiredBy: []
  timestamp: '2023-07-17 14:12:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/Static_Rmq.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Static_Rmq.test.cpp
- /verify/test/data_structure/Static_Rmq.test.cpp.html
title: test/data_structure/Static_Rmq.test.cpp
---