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
    \ Cap>\nstruct submodular {\npublic:\n    submodular(int n, int add_vertex = 0)\
    \ : gh(n + add_vertex +2), s(n), t(n+1), max(n+add_vertex+2),u(n+2)  { }\n\n \
    \   void add_one_variable_function(int i, Cap f0, Cap f1) {\n        if(f0 <=\
    \ f1) {\n            gh.add_edge(s, i, f1-f0);\n            R += f0;\n       \
    \ }\n        else {\n            gh.add_edge(i, t, f0-f1);\n            R += f1;\n\
    \        }\n    }\n\n    void add_two_variable_function(int i, int j, Cap a, Cap\
    \ b, Cap c, Cap d) {\n        assert(i < j);\n        R += a;\n        add_one_variable_function(i,\
    \ 0, c-a);\n        add_one_variable_function(j, 0, d-c);\n        gh.add_edge(i,\
    \ j, b+c-a-d);\n    }\n\n    void add_three_variable_function(int i, int j, int\
    \ k, Cap a, Cap b, Cap c, Cap d, Cap e, Cap f, Cap g, Cap h) {\n        assert(u\
    \ < max);\n        Cap p = (a + d + f + g) - (b + c + e + h);\n        if(p >=\
    \ 0) {\n            Cap p1 = f-b, p2 = g-e, p3 = d-c;\n            Cap p23 = (b+c)-(a+d),\
    \ p31 = (b+e)-(a+f), p12 = (c+e)-(a+g);\n            R += a;\n            add_one_variable_function(i,\
    \ 0, p1);\n            add_one_variable_function(j, 0, p2);\n            add_one_variable_function(k,\
    \ 0, p3);\n            add_two_variable_function(j, k, 0, p23, 0, 0);\n      \
    \      add_two_variable_function(i, k, 0, 0, p31, 0);\n            add_two_variable_function(i,\
    \ j, 0, p12, 0, 0);\n            gh.add_edge(i, u, p);\n            gh.add_edge(j,\
    \ u, p);\n            gh.add_edge(k, u, p);\n            gh.add_edge(u++, t, p);\n\
    \            R -= p;\n        }\n        else {\n            Cap p1 = c-g, p2\
    \ = b-d, p3 = e-f;\n            Cap p32 = (f+g)-(e+h), p13 = (d+g)-(c+h), p21\
    \ = (d+f)-(b+h);\n            R += h;\n            add_one_variable_function(i,\
    \ p1, 0);\n            add_one_variable_function(j, p2, 0);\n            add_one_variable_function(k,\
    \ p3, 0);\n            add_two_variable_function(j, k, 0, 0, p32, 0);\n      \
    \      add_two_variable_function(i, k, 0, p13, 0, 0);\n            add_two_variable_function(i,\
    \ j, 0, 0, p21, 0);\n            gh.add_edge(s, u, -p);\n            gh.add_edge(u,\
    \ i, -p);\n            gh.add_edge(u, j, -p);\n            gh.add_edge(u, k, -p);\n\
    \            u++;\n            R += p;\n        }\n    }\n\n    Cap min() {\n\
    \        return gh.flow(s, t) + R;\n    }\nprivate:\n    atcoder::mf_graph<Cap>\
    \ gh;\n    int s,t;\n    int max;\n    int u;\n    Cap R = 0;\n};\n\n}\n"
  code: "#pragma once\n\n/*\n    reference: https://theory-and-me.hatenablog.com/entry/2020/03/17/180157\n\
    \    depends on mf_graph in atcoder library(acl).\n*/\n\nnamespace ebi {\n\ntemplate<class\
    \ Cap>\nstruct submodular {\npublic:\n    submodular(int n, int add_vertex = 0)\
    \ : gh(n + add_vertex +2), s(n), t(n+1), max(n+add_vertex+2),u(n+2)  { }\n\n \
    \   void add_one_variable_function(int i, Cap f0, Cap f1) {\n        if(f0 <=\
    \ f1) {\n            gh.add_edge(s, i, f1-f0);\n            R += f0;\n       \
    \ }\n        else {\n            gh.add_edge(i, t, f0-f1);\n            R += f1;\n\
    \        }\n    }\n\n    void add_two_variable_function(int i, int j, Cap a, Cap\
    \ b, Cap c, Cap d) {\n        assert(i < j);\n        R += a;\n        add_one_variable_function(i,\
    \ 0, c-a);\n        add_one_variable_function(j, 0, d-c);\n        gh.add_edge(i,\
    \ j, b+c-a-d);\n    }\n\n    void add_three_variable_function(int i, int j, int\
    \ k, Cap a, Cap b, Cap c, Cap d, Cap e, Cap f, Cap g, Cap h) {\n        assert(u\
    \ < max);\n        Cap p = (a + d + f + g) - (b + c + e + h);\n        if(p >=\
    \ 0) {\n            Cap p1 = f-b, p2 = g-e, p3 = d-c;\n            Cap p23 = (b+c)-(a+d),\
    \ p31 = (b+e)-(a+f), p12 = (c+e)-(a+g);\n            R += a;\n            add_one_variable_function(i,\
    \ 0, p1);\n            add_one_variable_function(j, 0, p2);\n            add_one_variable_function(k,\
    \ 0, p3);\n            add_two_variable_function(j, k, 0, p23, 0, 0);\n      \
    \      add_two_variable_function(i, k, 0, 0, p31, 0);\n            add_two_variable_function(i,\
    \ j, 0, p12, 0, 0);\n            gh.add_edge(i, u, p);\n            gh.add_edge(j,\
    \ u, p);\n            gh.add_edge(k, u, p);\n            gh.add_edge(u++, t, p);\n\
    \            R -= p;\n        }\n        else {\n            Cap p1 = c-g, p2\
    \ = b-d, p3 = e-f;\n            Cap p32 = (f+g)-(e+h), p13 = (d+g)-(c+h), p21\
    \ = (d+f)-(b+h);\n            R += h;\n            add_one_variable_function(i,\
    \ p1, 0);\n            add_one_variable_function(j, p2, 0);\n            add_one_variable_function(k,\
    \ p3, 0);\n            add_two_variable_function(j, k, 0, 0, p32, 0);\n      \
    \      add_two_variable_function(i, k, 0, p13, 0, 0);\n            add_two_variable_function(i,\
    \ j, 0, 0, p21, 0);\n            gh.add_edge(s, u, -p);\n            gh.add_edge(u,\
    \ i, -p);\n            gh.add_edge(u, j, -p);\n            gh.add_edge(u, k, -p);\n\
    \            u++;\n            R += p;\n        }\n    }\n\n    Cap min() {\n\
    \        return gh.flow(s, t) + R;\n    }\nprivate:\n    atcoder::mf_graph<Cap>\
    \ gh;\n    int s,t;\n    int max;\n    int u;\n    Cap R = 0;\n};\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/submodular.hpp
  requiredBy: []
  timestamp: '2021-10-31 17:00:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/submodular.hpp
layout: document
redirect_from:
- /library/graph/submodular.hpp
- /library/graph/submodular.hpp.html
title: graph/submodular.hpp
---
