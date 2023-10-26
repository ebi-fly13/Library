---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dual_segtree_commutative.hpp
    title: dual segtree (commutative)
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
  bundledCode: "#line 1 \"test/data_structure/Range_Add_Query.test.cpp\"\n#define\
    \ PROBLEM \\\r\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"data_structure/dual_segtree_commutative.hpp\"\
    \n\r\n#include <cassert>\r\n#line 5 \"data_structure/dual_segtree_commutative.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class Monoid, Monoid (*op)(Monoid, Monoid),\
    \ Monoid (*e)()>\r\nstruct DualSegtree {\r\n  public:\r\n    DualSegtree(int n)\
    \ : n(n) {\r\n        size = 1;\r\n        while (size < n) size <<= 1;\r\n  \
    \      data.assign(2 * size, e());\r\n    }\r\n\r\n    DualSegtree(const std::vector<Monoid>\
    \ &vec) : n(vec.size()) {\r\n        size = 1;\r\n        while (size < n) size\
    \ <<= 1;\r\n        data.assign(2 * size, e());\r\n        std::copy(vec.begin(),\
    \ vec.end(), data.begin() + size);\r\n    }\r\n\r\n    Monoid get(int idx) const\
    \ {\r\n        assert(0 <= idx && idx < n);\r\n        idx += size;\r\n      \
    \  Monoid val = e();\r\n        while (idx > 0) {\r\n            val = op(val,\
    \ data[idx]);\r\n            idx >>= 1;\r\n        }\r\n        return val;\r\n\
    \    }\r\n\r\n    void apply(int l, int r, Monoid x) {\r\n        assert(0 <=\
    \ l && l <= r && r <= n);\r\n        l += size;\r\n        r += size;\r\n    \
    \    while (l < r) {\r\n            if (l & 1) {\r\n                data[l] =\
    \ op(data[l], x);\r\n                l++;\r\n            }\r\n            if (r\
    \ & 1) {\r\n                r--;\r\n                data[r] = op(data[r], x);\r\
    \n            }\r\n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\
    \n        return;\r\n    }\r\n\r\n  private:\r\n    std::vector<Monoid> data;\r\
    \n    int n;\r\n    int size;\r\n};\r\n\r\n}  // namespace ebi\n#line 8 \"test/data_structure/Range_Add_Query.test.cpp\"\
    \n\r\nint op(int a, int b) {\r\n    return a + b;\r\n}\r\n\r\nint e() {\r\n  \
    \  return 0;\r\n}\r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >>\
    \ q;\r\n    ebi::DualSegtree<int, op, e> dseg(n);\r\n    while (q--) {\r\n   \
    \     int flag;\r\n        std::cin >> flag;\r\n        if (flag == 0) {\r\n \
    \           int s, t, x;\r\n            std::cin >> s >> t >> x;\r\n         \
    \   s--;\r\n            dseg.apply(s, t, x);\r\n        } else {\r\n         \
    \   int t;\r\n            std::cin >> t;\r\n            t--;\r\n            std::cout\
    \ << dseg.get(t) << std::endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \\\r\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../data_structure/dual_segtree_commutative.hpp\"\
    \r\n\r\nint op(int a, int b) {\r\n    return a + b;\r\n}\r\n\r\nint e() {\r\n\
    \    return 0;\r\n}\r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n\
    \ >> q;\r\n    ebi::DualSegtree<int, op, e> dseg(n);\r\n    while (q--) {\r\n\
    \        int flag;\r\n        std::cin >> flag;\r\n        if (flag == 0) {\r\n\
    \            int s, t, x;\r\n            std::cin >> s >> t >> x;\r\n        \
    \    s--;\r\n            dseg.apply(s, t, x);\r\n        } else {\r\n        \
    \    int t;\r\n            std::cin >> t;\r\n            t--;\r\n            std::cout\
    \ << dseg.get(t) << std::endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/dual_segtree_commutative.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Add_Query.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 13:46:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Range_Add_Query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Add_Query.test.cpp
- /verify/test/data_structure/Range_Add_Query.test.cpp.html
title: test/data_structure/Range_Add_Query.test.cpp
---
