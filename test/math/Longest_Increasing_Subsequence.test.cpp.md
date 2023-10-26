---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/longest_increasing_subsequence.hpp
    title: LIS
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/math/Longest_Increasing_Subsequence.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\n\
    \n#line 2 \"math/longest_increasing_subsequence.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T>\
    \ std::vector<T> LIS(const std::vector<T> &a, bool narrowly) {\n    std::vector<T>\
    \ ret = {std::numeric_limits<T>::max()};\n    std::vector<int> used;\n    used.reserve(a.size());\n\
    \    for (auto x : a) {\n        auto itr = narrowly ? std::lower_bound(ret.begin(),\
    \ ret.end(), x)\n                            : std::upper_bound(ret.begin(), ret.end(),\
    \ x);\n        used.emplace_back(itr - ret.begin());\n        if (itr == ret.end())\n\
    \            ret.emplace_back(x);\n        else\n            *itr = x;\n    }\n\
    \    int len = ret.size();\n    int idx = len - 1;\n    T now = std::numeric_limits<T>::max();\n\
    \    std::vector<int> lis(len);\n    for (int i = int(a.size()) - 1; i >= 0; i--)\
    \ {\n        if (used[i] == idx && a[i] + int(narrowly) <= now) {\n          \
    \  now = a[i];\n            lis[idx--] = i;\n        }\n    }\n    return lis;\n\
    }\n\n}  // namespace ebi\n#line 4 \"test/math/Longest_Increasing_Subsequence.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"test/math/Longest_Increasing_Subsequence.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n\
    \    for (auto &x : a) std::cin >> x;\n    auto ans = ebi::LIS(a, true);\n   \
    \ int k = ans.size();\n    std::cout << k << '\\n';\n    for (int i = 0; i < k;\
    \ i++) {\n        std::cout << ans[i] << \" \\n\"[i == k - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"../../math/longest_increasing_subsequence.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int>\
    \ a(n);\n    for (auto &x : a) std::cin >> x;\n    auto ans = ebi::LIS(a, true);\n\
    \    int k = ans.size();\n    std::cout << k << '\\n';\n    for (int i = 0; i\
    \ < k; i++) {\n        std::cout << ans[i] << \" \\n\"[i == k - 1];\n    }\n}"
  dependsOn:
  - math/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/math/Longest_Increasing_Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Longest_Increasing_Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/math/Longest_Increasing_Subsequence.test.cpp
- /verify/test/math/Longest_Increasing_Subsequence.test.cpp.html
title: test/math/Longest_Increasing_Subsequence.test.cpp
---
