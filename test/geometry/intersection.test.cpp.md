---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: point
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A
  bundledCode: "#line 1 \"test/geometry/intersection.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <iomanip>\r\
    \n\r\n#line 2 \"geometry/point.hpp\"\n\r\n#include <cmath>\r\n#include <cassert>\r\
    \n#line 8 \"geometry/point.hpp\"\n\r\nnamespace ebi {\r\n\r\nconstexpr long double\
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
    \n        return internal::sgn(y-rhs.y)<0;\r\n    }\r\n};\r\n\r\nstd::ostream&\
    \ operator<<(std::ostream& os, const point &a) {\r\n    return os << a.x << \"\
    \ \" << a.y;\r\n}\r\n\r\nstd::istream& operator>>(std::istream& os, point &a)\
    \ {\r\n    return os >> a.x >> a.y;\r\n}\r\n\r\n// \u70B9a \u3092ang(\u30E9\u30B8\
    \u30A2\u30F3)\u56DE\u8EE2\u3059\u308B\r\npoint rot(const point &a, long double\
    \ ang) {\r\n    return point(std::cos(ang) * a.x - std::sin(ang) * a.y, std::sin(ang)\
    \ * a.x + std::cos(ang) * a.y);\r\n} \r\n\r\npoint rot90(const point &a) {\r\n\
    \    return point(-a.y, a.x);\r\n}\r\n\r\nlong double dot(const point &a, const\
    \ point &b) {\r\n    return a.dot(b);\r\n}\r\n\r\nlong double det(const point\
    \ &a, const point &b) {\r\n    return a.det(b);\r\n}\r\n\r\nlong double abs(const\
    \ point &a) {\r\n    return a.abs();\r\n}\r\n\r\nlong double norm(const point\
    \ &a) {\r\n    return internal::add(a.x*a.x, a.y*a.y);\r\n}\r\n\r\nint isp(const\
    \ point &a, const point &b, const point &c) {\r\n    int flag = internal::sgn(det(b-a,c-a));\r\
    \n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a, c-a))<0) return -2;\r\
    \n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\n    }\r\n    return\
    \ flag;\r\n}\r\n\r\n// \u5206\u5272\u7D71\u6CBB\u3067\u6700\u8FD1\u70B9\u5BFE\u3092\
    \u6C42\u3081\u308B O(N log N)\r\nlong double closest_pair(std::vector<point> p)\
    \ {\r\n    std::sort(p.begin(), p.end());\r\n    int n = p.size();\r\n    auto\
    \ f = [&](auto &&self, int l, int r) -> long double {\r\n        if(r-l == 1)\
    \ {\r\n            return 1e9;\r\n        }\r\n        int mid = (l+r)/2;\r\n\
    \        long double x = p[mid].x;\r\n        long double d = std::min(self(self,\
    \ l, mid), self(self, mid, r));\r\n        std::vector<point> b;\r\n        b.reserve(r-l);\r\
    \n        int j = mid;\r\n        for(int i = l; i < mid; i++) {\r\n         \
    \   while(j < r && p[j].y <= p[i].y) {\r\n                b.emplace_back(p[j++]);\r\
    \n            }\r\n            b.emplace_back(p[i]);\r\n        }\r\n        while(j\
    \ < r) {\r\n            b.emplace_back(p[j++]);\r\n        }\r\n        for(int\
    \ i = 0; i < r-l; i++) {\r\n            p[l+i] = b[i];\r\n        }\r\n      \
    \  b.clear();\r\n        for(int i = l; i < r; i++) {\r\n            if(std::abs(p[i].x\
    \ - x) >= d) continue;\r\n            for(int j = int(b.size())-1; j >= 0; j--)\
    \ {\r\n                if(p[i].y - b[j].y >= d) break;\r\n                d =\
    \ std::min(d, abs(p[i]-b[j]));\r\n            }\r\n            b.emplace_back(p[i]);\r\
    \n        }\r\n        return d;\r\n    };\r\n    return f(f, 0, n);\r\n}\r\n\r\
    \n}\n#line 2 \"geometry/line.hpp\"\n\n#line 5 \"geometry/line.hpp\"\n\n#line 7\
    \ \"geometry/line.hpp\"\n\nnamespace ebi {\n\nstruct line {\n    point a,b;\n\n\
    \    line(long double x1, long double y1, long double x2, long double y2) : a(x1,\
    \ y1), b(x2, y2) { }\n\n    line(const point &a, const point &b) : a(a), b(b)\
    \ { }\n\n    point proj(const point &p) const {\n        return a + (b-a)*(dot(b-a,p-a)/norm(b-a));\n\
    \    }\n\n    point relf(const point &p) const {\n        return proj(p)*double(2)\
    \ - p;\n    }\n\n    long double distance(const point &c) const {\n    return\
    \ std::abs(det(c - a, b - a)/abs(b-a));\n    }\n};\n\nint intersection(const line\
    \ &a, const line &b) {\n    if(internal::sgn(det(a.b-a.a, b.a-b.b)) != 0) {\n\
    \        if(internal::sgn(dot(a.b-a.a, b.b-b.a)) == 0) { // \u5782\u76F4\n   \
    \         return 1;\n        }\n        return 0; // \u4EA4\u5DEE\n    }\n   \
    \ else if(internal::sgn(det(a.b-a.a, b.a-a.a)) != 0) { // \u5E73\u884C\n     \
    \   return 2;\n    }\n    else { // \u540C\u4E00\u76F4\u7DDA\n        return 3;\n\
    \    }\n}\n\npoint cross_point(const point &a, const point &b, const point &c,\
    \ const point &d) {\n    return a + (b-a) * det(c - a, d - c) / det(b - a, d -\
    \ c);\n}\n\n// \u4EA4\u70B9\u304C\u3042\u308B\u304B\u78BA\u8A8D\u3059\u308B\uFF01\
    \npoint cross_point(const line &s, const line &t) {\n    assert(intersection(s,\
    \ t) < 2);\n    return s.a + (s.b - s.a) * det(t.a - s.a, t.b - t.a) / det(s.b\
    \ - s.a, t.b - t.a);\n}\n\n// \u76F4\u7DDAa\u3068\u70B9c\u306E\u8DDD\u96E2\nlong\
    \ double distance(const line &a, const point &c) {\n    return std::abs(det(c-a.a,\
    \ a.b - a.a)/abs(a.b-a.a));\n}\n\nlong double distance(const line &a, const line\
    \ &b) {\n    if(intersection(a, b) < 2) {\n        return 0;\n    }\n    else\
    \ {\n        return distance(a, b.a);\n    }\n}\n\n}\n#line 10 \"test/geometry/intersection.test.cpp\"\
    \n\r\nnamespace ebi {\r\n\r\nvoid main_() {\r\n    int q;\r\n    std::cin >> q;\r\
    \n    while(q--) {\r\n        point p0, p1, p2, p3;\r\n        std::cin >> p0.x\
    \ >> p0.y >> p1.x >> p1.y;\r\n        std::cin >> p2.x >> p2.y >> p3.x >> p3.y;\r\
    \n        line s1(p0, p1);\r\n        line s2(p2, p3);\r\n        int flag = intersection(s1,\
    \ s2);\r\n        if(flag == 3) flag = 2;\r\n        std::cout << flag << '\\\
    n';\r\n    }\r\n}\r\n\r\n}\r\n\r\nint main() {\r\n    std::cout << std::fixed\
    \ << std::setprecision(15);\r\n    std::cin.tie(nullptr);\r\n    std::ios::sync_with_stdio(false);\r\
    \n    ebi::main_();\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#include\
    \ <iomanip>\r\n\r\n#include \"geometry/point.hpp\"\r\n#include \"geometry/line.hpp\"\
    \r\n\r\nnamespace ebi {\r\n\r\nvoid main_() {\r\n    int q;\r\n    std::cin >>\
    \ q;\r\n    while(q--) {\r\n        point p0, p1, p2, p3;\r\n        std::cin\
    \ >> p0.x >> p0.y >> p1.x >> p1.y;\r\n        std::cin >> p2.x >> p2.y >> p3.x\
    \ >> p3.y;\r\n        line s1(p0, p1);\r\n        line s2(p2, p3);\r\n       \
    \ int flag = intersection(s1, s2);\r\n        if(flag == 3) flag = 2;\r\n    \
    \    std::cout << flag << '\\n';\r\n    }\r\n}\r\n\r\n}\r\n\r\nint main() {\r\n\
    \    std::cout << std::fixed << std::setprecision(15);\r\n    std::cin.tie(nullptr);\r\
    \n    std::ios::sync_with_stdio(false);\r\n    ebi::main_();\r\n}"
  dependsOn:
  - geometry/point.hpp
  - geometry/line.hpp
  isVerificationFile: true
  path: test/geometry/intersection.test.cpp
  requiredBy: []
  timestamp: '2021-09-16 15:40:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/intersection.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/intersection.test.cpp
- /verify/test/geometry/intersection.test.cpp.html
title: test/geometry/intersection.test.cpp
---
