---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/isp.hpp
    title: isp
  - icon: ':heavy_check_mark:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/intersection.test.cpp
    title: test/intersection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/intersection.hpp\"\n\r\n#line 2 \"geometry/isp.hpp\"\
    \n\r\n#line 2 \"geometry/template.hpp\"\n\r\n#include <cmath>\r\n#include <cassert>\r\
    \n\r\nnamespace ebi {\r\n\r\nconstexpr double EPS = 1e-10;\r\n\r\nnamespace internal\
    \ {\r\n\r\nint sgn(double a) {\r\n    return (a<-EPS) ? -1 : (a>EPS) ? 1 : 0;\r\
    \n}\r\n\r\ndouble add(double a, double b) {\r\n    if(std::abs(a+b) < EPS*(std::abs(a)\
    \ + std::abs(b))) return 0;\r\n    return a+b;\r\n}\r\n\r\n} // namespace internal\r\
    \n\r\nstruct point {\r\n    double x,y;\r\n\r\n    point() { }\r\n\r\n    point(double\
    \ x, double y) : x(x), y(y) { }\r\n\r\n    point &operator+=(const point rhs)\
    \ noexcept {\r\n        x = internal::add(x, rhs.x);\r\n        y = internal::add(y,\
    \ rhs.y);\r\n        return *this;\r\n    }\r\n\r\n    point &operator-=(const\
    \ point rhs) noexcept {\r\n        x = internal::add(x, -rhs.x);\r\n        y\
    \ = internal::add(y, -rhs.y);\r\n        return *this;\r\n    }\r\n\r\n    point\
    \ &operator*=(const double k) noexcept {\r\n        x *= k;\r\n        y *= k;\r\
    \n        return *this;\r\n    }\r\n\r\n    point &operator/=(const double k)\
    \ {\r\n        assert(internal::sgn(k)!=0);\r\n        x /= k;\r\n        y /=\
    \ k;\r\n        return *this;\r\n    }\r\n\r\n    point operator+(const point\
    \ rhs) const noexcept {\r\n        return point(*this) += rhs;\r\n    }\r\n\r\n\
    \    point operator-(const point rhs) const noexcept {\r\n        return point(*this)\
    \ -= rhs;\r\n    }\r\n\r\n    point operator*(const double rhs) const noexcept\
    \ {\r\n        return point(*this) *= rhs;\r\n    }\r\n\r\n    point operator/(const\
    \ double rhs) const {\r\n        return point(*this) /= rhs;\r\n    }\r\n\r\n\
    \    double abs() const noexcept {\r\n        return std::sqrt(internal::add(x*x,\
    \ y*y));\r\n    }\r\n\r\n    double dot(const point rhs) const noexcept {\r\n\
    \        return internal::add(x*rhs.x, y*rhs.y);\r\n    }\r\n\r\n    double det(const\
    \ point rhs) const noexcept {\r\n        return internal::add(x*rhs.y, -y*rhs.x);\r\
    \n    }\r\n\r\n    bool operator<(const point &rhs) const noexcept {\r\n     \
    \   if(internal::sgn(x-rhs.x)) return internal::sgn(x-rhs.x)<0;\r\n        return\
    \ internal::sgn(y-rhs.y)<0;\r\n    }\r\n};\r\n\r\ndouble dot(const point &a, const\
    \ point &b) {\r\n    return a.dot(b);\r\n}\r\n\r\ndouble det(const point &a, const\
    \ point &b) {\r\n    return a.det(b);\r\n}\r\n\r\ndouble norm(const point &a)\
    \ {\r\n    return internal::add(a.x*a.x, a.y*a.y);\r\n}\r\n\r\nstruct line {\r\
    \n    point a,b;\r\n\r\n    line(double x1, double y1, double x2, double y2) :\
    \ a(x1, y1), b(x2, y2) { }\r\n\r\n    point proj(const point &p) {\r\n       \
    \ return a + (b-a)*(dot(b-a,p-a)/norm(b-a));\r\n    }\r\n\r\n    point relf(const\
    \ point &p) {\r\n        return proj(p)*double(2) - p;\r\n    }\r\n};\r\n\r\n\
    }\n#line 4 \"geometry/isp.hpp\"\n\r\nnamespace ebi {\r\n\r\nint isp(const point\
    \ &a, const point &b, const point &c) {\r\n    int flag = internal::sgn(det(b-a,c-a));\r\
    \n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a, c-a))<0) return -2;\r\
    \n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\n    }\r\n    return\
    \ flag;\r\n}\r\n\r\n}\n#line 5 \"geometry/intersection.hpp\"\n\r\nnamespace ebi\
    \ {\r\n\r\nbool intersection(const point &a, const point &b, const point &c, const\
    \ point &d) {\r\n    if(isp(a,b,c)*isp(a,b,d) <= 0 && isp(c,d,a)*isp(c,d,b) <=\
    \ 0) {\r\n        return true;\r\n    }\r\n    return false;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include \"../geometry/isp.hpp\"\r\n#include \"../geometry/template.hpp\"\
    \r\n\r\nnamespace ebi {\r\n\r\nbool intersection(const point &a, const point &b,\
    \ const point &c, const point &d) {\r\n    if(isp(a,b,c)*isp(a,b,d) <= 0 && isp(c,d,a)*isp(c,d,b)\
    \ <= 0) {\r\n        return true;\r\n    }\r\n    return false;\r\n}\r\n\r\n}"
  dependsOn:
  - geometry/isp.hpp
  - geometry/template.hpp
  isVerificationFile: false
  path: geometry/intersection.hpp
  requiredBy: []
  timestamp: '2021-02-14 18:21:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/intersection.test.cpp
documentation_of: geometry/intersection.hpp
layout: document
redirect_from:
- /library/geometry/intersection.hpp
- /library/geometry/intersection.hpp.html
title: geometry/intersection.hpp
---