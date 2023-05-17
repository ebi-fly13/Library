---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary_trie.test.cpp
    title: test/binary_trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://kazuma8128.hatenablog.com/entry/2018/05/06/022654
  bundledCode: "#line 2 \"data_structure/binary_trie.hpp\"\n\r\n/*\r\n    reference:\
    \ https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\r\n*/\r\n\r\n#include\
    \ <algorithm>\r\n#include <array>\r\n#include <cassert>\r\n#include <climits>\r\
    \n#include <memory>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct binary_trie\
    \ {\r\n  private:\r\n    struct Node;\r\n    using node_ptr = std::shared_ptr<Node>;\r\
    \n    struct Node {\r\n        int count = 0;\r\n        std::array<node_ptr,\
    \ 2> childs;\r\n        Node() = default;\r\n    };\r\n\r\n  public:\r\n    binary_trie()\
    \ = default;\r\n\r\n    void insert(const T x) {\r\n        node_ptr now = root;\r\
    \n        now->count++;\r\n        for (int i = bit_size - 1; i >= 0; i--) {\r\
    \n            int index = (x >> i) & 1;\r\n            if (now->childs[index]\
    \ == nullptr) {\r\n                now->childs[index] = std::make_shared<Node>();\r\
    \n            }\r\n            now = now->childs[index];\r\n            now->count++;\r\
    \n        }\r\n        return;\r\n    }\r\n\r\n    void erase(const T x) {\r\n\
    \        if (find(x) == false) return;\r\n        node_ptr now = root;\r\n   \
    \     now->count--;\r\n        for (int i = bit_size - 1; i >= 0; i--) {\r\n \
    \           int index = (x >> i) & 1;\r\n            assert(now->childs[index]);\r\
    \n            now = now->childs[index];\r\n            now->count--;\r\n     \
    \   }\r\n        return;\r\n    }\r\n\r\n    bool find(const T x) const {\r\n\
    \        node_ptr now = root;\r\n        for (int i = bit_size - 1; i >= 0; i--)\
    \ {\r\n            int index = (x >> i) & 1;\r\n            if (now->childs[index]\
    \ == nullptr) {\r\n                return false;\r\n            }\r\n        \
    \    now = now->childs[index];\r\n            if (now->count == 0) {\r\n     \
    \           return false;\r\n            }\r\n        }\r\n        return true;\r\
    \n    }\r\n\r\n    T min_element(const T x) const {\r\n        T val = 0;\r\n\
    \        node_ptr now = root;\r\n        for (int i = bit_size - 1; i >= 0; i--)\
    \ {\r\n            int index = ((x >> i) & 1);\r\n            if (now->childs[index]\
    \ && now->childs[index]->count > 0) {\r\n                now = now->childs[index];\r\
    \n            } else if (now->childs[index ^ 1] &&\r\n                       now->childs[index\
    \ ^ 1]->count > 0) {\r\n                val |= T(1) << i;\r\n                now\
    \ = now->childs[index ^ 1];\r\n            } else {\r\n                assert(0);\r\
    \n            }\r\n        }\r\n        return val;\r\n    }\r\n\r\n    T max_element(const\
    \ T x) const {\r\n        T val = 0;\r\n        node_ptr now = root;\r\n     \
    \   for (int i = bit_size - 1; i >= 0; i--) {\r\n            int index = ((x >>\
    \ i) & 1) ^ 1;\r\n            if (now->childs[index] && now->childs[index]->count\
    \ > 0) {\r\n                val |= T(1) << i;\r\n                now = now->childs[index];\r\
    \n            } else if (now->childs[index ^ 1] &&\r\n                       now->childs[index\
    \ ^ 1]->count > 0) {\r\n                now = now->childs[index ^ 1];\r\n    \
    \        } else {\r\n                assert(0);\r\n            }\r\n        }\r\
    \n    }\r\n\r\n    int size() const {\r\n        return root->count;\r\n    }\r\
    \n\r\n  private:\r\n    const size_t bit_size = sizeof(T) * CHAR_BIT;\r\n    node_ptr\
    \ root = std::make_shared<Node>();\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n/*\r\n    reference: https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\r\
    \n*/\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <cassert>\r\n\
    #include <climits>\r\n#include <memory>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class T> struct binary_trie {\r\n  private:\r\n    struct Node;\r\n    using\
    \ node_ptr = std::shared_ptr<Node>;\r\n    struct Node {\r\n        int count\
    \ = 0;\r\n        std::array<node_ptr, 2> childs;\r\n        Node() = default;\r\
    \n    };\r\n\r\n  public:\r\n    binary_trie() = default;\r\n\r\n    void insert(const\
    \ T x) {\r\n        node_ptr now = root;\r\n        now->count++;\r\n        for\
    \ (int i = bit_size - 1; i >= 0; i--) {\r\n            int index = (x >> i) &\
    \ 1;\r\n            if (now->childs[index] == nullptr) {\r\n                now->childs[index]\
    \ = std::make_shared<Node>();\r\n            }\r\n            now = now->childs[index];\r\
    \n            now->count++;\r\n        }\r\n        return;\r\n    }\r\n\r\n \
    \   void erase(const T x) {\r\n        if (find(x) == false) return;\r\n     \
    \   node_ptr now = root;\r\n        now->count--;\r\n        for (int i = bit_size\
    \ - 1; i >= 0; i--) {\r\n            int index = (x >> i) & 1;\r\n           \
    \ assert(now->childs[index]);\r\n            now = now->childs[index];\r\n   \
    \         now->count--;\r\n        }\r\n        return;\r\n    }\r\n\r\n    bool\
    \ find(const T x) const {\r\n        node_ptr now = root;\r\n        for (int\
    \ i = bit_size - 1; i >= 0; i--) {\r\n            int index = (x >> i) & 1;\r\n\
    \            if (now->childs[index] == nullptr) {\r\n                return false;\r\
    \n            }\r\n            now = now->childs[index];\r\n            if (now->count\
    \ == 0) {\r\n                return false;\r\n            }\r\n        }\r\n \
    \       return true;\r\n    }\r\n\r\n    T min_element(const T x) const {\r\n\
    \        T val = 0;\r\n        node_ptr now = root;\r\n        for (int i = bit_size\
    \ - 1; i >= 0; i--) {\r\n            int index = ((x >> i) & 1);\r\n         \
    \   if (now->childs[index] && now->childs[index]->count > 0) {\r\n           \
    \     now = now->childs[index];\r\n            } else if (now->childs[index ^\
    \ 1] &&\r\n                       now->childs[index ^ 1]->count > 0) {\r\n   \
    \             val |= T(1) << i;\r\n                now = now->childs[index ^ 1];\r\
    \n            } else {\r\n                assert(0);\r\n            }\r\n    \
    \    }\r\n        return val;\r\n    }\r\n\r\n    T max_element(const T x) const\
    \ {\r\n        T val = 0;\r\n        node_ptr now = root;\r\n        for (int\
    \ i = bit_size - 1; i >= 0; i--) {\r\n            int index = ((x >> i) & 1) ^\
    \ 1;\r\n            if (now->childs[index] && now->childs[index]->count > 0) {\r\
    \n                val |= T(1) << i;\r\n                now = now->childs[index];\r\
    \n            } else if (now->childs[index ^ 1] &&\r\n                       now->childs[index\
    \ ^ 1]->count > 0) {\r\n                now = now->childs[index ^ 1];\r\n    \
    \        } else {\r\n                assert(0);\r\n            }\r\n        }\r\
    \n    }\r\n\r\n    int size() const {\r\n        return root->count;\r\n    }\r\
    \n\r\n  private:\r\n    const size_t bit_size = sizeof(T) * CHAR_BIT;\r\n    node_ptr\
    \ root = std::make_shared<Node>();\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binary_trie.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.hpp
- /library/data_structure/binary_trie.hpp.html
title: data_structure/binary_trie.hpp
---