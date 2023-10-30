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
    #include <algorithm>\r\n#include <vector>\r\n\r\n/*\r\n    refernce: https://noshi91.hatenablog.com/entry/2018/02/18/161529\r\
    \n    verify:\r\n   https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/21131946\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct partially_persistent_unionfind {\r\n\
    \  private:\r\n    int now = 0;\r\n    std::vector<int> par, time;\r\n    std::vector<std::vector<std::pair<int,\
    \ int>>> data;\r\n\r\n  public:\r\n    partially_persistent_unionfind(int n) :\
    \ par(n, 1), time(n, 1e9), data(n) {\r\n        for (auto &v : data) {\r\n   \
    \         v.emplace_back(0, 1);\r\n        }\r\n    }\r\n\r\n    int find(int\
    \ t, int v) {\r\n        if (time[v] > t)\r\n            return v;\r\n       \
    \ else\r\n            return find(t, par[v]);\r\n    }\r\n\r\n    bool merge(int\
    \ a, int b) {\r\n        ++now;\r\n        a = find(now, a);\r\n        b = find(now,\
    \ b);\r\n        if (a == b) return false;\r\n        if (par[a] < par[b]) std::swap(a,\
    \ b);\r\n        par[a] += par[b];\r\n        data[a].emplace_back(now, par[a]);\r\
    \n        par[b] = a;\r\n        time[b] = now;\r\n        return true;\r\n  \
    \  }\r\n\r\n    bool same(int t, int a, int b) {\r\n        return find(t, a)\
    \ == find(t, b);\r\n    }\r\n\r\n    int size(int t, int v) {\r\n        v = find(t,\
    \ v);\r\n        return std::prev(std::upper_bound(data[v].begin(), data[v].end(),\r\
    \n                                          std::pair<int, int>(t, 0)))\r\n  \
    \          ->second;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <vector>\r\n\r\n/*\r\
    \n    refernce: https://noshi91.hatenablog.com/entry/2018/02/18/161529\r\n   \
    \ verify:\r\n   https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/21131946\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct partially_persistent_unionfind {\r\n\
    \  private:\r\n    int now = 0;\r\n    std::vector<int> par, time;\r\n    std::vector<std::vector<std::pair<int,\
    \ int>>> data;\r\n\r\n  public:\r\n    partially_persistent_unionfind(int n) :\
    \ par(n, 1), time(n, 1e9), data(n) {\r\n        for (auto &v : data) {\r\n   \
    \         v.emplace_back(0, 1);\r\n        }\r\n    }\r\n\r\n    int find(int\
    \ t, int v) {\r\n        if (time[v] > t)\r\n            return v;\r\n       \
    \ else\r\n            return find(t, par[v]);\r\n    }\r\n\r\n    bool merge(int\
    \ a, int b) {\r\n        ++now;\r\n        a = find(now, a);\r\n        b = find(now,\
    \ b);\r\n        if (a == b) return false;\r\n        if (par[a] < par[b]) std::swap(a,\
    \ b);\r\n        par[a] += par[b];\r\n        data[a].emplace_back(now, par[a]);\r\
    \n        par[b] = a;\r\n        time[b] = now;\r\n        return true;\r\n  \
    \  }\r\n\r\n    bool same(int t, int a, int b) {\r\n        return find(t, a)\
    \ == find(t, b);\r\n    }\r\n\r\n    int size(int t, int v) {\r\n        v = find(t,\
    \ v);\r\n        return std::prev(std::upper_bound(data[v].begin(), data[v].end(),\r\
    \n                                          std::pair<int, int>(t, 0)))\r\n  \
    \          ->second;\r\n    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/partially_persistent_unionfind.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/partially_persistent_unionfind.hpp
layout: document
title: partially persistent unionfind
---

## 説明

### find(t, v)

時刻 $t$ での $v$ の親を返す。 $O(\log N)$

### merge(a, b)

$a$ と $b$ のグループをマージする。 $O(\log N)$

### same(t, a, b)

時刻 $t$ で $a$ と $b$ が同じグループに属するか判定する。 $O(\log N)$