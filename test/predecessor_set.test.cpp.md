---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/predecessor_set.hpp
    title: data_structure/predecessor_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/predecessor_set.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \n\n#line 2 \"data_structure/predecessor_set.hpp\"\n\n#include <set>\n\nnamespace\
    \ ebi {\n\nstruct predecessor_set {\n  public:\n    predecessor_set() = default;\n\
    \n    void insert(int k) {\n        set.insert(k);\n    }\n\n    void erase(int\
    \ k) {\n        set.erase(k);\n    }\n\n    bool find(int k) const {\n       \
    \ return set.find(k) != set.end();\n    }\n\n    int find_next(int k) const {\n\
    \        auto itr = set.lower_bound(k);\n        return itr == set.end() ? -1\
    \ : *itr;\n    }\n\n    int find_prev(int k) const {\n        auto itr = set.upper_bound(k);\n\
    \        return itr == set.begin() ? -1 : *(--itr);\n    }\n\n  private:\n   \
    \ std::set<int> set;\n};\n\n}  // namespace ebi\n#line 4 \"test/predecessor_set.test.cpp\"\
    \n\n#include <iostream>\n#include <string>\n\nint main() {\n    int n, q;\n  \
    \  std::cin >> n >> q;\n    std::string t;\n    std::cin >> t;\n    ebi::predecessor_set\
    \ set;\n    for (int i = 0; i < n; i++) {\n        if (t[i] == '1') {\n      \
    \      set.insert(i);\n        }\n    }\n    while (q--) {\n        int flag,\
    \ k;\n        std::cin >> flag >> k;\n        if (flag == 0) {\n            set.insert(k);\n\
    \        } else if (flag == 1) {\n            set.erase(k);\n        } else if\
    \ (flag == 2) {\n            std::cout << (set.find(k) ? 1 : 0) << '\\n';\n  \
    \      } else if (flag == 3) {\n            std::cout << set.find_next(k) << '\\\
    n';\n        } else {\n            std::cout << set.find_prev(k) << '\\n';\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include \"data_structure/predecessor_set.hpp\"\n\n#include <iostream>\n#include\
    \ <string>\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::string\
    \ t;\n    std::cin >> t;\n    ebi::predecessor_set set;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (t[i] == '1') {\n            set.insert(i);\n      \
    \  }\n    }\n    while (q--) {\n        int flag, k;\n        std::cin >> flag\
    \ >> k;\n        if (flag == 0) {\n            set.insert(k);\n        } else\
    \ if (flag == 1) {\n            set.erase(k);\n        } else if (flag == 2) {\n\
    \            std::cout << (set.find(k) ? 1 : 0) << '\\n';\n        } else if (flag\
    \ == 3) {\n            std::cout << set.find_next(k) << '\\n';\n        } else\
    \ {\n            std::cout << set.find_prev(k) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/predecessor_set.hpp
  isVerificationFile: true
  path: test/predecessor_set.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/predecessor_set.test.cpp
layout: document
redirect_from:
- /verify/test/predecessor_set.test.cpp
- /verify/test/predecessor_set.test.cpp.html
title: test/predecessor_set.test.cpp
---
