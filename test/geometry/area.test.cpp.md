---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line_segment.hpp
    title: geometry/line_segment.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: point
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A
  bundledCode: "#line 1 \"test/geometry/area.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <iomanip>\n\
    \n#line 2 \"geometry/point.hpp\"\n\r\n#include <cmath>\r\n#include <cassert>\r\
    \n#line 6 \"geometry/point.hpp\"\n\r\nnamespace ebi {\r\n\r\nconstexpr long double\
    \ EPS = 1e-10;\r\n\r\nnamespace internal {\r\n\r\nint sgn(long double a) {\r\n\
    \    return (a<-EPS) ? -1 : (a>EPS) ? 1 : 0;\r\n}\r\n\r\nlong double add(long\
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
    \n    }\r\n    return flag;\r\n}\r\n\r\n}\n#line 2 \"geometry/line.hpp\"\n\n#line\
    \ 5 \"geometry/line.hpp\"\n\n#line 7 \"geometry/line.hpp\"\n\nnamespace ebi {\n\
    \nstruct line {\n    point a,b;\n\n    line(long double x1, long double y1, long\
    \ double x2, long double y2) : a(x1, y1), b(x2, y2) { }\n\n    line(const point\
    \ &a, const point &b) : a(a), b(b) { }\n\n    point proj(const point &p) const\
    \ {\n        return a + (b-a)*(dot(b-a,p-a)/norm(b-a));\n    }\n\n    point relf(const\
    \ point &p) const {\n        return proj(p)*double(2) - p;\n    }\n\n    long\
    \ double distance(const point &c) const {\n    return std::abs(det(c - a, b -\
    \ a)/abs(b-a));\n    }\n};\n\nint intersection(const line &a, const line &b) {\n\
    \    if(internal::sgn(det(a.b-a.a, b.a-b.b)) != 0) {\n        if(internal::sgn(dot(a.b-a.a,\
    \ b.b-b.a)) == 0) { // \u5782\u76F4\n            return 1;\n        }\n      \
    \  return 0; // \u4EA4\u5DEE\n    }\n    else if(internal::sgn(det(a.b-a.a, b.a-a.a))\
    \ != 0) { // \u5E73\u884C\n        return 2;\n    }\n    else { // \u540C\u4E00\
    \u76F4\u7DDA\n        return 3;\n    }\n}\n\npoint cross_point(const point &a,\
    \ const point &b, const point &c, const point &d) {\n    return a + (b-a) * det(c\
    \ - a, d - c) / det(b - a, d - c);\n}\n\n// \u4EA4\u70B9\u304C\u3042\u308B\u304B\
    \u78BA\u8A8D\u3059\u308B\uFF01\npoint cross_point(const line &s, const line &t)\
    \ {\n    assert(intersection(s, t) < 2);\n    return s.a + (s.b - s.a) * det(t.a\
    \ - s.a, t.b - t.a) / det(s.b - s.a, t.b - t.a);\n}\n\n// \u76F4\u7DDAa\u3068\u70B9\
    c\u306E\u8DDD\u96E2\nlong double distance(const line &a, const point &c) {\n \
    \   return std::abs(det(c-a.a, a.b - a.a)/abs(a.b-a.a));\n}\n\nlong double distance(const\
    \ line &a, const line &b) {\n    if(intersection(a, b) < 2) {\n        return\
    \ 0;\n    }\n    else {\n        return distance(a, b.a);\n    }\n}\n\n}\n#line\
    \ 2 \"geometry/line_segment.hpp\"\n\n#line 5 \"geometry/line_segment.hpp\"\n\n\
    #line 8 \"geometry/line_segment.hpp\"\n\nnamespace ebi {\n\nstruct line_segment\
    \ {\n    point a, b;\n\n    line_segment(long double x1, long double y1, long\
    \ double x2, long double y2) : a(x1, y1), b(x2, y2) { }\n\n    line_segment(point\
    \ &a, point &b) : a(a), b(b) { }\n};\n\n// \u7DDA\u5206ab, cd \u304C\u4EA4\u308F\
    \u308B\u304B\u5224\u5B9A\nbool intersection_line_segment(const point &a, const\
    \ point &b, const point &c, const point &d) {\n    if(internal::sgn(isp(a,b,c)*isp(a,b,d))\
    \ <= 0 && internal::sgn(isp(c,d,a)*isp(c,d,b)) <= 0) {\n        return true;\n\
    \    }\n    return false;\n}\n\n// \u7DDA\u5206ab, cd \u304C\u4EA4\u308F\u308B\
    \u304B\u5224\u5B9A\nbool intersection(const line_segment &a, const line_segment\
    \ &b) {\n    return intersection_line_segment(a.a, a.b, b.a, b.b);\n}\n\nbool\
    \ intersection(const line &a, const line_segment &b) {\n    if(internal::sgn(det(b.a\
    \ - a.a, a.b)) * internal::sgn(det(b.b - a.a, a.b)) < 0) {\n        return true;\n\
    \    }\n    else {\n        return false;\n    }\n}\n\nlong double distance(const\
    \ line_segment &a, const point &c) {\n    if(internal::sgn(dot(a.b - a.a, c -\
    \ a.a)) < 0) {\n        return abs(c-a.a);\n    }\n    else if(internal::sgn(dot(a.a\
    \ - a.b, c - a.b)) < 0) {\n        return abs(c-a.b);\n    }\n    else {\n   \
    \     return std::abs(det(c - a.a, a.b - a.a)/abs(a.b-a.a));\n    }\n}\n\nlong\
    \ double distance(const line_segment &a, const line_segment &b) {\n    if(intersection(a,\
    \ b)) {\n        return 0;\n    }\n    else {\n        return std::min(std::min(distance(a,\
    \ b.a), distance(a, b.b)), std::min(distance(b, a.a), distance(b, a.b)));\n  \
    \  }\n}\n\nlong double distance(const line &a, const line_segment &b) {\n    if(intersection(a,\
    \ b)) {\n        return 0;\n    }\n    else {\n        return std::min(distance(a,\
    \ b.a), distance(a, b.b));\n    }\n}\n\n}\n#line 2 \"geometry/polygon.hpp\"\n\n\
    #line 5 \"geometry/polygon.hpp\"\n\n#line 7 \"geometry/polygon.hpp\"\n\nnamespace\
    \ ebi {\n\nlong double area(const std::vector<point> &p) {\n    long double s\
    \ = 0;\n    int n = p.size();\n    for(int i = 0; i < n; i++) {\n        s = internal::add(s,\
    \ det(p[i], p[(i+1 != n) ? i+1 : 0]));\n    }\n    s /= 2.0;\n    return s;\n\
    }\n\n// \u51F8\u591A\u89D2\u5F62\u304B\u5224\u5B9A. p\u306B\u53CD\u6642\u8A08\u56DE\
    \u308A\u3067\u70B9\u304C\u5165\u3063\u3066\u3044\u308B\u3068\u4EEE\u5B9A\nbool\
    \ is_convex(const std::vector<point> &p) {\n    int n = p.size();\n    for(int\
    \ i = 0; i < n; i++) {\n        if(isp(p[i], p[(i+1 != n) ? i+1 : 0], p[(i+2 <\
    \ n) ? i+2 : (i+2)%n]) == -1) {\n            return false;\n        }\n    }\n\
    \    return true;\n}\n\n}\n#line 12 \"test/geometry/area.test.cpp\"\n\nnamespace\
    \ ebi {\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::vector<point>\
    \ p(n);\n    for(auto &[x, y]: p) {\n        std::cin >> x >> y;\n    }\n    std::cout\
    \ << area(p) << '\\n';\n}\n\n}\n\nint main() {\n    std::cout << std::fixed <<\
    \ std::setprecision(1);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    ebi::main_();\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <iomanip>\n\
    \n#include \"geometry/point.hpp\"\n#include \"geometry/line.hpp\"\n#include \"\
    geometry/line_segment.hpp\"\n#include  \"geometry/polygon.hpp\"\n\nnamespace ebi\
    \ {\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::vector<point>\
    \ p(n);\n    for(auto &[x, y]: p) {\n        std::cin >> x >> y;\n    }\n    std::cout\
    \ << area(p) << '\\n';\n}\n\n}\n\nint main() {\n    std::cout << std::fixed <<\
    \ std::setprecision(1);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    ebi::main_();\n}"
  dependsOn:
  - geometry/point.hpp
  - geometry/line.hpp
  - geometry/line_segment.hpp
  - geometry/polygon.hpp
  isVerificationFile: true
  path: test/geometry/area.test.cpp
  requiredBy: []
  timestamp: '2021-09-15 01:40:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/area.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/area.test.cpp
- /verify/test/geometry/area.test.cpp.html
title: test/geometry/area.test.cpp
---
