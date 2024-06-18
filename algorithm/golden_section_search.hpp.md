---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/monge_d_edge_shortest_path.hpp
    title: Monge d-edge shortest path
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://x.com/noshi91/status/1399003086362865673
  bundledCode: "#line 2 \"algorithm/golden_section_search.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <functional>\n#include <utility>\n\n#line 2 \"template/int_alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\n\
    using i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 9 \"algorithm/golden_section_search.hpp\"\
    \n\nnamespace ebi {\n\n// ref: https://x.com/noshi91/status/1399003086362865673\n\
    template <std::integral S, class F,\n          class T = decltype(std::declval<F>()(std::declval<S>())),\n\
    \          class Compare = std::less<T>>\nstd::pair<S, T> golden_section_search(F\
    \ f, S min, S max,\n                                      const Compare &compare\
    \ = Compare()) {\n    assert(min <= max);\n    S a = min - 1, x, b;\n    {\n \
    \       S s = 1, t = 2;\n        while (t < max - min + 2) {\n            std::swap(s\
    \ += t, t);\n        }\n        x = a + t - s;\n        b = a + t;\n    }\n  \
    \  T fx = f(x), fy;\n    while (a + b != 2 * x) {\n        S y = a + b - x;\n\
    \        if (max < y || compare(fx, (fy = f(y)))) {\n            b = a;\n    \
    \        a = y;\n        } else {\n            a = x;\n            x = y;\n  \
    \          fx = fy;\n        }\n    }\n    return {x, fx};\n}\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <concepts>\n#include <functional>\n\
    #include <utility>\n\n#include \"../template/int_alias.hpp\"\n\nnamespace ebi\
    \ {\n\n// ref: https://x.com/noshi91/status/1399003086362865673\ntemplate <std::integral\
    \ S, class F,\n          class T = decltype(std::declval<F>()(std::declval<S>())),\n\
    \          class Compare = std::less<T>>\nstd::pair<S, T> golden_section_search(F\
    \ f, S min, S max,\n                                      const Compare &compare\
    \ = Compare()) {\n    assert(min <= max);\n    S a = min - 1, x, b;\n    {\n \
    \       S s = 1, t = 2;\n        while (t < max - min + 2) {\n            std::swap(s\
    \ += t, t);\n        }\n        x = a + t - s;\n        b = a + t;\n    }\n  \
    \  T fx = f(x), fy;\n    while (a + b != 2 * x) {\n        S y = a + b - x;\n\
    \        if (max < y || compare(fx, (fy = f(y)))) {\n            b = a;\n    \
    \        a = y;\n        } else {\n            a = x;\n            x = y;\n  \
    \          fx = fy;\n        }\n    }\n    return {x, fx};\n}\n\n}  // namespace\
    \ ebi"
  dependsOn:
  - template/int_alias.hpp
  isVerificationFile: false
  path: algorithm/golden_section_search.hpp
  requiredBy:
  - algorithm/monge_d_edge_shortest_path.hpp
  timestamp: '2023-12-28 15:52:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/golden_section_search.hpp
layout: document
title: Golden section search
---

## 説明

整数範囲で、黄金分割探索を行う。

### golden_section_search(f, min, max, compare)

凸な関数 $f$ に対して、 $[min, max]$ で黄金分割探索をして最小値を求める。compareに比較関数を与えることで最大値を求めることもできる。 $O(\log (\max - \min))$