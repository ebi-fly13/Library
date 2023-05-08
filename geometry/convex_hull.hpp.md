---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/geometry/convex_hull.test.cpp
    title: test/geometry/convex_hull.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/typical90/submissions/24974484
  bundledCode: "#line 2 \"geometry/convex_hull.hpp\"\n\r\n#include <vector>\r\n\r\n\
    /*\r\n    reference: \u30D7\u30ED\u30B0\u30E9\u30DF\u30F3\u30B0\u30B3\u30F3\u30C6\
    \u30B9\u30C8\u30C1\u30E3\u30EC\u30F3\u30B8\u30D6\u30C3\u30AF \u7B2C2\u7248 p234\r\
    \n    verify:    https://atcoder.jp/contests/typical90/submissions/24974484\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct Point {\r\n    T\
    \ x, y;\r\n\r\n    Point &operator+=(const Point &rhs) noexcept {\r\n        x\
    \ += rhs.x;\r\n        y += rhs.y;\r\n        return *this;\r\n    }\r\n\r\n \
    \   Point &operator-=(const Point &rhs) noexcept {\r\n        x -= rhs.x;\r\n\
    \        y -= rhs.y;\r\n        return *this;\r\n    }\r\n\r\n    Point operator-(const\
    \ Point &rhs) const noexcept {\r\n        return Point(*this) -= rhs;\r\n    }\r\
    \n\r\n    T det(const Point &rhs) const noexcept {\r\n        return x * rhs.y\
    \ - y * rhs.x;\r\n    }\r\n};\r\n\r\ntemplate<class T>\r\nstd::vector<Point<T>>\
    \ convex_hull(int n, std::vector<Point<T>> p, bool on = false) {\r\n    std::sort(p.begin(),\
    \ p.end(), [](const Point<T> &a, const Point<T> &b) { return a.x != b.x ? a.x\
    \ < b.x : a.y < b.y; });\r\n    std::vector<Point<T>> g1, g2;\r\n    int k1 =\
    \ 0, k2 = 0;\r\n    for(int i = 0; i < n; i++) {\r\n        while(k1 > 1 && (g1[k1-1]-g1[k1-2]).det(p[i]-g1[k1-1])\
    \ <= 0) {\r\n            if(on && (g1[k1-1]-g1[k1-2]).det(p[i]-g1[k1-1]) == 0)\
    \ break;\r\n            g1.pop_back();\r\n            k1--;\r\n        }\r\n \
    \       while(k2 > 1 && (g2[k2-1]-g2[k2-2]).det(p[i]-g2[k2-1]) >= 0) {\r\n   \
    \         if(on && (g2[k2-1]-g2[k2-2]).det(p[i]-g2[k2-1]) == 0) break;\r\n   \
    \         g2.pop_back();\r\n            k2--;\r\n        }\r\n        g1.push_back(p[i]);\r\
    \n        k1++;\r\n        g2.push_back(p[i]);\r\n        k2++;\r\n    }\r\n \
    \   std::vector<Point<T>> ch(k1+k2-2);\r\n    for(int i = 0; i < k1; i++) {\r\n\
    \        ch[i] = g1[i];\r\n    }\r\n    for(int i = k2-2; i > 0; i--) {\r\n  \
    \      ch[k1 + k2 - i - 2] = g2[i];\r\n    }\r\n    return ch;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\n/*\r\n    reference: \u30D7\u30ED\
    \u30B0\u30E9\u30DF\u30F3\u30B0\u30B3\u30F3\u30C6\u30B9\u30C8\u30C1\u30E3\u30EC\
    \u30F3\u30B8\u30D6\u30C3\u30AF \u7B2C2\u7248 p234\r\n    verify:    https://atcoder.jp/contests/typical90/submissions/24974484\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct Point {\r\n   \
    \ T x, y;\r\n\r\n    Point &operator+=(const Point &rhs) noexcept {\r\n      \
    \  x += rhs.x;\r\n        y += rhs.y;\r\n        return *this;\r\n    }\r\n\r\n\
    \    Point &operator-=(const Point &rhs) noexcept {\r\n        x -= rhs.x;\r\n\
    \        y -= rhs.y;\r\n        return *this;\r\n    }\r\n\r\n    Point operator-(const\
    \ Point &rhs) const noexcept {\r\n        return Point(*this) -= rhs;\r\n    }\r\
    \n\r\n    T det(const Point &rhs) const noexcept {\r\n        return x * rhs.y\
    \ - y * rhs.x;\r\n    }\r\n};\r\n\r\ntemplate<class T>\r\nstd::vector<Point<T>>\
    \ convex_hull(int n, std::vector<Point<T>> p, bool on = false) {\r\n    std::sort(p.begin(),\
    \ p.end(), [](const Point<T> &a, const Point<T> &b) { return a.x != b.x ? a.x\
    \ < b.x : a.y < b.y; });\r\n    std::vector<Point<T>> g1, g2;\r\n    int k1 =\
    \ 0, k2 = 0;\r\n    for(int i = 0; i < n; i++) {\r\n        while(k1 > 1 && (g1[k1-1]-g1[k1-2]).det(p[i]-g1[k1-1])\
    \ <= 0) {\r\n            if(on && (g1[k1-1]-g1[k1-2]).det(p[i]-g1[k1-1]) == 0)\
    \ break;\r\n            g1.pop_back();\r\n            k1--;\r\n        }\r\n \
    \       while(k2 > 1 && (g2[k2-1]-g2[k2-2]).det(p[i]-g2[k2-1]) >= 0) {\r\n   \
    \         if(on && (g2[k2-1]-g2[k2-2]).det(p[i]-g2[k2-1]) == 0) break;\r\n   \
    \         g2.pop_back();\r\n            k2--;\r\n        }\r\n        g1.push_back(p[i]);\r\
    \n        k1++;\r\n        g2.push_back(p[i]);\r\n        k2++;\r\n    }\r\n \
    \   std::vector<Point<T>> ch(k1+k2-2);\r\n    for(int i = 0; i < k1; i++) {\r\n\
    \        ch[i] = g1[i];\r\n    }\r\n    for(int i = k2-2; i > 0; i--) {\r\n  \
    \      ch[k1 + k2 - i - 2] = g2[i];\r\n    }\r\n    return ch;\r\n}\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2021-09-15 13:37:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/geometry/convex_hull.test.cpp
documentation_of: geometry/convex_hull.hpp
layout: document
redirect_from:
- /library/geometry/convex_hull.hpp
- /library/geometry/convex_hull.hpp.html
title: geometry/convex_hull.hpp
---
