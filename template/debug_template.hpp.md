---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Totient_Function.test.cpp
    title: test/math/Sum_of_Totient_Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/debug_template.hpp\"\n\n#include <iostream>\n\n\
    namespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                          \
    \                            \\\n    std::cerr << \"LINE: \" << __LINE__ << \"\
    \  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}\n"
  code: "#pragma once\n\n#include <iostream>\n\nnamespace ebi {\n\n#ifdef LOCAL\n\
    #define debug(...)                                                      \\\n \
    \   std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\",\
    \ \\\n        debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid\
    \ debug_out() {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename...\
    \ Tail> void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n  \
    \  if (sizeof...(t) > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/debug_template.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2023-08-10 23:52:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_1145.test.cpp
  - test/math/Sum_of_Totient_Function.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
documentation_of: template/debug_template.hpp
layout: document
redirect_from:
- /library/template/debug_template.hpp
- /library/template/debug_template.hpp.html
title: template/debug_template.hpp
---
