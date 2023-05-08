---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/static_range_inversion_query.test.cpp
    title: test/static_range_inversion_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/mo_algorithm.hpp\"\n\r\n#include <vector>\r\n\
    #include <algorithm>\r\n#include <cmath>\r\n#include <numeric>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<class IL, class IR, class DL, class DR, class O>\r\nvoid\
    \ mo_algorithm(const int &n, const std::vector<int> &l, const std::vector<int>\
    \ &r, const IL &insert_left, const IR &insert_right, const DL &delete_left, const\
    \ DR &delete_right, const O &out) {\r\n    const int q = l.size();\r\n    const\
    \ int block =  n/std::max<int>(1, std::sqrt(n));\r\n    std::vector<int> order(q,\
    \ 0);\r\n    iota(order.begin(), order.end(), 0);\r\n    std::sort(order.begin(),\
    \ order.end(), [&](int i, int j) {\r\n        int bi = l[i]/block;\r\n       \
    \ int bj = l[j]/block;\r\n        return bi != bj ? bi < bj : bi & 1 ? r[i] >\
    \ r[j] : r[i] < r[j];\r\n    });\r\n    int nl = 0, nr = 0;\r\n    for(auto i:\
    \ order) {\r\n        while(l[i] < nl) insert_left(--nl);\r\n        while(nr\
    \ < r[i]) insert_right(nr++);\r\n        while(nl < l[i]) delete_left(nl++);\r\
    \n        while(r[i] < nr) delete_right(--nr);\r\n        out(i);\r\n    }\r\n\
    \    return;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <algorithm>\r\n#include\
    \ <cmath>\r\n#include <numeric>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class IL,\
    \ class IR, class DL, class DR, class O>\r\nvoid mo_algorithm(const int &n, const\
    \ std::vector<int> &l, const std::vector<int> &r, const IL &insert_left, const\
    \ IR &insert_right, const DL &delete_left, const DR &delete_right, const O &out)\
    \ {\r\n    const int q = l.size();\r\n    const int block =  n/std::max<int>(1,\
    \ std::sqrt(n));\r\n    std::vector<int> order(q, 0);\r\n    iota(order.begin(),\
    \ order.end(), 0);\r\n    std::sort(order.begin(), order.end(), [&](int i, int\
    \ j) {\r\n        int bi = l[i]/block;\r\n        int bj = l[j]/block;\r\n   \
    \     return bi != bj ? bi < bj : bi & 1 ? r[i] > r[j] : r[i] < r[j];\r\n    });\r\
    \n    int nl = 0, nr = 0;\r\n    for(auto i: order) {\r\n        while(l[i] <\
    \ nl) insert_left(--nl);\r\n        while(nr < r[i]) insert_right(nr++);\r\n \
    \       while(nl < l[i]) delete_left(nl++);\r\n        while(r[i] < nr) delete_right(--nr);\r\
    \n        out(i);\r\n    }\r\n    return;\r\n}\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/mo_algorithm.hpp
  requiredBy: []
  timestamp: '2023-05-08 14:32:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static_range_inversion_query.test.cpp
documentation_of: algorithm/mo_algorithm.hpp
layout: document
redirect_from:
- /library/algorithm/mo_algorithm.hpp
- /library/algorithm/mo_algorithm.hpp.html
title: algorithm/mo_algorithm.hpp
---
