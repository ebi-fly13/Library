---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc218/submissions/25800862
    - https://twitter.com/maspy_stars/status/1436690222465486848
  bundledCode: "#line 2 \"data_structure/removable_priority_queue.hpp\"\n\n#include\
    \ <functional>\n#include <queue>\n#include <vector>\n\n/*\n    reference: https://twitter.com/maspy_stars/status/1436690222465486848\n\
    \    verify: https://atcoder.jp/contests/abc218/submissions/25800862\n*/\n\nnamespace\
    \ ebi {\n\ntemplate <class T, class Container = std::vector<T>,\n          class\
    \ Compare = std::less<typename Container::value_type>>\nstruct removable_priority_queue\
    \ {\n  private:\n    void update() {\n        while (!rm_que.empty() && que.top()\
    \ == rm_que.top()) {\n            que.pop();\n            rm_que.pop();\n    \
    \    }\n        return;\n    }\n\n  public:\n    removable_priority_queue() =\
    \ default;\n\n    bool empty() const {\n        return (size() == 0);\n    }\n\
    \n    int size() const {\n        return int(que.size() - rm_que.size());\n  \
    \  }\n\n    T top() {\n        assert(!empty());\n        update();\n        return\
    \ que.top();\n    }\n\n    void pop() {\n        assert(!empty());\n        update();\n\
    \        que.pop();\n        return;\n    }\n\n    void push(const T &x) {\n \
    \       que.push(x);\n        return;\n    }\n\n    template <class... Args> void\
    \ emplace(Args &&... args) {\n        que.emplace(std::forward<Args>(args)...);\n\
    \        return;\n    }\n\n    void remove(const T &x) {\n        rm_que.push(x);\n\
    \        assert(que.size() >= rm_que.size());\n        return;\n    }\n\n    template\
    \ <class... Args> void emplace_remove(Args &&... args) {\n        rm_que.emplace(std::forward<Args>(args)...);\n\
    \        assert(que.size() >= rm_que.size());\n        return;\n    }\n\n  private:\n\
    \    std::priority_queue<T, Container, Compare> que, rm_que;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <functional>\n#include <queue>\n#include <vector>\n\
    \n/*\n    reference: https://twitter.com/maspy_stars/status/1436690222465486848\n\
    \    verify: https://atcoder.jp/contests/abc218/submissions/25800862\n*/\n\nnamespace\
    \ ebi {\n\ntemplate <class T, class Container = std::vector<T>,\n          class\
    \ Compare = std::less<typename Container::value_type>>\nstruct removable_priority_queue\
    \ {\n  private:\n    void update() {\n        while (!rm_que.empty() && que.top()\
    \ == rm_que.top()) {\n            que.pop();\n            rm_que.pop();\n    \
    \    }\n        return;\n    }\n\n  public:\n    removable_priority_queue() =\
    \ default;\n\n    bool empty() const {\n        return (size() == 0);\n    }\n\
    \n    int size() const {\n        return int(que.size() - rm_que.size());\n  \
    \  }\n\n    T top() {\n        assert(!empty());\n        update();\n        return\
    \ que.top();\n    }\n\n    void pop() {\n        assert(!empty());\n        update();\n\
    \        que.pop();\n        return;\n    }\n\n    void push(const T &x) {\n \
    \       que.push(x);\n        return;\n    }\n\n    template <class... Args> void\
    \ emplace(Args &&... args) {\n        que.emplace(std::forward<Args>(args)...);\n\
    \        return;\n    }\n\n    void remove(const T &x) {\n        rm_que.push(x);\n\
    \        assert(que.size() >= rm_que.size());\n        return;\n    }\n\n    template\
    \ <class... Args> void emplace_remove(Args &&... args) {\n        rm_que.emplace(std::forward<Args>(args)...);\n\
    \        assert(que.size() >= rm_que.size());\n        return;\n    }\n\n  private:\n\
    \    std::priority_queue<T, Container, Compare> que, rm_que;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/removable_priority_queue.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/removable_priority_queue.hpp
layout: document
redirect_from:
- /library/data_structure/removable_priority_queue.hpp
- /library/data_structure/removable_priority_queue.hpp.html
title: data_structure/removable_priority_queue.hpp
---
