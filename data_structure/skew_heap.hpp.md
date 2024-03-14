---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/directed_mst.hpp
    title: Directed MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_grl_1_a.test.cpp
    title: test/aoj/aoj_grl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Directed_MST.test.cpp
    title: test/graph/Directed_MST.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/skew_heap.hpp\"\n\n#include <cassert>\n#include\
    \ <functional>\n#include <memory>\n#include <vector>\n\nnamespace ebi {\n\ntemplate\
    \ <class Key, class T, class Compare = std::less<Key>> struct skew_heap {\n  private:\n\
    \    using value_type = Key;\n    using Self = skew_heap<Key, T, Compare>;\n\n\
    \    struct Node;\n    using iterator = std::shared_ptr<Node>;\n\n    struct Node\
    \ {\n        Node(value_type x_, T info_) : x(x_), info(info_) {}\n\n        void\
    \ propagate() {\n            if (lhs) lhs->lazy += lazy;\n            if (rhs)\
    \ rhs->lazy += lazy;\n            x += lazy;\n            lazy = value_type();\n\
    \        }\n\n        value_type x;\n        T info;\n        value_type lazy\
    \ = value_type();\n        iterator lhs = nullptr, rhs = nullptr;\n    };\n\n\
    \    iterator internal_meld(iterator lhs, iterator rhs) {\n        if (lhs ==\
    \ nullptr) return rhs;\n        if (rhs == nullptr) return lhs;\n        lhs->propagate();\n\
    \        rhs->propagate();\n        if (Compare()(lhs->x, rhs->x)) {\n       \
    \     std::swap(lhs, rhs);\n        }\n        lhs->rhs = internal_meld(lhs->rhs,\
    \ rhs);\n        std::swap(lhs->lhs, lhs->rhs);\n        return lhs;\n    }\n\n\
    \  public:\n    skew_heap() = default;\n\n    void push(value_type x, T info)\
    \ {\n        root = internal_meld(root, std::make_shared<Node>(x, info));\n  \
    \      sz++;\n    }\n\n    void pop() {\n        assert(!empty());\n        root\
    \ = internal_meld(root->lhs, root->rhs);\n        sz--;\n    }\n\n    void meld(Self\
    \ &heap) {\n        root = internal_meld(root, heap.root);\n        sz += heap.sz;\n\
    \    }\n\n    void add(value_type lazy) {\n        if (root == nullptr) return;\n\
    \        root->lazy += lazy;\n        root->propagate();\n    }\n\n    bool empty()\
    \ const {\n        return root == nullptr;\n    }\n\n    std::pair<value_type,\
    \ T> top() const {\n        return {root->x, root->info};\n    }\n\n    int size()\
    \ const {\n        return sz;\n    }\n\n  private:\n    iterator root = nullptr;\n\
    \    int sz = 0;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\n#include <memory>\n\
    #include <vector>\n\nnamespace ebi {\n\ntemplate <class Key, class T, class Compare\
    \ = std::less<Key>> struct skew_heap {\n  private:\n    using value_type = Key;\n\
    \    using Self = skew_heap<Key, T, Compare>;\n\n    struct Node;\n    using iterator\
    \ = std::shared_ptr<Node>;\n\n    struct Node {\n        Node(value_type x_, T\
    \ info_) : x(x_), info(info_) {}\n\n        void propagate() {\n            if\
    \ (lhs) lhs->lazy += lazy;\n            if (rhs) rhs->lazy += lazy;\n        \
    \    x += lazy;\n            lazy = value_type();\n        }\n\n        value_type\
    \ x;\n        T info;\n        value_type lazy = value_type();\n        iterator\
    \ lhs = nullptr, rhs = nullptr;\n    };\n\n    iterator internal_meld(iterator\
    \ lhs, iterator rhs) {\n        if (lhs == nullptr) return rhs;\n        if (rhs\
    \ == nullptr) return lhs;\n        lhs->propagate();\n        rhs->propagate();\n\
    \        if (Compare()(lhs->x, rhs->x)) {\n            std::swap(lhs, rhs);\n\
    \        }\n        lhs->rhs = internal_meld(lhs->rhs, rhs);\n        std::swap(lhs->lhs,\
    \ lhs->rhs);\n        return lhs;\n    }\n\n  public:\n    skew_heap() = default;\n\
    \n    void push(value_type x, T info) {\n        root = internal_meld(root, std::make_shared<Node>(x,\
    \ info));\n        sz++;\n    }\n\n    void pop() {\n        assert(!empty());\n\
    \        root = internal_meld(root->lhs, root->rhs);\n        sz--;\n    }\n\n\
    \    void meld(Self &heap) {\n        root = internal_meld(root, heap.root);\n\
    \        sz += heap.sz;\n    }\n\n    void add(value_type lazy) {\n        if\
    \ (root == nullptr) return;\n        root->lazy += lazy;\n        root->propagate();\n\
    \    }\n\n    bool empty() const {\n        return root == nullptr;\n    }\n\n\
    \    std::pair<value_type, T> top() const {\n        return {root->x, root->info};\n\
    \    }\n\n    int size() const {\n        return sz;\n    }\n\n  private:\n  \
    \  iterator root = nullptr;\n    int sz = 0;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/skew_heap.hpp
  requiredBy:
  - graph/directed_mst.hpp
  timestamp: '2024-03-15 00:35:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_grl_1_a.test.cpp
  - test/graph/Directed_MST.test.cpp
documentation_of: data_structure/skew_heap.hpp
layout: document
redirect_from:
- /library/data_structure/skew_heap.hpp
- /library/data_structure/skew_heap.hpp.html
title: data_structure/skew_heap.hpp
---
