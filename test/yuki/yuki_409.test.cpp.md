---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/convex_hull_trick.hpp
    title: Convex Hull Trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/409
    links:
    - https://yukicoder.me/problems/no/409
  bundledCode: "#line 1 \"test/yuki/yuki_409.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/409\"\
    \n\n#include <algorithm>\n#include <cstdint>\n#include <iostream>\n\n#line 2 \"\
    algorithm/convex_hull_trick.hpp\"\n\n#include <cassert>\n#include <deque>\n#include\
    \ <utility>\n\nnamespace ebi {\n\ntemplate <class T> struct convex_hull_trick\
    \ {\n  private:\n    bool check(std::pair<T, T> a, std::pair<T, T> b, std::pair<T,\
    \ T> c) {\n        return (b.first - a.first) * (c.second - b.second) >=\n   \
    \            (c.first - b.first) * (b.second - a.second);\n    }\n\n    T f(std::pair<T,\
    \ T> a, T x) {\n        return a.first * x + a.second;\n    }\n\n  public:\n \
    \   convex_hull_trick() = default;\n\n    void add(T a, T b) {\n        while\
    \ (lines.size() >= 2 &&\n               check(*(lines.end() - 2), lines.back(),\
    \ {a, b})) {\n            lines.pop_back();\n        }\n        lines.emplace_back(a,\
    \ b);\n    }\n\n    T min(T x) {\n        assert(!lines.empty());\n        while\
    \ (lines.size() >= 2 && f(lines[0], x) >= f(lines[1], x)) {\n            lines.pop_front();\n\
    \        }\n        return f(lines[0], x);\n    }\n\n  private:\n    std::deque<std::pair<T,\
    \ T>> lines;\n};\n\n}  // namespace ebi\n#line 8 \"test/yuki/yuki_409.test.cpp\"\
    \n\nusing i64 = std::int64_t;\n\nint main() {\n    int n;\n    i64 a, b, w;\n\
    \    std::cin >> n >> a >> b >> w;\n    ebi::convex_hull_trick<i64> cht;\n   \
    \ cht.add(-2 * a - b, 2 * w + 2 * a);\n    auto f = [&](i64 r) -> i64 { return\
    \ -a * r + b * r * (r + 1) / 2; };\n    i64 ans = w + f(n);\n    for (int i =\
    \ 1; i <= n; i++) {\n        i64 d;\n        std::cin >> d;\n        i64 val =\
    \ cht.min(i);\n        i64 res = b * i * i + 2 * d + val;\n        res /= 2;\n\
    \        cht.add(-2 * a - 2 * b * i - b,\n                b * i * i + b * i +\
    \ 2 * a * (i + 1) + 2 * res);\n        ans = std::min(ans, res + f(n - i));\n\
    \    }\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/409\"\n\n#include <algorithm>\n\
    #include <cstdint>\n#include <iostream>\n\n#include \"../../algorithm/convex_hull_trick.hpp\"\
    \n\nusing i64 = std::int64_t;\n\nint main() {\n    int n;\n    i64 a, b, w;\n\
    \    std::cin >> n >> a >> b >> w;\n    ebi::convex_hull_trick<i64> cht;\n   \
    \ cht.add(-2 * a - b, 2 * w + 2 * a);\n    auto f = [&](i64 r) -> i64 { return\
    \ -a * r + b * r * (r + 1) / 2; };\n    i64 ans = w + f(n);\n    for (int i =\
    \ 1; i <= n; i++) {\n        i64 d;\n        std::cin >> d;\n        i64 val =\
    \ cht.min(i);\n        i64 res = b * i * i + 2 * d + val;\n        res /= 2;\n\
    \        cht.add(-2 * a - 2 * b * i - b,\n                b * i * i + b * i +\
    \ 2 * a * (i + 1) + 2 * res);\n        ans = std::min(ans, res + f(n - i));\n\
    \    }\n    std::cout << ans << '\\n';\n}"
  dependsOn:
  - algorithm/convex_hull_trick.hpp
  isVerificationFile: true
  path: test/yuki/yuki_409.test.cpp
  requiredBy: []
  timestamp: '2023-07-05 22:32:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yuki/yuki_409.test.cpp
layout: document
redirect_from:
- /verify/test/yuki/yuki_409.test.cpp
- /verify/test/yuki/yuki_409.test.cpp.html
title: test/yuki/yuki_409.test.cpp
---
