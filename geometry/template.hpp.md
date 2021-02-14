---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/point.test.cpp
    title: test/point.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/template.hpp\"\n\r\n#include <cmath>\r\n#include\
    \ <cassert>\r\n\r\nnamespace ebi {\r\n\r\nconstexpr double EPS = 1e-10;\r\n\r\n\
    namespace internal {\r\n\r\nint sgn(double a) {\r\n    return (a<-EPS) ? -1 :\
    \ (a>EPS) ? 1 : 0;\r\n}\r\n\r\ndouble add(double a, double b) {\r\n    if(std::abs(a+b)\
    \ < EPS*(std::abs(a) + std::abs(b))) return 0;\r\n    return a+b;\r\n}\r\n\r\n\
    } // namespace internal\r\n\r\nstruct point {\r\n    double x,y;\r\n\r\n    point()\
    \ { }\r\n\r\n    point(double x, double y) : x(x), y(y) { }\r\n\r\n    point &operator+=(const\
    \ point rhs) noexcept {\r\n        x = internal::add(x, rhs.x);\r\n        y =\
    \ internal::add(y, rhs.y);\r\n        return *this;\r\n    }\r\n\r\n    point\
    \ &operator-=(const point rhs) noexcept {\r\n        x = internal::add(x, -rhs.x);\r\
    \n        y = internal::add(y, -rhs.y);\r\n        return *this;\r\n    }\r\n\r\
    \n    point &operator*=(const double k) noexcept {\r\n        x *= k;\r\n    \
    \    y *= k;\r\n        return *this;\r\n    }\r\n\r\n    point &operator/=(const\
    \ double k) {\r\n        assert(internal::sgn(k)!=0);\r\n        x /= k;\r\n \
    \       y /= k;\r\n        return *this;\r\n    }\r\n\r\n    point operator+(const\
    \ point rhs) const noexcept {\r\n        return point(*this) += rhs;\r\n    }\r\
    \n\r\n    point operator-(const point rhs) const noexcept {\r\n        return\
    \ point(*this) -= rhs;\r\n    }\r\n\r\n    point operator*(const double rhs) const\
    \ noexcept {\r\n        return point(*this) *= rhs;\r\n    }\r\n\r\n    point\
    \ operator/(const double rhs) const {\r\n        return point(*this) /= rhs;\r\
    \n    }\r\n\r\n    double abs() const noexcept {\r\n        return std::sqrt(internal::add(x*x,\
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
    }\n"
  code: "#pragma once\r\n\r\n#include <cmath>\r\n#include <cassert>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nconstexpr double EPS = 1e-10;\r\n\r\nnamespace internal {\r\n\r\
    \nint sgn(double a) {\r\n    return (a<-EPS) ? -1 : (a>EPS) ? 1 : 0;\r\n}\r\n\r\
    \ndouble add(double a, double b) {\r\n    if(std::abs(a+b) < EPS*(std::abs(a)\
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
    \ point &p) {\r\n        return proj(p)*double(2) - p;\r\n    }\r\n};\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/template.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:17:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/point.test.cpp
documentation_of: geometry/template.hpp
layout: document
redirect_from:
- /library/geometry/template.hpp
- /library/geometry/template.hpp.html
title: geometry/template.hpp
---
