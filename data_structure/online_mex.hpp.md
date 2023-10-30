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
    - https://twitter.com/noshi91/status/1283759174791372809
  bundledCode: "#line 2 \"data_structure/online_mex.hpp\"\n\n/*\n    reference: https://twitter.com/noshi91/status/1283759174791372809\n\
    \n    Query\n    add(int x) : amortized O(1)\n    mex : amortized O(1)\n*/\n\n\
    #include <vector>\n\nnamespace ebi {\n\nstruct online_mex {\n  private:\n    int\
    \ mex_ = 0;\n    int q = 0;\n    int k = 1;\n    std::vector<int> ret;\n    std::vector<int>\
    \ p;\n\n    void update_mex() {\n        while (ret[mex_] > 0) {\n           \
    \ mex_++;\n        }\n    }\n\n    void increment() {\n        q++;\n        if\
    \ (q < k) return;\n        k *= 2;\n        ret.assign(k, 0);\n        for (const\
    \ auto &val : p) {\n            if (val < k) ret[val]++;\n        }\n    }\n\n\
    \  public:\n    online_mex() : ret(1, 0) {}\n\n    void add(int x) {\n       \
    \ p.emplace_back(x);\n        if (x < k) {\n            ret[x]++;\n        }\n\
    \        increment();\n    }\n\n    int mex() {\n        update_mex();\n     \
    \   return mex_;\n    }\n\n    int size() const {\n        return p.size();\n\
    \    }\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n/*\n    reference: https://twitter.com/noshi91/status/1283759174791372809\n\
    \n    Query\n    add(int x) : amortized O(1)\n    mex : amortized O(1)\n*/\n\n\
    #include <vector>\n\nnamespace ebi {\n\nstruct online_mex {\n  private:\n    int\
    \ mex_ = 0;\n    int q = 0;\n    int k = 1;\n    std::vector<int> ret;\n    std::vector<int>\
    \ p;\n\n    void update_mex() {\n        while (ret[mex_] > 0) {\n           \
    \ mex_++;\n        }\n    }\n\n    void increment() {\n        q++;\n        if\
    \ (q < k) return;\n        k *= 2;\n        ret.assign(k, 0);\n        for (const\
    \ auto &val : p) {\n            if (val < k) ret[val]++;\n        }\n    }\n\n\
    \  public:\n    online_mex() : ret(1, 0) {}\n\n    void add(int x) {\n       \
    \ p.emplace_back(x);\n        if (x < k) {\n            ret[x]++;\n        }\n\
    \        increment();\n    }\n\n    int mex() {\n        update_mex();\n     \
    \   return mex_;\n    }\n\n    int size() const {\n        return p.size();\n\
    \    }\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/online_mex.hpp
  requiredBy: []
  timestamp: '2023-10-19 17:23:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/online_mex.hpp
layout: document
title: online mex
---

## 説明

onlineで追加された値の集合のmexを計算する。

### add(x)

非負整数 $x$ を集合に追加する。 amortized $O(1)$

### mex()

集合のmexを返す。 amortized $O(1)$

### size()

追加した値の個数を返す。 $O(1)$