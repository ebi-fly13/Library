---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: point
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/area.test.cpp
    title: test/geometry/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/contains.test.cpp
    title: test/geometry/contains.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/is_convex.test.cpp
    title: test/geometry/is_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/polygon.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n#line 2 \"geometry/point.hpp\"\n\r\n#include <cmath>\r\n#line 6 \"geometry/point.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nconstexpr long double EPS = 1e-10;\r\n\r\nnamespace\
    \ internal {\r\n\r\nint sgn(long double a) {\r\n    return (a<-EPS) ? -1 : (a>EPS)\
    \ ? 1 : 0;\r\n}\r\n\r\nlong double add(long double a, long double b) {\r\n   \
    \ if(std::abs(a+b) < EPS*(std::abs(a) + std::abs(b))) return 0;\r\n    return\
    \ a+b;\r\n}\r\n\r\n} // namespace internal\r\n\r\nstruct point {\r\n    long double\
    \ x,y;\r\n\r\n    point() = default;\r\n\r\n    point(long double x, long double\
    \ y) : x(x), y(y) { }\r\n\r\n    point &operator+=(const point rhs) noexcept {\r\
    \n        x = internal::add(x, rhs.x);\r\n        y = internal::add(y, rhs.y);\r\
    \n        return *this;\r\n    }\r\n\r\n    point &operator-=(const point rhs)\
    \ noexcept {\r\n        x = internal::add(x, -rhs.x);\r\n        y = internal::add(y,\
    \ -rhs.y);\r\n        return *this;\r\n    }\r\n\r\n    point &operator*=(const\
    \ long double k) noexcept {\r\n        x *= k;\r\n        y *= k;\r\n        return\
    \ *this;\r\n    }\r\n\r\n    point &operator/=(const long double k) {\r\n    \
    \    assert(internal::sgn(k)!=0);\r\n        x /= k;\r\n        y /= k;\r\n  \
    \      return *this;\r\n    }\r\n\r\n    point operator+(const point &rhs) const\
    \ noexcept {\r\n        return point(*this) += rhs;\r\n    }\r\n\r\n    point\
    \ operator-(const point &rhs) const noexcept {\r\n        return point(*this)\
    \ -= rhs;\r\n    }\r\n\r\n    point operator*(const long double rhs) const noexcept\
    \ {\r\n        return point(*this) *= rhs;\r\n    }\r\n\r\n    point operator/(const\
    \ long double rhs) const {\r\n        return point(*this) /= rhs;\r\n    }\r\n\
    \r\n    point operator-() const noexcept {\r\n        return point(0, 0) - *this;\r\
    \n    }\r\n\r\n    long double abs() const noexcept {\r\n        return std::sqrt(internal::add(x*x,\
    \ y*y));\r\n    }\r\n\r\n    long double dot(const point rhs) const noexcept {\r\
    \n        return internal::add(x*rhs.x, y*rhs.y);\r\n    }\r\n\r\n    long double\
    \ det(const point rhs) const noexcept {\r\n        return internal::add(x*rhs.y,\
    \ -y*rhs.x);\r\n    }\r\n\r\n    // arctan(y/x) (\u5358\u4F4D\u306F\u30E9\u30B8\
    \u30A2\u30F3)\r\n    long double arg() const {\r\n        return std::atan2(y,\
    \ x);\r\n    }\r\n\r\n    // x\u6607\u9806, \u305D\u306E\u5F8Cy\u6607\u9806\r\n\
    \    bool operator<(const point &rhs) const noexcept {\r\n        if(internal::sgn(x-rhs.x))\
    \ return internal::sgn(x-rhs.x)<0;\r\n        return internal::sgn(y-rhs.y)<0;\r\
    \n    }\r\n};\r\n\r\nlong double dot(const point &a, const point &b) {\r\n   \
    \ return a.dot(b);\r\n}\r\n\r\nlong double det(const point &a, const point &b)\
    \ {\r\n    return a.det(b);\r\n}\r\n\r\nlong double abs(const point &a) {\r\n\
    \    return a.abs();\r\n}\r\n\r\nlong double norm(const point &a) {\r\n    return\
    \ internal::add(a.x*a.x, a.y*a.y);\r\n}\r\n\r\nint isp(const point &a, const point\
    \ &b, const point &c) {\r\n    int flag = internal::sgn(det(b-a,c-a));\r\n   \
    \ if(flag == 0) {\r\n        if(internal::sgn(dot(b-a, c-a))<0) return -2;\r\n\
    \        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\n    }\r\n    return\
    \ flag;\r\n}\r\n\r\n}\n#line 7 \"geometry/polygon.hpp\"\n\nnamespace ebi {\n\n\
    using Polygon = std::vector<point>;\n\nlong double area(const Polygon &poly) {\n\
    \    long double s = 0;\n    int n = poly.size();\n    for(int i = 0; i < n; i++)\
    \ {\n        s = internal::add(s, det(poly[i], poly[(i+1 != n) ? i+1 : 0]));\n\
    \    }\n    s /= 2.0;\n    return s;\n}\n\n// \u51F8\u591A\u89D2\u5F62\u304B\u5224\
    \u5B9A. p\u306B\u53CD\u6642\u8A08\u56DE\u308A\u3067\u70B9\u304C\u5165\u3063\u3066\
    \u3044\u308B\u3068\u4EEE\u5B9A\nbool is_convex(const Polygon &poly) {\n    int\
    \ n = poly.size();\n    for(int i = 0; i < n; i++) {\n        if(isp(poly[i],\
    \ poly[(i+1 != n) ? i+1 : 0], poly[(i+2 < n) ? i+2 : (i+2)%n]) == -1) {\n    \
    \        return false;\n        }\n    }\n    return true;\n}\n\nenum {\n    OUT,\
    \ ON, IN\n};\n\nint contains(const std::vector<point> &poly, const point &p) {\n\
    \    bool in = false;\n    int n = poly.size();\n    for(int i = 0; i < n; i++)\
    \ {\n        point a = poly[i] - p;\n        point b = poly[(i+1 < n) ? i+1 :\
    \ 0] - p;\n        if(a.y > b.y) std::swap(a, b);\n        if(a.y <= 0 && 0 <\
    \ b.y && det(a, b) < 0) in = !in;\n        if(det(a, b) == 0 && dot(a, b) <= 0)\
    \ return ON;\n    }\n    return in ? IN : OUT;\n}\n\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"point.hpp\"\
    \n\nnamespace ebi {\n\nusing Polygon = std::vector<point>;\n\nlong double area(const\
    \ Polygon &poly) {\n    long double s = 0;\n    int n = poly.size();\n    for(int\
    \ i = 0; i < n; i++) {\n        s = internal::add(s, det(poly[i], poly[(i+1 !=\
    \ n) ? i+1 : 0]));\n    }\n    s /= 2.0;\n    return s;\n}\n\n// \u51F8\u591A\u89D2\
    \u5F62\u304B\u5224\u5B9A. p\u306B\u53CD\u6642\u8A08\u56DE\u308A\u3067\u70B9\u304C\
    \u5165\u3063\u3066\u3044\u308B\u3068\u4EEE\u5B9A\nbool is_convex(const Polygon\
    \ &poly) {\n    int n = poly.size();\n    for(int i = 0; i < n; i++) {\n     \
    \   if(isp(poly[i], poly[(i+1 != n) ? i+1 : 0], poly[(i+2 < n) ? i+2 : (i+2)%n])\
    \ == -1) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    \nenum {\n    OUT, ON, IN\n};\n\nint contains(const std::vector<point> &poly,\
    \ const point &p) {\n    bool in = false;\n    int n = poly.size();\n    for(int\
    \ i = 0; i < n; i++) {\n        point a = poly[i] - p;\n        point b = poly[(i+1\
    \ < n) ? i+1 : 0] - p;\n        if(a.y > b.y) std::swap(a, b);\n        if(a.y\
    \ <= 0 && 0 < b.y && det(a, b) < 0) in = !in;\n        if(det(a, b) == 0 && dot(a,\
    \ b) <= 0) return ON;\n    }\n    return in ? IN : OUT;\n}\n\n}"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/polygon.hpp
  requiredBy: []
  timestamp: '2021-09-15 12:28:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/is_convex.test.cpp
  - test/geometry/contains.test.cpp
  - test/geometry/area.test.cpp
documentation_of: geometry/polygon.hpp
layout: document
redirect_from:
- /library/geometry/polygon.hpp
- /library/geometry/polygon.hpp.html
title: geometry/polygon.hpp
---
