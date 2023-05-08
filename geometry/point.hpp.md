---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line_segment.hpp
    title: geometry/line_segment.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/area.test.cpp
    title: test/geometry/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/circumscribed_circle_of_triangle.test.cpp
    title: test/geometry/circumscribed_circle_of_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/closest_pair.test.cpp
    title: test/geometry/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/common_area.test.cpp
    title: test/geometry/common_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/common_area_circles.test.cpp
    title: test/geometry/common_area_circles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/common_tangent.test.cpp
    title: test/geometry/common_tangent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/contains.test.cpp
    title: test/geometry/contains.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/convex_diameter.test.cpp
    title: test/geometry/convex_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/convex_polygon_cut.test.cpp
    title: test/geometry/convex_polygon_cut.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/cross_point.test.cpp
    title: test/geometry/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/cross_points_of_circle_and_line.test.cpp
    title: test/geometry/cross_points_of_circle_and_line.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/cross_points_of_circles.test.cpp
    title: test/geometry/cross_points_of_circles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/distance.test.cpp
    title: test/geometry/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/incircle_of_triangle.test.cpp
    title: test/geometry/incircle_of_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersection.test.cpp
    title: test/geometry/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersection_circle.test.cpp
    title: test/geometry/intersection_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersection_line_segment.test.cpp
    title: test/geometry/intersection_line_segment.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/is_convex.test.cpp
    title: test/geometry/is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/isp.test.cpp
    title: test/geometry/isp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/reflection.test.cpp
    title: test/geometry/reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/tangent_to_circle.test.cpp
    title: test/geometry/tangent_to_circle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/point.hpp\"\n\r\n#include <algorithm>\r\n#include\
    \ <cassert>\r\n#include <cmath>\r\n#include <cstdint>\r\n#include <iostream>\r\
    \n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nconstexpr long double EPS =\
    \ 1e-10;\r\n\r\nconst long double PI = std::acos(-1);\r\n\r\nnamespace internal\
    \ {\r\n\r\nint sgn(long double a) {\r\n    return (a < -EPS) ? -1 : (a > EPS)\
    \ ? 1 : 0;\r\n}\r\n\r\nlong double add(long double a, long double b) {\r\n   \
    \ if (std::abs(a + b) < EPS * (std::abs(a) + std::abs(b))) return 0;\r\n    return\
    \ a + b;\r\n}\r\n\r\n}  // namespace internal\r\n\r\nlong double arg_to_radian(long\
    \ double arg) {\r\n    return PI * arg / (long double)(180);\r\n}\r\n\r\nstruct\
    \ point {\r\n    long double x, y;\r\n\r\n    point() = default;\r\n\r\n    point(long\
    \ double x, long double y) : x(x), y(y) {}\r\n\r\n    point &operator+=(const\
    \ point rhs) noexcept {\r\n        x = internal::add(x, rhs.x);\r\n        y =\
    \ internal::add(y, rhs.y);\r\n        return *this;\r\n    }\r\n\r\n    point\
    \ &operator-=(const point rhs) noexcept {\r\n        x = internal::add(x, -rhs.x);\r\
    \n        y = internal::add(y, -rhs.y);\r\n        return *this;\r\n    }\r\n\r\
    \n    point &operator*=(const point rhs) noexcept {\r\n        long double _x\
    \ = internal::add(x * rhs.x, -y * rhs.y);\r\n        long double _y = internal::add(x\
    \ * rhs.y, y * rhs.x);\r\n        x = _x;\r\n        y = _y;\r\n        return\
    \ *this;\r\n    }\r\n\r\n    point &operator*=(const long double k) noexcept {\r\
    \n        x *= k;\r\n        y *= k;\r\n        return *this;\r\n    }\r\n\r\n\
    \    point &operator/=(const long double k) {\r\n        assert(internal::sgn(k)\
    \ != 0);\r\n        x /= k;\r\n        y /= k;\r\n        return *this;\r\n  \
    \  }\r\n\r\n    point operator+(const point &rhs) const noexcept {\r\n       \
    \ return point(*this) += rhs;\r\n    }\r\n\r\n    point operator-(const point\
    \ &rhs) const noexcept {\r\n        return point(*this) -= rhs;\r\n    }\r\n\r\
    \n    point operator*(const point &rhs) const noexcept {\r\n        return point(*this)\
    \ *= rhs;\r\n    }\r\n\r\n    point operator*(const long double rhs) const noexcept\
    \ {\r\n        return point(*this) *= rhs;\r\n    }\r\n\r\n    point operator/(const\
    \ long double rhs) const {\r\n        return point(*this) /= rhs;\r\n    }\r\n\
    \r\n    point operator-() const noexcept {\r\n        return point(0, 0) - *this;\r\
    \n    }\r\n\r\n    long double abs() const noexcept {\r\n        return std::sqrt(internal::add(x\
    \ * x, y * y));\r\n    }\r\n\r\n    long double dot(const point rhs) const noexcept\
    \ {\r\n        return internal::add(x * rhs.x, y * rhs.y);\r\n    }\r\n\r\n  \
    \  long double det(const point rhs) const noexcept {\r\n        return internal::add(x\
    \ * rhs.y, -y * rhs.x);\r\n    }\r\n\r\n    // arctan(y/x) (\u5358\u4F4D\u306F\
    \u30E9\u30B8\u30A2\u30F3)\r\n    long double arg() const {\r\n        return std::atan2(y,\
    \ x);\r\n    }\r\n\r\n    // x\u6607\u9806, \u305D\u306E\u5F8Cy\u6607\u9806\r\n\
    \    bool operator<(const point &rhs) const noexcept {\r\n        if (internal::sgn(x\
    \ - rhs.x)) return internal::sgn(x - rhs.x) < 0;\r\n        return internal::sgn(y\
    \ - rhs.y) < 0;\r\n    }\r\n\r\n    bool operator==(const point &rhs) const noexcept\
    \ {\r\n        if (internal::sgn(x - rhs.x) == 0 && internal::sgn(y - rhs.y) ==\
    \ 0)\r\n            return true;\r\n        else\r\n            return false;\r\
    \n    }\r\n\r\n    bool operator!=(const point &rhs) const noexcept {\r\n    \
    \    return !((*this) == rhs);\r\n    }\r\n};\r\n\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const point &a) {\r\n    return os << a.x << \" \" << a.y;\r\n}\r\n\r\n\
    std::istream &operator>>(std::istream &os, point &a) {\r\n    return os >> a.x\
    \ >> a.y;\r\n}\r\n\r\npoint conj(const point &a) {\r\n    return point(a.x, -a.y);\r\
    \n}\r\n\r\n// \u70B9a \u3092ang(\u30E9\u30B8\u30A2\u30F3)\u56DE\u8EE2\u3059\u308B\
    \r\npoint rot(const point &a, long double ang) {\r\n    return point(std::cos(ang)\
    \ * a.x - std::sin(ang) * a.y,\r\n                 std::sin(ang) * a.x + std::cos(ang)\
    \ * a.y);\r\n}\r\n\r\npoint rot90(const point &a) {\r\n    return point(-a.y,\
    \ a.x);\r\n}\r\n\r\nlong double dot(const point &a, const point &b) {\r\n    return\
    \ a.dot(b);\r\n}\r\n\r\nlong double det(const point &a, const point &b) {\r\n\
    \    return a.det(b);\r\n}\r\n\r\nlong double abs(const point &a) {\r\n    return\
    \ a.abs();\r\n}\r\n\r\nlong double norm(const point &a) {\r\n    return internal::add(a.x\
    \ * a.x, a.y * a.y);\r\n}\r\n\r\nint isp(const point &a, const point &b, const\
    \ point &c) {\r\n    int flag = internal::sgn(det(b - a, c - a));\r\n    if (flag\
    \ == 0) {\r\n        if (internal::sgn(dot(b - a, c - a)) < 0) return -2;\r\n\
    \        if (internal::sgn(dot(a - b, c - b)) < 0) return +2;\r\n    }\r\n   \
    \ return flag;\r\n}\r\n\r\n// \u5206\u5272\u7D71\u6CBB\u3067\u6700\u8FD1\u70B9\
    \u5BFE\u3092\u6C42\u3081\u308B O(N log N)\r\nlong double closest_pair(std::vector<point>\
    \ p) {\r\n    std::sort(p.begin(), p.end());\r\n    int n = p.size();\r\n    auto\
    \ f = [&](auto &&self, int l, int r) -> long double {\r\n        if (r - l ==\
    \ 1) {\r\n            return 1e9;\r\n        }\r\n        int mid = (l + r) /\
    \ 2;\r\n        long double x = p[mid].x;\r\n        long double d = std::min(self(self,\
    \ l, mid), self(self, mid, r));\r\n        std::vector<point> b;\r\n        b.reserve(r\
    \ - l);\r\n        int j = mid;\r\n        for (int i = l; i < mid; i++) {\r\n\
    \            while (j < r && p[j].y <= p[i].y) {\r\n                b.emplace_back(p[j++]);\r\
    \n            }\r\n            b.emplace_back(p[i]);\r\n        }\r\n        while\
    \ (j < r) {\r\n            b.emplace_back(p[j++]);\r\n        }\r\n        for\
    \ (int i = 0; i < r - l; i++) {\r\n            p[l + i] = b[i];\r\n        }\r\
    \n        b.clear();\r\n        for (int i = l; i < r; i++) {\r\n            if\
    \ (std::abs(p[i].x - x) >= d) continue;\r\n            for (int j = int(b.size())\
    \ - 1; j >= 0; j--) {\r\n                if (p[i].y - b[j].y >= d) break;\r\n\
    \                d = std::min(d, abs(p[i] - b[j]));\r\n            }\r\n     \
    \       b.emplace_back(p[i]);\r\n        }\r\n        return d;\r\n    };\r\n\
    \    return f(f, 0, n);\r\n}\r\n\r\n// \u2220ABC\u3092\u6C42\u3081\u308B(\u30E9\
    \u30B8\u30A2\u30F3)\r\nlong double angle(const point &A, const point &B, const\
    \ point &C) {\r\n    long double a = (B - C).abs(), b = (C - A).abs(), c = (A\
    \ - B).abs();\r\n    long double cos =\r\n        internal::add(internal::add(a\
    \ * a, c * c), -b * b) / (2.0 * c * a);\r\n    return std::acos(cos);\r\n}\r\n\
    \r\n// \u7B26\u53F7\u4ED8\u304D\r\nlong double calc_ang(point a, point b, point\
    \ c) {\r\n    long double cos = dot((a - b), (c - b)) / (abs(a - b) * abs(c -\
    \ b));\r\n    long double sin = det((a - b), (c - b)) / (abs(a - b) * abs(c -\
    \ b));\r\n    return std::atan2(sin, cos);\r\n}\r\n\r\nvoid arg_sort(std::vector<point>\
    \ &a) {\r\n    int n = a.size();\r\n    std::vector ps(4, std::vector<point>());\r\
    \n    auto idx = [](point v) -> int {\r\n        if (v.y >= 0)\r\n           \
    \ return (v.x >= 0) ? 0 : 1;\r\n        else\r\n            return (v.x >= 0)\
    \ ? 3 : 2;\r\n    };\r\n    for (auto p : a) {\r\n        assert(!(p.x == 0 &&\
    \ p.y == 0));\r\n        ps[idx(p)].emplace_back(p);\r\n    }\r\n    a.clear();\r\
    \n    a.reserve(n);\r\n    for (int i = 0; i < 4; i++) {\r\n        std::sort(ps[i].begin(),\
    \ ps[i].end(), [](point &p1, point &p2) -> bool {\r\n            int flag = internal::sgn(internal::add(p1.x\
    \ * p2.y, -p2.x * p1.y));\r\n            return flag == 0 ? (norm(p1) < norm(p2))\
    \ : flag > 0;\r\n        });\r\n        for (auto &p : ps[i]) a.emplace_back(p);\r\
    \n    }\r\n    return;\r\n}\r\n\r\ntemplate <class T> void arg_sort_ll(std::vector<std::pair<T,\
    \ T>> &a) {\r\n    using Point = std::pair<T, T>;\r\n    int n = a.size();\r\n\
    \    std::vector ps(4, std::vector<Point>());\r\n    auto idx = [](Point v) ->\
    \ int {\r\n        if (v.second >= 0)\r\n            return (v.first >= 0) ? 0\
    \ : 1;\r\n        else\r\n            return (v.first >= 0) ? 3 : 2;\r\n    };\r\
    \n    for (auto p : a) {\r\n        assert(!(p.first == 0 && p.second == 0));\r\
    \n        ps[idx(p)].emplace_back(p);\r\n    }\r\n    a.clear();\r\n    a.reserve(n);\r\
    \n    for (int i = 0; i < 4; i++) {\r\n        std::sort(ps[i].begin(), ps[i].end(),\
    \ [](Point &p1, Point &p2) -> bool {\r\n            T flag = p1.first * p2.second\
    \ - p2.first * p1.second;\r\n            return flag == 0 ? (p1.first * p1.first\
    \ + p1.second * p1.second <\r\n                                p2.first * p2.first\
    \ + p2.second * p2.second)\r\n                             : flag > 0;\r\n   \
    \     });\r\n        for (auto &p : ps[i]) a.emplace_back(p);\r\n    }\r\n   \
    \ return;\r\n}\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <cassert>\r\n#include\
    \ <cmath>\r\n#include <cstdint>\r\n#include <iostream>\r\n#include <vector>\r\n\
    \r\nnamespace ebi {\r\n\r\nconstexpr long double EPS = 1e-10;\r\n\r\nconst long\
    \ double PI = std::acos(-1);\r\n\r\nnamespace internal {\r\n\r\nint sgn(long double\
    \ a) {\r\n    return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0;\r\n}\r\n\r\nlong double\
    \ add(long double a, long double b) {\r\n    if (std::abs(a + b) < EPS * (std::abs(a)\
    \ + std::abs(b))) return 0;\r\n    return a + b;\r\n}\r\n\r\n}  // namespace internal\r\
    \n\r\nlong double arg_to_radian(long double arg) {\r\n    return PI * arg / (long\
    \ double)(180);\r\n}\r\n\r\nstruct point {\r\n    long double x, y;\r\n\r\n  \
    \  point() = default;\r\n\r\n    point(long double x, long double y) : x(x), y(y)\
    \ {}\r\n\r\n    point &operator+=(const point rhs) noexcept {\r\n        x = internal::add(x,\
    \ rhs.x);\r\n        y = internal::add(y, rhs.y);\r\n        return *this;\r\n\
    \    }\r\n\r\n    point &operator-=(const point rhs) noexcept {\r\n        x =\
    \ internal::add(x, -rhs.x);\r\n        y = internal::add(y, -rhs.y);\r\n     \
    \   return *this;\r\n    }\r\n\r\n    point &operator*=(const point rhs) noexcept\
    \ {\r\n        long double _x = internal::add(x * rhs.x, -y * rhs.y);\r\n    \
    \    long double _y = internal::add(x * rhs.y, y * rhs.x);\r\n        x = _x;\r\
    \n        y = _y;\r\n        return *this;\r\n    }\r\n\r\n    point &operator*=(const\
    \ long double k) noexcept {\r\n        x *= k;\r\n        y *= k;\r\n        return\
    \ *this;\r\n    }\r\n\r\n    point &operator/=(const long double k) {\r\n    \
    \    assert(internal::sgn(k) != 0);\r\n        x /= k;\r\n        y /= k;\r\n\
    \        return *this;\r\n    }\r\n\r\n    point operator+(const point &rhs) const\
    \ noexcept {\r\n        return point(*this) += rhs;\r\n    }\r\n\r\n    point\
    \ operator-(const point &rhs) const noexcept {\r\n        return point(*this)\
    \ -= rhs;\r\n    }\r\n\r\n    point operator*(const point &rhs) const noexcept\
    \ {\r\n        return point(*this) *= rhs;\r\n    }\r\n\r\n    point operator*(const\
    \ long double rhs) const noexcept {\r\n        return point(*this) *= rhs;\r\n\
    \    }\r\n\r\n    point operator/(const long double rhs) const {\r\n        return\
    \ point(*this) /= rhs;\r\n    }\r\n\r\n    point operator-() const noexcept {\r\
    \n        return point(0, 0) - *this;\r\n    }\r\n\r\n    long double abs() const\
    \ noexcept {\r\n        return std::sqrt(internal::add(x * x, y * y));\r\n   \
    \ }\r\n\r\n    long double dot(const point rhs) const noexcept {\r\n        return\
    \ internal::add(x * rhs.x, y * rhs.y);\r\n    }\r\n\r\n    long double det(const\
    \ point rhs) const noexcept {\r\n        return internal::add(x * rhs.y, -y *\
    \ rhs.x);\r\n    }\r\n\r\n    // arctan(y/x) (\u5358\u4F4D\u306F\u30E9\u30B8\u30A2\
    \u30F3)\r\n    long double arg() const {\r\n        return std::atan2(y, x);\r\
    \n    }\r\n\r\n    // x\u6607\u9806, \u305D\u306E\u5F8Cy\u6607\u9806\r\n    bool\
    \ operator<(const point &rhs) const noexcept {\r\n        if (internal::sgn(x\
    \ - rhs.x)) return internal::sgn(x - rhs.x) < 0;\r\n        return internal::sgn(y\
    \ - rhs.y) < 0;\r\n    }\r\n\r\n    bool operator==(const point &rhs) const noexcept\
    \ {\r\n        if (internal::sgn(x - rhs.x) == 0 && internal::sgn(y - rhs.y) ==\
    \ 0)\r\n            return true;\r\n        else\r\n            return false;\r\
    \n    }\r\n\r\n    bool operator!=(const point &rhs) const noexcept {\r\n    \
    \    return !((*this) == rhs);\r\n    }\r\n};\r\n\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const point &a) {\r\n    return os << a.x << \" \" << a.y;\r\n}\r\n\r\n\
    std::istream &operator>>(std::istream &os, point &a) {\r\n    return os >> a.x\
    \ >> a.y;\r\n}\r\n\r\npoint conj(const point &a) {\r\n    return point(a.x, -a.y);\r\
    \n}\r\n\r\n// \u70B9a \u3092ang(\u30E9\u30B8\u30A2\u30F3)\u56DE\u8EE2\u3059\u308B\
    \r\npoint rot(const point &a, long double ang) {\r\n    return point(std::cos(ang)\
    \ * a.x - std::sin(ang) * a.y,\r\n                 std::sin(ang) * a.x + std::cos(ang)\
    \ * a.y);\r\n}\r\n\r\npoint rot90(const point &a) {\r\n    return point(-a.y,\
    \ a.x);\r\n}\r\n\r\nlong double dot(const point &a, const point &b) {\r\n    return\
    \ a.dot(b);\r\n}\r\n\r\nlong double det(const point &a, const point &b) {\r\n\
    \    return a.det(b);\r\n}\r\n\r\nlong double abs(const point &a) {\r\n    return\
    \ a.abs();\r\n}\r\n\r\nlong double norm(const point &a) {\r\n    return internal::add(a.x\
    \ * a.x, a.y * a.y);\r\n}\r\n\r\nint isp(const point &a, const point &b, const\
    \ point &c) {\r\n    int flag = internal::sgn(det(b - a, c - a));\r\n    if (flag\
    \ == 0) {\r\n        if (internal::sgn(dot(b - a, c - a)) < 0) return -2;\r\n\
    \        if (internal::sgn(dot(a - b, c - b)) < 0) return +2;\r\n    }\r\n   \
    \ return flag;\r\n}\r\n\r\n// \u5206\u5272\u7D71\u6CBB\u3067\u6700\u8FD1\u70B9\
    \u5BFE\u3092\u6C42\u3081\u308B O(N log N)\r\nlong double closest_pair(std::vector<point>\
    \ p) {\r\n    std::sort(p.begin(), p.end());\r\n    int n = p.size();\r\n    auto\
    \ f = [&](auto &&self, int l, int r) -> long double {\r\n        if (r - l ==\
    \ 1) {\r\n            return 1e9;\r\n        }\r\n        int mid = (l + r) /\
    \ 2;\r\n        long double x = p[mid].x;\r\n        long double d = std::min(self(self,\
    \ l, mid), self(self, mid, r));\r\n        std::vector<point> b;\r\n        b.reserve(r\
    \ - l);\r\n        int j = mid;\r\n        for (int i = l; i < mid; i++) {\r\n\
    \            while (j < r && p[j].y <= p[i].y) {\r\n                b.emplace_back(p[j++]);\r\
    \n            }\r\n            b.emplace_back(p[i]);\r\n        }\r\n        while\
    \ (j < r) {\r\n            b.emplace_back(p[j++]);\r\n        }\r\n        for\
    \ (int i = 0; i < r - l; i++) {\r\n            p[l + i] = b[i];\r\n        }\r\
    \n        b.clear();\r\n        for (int i = l; i < r; i++) {\r\n            if\
    \ (std::abs(p[i].x - x) >= d) continue;\r\n            for (int j = int(b.size())\
    \ - 1; j >= 0; j--) {\r\n                if (p[i].y - b[j].y >= d) break;\r\n\
    \                d = std::min(d, abs(p[i] - b[j]));\r\n            }\r\n     \
    \       b.emplace_back(p[i]);\r\n        }\r\n        return d;\r\n    };\r\n\
    \    return f(f, 0, n);\r\n}\r\n\r\n// \u2220ABC\u3092\u6C42\u3081\u308B(\u30E9\
    \u30B8\u30A2\u30F3)\r\nlong double angle(const point &A, const point &B, const\
    \ point &C) {\r\n    long double a = (B - C).abs(), b = (C - A).abs(), c = (A\
    \ - B).abs();\r\n    long double cos =\r\n        internal::add(internal::add(a\
    \ * a, c * c), -b * b) / (2.0 * c * a);\r\n    return std::acos(cos);\r\n}\r\n\
    \r\n// \u7B26\u53F7\u4ED8\u304D\r\nlong double calc_ang(point a, point b, point\
    \ c) {\r\n    long double cos = dot((a - b), (c - b)) / (abs(a - b) * abs(c -\
    \ b));\r\n    long double sin = det((a - b), (c - b)) / (abs(a - b) * abs(c -\
    \ b));\r\n    return std::atan2(sin, cos);\r\n}\r\n\r\nvoid arg_sort(std::vector<point>\
    \ &a) {\r\n    int n = a.size();\r\n    std::vector ps(4, std::vector<point>());\r\
    \n    auto idx = [](point v) -> int {\r\n        if (v.y >= 0)\r\n           \
    \ return (v.x >= 0) ? 0 : 1;\r\n        else\r\n            return (v.x >= 0)\
    \ ? 3 : 2;\r\n    };\r\n    for (auto p : a) {\r\n        assert(!(p.x == 0 &&\
    \ p.y == 0));\r\n        ps[idx(p)].emplace_back(p);\r\n    }\r\n    a.clear();\r\
    \n    a.reserve(n);\r\n    for (int i = 0; i < 4; i++) {\r\n        std::sort(ps[i].begin(),\
    \ ps[i].end(), [](point &p1, point &p2) -> bool {\r\n            int flag = internal::sgn(internal::add(p1.x\
    \ * p2.y, -p2.x * p1.y));\r\n            return flag == 0 ? (norm(p1) < norm(p2))\
    \ : flag > 0;\r\n        });\r\n        for (auto &p : ps[i]) a.emplace_back(p);\r\
    \n    }\r\n    return;\r\n}\r\n\r\ntemplate <class T> void arg_sort_ll(std::vector<std::pair<T,\
    \ T>> &a) {\r\n    using Point = std::pair<T, T>;\r\n    int n = a.size();\r\n\
    \    std::vector ps(4, std::vector<Point>());\r\n    auto idx = [](Point v) ->\
    \ int {\r\n        if (v.second >= 0)\r\n            return (v.first >= 0) ? 0\
    \ : 1;\r\n        else\r\n            return (v.first >= 0) ? 3 : 2;\r\n    };\r\
    \n    for (auto p : a) {\r\n        assert(!(p.first == 0 && p.second == 0));\r\
    \n        ps[idx(p)].emplace_back(p);\r\n    }\r\n    a.clear();\r\n    a.reserve(n);\r\
    \n    for (int i = 0; i < 4; i++) {\r\n        std::sort(ps[i].begin(), ps[i].end(),\
    \ [](Point &p1, Point &p2) -> bool {\r\n            T flag = p1.first * p2.second\
    \ - p2.first * p1.second;\r\n            return flag == 0 ? (p1.first * p1.first\
    \ + p1.second * p1.second <\r\n                                p2.first * p2.first\
    \ + p2.second * p2.second)\r\n                             : flag > 0;\r\n   \
    \     });\r\n        for (auto &p : ps[i]) a.emplace_back(p);\r\n    }\r\n   \
    \ return;\r\n}\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: geometry/point.hpp
  requiredBy:
  - geometry/polygon.hpp
  - geometry/line_segment.hpp
  - geometry/circle.hpp
  - geometry/line.hpp
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/area.test.cpp
  - test/geometry/reflection.test.cpp
  - test/geometry/common_area_circles.test.cpp
  - test/geometry/cross_point.test.cpp
  - test/geometry/tangent_to_circle.test.cpp
  - test/geometry/contains.test.cpp
  - test/geometry/cross_points_of_circles.test.cpp
  - test/geometry/convex_diameter.test.cpp
  - test/geometry/is_convex.test.cpp
  - test/geometry/cross_points_of_circle_and_line.test.cpp
  - test/geometry/common_tangent.test.cpp
  - test/geometry/incircle_of_triangle.test.cpp
  - test/geometry/circumscribed_circle_of_triangle.test.cpp
  - test/geometry/intersection.test.cpp
  - test/geometry/intersection_circle.test.cpp
  - test/geometry/closest_pair.test.cpp
  - test/geometry/convex_polygon_cut.test.cpp
  - test/geometry/common_area.test.cpp
  - test/geometry/isp.test.cpp
  - test/geometry/intersection_line_segment.test.cpp
  - test/geometry/distance.test.cpp
documentation_of: geometry/point.hpp
layout: document
title: point
---

# 説明

計算幾何で用いる点(point)

# 関数

## isp

点の進行方向を求める関数.

- ```int isp(point a, point b, point c)```
    - 左に曲がる場合:$+1$ 
    - 右に曲がる場合:$-1$
    - c-a-bの順に並ぶ:$-2$
    - a-b-cの順に並ぶ:$+2$
    - a-c-bの順に並ぶ:$0$