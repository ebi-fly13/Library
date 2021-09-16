---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':question:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':question:'
    path: geometry/point.hpp
    title: point
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B
  bundledCode: "#line 1 \"test/geometry/incircle_of_triangle.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <algorithm>\n#include <cassert>\n#include\
    \ <iomanip>\n#include <cstdint>\n\n#line 2 \"geometry/circle.hpp\"\n\n#line 2\
    \ \"geometry/point.hpp\"\n\r\n#include <cmath>\r\n#line 8 \"geometry/point.hpp\"\
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
    \n    }\r\n};\r\n\r\nstd::ostream& operator<<(std::ostream& os, const point &a)\
    \ {\r\n    return os << a.x << \" \" << a.y;\r\n}\r\n\r\nlong double dot(const\
    \ point &a, const point &b) {\r\n    return a.dot(b);\r\n}\r\n\r\nlong double\
    \ det(const point &a, const point &b) {\r\n    return a.det(b);\r\n}\r\n\r\nlong\
    \ double abs(const point &a) {\r\n    return a.abs();\r\n}\r\n\r\nlong double\
    \ norm(const point &a) {\r\n    return internal::add(a.x*a.x, a.y*a.y);\r\n}\r\
    \n\r\nint isp(const point &a, const point &b, const point &c) {\r\n    int flag\
    \ = internal::sgn(det(b-a,c-a));\r\n    if(flag == 0) {\r\n        if(internal::sgn(dot(b-a,\
    \ c-a))<0) return -2;\r\n        if(internal::sgn(dot(a-b, c-b))<0) return +2;\r\
    \n    }\r\n    return flag;\r\n}\r\n\r\n// \u5206\u5272\u7D71\u6CBB\u3067\u6700\
    \u8FD1\u70B9\u5BFE\u3092\u6C42\u3081\u308B O(N log N)\r\nlong double closest_pair(std::vector<point>\
    \ p) {\r\n    std::sort(p.begin(), p.end());\r\n    int n = p.size();\r\n    auto\
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
    \ {\n        return distance(a, b.a);\n    }\n}\n\n}\n#line 5 \"geometry/circle.hpp\"\
    \n\nnamespace ebi {\n\nstruct circle {\n    point c;\n    long double r;\n   \
    \ circle() = default;\n    circle(const point &c, long double r) : c(c), r(r)\
    \ { } \n};\n\nint intersection(const circle &c1, const circle &c2) {\n    long\
    \ double d = abs(c1.c - c2.c);\n    long double r1 = c1.r, r2 = c2.r;\n    if(r1\
    \ < r2) std::swap(r1, r2); \n    if(d > internal::add(r1, r2)) {\n        return\
    \ 4;\n    }\n    else if(d == internal::add(r1, r2)) {\n        return 3;\n  \
    \  }\n    else if(d > internal::add(r1, -r2)) {\n        return 2;\n    }\n  \
    \  else if(d == internal::add(r1, -r2)) {\n        return 1;\n    }\n    else\
    \ {\n        return 0;\n    }\n}\n\ncircle incircle_of_triangle(const point &A,\
    \ const point &B, const point &C) {\n    long double a = abs(B-C), b = abs(C-A),\
    \ c = abs(A-B);\n    point in = A * a + B * b + C * c;\n    in /= (a + b + c);\n\
    \    long double r = distance(line(A, B), in);\n    return circle(in, r);\n}\n\
    \n}\n#line 11 \"test/geometry/incircle_of_triangle.test.cpp\"\n\nnamespace ebi\
    \ {\n\nusing i64 = std::int64_t;\n\nvoid main_() {\n    point a, b, c;\n    std::cin\
    \ >> a.x >> a.y;\n    std::cin >> b.x >> b.y;\n    std::cin >> c.x >> c.y;\n \
    \   circle in = incircle_of_triangle(a, b, c);\n    std::cout << in.c << \" \"\
    \ << in.r << '\\n';\n}\n\n}\n\nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    ebi::main_();\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include <iomanip>\n#include <cstdint>\n\n#include \"geometry/circle.hpp\"\n\n\
    namespace ebi {\n\nusing i64 = std::int64_t;\n\nvoid main_() {\n    point a, b,\
    \ c;\n    std::cin >> a.x >> a.y;\n    std::cin >> b.x >> b.y;\n    std::cin >>\
    \ c.x >> c.y;\n    circle in = incircle_of_triangle(a, b, c);\n    std::cout <<\
    \ in.c << \" \" << in.r << '\\n';\n}\n\n}\n\nint main() {\n    std::cout << std::fixed\
    \ << std::setprecision(15);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    ebi::main_();\n}"
  dependsOn:
  - geometry/circle.hpp
  - geometry/point.hpp
  - geometry/line.hpp
  isVerificationFile: true
  path: test/geometry/incircle_of_triangle.test.cpp
  requiredBy: []
  timestamp: '2021-09-16 12:50:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/geometry/incircle_of_triangle.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/incircle_of_triangle.test.cpp
- /verify/test/geometry/incircle_of_triangle.test.cpp.html
title: test/geometry/incircle_of_triangle.test.cpp
---
