---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/intersection.hpp
    title: geometry/intersection.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/intersection.test.cpp
    title: test/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/isp.test.cpp
    title: test/isp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/isp.hpp\"\n\r\n#line 2 \"geometry/template.hpp\"\
    \n\r\n#include <cmath>\r\n#include <cassert>\r\n\r\nnamespace ebi {\r\n\r\nconstexpr\
    \ long double EPS = 1e-10;\r\n\r\nnamespace internal {\r\n\r\nint sgn(long double\
    \ a) {\r\n    return (a<-EPS) ? -1 : (a>EPS) ? 1 : 0;\r\n}\r\n\r\ndouble add(long\
    \ double a, long double b) {\r\n    if(std::abs(a+b) < EPS*(std::abs(a) + std::abs(b)))\
    \ return 0;\r\n    return a+b;\r\n}\r\n\r\n} // namespace internal\r\n\r\nstruct\
    \ point {\r\n    long double x,y;\r\n\r\n    point() = default;\r\n\r\n    point(long\
    \ double x, long double y) : x(x), y(y) { }\r\n\r\n    point &operator+=(const\
    \ point rhs) noexcept {\r\n        x = internal::add(x, rhs.x);\r\n        y =\
    \ internal::add(y, rhs.y);\r\n        return *this;\r\n    }\r\n\r\n    point\
    \ &operator-=(const point rhs) noexcept {\r\n        x = internal::add(x, -rhs.x);\r\
    \n        y = internal::add(y, -rhs.y);\r\n        return *this;\r\n    }\r\n\r\
    \n    point &operator*=(const long double k) noexcept {\r\n        x *= k;\r\n\
    \        y *= k;\r\n        return *this;\r\n    }\r\n\r\n    point &operator/=(const\
    \ long double k) {\r\n        assert(internal::sgn(k)!=0);\r\n        x /= k;\r\
    \n        y /= k;\r\n        return *this;\r\n    }\r\n\r\n    point operator+(const\
    \ point &rhs) const noexcept {\r\n        return point(*this) += rhs;\r\n    }\r\
    \n\r\n    point operator-(const point &rhs) const noexcept {\r\n        return\
    \ point(*this) -= rhs;\r\n    }\r\n\r\n    point operator*(const long double rhs)\
    \ const noexcept {\r\n        return point(*this) *= rhs;\r\n    }\r\n\r\n   \
    \ point operator/(const long double rhs) const {\r\n        return point(*this)\
    \ /= rhs;\r\n    }\r\n\r\n    long double abs() const noexcept {\r\n        return\
    \ std::sqrt(internal::add(x*x, y*y));\r\n    }\r\n\r\n    long double dot(const\
    \ point rhs) const noexcept {\r\n        return internal::add(x*rhs.x, y*rhs.y);\r\
    \n    }\r\n\r\n    long double det(const point rhs) const noexcept {\r\n     \
    \   return internal::add(x*rhs.y, -y*rhs.x);\r\n    }\r\n\r\n    bool operator<(const\
    \ point &rhs) const noexcept {\r\n        if(internal::sgn(x-rhs.x)) return internal::sgn(x-rhs.x)<0;\r\
    \n        return internal::sgn(y-rhs.y)<0;\r\n    }\r\n};\r\n\r\nlong double dot(const\
    \ point &a, const point &b) {\r\n    return a.dot(b);\r\n}\r\n\r\nlong double\
    \ det(const point &a, const point &b) {\r\n    return a.det(b);\r\n}\r\n\r\nlong\
    \ double norm(const point &a) {\r\n    return internal::add(a.x*a.x, a.y*a.y);\r\
    \n}\r\n\r\nstruct line {\r\n    point a,b;\r\n\r\n    line(long double x1, long\
    \ double y1, long double x2, long double y2) : a(x1, y1), b(x2, y2) { }\r\n\r\n\
    \    point proj(const point &p) {\r\n        return a + (b-a)*(dot(b-a,p-a)/norm(b-a));\r\
    \n    }\r\n\r\n    point relf(const point &p) {\r\n        return proj(p)*double(2)\
    \ - p;\r\n    }\r\n};\r\n\r\n}\n#line 4 \"geometry/isp.hpp\"\n\r\nnamespace ebi\
    \ {\r\n\r\nint isp(const point &a, const point &b, const point &c) {\r\n    int\
    \ flag = internal::sgn(det(b-a,c-a));\r\n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a,\
    \ c-a))<0) return -2;\r\n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\
    \n    }\r\n    return flag;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include \"../geometry/template.hpp\"\r\n\r\nnamespace\
    \ ebi {\r\n\r\nint isp(const point &a, const point &b, const point &c) {\r\n \
    \   int flag = internal::sgn(det(b-a,c-a));\r\n    if(flag == 0) {\r\n       \
    \ if(internal::sgn(dot(b-a, c-a))<0) return -2;\r\n        if(internal::sgn(dot(a-b,\
    \ c-b))<0) return +2;\r\n    }\r\n    return flag;\r\n}\r\n\r\n}"
  dependsOn:
  - geometry/template.hpp
  isVerificationFile: false
  path: geometry/isp.hpp
  requiredBy:
  - geometry/intersection.hpp
  timestamp: '2021-09-14 18:15:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/intersection.test.cpp
  - test/isp.test.cpp
documentation_of: geometry/isp.hpp
layout: document
title: isp
---

# 説明

点の進行方向を求める関数.

- ```int isp(point a, point b, point c)```
    - 左に曲がる場合:$+1$ 
    - 右に曲がる場合:$-1$
    - c-a-bの順に並ぶ:$-2$
    - a-b-cの順に並ぶ:$+2$
    - a-c-bの順に並ぶ:$0$