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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/SegmentAddGetMin.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \r\n\r\n#line 2 \"data_structure/LiChaoSegmentTree.hpp\"\n\r\n#include <algorithm>\r\
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
    \ // namespace ebi\n#line 2 \"utility/int_alias.hpp\"\n\r\n#include <cstddef>\r\
    \n#include <cstdint>\r\n\r\nusing i32 = std::int32_t;\r\nusing i64 = std::int64_t;\r\
    \nusing u16 = std::uint16_t;\r\nusing u32 = std::uint32_t;\r\nusing u64 = std::uint64_t;\r\
    \nusing usize = std::size_t;\n#line 5 \"test/SegmentAddGetMin.test.cpp\"\n\r\n\
    #include <iostream>\r\n#line 9 \"test/SegmentAddGetMin.test.cpp\"\n\r\nint main(){\r\
    \n    int n,q; std::cin >> n >> q;\r\n    std::vector<std::pair<i64, i64>> lr(n);\r\
    \n    std::vector<ebi::line<i64>> y(n);\r\n    std::vector<i64> x;\r\n    for(int\
    \ i = 0; i<n; i++){\r\n        std::cin >> lr[i].first >> lr[i].second;\r\n  \
    \      std::cin >> y[i].a >> y[i].b;\r\n    }\r\n    std::vector<std::vector<i64>>\
    \ query(q);\r\n    for(int i = 0; i<q; i++) {\r\n        i64 t; std::cin >> t;\r\
    \n        query[i].emplace_back(t);\r\n        if(t==0) {\r\n            i64 l,r,a,b;\
    \ std::cin >> l >> r >> a >> b;\r\n            query[i].emplace_back(l);\r\n \
    \           query[i].emplace_back(r);\r\n            query[i].emplace_back(a);\r\
    \n            query[i].emplace_back(b);\r\n        }\r\n        else {\r\n   \
    \         i64 p; std::cin >> p;\r\n            query[i].emplace_back(p);\r\n \
    \           x.emplace_back(p);\r\n        }\r\n    }\r\n    if(x.size()==0) return\
    \ 0;\r\n    std::sort(x.begin(), x.end());\r\n    x.erase(unique(x.begin(), x.end()),\
    \ x.end());\r\n    x.emplace_back(1e9+10);\r\n    ebi::LiChaoSegmentTree<i64>\
    \ seg(x);\r\n    for(int i = 0; i<n; i++) {\r\n        int l = std::lower_bound(x.begin(),\
    \ x.end(), lr[i].first) - x.begin();\r\n        int r = std::lower_bound(x.begin(),\
    \ x.end(), lr[i].second) - x.begin();\r\n        seg.add_segment(y[i], l, r);\r\
    \n    }\r\n    for(int i = 0; i<q; i++) {\r\n        if(query[i][0]==0) {\r\n\
    \            int l = std::lower_bound(x.begin(), x.end(), query[i][1]) - x.begin();\r\
    \n            int r = std::lower_bound(x.begin(), x.end(), query[i][2]) - x.begin();\r\
    \n            ebi::line<i64> ya(query[i][3], query[i][4]);\r\n            seg.add_segment(ya,\
    \ l, r);\r\n        }\r\n        else {\r\n            int index = std::lower_bound(x.begin(),\
    \ x.end(), query[i][1]) - x.begin();\r\n            i64 ret = seg.get(index);\r\
    \n            if(ret == std::numeric_limits<i64>::max()) {\r\n               \
    \ std::cout << \"INFINITY\" << std::endl;\r\n            }\r\n            else{\r\
    \n                std::cout << ret << std::endl;\r\n            }\r\n        }\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\r\
    \n\r\n#include \"../data_structure/LiChaoSegmentTree.hpp\"\r\n#include \"../utility/int_alias.hpp\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n\r\
    \nint main(){\r\n    int n,q; std::cin >> n >> q;\r\n    std::vector<std::pair<i64,\
    \ i64>> lr(n);\r\n    std::vector<ebi::line<i64>> y(n);\r\n    std::vector<i64>\
    \ x;\r\n    for(int i = 0; i<n; i++){\r\n        std::cin >> lr[i].first >> lr[i].second;\r\
    \n        std::cin >> y[i].a >> y[i].b;\r\n    }\r\n    std::vector<std::vector<i64>>\
    \ query(q);\r\n    for(int i = 0; i<q; i++) {\r\n        i64 t; std::cin >> t;\r\
    \n        query[i].emplace_back(t);\r\n        if(t==0) {\r\n            i64 l,r,a,b;\
    \ std::cin >> l >> r >> a >> b;\r\n            query[i].emplace_back(l);\r\n \
    \           query[i].emplace_back(r);\r\n            query[i].emplace_back(a);\r\
    \n            query[i].emplace_back(b);\r\n        }\r\n        else {\r\n   \
    \         i64 p; std::cin >> p;\r\n            query[i].emplace_back(p);\r\n \
    \           x.emplace_back(p);\r\n        }\r\n    }\r\n    if(x.size()==0) return\
    \ 0;\r\n    std::sort(x.begin(), x.end());\r\n    x.erase(unique(x.begin(), x.end()),\
    \ x.end());\r\n    x.emplace_back(1e9+10);\r\n    ebi::LiChaoSegmentTree<i64>\
    \ seg(x);\r\n    for(int i = 0; i<n; i++) {\r\n        int l = std::lower_bound(x.begin(),\
    \ x.end(), lr[i].first) - x.begin();\r\n        int r = std::lower_bound(x.begin(),\
    \ x.end(), lr[i].second) - x.begin();\r\n        seg.add_segment(y[i], l, r);\r\
    \n    }\r\n    for(int i = 0; i<q; i++) {\r\n        if(query[i][0]==0) {\r\n\
    \            int l = std::lower_bound(x.begin(), x.end(), query[i][1]) - x.begin();\r\
    \n            int r = std::lower_bound(x.begin(), x.end(), query[i][2]) - x.begin();\r\
    \n            ebi::line<i64> ya(query[i][3], query[i][4]);\r\n            seg.add_segment(ya,\
    \ l, r);\r\n        }\r\n        else {\r\n            int index = std::lower_bound(x.begin(),\
    \ x.end(), query[i][1]) - x.begin();\r\n            i64 ret = seg.get(index);\r\
    \n            if(ret == std::numeric_limits<i64>::max()) {\r\n               \
    \ std::cout << \"INFINITY\" << std::endl;\r\n            }\r\n            else{\r\
    \n                std::cout << ret << std::endl;\r\n            }\r\n        }\r\
    \n    }\r\n}"
  dependsOn:
  - data_structure/LiChaoSegmentTree.hpp
  - utility/int_alias.hpp
  isVerificationFile: true
  path: test/SegmentAddGetMin.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SegmentAddGetMin.test.cpp
layout: document
redirect_from:
- /verify/test/SegmentAddGetMin.test.cpp
- /verify/test/SegmentAddGetMin.test.cpp.html
title: test/SegmentAddGetMin.test.cpp
---