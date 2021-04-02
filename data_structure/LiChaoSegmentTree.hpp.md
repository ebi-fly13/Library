---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LiChaoSegmentTree.test.cpp
    title: test/LiChaoSegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SegmentAddGetMin.test.cpp
    title: test/SegmentAddGetMin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/LiChaoSegmentTree.hpp\"\n\r\n#include <algorithm>\r\
    \n#include <vector>\r\n#include <limits>\r\n#include <cassert>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<class T>\r\nstruct line {\r\n    T a,b;\r\n    line(T\
    \ a=0, T b=0) : a(a), b(b) { }\r\n};\r\n\r\ntemplate<class T>\r\nstruct LiChaoSegmentTree\
    \ {\r\nprivate:\r\n    std::vector<line<T>> data;\r\n    std::vector<T> x;\r\n\
    \    int n;\r\n\r\n    T f(line<T> y, int i) {\r\n        return y.a*x[i]+y.b;\r\
    \n    }\r\n\r\n    void swap(line<T> &a, line<T> &b) {\r\n        line<T> c =\
    \ a;\r\n        a = b;\r\n        b = c;\r\n    }\r\n\r\npublic:\r\n    LiChaoSegmentTree(std::vector<T>\
    \ _x) : n(1) {\r\n        int _n = _x.size();\r\n        while(n<_n){\r\n    \
    \        n <<= 1;\r\n        }\r\n        x.assign(n, _x[_n-1]);\r\n        for(int\
    \ i = 0; i<_n; i++){\r\n            x[i] = _x[i];\r\n        }\r\n        T tmax\
    \ = std::numeric_limits<T>::max();\r\n        data.assign(2*n-1, line<T>(0, tmax));\r\
    \n    }\r\n\r\n    void add_line(line<T> y, int l = 0, int r = -1, int index =\
    \ 0) {\r\n        if(r<0) r = n;\r\n        bool left = (f(y, l) < f(data[index],\
    \ l));\r\n        bool mid = (f(y, (l+r)/2) < f(data[index], (l+r)/2));\r\n  \
    \      bool right = (f(y, r-1) < f(data[index], r-1));\r\n        if(left && right)\
    \ {\r\n            data[index] = y;\r\n            return;\r\n        }\r\n  \
    \      if(!(left || right)){\r\n            return;\r\n        }\r\n        if(mid)\
    \ {\r\n            swap(y, data[index]);\r\n            left = !left;\r\n    \
    \        right = !right;\r\n        }\r\n        if(left) {\r\n            add_line(y,\
    \ l, (l+r)/2, 2*index+1);\r\n        }\r\n        else {\r\n            add_line(y,\
    \ (l+r)/2, r, 2*index+2);\r\n        }\r\n    }\r\n\r\n    void add_segment(line<T>\
    \ y, int lx, int rx, int l = 0, int r = -1, int index = 0) {\r\n        assert(lx<=rx);\r\
    \n        assert(0<=lx);\r\n        assert(rx<=n);\r\n        if(r<0) r = n;\r\
    \n        if(r<= lx || rx<= l) {\r\n            return;\r\n        }\r\n     \
    \   if(lx <= l && r <= rx) {\r\n            add_line(y, l, r, index);\r\n    \
    \        return;\r\n        }\r\n        add_segment(y, lx, rx, l, (l+r)/2, 2*index+1);\r\
    \n        add_segment(y, lx, rx, (l+r)/2, r, 2*index+2);\r\n    }\r\n\r\n    T\
    \ get(int i) {\r\n        int k = i+n-1;\r\n        T val = f(data[k], i);\r\n\
    \        while(k>0){\r\n            k = (k-1)/2;\r\n            val = std::min(val,\
    \ f(data[k], i));\r\n        }\r\n        return val;\r\n    }\r\n};\r\n\r\n}\
    \ // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <vector>\r\n#include\
    \ <limits>\r\n#include <cassert>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class\
    \ T>\r\nstruct line {\r\n    T a,b;\r\n    line(T a=0, T b=0) : a(a), b(b) { }\r\
    \n};\r\n\r\ntemplate<class T>\r\nstruct LiChaoSegmentTree {\r\nprivate:\r\n  \
    \  std::vector<line<T>> data;\r\n    std::vector<T> x;\r\n    int n;\r\n\r\n \
    \   T f(line<T> y, int i) {\r\n        return y.a*x[i]+y.b;\r\n    }\r\n\r\n \
    \   void swap(line<T> &a, line<T> &b) {\r\n        line<T> c = a;\r\n        a\
    \ = b;\r\n        b = c;\r\n    }\r\n\r\npublic:\r\n    LiChaoSegmentTree(std::vector<T>\
    \ _x) : n(1) {\r\n        int _n = _x.size();\r\n        while(n<_n){\r\n    \
    \        n <<= 1;\r\n        }\r\n        x.assign(n, _x[_n-1]);\r\n        for(int\
    \ i = 0; i<_n; i++){\r\n            x[i] = _x[i];\r\n        }\r\n        T tmax\
    \ = std::numeric_limits<T>::max();\r\n        data.assign(2*n-1, line<T>(0, tmax));\r\
    \n    }\r\n\r\n    void add_line(line<T> y, int l = 0, int r = -1, int index =\
    \ 0) {\r\n        if(r<0) r = n;\r\n        bool left = (f(y, l) < f(data[index],\
    \ l));\r\n        bool mid = (f(y, (l+r)/2) < f(data[index], (l+r)/2));\r\n  \
    \      bool right = (f(y, r-1) < f(data[index], r-1));\r\n        if(left && right)\
    \ {\r\n            data[index] = y;\r\n            return;\r\n        }\r\n  \
    \      if(!(left || right)){\r\n            return;\r\n        }\r\n        if(mid)\
    \ {\r\n            swap(y, data[index]);\r\n            left = !left;\r\n    \
    \        right = !right;\r\n        }\r\n        if(left) {\r\n            add_line(y,\
    \ l, (l+r)/2, 2*index+1);\r\n        }\r\n        else {\r\n            add_line(y,\
    \ (l+r)/2, r, 2*index+2);\r\n        }\r\n    }\r\n\r\n    void add_segment(line<T>\
    \ y, int lx, int rx, int l = 0, int r = -1, int index = 0) {\r\n        assert(lx<=rx);\r\
    \n        assert(0<=lx);\r\n        assert(rx<=n);\r\n        if(r<0) r = n;\r\
    \n        if(r<= lx || rx<= l) {\r\n            return;\r\n        }\r\n     \
    \   if(lx <= l && r <= rx) {\r\n            add_line(y, l, r, index);\r\n    \
    \        return;\r\n        }\r\n        add_segment(y, lx, rx, l, (l+r)/2, 2*index+1);\r\
    \n        add_segment(y, lx, rx, (l+r)/2, r, 2*index+2);\r\n    }\r\n\r\n    T\
    \ get(int i) {\r\n        int k = i+n-1;\r\n        T val = f(data[k], i);\r\n\
    \        while(k>0){\r\n            k = (k-1)/2;\r\n            val = std::min(val,\
    \ f(data[k], i));\r\n        }\r\n        return val;\r\n    }\r\n};\r\n\r\n}\
    \ // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/LiChaoSegmentTree.hpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SegmentAddGetMin.test.cpp
  - test/LiChaoSegmentTree.test.cpp
documentation_of: data_structure/LiChaoSegmentTree.hpp
layout: document
redirect_from:
- /library/data_structure/LiChaoSegmentTree.hpp
- /library/data_structure/LiChaoSegmentTree.hpp.html
title: data_structure/LiChaoSegmentTree.hpp
---
