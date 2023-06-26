---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table_2d.hpp
    title: 2D sparse table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
  bundledCode: "#line 1 \"test/data_structure/sparse_table_2d.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\n\
    \n#line 2 \"data_structure/sparse_table_2d.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace ebi {\n\ntemplate <class S, S (*op)(S, S)> struct sparse_table_2d\
    \ {\n    sparse_table_2d(const std::vector<std::vector<S>> &table) {\n       \
    \ h = table.size();\n        w = h > 0 ? table[0].size() : 0;\n        lg_table.resize(std::max(h,\
    \ w) + 1);\n        lg_table[0] = lg_table[1] = 0;\n        for (int i = 2; i\
    \ <= std::max(h, w); i++)\n            lg_table[i] = lg_table[i >> 1] + 1;\n \
    \       lg_h = lg_table[h];\n        lg_w = lg_table[w];\n        st = std::vector(\n\
    \            lg_h + 1, std::vector(lg_w + 1, std::vector(h, std::vector<S>(w))));\n\
    \        for (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++)\
    \ {\n                st[0][0][i][j] = table[i][j];\n            }\n        }\n\
    \        for (int k = 0; (1 << k) <= h; k++) {\n            for (int l = 0; (1\
    \ << l) <= w; l++) {\n                if (k == 0 && l == 0) continue;\n      \
    \          for (int i = 0; i + (1 << k) <= h; i++) {\n                    for\
    \ (int j = 0; j + (1 << l) <= w; j++) {\n                        if (k > 0)\n\
    \                            st[k][l][i][j] =\n                              \
    \  op(st[k - 1][l][i][j],\n                                   st[k - 1][l][i +\
    \ (1 << (k - 1))][j]);\n                        else\n                       \
    \     st[k][l][i][j] =\n                                op(st[k][l - 1][i][j],\n\
    \                                   st[k][l - 1][i][j + (1 << (l - 1))]);\n  \
    \                  }\n                }\n            }\n        }\n    }\n\n \
    \   S prod(int l, int d, int r, int u) const {\n        assert(l < r && d < u);\n\
    \        int lg_lr = lg_table[r - l];\n        int lg_du = lg_table[u - d];\n\
    \        return op(\n            op(st[lg_lr][lg_du][l][d], st[lg_lr][lg_du][r\
    \ - (1 << lg_lr)][d]),\n            op(st[lg_lr][lg_du][l][u - (1 << lg_du)],\n\
    \               st[lg_lr][lg_du][r - (1 << lg_lr)][u - (1 << lg_du)]));\n    }\n\
    \n  private:\n    int h, w;\n    int lg_h, lg_w;\n    std::vector<int> lg_table;\n\
    \    std::vector<std::vector<std::vector<std::vector<S>>>> st;\n};\n\n}  // namespace\
    \ ebi\n#line 4 \"test/data_structure/sparse_table_2d.test.cpp\"\n\n#include <iostream>\n\
    #line 7 \"test/data_structure/sparse_table_2d.test.cpp\"\n\nint op(int a, int\
    \ b) {\n    return a < b ? a : b;\n}\n\nint main() {\n    int r, c, q;\n    while\
    \ (std::cin >> r >> c >> q, !(r == 0 && c == 0 && q == 0)) {\n        std::vector\
    \ grid(r, std::vector<int>(c));\n        for (int i = 0; i < r; i++) {\n     \
    \       for (int j = 0; j < c; j++) {\n                std::cin >> grid[i][j];\n\
    \            }\n        }\n        ebi::sparse_table_2d<int, op> st2d(grid);\n\
    \        while (q--) {\n            int l, d, r, u;\n            std::cin >> l\
    \ >> d >> r >> u;\n            r++;\n            u++;\n            std::cout <<\
    \ st2d.prod(l, d, r, u) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\
    \n\n#include \"../../data_structure/sparse_table_2d.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nint op(int a, int b) {\n    return a < b ? a : b;\n}\n\n\
    int main() {\n    int r, c, q;\n    while (std::cin >> r >> c >> q, !(r == 0 &&\
    \ c == 0 && q == 0)) {\n        std::vector grid(r, std::vector<int>(c));\n  \
    \      for (int i = 0; i < r; i++) {\n            for (int j = 0; j < c; j++)\
    \ {\n                std::cin >> grid[i][j];\n            }\n        }\n     \
    \   ebi::sparse_table_2d<int, op> st2d(grid);\n        while (q--) {\n       \
    \     int l, d, r, u;\n            std::cin >> l >> d >> r >> u;\n           \
    \ r++;\n            u++;\n            std::cout << st2d.prod(l, d, r, u) << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/sparse_table_2d.hpp
  isVerificationFile: true
  path: test/data_structure/sparse_table_2d.test.cpp
  requiredBy: []
  timestamp: '2023-06-27 01:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/sparse_table_2d.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/sparse_table_2d.test.cpp
- /verify/test/data_structure/sparse_table_2d.test.cpp.html
title: test/data_structure/sparse_table_2d.test.cpp
---
