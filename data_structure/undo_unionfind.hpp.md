---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_1645.test.cpp
    title: test/aoj/aoj_1645.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/undo_unionfind.hpp\"\n\n#include <vector>\n\
    #include <stack>\n#include <cassert>\n\nnamespace ebi {\n\nstruct undo_unionfind\
    \ {\nprivate:\n    std::stack< std::pair<int,int> > stack;\npublic:\n    std::vector<int>\
    \ par;\n\n    undo_unionfind(int n = 0) : par(n, -1) { }\n\n    bool same(int\
    \ x,int y){\n        return leader(x)==leader(y);\n    }\n\n    bool merge(int\
    \ x, int y){\n        x = leader(x); y = leader(y);\n        stack.push({x, par[x]});\n\
    \        stack.push({y, par[y]});\n        if(x==y) return false;\n        if(par[x]>par[y])\
    \ std::swap(x,y);\n        par[x]+=par[y];\n        par[y] = x;\n        return\
    \ true;\n    }\n\n    int leader(int x){\n        if(par[x]<0) return x;\n   \
    \     else return leader(par[x]);\n    }\n\n    int size(int x){\n        return\
    \ -par[leader(x)];\n    }\n\n    int count_group(){\n        int c = 0;\n    \
    \    for(int i = 0; i<int(par.size()); i++){\n            if(par[i]<0) c++; \n\
    \        }\n        return c;\n    }\n\n    void undo() {\n        assert(!stack.empty());\n\
    \        par[stack.top().first] = stack.top().second;\n        stack.pop();\n\
    \        par[stack.top().first] = stack.top().second;\n        stack.pop();\n\
    \        return;\n    }\n};\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <stack>\n#include <cassert>\n\
    \nnamespace ebi {\n\nstruct undo_unionfind {\nprivate:\n    std::stack< std::pair<int,int>\
    \ > stack;\npublic:\n    std::vector<int> par;\n\n    undo_unionfind(int n = 0)\
    \ : par(n, -1) { }\n\n    bool same(int x,int y){\n        return leader(x)==leader(y);\n\
    \    }\n\n    bool merge(int x, int y){\n        x = leader(x); y = leader(y);\n\
    \        stack.push({x, par[x]});\n        stack.push({y, par[y]});\n        if(x==y)\
    \ return false;\n        if(par[x]>par[y]) std::swap(x,y);\n        par[x]+=par[y];\n\
    \        par[y] = x;\n        return true;\n    }\n\n    int leader(int x){\n\
    \        if(par[x]<0) return x;\n        else return leader(par[x]);\n    }\n\n\
    \    int size(int x){\n        return -par[leader(x)];\n    }\n\n    int count_group(){\n\
    \        int c = 0;\n        for(int i = 0; i<int(par.size()); i++){\n       \
    \     if(par[i]<0) c++; \n        }\n        return c;\n    }\n\n    void undo()\
    \ {\n        assert(!stack.empty());\n        par[stack.top().first] = stack.top().second;\n\
    \        stack.pop();\n        par[stack.top().first] = stack.top().second;\n\
    \        stack.pop();\n        return;\n    }\n};\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/undo_unionfind.hpp
  requiredBy: []
  timestamp: '2021-10-16 12:06:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_1645.test.cpp
documentation_of: data_structure/undo_unionfind.hpp
layout: document
redirect_from:
- /library/data_structure/undo_unionfind.hpp
- /library/data_structure/undo_unionfind.hpp.html
title: data_structure/undo_unionfind.hpp
---
