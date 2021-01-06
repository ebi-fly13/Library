---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/SWAG.hpp\"\n\r\n#include <stack>\r\n#include\
    \ <cassert>\r\n\r\ntemplate<class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\r\
    \nstruct SWAG {\r\nprivate:\r\n    struct Node {\r\n        Semigroup value;\r\
    \n        Semigroup fold_back;\r\n        Node(Semigroup value, Semigroup fold_back)\
    \ : value(value), fold_back(fold_back) { }\r\n    };\r\n\r\n    void move() {\r\
    \n        assert(!back.empty());\r\n        Node p = back.top();\r\n        back.pop();\r\
    \n        front.push(Node(p.value, p.value));\r\n        while(!back.empty())\
    \ {\r\n            Node p = back.top();\r\n            back.pop();\r\n       \
    \     p.fold_back = op(p.value, front.top().fold_back);\r\n            front.push(p);\r\
    \n        }\r\n    }\r\n\r\n    std::stack<Node> front, back;\r\n\r\npublic:\r\
    \n\r\n    SWAG() { }\r\n\r\n    int size() {\r\n        return front.size() +\
    \ back.size();\r\n    }\r\n\r\n    bool empty() {\r\n        if(size()==0) return\
    \ true;\r\n        return false;\r\n    }\r\n\r\n    void push(Semigroup x) {\r\
    \n        Node node(x,x);\r\n        if(back.size()!=0) {\r\n            Node\
    \ p = back.top();\r\n            node.fold_back = op(p.fold_back, node.fold_back);\r\
    \n        }\r\n        back.push(node);\r\n    }\r\n\r\n    void pop() {\r\n \
    \       assert(!empty());\r\n        if(front.empty()) {\r\n            move();\r\
    \n        }\r\n        front.pop();\r\n    }\r\n\r\n    Semigroup fold_all() {\r\
    \n        assert(!empty());\r\n        if(front.empty()) {\r\n            return\
    \ back.top().fold_back;\r\n        }\r\n        else if(back.empty()){\r\n   \
    \         return front.top().fold_back;\r\n        }\r\n        else{\r\n    \
    \        return op(front.top().fold_back, back.top().fold_back);\r\n        }\r\
    \n    }\r\n};\n"
  code: "#pragma once\r\n\r\n#include <stack>\r\n#include <cassert>\r\n\r\ntemplate<class\
    \ Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\r\nstruct SWAG {\r\nprivate:\r\
    \n    struct Node {\r\n        Semigroup value;\r\n        Semigroup fold_back;\r\
    \n        Node(Semigroup value, Semigroup fold_back) : value(value), fold_back(fold_back)\
    \ { }\r\n    };\r\n\r\n    void move() {\r\n        assert(!back.empty());\r\n\
    \        Node p = back.top();\r\n        back.pop();\r\n        front.push(Node(p.value,\
    \ p.value));\r\n        while(!back.empty()) {\r\n            Node p = back.top();\r\
    \n            back.pop();\r\n            p.fold_back = op(p.value, front.top().fold_back);\r\
    \n            front.push(p);\r\n        }\r\n    }\r\n\r\n    std::stack<Node>\
    \ front, back;\r\n\r\npublic:\r\n\r\n    SWAG() { }\r\n\r\n    int size() {\r\n\
    \        return front.size() + back.size();\r\n    }\r\n\r\n    bool empty() {\r\
    \n        if(size()==0) return true;\r\n        return false;\r\n    }\r\n\r\n\
    \    void push(Semigroup x) {\r\n        Node node(x,x);\r\n        if(back.size()!=0)\
    \ {\r\n            Node p = back.top();\r\n            node.fold_back = op(p.fold_back,\
    \ node.fold_back);\r\n        }\r\n        back.push(node);\r\n    }\r\n\r\n \
    \   void pop() {\r\n        assert(!empty());\r\n        if(front.empty()) {\r\
    \n            move();\r\n        }\r\n        front.pop();\r\n    }\r\n\r\n  \
    \  Semigroup fold_all() {\r\n        assert(!empty());\r\n        if(front.empty())\
    \ {\r\n            return back.top().fold_back;\r\n        }\r\n        else if(back.empty()){\r\
    \n            return front.top().fold_back;\r\n        }\r\n        else{\r\n\
    \            return op(front.top().fold_back, back.top().fold_back);\r\n     \
    \   }\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/SWAG.hpp
  requiredBy: []
  timestamp: '2021-01-06 12:29:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/SWAG.hpp
layout: document
redirect_from:
- /library/data_structure/SWAG.hpp
- /library/data_structure/SWAG.hpp.html
title: data_structure/SWAG.hpp
---
