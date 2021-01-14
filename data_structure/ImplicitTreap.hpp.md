---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ImplicitTreap.test.cpp
    title: test/ImplicitTreap.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.slideshare.net/iwiwi/2-12188757
    - https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
  bundledCode: "#line 2 \"data_structure/ImplicitTreap.hpp\"\n\r\n/*\r\n    reference:\
    \ https://www.slideshare.net/iwiwi/2-12188757\r\n               \u5B9F\u88C5\u65B9\
    \u6CD5\u3084Treap\u306E\u30A2\u30A4\u30C7\u30A2\u306A\u3069.\r\n             \
    \  https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\r\n            \
    \   Treap\u3092\u30EA\u30B9\u30C8\u306E\u3088\u3046\u306B\u6271\u3046\u65B9\u6CD5\
    \u3084\u5B9F\u88C5\u6CD5, Monoid\u306E\u8F09\u305B\u65B9\u306A\u3069.\r\n*/\r\n\
    \r\n#include <random>\r\n\r\ntemplate<\r\n    class S,\r\n    S (*op)(S, S),\r\
    \n    S (*e)(),\r\n    class F,\r\n    S (*mapping)(F, S),\r\n    F (*composition)(F,\
    \ F),\r\n    F (*id)()>\r\nstruct ImplicitTreap {\r\nprivate:\r\n    struct Node\
    \ {\r\n        S val, acc;\r\n        F lazy;\r\n        int pri, cnt;\r\n   \
    \     bool rev;\r\n        Node *lch, *rch;\r\n        Node(S val, int pri) :\
    \ val(val), acc(e()), lazy(id()), pri(pri), cnt(0),rev(false), lch(nullptr), rch(nullptr)\
    \ { }\r\n    };\r\n\r\n    using node_ptr = Node*;\r\n\r\n    node_ptr root;\r\
    \n\r\n    std::random_device rnd;\r\n    std::mt19937 mt;\r\n    std::uniform_int_distribution<>\
    \ pri_rnd;\r\n\r\n    int cnt(node_ptr t) {\r\n        return t ? t->cnt : 0;\r\
    \n    }\r\n\r\n    void update_cnt(node_ptr t) {\r\n        if(t) {\r\n      \
    \      t->cnt = 1 + cnt(t->lch) + cnt(t->rch);\r\n        }\r\n    }\r\n\r\n \
    \   S acc(node_ptr t) {\r\n        return t ? t->acc : e();\r\n    }\r\n\r\n \
    \   void update_acc(node_ptr t) {\r\n        if(t) {\r\n            t->acc = op(acc(t->lch),\
    \ t->val);\r\n            t->acc = op(t->acc, acc(t->rch));\r\n        }\r\n \
    \   }\r\n\r\n    void eval(node_ptr t) {\r\n        if(t) {\r\n            if(t->lch)\
    \ {\r\n                t->lch->lazy = composition(t->lazy, t->lch->lazy);\r\n\
    \                t->lch->acc = mapping(t->lazy, t->lch->acc);\r\n            }\r\
    \n            if(t->rch) {\r\n                t->rch->lazy = composition(t->lazy,\
    \ t->rch->lazy);\r\n                t->rch->acc = mapping(t->lazy, t->rch->acc);\r\
    \n            }\r\n            t->val = mapping(t->lazy, t->val);\r\n        \
    \    t->lazy = id();\r\n        }\r\n    }\r\n\r\n    void pushdown(node_ptr t)\
    \ {\r\n        if(t && t->rev) {\r\n            t->rev = false;\r\n          \
    \  std::swap(t->lch, t->rch);\r\n            if(t->lch) t->lch->rev ^= 1;\r\n\
    \            if(t->rch) t->rch->rev ^= 1;\r\n        }\r\n        eval(t);\r\n\
    \        update(t);\r\n    }\r\n\r\n    void update(node_ptr t) {\r\n        update_cnt(t);\r\
    \n        update_acc(t);\r\n    }\r\n\r\n    node_ptr merge(node_ptr l, node_ptr\
    \ r) {\r\n        pushdown(l);\r\n        pushdown(r);\r\n        if(!l || !r)\
    \ {\r\n            return !l ? r : l;\r\n        }\r\n        if(l->pri > r->pri)\
    \ {\r\n            l->rch = merge(l->rch, r);\r\n            update(l);\r\n  \
    \          return l;\r\n        }\r\n        else {\r\n            r->lch = merge(l,\
    \ r->lch);\r\n            update(r);\r\n            return r;\r\n        }\r\n\
    \    }\r\n\r\n    std::pair<node_ptr, node_ptr> split(node_ptr t, int key) {\r\
    \n        if(!t) return std::pair<node_ptr, node_ptr>(nullptr, nullptr);\r\n \
    \       pushdown(t);\r\n        if(key < cnt(t->lch) + 1) {\r\n            auto\
    \ [l, r] = split(t->lch, key);\r\n            t->lch = r;\r\n            update(t);\r\
    \n            return std::pair<node_ptr, node_ptr>(l, t);\r\n        }\r\n   \
    \     else {\r\n            auto [l, r] = split(t->rch, key-cnt(t->lch)-1);\r\n\
    \            t->rch = l;\r\n            update(t);\r\n            return  std::pair<node_ptr,\
    \ node_ptr>(t, r);\r\n        }\r\n    }\r\n    \r\npublic:\r\n    ImplicitTreap()\
    \ : root(nullptr) {\r\n        mt = std::mt19937(rnd());\r\n        pri_rnd =\
    \ std::uniform_int_distribution<>(0, 1e9);\r\n    }\r\n\r\n    void insert(int\
    \ k, S x) {\r\n        auto [l, r] = split(root, k);\r\n        auto t = merge(l,\
    \ new Node(x, pri_rnd(mt)));\r\n        root = merge(t, r);\r\n    }\r\n\r\n \
    \   void erase(int k) {\r\n        auto [l, r] = split(root, k+1);\r\n       \
    \ auto [nl, nr] = split(l, k);\r\n        root = merge(nl, r);\r\n    }\r\n\r\n\
    \    void reverse(int l, int r) {\r\n        auto [t1, t2] = split(root, l);\r\
    \n        auto [t3, t4] = split(t2, r-l);\r\n        t3->rev ^= 1;\r\n       \
    \ t1 = merge(t1, t3);\r\n        root = merge(t1, t4);\r\n    }\r\n\r\n    void\
    \ apply(int l, int r, F x) {\r\n        auto [t1, t2] = split(root, l);\r\n  \
    \      auto [t3, t4] = split(t2, r-l);\r\n        t3->lazy = composition(x, t3->lazy);\r\
    \n        t3->acc = mapping(x, t3->acc);\r\n        t1 = merge(t1, t3);\r\n  \
    \      root = merge(t1,t4);\r\n    }\r\n\r\n    S prod(int l, int r) {\r\n   \
    \     auto [t1, t2] = split(root, l);\r\n        auto [t3, t4] = split(t2, r-l);\r\
    \n        S ret = t3->acc;\r\n        t1 = merge(t1, t3);\r\n        root = merge(t1,\
    \ t4);\r\n        return ret;\r\n    }\r\n};\n"
  code: "#pragma once\r\n\r\n/*\r\n    reference: https://www.slideshare.net/iwiwi/2-12188757\r\
    \n               \u5B9F\u88C5\u65B9\u6CD5\u3084Treap\u306E\u30A2\u30A4\u30C7\u30A2\
    \u306A\u3069.\r\n               https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\r\
    \n               Treap\u3092\u30EA\u30B9\u30C8\u306E\u3088\u3046\u306B\u6271\u3046\
    \u65B9\u6CD5\u3084\u5B9F\u88C5\u6CD5, Monoid\u306E\u8F09\u305B\u65B9\u306A\u3069\
    .\r\n*/\r\n\r\n#include <random>\r\n\r\ntemplate<\r\n    class S,\r\n    S (*op)(S,\
    \ S),\r\n    S (*e)(),\r\n    class F,\r\n    S (*mapping)(F, S),\r\n    F (*composition)(F,\
    \ F),\r\n    F (*id)()>\r\nstruct ImplicitTreap {\r\nprivate:\r\n    struct Node\
    \ {\r\n        S val, acc;\r\n        F lazy;\r\n        int pri, cnt;\r\n   \
    \     bool rev;\r\n        Node *lch, *rch;\r\n        Node(S val, int pri) :\
    \ val(val), acc(e()), lazy(id()), pri(pri), cnt(0),rev(false), lch(nullptr), rch(nullptr)\
    \ { }\r\n    };\r\n\r\n    using node_ptr = Node*;\r\n\r\n    node_ptr root;\r\
    \n\r\n    std::random_device rnd;\r\n    std::mt19937 mt;\r\n    std::uniform_int_distribution<>\
    \ pri_rnd;\r\n\r\n    int cnt(node_ptr t) {\r\n        return t ? t->cnt : 0;\r\
    \n    }\r\n\r\n    void update_cnt(node_ptr t) {\r\n        if(t) {\r\n      \
    \      t->cnt = 1 + cnt(t->lch) + cnt(t->rch);\r\n        }\r\n    }\r\n\r\n \
    \   S acc(node_ptr t) {\r\n        return t ? t->acc : e();\r\n    }\r\n\r\n \
    \   void update_acc(node_ptr t) {\r\n        if(t) {\r\n            t->acc = op(acc(t->lch),\
    \ t->val);\r\n            t->acc = op(t->acc, acc(t->rch));\r\n        }\r\n \
    \   }\r\n\r\n    void eval(node_ptr t) {\r\n        if(t) {\r\n            if(t->lch)\
    \ {\r\n                t->lch->lazy = composition(t->lazy, t->lch->lazy);\r\n\
    \                t->lch->acc = mapping(t->lazy, t->lch->acc);\r\n            }\r\
    \n            if(t->rch) {\r\n                t->rch->lazy = composition(t->lazy,\
    \ t->rch->lazy);\r\n                t->rch->acc = mapping(t->lazy, t->rch->acc);\r\
    \n            }\r\n            t->val = mapping(t->lazy, t->val);\r\n        \
    \    t->lazy = id();\r\n        }\r\n    }\r\n\r\n    void pushdown(node_ptr t)\
    \ {\r\n        if(t && t->rev) {\r\n            t->rev = false;\r\n          \
    \  std::swap(t->lch, t->rch);\r\n            if(t->lch) t->lch->rev ^= 1;\r\n\
    \            if(t->rch) t->rch->rev ^= 1;\r\n        }\r\n        eval(t);\r\n\
    \        update(t);\r\n    }\r\n\r\n    void update(node_ptr t) {\r\n        update_cnt(t);\r\
    \n        update_acc(t);\r\n    }\r\n\r\n    node_ptr merge(node_ptr l, node_ptr\
    \ r) {\r\n        pushdown(l);\r\n        pushdown(r);\r\n        if(!l || !r)\
    \ {\r\n            return !l ? r : l;\r\n        }\r\n        if(l->pri > r->pri)\
    \ {\r\n            l->rch = merge(l->rch, r);\r\n            update(l);\r\n  \
    \          return l;\r\n        }\r\n        else {\r\n            r->lch = merge(l,\
    \ r->lch);\r\n            update(r);\r\n            return r;\r\n        }\r\n\
    \    }\r\n\r\n    std::pair<node_ptr, node_ptr> split(node_ptr t, int key) {\r\
    \n        if(!t) return std::pair<node_ptr, node_ptr>(nullptr, nullptr);\r\n \
    \       pushdown(t);\r\n        if(key < cnt(t->lch) + 1) {\r\n            auto\
    \ [l, r] = split(t->lch, key);\r\n            t->lch = r;\r\n            update(t);\r\
    \n            return std::pair<node_ptr, node_ptr>(l, t);\r\n        }\r\n   \
    \     else {\r\n            auto [l, r] = split(t->rch, key-cnt(t->lch)-1);\r\n\
    \            t->rch = l;\r\n            update(t);\r\n            return  std::pair<node_ptr,\
    \ node_ptr>(t, r);\r\n        }\r\n    }\r\n    \r\npublic:\r\n    ImplicitTreap()\
    \ : root(nullptr) {\r\n        mt = std::mt19937(rnd());\r\n        pri_rnd =\
    \ std::uniform_int_distribution<>(0, 1e9);\r\n    }\r\n\r\n    void insert(int\
    \ k, S x) {\r\n        auto [l, r] = split(root, k);\r\n        auto t = merge(l,\
    \ new Node(x, pri_rnd(mt)));\r\n        root = merge(t, r);\r\n    }\r\n\r\n \
    \   void erase(int k) {\r\n        auto [l, r] = split(root, k+1);\r\n       \
    \ auto [nl, nr] = split(l, k);\r\n        root = merge(nl, r);\r\n    }\r\n\r\n\
    \    void reverse(int l, int r) {\r\n        auto [t1, t2] = split(root, l);\r\
    \n        auto [t3, t4] = split(t2, r-l);\r\n        t3->rev ^= 1;\r\n       \
    \ t1 = merge(t1, t3);\r\n        root = merge(t1, t4);\r\n    }\r\n\r\n    void\
    \ apply(int l, int r, F x) {\r\n        auto [t1, t2] = split(root, l);\r\n  \
    \      auto [t3, t4] = split(t2, r-l);\r\n        t3->lazy = composition(x, t3->lazy);\r\
    \n        t3->acc = mapping(x, t3->acc);\r\n        t1 = merge(t1, t3);\r\n  \
    \      root = merge(t1,t4);\r\n    }\r\n\r\n    S prod(int l, int r) {\r\n   \
    \     auto [t1, t2] = split(root, l);\r\n        auto [t3, t4] = split(t2, r-l);\r\
    \n        S ret = t3->acc;\r\n        t1 = merge(t1, t3);\r\n        root = merge(t1,\
    \ t4);\r\n        return ret;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/ImplicitTreap.hpp
  requiredBy: []
  timestamp: '2021-01-15 00:47:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ImplicitTreap.test.cpp
documentation_of: data_structure/ImplicitTreap.hpp
layout: document
redirect_from:
- /library/data_structure/ImplicitTreap.hpp
- /library/data_structure/ImplicitTreap.hpp.html
title: data_structure/ImplicitTreap.hpp
---
