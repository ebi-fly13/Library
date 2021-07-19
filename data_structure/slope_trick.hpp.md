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
  bundledCode: "#line 2 \"data_structure/slope_trick.hpp\"\n\n#include <vector>\n\
    #include <queue>\n#include <cassert>\n\nnamespace ebi {\n\ntemplate<class T>\n\
    struct slope_trick {\nprivate:\n    using Self = slope_trick<T>;\n\n    void pop_L()\
    \ {\n        if(L.empty()) return;\n        L.pop(); \n        return;\n    }\n\
    \n    T top_L() const {\n        if(L.empty()) return -INF;\n        return L.top()\
    \ + add_L;\n    }\n\n    void push_L(const T &a) {\n        L.push(a-add_L);\n\
    \        return;\n    }\n\n    void pop_R() {\n        if(R.empty()) return;\n\
    \        R.pop();\n        return;\n    }\n\n    T top_R() const {\n        if(R.empty())\
    \ return INF;\n        return R.top() + add_R;\n    }\n\n    void push_R(const\
    \ T &a) {\n        R.push(a-add_R);\n        return;\n    }\n\n    int size()\
    \ {\n        return L.size() + R.size();\n    }\n\n    void swap(Self &a, Self\
    \ &b) {\n        std::swap(a.min_f, b.min_f);\n        std::swap(a.L, b.L);\n\
    \        std::swap(a.R, b.R);\n        std::swap(a.add_L, b.add_L);\n        std::swap(a.add_R,\
    \ b.add_R);\n        return;\n    }\npublic:\n    slope_trick() : min_f(0), add_L(0),\
    \ add_R(0) { }\n\n    T min() const {\n        return min_f;\n    }\n\n    std::pair<T,\
    \ T> argmin() const {\n        return {top_L(), top_R()};\n    }\n\n    void add_all(const\
    \ T &a) {\n        min_f += a;\n        return;\n    }\n\n    // add (x-a)_+\n\
    \    void add_x_minus_a(const T &a) {\n        min_f += std::max(T(0), top_L()\
    \ - a);\n        if(top_L() <= a) {\n            push_R(a);\n        }\n     \
    \   else {\n            push_L(a);\n            push_R(top_L());\n           \
    \ pop_L();\n        }\n        return;\n    }\n\n    // add (a-x)_+\n    void\
    \ add_a_minus_x(const T &a) {\n        min_f += std::max(T(0), a - top_R());\n\
    \        if(top_R() >= a) {\n            push_L(a);\n        }\n        else {\n\
    \            push_R(a);\n            push_L(top_R());\n            pop_R();\n\
    \        }\n        return;\n    }\n\n    // add |x-a|\n    void add_abs(const\
    \ T &a) {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n        return;\n\
    \    }\n\n    void sliding_window_minimum(const T &a, const T &b) {\n        assert(a\
    \ <= b);\n        add_L += a;\n        add_R += b;\n        return;\n    }\n\n\
    \    void shift(const T &a) {\n        sliding_window_minimum(a, a);\n    }\n\n\
    \    void merge(Self &st) {\n        if(st.size() > size()) {\n            swap((*this),\
    \ st);\n        }\n        min_f += st.min_f;\n        while(!st.L.empty()) {\n\
    \            add_a_minus_x(st.top_L());\n            st.pop_L();\n        }\n\
    \        while(!st.R.empty()) {\n            add_x_minus_a(st.top_R());\n    \
    \        st.pop_R();\n        }\n        return;\n    }\n\n    // __/\n    void\
    \ right_cumulative_min() {\n        L = std::priority_queue<T>();\n    }\n\n \
    \   // \\__\n    void left_cumulative_min() {\n        R = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>();\n    }\n\nprivate:\n    T min_f;\n    std::priority_queue<T>\
    \ L;\n    std::priority_queue<T, std::vector<T>, std::greater<T>> R;\n    T add_L,\
    \ add_R;\n    const T INF = std::numeric_limits<T>::max()/4;\n};\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include <cassert>\n\
    \nnamespace ebi {\n\ntemplate<class T>\nstruct slope_trick {\nprivate:\n    using\
    \ Self = slope_trick<T>;\n\n    void pop_L() {\n        if(L.empty()) return;\n\
    \        L.pop(); \n        return;\n    }\n\n    T top_L() const {\n        if(L.empty())\
    \ return -INF;\n        return L.top() + add_L;\n    }\n\n    void push_L(const\
    \ T &a) {\n        L.push(a-add_L);\n        return;\n    }\n\n    void pop_R()\
    \ {\n        if(R.empty()) return;\n        R.pop();\n        return;\n    }\n\
    \n    T top_R() const {\n        if(R.empty()) return INF;\n        return R.top()\
    \ + add_R;\n    }\n\n    void push_R(const T &a) {\n        R.push(a-add_R);\n\
    \        return;\n    }\n\n    int size() {\n        return L.size() + R.size();\n\
    \    }\n\n    void swap(Self &a, Self &b) {\n        std::swap(a.min_f, b.min_f);\n\
    \        std::swap(a.L, b.L);\n        std::swap(a.R, b.R);\n        std::swap(a.add_L,\
    \ b.add_L);\n        std::swap(a.add_R, b.add_R);\n        return;\n    }\npublic:\n\
    \    slope_trick() : min_f(0), add_L(0), add_R(0) { }\n\n    T min() const {\n\
    \        return min_f;\n    }\n\n    std::pair<T, T> argmin() const {\n      \
    \  return {top_L(), top_R()};\n    }\n\n    void add_all(const T &a) {\n     \
    \   min_f += a;\n        return;\n    }\n\n    // add (x-a)_+\n    void add_x_minus_a(const\
    \ T &a) {\n        min_f += std::max(T(0), top_L() - a);\n        if(top_L() <=\
    \ a) {\n            push_R(a);\n        }\n        else {\n            push_L(a);\n\
    \            push_R(top_L());\n            pop_L();\n        }\n        return;\n\
    \    }\n\n    // add (a-x)_+\n    void add_a_minus_x(const T &a) {\n        min_f\
    \ += std::max(T(0), a - top_R());\n        if(top_R() >= a) {\n            push_L(a);\n\
    \        }\n        else {\n            push_R(a);\n            push_L(top_R());\n\
    \            pop_R();\n        }\n        return;\n    }\n\n    // add |x-a|\n\
    \    void add_abs(const T &a) {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n\
    \        return;\n    }\n\n    void sliding_window_minimum(const T &a, const T\
    \ &b) {\n        assert(a <= b);\n        add_L += a;\n        add_R += b;\n \
    \       return;\n    }\n\n    void shift(const T &a) {\n        sliding_window_minimum(a,\
    \ a);\n    }\n\n    void merge(Self &st) {\n        if(st.size() > size()) {\n\
    \            swap((*this), st);\n        }\n        min_f += st.min_f;\n     \
    \   while(!st.L.empty()) {\n            add_a_minus_x(st.top_L());\n         \
    \   st.pop_L();\n        }\n        while(!st.R.empty()) {\n            add_x_minus_a(st.top_R());\n\
    \            st.pop_R();\n        }\n        return;\n    }\n\n    // __/\n  \
    \  void right_cumulative_min() {\n        L = std::priority_queue<T>();\n    }\n\
    \n    // \\__\n    void left_cumulative_min() {\n        R = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>();\n    }\n\nprivate:\n    T min_f;\n    std::priority_queue<T>\
    \ L;\n    std::priority_queue<T, std::vector<T>, std::greater<T>> R;\n    T add_L,\
    \ add_R;\n    const T INF = std::numeric_limits<T>::max()/4;\n};\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/slope_trick.hpp
  requiredBy: []
  timestamp: '2021-07-19 18:23:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/slope_trick.hpp
layout: document
redirect_from:
- /library/data_structure/slope_trick.hpp
- /library/data_structure/slope_trick.hpp.html
title: data_structure/slope_trick.hpp
---
