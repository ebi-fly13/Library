---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Stern-Brocot_Tree.test.cpp
    title: test/math/Stern-Brocot_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/stern_brocot_tree.hpp\"\n\n#include <cassert>\n#include\
    \ <concepts>\n#include <iostream>\n#include <optional>\n#include <vector>\n#include\
    \ <cstdint>\n\nnamespace ebi {\n\nstruct stern_brocot_tree {\n  private:\n   \
    \ using value_type = std::int64_t;\n    using T = value_type;\n    using Fraction\
    \ = std::pair<T, T>;\n\n    static Fraction add(const Fraction &lhs, const Fraction\
    \ &rhs) {\n        return {lhs.first + rhs.first, lhs.second + rhs.second};\n\
    \    }\n\n    static Fraction mul(const T k, const Fraction &a) {\n        return\
    \ {k * a.first, k * a.second};\n    }\n\n  public:\n    stern_brocot_tree() =\
    \ default;\n\n    static std::vector<T> encode_path(const Fraction &f) {\n   \
    \     auto [x, y] = f;\n        std::vector<T> path;\n        while (x != y) {\n\
    \            T m = (x - 1) / y;\n            path.emplace_back(m);\n         \
    \   x -= m * y;\n            std::swap(x, y);\n        }\n        return path;\n\
    \    }\n\n    static std::pair<Fraction, Fraction> decode_path(\n        const\
    \ std::vector<T> &path) {\n        T lx = 0, ly = 1, rx = 1, ry = 0;\n       \
    \ for (bool is_right = true; auto n : path) {\n            if (is_right) {\n \
    \               lx += rx * n;\n                ly += ry * n;\n            } else\
    \ {\n                rx += lx * n;\n                ry += ly * n;\n          \
    \  }\n            is_right = !is_right;\n        }\n        return {{lx, ly},\
    \ {rx, ry}};\n    }\n\n    static std::pair<Fraction, Fraction> decode_path(\n\
    \        const std::vector<std::pair<char, T>> &path) {\n        if (path.empty())\
    \ {\n            return {{0, 1}, {1, 0}};\n        }\n        std::vector<T> p;\n\
    \        bool is_right = true;\n        if (path[0].first == 'L') {\n        \
    \    p.emplace_back(0);\n            is_right = !is_right;\n        }\n      \
    \  for (auto [c, n] : path) {\n            assert(c == (is_right ? 'R' : 'L'));\n\
    \            p.emplace_back(n);\n            is_right = !is_right;\n        }\n\
    \        return decode_path(p);\n    }\n\n    static Fraction lca(Fraction f,\
    \ Fraction g) {\n        auto path_f = encode_path(f);\n        auto path_g =\
    \ encode_path(g);\n        std::vector<T> path_h;\n        for (int i = 0; i <\
    \ (int)std::min(path_f.size(), path_g.size()); i++) {\n            T k = std::min(path_f[i],\
    \ path_g[i]);\n            path_h.emplace_back(k);\n            if (path_f[i]\
    \ != path_g[i]) {\n                break;\n            }\n        }\n        return\
    \ val(decode_path(path_h));\n    }\n\n    static std::optional<Fraction> ancestor(T\
    \ k, Fraction f) {\n        std::vector<T> path;\n        for (auto n : encode_path(f))\
    \ {\n            T m = std::min(k, n);\n            path.emplace_back(m);\n  \
    \          k -= m;\n            if (k == 0) break;\n        }\n        if (k >\
    \ 0) return std::nullopt;\n        return val(decode_path(path));\n    }\n\n \
    \   static std::pair<Fraction, Fraction> range(Fraction f) {\n        return decode_path(encode_path(f));\n\
    \    }\n\n    template<class F>\n    static Fraction binary_search(const T max_value,\
    \ F f) {\n        Fraction l = {0, 1}, r = {1, 0};\n        while(true) {\n  \
    \          Fraction now = val({l, r});\n            bool flag = f(now);\n    \
    \        Fraction from = flag ? l : r;\n            Fraction to = flag ? r : l;\n\
    \            T ok = 1, ng = 2;\n            while(f(add(from, mul(ng, to))) ==\
    \ flag) {\n                ok <<= 1;\n                ng <<= 1;\n            \
    \    auto nxt = add(from, mul(ok, to));\n                if(nxt.first > max_value\
    \ || nxt.second > max_value) return to;\n            }\n            while(ng -\
    \ ok > 1) {\n                T mid = (ok + ng) >> 1;\n                if(f(add(from,\
    \ mul(mid, to))) == flag) {\n                    ok = mid;\n                }\n\
    \                else {\n                    ng = mid;\n                }\n  \
    \          }\n            (flag ? l : r) = add(from, mul(ok, to));\n        }\n\
    \        assert(0);\n        return l;\n    }\n\n    static Fraction val(const\
    \ std::pair<Fraction, Fraction> &f) {\n        return add(f.first, f.second);\n\
    \    }\n\n    static void print_path(const std::vector<T> &path) {\n        if\
    \ (path.empty()) {\n            std::cout << \"0\\n\";\n            return;\n\
    \        }\n        int k = (int)path.size() - int(path[0] == 0);\n        std::cout\
    \ << k;\n        for (bool is_right = true; auto c : path) {\n            if (c\
    \ > 0) {\n                std::cout << \" \" << (is_right ? 'R' : 'L') << \" \"\
    \ << c;\n            }\n            is_right = !is_right;\n        }\n       \
    \ std::cout << '\\n';\n        return;\n    }\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <concepts>\n#include <iostream>\n\
    #include <optional>\n#include <vector>\n#include <cstdint>\n\nnamespace ebi {\n\
    \nstruct stern_brocot_tree {\n  private:\n    using value_type = std::int64_t;\n\
    \    using T = value_type;\n    using Fraction = std::pair<T, T>;\n\n    static\
    \ Fraction add(const Fraction &lhs, const Fraction &rhs) {\n        return {lhs.first\
    \ + rhs.first, lhs.second + rhs.second};\n    }\n\n    static Fraction mul(const\
    \ T k, const Fraction &a) {\n        return {k * a.first, k * a.second};\n   \
    \ }\n\n  public:\n    stern_brocot_tree() = default;\n\n    static std::vector<T>\
    \ encode_path(const Fraction &f) {\n        auto [x, y] = f;\n        std::vector<T>\
    \ path;\n        while (x != y) {\n            T m = (x - 1) / y;\n          \
    \  path.emplace_back(m);\n            x -= m * y;\n            std::swap(x, y);\n\
    \        }\n        return path;\n    }\n\n    static std::pair<Fraction, Fraction>\
    \ decode_path(\n        const std::vector<T> &path) {\n        T lx = 0, ly =\
    \ 1, rx = 1, ry = 0;\n        for (bool is_right = true; auto n : path) {\n  \
    \          if (is_right) {\n                lx += rx * n;\n                ly\
    \ += ry * n;\n            } else {\n                rx += lx * n;\n          \
    \      ry += ly * n;\n            }\n            is_right = !is_right;\n     \
    \   }\n        return {{lx, ly}, {rx, ry}};\n    }\n\n    static std::pair<Fraction,\
    \ Fraction> decode_path(\n        const std::vector<std::pair<char, T>> &path)\
    \ {\n        if (path.empty()) {\n            return {{0, 1}, {1, 0}};\n     \
    \   }\n        std::vector<T> p;\n        bool is_right = true;\n        if (path[0].first\
    \ == 'L') {\n            p.emplace_back(0);\n            is_right = !is_right;\n\
    \        }\n        for (auto [c, n] : path) {\n            assert(c == (is_right\
    \ ? 'R' : 'L'));\n            p.emplace_back(n);\n            is_right = !is_right;\n\
    \        }\n        return decode_path(p);\n    }\n\n    static Fraction lca(Fraction\
    \ f, Fraction g) {\n        auto path_f = encode_path(f);\n        auto path_g\
    \ = encode_path(g);\n        std::vector<T> path_h;\n        for (int i = 0; i\
    \ < (int)std::min(path_f.size(), path_g.size()); i++) {\n            T k = std::min(path_f[i],\
    \ path_g[i]);\n            path_h.emplace_back(k);\n            if (path_f[i]\
    \ != path_g[i]) {\n                break;\n            }\n        }\n        return\
    \ val(decode_path(path_h));\n    }\n\n    static std::optional<Fraction> ancestor(T\
    \ k, Fraction f) {\n        std::vector<T> path;\n        for (auto n : encode_path(f))\
    \ {\n            T m = std::min(k, n);\n            path.emplace_back(m);\n  \
    \          k -= m;\n            if (k == 0) break;\n        }\n        if (k >\
    \ 0) return std::nullopt;\n        return val(decode_path(path));\n    }\n\n \
    \   static std::pair<Fraction, Fraction> range(Fraction f) {\n        return decode_path(encode_path(f));\n\
    \    }\n\n    template<class F>\n    static Fraction binary_search(const T max_value,\
    \ F f) {\n        Fraction l = {0, 1}, r = {1, 0};\n        while(true) {\n  \
    \          Fraction now = val({l, r});\n            bool flag = f(now);\n    \
    \        Fraction from = flag ? l : r;\n            Fraction to = flag ? r : l;\n\
    \            T ok = 1, ng = 2;\n            while(f(add(from, mul(ng, to))) ==\
    \ flag) {\n                ok <<= 1;\n                ng <<= 1;\n            \
    \    auto nxt = add(from, mul(ok, to));\n                if(nxt.first > max_value\
    \ || nxt.second > max_value) return to;\n            }\n            while(ng -\
    \ ok > 1) {\n                T mid = (ok + ng) >> 1;\n                if(f(add(from,\
    \ mul(mid, to))) == flag) {\n                    ok = mid;\n                }\n\
    \                else {\n                    ng = mid;\n                }\n  \
    \          }\n            (flag ? l : r) = add(from, mul(ok, to));\n        }\n\
    \        assert(0);\n        return l;\n    }\n\n    static Fraction val(const\
    \ std::pair<Fraction, Fraction> &f) {\n        return add(f.first, f.second);\n\
    \    }\n\n    static void print_path(const std::vector<T> &path) {\n        if\
    \ (path.empty()) {\n            std::cout << \"0\\n\";\n            return;\n\
    \        }\n        int k = (int)path.size() - int(path[0] == 0);\n        std::cout\
    \ << k;\n        for (bool is_right = true; auto c : path) {\n            if (c\
    \ > 0) {\n                std::cout << \" \" << (is_right ? 'R' : 'L') << \" \"\
    \ << c;\n            }\n            is_right = !is_right;\n        }\n       \
    \ std::cout << '\\n';\n        return;\n    }\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: math/stern_brocot_tree.hpp
  requiredBy: []
  timestamp: '2023-12-28 16:44:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Stern-Brocot_Tree.test.cpp
documentation_of: math/stern_brocot_tree.hpp
layout: document
title: Stern-Brocot Tree
---

## 説明

Stern-Brocot Treeに対する各種操作を行う。断りがない場合、時間計算量は対数時間である。

ここで、Stern-Brocot Treeの各ノードは有理数 $l, r$ を持つ。任意の正の有理数 $a$ について、Stern-Brocot Treeのノードが一対一対応する。ノードの値を、対応する有理数のこととする。 $l = \frac{p}{q}, r = \frac{r}{s}$ とするとノードの値 $f$ は $f = \frac{p + r}{q + s}$ となる。また、あるノード $f$ を根とする部分木のノードに対応する値は開区間 $(f.l, f.r)$ に含まれる。

`Fraction` は有理数の型であり内部で `using Fraction = std::pair<i64,i64>` されている。

### encode_path(Fraction f)

有理数 $f = \frac{x}{y}$ のStern-Brocot Tree上のパスを返す。パスは `std::vector<i64>` に格納され、右左右左...という順に進む回数が格納されている。

$x, y$ は互いに素な正の整数とする。

### decode_path(std::vector\<i64\> path)

Stern-Brocot Tree上の根からのパスを渡し、パスの先のノードの持つ有理数 $l, r$ を返す。

### decode_path(std::vector<std::pair<char, i64>> path)

Stern-Brocot Treeの根から、右と左どちらに進むかと何回進むかのペアで表現されたパスを渡し、パスの先のノードを返す。

### lca(Fraction f, Fraction g)

有理数 $f, g$ を渡し、Stern-Brocot Tree上のLCAとなるノードの値を返す。

### ancestor(i64 k, Fraction f)

Stern-Brocot Tree の根から有理数 $f$ までのパス上のノードであり、深さ $k$ のノードの値を返す。

### range(Fraction f)

Stern-Brocot Tree の上の有理数 $f$ と対応するノードの持つ有理数 $(l, r)$ を返す。

### binary_search(i64 max_value, F f)

有理数を引数とし true / false を返す単調な関数 $f$ について、 $f(\frac{p}{q}) = true$ かつ $p < max\\_value$ かつ $q < max\\_value$ を満たす最大の $\frac{p}{q}$ を返す。 $f(0) = false$ の場合は $\frac{0}{1}$ を、 $f(\infty) = true$ の場合は $\frac{1}{0}$ を返す。

### val(std::pair<Fraction, Fraction> f)

ノード $f$ の値を有理数で返す。 $O(1)$

### print_path(std::vector\<i64\> path)

Stern-Brocot Treeの根からのパスを以下のようなフォーマットで出力する。

```
k c_0 n_0 c_1 n_1 ... c_{k-1} n_{k-1}
```

$c_i$ は `L` または `R` であり $n_i$ は $c_i$ が連続して並ぶ回数とする。
