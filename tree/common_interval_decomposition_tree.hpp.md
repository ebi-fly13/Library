---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Common_Interval_Decomposition_Tree.test.cpp
    title: test/tree/Common_Interval_Decomposition_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.mathenachia.blog/permutation-tree/
  bundledCode: "#line 2 \"tree/common_interval_decomposition_tree.hpp\"\n\n#include\
    \ <cassert>\n#include <numeric>\n#include <vector>\n\n#line 2 \"data_structure/sparse_table.hpp\"\
    \n\r\n#line 4 \"data_structure/sparse_table.hpp\"\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class Band, Band (*op)(Band, Band)>\
    \ struct sparse_table {\r\n  public:\r\n    sparse_table() = default;\r\n\r\n\
    \    sparse_table(const std::vector<Band> &a) : n(a.size()) {\r\n        table\
    \ = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n        for (int i\
    \ = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n        }\r\n     \
    \   for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int i = 0; i + (1\
    \ << k) <= n; i++) {\r\n                table[k][i] =\r\n                    op(table[k\
    \ - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n            }\r\n        }\r\n\
    \    }\r\n\r\n    void build(const std::vector<Band> &a) {\r\n        n = (int)a.size();\r\
    \n        table = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n   \
    \     for (int i = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n   \
    \     }\r\n        for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int\
    \ i = 0; i + (1 << k) <= n; i++) {\r\n                table[k][i] =\r\n      \
    \              op(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n    \
    \        }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Band fold(int l,\
    \ int r) {\r\n        int k = std::__lg(r - l);\r\n        return op(table[k][l],\
    \ table[k][r - (1 << k)]);\r\n    }\r\n\r\n  private:\r\n    int n;\r\n    std::vector<std::vector<Band>>\
    \ table;\r\n};\r\n\r\n}  // namespace ebi\n#line 8 \"tree/common_interval_decomposition_tree.hpp\"\
    \n\n/*\nreference: https://www.mathenachia.blog/permutation-tree/\n*/\n\nnamespace\
    \ ebi {\n\nstruct common_interval_decomposition_tree {\n  public:\n    enum NodeType\
    \ {\n        Prime,\n        Dec,\n        Inc,\n        One,\n    };\n\n    struct\
    \ Node {\n        int parent;\n        NodeType type;\n        int l, r;\n   \
    \ };\n\n  private:\n    static int op(int a, int b) {\n        return a < b ?\
    \ a : b;\n    }\n\n    void build(const std::vector<int> &p) {\n        int n\
    \ = (int)p.size();\n        std::vector<int> q(n, -1);\n        for (int i = 0;\
    \ i < n; i++) {\n            assert(0 <= p[i] && p[i] < n && q[p[i]] == -1);\n\
    \            q[p[i]] = i;\n        }\n        sparse_table<int, op> static_range_min(q);\n\
    \        struct LeftBase {\n            int l;\n            int vl, vr;\n    \
    \    };\n        struct Common {\n            int l, r, v;\n        };\n     \
    \   std::vector<LeftBase> stack;\n        std::vector<Common> commons;\n     \
    \   for (int r = 1; r <= n; r++) {\n            int a = p[r - 1];\n          \
    \  LeftBase y = {r - 1, a, a + 1};\n            while (!stack.empty()) {\n   \
    \             if (y.vl < stack.back().vl) stack.back().vl = y.vl;\n          \
    \      if (y.vr > stack.back().vr) stack.back().vr = y.vr;\n                auto\
    \ x = stack.back();\n                if (static_range_min.fold(x.vl, x.vr) < x.l)\
    \ {\n                    stack.pop_back();\n                    auto &new_x =\
    \ stack.back();\n                    if (x.vl < new_x.vl) new_x.vl = x.vl;\n \
    \                   if (x.vr > new_x.vr) new_x.vr = x.vr;\n                } else\
    \ if (x.vr - x.vl == r - x.l) {\n                    y = x;\n                \
    \    stack.pop_back();\n                    commons.emplace_back(x.l, r, x.vl);\n\
    \                } else {\n                    break;\n                }\n   \
    \         }\n            stack.push_back(y);\n        }\n        while (stack.size()\
    \ >= 2) {\n            auto x = stack.back();\n            stack.pop_back();\n\
    \            auto &new_x = stack.back();\n            if (x.vl < new_x.vl) new_x.vl\
    \ = x.vl;\n            if (x.vr > new_x.vr) new_x.vr = x.vr;\n            if (new_x.vr\
    \ - new_x.vl == n - new_x.l) {\n                commons.emplace_back(new_x.l,\
    \ n, new_x.vl);\n            }\n        }\n        assert(stack.size() == 1);\n\
    \        for (int i = 0; i < n; i++) tree.emplace_back(-1, One, i, i + 1);\n \
    \       std::vector<int> id(n);\n        std::iota(id.begin(), id.end(), 0);\n\
    \        std::vector<int> right_list(n);\n        std::iota(right_list.begin(),\
    \ right_list.end(), 1);\n        for (auto common : commons) {\n            int\
    \ m = right_list[common.l];\n            if (right_list[m] == common.r) {\n  \
    \              int a = id[common.l];\n                int b = id[m];\n       \
    \         right_list[common.l] = common.r;\n                auto t = p[common.l]\
    \ < p[common.r - 1] ? Inc : Dec;\n                if (tree[a].type == t) {\n \
    \                   tree[b].parent = a;\n                    tree[a].r = common.r;\n\
    \                } else {\n                    int c = (int)tree.size();\n   \
    \                 tree.emplace_back(-1, t, common.l, common.r);\n            \
    \        tree[a].parent = c;\n                    tree[b].parent = c;\n      \
    \              id[common.l] = c;\n                }\n            } else {\n  \
    \              int c = (int)tree.size();\n                tree.emplace_back(-1,\
    \ Prime, common.l, common.r);\n                for (int i = common.l; i < common.r;\
    \ i = right_list[i]) {\n                    tree[id[i]].parent = c;\n        \
    \        }\n                id[common.l] = c;\n                right_list[common.l]\
    \ = common.r;\n            }\n        }\n    }\n\n  public:\n    common_interval_decomposition_tree(const\
    \ std::vector<int> &p) {\n        build(p);\n    }\n\n    std::vector<Node> get_tree()\
    \ const {\n        return tree;\n    }\n\n  private:\n    std::vector<Node> tree;\n\
    };\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    \n#include \"../data_structure/sparse_table.hpp\"\n\n/*\nreference: https://www.mathenachia.blog/permutation-tree/\n\
    */\n\nnamespace ebi {\n\nstruct common_interval_decomposition_tree {\n  public:\n\
    \    enum NodeType {\n        Prime,\n        Dec,\n        Inc,\n        One,\n\
    \    };\n\n    struct Node {\n        int parent;\n        NodeType type;\n  \
    \      int l, r;\n    };\n\n  private:\n    static int op(int a, int b) {\n  \
    \      return a < b ? a : b;\n    }\n\n    void build(const std::vector<int> &p)\
    \ {\n        int n = (int)p.size();\n        std::vector<int> q(n, -1);\n    \
    \    for (int i = 0; i < n; i++) {\n            assert(0 <= p[i] && p[i] < n &&\
    \ q[p[i]] == -1);\n            q[p[i]] = i;\n        }\n        sparse_table<int,\
    \ op> static_range_min(q);\n        struct LeftBase {\n            int l;\n  \
    \          int vl, vr;\n        };\n        struct Common {\n            int l,\
    \ r, v;\n        };\n        std::vector<LeftBase> stack;\n        std::vector<Common>\
    \ commons;\n        for (int r = 1; r <= n; r++) {\n            int a = p[r -\
    \ 1];\n            LeftBase y = {r - 1, a, a + 1};\n            while (!stack.empty())\
    \ {\n                if (y.vl < stack.back().vl) stack.back().vl = y.vl;\n   \
    \             if (y.vr > stack.back().vr) stack.back().vr = y.vr;\n          \
    \      auto x = stack.back();\n                if (static_range_min.fold(x.vl,\
    \ x.vr) < x.l) {\n                    stack.pop_back();\n                    auto\
    \ &new_x = stack.back();\n                    if (x.vl < new_x.vl) new_x.vl =\
    \ x.vl;\n                    if (x.vr > new_x.vr) new_x.vr = x.vr;\n         \
    \       } else if (x.vr - x.vl == r - x.l) {\n                    y = x;\n   \
    \                 stack.pop_back();\n                    commons.emplace_back(x.l,\
    \ r, x.vl);\n                } else {\n                    break;\n          \
    \      }\n            }\n            stack.push_back(y);\n        }\n        while\
    \ (stack.size() >= 2) {\n            auto x = stack.back();\n            stack.pop_back();\n\
    \            auto &new_x = stack.back();\n            if (x.vl < new_x.vl) new_x.vl\
    \ = x.vl;\n            if (x.vr > new_x.vr) new_x.vr = x.vr;\n            if (new_x.vr\
    \ - new_x.vl == n - new_x.l) {\n                commons.emplace_back(new_x.l,\
    \ n, new_x.vl);\n            }\n        }\n        assert(stack.size() == 1);\n\
    \        for (int i = 0; i < n; i++) tree.emplace_back(-1, One, i, i + 1);\n \
    \       std::vector<int> id(n);\n        std::iota(id.begin(), id.end(), 0);\n\
    \        std::vector<int> right_list(n);\n        std::iota(right_list.begin(),\
    \ right_list.end(), 1);\n        for (auto common : commons) {\n            int\
    \ m = right_list[common.l];\n            if (right_list[m] == common.r) {\n  \
    \              int a = id[common.l];\n                int b = id[m];\n       \
    \         right_list[common.l] = common.r;\n                auto t = p[common.l]\
    \ < p[common.r - 1] ? Inc : Dec;\n                if (tree[a].type == t) {\n \
    \                   tree[b].parent = a;\n                    tree[a].r = common.r;\n\
    \                } else {\n                    int c = (int)tree.size();\n   \
    \                 tree.emplace_back(-1, t, common.l, common.r);\n            \
    \        tree[a].parent = c;\n                    tree[b].parent = c;\n      \
    \              id[common.l] = c;\n                }\n            } else {\n  \
    \              int c = (int)tree.size();\n                tree.emplace_back(-1,\
    \ Prime, common.l, common.r);\n                for (int i = common.l; i < common.r;\
    \ i = right_list[i]) {\n                    tree[id[i]].parent = c;\n        \
    \        }\n                id[common.l] = c;\n                right_list[common.l]\
    \ = common.r;\n            }\n        }\n    }\n\n  public:\n    common_interval_decomposition_tree(const\
    \ std::vector<int> &p) {\n        build(p);\n    }\n\n    std::vector<Node> get_tree()\
    \ const {\n        return tree;\n    }\n\n  private:\n    std::vector<Node> tree;\n\
    };\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/sparse_table.hpp
  isVerificationFile: false
  path: tree/common_interval_decomposition_tree.hpp
  requiredBy: []
  timestamp: '2025-03-24 18:22:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Common_Interval_Decomposition_Tree.test.cpp
documentation_of: tree/common_interval_decomposition_tree.hpp
layout: document
title: Common Interval Decomposition Tree
---

## 説明

Common Interval Decomposition Tree (別称:Permutation Tree) を構築する。
$O(N\log{N})$