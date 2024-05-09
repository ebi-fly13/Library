---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_409.test.cpp
    title: test/yuki/yuki_409.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_409.test.cpp
documentation_of: algorithm/convex_hull_trick.hpp
layout: document
title: Convex Hull Trick
---

## 説明

直線の追加 (傾きの降順で)と $x$ における最小値クエリ ( $x$ は単調増加)を処理する。

### add(a, b)

直線 $y = ax + b$ を追加。傾きが降順で与えられると仮定。

### get(x)

$\min f_i(x)$ を求める。 与えられる $x$ は単調増加であると仮定。