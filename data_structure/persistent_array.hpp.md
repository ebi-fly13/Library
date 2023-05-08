---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/persistent_unionfind.hpp
    title: data_structure/persistent_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/persistent_unionfind.test.cpp
    title: test/persistent_unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://37zigen.com/persistent-array/
  bundledCode: "#line 2 \"data_structure/persistent_array.hpp\"\n\r\n#include <cstdint>\r\
    \n#include <vector>\r\n#include <memory>\r\n#include <cassert>\r\n\r\n/*\r\n \
    \   reference: https://37zigen.com/persistent-array/\r\n*/\r\n\r\nnamespace ebi\
    \ {\r\n\r\ntemplate<class T, std::size_t m>\r\nstruct persistent_array {\r\nprivate:\r\
    \n    struct Node;\r\n    using node_ptr = std::shared_ptr<Node>;\r\n    using\
    \ size_t = std::size_t;\r\n    struct Node {\r\n        T val;\r\n        std::vector<node_ptr>\
    \ chr;\r\n        Node(T val, std::vector<node_ptr> chr = std::vector<node_ptr>(m))\
    \ : val(val), chr(chr) { }\r\n        node_ptr get_chr(int i) {\r\n          \
    \  return chr[i];\r\n        }\r\n        void update_chr(int i, node_ptr node)\
    \ {\r\n            chr[i] = node;\r\n        }\r\n    };\r\n\r\n    std::vector<node_ptr>\
    \ root;\r\n    int now;\r\n\r\npublic:\r\n    persistent_array(std::size_t n,\
    \ T val) : now(0) {\r\n        root.emplace_back(std::make_shared<Node>(val));\r\
    \n        for(size_t i = 1; i < n; i++) {\r\n            node_ptr node = root[0];\r\
    \n            size_t ret = i;\r\n            while(ret > 0) {\r\n            \
    \    if(node->chr[ret%m] == nullptr) {\r\n                    node->chr[ret%m]\
    \ = std::make_shared<Node>(val);\r\n                }\r\n                node\
    \ = node->chr[ret%m];\r\n                ret /= m;\r\n            }\r\n      \
    \      if(node == nullptr) {\r\n                node = std::make_shared<Node>(val);\r\
    \n            }\r\n        }\r\n    }\r\n\r\n    persistent_array(std::vector<T>\
    \ a) : now(0) {\r\n        size_t n = a.size();\r\n        root.emplace_back(std::make_shared<Node>(a[0]));\r\
    \n        for(size_t i = 1; i < n; i++) {\r\n            node_ptr node = root[0];\r\
    \n            size_t ret = i;\r\n            while(ret > 0) {\r\n            \
    \    if(node->chr[ret%m] == nullptr) {\r\n                    node->chr[ret%m]\
    \ = std::make_shared<Node>(a[i]);\r\n                }\r\n                node\
    \ = node->chr[ret%m];\r\n                ret /= m;\r\n            }\r\n      \
    \      if(node == nullptr) {\r\n                node = std::make_shared<Node>(a[i]);\r\
    \n            }\r\n        }\r\n    }\r\n\r\n    T get(size_t i, int time = -1)\
    \ {\r\n        assert(time <= now);\r\n        if(time < 0) time = now;\r\n  \
    \      node_ptr node = root[time];\r\n        while(i > 0) {\r\n            node\
    \ = node->chr[i%m];\r\n            i /= m;\r\n        }\r\n        return node->val;\r\
    \n    }\r\n\r\n    void set(size_t i, T val, int time = -1) {\r\n        if(time\
    \ < 0) time = now;\r\n        assert(time <= now);\r\n        node_ptr p = root[time];\r\
    \n        node_ptr node = std::make_shared<Node>(p->val, p->chr);\r\n        root.emplace_back(node);\r\
    \n        while(i > 0) {\r\n            p = p->chr[i%m];\r\n            node->chr[i%m]\
    \ = std::make_shared<Node>(p->val, p->chr);\r\n            node = node->chr[i%m];\r\
    \n            i /= m;\r\n        }\r\n        node->val = val;\r\n        now++;\r\
    \n    }\r\n\r\n    void add(size_t i, T rhs, int time = -1) {\r\n        if(time\
    \ < 0) time = now;\r\n        assert(time <= now);\r\n        node_ptr p = root[time];\r\
    \n        node_ptr node = std::make_shared<Node>(p->val, p->chr);\r\n        root.emplace_back(node);\r\
    \n        while(i > 0) {\r\n            p = p->chr[i%m];\r\n            node->chr[i%m]\
    \ = std::make_shared<Node>(p->val, p->chr);\r\n            node = node->chr[i%m];\r\
    \n            i /= m;\r\n        }\r\n        node->val += rhs;\r\n        now++;\r\
    \n    } \r\n\r\n    void update(size_t i, T rhs, int time = -1) {\r\n        if(time\
    \ < 0) time = now;\r\n        assert(time <= now);\r\n        node_ptr node =\
    \ root[time];\r\n        node_ptr p = root[time];\r\n        while(i > 0) {\r\n\
    \            p = p->chr[i%m];\r\n            node->chr[i%m] = std::make_shared<Node>(p->val,\
    \ p->chr);\r\n            node = node->chr[i%m];\r\n            i /= m;\r\n  \
    \      }\r\n        node->val = rhs;\r\n    }\r\n};\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <cstdint>\r\n#include <vector>\r\n#include <memory>\r\
    \n#include <cassert>\r\n\r\n/*\r\n    reference: https://37zigen.com/persistent-array/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T, std::size_t m>\r\nstruct\
    \ persistent_array {\r\nprivate:\r\n    struct Node;\r\n    using node_ptr = std::shared_ptr<Node>;\r\
    \n    using size_t = std::size_t;\r\n    struct Node {\r\n        T val;\r\n \
    \       std::vector<node_ptr> chr;\r\n        Node(T val, std::vector<node_ptr>\
    \ chr = std::vector<node_ptr>(m)) : val(val), chr(chr) { }\r\n        node_ptr\
    \ get_chr(int i) {\r\n            return chr[i];\r\n        }\r\n        void\
    \ update_chr(int i, node_ptr node) {\r\n            chr[i] = node;\r\n       \
    \ }\r\n    };\r\n\r\n    std::vector<node_ptr> root;\r\n    int now;\r\n\r\npublic:\r\
    \n    persistent_array(std::size_t n, T val) : now(0) {\r\n        root.emplace_back(std::make_shared<Node>(val));\r\
    \n        for(size_t i = 1; i < n; i++) {\r\n            node_ptr node = root[0];\r\
    \n            size_t ret = i;\r\n            while(ret > 0) {\r\n            \
    \    if(node->chr[ret%m] == nullptr) {\r\n                    node->chr[ret%m]\
    \ = std::make_shared<Node>(val);\r\n                }\r\n                node\
    \ = node->chr[ret%m];\r\n                ret /= m;\r\n            }\r\n      \
    \      if(node == nullptr) {\r\n                node = std::make_shared<Node>(val);\r\
    \n            }\r\n        }\r\n    }\r\n\r\n    persistent_array(std::vector<T>\
    \ a) : now(0) {\r\n        size_t n = a.size();\r\n        root.emplace_back(std::make_shared<Node>(a[0]));\r\
    \n        for(size_t i = 1; i < n; i++) {\r\n            node_ptr node = root[0];\r\
    \n            size_t ret = i;\r\n            while(ret > 0) {\r\n            \
    \    if(node->chr[ret%m] == nullptr) {\r\n                    node->chr[ret%m]\
    \ = std::make_shared<Node>(a[i]);\r\n                }\r\n                node\
    \ = node->chr[ret%m];\r\n                ret /= m;\r\n            }\r\n      \
    \      if(node == nullptr) {\r\n                node = std::make_shared<Node>(a[i]);\r\
    \n            }\r\n        }\r\n    }\r\n\r\n    T get(size_t i, int time = -1)\
    \ {\r\n        assert(time <= now);\r\n        if(time < 0) time = now;\r\n  \
    \      node_ptr node = root[time];\r\n        while(i > 0) {\r\n            node\
    \ = node->chr[i%m];\r\n            i /= m;\r\n        }\r\n        return node->val;\r\
    \n    }\r\n\r\n    void set(size_t i, T val, int time = -1) {\r\n        if(time\
    \ < 0) time = now;\r\n        assert(time <= now);\r\n        node_ptr p = root[time];\r\
    \n        node_ptr node = std::make_shared<Node>(p->val, p->chr);\r\n        root.emplace_back(node);\r\
    \n        while(i > 0) {\r\n            p = p->chr[i%m];\r\n            node->chr[i%m]\
    \ = std::make_shared<Node>(p->val, p->chr);\r\n            node = node->chr[i%m];\r\
    \n            i /= m;\r\n        }\r\n        node->val = val;\r\n        now++;\r\
    \n    }\r\n\r\n    void add(size_t i, T rhs, int time = -1) {\r\n        if(time\
    \ < 0) time = now;\r\n        assert(time <= now);\r\n        node_ptr p = root[time];\r\
    \n        node_ptr node = std::make_shared<Node>(p->val, p->chr);\r\n        root.emplace_back(node);\r\
    \n        while(i > 0) {\r\n            p = p->chr[i%m];\r\n            node->chr[i%m]\
    \ = std::make_shared<Node>(p->val, p->chr);\r\n            node = node->chr[i%m];\r\
    \n            i /= m;\r\n        }\r\n        node->val += rhs;\r\n        now++;\r\
    \n    } \r\n\r\n    void update(size_t i, T rhs, int time = -1) {\r\n        if(time\
    \ < 0) time = now;\r\n        assert(time <= now);\r\n        node_ptr node =\
    \ root[time];\r\n        node_ptr p = root[time];\r\n        while(i > 0) {\r\n\
    \            p = p->chr[i%m];\r\n            node->chr[i%m] = std::make_shared<Node>(p->val,\
    \ p->chr);\r\n            node = node->chr[i%m];\r\n            i /= m;\r\n  \
    \      }\r\n        node->val = rhs;\r\n    }\r\n};\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/persistent_array.hpp
  requiredBy:
  - data_structure/persistent_unionfind.hpp
  timestamp: '2021-04-02 19:30:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/persistent_unionfind.test.cpp
documentation_of: data_structure/persistent_array.hpp
layout: document
redirect_from:
- /library/data_structure/persistent_array.hpp
- /library/data_structure/persistent_array.hpp.html
title: data_structure/persistent_array.hpp
---
