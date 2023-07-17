---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Range_Sum_Persistent_Segtree.test.cpp
    title: test/data_structure/Point_Add_Range_Sum_Persistent_Segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://37zigen.com/persistent-segment-tree/
  bundledCode: "#line 2 \"data_structure/PersistentSegmentTree.hpp\"\n\r\n#include\
    \ <cassert>\r\n#include <vector>\r\n\r\n/*\r\n    reference: https://37zigen.com/persistent-segment-tree/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class Monoid, Monoid (*op)(Monoid,\
    \ Monoid), Monoid (*e)()>\r\nstruct PersistentSegmentTree {\r\n  private:\r\n\
    \    struct Node {\r\n        Monoid val;\r\n        Node *left, *right, *par;\r\
    \n        Node(Node *par = nullptr)\r\n            : val(e()), left(nullptr),\
    \ right(nullptr), par(par) {}\r\n        void update() {\r\n            val =\
    \ e();\r\n            if (left != nullptr) val = left->val;\r\n            if\
    \ (right != nullptr) val = op(val, right->val);\r\n        }\r\n    };\r\n\r\n\
    \    using node_ptr = Node *;\r\n\r\n    std::vector<node_ptr> roots;\r\n\r\n\
    \    int n;\r\n    int time;\r\n\r\n    Monoid prod(int l, int r, int nl, int\
    \ nr, node_ptr now) {\r\n        if (now == nullptr || nr <= l || r <= nl) return\
    \ e();\r\n        if (l <= nl && nr <= r) return now->val;\r\n        return op(prod(l,\
    \ r, nl, (nl + nr) / 2, now->left),\r\n                  prod(l, r, (nl + nr)\
    \ / 2, nr, now->right));\r\n    }\r\n\r\n  public:\r\n    PersistentSegmentTree(int\
    \ _n) : n(1), time(1) {\r\n        while (n < _n) {\r\n            n <<= 1;\r\n\
    \        }\r\n        roots.emplace_back(new Node());\r\n    }\r\n\r\n    PersistentSegmentTree(std::vector<Monoid>\
    \ v) : n(1), time(1) {\r\n        int _n = v.size();\r\n        while (n < _n)\
    \ {\r\n            n <<= 1;\r\n        }\r\n        auto dfs = [&](auto dfs, int\
    \ l, int r, node_ptr now) -> void {\r\n            assert(now != nullptr);\r\n\
    \            if (_n <= l) return;\r\n            if (r - l == 1) {\r\n       \
    \         now->val = v[l];\r\n                return;\r\n            }\r\n   \
    \         int mid = (l + r) / 2;\r\n            if (now->left == nullptr) now->left\
    \ = new Node(now);\r\n            if (now->right == nullptr) now->right = new\
    \ Node(now);\r\n            dfs(dfs, l, mid, now->left);\r\n            dfs(dfs,\
    \ mid, r, now->right);\r\n            now->update();\r\n        };\r\n       \
    \ node_ptr root = new Node();\r\n        roots.emplace_back(root);\r\n       \
    \ dfs(dfs, 0, n, root);\r\n    }\r\n\r\n    void set(int ver, int i, Monoid x)\
    \ {\r\n        assert(0 <= ver && ver < time);\r\n        node_ptr now = new Node();\r\
    \n        node_ptr p = roots[ver];\r\n        roots.emplace_back(now);\r\n   \
    \     time++;\r\n        int l = 0, r = n;\r\n        while (r - l > 1) {\r\n\
    \            int mid = (r + l) / 2;\r\n            if (i < mid) {\r\n        \
    \        r = mid;\r\n                now->left = new Node(now);\r\n          \
    \      if (p != nullptr) {\r\n                    now->right = p->right;\r\n \
    \                   p = p->left;\r\n                }\r\n                now =\
    \ now->left;\r\n            } else {\r\n                l = mid;\r\n         \
    \       now->right = new Node(now);\r\n                if (p != nullptr) {\r\n\
    \                    now->left = p->left;\r\n                    p = p->right;\r\
    \n                }\r\n                now = now->right;\r\n            }\r\n\
    \        }\r\n        now->val = x;\r\n        while (now->par) {\r\n        \
    \    now = now->par;\r\n            now->update();\r\n        }\r\n    }\r\n\r\
    \n    Monoid get(int ver, int i) {\r\n        assert(0 <= ver && ver < time);\r\
    \n        int l = 0, r = n;\r\n        node_ptr now = roots[ver];\r\n        while\
    \ (r - l > 1) {\r\n            int mid = (l + r) / 2;\r\n            if (i < mid)\
    \ {\r\n                if (now->left == nullptr) return e();\r\n             \
    \   now = now->left;\r\n                r = mid;\r\n            } else {\r\n \
    \               if (now->right == nullptr) return e();\r\n                now\
    \ = now->right;\r\n                l = mid;\r\n            }\r\n        }\r\n\
    \        return now->val;\r\n    }\r\n\r\n    Monoid prod(int ver, int l, int\
    \ r) {\r\n        assert(0 <= ver && ver < time);\r\n        return prod(l, r,\
    \ 0, n, roots[ver]);\r\n    }\r\n\r\n    Monoid all_prod(int ver) {\r\n      \
    \  assert(ver < time);\r\n        assert(roots[ver]->par == nullptr);\r\n    \
    \    return roots[ver]->val;\r\n    }\r\n\r\n    int latest() {\r\n        return\
    \ time - 1;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <vector>\r\n\r\n/*\r\n\
    \    reference: https://37zigen.com/persistent-segment-tree/\r\n*/\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\
    \nstruct PersistentSegmentTree {\r\n  private:\r\n    struct Node {\r\n      \
    \  Monoid val;\r\n        Node *left, *right, *par;\r\n        Node(Node *par\
    \ = nullptr)\r\n            : val(e()), left(nullptr), right(nullptr), par(par)\
    \ {}\r\n        void update() {\r\n            val = e();\r\n            if (left\
    \ != nullptr) val = left->val;\r\n            if (right != nullptr) val = op(val,\
    \ right->val);\r\n        }\r\n    };\r\n\r\n    using node_ptr = Node *;\r\n\r\
    \n    std::vector<node_ptr> roots;\r\n\r\n    int n;\r\n    int time;\r\n\r\n\
    \    Monoid prod(int l, int r, int nl, int nr, node_ptr now) {\r\n        if (now\
    \ == nullptr || nr <= l || r <= nl) return e();\r\n        if (l <= nl && nr <=\
    \ r) return now->val;\r\n        return op(prod(l, r, nl, (nl + nr) / 2, now->left),\r\
    \n                  prod(l, r, (nl + nr) / 2, nr, now->right));\r\n    }\r\n\r\
    \n  public:\r\n    PersistentSegmentTree(int _n) : n(1), time(1) {\r\n       \
    \ while (n < _n) {\r\n            n <<= 1;\r\n        }\r\n        roots.emplace_back(new\
    \ Node());\r\n    }\r\n\r\n    PersistentSegmentTree(std::vector<Monoid> v) :\
    \ n(1), time(1) {\r\n        int _n = v.size();\r\n        while (n < _n) {\r\n\
    \            n <<= 1;\r\n        }\r\n        auto dfs = [&](auto dfs, int l,\
    \ int r, node_ptr now) -> void {\r\n            assert(now != nullptr);\r\n  \
    \          if (_n <= l) return;\r\n            if (r - l == 1) {\r\n         \
    \       now->val = v[l];\r\n                return;\r\n            }\r\n     \
    \       int mid = (l + r) / 2;\r\n            if (now->left == nullptr) now->left\
    \ = new Node(now);\r\n            if (now->right == nullptr) now->right = new\
    \ Node(now);\r\n            dfs(dfs, l, mid, now->left);\r\n            dfs(dfs,\
    \ mid, r, now->right);\r\n            now->update();\r\n        };\r\n       \
    \ node_ptr root = new Node();\r\n        roots.emplace_back(root);\r\n       \
    \ dfs(dfs, 0, n, root);\r\n    }\r\n\r\n    void set(int ver, int i, Monoid x)\
    \ {\r\n        assert(0 <= ver && ver < time);\r\n        node_ptr now = new Node();\r\
    \n        node_ptr p = roots[ver];\r\n        roots.emplace_back(now);\r\n   \
    \     time++;\r\n        int l = 0, r = n;\r\n        while (r - l > 1) {\r\n\
    \            int mid = (r + l) / 2;\r\n            if (i < mid) {\r\n        \
    \        r = mid;\r\n                now->left = new Node(now);\r\n          \
    \      if (p != nullptr) {\r\n                    now->right = p->right;\r\n \
    \                   p = p->left;\r\n                }\r\n                now =\
    \ now->left;\r\n            } else {\r\n                l = mid;\r\n         \
    \       now->right = new Node(now);\r\n                if (p != nullptr) {\r\n\
    \                    now->left = p->left;\r\n                    p = p->right;\r\
    \n                }\r\n                now = now->right;\r\n            }\r\n\
    \        }\r\n        now->val = x;\r\n        while (now->par) {\r\n        \
    \    now = now->par;\r\n            now->update();\r\n        }\r\n    }\r\n\r\
    \n    Monoid get(int ver, int i) {\r\n        assert(0 <= ver && ver < time);\r\
    \n        int l = 0, r = n;\r\n        node_ptr now = roots[ver];\r\n        while\
    \ (r - l > 1) {\r\n            int mid = (l + r) / 2;\r\n            if (i < mid)\
    \ {\r\n                if (now->left == nullptr) return e();\r\n             \
    \   now = now->left;\r\n                r = mid;\r\n            } else {\r\n \
    \               if (now->right == nullptr) return e();\r\n                now\
    \ = now->right;\r\n                l = mid;\r\n            }\r\n        }\r\n\
    \        return now->val;\r\n    }\r\n\r\n    Monoid prod(int ver, int l, int\
    \ r) {\r\n        assert(0 <= ver && ver < time);\r\n        return prod(l, r,\
    \ 0, n, roots[ver]);\r\n    }\r\n\r\n    Monoid all_prod(int ver) {\r\n      \
    \  assert(ver < time);\r\n        assert(roots[ver]->par == nullptr);\r\n    \
    \    return roots[ver]->val;\r\n    }\r\n\r\n    int latest() {\r\n        return\
    \ time - 1;\r\n    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/PersistentSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Range_Sum_Persistent_Segtree.test.cpp
documentation_of: data_structure/PersistentSegmentTree.hpp
layout: document
redirect_from:
- /library/data_structure/PersistentSegmentTree.hpp
- /library/data_structure/PersistentSegmentTree.hpp.html
title: data_structure/PersistentSegmentTree.hpp
---
