---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Segtree.test.cpp
    title: test/Segtree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/Segtree.hpp\"\n\r\n#include <vector>\r\n\r\
    \ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct\
    \ Segtree {\r\nprivate:\r\n    std::vector<Monoid> data;\r\n    int n;\r\npublic:\r\
    \n    Segtree(int _n) : n(1) {\r\n        while(n<_n){\r\n            n <<= 1;\r\
    \n        }\r\n        data.assign(2*n-1, e());\r\n    }\r\n\r\n    Segtree(std::vector<Monoid>\
    \ v) : n(1) {\r\n        int _n = v.size();\r\n        while(n<_n){\r\n      \
    \      n <<= 1;\r\n        }\r\n        data.assign(2*n-1, e());\r\n        for(int\
    \ i = 0; i<_n; i++){\r\n            data[n+i-1] = v[i];\r\n        }\r\n     \
    \   for(int i = n-2; i>=0; i--){\r\n            data[i] = op(data[2*i+1], data[2*i+2]);\r\
    \n        }\r\n    }\r\n\r\n    void set(int p, Monoid x){\r\n        int k =\
    \ n+p-1;\r\n        data[k] = x;\r\n        while(k>0){\r\n            k = (k-1)/2;\r\
    \n            data[k] = op(data[2*k+1], data[2*k+2]);\r\n        }\r\n    }\r\n\
    \r\n    Monoid prod(int tl, int tr, int l=0, int r=-1, int index=0){\r\n     \
    \   if(r<0) r = n;\r\n        if(tr<=l || r<=tl){\r\n            return e();\r\
    \n        }\r\n        if(tl<=l && r<=tr){\r\n            return data[index];\r\
    \n        }\r\n        return op(prod(tl, tr, l, (l+r)/2, 2*index+1), prod(tl,\
    \ tr, (l+r)/2, r, 2*index+2));\r\n    }\r\n\r\n    Monoid all_prod() { return\
    \ data[0]; }\r\n\r\n    Monoid operator [] (int p) { return data[n+p-1]; }\r\n\
    };\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\ntemplate<class Monoid, Monoid\
    \ (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct Segtree {\r\nprivate:\r\n  \
    \  std::vector<Monoid> data;\r\n    int n;\r\npublic:\r\n    Segtree(int _n) :\
    \ n(1) {\r\n        while(n<_n){\r\n            n <<= 1;\r\n        }\r\n    \
    \    data.assign(2*n-1, e());\r\n    }\r\n\r\n    Segtree(std::vector<Monoid>\
    \ v) : n(1) {\r\n        int _n = v.size();\r\n        while(n<_n){\r\n      \
    \      n <<= 1;\r\n        }\r\n        data.assign(2*n-1, e());\r\n        for(int\
    \ i = 0; i<_n; i++){\r\n            data[n+i-1] = v[i];\r\n        }\r\n     \
    \   for(int i = n-2; i>=0; i--){\r\n            data[i] = op(data[2*i+1], data[2*i+2]);\r\
    \n        }\r\n    }\r\n\r\n    void set(int p, Monoid x){\r\n        int k =\
    \ n+p-1;\r\n        data[k] = x;\r\n        while(k>0){\r\n            k = (k-1)/2;\r\
    \n            data[k] = op(data[2*k+1], data[2*k+2]);\r\n        }\r\n    }\r\n\
    \r\n    Monoid prod(int tl, int tr, int l=0, int r=-1, int index=0){\r\n     \
    \   if(r<0) r = n;\r\n        if(tr<=l || r<=tl){\r\n            return e();\r\
    \n        }\r\n        if(tl<=l && r<=tr){\r\n            return data[index];\r\
    \n        }\r\n        return op(prod(tl, tr, l, (l+r)/2, 2*index+1), prod(tl,\
    \ tr, (l+r)/2, r, 2*index+2));\r\n    }\r\n\r\n    Monoid all_prod() { return\
    \ data[0]; }\r\n\r\n    Monoid operator [] (int p) { return data[n+p-1]; }\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Segtree.hpp
  requiredBy: []
  timestamp: '2021-01-05 22:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Segtree.test.cpp
documentation_of: data_structure/Segtree.hpp
layout: document
redirect_from:
- /library/data_structure/Segtree.hpp
- /library/data_structure/Segtree.hpp.html
title: data_structure/Segtree.hpp
---
