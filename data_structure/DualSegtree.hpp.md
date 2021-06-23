---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DualSegtree.test.cpp
    title: test/DualSegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/DualSegtree.hpp\"\n\r\n#include <vector>\r\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid),\
    \ Monoid (*e)()>\r\nstruct DualSegtree {\r\nprivate:\r\n    std::vector<Monoid>\
    \ data;\r\n    int n;\r\npublic:\r\n    DualSegtree(int _n) : n(1) {\r\n     \
    \   while(n<_n){\r\n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1,\
    \ e());\r\n    }\r\n\r\n    DualSegtree(std::vector<Monoid> v) : n(1) {\r\n  \
    \      int _n = v.size();\r\n        while(n<_n){\r\n            n <<= 1;\r\n\
    \        }\r\n        data.assign(2*n-1, e());\r\n        for(int i = 0; i<_n;\
    \ i++){\r\n            data[i+n-1] = v[i];\r\n        }\r\n    }\r\n\r\n    Monoid\
    \ get(int p) {\r\n        int k = p+n-1;\r\n        Monoid val = data[k];\r\n\
    \        while(k>0){\r\n            k = (k-1)/2;\r\n            val = op(val,\
    \ data[k]);\r\n        }\r\n        return val;\r\n    }\r\n\r\n    void apply(int\
    \ tl, int tr, Monoid x,int l = 0, int r = -1, int index = 0) {\r\n        if(r<0)\
    \ r = n;\r\n        if(tr<=l || r<=tl) {\r\n            return;\r\n        }\r\
    \n        if(tl<=l && r<=tr) {\r\n            data[index] = op(data[index], x);\r\
    \n            return;\r\n        }\r\n        apply(tl, tr, x, l, (l+r)/2, 2*index+1);\r\
    \n        apply(tl, tr, x,(l+r)/2, r, 2*index+2);\r\n        return;\r\n    }\r\
    \n};\r\n\r\n} // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class\
    \ Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct DualSegtree {\r\
    \nprivate:\r\n    std::vector<Monoid> data;\r\n    int n;\r\npublic:\r\n    DualSegtree(int\
    \ _n) : n(1) {\r\n        while(n<_n){\r\n            n <<= 1;\r\n        }\r\n\
    \        data.assign(2*n-1, e());\r\n    }\r\n\r\n    DualSegtree(std::vector<Monoid>\
    \ v) : n(1) {\r\n        int _n = v.size();\r\n        while(n<_n){\r\n      \
    \      n <<= 1;\r\n        }\r\n        data.assign(2*n-1, e());\r\n        for(int\
    \ i = 0; i<_n; i++){\r\n            data[i+n-1] = v[i];\r\n        }\r\n    }\r\
    \n\r\n    Monoid get(int p) {\r\n        int k = p+n-1;\r\n        Monoid val\
    \ = data[k];\r\n        while(k>0){\r\n            k = (k-1)/2;\r\n          \
    \  val = op(val, data[k]);\r\n        }\r\n        return val;\r\n    }\r\n\r\n\
    \    void apply(int tl, int tr, Monoid x,int l = 0, int r = -1, int index = 0)\
    \ {\r\n        if(r<0) r = n;\r\n        if(tr<=l || r<=tl) {\r\n            return;\r\
    \n        }\r\n        if(tl<=l && r<=tr) {\r\n            data[index] = op(data[index],\
    \ x);\r\n            return;\r\n        }\r\n        apply(tl, tr, x, l, (l+r)/2,\
    \ 2*index+1);\r\n        apply(tl, tr, x,(l+r)/2, r, 2*index+2);\r\n        return;\r\
    \n    }\r\n};\r\n\r\n} // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/DualSegtree.hpp
  requiredBy: []
  timestamp: '2021-06-23 13:29:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DualSegtree.test.cpp
documentation_of: data_structure/DualSegtree.hpp
layout: document
redirect_from:
- /library/data_structure/DualSegtree.hpp
- /library/data_structure/DualSegtree.hpp.html
title: data_structure/DualSegtree.hpp
---
