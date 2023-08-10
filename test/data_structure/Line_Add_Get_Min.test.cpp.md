---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/li_chao_tree.hpp
    title: Li Chao Tree
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/data_structure/Line_Add_Get_Min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include <iostream>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"data_structure/li_chao_tree.hpp\"\
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
    #line 2 \"template/int_alias.hpp\"\n\n#include <cstddef>\n#include <cstdint>\n\
    \nnamespace ebi {\n\nusing std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\n\
    using i16 = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}\n#line 9 \"test/data_structure/Line_Add_Get_Min.test.cpp\"\
    \n\nusing ebi::i64;\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    std::vector<std::pair<i64, i64>> p(n);\n    for (auto &[a, b] : p) {\n  \
    \      std::cin >> a >> b;\n    }\n    std::vector<i64> x;\n    std::vector<std::vector<i64>>\
    \ query(q);\n    for (int i = 0; i < q; i++) {\n        int t;\n        std::cin\
    \ >> t;\n        query[i].emplace_back(t);\n        if (t == 0) {\n          \
    \  i64 a, b;\n            std::cin >> a >> b;\n            query[i].emplace_back(a);\n\
    \            query[i].emplace_back(b);\n        } else {\n            i64 p;\n\
    \            std::cin >> p;\n            query[i].emplace_back(p);\n         \
    \   x.emplace_back(p);\n        }\n    }\n    ebi::li_chao_tree<i64> seg(x);\n\
    \    for (auto [a, b] : p) {\n        seg.add_line(a, b);\n    }\n    for (int\
    \ i = 0; i < q; i++) {\n        if (query[i][0] == 0) {\n            seg.add_line(query[i][1],\
    \ query[i][2]);\n        } else {\n            std::cout << seg.min(query[i][1])\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"../../data_structure/li_chao_tree.hpp\"\
    \n#include \"../../template/int_alias.hpp\"\n\nusing ebi::i64;\n\nint main() {\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<std::pair<i64, i64>>\
    \ p(n);\n    for (auto &[a, b] : p) {\n        std::cin >> a >> b;\n    }\n  \
    \  std::vector<i64> x;\n    std::vector<std::vector<i64>> query(q);\n    for (int\
    \ i = 0; i < q; i++) {\n        int t;\n        std::cin >> t;\n        query[i].emplace_back(t);\n\
    \        if (t == 0) {\n            i64 a, b;\n            std::cin >> a >> b;\n\
    \            query[i].emplace_back(a);\n            query[i].emplace_back(b);\n\
    \        } else {\n            i64 p;\n            std::cin >> p;\n          \
    \  query[i].emplace_back(p);\n            x.emplace_back(p);\n        }\n    }\n\
    \    ebi::li_chao_tree<i64> seg(x);\n    for (auto [a, b] : p) {\n        seg.add_line(a,\
    \ b);\n    }\n    for (int i = 0; i < q; i++) {\n        if (query[i][0] == 0)\
    \ {\n            seg.add_line(query[i][1], query[i][2]);\n        } else {\n \
    \           std::cout << seg.min(query[i][1]) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/li_chao_tree.hpp
  - template/int_alias.hpp
  isVerificationFile: true
  path: test/data_structure/Line_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '2023-08-10 23:52:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Line_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Line_Add_Get_Min.test.cpp
- /verify/test/data_structure/Line_Add_Get_Min.test.cpp.html
title: test/data_structure/Line_Add_Get_Min.test.cpp
---
