---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/UnionFind.hpp
    title: data_structure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \r\n\r\n#line 2 \"data_structure/UnionFind.hpp\"\n\r\n#include <vector>\r\n\r\n\
    namespace ebi {\r\n\r\nstruct UnionFind {\r\nprivate:\r\n    std::vector<int>\
    \ par;\r\n\r\npublic:\r\n    UnionFind(int n=0): par(n,-1){ }\r\n\r\n    bool\
    \ same(int x,int y){\r\n        return leader(x)==leader(y);\r\n    }\r\n\r\n\
    \    bool merge(int x, int y){\r\n        x = leader(x); y = leader(y);\r\n  \
    \      if(x==y) return false;\r\n        if(par[x]>par[y]) std::swap(x,y);\r\n\
    \        par[x]+=par[y];\r\n        par[y] = x;\r\n        return true;\r\n  \
    \  }\r\n\r\n    int leader(int x){\r\n        if(par[x]<0) return x;\r\n     \
    \   else return par[x] = leader(par[x]);\r\n    }\r\n\r\n    int size(int x){\r\
    \n        return -par[leader(x)];\r\n    }\r\n\r\n    int count_group(){\r\n \
    \       int c = 0;\r\n        for(int i = 0; i<int(par.size()); i++){\r\n    \
    \        if(par[i]<0) c++; \r\n        }\r\n        return c;\r\n    }\r\n\r\n\
    \    void clear() {\r\n        for(int i = 0; i < int(par.size()); i++) {\r\n\
    \            par[i] = -1;\r\n        }\r\n    }\r\n};\r\n\r\n} // namespace ebi\n\
    #line 4 \"test/UnionFind.test.cpp\"\n\r\n#include <iostream>\r\n\r\nint main()\
    \ {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    ebi::UnionFind uf(n);\r\
    \n    while (q--) {\r\n        int t, u, v;\r\n        std::cin >> t >> u >> v;\r\
    \n        if (t == 0) {\r\n            uf.merge(u, v);\r\n        } else {\r\n\
    \            if (uf.same(u, v)) {\r\n                std::cout << \"1\\n\";\r\n\
    \            } else {\r\n                std::cout << \"0\\n\";\r\n          \
    \  }\r\n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ \"../data_structure/UnionFind.hpp\"\r\n\r\n#include <iostream>\r\n\r\nint main()\
    \ {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    ebi::UnionFind uf(n);\r\
    \n    while (q--) {\r\n        int t, u, v;\r\n        std::cin >> t >> u >> v;\r\
    \n        if (t == 0) {\r\n            uf.merge(u, v);\r\n        } else {\r\n\
    \            if (uf.same(u, v)) {\r\n                std::cout << \"1\\n\";\r\n\
    \            } else {\r\n                std::cout << \"0\\n\";\r\n          \
    \  }\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - data_structure/UnionFind.hpp
  isVerificationFile: true
  path: test/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 05:33:08+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/UnionFind.test.cpp
- /verify/test/UnionFind.test.cpp.html
title: test/UnionFind.test.cpp
---
