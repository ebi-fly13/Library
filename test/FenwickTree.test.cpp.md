---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/FenwickTree.hpp
    title: data_structure/FenwickTree.hpp
  - icon: ':question:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/FenwickTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \r\n\r\n#line 2 \"data_structure/FenwickTree.hpp\"\n\r\n#include <vector>\r\n\
    #include <cassert>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct FenwickTree\
    \ {\r\nprivate:\r\n    int n;\r\n    std::vector<T> data;\r\n\r\npublic:\r\n \
    \   FenwickTree(int _n) : n(_n), data(std::vector<T>(_n+1, T(0))) { }\r\n\r\n\
    \    void add(int i, T val) {\r\n        i++;\r\n        for(int x = i; x <= n;\
    \ x += x & -x) {\r\n            data[x] += val;\r\n        }\r\n    }\r\n\r\n\
    \    T prefix_sum(int i) {\r\n        assert(0<=i && i<=n);\r\n        T ret =\
    \ 0;\r\n        for(int x = i; x>0; x -= x & -x) {\r\n            ret += data[x];\r\
    \n        }\r\n        return ret;\r\n    }\r\n\r\n    T sum(int l, int r) {\r\
    \n        return prefix_sum(r)-prefix_sum(l);\r\n    }\r\n\r\n    // prefix_sum(x)\
    \ >= key \u3068\u306A\u308B\u6700\u5C0F\u306Ex\u3092\u8FD4\u3059\u95A2\u6570 O(log\
    \ N)\r\n    int lower_bound(T key) {\r\n        if(key<=0) return 0;\r\n     \
    \   int x = 0;\r\n        int max = 1;\r\n        while((max<<1) <= n) max <<=\
    \ 1;\r\n        for(int k = max; k>0; k >>= 1) {\r\n            if(x+k<=n && data[x+k]<key)\
    \ {\r\n                x += k;\r\n                key -= data[x];\r\n        \
    \    }\r\n        }\r\n        return x+1;\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi\n#line 4 \"test/FenwickTree.test.cpp\"\n\r\n#include <iostream>\r\n\r\n\
    #line 2 \"utility/int_alias.hpp\"\n\r\n#include <cstddef>\r\n#include <cstdint>\r\
    \n\r\nusing i32 = std::int32_t;\r\nusing i64 = std::int64_t;\r\nusing u16 = std::uint16_t;\r\
    \nusing u32 = std::uint32_t;\r\nusing u64 = std::uint64_t;\r\nusing usize = std::size_t;\n\
    #line 8 \"test/FenwickTree.test.cpp\"\n\r\nint main() {\r\n    int n, q;\r\n \
    \   std::cin >> n >> q;\r\n    ebi::FenwickTree<i64> fw(n);\r\n    for (int i\
    \ = 0; i < n; i++) {\r\n        i64 a;\r\n        std::cin >> a;\r\n        fw.add(i,\
    \ a);\r\n    }\r\n    for (int i = 0; i < q; i++) {\r\n        int flag;\r\n \
    \       std::cin >> flag;\r\n        if (flag == 0) {\r\n            int p;\r\n\
    \            i64 x;\r\n            std::cin >> p >> x;\r\n            fw.add(p,\
    \ x);\r\n        } else {\r\n            int l, r;\r\n            std::cin >>\
    \ l >> r;\r\n            std::cout << fw.sum(l, r) << std::endl;\r\n        }\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../data_structure/FenwickTree.hpp\"\r\n\r\n#include <iostream>\r\
    \n\r\n#include \"../utility/int_alias.hpp\"\r\n\r\nint main() {\r\n    int n,\
    \ q;\r\n    std::cin >> n >> q;\r\n    ebi::FenwickTree<i64> fw(n);\r\n    for\
    \ (int i = 0; i < n; i++) {\r\n        i64 a;\r\n        std::cin >> a;\r\n  \
    \      fw.add(i, a);\r\n    }\r\n    for (int i = 0; i < q; i++) {\r\n       \
    \ int flag;\r\n        std::cin >> flag;\r\n        if (flag == 0) {\r\n     \
    \       int p;\r\n            i64 x;\r\n            std::cin >> p >> x;\r\n  \
    \          fw.add(p, x);\r\n        } else {\r\n            int l, r;\r\n    \
    \        std::cin >> l >> r;\r\n            std::cout << fw.sum(l, r) << std::endl;\r\
    \n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/FenwickTree.hpp
  - utility/int_alias.hpp
  isVerificationFile: true
  path: test/FenwickTree.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 05:33:08+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FenwickTree.test.cpp
layout: document
redirect_from:
- /verify/test/FenwickTree.test.cpp
- /verify/test/FenwickTree.test.cpp.html
title: test/FenwickTree.test.cpp
---
