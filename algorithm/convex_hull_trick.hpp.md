---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/convex_hull_trick.hpp\"\n\n#include <cassert>\n\
    #include <deque>\n#include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\
    \ struct convex_hull_trick {\n  private:\n    bool check(std::pair<T, T> a, std::pair<T,\
    \ T> b, std::pair<T, T> c) {\n        return (b.first - a.first) * (c.second -\
    \ b.second) >=\n               (c.first - b.first) * (b.second - a.second);\n\
    \    }\n\n    T f(std::pair<T, T> a, T x) {\n        return a.first * x + a.second;\n\
    \    }\n\n  public:\n    convex_hull_trick() = default;\n\n    void add(T a, T\
    \ b) {\n        while (lines.size() >= 2 &&\n               check(*(lines.end()\
    \ - 2), lines.back(), {a, b})) {\n            lines.pop_back();\n        }\n \
    \       lines.emplace_back(a, b);\n    }\n\n    T min(T x) {\n        assert(!lines.empty());\n\
    \        while (lines.size() >= 2 && f(lines[0], x) >= f(lines[1], x)) {\n   \
    \         lines.pop_front();\n        }\n        return f(lines[0], x);\n    }\n\
    \n  private:\n    std::deque<std::pair<T, T>> lines;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <deque>\n#include <utility>\n\
    \nnamespace ebi {\n\ntemplate <class T> struct convex_hull_trick {\n  private:\n\
    \    bool check(std::pair<T, T> a, std::pair<T, T> b, std::pair<T, T> c) {\n \
    \       return (b.first - a.first) * (c.second - b.second) >=\n              \
    \ (c.first - b.first) * (b.second - a.second);\n    }\n\n    T f(std::pair<T,\
    \ T> a, T x) {\n        return a.first * x + a.second;\n    }\n\n  public:\n \
    \   convex_hull_trick() = default;\n\n    void add(T a, T b) {\n        while\
    \ (lines.size() >= 2 &&\n               check(*(lines.end() - 2), lines.back(),\
    \ {a, b})) {\n            lines.pop_back();\n        }\n        lines.emplace_back(a,\
    \ b);\n    }\n\n    T min(T x) {\n        assert(!lines.empty());\n        while\
    \ (lines.size() >= 2 && f(lines[0], x) >= f(lines[1], x)) {\n            lines.pop_front();\n\
    \        }\n        return f(lines[0], x);\n    }\n\n  private:\n    std::deque<std::pair<T,\
    \ T>> lines;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2023-07-05 21:52:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/convex_hull_trick.hpp
layout: document
redirect_from:
- /library/algorithm/convex_hull_trick.hpp
- /library/algorithm/convex_hull_trick.hpp.html
title: algorithm/convex_hull_trick.hpp
---
