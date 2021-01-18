---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/LazySegtree.test.cpp
    title: test/LazySegtree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html
    - https://beet-aizu.hatenablog.com/entry/2017/12/01/225955
  bundledCode: "#line 2 \"data_structure/LazySegtree.hpp\"\n\r\n/*\r\n    reference:\
    \ https://beet-aizu.hatenablog.com/entry/2017/12/01/225955\r\n               https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<\r\n    class\
    \ S,\r\n    S (*op)(S, S),\r\n    S (*e)(),\r\n    class F,\r\n    S (*mapping)(F,\
    \ S),\r\n    F (*merge)(F, F),\r\n    F (*id)()>\r\nstruct LazySegtree {\r\nprivate:\r\
    \n    std::vector<S> data;\r\n    std::vector<F> lazy;\r\n    int n;\r\n\r\n \
    \   void eval(int index, int l, int r) {\r\n        data[index] = mapping(lazy[index],\
    \ data[index]);\r\n        if(r-l>1) {\r\n            lazy[2*index+1] = merge(lazy[index]\
    \ ,lazy[2*index+1]);\r\n            lazy[2*index+2] = merge(lazy[index] ,lazy[2*index+2]);\r\
    \n        }\r\n        lazy[index] = id();\r\n    }\r\n\r\npublic:\r\n    LazySegtree(int\
    \ _n) : n(1) {\r\n        while(n<_n) {\r\n            n <<= 1;\r\n        }\r\
    \n        data.assign(2*n-1, e());\r\n        lazy.assign(2*n-1, id());\r\n  \
    \  }\r\n\r\n    LazySegtree(std::vector<S> v) : n(1) {\r\n        int _n = v.size();\r\
    \n        while(n<_n) {\r\n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1,\
    \ e());\r\n        lazy.assign(2*n-1, id());\r\n        for(int i = 0; i<_n; i++)\
    \ {\r\n            data[i+n-1] = v[i];\r\n        }\r\n        for(int i = n-2;\
    \ i>=0; i--) {\r\n            data[i] = op(data[2*i+1], data[2*i+2]);\r\n    \
    \    }\r\n    }\r\n\r\n    S prod(int l, int r, int nl = 0, int nr = -1, int index\
    \ = 0) {\r\n        if(nr < 0) nr = n;\r\n        if(nr<=l || r<=nl) {\r\n   \
    \         return e();\r\n        }\r\n        eval(index, nl, nr);\r\n       \
    \ if(l<=nl && nr<=r) {\r\n            return data[index];\r\n        }\r\n   \
    \     return op(prod(l, r, nl, (nl+nr)/2, 2*index+1), prod(l, r, (nl+nr)/2, nr,\
    \ 2*index+2));\r\n    }\r\n\r\n    S all_prod() {\r\n        eval(0,0,n);\r\n\
    \        return data[0];\r\n    }\r\n\r\n    void apply(int l, int r, F f, int\
    \ nl = 0, int nr = -1, int index = 0) {\r\n        if(nr<0) nr = n;\r\n      \
    \  eval(index, nl, nr);\r\n        if(nr<=l || r<=nl) return;\r\n        if(l<=nl\
    \ && nr<=r) {\r\n            lazy[index] = merge(f, lazy[index]);\r\n        \
    \    eval(index, nl, nr);\r\n            return;\r\n        }\r\n        apply(l,\
    \ r, f, nl, (nl+nr)/2, 2*index+1);\r\n        apply(l, r, f, (nl+nr)/2, nr, 2*index+2);\r\
    \n        data[index] = op(data[2*index+1], data[2*index+2]);\r\n        return;\r\
    \n    }\r\n};\r\n\r\n} // namespace ebi\n"
  code: "#pragma once\r\n\r\n/*\r\n    reference: https://beet-aizu.hatenablog.com/entry/2017/12/01/225955\r\
    \n               https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<\r\n    class\
    \ S,\r\n    S (*op)(S, S),\r\n    S (*e)(),\r\n    class F,\r\n    S (*mapping)(F,\
    \ S),\r\n    F (*merge)(F, F),\r\n    F (*id)()>\r\nstruct LazySegtree {\r\nprivate:\r\
    \n    std::vector<S> data;\r\n    std::vector<F> lazy;\r\n    int n;\r\n\r\n \
    \   void eval(int index, int l, int r) {\r\n        data[index] = mapping(lazy[index],\
    \ data[index]);\r\n        if(r-l>1) {\r\n            lazy[2*index+1] = merge(lazy[index]\
    \ ,lazy[2*index+1]);\r\n            lazy[2*index+2] = merge(lazy[index] ,lazy[2*index+2]);\r\
    \n        }\r\n        lazy[index] = id();\r\n    }\r\n\r\npublic:\r\n    LazySegtree(int\
    \ _n) : n(1) {\r\n        while(n<_n) {\r\n            n <<= 1;\r\n        }\r\
    \n        data.assign(2*n-1, e());\r\n        lazy.assign(2*n-1, id());\r\n  \
    \  }\r\n\r\n    LazySegtree(std::vector<S> v) : n(1) {\r\n        int _n = v.size();\r\
    \n        while(n<_n) {\r\n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1,\
    \ e());\r\n        lazy.assign(2*n-1, id());\r\n        for(int i = 0; i<_n; i++)\
    \ {\r\n            data[i+n-1] = v[i];\r\n        }\r\n        for(int i = n-2;\
    \ i>=0; i--) {\r\n            data[i] = op(data[2*i+1], data[2*i+2]);\r\n    \
    \    }\r\n    }\r\n\r\n    S prod(int l, int r, int nl = 0, int nr = -1, int index\
    \ = 0) {\r\n        if(nr < 0) nr = n;\r\n        if(nr<=l || r<=nl) {\r\n   \
    \         return e();\r\n        }\r\n        eval(index, nl, nr);\r\n       \
    \ if(l<=nl && nr<=r) {\r\n            return data[index];\r\n        }\r\n   \
    \     return op(prod(l, r, nl, (nl+nr)/2, 2*index+1), prod(l, r, (nl+nr)/2, nr,\
    \ 2*index+2));\r\n    }\r\n\r\n    S all_prod() {\r\n        eval(0,0,n);\r\n\
    \        return data[0];\r\n    }\r\n\r\n    void apply(int l, int r, F f, int\
    \ nl = 0, int nr = -1, int index = 0) {\r\n        if(nr<0) nr = n;\r\n      \
    \  eval(index, nl, nr);\r\n        if(nr<=l || r<=nl) return;\r\n        if(l<=nl\
    \ && nr<=r) {\r\n            lazy[index] = merge(f, lazy[index]);\r\n        \
    \    eval(index, nl, nr);\r\n            return;\r\n        }\r\n        apply(l,\
    \ r, f, nl, (nl+nr)/2, 2*index+1);\r\n        apply(l, r, f, (nl+nr)/2, nr, 2*index+2);\r\
    \n        data[index] = op(data[2*index+1], data[2*index+2]);\r\n        return;\r\
    \n    }\r\n};\r\n\r\n} // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/LazySegtree.hpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/LazySegtree.test.cpp
documentation_of: data_structure/LazySegtree.hpp
layout: document
redirect_from:
- /library/data_structure/LazySegtree.hpp
- /library/data_structure/LazySegtree.hpp.html
title: data_structure/LazySegtree.hpp
---
