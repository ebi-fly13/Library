---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/geometry/intersection.test.cpp
    title: test/geometry/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersection_line_segment.test.cpp
    title: test/geometry/intersection_line_segment.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/isp.test.cpp
    title: test/geometry/isp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/reflection.test.cpp
    title: test/geometry/reflection.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/point.hpp\"\n\r\n#include <cmath>\r\n#include <cassert>\r\
    \n\r\nnamespace ebi {\r\n\r\nconstexpr long double EPS = 1e-10;\r\n\r\nnamespace\
    \ internal {\r\n\r\nint sgn(long double a) {\r\n    return (a<-EPS) ? -1 : (a>EPS)\
    \ ? 1 : 0;\r\n}\r\n\r\ndouble add(long double a, long double b) {\r\n    if(std::abs(a+b)\
    \ < EPS*(std::abs(a) + std::abs(b))) return 0;\r\n    return a+b;\r\n}\r\n\r\n\
    } // namespace internal\r\n\r\nstruct point {\r\n    long double x,y;\r\n\r\n\
    \    point() = default;\r\n\r\n    point(long double x, long double y) : x(x),\
    \ y(y) { }\r\n\r\n    point &operator+=(const point rhs) noexcept {\r\n      \
    \  x = internal::add(x, rhs.x);\r\n        y = internal::add(y, rhs.y);\r\n  \
    \      return *this;\r\n    }\r\n\r\n    point &operator-=(const point rhs) noexcept\
    \ {\r\n        x = internal::add(x, -rhs.x);\r\n        y = internal::add(y, -rhs.y);\r\
    \n        return *this;\r\n    }\r\n\r\n    point &operator*=(const long double\
    \ k) noexcept {\r\n        x *= k;\r\n        y *= k;\r\n        return *this;\r\
    \n    }\r\n\r\n    point &operator/=(const long double k) {\r\n        assert(internal::sgn(k)!=0);\r\
    \n        x /= k;\r\n        y /= k;\r\n        return *this;\r\n    }\r\n\r\n\
    \    point operator+(const point &rhs) const noexcept {\r\n        return point(*this)\
    \ += rhs;\r\n    }\r\n\r\n    point operator-(const point &rhs) const noexcept\
    \ {\r\n        return point(*this) -= rhs;\r\n    }\r\n\r\n    point operator*(const\
    \ long double rhs) const noexcept {\r\n        return point(*this) *= rhs;\r\n\
    \    }\r\n\r\n    point operator/(const long double rhs) const {\r\n        return\
    \ point(*this) /= rhs;\r\n    }\r\n\r\n    point operator-() const noexcept {\r\
    \n        return point(0, 0) - *this;\r\n    }\r\n\r\n    long double abs() const\
    \ noexcept {\r\n        return std::sqrt(internal::add(x*x, y*y));\r\n    }\r\n\
    \r\n    long double dot(const point rhs) const noexcept {\r\n        return internal::add(x*rhs.x,\
    \ y*rhs.y);\r\n    }\r\n\r\n    long double det(const point rhs) const noexcept\
    \ {\r\n        return internal::add(x*rhs.y, -y*rhs.x);\r\n    }\r\n\r\n    //\
    \ arctan(y/x) (\u5358\u4F4D\u306F\u30E9\u30B8\u30A2\u30F3)\r\n    long double\
    \ arg() const {\r\n        return std::atan2(y, x);\r\n    }\r\n\r\n    // x\u6607\
    \u9806, \u305D\u306E\u5F8Cy\u6607\u9806\r\n    bool operator<(const point &rhs)\
    \ const noexcept {\r\n        if(internal::sgn(x-rhs.x)) return internal::sgn(x-rhs.x)<0;\r\
    \n        return internal::sgn(y-rhs.y)<0;\r\n    }\r\n};\r\n\r\nlong double dot(const\
    \ point &a, const point &b) {\r\n    return a.dot(b);\r\n}\r\n\r\nlong double\
    \ det(const point &a, const point &b) {\r\n    return a.det(b);\r\n}\r\n\r\nlong\
    \ double norm(const point &a) {\r\n    return internal::add(a.x*a.x, a.y*a.y);\r\
    \n}\r\n\r\nint isp(const point &a, const point &b, const point &c) {\r\n    int\
    \ flag = internal::sgn(det(b-a,c-a));\r\n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a,\
    \ c-a))<0) return -2;\r\n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\
    \n    }\r\n    return flag;\r\n}\r\n\r\nbool intersection_line_segment(const point\
    \ &a, const point &b, const point &c, const point &d) {\r\n    if(isp(a,b,c)*isp(a,b,d)\
    \ <= 0 && isp(c,d,a)*isp(c,d,b) <= 0) {\r\n        return true;\r\n    }\r\n \
    \   return false;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <cmath>\r\n#include <cassert>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nconstexpr long double EPS = 1e-10;\r\n\r\nnamespace internal {\r\
    \n\r\nint sgn(long double a) {\r\n    return (a<-EPS) ? -1 : (a>EPS) ? 1 : 0;\r\
    \n}\r\n\r\ndouble add(long double a, long double b) {\r\n    if(std::abs(a+b)\
    \ < EPS*(std::abs(a) + std::abs(b))) return 0;\r\n    return a+b;\r\n}\r\n\r\n\
    } // namespace internal\r\n\r\nstruct point {\r\n    long double x,y;\r\n\r\n\
    \    point() = default;\r\n\r\n    point(long double x, long double y) : x(x),\
    \ y(y) { }\r\n\r\n    point &operator+=(const point rhs) noexcept {\r\n      \
    \  x = internal::add(x, rhs.x);\r\n        y = internal::add(y, rhs.y);\r\n  \
    \      return *this;\r\n    }\r\n\r\n    point &operator-=(const point rhs) noexcept\
    \ {\r\n        x = internal::add(x, -rhs.x);\r\n        y = internal::add(y, -rhs.y);\r\
    \n        return *this;\r\n    }\r\n\r\n    point &operator*=(const long double\
    \ k) noexcept {\r\n        x *= k;\r\n        y *= k;\r\n        return *this;\r\
    \n    }\r\n\r\n    point &operator/=(const long double k) {\r\n        assert(internal::sgn(k)!=0);\r\
    \n        x /= k;\r\n        y /= k;\r\n        return *this;\r\n    }\r\n\r\n\
    \    point operator+(const point &rhs) const noexcept {\r\n        return point(*this)\
    \ += rhs;\r\n    }\r\n\r\n    point operator-(const point &rhs) const noexcept\
    \ {\r\n        return point(*this) -= rhs;\r\n    }\r\n\r\n    point operator*(const\
    \ long double rhs) const noexcept {\r\n        return point(*this) *= rhs;\r\n\
    \    }\r\n\r\n    point operator/(const long double rhs) const {\r\n        return\
    \ point(*this) /= rhs;\r\n    }\r\n\r\n    point operator-() const noexcept {\r\
    \n        return point(0, 0) - *this;\r\n    }\r\n\r\n    long double abs() const\
    \ noexcept {\r\n        return std::sqrt(internal::add(x*x, y*y));\r\n    }\r\n\
    \r\n    long double dot(const point rhs) const noexcept {\r\n        return internal::add(x*rhs.x,\
    \ y*rhs.y);\r\n    }\r\n\r\n    long double det(const point rhs) const noexcept\
    \ {\r\n        return internal::add(x*rhs.y, -y*rhs.x);\r\n    }\r\n\r\n    //\
    \ arctan(y/x) (\u5358\u4F4D\u306F\u30E9\u30B8\u30A2\u30F3)\r\n    long double\
    \ arg() const {\r\n        return std::atan2(y, x);\r\n    }\r\n\r\n    // x\u6607\
    \u9806, \u305D\u306E\u5F8Cy\u6607\u9806\r\n    bool operator<(const point &rhs)\
    \ const noexcept {\r\n        if(internal::sgn(x-rhs.x)) return internal::sgn(x-rhs.x)<0;\r\
    \n        return internal::sgn(y-rhs.y)<0;\r\n    }\r\n};\r\n\r\nlong double dot(const\
    \ point &a, const point &b) {\r\n    return a.dot(b);\r\n}\r\n\r\nlong double\
    \ det(const point &a, const point &b) {\r\n    return a.det(b);\r\n}\r\n\r\nlong\
    \ double norm(const point &a) {\r\n    return internal::add(a.x*a.x, a.y*a.y);\r\
    \n}\r\n\r\nint isp(const point &a, const point &b, const point &c) {\r\n    int\
    \ flag = internal::sgn(det(b-a,c-a));\r\n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a,\
    \ c-a))<0) return -2;\r\n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\
    \n    }\r\n    return flag;\r\n}\r\n\r\nbool intersection_line_segment(const point\
    \ &a, const point &b, const point &c, const point &d) {\r\n    if(isp(a,b,c)*isp(a,b,d)\
    \ <= 0 && isp(c,d,a)*isp(c,d,b) <= 0) {\r\n        return true;\r\n    }\r\n \
    \   return false;\r\n}\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/point.hpp
  requiredBy:
  - geometry/line.hpp
  timestamp: '2021-09-14 22:42:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/geometry/intersection.test.cpp
  - test/geometry/reflection.test.cpp
  - test/geometry/isp.test.cpp
  - test/geometry/intersection_line_segment.test.cpp
documentation_of: geometry/point.hpp
layout: document
redirect_from:
- /library/geometry/point.hpp
- /library/geometry/point.hpp.html
title: geometry/point.hpp
---
