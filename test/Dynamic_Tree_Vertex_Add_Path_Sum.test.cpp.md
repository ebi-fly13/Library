---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/link_cut_tree.hpp
    title: data_structure/link_cut_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp\"\n#define\
    \ PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\n#line 2 \"data_structure/link_cut_tree.hpp\"\
    \n\n#include <cassert>\n#include <memory>\n\nnamespace ebi {\n\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F), F (*id)()>\nstruct link_cut_tree {\n   private:\n    struct Node;\n    using\
    \ node_ptr = std::shared_ptr<Node>;\n\n    struct Node {\n        int index;\n\
    \        S val, sum, rev_sum;\n        F lazy;\n        node_ptr lch, rch, par;\n\
    \        bool rev;\n\n        Node(int _index, S _val)\n            : index(_index),\n\
    \              val(_val),\n              sum(_val),\n              rev_sum(_val),\n\
    \              lazy(id()),\n              lch(nullptr),\n              rch(nullptr),\n\
    \              par(nullptr),\n              rev(false) {}\n\n        Node(int\
    \ _index)\n            : index(_index),\n              val(e()),\n           \
    \   sum(e()),\n              rev_sum(e()),\n              lazy(id()),\n      \
    \        lch(nullptr),\n              rch(nullptr),\n              par(nullptr),\n\
    \              rev(false) {}\n\n        bool is_root() {\n            return !par\
    \ || (par->lch.get() != this && par->rch.get() != this);\n        }\n\n      \
    \  void set(S x) {\n            val = sum = rev_sum = x;\n            lazy = id();\n\
    \        }\n\n        void propagate(F f) {\n            lazy = composition(f,\
    \ lazy);\n            val = mapping(f, val);\n            sum = mapping(f, sum);\n\
    \            rev_sum = mapping(f, rev_sum);\n        }\n\n        void update()\
    \ {\n            sum = val;\n            rev_sum = val;\n            if (lch)\
    \ {\n                sum = op(lch->sum, sum);\n                rev_sum = op(rev_sum,\
    \ lch->rev_sum);\n            }\n            if (rch) {\n                sum =\
    \ op(sum, rch->sum);\n                rev_sum = op(rch->rev_sum, rev_sum);\n \
    \           }\n        }\n\n        void toggle() {\n            std::swap(lch,\
    \ rch);\n            std::swap(sum, rev_sum);\n            rev ^= true;\n    \
    \    }\n\n        void eval() {\n            if (lch) {\n                lch->lazy\
    \ = composition(lazy, lch->lazy);\n                lch->sum = mapping(lazy, lch->sum);\n\
    \                lch->rev_sum = mapping(lazy, lch->rev_sum);\n            }\n\
    \            if (rch) {\n                rch->lazy = composition(lazy, rch->lazy);\n\
    \                rch->sum = mapping(lazy, rch->sum);\n                rch->rev_sum\
    \ = mapping(lazy, rch->rev_sum);\n            }\n            val = mapping(lazy,\
    \ val);\n            lazy = id();\n            return;\n        }\n\n        void\
    \ pushdown() {\n            eval();\n            if (rev) {\n                rev\
    \ = false;\n                if (lch) lch->toggle();\n                if (rch)\
    \ rch->toggle();\n            }\n        }\n    };\n\n    void rot_L(node_ptr\
    \ node) {\n        assert(node->par);\n        auto par = node->par;\n       \
    \ auto g = par->par;\n        if ((par->rch = node->lch)) node->lch->par = par;\n\
    \        node->lch = par;\n        par->par = node;\n        par->update();\n\
    \        node->update();\n        if ((node->par = g)) {\n            if (g->lch\
    \ == par) g->lch = node;\n            if (g->rch == par) g->rch = node;\n    \
    \        g->update();\n        }\n        return;\n    }\n\n    void rot_R(node_ptr\
    \ node) {\n        assert(node->par);\n        auto par = node->par;\n       \
    \ auto g = par->par;\n        if ((par->lch = node->rch)) node->rch->par = par;\n\
    \        node->rch = par;\n        par->par = node;\n        par->update();\n\
    \        node->update();\n        if ((node->par = g)) {\n            if (g->lch\
    \ == par) g->lch = node;\n            if (g->rch == par) g->rch = node;\n    \
    \        g->update();\n        }\n        return;\n    }\n\n    void splay(node_ptr\
    \ node) {\n        if (!node) return;\n        node->pushdown();\n        while\
    \ (!node->is_root()) {\n            auto par = node->par;\n            if (par->is_root())\
    \ {\n                par->pushdown();\n                node->pushdown();\n   \
    \             if (par->lch == node) rot_R(node);\n                if (par->rch\
    \ == node) rot_L(node);\n            } else {\n                auto g = par->par;\n\
    \                g->pushdown();\n                par->pushdown();\n          \
    \      node->pushdown();\n                if (g->lch == par) {\n             \
    \       if (par->lch == node) {\n                        rot_R(par);\n       \
    \                 rot_R(node);\n                    } else {\n               \
    \         rot_L(node);\n                        rot_R(node);\n               \
    \     }\n                } else {\n                    assert(g->rch == par);\n\
    \                    if (par->rch == node) {\n                        rot_L(par);\n\
    \                        rot_L(node);\n                    } else {\n        \
    \                rot_R(node);\n                        rot_L(node);\n        \
    \            }\n                }\n            }\n        }\n        return;\n\
    \    }\n\n    void make_node(int index, S val) {\n        vertex[index] = std::make_shared<Node>(index,\
    \ val);\n        return;\n    }\n\n    void expose(node_ptr node) {\n        node_ptr\
    \ prev_rch = nullptr;\n        for (node_ptr cur = node; cur; cur = cur->par)\
    \ {\n            splay(cur);\n            cur->rch = prev_rch;\n            cur->update();\n\
    \            prev_rch = cur;\n        }\n        splay(node);\n        return;\n\
    \    }\n\n    void link(node_ptr child, node_ptr parent) {\n        expose(child);\n\
    \        expose(parent);\n        child->par = parent;\n        parent->rch =\
    \ child;\n        return;\n    }\n\n    void cut(node_ptr child) {\n        expose(child);\n\
    \        assert(child->lch);\n        auto parent = child->lch;\n        child->lch\
    \ = nullptr;\n        parent->par = nullptr;\n        return;\n    }\n\n    void\
    \ evert(node_ptr node) {\n        expose(node);\n        node->toggle();\n   \
    \     node->pushdown();\n        return;\n    }\n\n   public:\n    link_cut_tree(int\
    \ n) : vertex(n) {}\n\n    link_cut_tree(const std::vector<S> &a) {\n        int\
    \ n = a.size();\n        vertex.resize(n);\n        for (int i = 0; i < n; i++)\
    \ make_node(i, a[i]);\n    }\n\n    void add_edge(int i, int j) {\n        evert(vertex[i]);\n\
    \        link(vertex[i], vertex[j]);\n        return;\n    }\n\n    void erase_edge(int\
    \ i, int j) {\n        evert(vertex[i]);\n        cut(vertex[j]);\n    }\n\n \
    \   // s-t\u30D1\u30B9\u306Bf\u3092\u4F5C\u7528\u3055\u305B\u308B\n    void apply(int\
    \ s, int t, F f) {\n        evert(vertex[s]);\n        expose(vertex[t]);\n  \
    \      vertex[s]->propagate(f);\n        vertex[s]->pushdown();\n    }\n\n   \
    \ void set(int v, S x) {\n        evert(vertex[v]);\n        expose(vertex[v]);\n\
    \        vertex[v]->set(x);\n    }\n\n    S prod(int s, int t) {\n        evert(vertex[s]);\n\
    \        expose(vertex[t]);\n        return vertex[t]->sum;\n    }\n\n    S get(int\
    \ v) {\n        expose(vertex[v]);\n        return vertex[v]->val;\n    }\n\n\
    \    std::vector<int> get_path(int s, int t) {\n        evert(vertex[s]);\n  \
    \      expose(vertex[t]);\n        std::vector<int> vs;\n        auto dfs = [&](auto\
    \ &&self, node_ptr v) -> void {\n            if (!v) return;\n            self(self,\
    \ v->rch);\n            vs.emplace_back(v->index);\n            self(self, v->lch);\n\
    \            return;\n        };\n        dfs(dfs, vertex[t]);\n        return\
    \ vs;\n    }\n\n    /*\n    void DEBUG() {\n        for (auto node : vertex) {\n\
    \            debug(node->index, node->val.value, node->sum.value);\n         \
    \   if (node->par) {\n                debug(node->par->index);\n            }\n\
    \            if (node->lch) {\n                debug(node->lch->index);\n    \
    \        }\n            if (node->rch) {\n                debug(node->rch->index);\n\
    \            }\n        }\n    }\n    */\n\n   private:\n    std::vector<node_ptr>\
    \ vertex;\n};\n\n}  // namespace ebi\n#line 9 \"test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp\"\
    \n\nusing i64 = std::int64_t;\n\nstruct S {\n    i64 value;\n    int size;\n};\n\
    \nusing F = i64;\n\nS op(S a, S b) { return {a.value + b.value, a.size + b.size};\
    \ }\nS e() { return {0, 0}; }\nS mapping(F f, S x) { return {x.value + f * x.size,\
    \ x.size}; }\nF composition(F f, F g) { return f + g; }\nF id() { return 0; }\n\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<S> a(n);\n\
    \    for (auto &s : a) {\n        std::cin >> s.value;\n        s.size = 1;\n\
    \    }\n    ebi::link_cut_tree<S, op, e, F, mapping, composition, id> lct(a);\n\
    \    for (int i = 0; i < n - 1; i++) {\n        int u, v;\n        std::cin >>\
    \ u >> v;\n        lct.add_edge(u, v);\n    }\n    while (q--) {\n        int\
    \ t;\n        std::cin >> t;\n        if (t == 0) {\n            int u, v, w,\
    \ x;\n            std::cin >> u >> v >> w >> x;\n            lct.erase_edge(u,\
    \ v);\n            lct.add_edge(w, x);\n        } else if (t == 1) {\n       \
    \     int p;\n            F x;\n            std::cin >> p >> x;\n            lct.set(p,\
    \ {lct.get(p).value + x, 1});\n        } else {\n            int u, v;\n     \
    \       std::cin >> u >> v;\n            std::cout << lct.prod(u, v).value <<\
    \ '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\n#include \"\
    data_structure/link_cut_tree.hpp\"\n\nusing i64 = std::int64_t;\n\nstruct S {\n\
    \    i64 value;\n    int size;\n};\n\nusing F = i64;\n\nS op(S a, S b) { return\
    \ {a.value + b.value, a.size + b.size}; }\nS e() { return {0, 0}; }\nS mapping(F\
    \ f, S x) { return {x.value + f * x.size, x.size}; }\nF composition(F f, F g)\
    \ { return f + g; }\nF id() { return 0; }\n\nint main() {\n    int n, q;\n   \
    \ std::cin >> n >> q;\n    std::vector<S> a(n);\n    for (auto &s : a) {\n   \
    \     std::cin >> s.value;\n        s.size = 1;\n    }\n    ebi::link_cut_tree<S,\
    \ op, e, F, mapping, composition, id> lct(a);\n    for (int i = 0; i < n - 1;\
    \ i++) {\n        int u, v;\n        std::cin >> u >> v;\n        lct.add_edge(u,\
    \ v);\n    }\n    while (q--) {\n        int t;\n        std::cin >> t;\n    \
    \    if (t == 0) {\n            int u, v, w, x;\n            std::cin >> u >>\
    \ v >> w >> x;\n            lct.erase_edge(u, v);\n            lct.add_edge(w,\
    \ x);\n        } else if (t == 1) {\n            int p;\n            F x;\n  \
    \          std::cin >> p >> x;\n            lct.set(p, {lct.get(p).value + x,\
    \ 1});\n        } else {\n            int u, v;\n            std::cin >> u >>\
    \ v;\n            std::cout << lct.prod(u, v).value << '\\n';\n        }\n   \
    \ }\n}"
  dependsOn:
  - data_structure/link_cut_tree.hpp
  isVerificationFile: true
  path: test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 14:32:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
- /verify/test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp.html
title: test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
---
