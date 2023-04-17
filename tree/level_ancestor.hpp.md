---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/Jump_on_Tree.cpp
    title: test/Jump_on_Tree.cpp
  - icon: ':warning:'
    path: test/level_ancestor_lca.cpp
    title: test/level_ancestor_lca.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/level_ancestor.hpp\"\n\r\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n\r\nnamespace ebi {\r\n\r\nstruct level_ancestor\
    \ {\r\nprivate:\r\n    int n;\r\n    std::vector<int> in;\r\n    std::vector<int>\
    \ inv_in;\r\n    std::vector<int> depths;\r\n    std::vector<std::vector<int>>\
    \ s;\r\npublic:\r\n    level_ancestor(const std::vector<std::vector<int>> &gh,\
    \ int root = 0) : n(gh.size()), in(n), inv_in(n), depths(n) {\r\n        int cnt\
    \ = 0;\r\n        int max = 0;\r\n        auto dfs = [&](auto &&self, int v, int\
    \ par = -1) -> void {\r\n            inv_in[cnt] = v;\r\n            in[v] = cnt++;\r\
    \n            max = std::max(max, depths[v]);\r\n            for(auto nv: gh[v])\
    \ if(nv != par) {\r\n                depths[nv] = depths[v] + 1;\r\n         \
    \       self(self, nv, v);\r\n            }\r\n        };\r\n        dfs(dfs,\
    \ root);\r\n        s.resize(max+1);\r\n        for(int i = 0; i < n; i++) {\r\
    \n            int u = inv_in[i];\r\n            s[depths[u]].emplace_back(i);\r\
    \n        }\r\n    }\r\n\r\n    int query(int u, int k) const {\r\n        int\
    \ m = depths[u] - k;\r\n        assert(m >= 0);\r\n        return inv_in[*std::prev(std::upper_bound(s[m].begin(),\
    \ s[m].end(), in[u]))];\r\n    }\r\n\r\n    int depth(int u) const {\r\n     \
    \   return depths[u];\r\n    }\r\n};\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <algorithm>\r\n#include\
    \ <cassert>\r\n\r\nnamespace ebi {\r\n\r\nstruct level_ancestor {\r\nprivate:\r\
    \n    int n;\r\n    std::vector<int> in;\r\n    std::vector<int> inv_in;\r\n \
    \   std::vector<int> depths;\r\n    std::vector<std::vector<int>> s;\r\npublic:\r\
    \n    level_ancestor(const std::vector<std::vector<int>> &gh, int root = 0) :\
    \ n(gh.size()), in(n), inv_in(n), depths(n) {\r\n        int cnt = 0;\r\n    \
    \    int max = 0;\r\n        auto dfs = [&](auto &&self, int v, int par = -1)\
    \ -> void {\r\n            inv_in[cnt] = v;\r\n            in[v] = cnt++;\r\n\
    \            max = std::max(max, depths[v]);\r\n            for(auto nv: gh[v])\
    \ if(nv != par) {\r\n                depths[nv] = depths[v] + 1;\r\n         \
    \       self(self, nv, v);\r\n            }\r\n        };\r\n        dfs(dfs,\
    \ root);\r\n        s.resize(max+1);\r\n        for(int i = 0; i < n; i++) {\r\
    \n            int u = inv_in[i];\r\n            s[depths[u]].emplace_back(i);\r\
    \n        }\r\n    }\r\n\r\n    int query(int u, int k) const {\r\n        int\
    \ m = depths[u] - k;\r\n        assert(m >= 0);\r\n        return inv_in[*std::prev(std::upper_bound(s[m].begin(),\
    \ s[m].end(), in[u]))];\r\n    }\r\n\r\n    int depth(int u) const {\r\n     \
    \   return depths[u];\r\n    }\r\n};\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree/level_ancestor.hpp
  requiredBy:
  - test/level_ancestor_lca.cpp
  - test/Jump_on_Tree.cpp
  timestamp: '2023-04-17 15:17:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/level_ancestor.hpp
layout: document
redirect_from:
- /library/tree/level_ancestor.hpp
- /library/tree/level_ancestor.hpp.html
title: tree/level_ancestor.hpp
---
