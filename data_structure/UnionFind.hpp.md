---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/UnionFind.test.cpp
    title: test/UnionFind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/UnionFind.hpp\"\n\r\n#include <vector>\r\n\
    \r\nstruct UnionFind {\r\nprivate:\r\n    std::vector<int> par;\r\n\r\npublic:\r\
    \n    UnionFind(int n=0): par(n,-1){ }\r\n\r\n    bool same(int x,int y){\r\n\
    \        return leader(x)==leader(y);\r\n    }\r\n\r\n    bool merge(int x, int\
    \ y){\r\n        x = leader(x); y = leader(y);\r\n        if(x==y) return false;\r\
    \n        if(par[x]>par[y]) std::swap(x,y);\r\n        par[x]+=par[y];\r\n   \
    \     par[y] = x;\r\n        return true;\r\n    }\r\n\r\n    int leader(int x){\r\
    \n        if(par[x]<0) return x;\r\n        else return par[x] = leader(par[x]);\r\
    \n    }\r\n\r\n    int size(int x){\r\n        return -par[leader(x)];\r\n   \
    \ }\r\n\r\n    int count_group(){\r\n        int c = 0;\r\n        for(int i =\
    \ 0; i<par.size(); i++){\r\n            if(par[i]<0) c++; \r\n        }\r\n  \
    \      return c;\r\n    }\r\n};\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nstruct UnionFind {\r\nprivate:\r\
    \n    std::vector<int> par;\r\n\r\npublic:\r\n    UnionFind(int n=0): par(n,-1){\
    \ }\r\n\r\n    bool same(int x,int y){\r\n        return leader(x)==leader(y);\r\
    \n    }\r\n\r\n    bool merge(int x, int y){\r\n        x = leader(x); y = leader(y);\r\
    \n        if(x==y) return false;\r\n        if(par[x]>par[y]) std::swap(x,y);\r\
    \n        par[x]+=par[y];\r\n        par[y] = x;\r\n        return true;\r\n \
    \   }\r\n\r\n    int leader(int x){\r\n        if(par[x]<0) return x;\r\n    \
    \    else return par[x] = leader(par[x]);\r\n    }\r\n\r\n    int size(int x){\r\
    \n        return -par[leader(x)];\r\n    }\r\n\r\n    int count_group(){\r\n \
    \       int c = 0;\r\n        for(int i = 0; i<par.size(); i++){\r\n         \
    \   if(par[i]<0) c++; \r\n        }\r\n        return c;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/UnionFind.hpp
  requiredBy: []
  timestamp: '2021-01-05 00:58:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/UnionFind.test.cpp
documentation_of: data_structure/UnionFind.hpp
layout: document
redirect_from:
- /library/data_structure/UnionFind.hpp
- /library/data_structure/UnionFind.hpp.html
title: data_structure/UnionFind.hpp
---
