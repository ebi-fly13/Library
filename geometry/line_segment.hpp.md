---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/distance.test.cpp
    title: test/geometry/distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/line_segment.hpp\"\n\n#include <cmath>\n#include\
    \ <cassert>\n\n#line 2 \"geometry/point.hpp\"\n\r\n#line 5 \"geometry/point.hpp\"\
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
    \ double abs(const point &a) {\r\n    return a.abs();\r\n}\r\n\r\nlong double\
    \ norm(const point &a) {\r\n    return internal::add(a.x*a.x, a.y*a.y);\r\n}\r\
    \n\r\nint isp(const point &a, const point &b, const point &c) {\r\n    int flag\
    \ = internal::sgn(det(b-a,c-a));\r\n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a,\
    \ c-a))<0) return -2;\r\n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\
    \n    }\r\n    return flag;\r\n}\r\n\r\n// \u7DDA\u5206ab, cd \u304C\u4EA4\u308F\
    \u308B\u304B\u5224\u5B9A\r\nbool intersection_line_segment(const point &a, const\
    \ point &b, const point &c, const point &d) {\r\n    if(internal::sgn(isp(a,b,c)*isp(a,b,d))\
    \ <= 0 && internal::sgn(isp(c,d,a)*isp(c,d,b)) <= 0) {\r\n        return true;\r\
    \n    }\r\n    return false;\r\n}\r\n\r\npoint cross_point(const point &a, const\
    \ point &b, const point &c, const point &d) {\r\n    return a + (b-a) * det(c\
    \ - a, d - c) / det(b - a, d - c);\r\n}\r\n\r\n}\n#line 7 \"geometry/line_segment.hpp\"\
    \n\nnamespace ebi {\n\nstruct line_segment {\n    point a, b;\n\n    line_segment(long\
    \ double x1, long double y1, long double x2, long double y2) : a(x1, y1), b(x2,\
    \ y2) { }\n\n    line_segment(point &a, point &b) : a(a), b(b) { }\n};\n\n// \u7DDA\
    \u5206ab, cd \u304C\u4EA4\u308F\u308B\u304B\u5224\u5B9A\nbool intersection_line_segment(const\
    \ line_segment &a, const line_segment &b) {\n    return intersection_line_segment(a.a,\
    \ a.b, b.a, b.b);\n}\n\nlong double distance(const line_segment &a, const point\
    \ &c) {\n    if(internal::sgn(dot(a.b - a.a, c - a.a)) < 0) {\n        return\
    \ abs(c-a.a);\n    }\n    else if(internal::sgn(dot(a.a - a.b, c - a.b)) < 0)\
    \ {\n        return abs(c-a.b);\n    }\n    else {\n        return std::abs(det(c\
    \ - a.a, a.b - a.a)/abs(a.b-a.a));\n    }\n}\n\nlong double distance(const line_segment\
    \ &a, const line_segment &b) {\n    if(intersection_line_segment(a, b)) {\n  \
    \      return 0;\n    }\n    else {\n        return std::min(std::min(distance(a,\
    \ b.a), distance(a, b.b)), std::min(distance(b, a.a), distance(b, a.b)));\n  \
    \  }\n}\n\n}\n"
  code: "#pragma once\n\n#include <cmath>\n#include <cassert>\n\n#include \"point.hpp\"\
    \n\nnamespace ebi {\n\nstruct line_segment {\n    point a, b;\n\n    line_segment(long\
    \ double x1, long double y1, long double x2, long double y2) : a(x1, y1), b(x2,\
    \ y2) { }\n\n    line_segment(point &a, point &b) : a(a), b(b) { }\n};\n\n// \u7DDA\
    \u5206ab, cd \u304C\u4EA4\u308F\u308B\u304B\u5224\u5B9A\nbool intersection_line_segment(const\
    \ line_segment &a, const line_segment &b) {\n    return intersection_line_segment(a.a,\
    \ a.b, b.a, b.b);\n}\n\nlong double distance(const line_segment &a, const point\
    \ &c) {\n    if(internal::sgn(dot(a.b - a.a, c - a.a)) < 0) {\n        return\
    \ abs(c-a.a);\n    }\n    else if(internal::sgn(dot(a.a - a.b, c - a.b)) < 0)\
    \ {\n        return abs(c-a.b);\n    }\n    else {\n        return std::abs(det(c\
    \ - a.a, a.b - a.a)/abs(a.b-a.a));\n    }\n}\n\nlong double distance(const line_segment\
    \ &a, const line_segment &b) {\n    if(intersection_line_segment(a, b)) {\n  \
    \      return 0;\n    }\n    else {\n        return std::min(std::min(distance(a,\
    \ b.a), distance(a, b.b)), std::min(distance(b, a.a), distance(b, a.b)));\n  \
    \  }\n}\n\n}"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/line_segment.hpp
  requiredBy: []
  timestamp: '2021-09-15 00:04:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/distance.test.cpp
documentation_of: geometry/line_segment.hpp
layout: document
redirect_from:
- /library/geometry/line_segment.hpp
- /library/geometry/line_segment.hpp.html
title: geometry/line_segment.hpp
---
