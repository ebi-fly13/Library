---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc116/submissions/21477123
    - https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c#toc4
  bundledCode: "#line 2 \"math/DirichletSeries.hpp\"\n\r\n/*\r\n    verify: https://atcoder.jp/contests/arc116/submissions/21477123\r\
    \n    refernce: https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c#toc4\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cstdint>\r\n#include <cmath>\r\n\r\n\
    namespace ebi {\r\n\r\ntemplate<class T>\r\nstruct DirichletSeries {\r\nprivate:\r\
    \n    using Self = DirichletSeries<T>;\r\n    using size_t = std::size_t;\r\n\
    \    using u64 = std::uint_fast64_t;\r\n\r\n    static size_t N,K,L;\r\n    std::vector<T>\
    \ a,A;\r\npublic:\r\n    DirichletSeries() : a(K+1), A(L+1) { }\r\n\r\n    Self\
    \ operator*(const Self &rhs) const noexcept {\r\n        return Self(*this) *=\
    \ rhs;\r\n    }\r\n\r\n    Self operator*=(const Self &rhs) noexcept {\r\n   \
    \     Self ret;\r\n        for(size_t i = 1; i < K+1; ++i) {\r\n            for(size_t\
    \ j = 1; j < K/i + 1; ++j) {\r\n                ret.a[i*j] += a[i]*rhs.a[j];\r\
    \n            }\r\n        }\r\n        std::vector<T> sum_a = a, sum_b = rhs.a;\r\
    \n        for(size_t i = 1; i < K; ++i) {\r\n            sum_a[i+1] += sum_a[i];\r\
    \n            sum_b[i+1] += sum_b[i];\r\n        }\r\n        auto get_A = [&](size_t\
    \ x) -> T {\r\n            if(x <= K) {\r\n                return sum_a[x];\r\n\
    \            }\r\n            else {\r\n                return A[N/x];\r\n   \
    \         }\r\n        };\r\n        auto get_B = [&](size_t x) -> T {\r\n   \
    \         if(x <= K) {\r\n                return sum_b[x];\r\n            }\r\n\
    \            else {\r\n                return rhs.A[N/x];\r\n            }\r\n\
    \        };\r\n        for(size_t l = 1; l < L+1; ++l) {\r\n            size_t\
    \ n = N/l;\r\n            size_t m = std::floor(std::sqrt(n));\r\n           \
    \ for(size_t i = 1; i < m + 1; ++i) {\r\n                ret.A[l] += a[i] * get_B(n/i)\
    \ + rhs.a[i] * (get_A(n/i) - get_A(m));\r\n            }\r\n        }\r\n    \
    \    return *this = ret;\r\n    }\r\n\r\n    Self pow(u64 n) const {\r\n     \
    \   Self res;\r\n        res.a[1] = 1;\r\n        res.A.assign(L+1, 1);\r\n  \
    \      Self x = *this;\r\n        while(n>0){\r\n            if(n&1) res = res\
    \ * x;\r\n            x = x*x;\r\n            n>>=1;\r\n        }\r\n        return\
    \ res;\r\n    }\r\n\r\n    T get_sum() {\r\n        return A[1];\r\n    }\r\n\r\
    \n    static Self zeta() {\r\n        Self ret;\r\n        ret.a.assign(K+1, 1);\r\
    \n        for(size_t i = 1; i < L + 1; ++i) {\r\n            ret.A[i] = N/i;\r\
    \n        }\r\n        return ret;\r\n    }\r\n\r\n    static void set_size(size_t\
    \ n) {\r\n        N = n;\r\n        K = std::ceil(std::cbrt(n*n));\r\n       \
    \ L = std::ceil(std::cbrt(n));\r\n    }\r\n};\r\n\r\ntemplate<class T>\r\nsize_t\
    \ DirichletSeries<T>::N = 1000000;\r\ntemplate<class T>\r\nsize_t DirichletSeries<T>::K\
    \ = 10000;\r\ntemplate<class T>\r\nsize_t DirichletSeries<T>::L = 100;\r\n\r\n\
    }\n"
  code: "#pragma once\r\n\r\n/*\r\n    verify: https://atcoder.jp/contests/arc116/submissions/21477123\r\
    \n    refernce: https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c#toc4\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cstdint>\r\n#include <cmath>\r\n\r\n\
    namespace ebi {\r\n\r\ntemplate<class T>\r\nstruct DirichletSeries {\r\nprivate:\r\
    \n    using Self = DirichletSeries<T>;\r\n    using size_t = std::size_t;\r\n\
    \    using u64 = std::uint_fast64_t;\r\n\r\n    static size_t N,K,L;\r\n    std::vector<T>\
    \ a,A;\r\npublic:\r\n    DirichletSeries() : a(K+1), A(L+1) { }\r\n\r\n    Self\
    \ operator*(const Self &rhs) const noexcept {\r\n        return Self(*this) *=\
    \ rhs;\r\n    }\r\n\r\n    Self operator*=(const Self &rhs) noexcept {\r\n   \
    \     Self ret;\r\n        for(size_t i = 1; i < K+1; ++i) {\r\n            for(size_t\
    \ j = 1; j < K/i + 1; ++j) {\r\n                ret.a[i*j] += a[i]*rhs.a[j];\r\
    \n            }\r\n        }\r\n        std::vector<T> sum_a = a, sum_b = rhs.a;\r\
    \n        for(size_t i = 1; i < K; ++i) {\r\n            sum_a[i+1] += sum_a[i];\r\
    \n            sum_b[i+1] += sum_b[i];\r\n        }\r\n        auto get_A = [&](size_t\
    \ x) -> T {\r\n            if(x <= K) {\r\n                return sum_a[x];\r\n\
    \            }\r\n            else {\r\n                return A[N/x];\r\n   \
    \         }\r\n        };\r\n        auto get_B = [&](size_t x) -> T {\r\n   \
    \         if(x <= K) {\r\n                return sum_b[x];\r\n            }\r\n\
    \            else {\r\n                return rhs.A[N/x];\r\n            }\r\n\
    \        };\r\n        for(size_t l = 1; l < L+1; ++l) {\r\n            size_t\
    \ n = N/l;\r\n            size_t m = std::floor(std::sqrt(n));\r\n           \
    \ for(size_t i = 1; i < m + 1; ++i) {\r\n                ret.A[l] += a[i] * get_B(n/i)\
    \ + rhs.a[i] * (get_A(n/i) - get_A(m));\r\n            }\r\n        }\r\n    \
    \    return *this = ret;\r\n    }\r\n\r\n    Self pow(u64 n) const {\r\n     \
    \   Self res;\r\n        res.a[1] = 1;\r\n        res.A.assign(L+1, 1);\r\n  \
    \      Self x = *this;\r\n        while(n>0){\r\n            if(n&1) res = res\
    \ * x;\r\n            x = x*x;\r\n            n>>=1;\r\n        }\r\n        return\
    \ res;\r\n    }\r\n\r\n    T get_sum() {\r\n        return A[1];\r\n    }\r\n\r\
    \n    static Self zeta() {\r\n        Self ret;\r\n        ret.a.assign(K+1, 1);\r\
    \n        for(size_t i = 1; i < L + 1; ++i) {\r\n            ret.A[i] = N/i;\r\
    \n        }\r\n        return ret;\r\n    }\r\n\r\n    static void set_size(size_t\
    \ n) {\r\n        N = n;\r\n        K = std::ceil(std::cbrt(n*n));\r\n       \
    \ L = std::ceil(std::cbrt(n));\r\n    }\r\n};\r\n\r\ntemplate<class T>\r\nsize_t\
    \ DirichletSeries<T>::N = 1000000;\r\ntemplate<class T>\r\nsize_t DirichletSeries<T>::K\
    \ = 10000;\r\ntemplate<class T>\r\nsize_t DirichletSeries<T>::L = 100;\r\n\r\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/DirichletSeries.hpp
  requiredBy: []
  timestamp: '2021-04-03 17:24:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/DirichletSeries.hpp
layout: document
redirect_from:
- /library/math/DirichletSeries.hpp
- /library/math/DirichletSeries.hpp.html
title: math/DirichletSeries.hpp
---
