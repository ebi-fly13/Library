---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segtree.hpp
    title: lazy segtree
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Area_of_Union_of_Rectangles.test.cpp
    title: test/data_structure/Area_of_Union_of_Rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/area_of_union_of_rectangles.hpp\"\n\n#include\
    \ <cassert>\n#include <limits>\n#include <vector>\n\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#include <algorithm>\n#line 6 \"data_structure/compress.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp_)\
    \ : cp(cp_) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi\n#line 2 \"data_structure/lazy_segtree.hpp\"\
    \n\r\n/*\r\n    reference:\r\n   https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#include <bit>\r\n#line 10 \"data_structure/lazy_segtree.hpp\"\n#include\
    \ <cstdint>\r\n#include <ranges>\r\n#line 13 \"data_structure/lazy_segtree.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)(), class\
    \ F, S (*mapping)(F, S),\r\n          F (*composition)(F, F), F (*id)()>\r\nstruct\
    \ lazy_segtree {\r\n  private:\r\n    void update(int i) {\r\n        data[i]\
    \ = op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n    void all_apply(int k,\
    \ F f) {\r\n        data[k] = mapping(f, data[k]);\r\n        if (k < sz) lazy[k]\
    \ = composition(f, lazy[k]);\r\n    }\r\n\r\n    void push(int i) {\r\n      \
    \  all_apply(2 * i, lazy[i]);\r\n        all_apply(2 * i + 1, lazy[i]);\r\n  \
    \      lazy[i] = id();\r\n    }\r\n\r\n  public:\r\n    lazy_segtree(int n_) :\
    \ lazy_segtree(std::vector<S>(n_, e())) {}\r\n    lazy_segtree(const std::vector<S>\
    \ &a)\r\n        : n(a.size()),\r\n          sz(std::bit_ceil(a.size())),\r\n\
    \          lg2(std::countr_zero(std::uint32_t(sz))) {\r\n        data = std::vector<S>(2\
    \ * sz, e());\r\n        lazy = std::vector<F>(sz, id());\r\n        for (int\
    \ i : std::views::iota(0, n)) {\r\n            data[sz + i] = a[i];\r\n      \
    \  }\r\n        for (int i : std::views::iota(1, sz) | std::views::reverse) {\r\
    \n            update(i);\r\n        }\r\n    }\r\n\r\n    void set(int p, S x)\
    \ {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\n        for (int\
    \ i = lg2; i >= 1; i--) push(p >> i);\r\n        data[p] = x;\r\n        for (int\
    \ i = 1; i <= lg2; i++) update(p >> i);\r\n    }\r\n\r\n    S get(int p) {\r\n\
    \        assert(0 <= p && p < n);\r\n        p += sz;\r\n        for (int i =\
    \ lg2; i >= 1; i--) push(p >> i);\r\n        return data[p];\r\n    }\r\n\r\n\
    \    S prod(int l, int r) {\r\n        assert(0 <= l && l <= r && r <= n);\r\n\
    \        if (l == r) return e();\r\n\r\n        l += sz;\r\n        r += sz;\r\
    \n\r\n        for (int i = lg2; i >= 1; i--) {\r\n            if (((l >> i) <<\
    \ i) != l) push(l >> i);\r\n            if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\r\n        }\r\n\r\n        S sml = e(), smr = e();\r\n        while\
    \ (l < r) {\r\n            if (l & 1) sml = op(sml, data[l++]);\r\n          \
    \  if (r & 1) smr = op(data[--r], smr);\r\n            l >>= 1;\r\n          \
    \  r >>= 1;\r\n        }\r\n\r\n        return op(sml, smr);\r\n    }\r\n\r\n\
    \    S all_prod() const {\r\n        return data[1];\r\n    }\r\n\r\n    void\
    \ apply(int p, F f) {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\
    \n        for (int i = lg2; i >= 1; i--) push(p >> i);\r\n        data[p] = mapping(f,\
    \ data[p]);\r\n        for (int i = 1; i <= lg2; i++) update(p >> i);\r\n    }\r\
    \n\r\n    void apply(int l, int r, F f) {\r\n        assert(0 <= l && l <= r &&\
    \ r <= n);\r\n        l += sz;\r\n        r += sz;\r\n        for (int i = lg2;\
    \ i >= 1; i--) {\r\n            if (((l >> i) << i) != l) push(l >> i);\r\n  \
    \          if (((r >> i) << i) != r) push((r - 1) >> i);\r\n        }\r\n\r\n\
    \        {\r\n            int memo_l = l, memo_r = r;\r\n            while (l\
    \ < r) {\r\n                if (l & 1) all_apply(l++, f);\r\n                if\
    \ (r & 1) all_apply(--r, f);\r\n                l >>= 1;\r\n                r\
    \ >>= 1;\r\n            }\r\n            l = memo_l;\r\n            r = memo_r;\r\
    \n        }\r\n\r\n        for (int i = 1; i <= lg2; i++) {\r\n            if\
    \ (((l >> i) << i) != l) update(l >> i);\r\n            if (((r >> i) << i) !=\
    \ r) update((r - 1) >> i);\r\n        }\r\n    }\r\n\r\n    template <class G>\
    \ int max_right(int l, G g) {\r\n        assert(0 <= l && l <= n);\r\n       \
    \ assert(g(e()));\r\n        if (l == n) return n;\r\n        l += sz;\r\n   \
    \     for (int i = lg2; i >= 1; i--) push(l >> i);\r\n        S sm = e();\r\n\
    \        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!g(op(sm,\
    \ data[l]))) {\r\n                while (l < sz) {\r\n                    push(l);\r\
    \n                    l = l << 1;\r\n                    if (g(op(sm, data[l])))\
    \ {\r\n                        sm = op(sm, data[l]);\r\n                     \
    \   l++;\r\n                    }\r\n                }\r\n                return\
    \ l - sz;\r\n            }\r\n            sm = op(sm, data[l]);\r\n          \
    \  l++;\r\n        } while ((l & -l) != l);\r\n        return n;\r\n    }\r\n\r\
    \n    template <class G> int min_left(int r, G g) {\r\n        assert(0 <= r &&\
    \ r <= n);\r\n        assert(g(e()));\r\n        if (r == 0) return 0;\r\n   \
    \     r += sz;\r\n        for (int i = lg2; i >= 1; i--) push((r - 1) >> i);\r\
    \n        S sm = e();\r\n        do {\r\n            r--;\r\n            while\
    \ (r > 1 && r % 2) r >>= 1;\r\n            if (!g(op(data[r], sm))) {\r\n    \
    \            while (r < sz) {\r\n                    push(r);\r\n            \
    \        r = (r << 1) + 1;\r\n                    if (g(op(data[r], sm))) {\r\n\
    \                        sm = op(data[r], sm);\r\n                        r--;\r\
    \n                    }\r\n                }\r\n                return r + 1 -\
    \ sz;\r\n            }\r\n            sm = op(data[r], sm);\r\n        } while\
    \ ((r & -r) != r);\r\n        return 0;\r\n    }\r\n\r\n  private:\r\n    int\
    \ n, sz, lg2;\r\n    std::vector<S> data;\r\n    std::vector<F> lazy;\r\n};\r\n\
    \r\n}  // namespace ebi\r\n#line 2 \"template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\
    \n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\nusing i8 =\
    \ std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16\
    \ = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing\
    \ i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 10 \"data_structure/area_of_union_of_rectangles.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\nusing S = std::pair<int, i64>;\n\
    \nS op(S a, S b) {\n    if (a.first == b.first)\n        return {a.first, a.second\
    \ + b.second};\n    else if (a.first < b.first)\n        return a;\n    else\n\
    \        return b;\n}\n\nS e() {\n    return {std::numeric_limits<int>::max(),\
    \ 0};\n}\n\nS mapping(int f, S x) {\n    return {x.first + f, x.second};\n}\n\n\
    int composition(int f, int g) {\n    return f + g;\n}\n\nint id() {\n    return\
    \ 0;\n}\n\n}  // namespace internal\n\nstruct area_of_union_of_rectangles {\n\
    \  public:\n    area_of_union_of_rectangles() = default;\n\n    void add_rectangle(i64\
    \ l, i64 d, i64 r, i64 u) {\n        qs.push_back({l, d, r, u});\n        cp_x.add(l);\n\
    \        cp_x.add(r);\n        cp_y.add(d);\n        cp_y.add(u);\n    }\n\n \
    \   i64 run() {\n        assert(is_first);\n        is_first = false;\n      \
    \  cp_x.build();\n        cp_y.build();\n        int n = cp_x.size(), m = cp_y.size();\n\
    \        using namespace internal;\n        lazy_segtree<S, op, e, int, mapping,\
    \ composition, id> seg(\n            [&]() -> std::vector<S> {\n             \
    \   std::vector<S> data(m - 1);\n                for (int i = 0; i < m - 1; i++)\
    \ {\n                    data[i] = {0, cp_y.val(i + 1) - cp_y.val(i)};\n     \
    \           }\n                return data;\n            }());\n        std::vector\
    \ table(n,\n                          std::vector(2, std::vector<std::pair<i64,\
    \ i64>>()));\n        for (auto [l, d, r, u] : qs) {\n            int x = cp_y.get(d);\n\
    \            int y = cp_y.get(u);\n            table[cp_x.get(l)][0].emplace_back(x,\
    \ y);\n            table[cp_x.get(r)][1].emplace_back(x, y);\n        }\n    \
    \    i64 ans = 0;\n        for (int i = 0; i < n - 1; i++) {\n            i64\
    \ wy = cp_y.val(m - 1) - cp_y.val(0);\n            i64 wx = cp_x.val(i + 1) -\
    \ cp_x.val(i);\n            for (auto [d, u] : table[i][0]) {\n              \
    \  seg.apply(d, u, 1);\n            }\n            for (auto [d, u] : table[i][1])\
    \ {\n                seg.apply(d, u, -1);\n            }\n            auto [min,\
    \ cnt] = seg.all_prod();\n            if (min == 0) wy -= cnt;\n            ans\
    \ += wx * wy;\n        }\n        return ans;\n    }\n\n  private:\n    bool is_first\
    \ = true;\n    std::vector<std::array<i64, 4>> qs;\n    compress<i64> cp_x, cp_y;\n\
    };\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \n#include \"../data_structure/compress.hpp\"\n#include \"../data_structure/lazy_segtree.hpp\"\
    \n#include \"../template/int_alias.hpp\"\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\nusing S = std::pair<int, i64>;\n\nS op(S a, S b) {\n    if (a.first ==\
    \ b.first)\n        return {a.first, a.second + b.second};\n    else if (a.first\
    \ < b.first)\n        return a;\n    else\n        return b;\n}\n\nS e() {\n \
    \   return {std::numeric_limits<int>::max(), 0};\n}\n\nS mapping(int f, S x) {\n\
    \    return {x.first + f, x.second};\n}\n\nint composition(int f, int g) {\n \
    \   return f + g;\n}\n\nint id() {\n    return 0;\n}\n\n}  // namespace internal\n\
    \nstruct area_of_union_of_rectangles {\n  public:\n    area_of_union_of_rectangles()\
    \ = default;\n\n    void add_rectangle(i64 l, i64 d, i64 r, i64 u) {\n       \
    \ qs.push_back({l, d, r, u});\n        cp_x.add(l);\n        cp_x.add(r);\n  \
    \      cp_y.add(d);\n        cp_y.add(u);\n    }\n\n    i64 run() {\n        assert(is_first);\n\
    \        is_first = false;\n        cp_x.build();\n        cp_y.build();\n   \
    \     int n = cp_x.size(), m = cp_y.size();\n        using namespace internal;\n\
    \        lazy_segtree<S, op, e, int, mapping, composition, id> seg(\n        \
    \    [&]() -> std::vector<S> {\n                std::vector<S> data(m - 1);\n\
    \                for (int i = 0; i < m - 1; i++) {\n                    data[i]\
    \ = {0, cp_y.val(i + 1) - cp_y.val(i)};\n                }\n                return\
    \ data;\n            }());\n        std::vector table(n,\n                   \
    \       std::vector(2, std::vector<std::pair<i64, i64>>()));\n        for (auto\
    \ [l, d, r, u] : qs) {\n            int x = cp_y.get(d);\n            int y =\
    \ cp_y.get(u);\n            table[cp_x.get(l)][0].emplace_back(x, y);\n      \
    \      table[cp_x.get(r)][1].emplace_back(x, y);\n        }\n        i64 ans =\
    \ 0;\n        for (int i = 0; i < n - 1; i++) {\n            i64 wy = cp_y.val(m\
    \ - 1) - cp_y.val(0);\n            i64 wx = cp_x.val(i + 1) - cp_x.val(i);\n \
    \           for (auto [d, u] : table[i][0]) {\n                seg.apply(d, u,\
    \ 1);\n            }\n            for (auto [d, u] : table[i][1]) {\n        \
    \        seg.apply(d, u, -1);\n            }\n            auto [min, cnt] = seg.all_prod();\n\
    \            if (min == 0) wy -= cnt;\n            ans += wx * wy;\n        }\n\
    \        return ans;\n    }\n\n  private:\n    bool is_first = true;\n    std::vector<std::array<i64,\
    \ 4>> qs;\n    compress<i64> cp_x, cp_y;\n};\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/compress.hpp
  - data_structure/lazy_segtree.hpp
  - template/int_alias.hpp
  isVerificationFile: false
  path: data_structure/area_of_union_of_rectangles.hpp
  requiredBy: []
  timestamp: '2024-04-25 14:53:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Area_of_Union_of_Rectangles.test.cpp
documentation_of: data_structure/area_of_union_of_rectangles.hpp
layout: document
title: Area of Union of Rectangles
---

## 説明

複数の長方形の和集合の面積を求める。長方形の個数を $N$ として $O(N\log{N})$

### add_rectangle(l, d, r, u)

長方形 $\{(x, y): l \leq x \leq r, d \leq y \leq u\}$ を追加する。

### run()

長方形の和集合の面積を求める。