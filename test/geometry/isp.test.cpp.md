---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
  bundledCode: "#line 1 \"test/geometry/isp.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\"\
    \r\n\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <limits>\r\n\r\n\
    #line 2 \"geometry/point.hpp\"\n\r\n#include <cmath>\r\n#include <cassert>\r\n\
    #include <vector>\r\n\r\nnamespace ebi {\r\n\r\nconstexpr long double EPS = 1e-10;\r\
    \n\r\nnamespace internal {\r\n\r\nint sgn(long double a) {\r\n    return (a<-EPS)\
    \ ? -1 : (a>EPS) ? 1 : 0;\r\n}\r\n\r\nlong double add(long double a, long double\
    \ b) {\r\n    if(std::abs(a+b) < EPS*(std::abs(a) + std::abs(b))) return 0;\r\n\
    \    return a+b;\r\n}\r\n\r\n} // namespace internal\r\n\r\nstruct point {\r\n\
    \    long double x,y;\r\n\r\n    point() = default;\r\n\r\n    point(long double\
    \ x, long double y) : x(x), y(y) { }\r\n\r\n    point &operator+=(const point\
    \ rhs) noexcept {\r\n        x = internal::add(x, rhs.x);\r\n        y = internal::add(y,\
    \ rhs.y);\r\n        return *this;\r\n    }\r\n\r\n    point &operator-=(const\
    \ point rhs) noexcept {\r\n        x = internal::add(x, -rhs.x);\r\n        y\
    \ = internal::add(y, -rhs.y);\r\n        return *this;\r\n    }\r\n\r\n    point\
    \ &operator*=(const long double k) noexcept {\r\n        x *= k;\r\n        y\
    \ *= k;\r\n        return *this;\r\n    }\r\n\r\n    point &operator/=(const long\
    \ double k) {\r\n        assert(internal::sgn(k)!=0);\r\n        x /= k;\r\n \
    \       y /= k;\r\n        return *this;\r\n    }\r\n\r\n    point operator+(const\
    \ point &rhs) const noexcept {\r\n        return point(*this) += rhs;\r\n    }\r\
    \n\r\n    point operator-(const point &rhs) const noexcept {\r\n        return\
    \ point(*this) -= rhs;\r\n    }\r\n\r\n    point operator*(const long double rhs)\
    \ const noexcept {\r\n        return point(*this) *= rhs;\r\n    }\r\n\r\n   \
    \ point operator/(const long double rhs) const {\r\n        return point(*this)\
    \ /= rhs;\r\n    }\r\n\r\n    point operator-() const noexcept {\r\n        return\
    \ point(0, 0) - *this;\r\n    }\r\n\r\n    long double abs() const noexcept {\r\
    \n        return std::sqrt(internal::add(x*x, y*y));\r\n    }\r\n\r\n    long\
    \ double dot(const point rhs) const noexcept {\r\n        return internal::add(x*rhs.x,\
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
    \n    }\r\n    return flag;\r\n}\r\n\r\n}\n#line 8 \"test/geometry/isp.test.cpp\"\
    \n\r\nint main() {\r\n    std::cout << std::fixed << std::setprecision(15);\r\n\
    \    double x1,y1,x2,y2;\r\n    std::cin >> x1 >> y1 >> x2 >> y2;\r\n    ebi::point\
    \ p0(x1, y1), p1(x2, y2);\r\n    int q;\r\n    std::cin >> q;\r\n    while(q--)\
    \ {\r\n        double x,y;\r\n        std::cin >> x >> y;\r\n        int flag\
    \ = ebi::isp(p0, p1, ebi::point(x,y));\r\n        std::string ans;\r\n       \
    \ if(flag == 1) {\r\n            ans = \"COUNTER_CLOCKWISE\";\r\n        }\r\n\
    \        else if(flag == -1) {\r\n            ans = \"CLOCKWISE\";\r\n       \
    \ }\r\n        else if(flag == -2) {\r\n            ans = \"ONLINE_BACK\";\r\n\
    \        }\r\n        else if(flag == 2) {\r\n            ans = \"ONLINE_FRONT\"\
    ;\r\n        }\r\n        else {\r\n            ans = \"ON_SEGMENT\";\r\n    \
    \    }\r\n        std::cout << ans << std::endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\"\
    \r\n\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <limits>\r\n\r\n\
    #include \"geometry/point.hpp\"\r\n\r\nint main() {\r\n    std::cout << std::fixed\
    \ << std::setprecision(15);\r\n    double x1,y1,x2,y2;\r\n    std::cin >> x1 >>\
    \ y1 >> x2 >> y2;\r\n    ebi::point p0(x1, y1), p1(x2, y2);\r\n    int q;\r\n\
    \    std::cin >> q;\r\n    while(q--) {\r\n        double x,y;\r\n        std::cin\
    \ >> x >> y;\r\n        int flag = ebi::isp(p0, p1, ebi::point(x,y));\r\n    \
    \    std::string ans;\r\n        if(flag == 1) {\r\n            ans = \"COUNTER_CLOCKWISE\"\
    ;\r\n        }\r\n        else if(flag == -1) {\r\n            ans = \"CLOCKWISE\"\
    ;\r\n        }\r\n        else if(flag == -2) {\r\n            ans = \"ONLINE_BACK\"\
    ;\r\n        }\r\n        else if(flag == 2) {\r\n            ans = \"ONLINE_FRONT\"\
    ;\r\n        }\r\n        else {\r\n            ans = \"ON_SEGMENT\";\r\n    \
    \    }\r\n        std::cout << ans << std::endl;\r\n    }\r\n}"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: true
  path: test/geometry/isp.test.cpp
  requiredBy: []
  timestamp: '2021-09-15 01:14:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/isp.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/isp.test.cpp
- /verify/test/geometry/isp.test.cpp.html
title: test/geometry/isp.test.cpp
---
