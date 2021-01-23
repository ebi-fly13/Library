---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/BinaryTrie.hpp
    title: data_structure/BinaryTrie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/BinaryTrie.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \r\n\r\n#line 2 \"data_structure/BinaryTrie.hpp\"\n\r\n/*\r\n    reference: https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\r\
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
    \ ebi\n#line 4 \"test/BinaryTrie.test.cpp\"\n\r\n#include <iostream>\r\n\r\nint\
    \ main(){\r\n    int q;\r\n    std::cin >> q;\r\n    ebi::BinaryTrie<int> set(31);\r\
    \n    while(q--) {\r\n        int t, x;\r\n        std::cin >> t >> x;\r\n   \
    \     if(t==0) {\r\n            if(!set.find(x)) {\r\n                set.insert(x);\r\
    \n            }\r\n        }\r\n        else if(t==1) {\r\n            set.erase(x);\r\
    \n        }\r\n        else {\r\n            std::cout << set.min_element(x) <<\
    \ std::endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\r\n\r\n#include\
    \ \"../data_structure/BinaryTrie.hpp\"\r\n\r\n#include <iostream>\r\n\r\nint main(){\r\
    \n    int q;\r\n    std::cin >> q;\r\n    ebi::BinaryTrie<int> set(31);\r\n  \
    \  while(q--) {\r\n        int t, x;\r\n        std::cin >> t >> x;\r\n      \
    \  if(t==0) {\r\n            if(!set.find(x)) {\r\n                set.insert(x);\r\
    \n            }\r\n        }\r\n        else if(t==1) {\r\n            set.erase(x);\r\
    \n        }\r\n        else {\r\n            std::cout << set.min_element(x) <<\
    \ std::endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/BinaryTrie.hpp
  isVerificationFile: true
  path: test/BinaryTrie.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BinaryTrie.test.cpp
layout: document
redirect_from:
- /verify/test/BinaryTrie.test.cpp
- /verify/test/BinaryTrie.test.cpp.html
title: test/BinaryTrie.test.cpp
---
