---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/li_chao_tree.hpp
    title: Li Chao Tree
  - icon: ':question:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/data_structure/Segment_Add_Get_Min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n#include\
    \ <iostream>\n#include <utility>\n#include <vector>\n\n#line 2 \"data_structure/li_chao_tree.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#line 8 \"data_structure/li_chao_tree.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct li_chao_tree {\n  private:\n\
    \    T f(std::pair<T, T> y, T x) const {\n        return y.first * x + y.second;\n\
    \    }\n\n    void add(std::pair<T, T> y, int l, int r, int index) {\n       \
    \ while (l < r) {\n            bool left = f(y, xs[l]) < f(data[index], xs[l]);\n\
    \            bool mid = f(y, xs[(l + r) / 2]) < f(data[index], xs[(l + r) / 2]);\n\
    \            bool right = f(y, xs[r - 1]) < f(data[index], xs[r - 1]);\n     \
    \       if (left && right) {\n                data[index] = y;\n             \
    \   return;\n            }\n            if (!(left || right)) {\n            \
    \    return;\n            }\n            if (mid) {\n                std::swap(y,\
    \ data[index]);\n                left = !left;\n                right = !right;\n\
    \            }\n            if (left) {\n                r = (l + r) / 2;\n  \
    \              index *= 2;\n            } else {\n                l = (l + r)\
    \ / 2;\n                index = 2 * index + 1;\n            }\n        }\n   \
    \ }\n\n    int get_index(T x) const {\n        auto itr = std::lower_bound(xs.begin(),\
    \ xs.end(), x);\n        return itr - xs.begin();\n    }\n\n  public:\n    li_chao_tree(std::vector<T>\
    \ &_x) : xs(_x), sz(1) {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        while (sz < int(xs.size())) sz <<= 1;\n     \
    \   while (int(xs.size()) < sz) xs.emplace_back(xs.back() + 1);\n        data.assign(2\
    \ * sz, {0, std::numeric_limits<T>::max()});\n    }\n\n    void add_line(T a,\
    \ T b) {\n        add({a, b}, 0, sz, 1);\n    }\n\n    void add_segment(T a, T\
    \ b, T lx, T rx) {\n        int l = get_index(lx);\n        int r = get_index(rx);\n\
    \        assert(0 <= l && l <= r && r <= sz);\n        int il = l + sz;\n    \
    \    int ir = r + sz;\n        int rank = 0;\n        while (il < ir) {\n    \
    \        if (il & 1) {\n                add({a, b}, l, l + (1 << rank), il++);\n\
    \                l += (1 << rank);\n            }\n            if (ir & 1) {\n\
    \                add({a, b}, r - (1 << rank), r, --ir);\n                r -=\
    \ (1 << rank);\n            }\n            rank++;\n            il >>= 1;\n  \
    \          ir >>= 1;\n        }\n    }\n\n    T min(T x) {\n        int k = get_index(x)\
    \ + sz;\n        T val = std::numeric_limits<T>::max();\n        while (k > 0)\
    \ {\n            val = std::min(val, f(data[k], x));\n            k >>= 1;\n \
    \       }\n        return val;\n    }\n\n  private:\n    std::vector<std::pair<T,\
    \ T>> data;\n    std::vector<T> xs;\n    int sz;\n};\n\n}  // namespace ebi\n\
    #line 2 \"utility/int_alias.hpp\"\n\r\n#include <cstddef>\r\n#include <cstdint>\r\
    \n\r\nusing std::size_t;\r\nusing i8 = std::int8_t;\r\nusing u8 = std::uint8_t;\r\
    \nusing i16 = std::int16_t;\r\nusing u16 = std::uint16_t;\r\nusing i32 = std::int32_t;\r\
    \nusing u32 = std::uint32_t;\r\nusing i64 = std::int64_t;\r\nusing u64 = std::uint64_t;\r\
    \nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\n#line 9 \"test/data_structure/Segment_Add_Get_Min.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<std::pair<i64,\
    \ i64>> lr(n);\n    std::vector<std::pair<i64, i64>> y(n);\n    std::vector<i64>\
    \ x;\n    for (int i = 0; i < n; i++) {\n        std::cin >> lr[i].first >> lr[i].second;\n\
    \        std::cin >> y[i].first >> y[i].second;\n    }\n    std::vector<std::vector<i64>>\
    \ query(q);\n    for (int i = 0; i < q; i++) {\n        i64 t;\n        std::cin\
    \ >> t;\n        query[i].emplace_back(t);\n        if (t == 0) {\n          \
    \  i64 l, r, a, b;\n            std::cin >> l >> r >> a >> b;\n            query[i].emplace_back(l);\n\
    \            query[i].emplace_back(r);\n            query[i].emplace_back(a);\n\
    \            query[i].emplace_back(b);\n        } else {\n            i64 p;\n\
    \            std::cin >> p;\n            query[i].emplace_back(p);\n         \
    \   x.emplace_back(p);\n        }\n    }\n    if (x.size() == 0) return 0;\n \
    \   std::sort(x.begin(), x.end());\n    x.erase(unique(x.begin(), x.end()), x.end());\n\
    \    x.emplace_back(1e9 + 10);\n    ebi::li_chao_tree<i64> seg(x);\n    for (int\
    \ i = 0; i < n; i++) {\n        auto [l, r] = lr[i];\n        auto [a, b] = y[i];\n\
    \        seg.add_segment(a, b, l, r);\n    }\n    for (int i = 0; i < q; i++)\
    \ {\n        if (query[i][0] == 0) {\n            i64 l = query[i][1];\n     \
    \       i64 r = query[i][2];\n            i64 a = query[i][3];\n            i64\
    \ b = query[i][4];\n            seg.add_segment(a, b, l, r);\n        } else {\n\
    \            i64 ret = seg.min(query[i][1]);\n            if (ret == std::numeric_limits<i64>::max())\
    \ {\n                std::cout << \"INFINITY\" << std::endl;\n            } else\
    \ {\n                std::cout << ret << std::endl;\n            }\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"../../data_structure/li_chao_tree.hpp\"\
    \n#include \"../../utility/int_alias.hpp\"\n\nint main() {\n    int n, q;\n  \
    \  std::cin >> n >> q;\n    std::vector<std::pair<i64, i64>> lr(n);\n    std::vector<std::pair<i64,\
    \ i64>> y(n);\n    std::vector<i64> x;\n    for (int i = 0; i < n; i++) {\n  \
    \      std::cin >> lr[i].first >> lr[i].second;\n        std::cin >> y[i].first\
    \ >> y[i].second;\n    }\n    std::vector<std::vector<i64>> query(q);\n    for\
    \ (int i = 0; i < q; i++) {\n        i64 t;\n        std::cin >> t;\n        query[i].emplace_back(t);\n\
    \        if (t == 0) {\n            i64 l, r, a, b;\n            std::cin >> l\
    \ >> r >> a >> b;\n            query[i].emplace_back(l);\n            query[i].emplace_back(r);\n\
    \            query[i].emplace_back(a);\n            query[i].emplace_back(b);\n\
    \        } else {\n            i64 p;\n            std::cin >> p;\n          \
    \  query[i].emplace_back(p);\n            x.emplace_back(p);\n        }\n    }\n\
    \    if (x.size() == 0) return 0;\n    std::sort(x.begin(), x.end());\n    x.erase(unique(x.begin(),\
    \ x.end()), x.end());\n    x.emplace_back(1e9 + 10);\n    ebi::li_chao_tree<i64>\
    \ seg(x);\n    for (int i = 0; i < n; i++) {\n        auto [l, r] = lr[i];\n \
    \       auto [a, b] = y[i];\n        seg.add_segment(a, b, l, r);\n    }\n   \
    \ for (int i = 0; i < q; i++) {\n        if (query[i][0] == 0) {\n           \
    \ i64 l = query[i][1];\n            i64 r = query[i][2];\n            i64 a =\
    \ query[i][3];\n            i64 b = query[i][4];\n            seg.add_segment(a,\
    \ b, l, r);\n        } else {\n            i64 ret = seg.min(query[i][1]);\n \
    \           if (ret == std::numeric_limits<i64>::max()) {\n                std::cout\
    \ << \"INFINITY\" << std::endl;\n            } else {\n                std::cout\
    \ << ret << std::endl;\n            }\n        }\n    }\n}"
  dependsOn:
  - data_structure/li_chao_tree.hpp
  - utility/int_alias.hpp
  isVerificationFile: true
  path: test/data_structure/Segment_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '2023-07-10 17:44:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Segment_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Segment_Add_Get_Min.test.cpp
- /verify/test/data_structure/Segment_Add_Get_Min.test.cpp.html
title: test/data_structure/Segment_Add_Get_Min.test.cpp
---
