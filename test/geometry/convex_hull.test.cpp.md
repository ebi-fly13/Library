---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/convex_hull.hpp
    title: geometry/convex_hull.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A
  bundledCode: "#line 1 \"test/geometry/convex_hull.test.cpp\"\n#define PROBLEM \\\
    \n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A\"\n\
    \n#line 2 \"geometry/convex_hull.hpp\"\n\r\n#include <algorithm>\r\n#include <vector>\r\
    \n\r\n/*\r\n    reference: \u30D7\u30ED\u30B0\u30E9\u30DF\u30F3\u30B0\u30B3\u30F3\
    \u30C6\u30B9\u30C8\u30C1\u30E3\u30EC\u30F3\u30B8\u30D6\u30C3\u30AF \u7B2C2\u7248\
    \ p234\r\n    verify:    https://atcoder.jp/contests/typical90/submissions/24974484\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct Point {\r\n    T\
    \ x, y;\r\n\r\n    Point &operator+=(const Point &rhs) noexcept {\r\n        x\
    \ += rhs.x;\r\n        y += rhs.y;\r\n        return *this;\r\n    }\r\n\r\n \
    \   Point &operator-=(const Point &rhs) noexcept {\r\n        x -= rhs.x;\r\n\
    \        y -= rhs.y;\r\n        return *this;\r\n    }\r\n\r\n    Point operator-(const\
    \ Point &rhs) const noexcept {\r\n        return Point(*this) -= rhs;\r\n    }\r\
    \n\r\n    T det(const Point &rhs) const noexcept {\r\n        return x * rhs.y\
    \ - y * rhs.x;\r\n    }\r\n};\r\n\r\ntemplate <class T>\r\nstd::vector<Point<T>>\
    \ convex_hull(int n, std::vector<Point<T>> p,\r\n                            \
    \      bool on = false) {\r\n    std::sort(p.begin(), p.end(), [](const Point<T>\
    \ &a, const Point<T> &b) {\r\n        return a.x != b.x ? a.x < b.x : a.y < b.y;\r\
    \n    });\r\n    std::vector<Point<T>> g1, g2;\r\n    int k1 = 0, k2 = 0;\r\n\
    \    for (int i = 0; i < n; i++) {\r\n        while (k1 > 1 &&\r\n           \
    \    (g1[k1 - 1] - g1[k1 - 2]).det(p[i] - g1[k1 - 1]) <= 0) {\r\n            if\
    \ (on && (g1[k1 - 1] - g1[k1 - 2]).det(p[i] - g1[k1 - 1]) == 0)\r\n          \
    \      break;\r\n            g1.pop_back();\r\n            k1--;\r\n        }\r\
    \n        while (k2 > 1 &&\r\n               (g2[k2 - 1] - g2[k2 - 2]).det(p[i]\
    \ - g2[k2 - 1]) >= 0) {\r\n            if (on && (g2[k2 - 1] - g2[k2 - 2]).det(p[i]\
    \ - g2[k2 - 1]) == 0)\r\n                break;\r\n            g2.pop_back();\r\
    \n            k2--;\r\n        }\r\n        g1.push_back(p[i]);\r\n        k1++;\r\
    \n        g2.push_back(p[i]);\r\n        k2++;\r\n    }\r\n    std::vector<Point<T>>\
    \ ch(k1 + k2 - 2);\r\n    for (int i = 0; i < k1; i++) {\r\n        ch[i] = g1[i];\r\
    \n    }\r\n    for (int i = k2 - 2; i > 0; i--) {\r\n        ch[k1 + k2 - i -\
    \ 2] = g2[i];\r\n    }\r\n    return ch;\r\n}\r\n\r\n}  // namespace ebi\n#line\
    \ 5 \"test/geometry/convex_hull.test.cpp\"\n\n#line 7 \"test/geometry/convex_hull.test.cpp\"\
    \n#include <cstdint>\n#include <iomanip>\n#include <iostream>\n#line 11 \"test/geometry/convex_hull.test.cpp\"\
    \n\nnamespace ebi {\n\nusing i64 = std::int64_t;\n\nvoid main_() {\n    int n;\n\
    \    std::cin >> n;\n    std::vector<Point<i64>> poly(n);\n    for (auto& [x,\
    \ y] : poly) {\n        std::cin >> x >> y;\n    }\n    auto ch = convex_hull(n,\
    \ poly, true);\n    int m = ch.size();\n    int idx = 0;\n    for (int i = 0;\
    \ i < m; i++) {\n        if (ch[i].y < ch[idx].y) {\n            idx = i;\n  \
    \      } else if (ch[i].y == ch[idx].y) {\n            if (ch[i].x < ch[idx].x)\
    \ {\n                idx = i;\n            }\n        }\n    }\n    std::cout\
    \ << m << '\\n';\n    for (int i = 0; i < m; i++) {\n        auto [x, y] = ch[(i\
    \ + idx) % m];\n        std::cout << x << \" \" << y << '\\n';\n    }\n}\n\n}\
    \  // namespace ebi\n\nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    ebi::main_();\n\
    }\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A\"\
    \n\n#include \"geometry/convex_hull.hpp\"\n\n#include <algorithm>\n#include <cstdint>\n\
    #include <iomanip>\n#include <iostream>\n#include <vector>\n\nnamespace ebi {\n\
    \nusing i64 = std::int64_t;\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n\
    \    std::vector<Point<i64>> poly(n);\n    for (auto& [x, y] : poly) {\n     \
    \   std::cin >> x >> y;\n    }\n    auto ch = convex_hull(n, poly, true);\n  \
    \  int m = ch.size();\n    int idx = 0;\n    for (int i = 0; i < m; i++) {\n \
    \       if (ch[i].y < ch[idx].y) {\n            idx = i;\n        } else if (ch[i].y\
    \ == ch[idx].y) {\n            if (ch[i].x < ch[idx].x) {\n                idx\
    \ = i;\n            }\n        }\n    }\n    std::cout << m << '\\n';\n    for\
    \ (int i = 0; i < m; i++) {\n        auto [x, y] = ch[(i + idx) % m];\n      \
    \  std::cout << x << \" \" << y << '\\n';\n    }\n}\n\n}  // namespace ebi\n\n\
    int main() {\n    std::cout << std::fixed << std::setprecision(15);\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    ebi::main_();\n}"
  dependsOn:
  - geometry/convex_hull.hpp
  isVerificationFile: true
  path: test/geometry/convex_hull.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/convex_hull.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/convex_hull.test.cpp
- /verify/test/geometry/convex_hull.test.cpp.html
title: test/geometry/convex_hull.test.cpp
---
