---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/21131946
    - https://noshi91.hatenablog.com/entry/2018/02/18/161529
  bundledCode: "#line 2 \"data_structure/partially_persistent_unionfind.hpp\"\n\r\n\
    #include <vector>\r\n#include <algorithm>\r\n\r\n/*\r\n    refernce: https://noshi91.hatenablog.com/entry/2018/02/18/161529\r\
    \n    verify: https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/21131946\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct partially_persistent_unionfind {\r\n\
    private:\r\n    int now = 0;\r\n    std::vector<int> par,time;\r\n    std::vector<std::vector<std::pair<int,int>>>\
    \ data;\r\npublic:\r\n    partially_persistent_unionfind(int n) : par(n,1), time(n,1e9),\
    \ data(n) {\r\n        for(auto &v : data) {\r\n            v.emplace_back(0,1);\r\
    \n        }\r\n    }\r\n\r\n    int find(int t, int v) {\r\n        if(time[v]\
    \ > t) return v;\r\n        else return find(t, par[v]);\r\n    }\r\n\r\n    bool\
    \ merge(int a, int b) {\r\n        ++now;\r\n        a = find(now, a);\r\n   \
    \     b = find(now, b);\r\n        if(a == b) return false;\r\n        if(par[a]\
    \ < par[b]) std::swap(a,b);\r\n        par[a] += par[b];\r\n        data[a].emplace_back(now,\
    \ par[a]);\r\n        par[b] = a;\r\n        time[b] = now;\r\n        return\
    \ true;\r\n    }\r\n\r\n    bool same(int t, int a, int b) {\r\n        return\
    \ find(t, a) == find(t, b);\r\n    }\r\n\r\n    int size(int t, int v) {\r\n \
    \       v = find(t,v);\r\n        return std::prev(std::upper_bound(data[v].begin(),\
    \ data[v].end(), std::pair<int,int>(t,0)))->second;\r\n    }\r\n\r\n};\r\n\r\n\
    }\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <algorithm>\r\n\r\n/*\r\
    \n    refernce: https://noshi91.hatenablog.com/entry/2018/02/18/161529\r\n   \
    \ verify: https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/21131946\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct partially_persistent_unionfind {\r\n\
    private:\r\n    int now = 0;\r\n    std::vector<int> par,time;\r\n    std::vector<std::vector<std::pair<int,int>>>\
    \ data;\r\npublic:\r\n    partially_persistent_unionfind(int n) : par(n,1), time(n,1e9),\
    \ data(n) {\r\n        for(auto &v : data) {\r\n            v.emplace_back(0,1);\r\
    \n        }\r\n    }\r\n\r\n    int find(int t, int v) {\r\n        if(time[v]\
    \ > t) return v;\r\n        else return find(t, par[v]);\r\n    }\r\n\r\n    bool\
    \ merge(int a, int b) {\r\n        ++now;\r\n        a = find(now, a);\r\n   \
    \     b = find(now, b);\r\n        if(a == b) return false;\r\n        if(par[a]\
    \ < par[b]) std::swap(a,b);\r\n        par[a] += par[b];\r\n        data[a].emplace_back(now,\
    \ par[a]);\r\n        par[b] = a;\r\n        time[b] = now;\r\n        return\
    \ true;\r\n    }\r\n\r\n    bool same(int t, int a, int b) {\r\n        return\
    \ find(t, a) == find(t, b);\r\n    }\r\n\r\n    int size(int t, int v) {\r\n \
    \       v = find(t,v);\r\n        return std::prev(std::upper_bound(data[v].begin(),\
    \ data[v].end(), std::pair<int,int>(t,0)))->second;\r\n    }\r\n\r\n};\r\n\r\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/partially_persistent_unionfind.hpp
  requiredBy: []
  timestamp: '2021-03-21 17:57:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/partially_persistent_unionfind.hpp
layout: document
redirect_from:
- /library/data_structure/partially_persistent_unionfind.hpp
- /library/data_structure/partially_persistent_unionfind.hpp.html
title: data_structure/partially_persistent_unionfind.hpp
---
