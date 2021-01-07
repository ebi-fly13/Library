---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/LiChaoSegmentTree.hpp
    title: data_structure/LiChaoSegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/LiChaoSegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
    \r\n\r\n#line 2 \"data_structure/LiChaoSegmentTree.hpp\"\n\r\n#include <algorithm>\r\
    \n#include <vector>\r\n#include <limits>\r\n\r\ntemplate<class T>\r\nstruct line\
    \ {\r\n    T a,b;\r\n    line(T a=0, T b=0) : a(a), b(b) { }\r\n};\r\n\r\ntemplate<class\
    \ T>\r\nstruct LiChaoSegmentTree {\r\nprivate:\r\n    std::vector<line<T>> data;\r\
    \n    std::vector<T> x;\r\n    int n;\r\n\r\n    T f(line<T> y, int i) {\r\n \
    \       return y.a*x[i]+y.b;\r\n    }\r\n\r\n    void swap(line<T> &a, line<T>\
    \ &b) {\r\n        line<T> c = a;\r\n        a = b;\r\n        b = c;\r\n    }\r\
    \n\r\npublic:\r\n    LiChaoSegmentTree(std::vector<T> _x) : n(1) {\r\n       \
    \ int _n = _x.size();\r\n        while(n<_n){\r\n            n <<= 1;\r\n    \
    \    }\r\n        x.assign(n, _x[_n-1]);\r\n        for(int i = 0; i<_n; i++){\r\
    \n            x[i] = _x[i];\r\n        }\r\n        T tmax = std::numeric_limits<T>::max();\r\
    \n        data.assign(2*n-1, line<T>(0, tmax));\r\n    }\r\n\r\n    void add_line(line<T>\
    \ y, int l = 0, int r = -1, int index = 0) {\r\n        if(r<0) r = n;\r\n   \
    \     int left = (f(y, l) < f(data[index], l));\r\n        int mid = (f(y, (l+r)/2)\
    \ < f(data[index], (l+r)/2));\r\n        int right = (f(y, r-1) < f(data[index],\
    \ r-1));\r\n        if(left && right) {\r\n            data[index] = y;\r\n  \
    \          return;\r\n        }\r\n        if(!(left || right)){\r\n         \
    \   return;\r\n        }\r\n        if(mid) {\r\n            swap(y, data[index]);\r\
    \n            left = !left;\r\n            right = !right;\r\n        }\r\n  \
    \      if(left) {\r\n            add_line(y, l, (l+r)/2, 2*index+1);\r\n     \
    \   }\r\n        else {\r\n            add_line(y, (l+r)/2, r, 2*index+2);\r\n\
    \        }\r\n    }\r\n\r\n    T get(int i) {\r\n        int k = i+n-1;\r\n  \
    \      T val = f(data[k], i);\r\n        while(k>0){\r\n            k = (k-1)/2;\r\
    \n            val = std::min(val, f(data[k], i));\r\n        }\r\n        return\
    \ val;\r\n    }\r\n};\n#line 2 \"utility/int_alias.hpp\"\n\r\n#include <cstddef>\r\
    \n#include <cstdint>\r\n\r\nusing i32 = std::int32_t;\r\nusing i64 = std::int64_t;\r\
    \nusing u32 = std::uint32_t;\r\nusing u64 = std::uint64_t;\r\nusing usize = std::size_t;\n\
    #line 5 \"test/LiChaoSegmentTree.test.cpp\"\n\r\n#include <iostream>\r\n\r\nint\
    \ main(){\r\n    int n,q; std::cin >> n >> q;\r\n    std::vector<line<i64>> p(n);\r\
    \n    for(int i = 0; i<n; i++) {\r\n        std::cin >> p[i].a >> p[i].b;\r\n\
    \    }\r\n    std::vector<i64> x;\r\n    std::vector<std::vector<i64>> query(q);\r\
    \n    for(int i = 0; i<q; i++) {\r\n        int t; std::cin >> t;\r\n        query[i].emplace_back(t);\r\
    \n        if(t==0) {\r\n            i64 a,b; std::cin >> a >> b;\r\n         \
    \   query[i].emplace_back(a);\r\n            query[i].emplace_back(b);\r\n   \
    \     }\r\n        else {\r\n            i64 p; std::cin >> p;\r\n           \
    \ query[i].emplace_back(p);\r\n            x.emplace_back(p);\r\n        }\r\n\
    \    }\r\n    std::sort(x.begin(), x.end());\r\n    x.erase(unique(x.begin(),\
    \ x.end()), x.end());\r\n    LiChaoSegmentTree<i64> seg(x);\r\n    for(auto y:\
    \ p) {\r\n        seg.add_line(y);\r\n    }\r\n    for(int i = 0; i<q; i++) {\r\
    \n        if(query[i][0]==0){\r\n            line<i64> y(query[i][1], query[i][2]);\r\
    \n            seg.add_line(y);\r\n        }\r\n        else{\r\n            int\
    \ index = std::lower_bound(x.begin(), x.end(), query[i][1])-x.begin();\r\n   \
    \         std::cout << seg.get(index) << std::endl;\r\n        }\r\n    }\r\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\
    \n#include \"../data_structure/LiChaoSegmentTree.hpp\"\r\n#include \"../utility/int_alias.hpp\"\
    \r\n\r\n#include <iostream>\r\n\r\nint main(){\r\n    int n,q; std::cin >> n >>\
    \ q;\r\n    std::vector<line<i64>> p(n);\r\n    for(int i = 0; i<n; i++) {\r\n\
    \        std::cin >> p[i].a >> p[i].b;\r\n    }\r\n    std::vector<i64> x;\r\n\
    \    std::vector<std::vector<i64>> query(q);\r\n    for(int i = 0; i<q; i++) {\r\
    \n        int t; std::cin >> t;\r\n        query[i].emplace_back(t);\r\n     \
    \   if(t==0) {\r\n            i64 a,b; std::cin >> a >> b;\r\n            query[i].emplace_back(a);\r\
    \n            query[i].emplace_back(b);\r\n        }\r\n        else {\r\n   \
    \         i64 p; std::cin >> p;\r\n            query[i].emplace_back(p);\r\n \
    \           x.emplace_back(p);\r\n        }\r\n    }\r\n    std::sort(x.begin(),\
    \ x.end());\r\n    x.erase(unique(x.begin(), x.end()), x.end());\r\n    LiChaoSegmentTree<i64>\
    \ seg(x);\r\n    for(auto y: p) {\r\n        seg.add_line(y);\r\n    }\r\n   \
    \ for(int i = 0; i<q; i++) {\r\n        if(query[i][0]==0){\r\n            line<i64>\
    \ y(query[i][1], query[i][2]);\r\n            seg.add_line(y);\r\n        }\r\n\
    \        else{\r\n            int index = std::lower_bound(x.begin(), x.end(),\
    \ query[i][1])-x.begin();\r\n            std::cout << seg.get(index) << std::endl;\r\
    \n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/LiChaoSegmentTree.hpp
  - utility/int_alias.hpp
  isVerificationFile: true
  path: test/LiChaoSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2021-01-08 01:25:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LiChaoSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/LiChaoSegmentTree.test.cpp
- /verify/test/LiChaoSegmentTree.test.cpp.html
title: test/LiChaoSegmentTree.test.cpp
---
