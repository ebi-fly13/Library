---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/intersection.hpp
    title: geometry/intersection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/isp.hpp
    title: isp
  - icon: ':heavy_check_mark:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
  bundledCode: "#line 1 \"test/intersection.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B\"\
    \r\n\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <limits>\r\n#include\
    \ <vector>\r\n\r\n#line 2 \"geometry/template.hpp\"\n\r\n#include <cmath>\r\n\
    #include <cassert>\r\n\r\nnamespace ebi {\r\n\r\nconstexpr double EPS = 1e-10;\r\
    \n\r\nnamespace internal {\r\n\r\nint sgn(double a) {\r\n    return (a<-EPS) ?\
    \ -1 : (a>EPS) ? 1 : 0;\r\n}\r\n\r\ndouble add(double a, double b) {\r\n    if(std::abs(a+b)\
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
    }\n#line 2 \"geometry/intersection.hpp\"\n\r\n#line 2 \"geometry/isp.hpp\"\n\r\
    \n#line 4 \"geometry/isp.hpp\"\n\r\nnamespace ebi {\r\n\r\nint isp(const point\
    \ &a, const point &b, const point &c) {\r\n    int flag = internal::sgn(det(b-a,c-a));\r\
    \n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a, c-a))<0) return -2;\r\
    \n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\n    }\r\n    return\
    \ flag;\r\n}\r\n\r\n}\n#line 5 \"geometry/intersection.hpp\"\n\r\nnamespace ebi\
    \ {\r\n\r\nbool intersection(const point &a, const point &b, const point &c, const\
    \ point &d) {\r\n    if(isp(a,b,c)*isp(a,b,d) <= 0 && isp(c,d,a)*isp(c,d,b) <=\
    \ 0) {\r\n        return true;\r\n    }\r\n    return false;\r\n}\r\n\r\n}\n#line\
    \ 10 \"test/intersection.test.cpp\"\n\r\nint main() {\r\n    std::cout << std::fixed\
    \ << std::setprecision(15);\r\n    int q;\r\n    std::cin >> q;\r\n    while(q--)\
    \ {\r\n        double x,y;\r\n        std::vector<ebi::point> p(4);\r\n      \
    \  for(int i = 0; i<4; i++) {\r\n            std::cin >> x >> y;\r\n         \
    \   p[i] = ebi::point(x,y);\r\n        }\r\n        if(ebi::intersection(p[0],p[1],p[2],p[3]))\
    \ {\r\n            std::cout << 1 << std::endl;\r\n        }\r\n        else {\r\
    \n            std::cout << 0 << std::endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B\"\
    \r\n\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <limits>\r\n#include\
    \ <vector>\r\n\r\n#include \"../geometry/template.hpp\"\r\n#include \"../geometry/intersection.hpp\"\
    \r\n\r\nint main() {\r\n    std::cout << std::fixed << std::setprecision(15);\r\
    \n    int q;\r\n    std::cin >> q;\r\n    while(q--) {\r\n        double x,y;\r\
    \n        std::vector<ebi::point> p(4);\r\n        for(int i = 0; i<4; i++) {\r\
    \n            std::cin >> x >> y;\r\n            p[i] = ebi::point(x,y);\r\n \
    \       }\r\n        if(ebi::intersection(p[0],p[1],p[2],p[3])) {\r\n        \
    \    std::cout << 1 << std::endl;\r\n        }\r\n        else {\r\n         \
    \   std::cout << 0 << std::endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - geometry/template.hpp
  - geometry/intersection.hpp
  - geometry/isp.hpp
  isVerificationFile: true
  path: test/intersection.test.cpp
  requiredBy: []
  timestamp: '2021-02-14 18:21:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/intersection.test.cpp
layout: document
redirect_from:
- /verify/test/intersection.test.cpp
- /verify/test/intersection.test.cpp.html
title: test/intersection.test.cpp
---
