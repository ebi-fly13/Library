---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/all.hpp\"\n\r\n#include <cmath>\r\n#include <cassert>\r\
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
    \ {\r\n    return internal::add(a.x*a.x, a.y*a.y);\r\n}\r\n\r\nint isp(const point\
    \ &a, const point &b, const point &c) {\r\n    int flag = internal::sgn(det(b-a,c-a));\r\
    \n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a, c-a))<0) return -2;\r\
    \n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\n    }\r\n    return\
    \ flag;\r\n}\r\n\r\nbool intersection(const point &a, const point &b, const point\
    \ &c, const point &d) {\r\n    if(isp(a,b,c)*isp(a,b,d) <= 0 && isp(c,d,a)*isp(c,d,b)\
    \ <= 0) {\r\n        return true;\r\n    }\r\n    return false;\r\n}\r\n\r\nstruct\
    \ line {\r\n    point a,b;\r\n\r\n    line(double x1, double y1, double x2, double\
    \ y2) : a(x1, y1), b(x2, y2) { }\r\n\r\n    point proj(const point &p) {\r\n \
    \       return a + (b-a)*(dot(b-a,p-a)/norm(b-a));\r\n    }\r\n\r\n    point relf(const\
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
    \ {\r\n    return internal::add(a.x*a.x, a.y*a.y);\r\n}\r\n\r\nint isp(const point\
    \ &a, const point &b, const point &c) {\r\n    int flag = internal::sgn(det(b-a,c-a));\r\
    \n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a, c-a))<0) return -2;\r\
    \n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\n    }\r\n    return\
    \ flag;\r\n}\r\n\r\nbool intersection(const point &a, const point &b, const point\
    \ &c, const point &d) {\r\n    if(isp(a,b,c)*isp(a,b,d) <= 0 && isp(c,d,a)*isp(c,d,b)\
    \ <= 0) {\r\n        return true;\r\n    }\r\n    return false;\r\n}\r\n\r\nstruct\
    \ line {\r\n    point a,b;\r\n\r\n    line(double x1, double y1, double x2, double\
    \ y2) : a(x1, y1), b(x2, y2) { }\r\n\r\n    point proj(const point &p) {\r\n \
    \       return a + (b-a)*(dot(b-a,p-a)/norm(b-a));\r\n    }\r\n\r\n    point relf(const\
    \ point &p) {\r\n        return proj(p)*double(2) - p;\r\n    }\r\n};\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/all.hpp
  requiredBy: []
  timestamp: '2021-02-14 18:21:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/all.hpp
layout: document
redirect_from:
- /library/geometry/all.hpp
- /library/geometry/all.hpp.html
title: geometry/all.hpp
---
