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
    - https://theory-and-me.hatenablog.com/entry/2020/03/17/180157
  bundledCode: "#line 2 \"graph/submodular.hpp\"\n\n/*\n    reference: https://theory-and-me.hatenablog.com/entry/2020/03/17/180157\n\
    \    depends on mf_graph in atcoder library(acl).\n*/\n\nnamespace ebi {\n\ntemplate<class\
    \ Cap>\nstruct submodular {\npublic:\n    submodular(int n) : gh(n+2), s(n), t(n+1)\
    \  { }\n\n    void add_one_variable_function(int i, Cap f0, Cap f1) {\n      \
    \  if(f0 <= f1) {\n            gh.add_edge(s, i, f1-f0);\n            R += f0;\n\
    \        }\n        else {\n            gh.add_edge(i, t, f0-f1);\n          \
    \  R += f1;\n        }\n    }\n\n    void add_two_variable_function(int i, int\
    \ j, Cap a, Cap b, Cap c, Cap d) {\n        assert(i < j);\n        R += a;\n\
    \        add_one_variable_function(i, 0, c-a);\n        add_one_variable_function(j,\
    \ 0, d-c);\n        gh.add_edge(i, j, b+c-a-d);\n    }\n\n    Cap min() {\n  \
    \      return gh.flow(s, t) + R;\n    }\nprivate:\n    atcoder::mf_graph<Cap>\
    \ gh;\n    int s,t;\n    Cap R = 0;\n};\n\n}\n"
  code: "#pragma once\n\n/*\n    reference: https://theory-and-me.hatenablog.com/entry/2020/03/17/180157\n\
    \    depends on mf_graph in atcoder library(acl).\n*/\n\nnamespace ebi {\n\ntemplate<class\
    \ Cap>\nstruct submodular {\npublic:\n    submodular(int n) : gh(n+2), s(n), t(n+1)\
    \  { }\n\n    void add_one_variable_function(int i, Cap f0, Cap f1) {\n      \
    \  if(f0 <= f1) {\n            gh.add_edge(s, i, f1-f0);\n            R += f0;\n\
    \        }\n        else {\n            gh.add_edge(i, t, f0-f1);\n          \
    \  R += f1;\n        }\n    }\n\n    void add_two_variable_function(int i, int\
    \ j, Cap a, Cap b, Cap c, Cap d) {\n        assert(i < j);\n        R += a;\n\
    \        add_one_variable_function(i, 0, c-a);\n        add_one_variable_function(j,\
    \ 0, d-c);\n        gh.add_edge(i, j, b+c-a-d);\n    }\n\n    Cap min() {\n  \
    \      return gh.flow(s, t) + R;\n    }\nprivate:\n    atcoder::mf_graph<Cap>\
    \ gh;\n    int s,t;\n    Cap R = 0;\n};\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/submodular.hpp
  requiredBy: []
  timestamp: '2021-10-31 15:43:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/submodular.hpp
layout: document
redirect_from:
- /library/graph/submodular.hpp
- /library/graph/submodular.hpp.html
title: graph/submodular.hpp
---
