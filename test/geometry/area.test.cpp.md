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
  bundledCode: "#line 1 \"test/geometry/area.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A\"\n\n#include\
    \ <algorithm>\n#include <iomanip>\n#include <iostream>\n#include <vector>\n\n\
    #line 2 \"geometry/line.hpp\"\n\n#include <cassert>\n#include <cmath>\n\n#line\
    \ 2 \"geometry/point.hpp\"\n\r\n#line 6 \"geometry/point.hpp\"\n#include <cstdint>\r\
    \n#line 9 \"geometry/point.hpp\"\n\r\nnamespace ebi {\r\n\r\nconstexpr long double\
    \ EPS = 1e-10;\r\n\r\nconst long double PI = std::acos(-1);\r\n\r\nnamespace internal\
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
    \ return;\r\n}\r\n\r\n}  // namespace ebi\n#line 7 \"geometry/line.hpp\"\n\nnamespace\
    \ ebi {\n\nstruct line {\n    point a, b;\n\n    line(long double x1, long double\
    \ y1, long double x2, long double y2)\n        : a(x1, y1), b(x2, y2) {}\n\n \
    \   line(const point &a, const point &b) : a(a), b(b) {}\n\n    point proj(const\
    \ point &p) const {\n        return a + (b - a) * (dot(b - a, p - a) / norm(b\
    \ - a));\n    }\n\n    point relf(const point &p) const {\n        return proj(p)\
    \ * double(2) - p;\n    }\n\n    long double distance(const point &c) const {\n\
    \        return std::abs(det(c - a, b - a) / abs(b - a));\n    }\n};\n\nint intersection(const\
    \ line &a, const line &b) {\n    if (internal::sgn(det(a.b - a.a, b.a - b.b))\
    \ != 0) {\n        if (internal::sgn(dot(a.b - a.a, b.b - b.a)) == 0) {  // \u5782\
    \u76F4\n            return 1;\n        }\n        return 0;                  \
    \                              // \u4EA4\u5DEE\n    } else if (internal::sgn(det(a.b\
    \ - a.a, b.a - a.a)) != 0) {  // \u5E73\u884C\n        return 2;\n    } else {\
    \  // \u540C\u4E00\u76F4\u7DDA\n        return 3;\n    }\n}\n\npoint cross_point(const\
    \ point &a, const point &b, const point &c,\n                  const point &d)\
    \ {\n    return a + (b - a) * det(c - a, d - c) / det(b - a, d - c);\n}\n\n//\
    \ \u4EA4\u70B9\u304C\u3042\u308B\u304B\u78BA\u8A8D\u3059\u308B\uFF01\npoint cross_point(const\
    \ line &s, const line &t) {\n    assert(intersection(s, t) < 2);\n    return s.a\
    \ +\n           (s.b - s.a) * det(t.a - s.a, t.b - t.a) / det(s.b - s.a, t.b -\
    \ t.a);\n}\n\n// \u76F4\u7DDAa\u3068\u70B9c\u306E\u8DDD\u96E2\nlong double distance(const\
    \ line &a, const point &c) {\n    return std::abs(det(c - a.a, a.b - a.a) / abs(a.b\
    \ - a.a));\n}\n\nlong double distance(const line &a, const line &b) {\n    if\
    \ (intersection(a, b) < 2) {\n        return 0;\n    } else {\n        return\
    \ distance(a, b.a);\n    }\n}\n\n}  // namespace ebi\n#line 2 \"geometry/line_segment.hpp\"\
    \n\n#line 5 \"geometry/line_segment.hpp\"\n\n#line 8 \"geometry/line_segment.hpp\"\
    \n\nnamespace ebi {\n\nstruct line_segment {\n    point a, b;\n\n    line_segment()\
    \ = default;\n\n    line_segment(long double x1, long double y1, long double x2,\
    \ long double y2)\n        : a(x1, y1), b(x2, y2) {}\n\n    line_segment(const\
    \ point &a, const point &b) : a(a), b(b) {}\n};\n\n// \u7DDA\u5206ab, cd \u304C\
    \u4EA4\u308F\u308B\u304B\u5224\u5B9A\nbool intersection_line_segment(const point\
    \ &a, const point &b, const point &c,\n                               const point\
    \ &d) {\n    if (internal::sgn(isp(a, b, c) * isp(a, b, d)) <= 0 &&\n        internal::sgn(isp(c,\
    \ d, a) * isp(c, d, b)) <= 0) {\n        return true;\n    }\n    return false;\n\
    }\n\n// \u7DDA\u5206ab, cd \u304C\u4EA4\u308F\u308B\u304B\u5224\u5B9A\nbool intersection(const\
    \ line_segment &a, const line_segment &b) {\n    return intersection_line_segment(a.a,\
    \ a.b, b.a, b.b);\n}\n\nbool intersection(const line &a, const line_segment &b)\
    \ {\n    if (internal::sgn(det(a.b - a.a, b.a - a.a)) *\n            internal::sgn(det(a.b\
    \ - a.a, b.b - a.a)) <\n        0) {\n        return true;\n    } else {\n   \
    \     return false;\n    }\n}\n\npoint cross_point(const line_segment &s, const\
    \ line_segment &t) {\n    assert(intersection(s, t));\n    return s.a +\n    \
    \       (s.b - s.a) * det(t.a - s.a, t.b - t.a) / det(s.b - s.a, t.b - t.a);\n\
    }\n\nlong double distance(const line_segment &a, const point &c) {\n    if (internal::sgn(dot(a.b\
    \ - a.a, c - a.a)) < 0) {\n        return abs(c - a.a);\n    } else if (internal::sgn(dot(a.a\
    \ - a.b, c - a.b)) < 0) {\n        return abs(c - a.b);\n    } else {\n      \
    \  return std::abs(det(c - a.a, a.b - a.a) / abs(a.b - a.a));\n    }\n}\n\nlong\
    \ double distance(const line_segment &a, const line_segment &b) {\n    if (intersection(a,\
    \ b)) {\n        return 0;\n    } else {\n        return std::min(std::min(distance(a,\
    \ b.a), distance(a, b.b)),\n                        std::min(distance(b, a.a),\
    \ distance(b, a.b)));\n    }\n}\n\nlong double distance(const line &a, const line_segment\
    \ &b) {\n    if (intersection(a, b)) {\n        return 0;\n    } else {\n    \
    \    return std::min(distance(a, b.a), distance(a, b.b));\n    }\n}\n\n}  // namespace\
    \ ebi\n#line 2 \"geometry/polygon.hpp\"\n\n#line 5 \"geometry/polygon.hpp\"\n\n\
    #line 8 \"geometry/polygon.hpp\"\n\nnamespace ebi {\n\nusing Polygon = std::vector<point>;\n\
    \nlong double area(const Polygon &poly) {\n    long double s = 0;\n    int n =\
    \ poly.size();\n    for (int i = 0; i < n; i++) {\n        s = internal::add(s,\
    \ det(poly[i], poly[(i + 1 != n) ? i + 1 : 0]));\n    }\n    s /= 2.0;\n    return\
    \ s;\n}\n\n// \u51F8\u591A\u89D2\u5F62\u304B\u5224\u5B9A. p\u306B\u53CD\u6642\u8A08\
    \u56DE\u308A\u3067\u70B9\u304C\u5165\u3063\u3066\u3044\u308B\u3068\u4EEE\u5B9A\
    \nbool is_convex(const Polygon &poly) {\n    int n = poly.size();\n    for (int\
    \ i = 0; i < n; i++) {\n        if (isp(poly[i], poly[(i + 1 != n) ? i + 1 : 0],\n\
    \                poly[(i + 2 < n) ? i + 2 : (i + 2) % n]) == -1) {\n         \
    \   return false;\n        }\n    }\n    return true;\n}\n\nenum { OUT, ON, IN\
    \ };\n\nint contains(const Polygon &poly, const point &p) {\n    bool in = false;\n\
    \    int n = poly.size();\n    for (int i = 0; i < n; i++) {\n        point a\
    \ = poly[i] - p;\n        point b = poly[(i + 1 < n) ? i + 1 : 0] - p;\n     \
    \   if (a.y > b.y) std::swap(a, b);\n        if (a.y <= 0 && 0 < b.y && det(a,\
    \ b) < 0) in = !in;\n        if (det(a, b) == 0 && dot(a, b) <= 0) return ON;\n\
    \    }\n    return in ? IN : OUT;\n}\n\nlong double convex_diameter(const Polygon\
    \ &convex_poly) {\n    int n = convex_poly.size();\n    int is = 0, js = 0;\n\
    \    for (int i = 1; i < n; i++) {\n        if (convex_poly[i].y > convex_poly[is].y)\
    \ is = i;\n        if (convex_poly[i].y < convex_poly[js].y) js = i;\n    }\n\
    \    long double max = (convex_poly[is] - convex_poly[js]).abs();\n    int i,\
    \ max_i, j, max_j;\n    i = max_i = is;\n    j = max_j = js;\n    do {\n     \
    \   if (det(convex_poly[(i + 1 < n) ? i + 1 : 0] - convex_poly[i],\n         \
    \       convex_poly[(j + 1 < n) ? j + 1 : 0] - convex_poly[j]) >= 0) {\n     \
    \       j = (j + 1 < n) ? j + 1 : 0;\n        } else {\n            i = (i + 1\
    \ < n) ? i + 1 : 0;\n        }\n        if ((convex_poly[i] - convex_poly[j]).abs()\
    \ > max) {\n            max = (convex_poly[i] - convex_poly[j]).abs();\n     \
    \       max_i = i;\n            max_j = j;\n        }\n    } while (i != is ||\
    \ j != js);\n    return max;\n}\n\nPolygon convex_polygon_cut(const Polygon &poly,\
    \ const line &l) {\n    Polygon ret;\n    int n = poly.size();\n    for (int i\
    \ = 0; i < n; i++) {\n        const point &now = poly[i];\n        const point\
    \ &nxt = poly[(i + 1 < n) ? i + 1 : 0];\n        long double cf = det(l.a - now,\
    \ l.b - now);\n        long double cs = det(l.a - nxt, l.b - nxt);\n        if\
    \ (internal::sgn(cf) >= 0) {\n            ret.emplace_back(now);\n        }\n\
    \        if (internal::sgn(cf) * internal::sgn(cs) < 0) {\n            ret.emplace_back(cross_point(line(now,\
    \ nxt), l));\n        }\n    }\n    return ret;\n}\n\n}  // namespace ebi\n#line\
    \ 13 \"test/geometry/area.test.cpp\"\n\nnamespace ebi {\n\nvoid main_() {\n  \
    \  int n;\n    std::cin >> n;\n    std::vector<point> p(n);\n    for (auto& [x,\
    \ y] : p) {\n        std::cin >> x >> y;\n    }\n    std::cout << area(p) << '\\\
    n';\n}\n\n}  // namespace ebi\n\nint main() {\n    std::cout << std::fixed <<\
    \ std::setprecision(1);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    ebi::main_();\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A\"\
    \n\n#include <algorithm>\n#include <iomanip>\n#include <iostream>\n#include <vector>\n\
    \n#include \"geometry/line.hpp\"\n#include \"geometry/line_segment.hpp\"\n#include\
    \ \"geometry/point.hpp\"\n#include \"geometry/polygon.hpp\"\n\nnamespace ebi {\n\
    \nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::vector<point> p(n);\n\
    \    for (auto& [x, y] : p) {\n        std::cin >> x >> y;\n    }\n    std::cout\
    \ << area(p) << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n    std::cout\
    \ << std::fixed << std::setprecision(1);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    ebi::main_();\n}"
  dependsOn:
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/line_segment.hpp
  - geometry/polygon.hpp
  isVerificationFile: true
  path: test/geometry/area.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/area.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/area.test.cpp
- /verify/test/geometry/area.test.cpp.html
title: test/geometry/area.test.cpp
---