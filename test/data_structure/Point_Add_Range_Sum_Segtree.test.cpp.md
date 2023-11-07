---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/data_structure/Point_Add_Range_Sum_Segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\n\r\
    \n#include <cstdint>\r\n#include <iostream>\r\n\r\n#line 2 \"data_structure/segtree.hpp\"\
    \n\r\n#include <cassert>\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()> struct segtree {\r\n  private:\r\n    int\
    \ n;\r\n    int sz;\r\n    std::vector<S> data;\r\n\r\n    void update(int i)\
    \ {\r\n        data[i] = op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n  public:\r\
    \n    segtree(int n_) : segtree(std::vector<S>(n_, e())) {}\r\n    segtree(const\
    \ std::vector<S> &v) : n((int)v.size()), sz(1) {\r\n        while (sz < n) sz\
    \ *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\n        for (int i =\
    \ 0; i < n; i++) {\r\n            data[sz + i] = v[i];\r\n        }\r\n      \
    \  for (int i = sz - 1; i >= 1; i--) update(i);\r\n    }\r\n\r\n    void set(int\
    \ p, S x) {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\n      \
    \  data[p] = x;\r\n        while (p > 1) {\r\n            p >>= 1;\r\n       \
    \     update(p);\r\n        }\r\n    }\r\n\r\n    S get(int p) const {\r\n   \
    \     assert(0 <= p && p < n);\r\n        return data[p + sz];\r\n    }\r\n\r\n\
    \    S prod(int l, int r) const {\r\n        assert(0 <= l && l <= r && r <= n);\r\
    \n        S sml = e(), smr = e();\r\n        l += sz;\r\n        r += sz;\r\n\
    \        while (l < r) {\r\n            if (l & 1) sml = op(sml, data[l++]);\r\
    \n            if (r & 1) smr = op(data[--r], smr);\r\n            l >>= 1;\r\n\
    \            r >>= 1;\r\n        }\r\n        return op(sml, smr);\r\n    }\r\n\
    \r\n    S all_prod() const {\r\n        return data[1];\r\n    }\r\n\r\n    template\
    \ <class F> int max_right(int l, F f) const {\r\n        assert(0 <= l && l <\
    \ n);\r\n        assert(f(e()));\r\n        if (l == n) return n;\r\n        l\
    \ += sz;\r\n        S sm = e();\r\n        do {\r\n            while (l % 2 ==\
    \ 0) l >>= 1;\r\n            if (!f(op(sm, data[l]))) {\r\n                while\
    \ (l < sz) {\r\n                    l = 2 * l;\r\n                    if (f(op(sm,\
    \ data[l]))) {\r\n                        sm = op(sm, data[l]);\r\n          \
    \              l++;\r\n                    }\r\n                }\r\n        \
    \        return l - sz;\r\n            }\r\n            sm = op(sm, data[l]);\r\
    \n            l++;\r\n        } while ((l & -l) != l);\r\n        return n;\r\n\
    \    }\r\n\r\n    template <class F> int min_left(int r, F f) const {\r\n    \
    \    assert(0 <= r && r <= n);\r\n        assert(f(e()));\r\n        if (r ==\
    \ 0) return 0;\r\n        r += sz;\r\n        S sm = e();\r\n        do {\r\n\
    \            r--;\r\n            while (r > 1 && (r % 2)) r >>= 1;\r\n       \
    \     if (!f(op(data[r], sm))) {\r\n                while (r < sz) {\r\n     \
    \               r = 2 * r + 1;\r\n                    if (f(op(data[r], sm)))\
    \ {\r\n                        sm = op(data[r], sm);\r\n                     \
    \   r--;\r\n                    }\r\n                }\r\n                return\
    \ r + 1 - sz;\r\n            }\r\n            sm = op(data[r], sm);\r\n      \
    \  } while ((r & -r) != r);\r\n        return 0;\r\n    }\r\n\r\n    S operator[](int\
    \ p) const {\r\n        return data[sz + p];\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\r\n#line 7 \"test/data_structure/Point_Add_Range_Sum_Segtree.test.cpp\"\n\
    \r\nusing i64 = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b) {\r\n    return a +\
    \ b;\r\n}\r\ni64 e() {\r\n    return (i64)0;\r\n}\r\n\r\nint main() {\r\n    int\
    \ n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n        std::cin >> a[i];\r\n    }\r\n    ebi::segtree<i64,\
    \ op, e> seg(a);\r\n    while (q--) {\r\n        int t;\r\n        std::cin >>\
    \ t;\r\n        if (t == 0) {\r\n            int p;\r\n            i64 x;\r\n\
    \            std::cin >> p >> x;\r\n            seg.set(p, seg[p] + x);\r\n  \
    \      } else {\r\n            int l, r;\r\n            std::cin >> l >> r;\r\n\
    \            std::cout << seg.prod(l, r) << std::endl;\r\n        }\r\n    }\r\
    \n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include <cstdint>\r\n#include <iostream>\r\n\r\n#include \"../../data_structure/segtree.hpp\"\
    \r\n\r\nusing i64 = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b) {\r\n    return\
    \ a + b;\r\n}\r\ni64 e() {\r\n    return (i64)0;\r\n}\r\n\r\nint main() {\r\n\
    \    int n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\n  \
    \  for (int i = 0; i < n; i++) {\r\n        std::cin >> a[i];\r\n    }\r\n   \
    \ ebi::segtree<i64, op, e> seg(a);\r\n    while (q--) {\r\n        int t;\r\n\
    \        std::cin >> t;\r\n        if (t == 0) {\r\n            int p;\r\n   \
    \         i64 x;\r\n            std::cin >> p >> x;\r\n            seg.set(p,\
    \ seg[p] + x);\r\n        } else {\r\n            int l, r;\r\n            std::cin\
    \ >> l >> r;\r\n            std::cout << seg.prod(l, r) << std::endl;\r\n    \
    \    }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: test/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  requiredBy: []
  timestamp: '2023-10-31 01:04:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
- /verify/test/data_structure/Point_Add_Range_Sum_Segtree.test.cpp.html
title: test/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
---
