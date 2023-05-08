---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
    title: test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/link_cut_tree.hpp\"\n\n#include <cassert>\n\
    #include <memory>\n\nnamespace ebi {\n\ntemplate <class S, S (*op)(S, S), S (*e)(),\
    \ class F, S (*mapping)(F, S),\n          F (*composition)(F, F), F (*id)()>\n\
    struct link_cut_tree {\n  private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        int index;\n        S val, sum, rev_sum;\n      \
    \  F lazy;\n        node_ptr lch, rch, par;\n        bool rev;\n\n        Node(int\
    \ _index, S _val)\n            : index(_index),\n              val(_val),\n  \
    \            sum(_val),\n              rev_sum(_val),\n              lazy(id()),\n\
    \              lch(nullptr),\n              rch(nullptr),\n              par(nullptr),\n\
    \              rev(false) {}\n\n        Node(int _index)\n            : index(_index),\n\
    \              val(e()),\n              sum(e()),\n              rev_sum(e()),\n\
    \              lazy(id()),\n              lch(nullptr),\n              rch(nullptr),\n\
    \              par(nullptr),\n              rev(false) {}\n\n        bool is_root()\
    \ {\n            return !par || (par->lch.get() != this && par->rch.get() != this);\n\
    \        }\n\n        void set(S x) {\n            val = sum = rev_sum = x;\n\
    \            lazy = id();\n        }\n\n        void propagate(F f) {\n      \
    \      lazy = composition(f, lazy);\n            val = mapping(f, val);\n    \
    \        sum = mapping(f, sum);\n            rev_sum = mapping(f, rev_sum);\n\
    \        }\n\n        void update() {\n            sum = val;\n            rev_sum\
    \ = val;\n            if (lch) {\n                sum = op(lch->sum, sum);\n \
    \               rev_sum = op(rev_sum, lch->rev_sum);\n            }\n        \
    \    if (rch) {\n                sum = op(sum, rch->sum);\n                rev_sum\
    \ = op(rch->rev_sum, rev_sum);\n            }\n        }\n\n        void toggle()\
    \ {\n            std::swap(lch, rch);\n            std::swap(sum, rev_sum);\n\
    \            rev ^= true;\n        }\n\n        void eval() {\n            if\
    \ (lch) {\n                lch->lazy = composition(lazy, lch->lazy);\n       \
    \         lch->sum = mapping(lazy, lch->sum);\n                lch->rev_sum =\
    \ mapping(lazy, lch->rev_sum);\n            }\n            if (rch) {\n      \
    \          rch->lazy = composition(lazy, rch->lazy);\n                rch->sum\
    \ = mapping(lazy, rch->sum);\n                rch->rev_sum = mapping(lazy, rch->rev_sum);\n\
    \            }\n            val = mapping(lazy, val);\n            lazy = id();\n\
    \            return;\n        }\n\n        void pushdown() {\n            eval();\n\
    \            if (rev) {\n                rev = false;\n                if (lch)\
    \ lch->toggle();\n                if (rch) rch->toggle();\n            }\n   \
    \     }\n    };\n\n    void rot_L(node_ptr node) {\n        assert(node->par);\n\
    \        auto par = node->par;\n        auto g = par->par;\n        if ((par->rch\
    \ = node->lch)) node->lch->par = par;\n        node->lch = par;\n        par->par\
    \ = node;\n        par->update();\n        node->update();\n        if ((node->par\
    \ = g)) {\n            if (g->lch == par) g->lch = node;\n            if (g->rch\
    \ == par) g->rch = node;\n            g->update();\n        }\n        return;\n\
    \    }\n\n    void rot_R(node_ptr node) {\n        assert(node->par);\n      \
    \  auto par = node->par;\n        auto g = par->par;\n        if ((par->lch =\
    \ node->rch)) node->rch->par = par;\n        node->rch = par;\n        par->par\
    \ = node;\n        par->update();\n        node->update();\n        if ((node->par\
    \ = g)) {\n            if (g->lch == par) g->lch = node;\n            if (g->rch\
    \ == par) g->rch = node;\n            g->update();\n        }\n        return;\n\
    \    }\n\n    void splay(node_ptr node) {\n        if (!node) return;\n      \
    \  node->pushdown();\n        while (!node->is_root()) {\n            auto par\
    \ = node->par;\n            if (par->is_root()) {\n                par->pushdown();\n\
    \                node->pushdown();\n                if (par->lch == node) rot_R(node);\n\
    \                if (par->rch == node) rot_L(node);\n            } else {\n  \
    \              auto g = par->par;\n                g->pushdown();\n          \
    \      par->pushdown();\n                node->pushdown();\n                if\
    \ (g->lch == par) {\n                    if (par->lch == node) {\n           \
    \             rot_R(par);\n                        rot_R(node);\n            \
    \        } else {\n                        rot_L(node);\n                    \
    \    rot_R(node);\n                    }\n                } else {\n         \
    \           assert(g->rch == par);\n                    if (par->rch == node)\
    \ {\n                        rot_L(par);\n                        rot_L(node);\n\
    \                    } else {\n                        rot_R(node);\n        \
    \                rot_L(node);\n                    }\n                }\n    \
    \        }\n        }\n        return;\n    }\n\n    void make_node(int index,\
    \ S val) {\n        vertex[index] = std::make_shared<Node>(index, val);\n    \
    \    return;\n    }\n\n    void expose(node_ptr node) {\n        node_ptr prev_rch\
    \ = nullptr;\n        for (node_ptr cur = node; cur; cur = cur->par) {\n     \
    \       splay(cur);\n            cur->rch = prev_rch;\n            cur->update();\n\
    \            prev_rch = cur;\n        }\n        splay(node);\n        return;\n\
    \    }\n\n    void link(node_ptr child, node_ptr parent) {\n        expose(child);\n\
    \        expose(parent);\n        child->par = parent;\n        parent->rch =\
    \ child;\n        return;\n    }\n\n    void cut(node_ptr child) {\n        expose(child);\n\
    \        assert(child->lch);\n        auto parent = child->lch;\n        child->lch\
    \ = nullptr;\n        parent->par = nullptr;\n        return;\n    }\n\n    void\
    \ evert(node_ptr node) {\n        expose(node);\n        node->toggle();\n   \
    \     node->pushdown();\n        return;\n    }\n\n  public:\n    link_cut_tree(int\
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
    \            }\n        }\n    }\n    */\n\n  private:\n    std::vector<node_ptr>\
    \ vertex;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <memory>\n\nnamespace ebi {\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n \
    \         F (*composition)(F, F), F (*id)()>\nstruct link_cut_tree {\n  private:\n\
    \    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node\
    \ {\n        int index;\n        S val, sum, rev_sum;\n        F lazy;\n     \
    \   node_ptr lch, rch, par;\n        bool rev;\n\n        Node(int _index, S _val)\n\
    \            : index(_index),\n              val(_val),\n              sum(_val),\n\
    \              rev_sum(_val),\n              lazy(id()),\n              lch(nullptr),\n\
    \              rch(nullptr),\n              par(nullptr),\n              rev(false)\
    \ {}\n\n        Node(int _index)\n            : index(_index),\n             \
    \ val(e()),\n              sum(e()),\n              rev_sum(e()),\n          \
    \    lazy(id()),\n              lch(nullptr),\n              rch(nullptr),\n \
    \             par(nullptr),\n              rev(false) {}\n\n        bool is_root()\
    \ {\n            return !par || (par->lch.get() != this && par->rch.get() != this);\n\
    \        }\n\n        void set(S x) {\n            val = sum = rev_sum = x;\n\
    \            lazy = id();\n        }\n\n        void propagate(F f) {\n      \
    \      lazy = composition(f, lazy);\n            val = mapping(f, val);\n    \
    \        sum = mapping(f, sum);\n            rev_sum = mapping(f, rev_sum);\n\
    \        }\n\n        void update() {\n            sum = val;\n            rev_sum\
    \ = val;\n            if (lch) {\n                sum = op(lch->sum, sum);\n \
    \               rev_sum = op(rev_sum, lch->rev_sum);\n            }\n        \
    \    if (rch) {\n                sum = op(sum, rch->sum);\n                rev_sum\
    \ = op(rch->rev_sum, rev_sum);\n            }\n        }\n\n        void toggle()\
    \ {\n            std::swap(lch, rch);\n            std::swap(sum, rev_sum);\n\
    \            rev ^= true;\n        }\n\n        void eval() {\n            if\
    \ (lch) {\n                lch->lazy = composition(lazy, lch->lazy);\n       \
    \         lch->sum = mapping(lazy, lch->sum);\n                lch->rev_sum =\
    \ mapping(lazy, lch->rev_sum);\n            }\n            if (rch) {\n      \
    \          rch->lazy = composition(lazy, rch->lazy);\n                rch->sum\
    \ = mapping(lazy, rch->sum);\n                rch->rev_sum = mapping(lazy, rch->rev_sum);\n\
    \            }\n            val = mapping(lazy, val);\n            lazy = id();\n\
    \            return;\n        }\n\n        void pushdown() {\n            eval();\n\
    \            if (rev) {\n                rev = false;\n                if (lch)\
    \ lch->toggle();\n                if (rch) rch->toggle();\n            }\n   \
    \     }\n    };\n\n    void rot_L(node_ptr node) {\n        assert(node->par);\n\
    \        auto par = node->par;\n        auto g = par->par;\n        if ((par->rch\
    \ = node->lch)) node->lch->par = par;\n        node->lch = par;\n        par->par\
    \ = node;\n        par->update();\n        node->update();\n        if ((node->par\
    \ = g)) {\n            if (g->lch == par) g->lch = node;\n            if (g->rch\
    \ == par) g->rch = node;\n            g->update();\n        }\n        return;\n\
    \    }\n\n    void rot_R(node_ptr node) {\n        assert(node->par);\n      \
    \  auto par = node->par;\n        auto g = par->par;\n        if ((par->lch =\
    \ node->rch)) node->rch->par = par;\n        node->rch = par;\n        par->par\
    \ = node;\n        par->update();\n        node->update();\n        if ((node->par\
    \ = g)) {\n            if (g->lch == par) g->lch = node;\n            if (g->rch\
    \ == par) g->rch = node;\n            g->update();\n        }\n        return;\n\
    \    }\n\n    void splay(node_ptr node) {\n        if (!node) return;\n      \
    \  node->pushdown();\n        while (!node->is_root()) {\n            auto par\
    \ = node->par;\n            if (par->is_root()) {\n                par->pushdown();\n\
    \                node->pushdown();\n                if (par->lch == node) rot_R(node);\n\
    \                if (par->rch == node) rot_L(node);\n            } else {\n  \
    \              auto g = par->par;\n                g->pushdown();\n          \
    \      par->pushdown();\n                node->pushdown();\n                if\
    \ (g->lch == par) {\n                    if (par->lch == node) {\n           \
    \             rot_R(par);\n                        rot_R(node);\n            \
    \        } else {\n                        rot_L(node);\n                    \
    \    rot_R(node);\n                    }\n                } else {\n         \
    \           assert(g->rch == par);\n                    if (par->rch == node)\
    \ {\n                        rot_L(par);\n                        rot_L(node);\n\
    \                    } else {\n                        rot_R(node);\n        \
    \                rot_L(node);\n                    }\n                }\n    \
    \        }\n        }\n        return;\n    }\n\n    void make_node(int index,\
    \ S val) {\n        vertex[index] = std::make_shared<Node>(index, val);\n    \
    \    return;\n    }\n\n    void expose(node_ptr node) {\n        node_ptr prev_rch\
    \ = nullptr;\n        for (node_ptr cur = node; cur; cur = cur->par) {\n     \
    \       splay(cur);\n            cur->rch = prev_rch;\n            cur->update();\n\
    \            prev_rch = cur;\n        }\n        splay(node);\n        return;\n\
    \    }\n\n    void link(node_ptr child, node_ptr parent) {\n        expose(child);\n\
    \        expose(parent);\n        child->par = parent;\n        parent->rch =\
    \ child;\n        return;\n    }\n\n    void cut(node_ptr child) {\n        expose(child);\n\
    \        assert(child->lch);\n        auto parent = child->lch;\n        child->lch\
    \ = nullptr;\n        parent->par = nullptr;\n        return;\n    }\n\n    void\
    \ evert(node_ptr node) {\n        expose(node);\n        node->toggle();\n   \
    \     node->pushdown();\n        return;\n    }\n\n  public:\n    link_cut_tree(int\
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
    \            }\n        }\n    }\n    */\n\n  private:\n    std::vector<node_ptr>\
    \ vertex;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/link_cut_tree.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Dynamic_Tree_Vertex_Add_Path_Sum.test.cpp
documentation_of: data_structure/link_cut_tree.hpp
layout: document
redirect_from:
- /library/data_structure/link_cut_tree.hpp
- /library/data_structure/link_cut_tree.hpp.html
title: data_structure/link_cut_tree.hpp
---
