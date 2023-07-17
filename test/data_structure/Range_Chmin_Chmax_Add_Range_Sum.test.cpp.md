---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/SegmentTreeBeats.hpp
    title: data_structure/SegmentTreeBeats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp\"\
    \n#define PROBLEM \\\r\n    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <cstdint>\r\n\r\n\
    #line 2 \"data_structure/SegmentTreeBeats.hpp\"\n\r\n#include <algorithm>\r\n\
    #include <limits>\r\n#line 6 \"data_structure/SegmentTreeBeats.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class S> struct SegmentTreeBeats {\r\n  private:\r\n\
    \    S INF = std::numeric_limits<S>::max() / 4;\r\n    std::vector<S> max_v, smax_v,\
    \ max_c;\r\n    std::vector<S> min_v, smin_v, min_c;\r\n    std::vector<S> data;\r\
    \n    std::vector<S> lazy;\r\n    int n;\r\n\r\n    void update(int k) {\r\n \
    \       data[k] = data[2 * k + 1] + data[2 * k + 2];\r\n\r\n        if (max_v[2\
    \ * k + 1] != max_v[2 * k + 2]) {\r\n            int p = 2 * k + 1, q = 2 * k\
    \ + 2;\r\n            if (max_v[p] < max_v[q]) std::swap(p, q);\r\n          \
    \  max_v[k] = max_v[p];\r\n            max_c[k] = max_c[p];\r\n            smax_v[k]\
    \ = std::max(smax_v[p], max_v[q]);\r\n        } else {\r\n            max_v[k]\
    \ = max_v[2 * k + 1];\r\n            max_c[k] = max_c[2 * k + 1] + max_c[2 * k\
    \ + 2];\r\n            smax_v[k] = std::max(smax_v[2 * k + 1], smax_v[2 * k +\
    \ 2]);\r\n        }\r\n\r\n        if (min_v[2 * k + 1] != min_v[2 * k + 2]) {\r\
    \n            int p = 2 * k + 1, q = 2 * k + 2;\r\n            if (min_v[p] >\
    \ min_v[q]) std::swap(p, q);\r\n            min_v[k] = min_v[p];\r\n         \
    \   min_c[k] = min_c[p];\r\n            smin_v[k] = std::min(smin_v[p], min_v[q]);\r\
    \n        } else {\r\n            min_v[k] = min_v[2 * k + 1];\r\n           \
    \ min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];\r\n            smin_v[k] = std::min(smin_v[2\
    \ * k + 1], smin_v[2 * k + 2]);\r\n        }\r\n    }\r\n\r\n    void update_node_max(int\
    \ k, S x) {\r\n        data[k] += (x - max_v[k]) * max_c[k];\r\n        if (max_v[k]\
    \ == min_v[k]) {\r\n            max_v[k] = min_v[k] = x;\r\n        } else if\
    \ (max_v[k] == smin_v[k]) {\r\n            max_v[k] = smin_v[k] = x;\r\n     \
    \   } else {\r\n            max_v[k] = x;\r\n        }\r\n    }\r\n\r\n    void\
    \ update_node_min(int k, S x) {\r\n        data[k] += (x - min_v[k]) * min_c[k];\r\
    \n        if (min_v[k] == max_v[k]) {\r\n            min_v[k] = max_v[k] = x;\r\
    \n        } else if (min_v[k] == smax_v[k]) {\r\n            min_v[k] = smax_v[k]\
    \ = x;\r\n        } else {\r\n            min_v[k] = x;\r\n        }\r\n    }\r\
    \n\r\n    void pushdown(int k, int l, int r) {\r\n        if (r - l <= 1) return;\r\
    \n        if (lazy[k] != 0) {\r\n            add_all(2 * k + 1, lazy[k], l, (l\
    \ + r) / 2);\r\n            add_all(2 * k + 2, lazy[k], (l + r) / 2, r);\r\n \
    \           lazy[k] = 0;\r\n        }\r\n        if (max_v[k] < max_v[2 * k +\
    \ 1]) {\r\n            update_node_max(2 * k + 1, max_v[k]);\r\n        }\r\n\
    \        if (min_v[k] > min_v[2 * k + 1]) {\r\n            update_node_min(2 *\
    \ k + 1, min_v[k]);\r\n        }\r\n        if (max_v[k] < max_v[2 * k + 2]) {\r\
    \n            update_node_max(2 * k + 2, max_v[k]);\r\n        }\r\n        if\
    \ (min_v[k] > min_v[2 * k + 2]) {\r\n            update_node_min(2 * k + 2, min_v[k]);\r\
    \n        }\r\n    }\r\n\r\n    void add_all(int k, S x, int l, int r) {\r\n \
    \       data[k] += x * (r - l);\r\n        max_v[k] += x;\r\n        if (smax_v[k]\
    \ != -INF) smax_v[k] += x;\r\n        min_v[k] += x;\r\n        if (smin_v[k]\
    \ != INF) smin_v[k] += x;\r\n        lazy[k] += x;\r\n    }\r\n\r\n  public:\r\
    \n    SegmentTreeBeats(std::vector<S> v) : n(1) {\r\n        int _n = v.size();\r\
    \n        while (n < _n) {\r\n            n <<= 1;\r\n        }\r\n        data.assign(2\
    \ * n - 1, 0);\r\n        lazy.assign(2 * n - 1, 0);\r\n        max_v = smax_v\
    \ = max_c = min_v = smin_v = min_c =\r\n            std::vector<S>(2 * n - 1);\r\
    \n        for (int i = 0; i < n; i++) {\r\n            int k = i + n - 1;\r\n\
    \            if (i < _n) data[k] = v[i];\r\n            max_v[k] = data[k];\r\n\
    \            smax_v[k] = -INF;\r\n            max_c[k] = 1;\r\n            min_v[k]\
    \ = data[k];\r\n            smin_v[k] = INF;\r\n            min_c[k] = 1;\r\n\
    \        }\r\n        for (int i = n - 2; i >= 0; i--) {\r\n            update(i);\r\
    \n        }\r\n    }\r\n\r\n    void apply_chmin(int l, int r, S x, int nl = 0,\
    \ int nr = -1,\r\n                     int index = 0) {\r\n        if (nr < 0)\
    \ nr = n;\r\n        if (nr <= l || r <= nl || max_v[index] <= x) {\r\n      \
    \      return;\r\n        }\r\n        if (l <= nl && nr <= r && smax_v[index]\
    \ < x) {\r\n            update_node_max(index, x);\r\n            return;\r\n\
    \        }\r\n        pushdown(index, nl, nr);\r\n        apply_chmin(l, r, x,\
    \ nl, (nl + nr) / 2, 2 * index + 1);\r\n        apply_chmin(l, r, x, (nl + nr)\
    \ / 2, nr, 2 * index + 2);\r\n        update(index);\r\n        return;\r\n  \
    \  }\r\n\r\n    void apply_chmax(int l, int r, S x, int nl = 0, int nr = -1,\r\
    \n                     int index = 0) {\r\n        if (nr < 0) nr = n;\r\n   \
    \     if (nr <= l || r <= nl || min_v[index] >= x) {\r\n            return;\r\n\
    \        }\r\n        if (l <= nl && nr <= r && smin_v[index] > x) {\r\n     \
    \       update_node_min(index, x);\r\n            return;\r\n        }\r\n   \
    \     pushdown(index, nl, nr);\r\n        apply_chmax(l, r, x, nl, (nl + nr) /\
    \ 2, 2 * index + 1);\r\n        apply_chmax(l, r, x, (nl + nr) / 2, nr, 2 * index\
    \ + 2);\r\n        update(index);\r\n        return;\r\n    }\r\n\r\n    void\
    \ apply(int l, int r, S x, int nl = 0, int nr = -1, int index = 0) {\r\n     \
    \   if (nr < 0) nr = n;\r\n        if (nr <= l || r <= nl) {\r\n            return;\r\
    \n        }\r\n        if (l <= nl && nr <= r) {\r\n            add_all(index,\
    \ x, nl, nr);\r\n            return;\r\n        }\r\n        pushdown(index, nl,\
    \ nr);\r\n        apply(l, r, x, nl, (nl + nr) / 2, 2 * index + 1);\r\n      \
    \  apply(l, r, x, (nl + nr) / 2, nr, 2 * index + 2);\r\n        update(index);\r\
    \n        return;\r\n    }\r\n\r\n    S prod(int l, int r, int nl = 0, int nr\
    \ = -1, int index = 0) {\r\n        if (nr < 0) nr = n;\r\n        if (nr <= l\
    \ || r <= nl) {\r\n            return 0;\r\n        }\r\n        if (l <= nl &&\
    \ nr <= r) {\r\n            return data[index];\r\n        }\r\n        pushdown(index,\
    \ nl, nr);\r\n        return prod(l, r, nl, (nl + nr) / 2, 2 * index + 1) +\r\n\
    \               prod(l, r, (nl + nr) / 2, nr, 2 * index + 2);\r\n    }\r\n};\r\
    \n\r\n}  // namespace ebi\r\n#line 9 \"test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp\"\
    \n\r\nusing i64 = std::int64_t;\r\nusing S = i64;\r\n\r\nint main() {\r\n    int\
    \ n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n        std::cin >> a[i];\r\n    }\r\n    ebi::SegmentTreeBeats<S>\
    \ seg(a);\r\n    while (q--) {\r\n        int t;\r\n        std::cin >> t;\r\n\
    \        if (t == 0) {\r\n            int l, r;\r\n            i64 b;\r\n    \
    \        std::cin >> l >> r >> b;\r\n            seg.apply_chmin(l, r, b);\r\n\
    \        } else if (t == 1) {\r\n            int l, r;\r\n            i64 b;\r\
    \n            std::cin >> l >> r >> b;\r\n            seg.apply_chmax(l, r, b);\r\
    \n        } else if (t == 2) {\r\n            int l, r;\r\n            i64 b;\r\
    \n            std::cin >> l >> r >> b;\r\n            seg.apply(l, r, b);\r\n\
    \        } else {\r\n            int l, r;\r\n            std::cin >> l >> r;\r\
    \n            std::cout << seg.prod(l, r) << std::endl;\r\n        }\r\n    }\r\
    \n}\n"
  code: "#define PROBLEM \\\r\n    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <cstdint>\r\n\r\n\
    #include \"../../data_structure/SegmentTreeBeats.hpp\"\r\n\r\nusing i64 = std::int64_t;\r\
    \nusing S = i64;\r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >>\
    \ q;\r\n    std::vector<i64> a(n);\r\n    for (int i = 0; i < n; i++) {\r\n  \
    \      std::cin >> a[i];\r\n    }\r\n    ebi::SegmentTreeBeats<S> seg(a);\r\n\
    \    while (q--) {\r\n        int t;\r\n        std::cin >> t;\r\n        if (t\
    \ == 0) {\r\n            int l, r;\r\n            i64 b;\r\n            std::cin\
    \ >> l >> r >> b;\r\n            seg.apply_chmin(l, r, b);\r\n        } else if\
    \ (t == 1) {\r\n            int l, r;\r\n            i64 b;\r\n            std::cin\
    \ >> l >> r >> b;\r\n            seg.apply_chmax(l, r, b);\r\n        } else if\
    \ (t == 2) {\r\n            int l, r;\r\n            i64 b;\r\n            std::cin\
    \ >> l >> r >> b;\r\n            seg.apply(l, r, b);\r\n        } else {\r\n \
    \           int l, r;\r\n            std::cin >> l >> r;\r\n            std::cout\
    \ << seg.prod(l, r) << std::endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/SegmentTreeBeats.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-07-17 14:52:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp
- /verify/test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp.html
title: test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp
---
