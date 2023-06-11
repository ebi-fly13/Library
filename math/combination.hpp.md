---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/combination.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n#line 2 \"utility/modint_base.hpp\"\n\n#include <type_traits>\n\nnamespace ebi\
    \ {\n\nnamespace internal {\n\nstruct modint_base {};\n\ntemplate <class T> using\
    \ is_modint = std::is_base_of<modint_base, T>;\ntemplate <class T> using is_modint_t\
    \ = std::enable_if_t<is_modint<T>::value>;\n\n}  // namespace internal\n\n}  //\
    \ namespace ebi\n#line 7 \"math/combination.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class mint>\nstruct combination {\n    combination(int n) : m(n), fact(n +\
    \ 1), inv_fact(n + 1) {\n        fact[0] = 1;\n        for (int i = 1; i <= n;\
    \ i++) {\n            fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[n]\
    \ = fact[n].inv();\n        for (int i = n; i > 0; i--) {\n            inv_fact[i\
    \ - 1] = inv_fact[i] * i;\n        }\n    }\n\n    mint operator()(int n, int\
    \ k) const {\n        assert(n <= m);\n        if (k < 0 || n < k) return 0;\n\
    \        return fact[n] * inv_fact[k] * inv_fact[n - k];\n    }\n\n    mint f(int\
    \ n) const {\n        assert(n <= m);\n        if (n < 0) return 0;\n        return\
    \ fact[n];\n    }\n\n    mint inv_f(int n) const {\n        assert(n <= m);\n\
    \        if (n < 0) return 0;\n        return inv_fact[n];\n    }\n\n    mint\
    \ inv(int n) const {\n        assert(n <= m);\n        return inv_fact[n] * fact[n-1];\n\
    \    }\n\n  private:\n    int m;\n    std::vector<mint> fact, inv_fact;\n};\n\n\
    }  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../utility/modint_base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class mint>\nstruct combination {\n    combination(int\
    \ n) : m(n), fact(n + 1), inv_fact(n + 1) {\n        fact[0] = 1;\n        for\
    \ (int i = 1; i <= n; i++) {\n            fact[i] = fact[i - 1] * i;\n       \
    \ }\n        inv_fact[n] = fact[n].inv();\n        for (int i = n; i > 0; i--)\
    \ {\n            inv_fact[i - 1] = inv_fact[i] * i;\n        }\n    }\n\n    mint\
    \ operator()(int n, int k) const {\n        assert(n <= m);\n        if (k < 0\
    \ || n < k) return 0;\n        return fact[n] * inv_fact[k] * inv_fact[n - k];\n\
    \    }\n\n    mint f(int n) const {\n        assert(n <= m);\n        if (n <\
    \ 0) return 0;\n        return fact[n];\n    }\n\n    mint inv_f(int n) const\
    \ {\n        assert(n <= m);\n        if (n < 0) return 0;\n        return inv_fact[n];\n\
    \    }\n\n    mint inv(int n) const {\n        assert(n <= m);\n        return\
    \ inv_fact[n] * fact[n-1];\n    }\n\n  private:\n    int m;\n    std::vector<mint>\
    \ fact, inv_fact;\n};\n\n}  // namespace ebi"
  dependsOn:
  - utility/modint_base.hpp
  isVerificationFile: false
  path: math/combination.hpp
  requiredBy: []
  timestamp: '2023-06-08 01:58:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.hpp
layout: document
redirect_from:
- /library/math/combination.hpp
- /library/math/combination.hpp.html
title: math/combination.hpp
---
