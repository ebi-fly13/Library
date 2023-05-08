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
  bundledCode: "#line 2 \"data_structure/range_query_binary_trie.hpp\"\n\n#include\
    \ <array>\n#include <cassert>\n#include <limits>\n#include <memory>\n#include\
    \ <set>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T, int BIT_SIZE>\
    \ struct range_query_binary_trie {\n  private:\n    struct Node;\n    using node_ptr\
    \ = std::shared_ptr<Node>;\n    struct Node {\n        std::array<node_ptr, 2>\
    \ child;\n        std::set<int> set = {1'000'000'000};\n\n        Node() = default;\n\
    \    };\n\n    void insert(int idx) {\n        T x = a[idx];\n        node_ptr\
    \ now = root;\n        now->set.insert(idx);\n        for (int i = BIT_SIZE -\
    \ 1; i >= 0; i--) {\n            int index = (x >> i) & 1;\n            if (now->child[index]\
    \ == nullptr) {\n                now->child[index] = std::make_shared<Node>();\n\
    \            }\n            now = now->child[index];\n            now->set.insert(idx);\n\
    \        }\n    }\n\n    void erase(int idx) {\n        T x = a[idx];\n      \
    \  node_ptr now = root;\n        now->set.erase(idx);\n        for (int i = BIT_SIZE\
    \ - 1; i >= 0; i--) {\n            int index = (x >> i) & 1;\n            now\
    \ = now->child[index];\n            now->set.erase(idx);\n        }\n    }\n\n\
    \  public:\n    range_query_binary_trie(const std::vector<T> &a) : a(a) {\n  \
    \      for (int i = 0; i < (int)a.size(); i++) insert(i);\n    }\n\n    void set(int\
    \ idx, T x) {\n        erase(idx);\n        a[idx] = x;\n        insert(idx);\n\
    \    }\n\n    T get(int idx) const {\n        return a[idx];\n    }\n\n    T min_element(int\
    \ l, int r, T x) {\n        T val = 0;\n        node_ptr now = root;\n       \
    \ for (int i = BIT_SIZE - 1; i >= 0; i--) {\n            int index = (x >> i)\
    \ & 1;\n            if (now->child[index] &&\n                *now->child[index]->set.lower_bound(l)\
    \ < r) {\n                now = now->child[index];\n            } else if (now->child[index\
    \ ^ 1] &&\n                       *now->child[index ^ 1]->set.lower_bound(l) <\
    \ r) {\n                now = now->child[index ^ 1];\n                val |= T(1)\
    \ << i;\n            } else {\n                assert(0);\n            }\n   \
    \     }\n        return val;\n    }\n\n  private:\n    std::vector<T> a;\n   \
    \ node_ptr root = std::make_shared<Node>();\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <limits>\n\
    #include <memory>\n#include <set>\n#include <vector>\n\nnamespace ebi {\n\ntemplate\
    \ <class T, int BIT_SIZE> struct range_query_binary_trie {\n  private:\n    struct\
    \ Node;\n    using node_ptr = std::shared_ptr<Node>;\n    struct Node {\n    \
    \    std::array<node_ptr, 2> child;\n        std::set<int> set = {1'000'000'000};\n\
    \n        Node() = default;\n    };\n\n    void insert(int idx) {\n        T x\
    \ = a[idx];\n        node_ptr now = root;\n        now->set.insert(idx);\n   \
    \     for (int i = BIT_SIZE - 1; i >= 0; i--) {\n            int index = (x >>\
    \ i) & 1;\n            if (now->child[index] == nullptr) {\n                now->child[index]\
    \ = std::make_shared<Node>();\n            }\n            now = now->child[index];\n\
    \            now->set.insert(idx);\n        }\n    }\n\n    void erase(int idx)\
    \ {\n        T x = a[idx];\n        node_ptr now = root;\n        now->set.erase(idx);\n\
    \        for (int i = BIT_SIZE - 1; i >= 0; i--) {\n            int index = (x\
    \ >> i) & 1;\n            now = now->child[index];\n            now->set.erase(idx);\n\
    \        }\n    }\n\n  public:\n    range_query_binary_trie(const std::vector<T>\
    \ &a) : a(a) {\n        for (int i = 0; i < (int)a.size(); i++) insert(i);\n \
    \   }\n\n    void set(int idx, T x) {\n        erase(idx);\n        a[idx] = x;\n\
    \        insert(idx);\n    }\n\n    T get(int idx) const {\n        return a[idx];\n\
    \    }\n\n    T min_element(int l, int r, T x) {\n        T val = 0;\n       \
    \ node_ptr now = root;\n        for (int i = BIT_SIZE - 1; i >= 0; i--) {\n  \
    \          int index = (x >> i) & 1;\n            if (now->child[index] &&\n \
    \               *now->child[index]->set.lower_bound(l) < r) {\n              \
    \  now = now->child[index];\n            } else if (now->child[index ^ 1] &&\n\
    \                       *now->child[index ^ 1]->set.lower_bound(l) < r) {\n  \
    \              now = now->child[index ^ 1];\n                val |= T(1) << i;\n\
    \            } else {\n                assert(0);\n            }\n        }\n\
    \        return val;\n    }\n\n  private:\n    std::vector<T> a;\n    node_ptr\
    \ root = std::make_shared<Node>();\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/range_query_binary_trie.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/range_query_binary_trie.hpp
layout: document
redirect_from:
- /library/data_structure/range_query_binary_trie.hpp
- /library/data_structure/range_query_binary_trie.hpp.html
title: data_structure/range_query_binary_trie.hpp
---
