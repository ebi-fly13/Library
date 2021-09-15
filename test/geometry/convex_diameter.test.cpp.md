---
data:
  _extendedDependsOn:
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
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B
  bundledCode: "#line 1 \"test/geometry/convex_diameter.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B\"\n#define\
    \ ERROR 0.00000001\n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\n#include <iomanip>\n#include <cstdint>\n\n#line 2 \"geometry/point.hpp\"\
    \n\r\n#include <cmath>\r\n#line 6 \"geometry/point.hpp\"\n\r\nnamespace ebi {\r\
    \n\r\nconstexpr long double EPS = 1e-10;\r\n\r\nnamespace internal {\r\n\r\nint\
    \ sgn(long double a) {\r\n    return (a<-EPS) ? -1 : (a>EPS) ? 1 : 0;\r\n}\r\n\
    \r\nlong double add(long double a, long double b) {\r\n    if(std::abs(a+b) <\
    \ EPS*(std::abs(a) + std::abs(b))) return 0;\r\n    return a+b;\r\n}\r\n\r\n}\
    \ // namespace internal\r\n\r\nstruct point {\r\n    long double x,y;\r\n\r\n\
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
    \n    }\r\n    return flag;\r\n}\r\n\r\n}\n#line 2 \"geometry/polygon.hpp\"\n\n\
    #line 5 \"geometry/polygon.hpp\"\n\n#line 7 \"geometry/polygon.hpp\"\n\nnamespace\
    \ ebi {\n\nusing Polygon = std::vector<point>;\n\nlong double area(const Polygon\
    \ &poly) {\n    long double s = 0;\n    int n = poly.size();\n    for(int i =\
    \ 0; i < n; i++) {\n        s = internal::add(s, det(poly[i], poly[(i+1 != n)\
    \ ? i+1 : 0]));\n    }\n    s /= 2.0;\n    return s;\n}\n\n// \u51F8\u591A\u89D2\
    \u5F62\u304B\u5224\u5B9A. p\u306B\u53CD\u6642\u8A08\u56DE\u308A\u3067\u70B9\u304C\
    \u5165\u3063\u3066\u3044\u308B\u3068\u4EEE\u5B9A\nbool is_convex(const Polygon\
    \ &poly) {\n    int n = poly.size();\n    for(int i = 0; i < n; i++) {\n     \
    \   if(isp(poly[i], poly[(i+1 != n) ? i+1 : 0], poly[(i+2 < n) ? i+2 : (i+2)%n])\
    \ == -1) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    \nenum {\n    OUT, ON, IN\n};\n\nint contains(const Polygon &poly, const point\
    \ &p) {\n    bool in = false;\n    int n = poly.size();\n    for(int i = 0; i\
    \ < n; i++) {\n        point a = poly[i] - p;\n        point b = poly[(i+1 < n)\
    \ ? i+1 : 0] - p;\n        if(a.y > b.y) std::swap(a, b);\n        if(a.y <= 0\
    \ && 0 < b.y && det(a, b) < 0) in = !in;\n        if(det(a, b) == 0 && dot(a,\
    \ b) <= 0) return ON;\n    }\n    return in ? IN : OUT;\n}\n\nlong double convex_diameter(const\
    \ Polygon &convex_poly) {\n    int n = convex_poly.size();\n    int is = 0, js\
    \ = 0;\n    for(int i = 1; i < n; i++) {\n        if(convex_poly[i].y > convex_poly[is].y)\
    \ is = i;\n        if(convex_poly[i].y < convex_poly[js].y) js = i;\n    }\n \
    \   long double max = (convex_poly[is]-convex_poly[js]).abs();\n    int i, max_i,\
    \ j, max_j;\n    i = max_i = is;\n    j = max_j = js;\n    do {\n        if(det(convex_poly[(i+1\
    \ < n) ? i+1 : 0] - convex_poly[i], convex_poly[(j+1 < n) ? j+1 : 0] - convex_poly[j])\
    \ >= 0) {\n            j = (j+1 < n) ? j+1 : 0;\n        }\n        else {\n \
    \           i = (i+1 < n) ? i+1 : 0;\n        }\n        if((convex_poly[i] -\
    \ convex_poly[j]).abs() > max) {\n            max = (convex_poly[i] - convex_poly[j]).abs();\n\
    \            max_i = i;\n            max_j = j;\n        }\n    } while(i != is\
    \ || j != js);\n    return max;\n}\n\n}\n#line 13 \"test/geometry/convex_diameter.test.cpp\"\
    \n\nnamespace ebi {\n\nusing i64 = std::int64_t;\n\nvoid main_() {\n    int n;\n\
    \    std::cin >> n;\n    std::vector<point> poly(n);\n    for(auto &[x, y]: poly)\
    \ {\n        std::cin >> x >> y;\n    }\n    std::cout << convex_diameter(poly)\
    \ << '\\n';\n}\n\n}\n\nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    ebi::main_();\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B\"\
    \n#define ERROR 0.00000001\n\n#include <iostream>\n#include <vector>\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iomanip>\n#include <cstdint>\n\n\
    #include \"geometry/point.hpp\"\n#include \"geometry/polygon.hpp\"\n\nnamespace\
    \ ebi {\n\nusing i64 = std::int64_t;\n\nvoid main_() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<point> poly(n);\n    for(auto &[x, y]: poly) {\n    \
    \    std::cin >> x >> y;\n    }\n    std::cout << convex_diameter(poly) << '\\\
    n';\n}\n\n}\n\nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    ebi::main_();\n\
    }"
  dependsOn:
  - geometry/point.hpp
  - geometry/polygon.hpp
  isVerificationFile: true
  path: test/geometry/convex_diameter.test.cpp
  requiredBy: []
  timestamp: '2021-09-15 15:38:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/convex_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/convex_diameter.test.cpp
- /verify/test/geometry/convex_diameter.test.cpp.html
title: test/geometry/convex_diameter.test.cpp
---
