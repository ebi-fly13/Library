---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2450.test.cpp
    title: test/aoj/aoj_2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_2439.test.cpp
    title: test/yuki/yuki_2439.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html
  bundledCode: "#line 2 \"data_structure/lazy_segtree.hpp\"\n\r\n/*\r\n    reference:\r\
    \n   https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#include <bit>\r\n#include <cassert>\r\n#include <ranges>\r\n#include\
    \ <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)(),\
    \ class F, S (*mapping)(F, S),\r\n          F (*composition)(F, F), F (*id)()>\r\
    \nstruct lazy_segtree {\r\n  private:\r\n    void update(int i) {\r\n        data[i]\
    \ = op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n    void all_apply(int k,\
    \ F f) {\r\n        data[k] = mapping(f, data[k]);\r\n        if (k < sz) lazy[k]\
    \ = composition(f, lazy[k]);\r\n    }\r\n\r\n    void push(int i) {\r\n      \
    \  all_apply(2 * i, lazy[i]);\r\n        all_apply(2 * i + 1, lazy[i]);\r\n  \
    \      lazy[i] = id();\r\n    }\r\n\r\n  public:\r\n    lazy_segtree(int _n) :\
    \ lazy_segtree(std::vector<S>(_n, e())) {}\r\n    lazy_segtree(const std::vector<S>\
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
    \r\n}  // namespace ebi\r\n"
  code: "#pragma once\r\n\r\n/*\r\n    reference:\r\n   https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#include <bit>\r\n#include <cassert>\r\n#include <ranges>\r\n#include\
    \ <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)(),\
    \ class F, S (*mapping)(F, S),\r\n          F (*composition)(F, F), F (*id)()>\r\
    \nstruct lazy_segtree {\r\n  private:\r\n    void update(int i) {\r\n        data[i]\
    \ = op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n    void all_apply(int k,\
    \ F f) {\r\n        data[k] = mapping(f, data[k]);\r\n        if (k < sz) lazy[k]\
    \ = composition(f, lazy[k]);\r\n    }\r\n\r\n    void push(int i) {\r\n      \
    \  all_apply(2 * i, lazy[i]);\r\n        all_apply(2 * i + 1, lazy[i]);\r\n  \
    \      lazy[i] = id();\r\n    }\r\n\r\n  public:\r\n    lazy_segtree(int _n) :\
    \ lazy_segtree(std::vector<S>(_n, e())) {}\r\n    lazy_segtree(const std::vector<S>\
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
    \r\n}  // namespace ebi\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2450.test.cpp
  - test/yuki/yuki_2439.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
documentation_of: data_structure/lazy_segtree.hpp
layout: document
title: lazy segtree
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して各種区間操作ができるデータ構造である。インターフェースはすべてACLと同様。

### コンストラクタ

`lazy_segtree<S, op, e, F, mapping, composition, id>(int n)`
`lazy_segtree<S, op, e, F, mapping, composition, id>(const std::vector<S> &v)`

-   型 `S`
-   二項演算 `S op(S, S)`
-   単位元 `S e()`
-   写像の型 `F`
-   $f(x)$ を返す関数 `S mapping(F f, S x)`
-   $f(g)$ を返す関数 `F composition(F f, F g)`
-   $id(x) = x$ となる $id$ を返す関数 `F id()`

に対する遅延セグ木を構築する。要素数を渡す場合、 `std::vector<S>(n, e())` に対して遅延セグ木を構築する。Range add Range Sumの場合次のようになる。計算量 $O(n)$

```cpp
struct S {
    long long value;
    int size;
};
using F = long long;

S op(S a, S b) { return {a.value+b.value, a.size+b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {x.value + f*x.size, x.size}; }
F composition(F f, F g) { return f+g; }
F id() { return 0; }

lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
```

### get(int p)

v[p] を返す。

### set(int p, S x)

v[p] = x とする。

### prod(int l, int r)

op(v[l], ..., a[r-1]) を返す。

### all_prod()

op(v[0], ..., v[n-1]) を返す。

### apply(int p, F f)

v[p] に、写像 $f$ を作用させる。

### apply(int l, int r, F f)

v[l], ... v[r-1] に、写像 $f$ を作用させる。

### max_right(int l, F f)

セグ木上の二分探索。$[l, r)$ が f を満たすような最大の $r$ を返す。

### min_left(int r, F f)

セグ木上の二分探索。$[l, r)$ が f を満たすような最小の $l$ を返す。