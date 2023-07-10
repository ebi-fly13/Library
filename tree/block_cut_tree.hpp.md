---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.hpp
    title: graph/biconnected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: Low Link
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Biconnected_Components.test.cpp
    title: test/graph/Biconnected_Components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/block_cut_tree.hpp\"\n\n#include <cassert>\n\n#line\
    \ 2 \"graph/biconnected_components.hpp\"\n\n#line 2 \"graph/low_link.hpp\"\n\n\
    #include <algorithm>\n#include <utility>\n#include <vector>\n\nnamespace ebi {\n\
    \nstruct low_link {\n  private:\n    void dfs(int v, int par = -1) {\n       \
    \ static int k = 0;\n        low[v] = ord[v] = k++;\n        int cnt = 0;\n  \
    \      bool is_arti = false, is_second = false;\n        for (auto nv : g[v])\
    \ {\n            if (ord[nv] == -1) {\n                cnt++;\n              \
    \  dfs(nv, v);\n                low[v] = std::min(low[v], low[nv]);\n        \
    \        is_arti |= (par != -1) && (low[nv] >= ord[v]);\n                if (ord[v]\
    \ < low[nv]) {\n                    _bridge.emplace_back(std::minmax(v, nv));\n\
    \                }\n            } else if (nv != par || is_second) {\n       \
    \         low[v] = std::min(low[v], ord[nv]);\n            } else {\n        \
    \        is_second = true;\n            }\n        }\n        is_arti |= par ==\
    \ -1 && cnt > 1;\n        if (is_arti) _articulation.emplace_back(v);\n    }\n\
    \n  public:\n    low_link(const std::vector<std::vector<int>> &g)\n        : n(g.size()),\
    \ g(g), ord(n, -1), low(n) {\n        for (int i = 0; i < n; i++) {\n        \
    \    if (ord[i] == -1) dfs(i);\n        }\n    }\n\n    std::vector<int> articulation()\
    \ const {\n        return _articulation;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> bridge() const {\n        return _bridge;\n    }\n\n  protected:\n   \
    \ int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> ord, low,\
    \ _articulation;\n    std::vector<std::pair<int, int>> _bridge;\n};\n\n}  // namespace\
    \ ebi\n#line 4 \"graph/biconnected_components.hpp\"\n\nnamespace ebi {\n\nstruct\
    \ biconnected_components : low_link {\n  private:\n    void dfs(int v, int par\
    \ = -1) {\n        used[v] = true;\n        for (auto nv : this->g[v]) {\n   \
    \         if (nv == par) continue;\n            if (!used[nv] || this->ord[nv]\
    \ < this->ord[v]) {\n                tmp.emplace_back(std::minmax(v, nv));\n \
    \           }\n            if (!used[nv]) {\n                dfs(nv, v);\n   \
    \             if (this->low[nv] >= this->ord[v]) {\n                    bc.emplace_back();\n\
    \                    while (true) {\n                        auto e = tmp.back();\n\
    \                        bc.back().emplace_back(e);\n                        tmp.pop_back();\n\
    \                        if (e.first == std::min(v, nv) &&\n                 \
    \           e.second == std::max(v, nv)) {\n                            break;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n        }\n    }\n\n  public:\n    biconnected_components(const std::vector<std::vector<int>>\
    \ &g)\n        : low_link(g), used(this->n, false) {\n        for (int i = 0;\
    \ i < this->n; i++) {\n            if (!used[i]) dfs(i);\n        }\n    }\n\n\
    \  protected:\n    std::vector<bool> used;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> bc;\n    std::vector<std::pair<int, int>> tmp;\n};\n\n}  // namespace\
    \ ebi\n#line 6 \"tree/block_cut_tree.hpp\"\n\nnamespace ebi {\n\nstruct block_cut_tree\
    \ : biconnected_components {\n  public:\n    block_cut_tree(const std::vector<std::vector<int>>\
    \ &g)\n        : biconnected_components(g), rev(this->n, -1) {\n        int cnt\
    \ = 0;\n        for (auto v : this->_articulation) {\n            rev[v] = cnt++;\n\
    \        }\n        int sz = cnt + this->bc.size();\n        tree.resize(sz);\n\
    \        std::vector<int> last(this->n, -1);\n        for (int i = cnt; i < sz;\
    \ i++) {\n            for (auto e : this->bc[i - cnt]) {\n                for\
    \ (auto v : {e.first, e.second}) {\n                    if (rev[v] != -1 && rev[v]\
    \ < cnt) {\n                        if (std::exchange(last[v], i) != i) {\n  \
    \                          tree[i].emplace_back(rev[v]);\n                   \
    \         tree[rev[v]].emplace_back(i);\n                        }\n         \
    \           } else {\n                        rev[v] = i;\n                  \
    \  }\n                }\n            }\n        }\n        groups.resize(sz);\n\
    \        for (int i = 0; i < this->n; i++) {\n            if (rev[i] < 0) {\n\
    \                rev[i] = sz++;\n                groups.emplace_back();\n    \
    \            tree.emplace_back();\n            }\n            groups[rev[i]].emplace_back(i);\n\
    \        }\n    }\n\n    std::vector<std::vector<int>> bcc() {\n        int cnt\
    \ = this->_articulation.size();\n        int sz = groups.size() - cnt;\n     \
    \   std::vector _bcc(sz, std::vector<int>());\n        for (int i = 0; i < sz;\
    \ i++) {\n            _bcc[i] = groups[cnt + i];\n            for (auto nv : tree[cnt\
    \ + i]) {\n                assert(0 <= nv && nv < cnt);\n                assert(groups[nv].size()\
    \ == 1);\n                _bcc[i].emplace_back(groups[nv][0]);\n            }\n\
    \        }\n        return _bcc;\n    }\n\n  private:\n    std::vector<int> rev;\n\
    \    std::vector<std::vector<int>> tree;\n    std::vector<std::vector<int>> groups;\n\
    };\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n\n#include \"../graph/biconnected_components.hpp\"\
    \n\nnamespace ebi {\n\nstruct block_cut_tree : biconnected_components {\n  public:\n\
    \    block_cut_tree(const std::vector<std::vector<int>> &g)\n        : biconnected_components(g),\
    \ rev(this->n, -1) {\n        int cnt = 0;\n        for (auto v : this->_articulation)\
    \ {\n            rev[v] = cnt++;\n        }\n        int sz = cnt + this->bc.size();\n\
    \        tree.resize(sz);\n        std::vector<int> last(this->n, -1);\n     \
    \   for (int i = cnt; i < sz; i++) {\n            for (auto e : this->bc[i - cnt])\
    \ {\n                for (auto v : {e.first, e.second}) {\n                  \
    \  if (rev[v] != -1 && rev[v] < cnt) {\n                        if (std::exchange(last[v],\
    \ i) != i) {\n                            tree[i].emplace_back(rev[v]);\n    \
    \                        tree[rev[v]].emplace_back(i);\n                     \
    \   }\n                    } else {\n                        rev[v] = i;\n   \
    \                 }\n                }\n            }\n        }\n        groups.resize(sz);\n\
    \        for (int i = 0; i < this->n; i++) {\n            if (rev[i] < 0) {\n\
    \                rev[i] = sz++;\n                groups.emplace_back();\n    \
    \            tree.emplace_back();\n            }\n            groups[rev[i]].emplace_back(i);\n\
    \        }\n    }\n\n    std::vector<std::vector<int>> bcc() {\n        int cnt\
    \ = this->_articulation.size();\n        int sz = groups.size() - cnt;\n     \
    \   std::vector _bcc(sz, std::vector<int>());\n        for (int i = 0; i < sz;\
    \ i++) {\n            _bcc[i] = groups[cnt + i];\n            for (auto nv : tree[cnt\
    \ + i]) {\n                assert(0 <= nv && nv < cnt);\n                assert(groups[nv].size()\
    \ == 1);\n                _bcc[i].emplace_back(groups[nv][0]);\n            }\n\
    \        }\n        return _bcc;\n    }\n\n  private:\n    std::vector<int> rev;\n\
    \    std::vector<std::vector<int>> tree;\n    std::vector<std::vector<int>> groups;\n\
    };\n\n}  // namespace ebi"
  dependsOn:
  - graph/biconnected_components.hpp
  - graph/low_link.hpp
  isVerificationFile: false
  path: tree/block_cut_tree.hpp
  requiredBy: []
  timestamp: '2023-07-10 11:25:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Biconnected_Components.test.cpp
documentation_of: tree/block_cut_tree.hpp
layout: document
redirect_from:
- /library/tree/block_cut_tree.hpp
- /library/tree/block_cut_tree.hpp.html
title: tree/block_cut_tree.hpp
---
