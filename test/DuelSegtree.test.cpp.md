---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/DuelSegtree.hpp
    title: data_structure/DuelSegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"test/DuelSegtree.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \r\n\r\n#line 2 \"data_structure/DuelSegtree.hpp\"\n\r\n#include <vector>\r\n\r\
    \nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid),\
    \ Monoid (*e)()>\r\nstruct DuelSegtree {\r\nprivate:\r\n    std::vector<Monoid>\
    \ data;\r\n    int n;\r\npublic:\r\n    DuelSegtree(int _n) : n(1) {\r\n     \
    \   while(n<_n){\r\n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1,\
    \ e());\r\n    }\r\n\r\n    DuelSegtree(std::vector<Monoid> v) : n(1) {\r\n  \
    \      int _n = v.size();\r\n        while(n<_n){\r\n            n <<= 1;\r\n\
    \        }\r\n        data.assign(2*n-1, e());\r\n        for(int i = 0; i<_n;\
    \ i++){\r\n            data[i+n-1] = v[i];\r\n        }\r\n    }\r\n\r\n    Monoid\
    \ get(int p) {\r\n        int k = p+n-1;\r\n        Monoid val = data[k];\r\n\
    \        while(k>0){\r\n            k = (k-1)/2;\r\n            val = op(val,\
    \ data[k]);\r\n        }\r\n        return val;\r\n    }\r\n\r\n    void apply(int\
    \ tl, int tr, Monoid x,int l = 0, int r = -1, int index = 0) {\r\n        if(r<0)\
    \ r = n;\r\n        if(tr<=l || r<=tl) {\r\n            return;\r\n        }\r\
    \n        if(tl<=l && r<=tr) {\r\n            data[index] = op(data[index], x);\r\
    \n            return;\r\n        }\r\n        apply(tl, tr, x, l, (l+r)/2, 2*index+1);\r\
    \n        apply(tl, tr, x,(l+r)/2, r, 2*index+2);\r\n        return;\r\n    }\r\
    \n};\r\n\r\n} // namespace ebi\n#line 4 \"test/DuelSegtree.test.cpp\"\n\r\n#include\
    \ <iostream>\r\n#line 7 \"test/DuelSegtree.test.cpp\"\n\r\nint op(int a, int b)\
    \ {\r\n    return a+b;\r\n}\r\n\r\nint e(){\r\n    return 0;\r\n}\r\n\r\nint main()\
    \ {\r\n    int n,q; std::cin >> n >> q;\r\n    ebi::DuelSegtree<int, op, e> dseg(n);\r\
    \n    while(q--){\r\n        int flag;\r\n        std::cin >> flag;\r\n      \
    \  if(flag==0){\r\n            int s,t,x; std::cin >> s >> t >> x;\r\n       \
    \     s--;\r\n            dseg.apply(s,t,x);\r\n        }\r\n        else{\r\n\
    \            int t; std::cin >> t;\r\n            t--;\r\n            std::cout\
    \ << dseg.get(t) << std::endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \r\n\r\n#include \"../data_structure/DuelSegtree.hpp\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n\r\nint op(int a, int b) {\r\n    return a+b;\r\n}\r\n\r\
    \nint e(){\r\n    return 0;\r\n}\r\n\r\nint main() {\r\n    int n,q; std::cin\
    \ >> n >> q;\r\n    ebi::DuelSegtree<int, op, e> dseg(n);\r\n    while(q--){\r\
    \n        int flag;\r\n        std::cin >> flag;\r\n        if(flag==0){\r\n \
    \           int s,t,x; std::cin >> s >> t >> x;\r\n            s--;\r\n      \
    \      dseg.apply(s,t,x);\r\n        }\r\n        else{\r\n            int t;\
    \ std::cin >> t;\r\n            t--;\r\n            std::cout << dseg.get(t) <<\
    \ std::endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/DuelSegtree.hpp
  isVerificationFile: true
  path: test/DuelSegtree.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DuelSegtree.test.cpp
layout: document
redirect_from:
- /verify/test/DuelSegtree.test.cpp
- /verify/test/DuelSegtree.test.cpp.html
title: test/DuelSegtree.test.cpp
---
