---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/splay_tree.hpp\"\n\n#include <limits>\n#include\
    \ <memory>\n#include <optional>\n\nnamespace ebi {\n\ntemplate <class T>\nstruct\
    \ splay_tree {\n   private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \    struct Node {\n        int sz;\n        T val;\n        node_ptr lch, rch,\
    \ par;\n\n        Node(T _val)\n            : sz(1), val(_val), lch(nullptr),\
    \ rch(nullptr), par(nullptr) {}\n\n        bool is_root() { return !par; }\n\n\
    \        void update() {\n            sz = 1;\n            if (lch) {\n      \
    \          sz += lch->sz;\n            }\n            if (rch) {\n           \
    \     sz += rch->sz;\n            }\n        }\n    };\n\n    void rot_L(node_ptr\
    \ node) {\n        assert(node->par);\n        auto par = node->par;\n       \
    \ auto g = par->par;\n        if ((par->rch = node->lch)) node->lch->par = par;\n\
    \        node->lch = par;\n        par->par = node;\n        node->update();\n\
    \        par->update();\n        if ((node->par = g)) {\n            if (g->lch\
    \ == par) g->lch = node;\n            if (g->rch == par) g->rch = node;\n    \
    \        g->update();\n        }\n        return;\n    }\n\n    void rot_R(node_ptr\
    \ node) {\n        assert(node->par);\n        auto par = node->par;\n       \
    \ auto g = par->par;\n        if ((par->lch = node->rch)) node->rch->par = par;\n\
    \        node->rch = par;\n        par->par = node;\n        node->update();\n\
    \        par->update();\n        if ((node->par = g)) {\n            if (g->lch\
    \ == par) g->lch = node;\n            if (g->rch == par) g->rch = node;\n    \
    \        g->update();\n        }\n        return;\n    }\n\n    void splay(node_ptr\
    \ node) {\n        if (!node) return;\n        while (!node->is_root()) {\n  \
    \          auto par = node->par;\n            if (par->is_root()) {\n        \
    \        if (par->lch == node) rot_R(node);\n                if (par->rch == node)\
    \ rot_L(node);\n            } else {\n                auto g = par->par;\n   \
    \             if (g->lch == par) {\n                    if (par->lch == node)\
    \ {\n                        rot_R(par);\n                        rot_R(node);\n\
    \                    } else {\n                        rot_L(node);\n        \
    \                rot_R(node);\n                    }\n                } else {\n\
    \                    assert(g->rch == par);\n                    if (par->rch\
    \ == node) {\n                        rot_L(par);\n                        rot_L(node);\n\
    \                    } else {\n                        rot_R(node);\n        \
    \                rot_L(node);\n                    }\n                }\n    \
    \        }\n        }\n        return;\n    }\n\n    void search(T x) {\n    \
    \    if (!root) return;\n        node_ptr now = root;\n        while (now) {\n\
    \            if (now->val == x) {\n                break;\n            } else\
    \ if (now->val < x) {\n                if (!now->rch) break;\n               \
    \ now = now->rch;\n            } else {\n                if (!now->lch) break;\n\
    \                now = now->lch;\n            }\n        }\n        assert(now);\n\
    \        splay(now);\n        root = now;\n        assert(root->is_root());\n\
    \        return;\n    }\n\n   public:\n    splay_tree() = default;\n\n    bool\
    \ find(T x) {\n        search(x);\n        if (!root || root->val != x) return\
    \ false;\n        return true;\n    }\n\n    void insert(T x) {\n        if (!find(x))\
    \ {\n            auto node = std::make_shared<Node>(x);\n            if (!root)\n\
    \                root = node;\n            else if (root->val < x) {\n       \
    \         node->lch = root;\n                root->par = node;\n             \
    \   node->rch = root->rch;\n                root->rch = nullptr;\n           \
    \     if (node->rch) node->rch->par = node;\n                root = node;\n  \
    \          } else {\n                node->rch = root;\n                root->par\
    \ = node;\n                node->lch = root->lch;\n                root->lch =\
    \ nullptr;\n                if (node->lch) node->lch->par = node;\n          \
    \      root = node;\n            }\n        }\n        return;\n    }\n\n    void\
    \ erase(T x) {\n        if (find(x)) {\n            assert(root->val == x);\n\
    \            if (!root->lch)\n                root = root->rch;\n            else\
    \ if (!root->rch)\n                root = root->lch;\n            else {\n   \
    \             assert(root->lch && root->rch);\n                root->lch->par\
    \ = root->rch->par = nullptr;\n                auto rch = root->rch;\n       \
    \         root = root->lch;\n                search(x);\n                root->rch\
    \ = rch;\n                rch->par = root;\n            }\n        }\n       \
    \ if (root) root->par = nullptr;\n        return;\n    }\n\n    std::optional<T>\
    \ lower_bound(T x) {\n        if(!root) return std::nullopt;\n        search(x);\n\
    \        if (x <= root->val) return root->val;\n        if(!root->rch) return\
    \ std::nullopt;\n        auto node = root->rch;\n        while(node->lch) {\n\
    \            node = node->lch;\n        }\n        return std::make_optional<T>(node->val);\n\
    \    }\n\n    std::optional<T> upper_bound(T x) {\n        if(!root) return std::nullopt;\n\
    \        search(x);\n        if(x < root->val) return std::make_shared<T>(root->val);\n\
    \        if(!root->rch) return std::nullopt;\n        auto node = root->rch;\n\
    \        while(node->lch) {\n            node = node->lch;\n        }\n      \
    \  return std::make_optional<T>(node->val);\n    }\n\n    int size() const { return\
    \ root ? root->sz : 0; }\n\n   private:\n    node_ptr root = nullptr;\n};\n\n\
    }  // namespace ebi\n"
  code: "#pragma once\n\n#include <limits>\n#include <memory>\n#include <optional>\n\
    \nnamespace ebi {\n\ntemplate <class T>\nstruct splay_tree {\n   private:\n  \
    \  struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n    struct Node\
    \ {\n        int sz;\n        T val;\n        node_ptr lch, rch, par;\n\n    \
    \    Node(T _val)\n            : sz(1), val(_val), lch(nullptr), rch(nullptr),\
    \ par(nullptr) {}\n\n        bool is_root() { return !par; }\n\n        void update()\
    \ {\n            sz = 1;\n            if (lch) {\n                sz += lch->sz;\n\
    \            }\n            if (rch) {\n                sz += rch->sz;\n     \
    \       }\n        }\n    };\n\n    void rot_L(node_ptr node) {\n        assert(node->par);\n\
    \        auto par = node->par;\n        auto g = par->par;\n        if ((par->rch\
    \ = node->lch)) node->lch->par = par;\n        node->lch = par;\n        par->par\
    \ = node;\n        node->update();\n        par->update();\n        if ((node->par\
    \ = g)) {\n            if (g->lch == par) g->lch = node;\n            if (g->rch\
    \ == par) g->rch = node;\n            g->update();\n        }\n        return;\n\
    \    }\n\n    void rot_R(node_ptr node) {\n        assert(node->par);\n      \
    \  auto par = node->par;\n        auto g = par->par;\n        if ((par->lch =\
    \ node->rch)) node->rch->par = par;\n        node->rch = par;\n        par->par\
    \ = node;\n        node->update();\n        par->update();\n        if ((node->par\
    \ = g)) {\n            if (g->lch == par) g->lch = node;\n            if (g->rch\
    \ == par) g->rch = node;\n            g->update();\n        }\n        return;\n\
    \    }\n\n    void splay(node_ptr node) {\n        if (!node) return;\n      \
    \  while (!node->is_root()) {\n            auto par = node->par;\n           \
    \ if (par->is_root()) {\n                if (par->lch == node) rot_R(node);\n\
    \                if (par->rch == node) rot_L(node);\n            } else {\n  \
    \              auto g = par->par;\n                if (g->lch == par) {\n    \
    \                if (par->lch == node) {\n                        rot_R(par);\n\
    \                        rot_R(node);\n                    } else {\n        \
    \                rot_L(node);\n                        rot_R(node);\n        \
    \            }\n                } else {\n                    assert(g->rch ==\
    \ par);\n                    if (par->rch == node) {\n                       \
    \ rot_L(par);\n                        rot_L(node);\n                    } else\
    \ {\n                        rot_R(node);\n                        rot_L(node);\n\
    \                    }\n                }\n            }\n        }\n        return;\n\
    \    }\n\n    void search(T x) {\n        if (!root) return;\n        node_ptr\
    \ now = root;\n        while (now) {\n            if (now->val == x) {\n     \
    \           break;\n            } else if (now->val < x) {\n                if\
    \ (!now->rch) break;\n                now = now->rch;\n            } else {\n\
    \                if (!now->lch) break;\n                now = now->lch;\n    \
    \        }\n        }\n        assert(now);\n        splay(now);\n        root\
    \ = now;\n        assert(root->is_root());\n        return;\n    }\n\n   public:\n\
    \    splay_tree() = default;\n\n    bool find(T x) {\n        search(x);\n   \
    \     if (!root || root->val != x) return false;\n        return true;\n    }\n\
    \n    void insert(T x) {\n        if (!find(x)) {\n            auto node = std::make_shared<Node>(x);\n\
    \            if (!root)\n                root = node;\n            else if (root->val\
    \ < x) {\n                node->lch = root;\n                root->par = node;\n\
    \                node->rch = root->rch;\n                root->rch = nullptr;\n\
    \                if (node->rch) node->rch->par = node;\n                root =\
    \ node;\n            } else {\n                node->rch = root;\n           \
    \     root->par = node;\n                node->lch = root->lch;\n            \
    \    root->lch = nullptr;\n                if (node->lch) node->lch->par = node;\n\
    \                root = node;\n            }\n        }\n        return;\n   \
    \ }\n\n    void erase(T x) {\n        if (find(x)) {\n            assert(root->val\
    \ == x);\n            if (!root->lch)\n                root = root->rch;\n   \
    \         else if (!root->rch)\n                root = root->lch;\n          \
    \  else {\n                assert(root->lch && root->rch);\n                root->lch->par\
    \ = root->rch->par = nullptr;\n                auto rch = root->rch;\n       \
    \         root = root->lch;\n                search(x);\n                root->rch\
    \ = rch;\n                rch->par = root;\n            }\n        }\n       \
    \ if (root) root->par = nullptr;\n        return;\n    }\n\n    std::optional<T>\
    \ lower_bound(T x) {\n        if(!root) return std::nullopt;\n        search(x);\n\
    \        if (x <= root->val) return root->val;\n        if(!root->rch) return\
    \ std::nullopt;\n        auto node = root->rch;\n        while(node->lch) {\n\
    \            node = node->lch;\n        }\n        return std::make_optional<T>(node->val);\n\
    \    }\n\n    std::optional<T> upper_bound(T x) {\n        if(!root) return std::nullopt;\n\
    \        search(x);\n        if(x < root->val) return std::make_shared<T>(root->val);\n\
    \        if(!root->rch) return std::nullopt;\n        auto node = root->rch;\n\
    \        while(node->lch) {\n            node = node->lch;\n        }\n      \
    \  return std::make_optional<T>(node->val);\n    }\n\n    int size() const { return\
    \ root ? root->sz : 0; }\n\n   private:\n    node_ptr root = nullptr;\n};\n\n\
    }  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/splay_tree.hpp
  requiredBy: []
  timestamp: '2023-05-08 14:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/splay_tree.hpp
layout: document
redirect_from:
- /library/data_structure/splay_tree.hpp
- /library/data_structure/splay_tree.hpp.html
title: data_structure/splay_tree.hpp
---
