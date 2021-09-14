---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point.test.cpp
    title: test/point.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/line.hpp\"\n\n#include <cmath>\n#include <cassert>\n\
    \n#line 2 \"geometry/point.hpp\"\n\r\n#line 5 \"geometry/point.hpp\"\n\r\nnamespace\
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
    \n    }\r\n    return flag;\r\n}\r\n\r\nbool intersection(const point &a, const\
    \ point &b, const point &c, const point &d) {\r\n    if(isp(a,b,c)*isp(a,b,d)\
    \ <= 0 && isp(c,d,a)*isp(c,d,b) <= 0) {\r\n        return true;\r\n    }\r\n \
    \   return false;\r\n}\r\n\r\n}\n#line 7 \"geometry/line.hpp\"\n\nnamespace ebi\
    \ {\n\nstruct line {\n    point a,b;\n\n    line(long double x1, long double y1,\
    \ long double x2, long double y2) : a(x1, y1), b(x2, y2) { }\n\n    line(point\
    \ &a, point &b) : a(a), b(b) { }\n\n    point proj(const point &p) {\n       \
    \ return a + (b-a)*(dot(b-a,p-a)/norm(b-a));\n    }\n\n    point relf(const point\
    \ &p) {\n        return proj(p)*double(2) - p;\n    }\n};\n    \n}\n"
  code: "#pragma once\n\n#include <cmath>\n#include <cassert>\n\n#include \"point.hpp\"\
    \n\nnamespace ebi {\n\nstruct line {\n    point a,b;\n\n    line(long double x1,\
    \ long double y1, long double x2, long double y2) : a(x1, y1), b(x2, y2) { }\n\
    \n    line(point &a, point &b) : a(a), b(b) { }\n\n    point proj(const point\
    \ &p) {\n        return a + (b-a)*(dot(b-a,p-a)/norm(b-a));\n    }\n\n    point\
    \ relf(const point &p) {\n        return proj(p)*double(2) - p;\n    }\n};\n \
    \   \n}"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy: []
  timestamp: '2021-09-14 22:15:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point.test.cpp
documentation_of: geometry/line.hpp
layout: document
redirect_from:
- /library/geometry/line.hpp
- /library/geometry/line.hpp.html
title: geometry/line.hpp
---
