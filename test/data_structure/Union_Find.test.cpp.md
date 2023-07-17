---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/UnionFind.hpp
    title: data_structure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/data_structure/Union_Find.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include <iostream>\r\n\
    \r\n#line 2 \"data_structure/UnionFind.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nstruct UnionFind {\r\n  private:\r\n    std::vector<int> par;\r\
    \n\r\n  public:\r\n    UnionFind(int n = 0) : par(n, -1) {}\r\n\r\n    bool same(int\
    \ x, int y) {\r\n        return leader(x) == leader(y);\r\n    }\r\n\r\n    bool\
    \ merge(int x, int y) {\r\n        x = leader(x);\r\n        y = leader(y);\r\n\
    \        if (x == y) return false;\r\n        if (par[x] > par[y]) std::swap(x,\
    \ y);\r\n        par[x] += par[y];\r\n        par[y] = x;\r\n        return true;\r\
    \n    }\r\n\r\n    int leader(int x) {\r\n        if (par[x] < 0)\r\n        \
    \    return x;\r\n        else\r\n            return par[x] = leader(par[x]);\r\
    \n    }\r\n\r\n    int size(int x) {\r\n        return -par[leader(x)];\r\n  \
    \  }\r\n\r\n    int count_group() {\r\n        int c = 0;\r\n        for (int\
    \ i = 0; i < int(par.size()); i++) {\r\n            if (par[i] < 0) c++;\r\n \
    \       }\r\n        return c;\r\n    }\r\n\r\n    void clear() {\r\n        for\
    \ (int i = 0; i < int(par.size()); i++) {\r\n            par[i] = -1;\r\n    \
    \    }\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n#line 6 \"test/data_structure/Union_Find.test.cpp\"\
    \n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    ebi::UnionFind\
    \ uf(n);\r\n    while (q--) {\r\n        int t, u, v;\r\n        std::cin >> t\
    \ >> u >> v;\r\n        if (t == 0) {\r\n            uf.merge(u, v);\r\n     \
    \   } else {\r\n            if (uf.same(u, v)) {\r\n                std::cout\
    \ << \"1\\n\";\r\n            } else {\r\n                std::cout << \"0\\n\"\
    ;\r\n            }\r\n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"../../data_structure/UnionFind.hpp\"\r\n\r\nint\
    \ main() {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    ebi::UnionFind uf(n);\r\
    \n    while (q--) {\r\n        int t, u, v;\r\n        std::cin >> t >> u >> v;\r\
    \n        if (t == 0) {\r\n            uf.merge(u, v);\r\n        } else {\r\n\
    \            if (uf.same(u, v)) {\r\n                std::cout << \"1\\n\";\r\n\
    \            } else {\r\n                std::cout << \"0\\n\";\r\n          \
    \  }\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - data_structure/UnionFind.hpp
  isVerificationFile: true
  path: test/data_structure/Union_Find.test.cpp
  requiredBy: []
  timestamp: '2023-07-17 14:12:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Union_Find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Union_Find.test.cpp
- /verify/test/data_structure/Union_Find.test.cpp.html
title: test/data_structure/Union_Find.test.cpp
---
