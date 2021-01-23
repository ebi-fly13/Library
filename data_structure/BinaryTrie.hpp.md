---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BinaryTrie.test.cpp
    title: test/BinaryTrie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://kazuma8128.hatenablog.com/entry/2018/05/06/022654
  bundledCode: "#line 2 \"data_structure/BinaryTrie.hpp\"\n\r\n/*\r\n    reference:\
    \ https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\r\n*/\r\n\r\n#include\
    \ <algorithm>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct BinaryTrie\
    \ {\r\nprivate:\r\n    struct Node {\r\n        int cnt;\r\n        Node *chr[2]\
    \ = {nullptr, nullptr};\r\n        Node(int c=0) : cnt(c) { }\r\n    };\r\n\r\n\
    \    using node_ptr = Node*;\r\n\r\n    node_ptr root;\r\n\r\n    int bit_size;\r\
    \npublic:\r\n    BinaryTrie(int bit_size = 32) : bit_size(bit_size) {\r\n    \
    \    root = new Node();\r\n    } \r\n\r\n    void insert(T x) {\r\n        node_ptr\
    \ now = root;\r\n        now->cnt++;\r\n        for(int i = bit_size-1; i>=0;\
    \ i--) {\r\n            int p =  (x & ((T)1 << i))>0;\r\n            if(!now->chr[p])\
    \ {\r\n                now->chr[p] = new Node();\r\n            }\r\n        \
    \    now = now->chr[p];\r\n            now->cnt++;\r\n        }\r\n    }\r\n\r\
    \n    void erase(T x) {\r\n        if(!find(x)) return;\r\n        node_ptr now\
    \ = root;\r\n        now->cnt--;\r\n        for(int i = bit_size-1; i>=0; i--)\
    \ {\r\n            int p = (x & ((T)1 << i)) > 0;\r\n            if(!now->chr[p])\
    \ {\r\n                return;\r\n            }\r\n            now = now->chr[p];\r\
    \n            now->cnt--;\r\n        }\r\n    }\r\n\r\n    bool find(T x) const\
    \ {\r\n        node_ptr now = root;\r\n        for(int i = bit_size-1; i>=0; i--)\
    \ {\r\n            int p = (x & ((T)1 << i)) > 0;\r\n            if((!now->chr[p])\
    \ || now->chr[p]->cnt == 0) {\r\n                return false;\r\n           \
    \ }\r\n            now = now->chr[p];\r\n        }\r\n        return true;\r\n\
    \    }\r\n\r\n    T max_element() const {\r\n        T val = 0;\r\n        node_ptr\
    \ now = root;\r\n        for(int i = bit_size-1; i>=0; i--) {\r\n            if(now->chr[1]\
    \ && now->chr[1] > 0) {\r\n                val |= (T)1 << i;\r\n             \
    \   now = now->chr[1];\r\n            }\r\n            else {\r\n            \
    \    now = now->chr[0];\r\n            }\r\n        }\r\n        return val;\r\
    \n    }\r\n\r\n    T min_element() const {\r\n        T val = 0;\r\n        node_ptr\
    \ now = root;\r\n        for(int i = bit_size-1; i>=0; i--) {\r\n            if(now->chr[0]\
    \ && now->chr[0] > 0) {\r\n                now = now->chr[0];\r\n            }\r\
    \n            else {\r\n                val |= (T)1 << i;\r\n                now\
    \ = now->chr[1];\r\n            }\r\n        }\r\n        return val;\r\n    }\r\
    \n\r\n    T max_element(T x) const {\r\n        node_ptr now = root;\r\n     \
    \   for(int i = bit_size-1; i>=0; i--) {\r\n            int p = (x & ((T)1 <<\
    \ i)) > 0;\r\n            int q = std::abs(p-1);\r\n            if(now->chr[q]\
    \ && now->chr[q]->cnt > 0) {\r\n                if(q) x ^= ((T)1 << i);\r\n  \
    \              now = now->chr[q];\r\n            }\r\n            else {\r\n \
    \               if(p) x ^= ((T)1 << i);\r\n                now = now->chr[p];\r\
    \n            }\r\n        }\r\n        return x;\r\n    }\r\n\r\n    T min_element(T\
    \ x) const {\r\n        node_ptr now = root;\r\n        for(int i = bit_size-1;\
    \ i>=0; i--) {\r\n            int p = (x & ((T)1 << i)) > 0;\r\n            if(now->chr[p]\
    \ && now->chr[p]->cnt > 0) {\r\n                if(p) x ^= ((T)1 << i);\r\n  \
    \              now = now->chr[p];\r\n            }\r\n            else {\r\n \
    \               if(p==0) x ^= (T)1 << i;\r\n                now = now->chr[std::abs(p-1)];\r\
    \n            }\r\n        }\r\n        return x;\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi\n"
  code: "#pragma once\r\n\r\n/*\r\n    reference: https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\r\
    \n*/\r\n\r\n#include <algorithm>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class\
    \ T>\r\nstruct BinaryTrie {\r\nprivate:\r\n    struct Node {\r\n        int cnt;\r\
    \n        Node *chr[2] = {nullptr, nullptr};\r\n        Node(int c=0) : cnt(c)\
    \ { }\r\n    };\r\n\r\n    using node_ptr = Node*;\r\n\r\n    node_ptr root;\r\
    \n\r\n    int bit_size;\r\npublic:\r\n    BinaryTrie(int bit_size = 32) : bit_size(bit_size)\
    \ {\r\n        root = new Node();\r\n    } \r\n\r\n    void insert(T x) {\r\n\
    \        node_ptr now = root;\r\n        now->cnt++;\r\n        for(int i = bit_size-1;\
    \ i>=0; i--) {\r\n            int p =  (x & ((T)1 << i))>0;\r\n            if(!now->chr[p])\
    \ {\r\n                now->chr[p] = new Node();\r\n            }\r\n        \
    \    now = now->chr[p];\r\n            now->cnt++;\r\n        }\r\n    }\r\n\r\
    \n    void erase(T x) {\r\n        if(!find(x)) return;\r\n        node_ptr now\
    \ = root;\r\n        now->cnt--;\r\n        for(int i = bit_size-1; i>=0; i--)\
    \ {\r\n            int p = (x & ((T)1 << i)) > 0;\r\n            if(!now->chr[p])\
    \ {\r\n                return;\r\n            }\r\n            now = now->chr[p];\r\
    \n            now->cnt--;\r\n        }\r\n    }\r\n\r\n    bool find(T x) const\
    \ {\r\n        node_ptr now = root;\r\n        for(int i = bit_size-1; i>=0; i--)\
    \ {\r\n            int p = (x & ((T)1 << i)) > 0;\r\n            if((!now->chr[p])\
    \ || now->chr[p]->cnt == 0) {\r\n                return false;\r\n           \
    \ }\r\n            now = now->chr[p];\r\n        }\r\n        return true;\r\n\
    \    }\r\n\r\n    T max_element() const {\r\n        T val = 0;\r\n        node_ptr\
    \ now = root;\r\n        for(int i = bit_size-1; i>=0; i--) {\r\n            if(now->chr[1]\
    \ && now->chr[1] > 0) {\r\n                val |= (T)1 << i;\r\n             \
    \   now = now->chr[1];\r\n            }\r\n            else {\r\n            \
    \    now = now->chr[0];\r\n            }\r\n        }\r\n        return val;\r\
    \n    }\r\n\r\n    T min_element() const {\r\n        T val = 0;\r\n        node_ptr\
    \ now = root;\r\n        for(int i = bit_size-1; i>=0; i--) {\r\n            if(now->chr[0]\
    \ && now->chr[0] > 0) {\r\n                now = now->chr[0];\r\n            }\r\
    \n            else {\r\n                val |= (T)1 << i;\r\n                now\
    \ = now->chr[1];\r\n            }\r\n        }\r\n        return val;\r\n    }\r\
    \n\r\n    T max_element(T x) const {\r\n        node_ptr now = root;\r\n     \
    \   for(int i = bit_size-1; i>=0; i--) {\r\n            int p = (x & ((T)1 <<\
    \ i)) > 0;\r\n            int q = std::abs(p-1);\r\n            if(now->chr[q]\
    \ && now->chr[q]->cnt > 0) {\r\n                if(q) x ^= ((T)1 << i);\r\n  \
    \              now = now->chr[q];\r\n            }\r\n            else {\r\n \
    \               if(p) x ^= ((T)1 << i);\r\n                now = now->chr[p];\r\
    \n            }\r\n        }\r\n        return x;\r\n    }\r\n\r\n    T min_element(T\
    \ x) const {\r\n        node_ptr now = root;\r\n        for(int i = bit_size-1;\
    \ i>=0; i--) {\r\n            int p = (x & ((T)1 << i)) > 0;\r\n            if(now->chr[p]\
    \ && now->chr[p]->cnt > 0) {\r\n                if(p) x ^= ((T)1 << i);\r\n  \
    \              now = now->chr[p];\r\n            }\r\n            else {\r\n \
    \               if(p==0) x ^= (T)1 << i;\r\n                now = now->chr[std::abs(p-1)];\r\
    \n            }\r\n        }\r\n        return x;\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BinaryTrie.test.cpp
documentation_of: data_structure/BinaryTrie.hpp
layout: document
redirect_from:
- /library/data_structure/BinaryTrie.hpp
- /library/data_structure/BinaryTrie.hpp.html
title: data_structure/BinaryTrie.hpp
---
