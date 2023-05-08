---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DynamicSegmentTree.test.cpp
    title: test/DynamicSegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/DynamicSegmentTree.hpp\"\n\r\n#include <memory>\r\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class Monoid, Monoid (*op)(Monoid, Monoid),\
    \ Monoid (*e)()>\r\nstruct DynamicSegmentTree {\r\n  private:\r\n    struct Node;\r\
    \n    using node_ptr = std::shared_ptr<Node>;\r\n    struct Node {\r\n       \
    \ Monoid val;\r\n        node_ptr left, right, par;\r\n        Node(node_ptr _par\
    \ = nullptr)\r\n            : val(e()), left(nullptr), right(nullptr), par(_par)\
    \ {}\r\n    };\r\n\r\n    node_ptr root;\r\n    int n;\r\n\r\n  public:\r\n  \
    \  DynamicSegmentTree(int _n = 0) : n(1) {\r\n        while (n < _n) {\r\n   \
    \         n <<= 1;\r\n        }\r\n        root = std::make_shared<Node>();\r\n\
    \    }\r\n\r\n    void set(int i, Monoid x) {\r\n        int l = 0, r = n;\r\n\
    \        node_ptr now = root;\r\n        while (r - l > 1) {\r\n            int\
    \ mid = (l + r) / 2;\r\n            if (i < mid) {\r\n                if (!now->left)\
    \ {\r\n                    now->left = std::make_shared<Node>(now);\r\n      \
    \          }\r\n                now = now->left;\r\n                r = mid;\r\
    \n            } else {\r\n                if (!now->right) {\r\n             \
    \       now->right = std::make_shared<Node>(now);\r\n                }\r\n   \
    \             now = now->right;\r\n                l = mid;\r\n            }\r\
    \n        }\r\n        now->val = x;\r\n        while (now->par) {\r\n       \
    \     now = now->par;\r\n            now->val = e();\r\n            if (now->left)\
    \ now->val = now->left->val;\r\n            if (now->right) now->val = op(now->val,\
    \ now->right->val);\r\n        }\r\n    }\r\n\r\n    Monoid prod(int tl, int tr,\
    \ int l = 0, int r = -1, node_ptr now = nullptr) {\r\n        if (!now) now =\
    \ root;\r\n        if (r < 0) r = n;\r\n        if (tr <= l || r <= tl) {\r\n\
    \            return e();\r\n        }\r\n        if (tl <= l && r <= tr) {\r\n\
    \            return now->val;\r\n        }\r\n        Monoid val = e();\r\n  \
    \      if (now->left) {\r\n            val = prod(tl, tr, l, (l + r) / 2, now->left);\r\
    \n        }\r\n        if (now->right) {\r\n            val = op(val, prod(tl,\
    \ tr, (l + r) / 2, r, now->right));\r\n        }\r\n        return val;\r\n  \
    \  }\r\n\r\n    Monoid all_prod() {\r\n        return root->val;\r\n    }\r\n\r\
    \n    Monoid get(int i) {\r\n        int l = 0;\r\n        int r = n;\r\n    \
    \    node_ptr now = root;\r\n        while (r - l > 1) {\r\n            int mid\
    \ = (l + r) / 2;\r\n            if (i < mid) {\r\n                if (!now->left)\
    \ return e();\r\n                now = now->left;\r\n                r = mid;\r\
    \n            } else {\r\n                if (!now->right) return e();\r\n   \
    \             now = now->right;\r\n                l = mid;\r\n            }\r\
    \n        }\r\n        return now->val;\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\r\n\r\n#include <memory>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct DynamicSegmentTree\
    \ {\r\n  private:\r\n    struct Node;\r\n    using node_ptr = std::shared_ptr<Node>;\r\
    \n    struct Node {\r\n        Monoid val;\r\n        node_ptr left, right, par;\r\
    \n        Node(node_ptr _par = nullptr)\r\n            : val(e()), left(nullptr),\
    \ right(nullptr), par(_par) {}\r\n    };\r\n\r\n    node_ptr root;\r\n    int\
    \ n;\r\n\r\n  public:\r\n    DynamicSegmentTree(int _n = 0) : n(1) {\r\n     \
    \   while (n < _n) {\r\n            n <<= 1;\r\n        }\r\n        root = std::make_shared<Node>();\r\
    \n    }\r\n\r\n    void set(int i, Monoid x) {\r\n        int l = 0, r = n;\r\n\
    \        node_ptr now = root;\r\n        while (r - l > 1) {\r\n            int\
    \ mid = (l + r) / 2;\r\n            if (i < mid) {\r\n                if (!now->left)\
    \ {\r\n                    now->left = std::make_shared<Node>(now);\r\n      \
    \          }\r\n                now = now->left;\r\n                r = mid;\r\
    \n            } else {\r\n                if (!now->right) {\r\n             \
    \       now->right = std::make_shared<Node>(now);\r\n                }\r\n   \
    \             now = now->right;\r\n                l = mid;\r\n            }\r\
    \n        }\r\n        now->val = x;\r\n        while (now->par) {\r\n       \
    \     now = now->par;\r\n            now->val = e();\r\n            if (now->left)\
    \ now->val = now->left->val;\r\n            if (now->right) now->val = op(now->val,\
    \ now->right->val);\r\n        }\r\n    }\r\n\r\n    Monoid prod(int tl, int tr,\
    \ int l = 0, int r = -1, node_ptr now = nullptr) {\r\n        if (!now) now =\
    \ root;\r\n        if (r < 0) r = n;\r\n        if (tr <= l || r <= tl) {\r\n\
    \            return e();\r\n        }\r\n        if (tl <= l && r <= tr) {\r\n\
    \            return now->val;\r\n        }\r\n        Monoid val = e();\r\n  \
    \      if (now->left) {\r\n            val = prod(tl, tr, l, (l + r) / 2, now->left);\r\
    \n        }\r\n        if (now->right) {\r\n            val = op(val, prod(tl,\
    \ tr, (l + r) / 2, r, now->right));\r\n        }\r\n        return val;\r\n  \
    \  }\r\n\r\n    Monoid all_prod() {\r\n        return root->val;\r\n    }\r\n\r\
    \n    Monoid get(int i) {\r\n        int l = 0;\r\n        int r = n;\r\n    \
    \    node_ptr now = root;\r\n        while (r - l > 1) {\r\n            int mid\
    \ = (l + r) / 2;\r\n            if (i < mid) {\r\n                if (!now->left)\
    \ return e();\r\n                now = now->left;\r\n                r = mid;\r\
    \n            } else {\r\n                if (!now->right) return e();\r\n   \
    \             now = now->right;\r\n                l = mid;\r\n            }\r\
    \n        }\r\n        return now->val;\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/DynamicSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DynamicSegmentTree.test.cpp
documentation_of: data_structure/DynamicSegmentTree.hpp
layout: document
redirect_from:
- /library/data_structure/DynamicSegmentTree.hpp
- /library/data_structure/DynamicSegmentTree.hpp.html
title: data_structure/DynamicSegmentTree.hpp
---
