---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/mo_algorithm.hpp
    title: algorithm/mo_algorithm.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/FenwickTree.hpp
    title: data_structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/static_range_inversion_query.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <numeric>\r\
    \n#include <cstdint>\r\n\r\n#line 2 \"algorithm/mo_algorithm.hpp\"\n\r\n#line\
    \ 5 \"algorithm/mo_algorithm.hpp\"\n#include <cmath>\r\n#line 7 \"algorithm/mo_algorithm.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<class IL, class IR, class DL, class DR,\
    \ class O>\r\nvoid mo_algorithm(const int &n, const std::vector<int> &l, const\
    \ std::vector<int> &r, const IL &insert_left, const IR &insert_right, const DL\
    \ &delete_left, const DR &delete_right, const O &out) {\r\n    const int q = l.size();\r\
    \n    const int block =  n/std::max<int>(1, std::sqrt(n));\r\n    std::vector<int>\
    \ order(q, 0);\r\n    iota(order.begin(), order.end(), 0);\r\n    std::sort(order.begin(),\
    \ order.end(), [&](int i, int j) {\r\n        int bi = l[i]/block;\r\n       \
    \ int bj = l[j]/block;\r\n        return bi != bj ? bi < bj : bi & 1 ? r[i] >\
    \ r[j] : r[i] < r[j];\r\n    });\r\n    int nl = 0, nr = 0;\r\n    for(auto i:\
    \ order) {\r\n        while(l[i] < nl) insert_left(--nl);\r\n        while(nr\
    \ < r[i]) insert_right(nr++);\r\n        while(nl < l[i]) delete_left(nl++);\r\
    \n        while(r[i] < nr) delete_right(--nr);\r\n        out(i);\r\n    }\r\n\
    \    return;\r\n}\r\n\r\n}\n#line 2 \"data_structure/FenwickTree.hpp\"\n\r\n#line\
    \ 4 \"data_structure/FenwickTree.hpp\"\n#include <cassert>\r\n\r\nnamespace ebi\
    \ {\r\n\r\ntemplate<class T>\r\nstruct FenwickTree {\r\nprivate:\r\n    int n;\r\
    \n    std::vector<T> data;\r\n\r\npublic:\r\n    FenwickTree(int _n) : n(_n),\
    \ data(std::vector<T>(_n+1, T(0))) { }\r\n\r\n    void add(int i, T val) {\r\n\
    \        i++;\r\n        for(int x = i; x <= n; x += x & -x) {\r\n           \
    \ data[x] += val;\r\n        }\r\n    }\r\n\r\n    T prefix_sum(int i) {\r\n \
    \       assert(0<=i && i<=n);\r\n        T ret = 0;\r\n        for(int x = i;\
    \ x>0; x -= x & -x) {\r\n            ret += data[x];\r\n        }\r\n        return\
    \ ret;\r\n    }\r\n\r\n    T sum(int l, int r) {\r\n        return prefix_sum(r)-prefix_sum(l);\r\
    \n    }\r\n\r\n    // prefix_sum(x) >= key \u3068\u306A\u308B\u6700\u5C0F\u306E\
    x\u3092\u8FD4\u3059\u95A2\u6570 O(log N)\r\n    int lower_bound(T key) {\r\n \
    \       if(key<=0) return 0;\r\n        int x = 0;\r\n        int max = 1;\r\n\
    \        while((max<<1) <= n) max <<= 1;\r\n        for(int k = max; k>0; k >>=\
    \ 1) {\r\n            if(x+k<=n && data[x+k]<key) {\r\n                x += k;\r\
    \n                key -= data[x];\r\n            }\r\n        }\r\n        return\
    \ x+1;\r\n    }\r\n};\r\n\r\n} // namespace ebi\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#line 5 \"data_structure/compress.hpp\"\n\nnamespace ebi {\n\ntemplate<class\
    \ T>\nstruct compress {\nprivate:\n    std::vector<T> cp;\n    bool flag = false;\n\
    public:\n    compress() = default;\n\n    compress(std::vector<T> cp) : cp(cp)\
    \ {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \        flag = true;\n    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n\
    \        flag = false;\n    }\n\n    int get(const T &val) {\n        if(flag\
    \ == false) build();\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n};\n\n}\n#line 12 \"test/static_range_inversion_query.test.cpp\"\n\r\n\
    using u64 = std::uint64_t;\r\n\r\nint main() {\r\n    int n,q;\r\n    std::cin\
    \ >> n >> q;\r\n    std::vector<int> a(n);\r\n    std::vector<int> l(q), r(q);\r\
    \n    ebi::compress<int> cp;\r\n    for(int i = 0; i < n; i++) {\r\n        std::cin\
    \ >> a[i];\r\n        cp.add(a[i]);\r\n    }\r\n    cp.build();\r\n    for(int\
    \ i = 0; i < n; i++) {\r\n        a[i] = cp.get(a[i]);\r\n    }\r\n    for(int\
    \ i = 0; i < q; i++) {\r\n        std::cin >> l[i] >> r[i];\r\n    }\r\n    ebi::FenwickTree<u64>\
    \ fw(cp.size());\r\n    std::vector<u64> ans(q);\r\n    u64 ret = 0;\r\n    const\
    \ auto insert_left = [&](int l) -> void {\r\n        ret += fw.prefix_sum(a[l]);\r\
    \n        fw.add(a[l], 1);\r\n    };\r\n    const auto insert_right = [&](int\
    \ r) -> void {\r\n        ret += fw.sum(a[r]+1, cp.size());\r\n        fw.add(a[r],\
    \ 1);\r\n    };\r\n    const auto delete_left = [&](int l) -> void {\r\n     \
    \   ret -= fw.prefix_sum(a[l]);\r\n        fw.add(a[l], -1);\r\n    };\r\n   \
    \ const auto delete_right = [&](int r) -> void {\r\n        ret -= fw.sum(a[r]+1,\
    \ cp.size());\r\n        fw.add(a[r], -1);\r\n    };\r\n    const auto out = [&](int\
    \ i) -> void {\r\n        ans[i] = ret;\r\n    };\r\n    ebi::mo_algorithm(n,\
    \ l, r, insert_left, insert_right, delete_left, delete_right, out);\r\n    for(auto\
    \ val: ans) {\r\n        std::cout << val << '\\n';\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#include\
    \ <numeric>\r\n#include <cstdint>\r\n\r\n#include \"../algorithm/mo_algorithm.hpp\"\
    \r\n#include \"../data_structure/FenwickTree.hpp\"\r\n#include \"../data_structure/compress.hpp\"\
    \r\n\r\nusing u64 = std::uint64_t;\r\n\r\nint main() {\r\n    int n,q;\r\n   \
    \ std::cin >> n >> q;\r\n    std::vector<int> a(n);\r\n    std::vector<int> l(q),\
    \ r(q);\r\n    ebi::compress<int> cp;\r\n    for(int i = 0; i < n; i++) {\r\n\
    \        std::cin >> a[i];\r\n        cp.add(a[i]);\r\n    }\r\n    cp.build();\r\
    \n    for(int i = 0; i < n; i++) {\r\n        a[i] = cp.get(a[i]);\r\n    }\r\n\
    \    for(int i = 0; i < q; i++) {\r\n        std::cin >> l[i] >> r[i];\r\n   \
    \ }\r\n    ebi::FenwickTree<u64> fw(cp.size());\r\n    std::vector<u64> ans(q);\r\
    \n    u64 ret = 0;\r\n    const auto insert_left = [&](int l) -> void {\r\n  \
    \      ret += fw.prefix_sum(a[l]);\r\n        fw.add(a[l], 1);\r\n    };\r\n \
    \   const auto insert_right = [&](int r) -> void {\r\n        ret += fw.sum(a[r]+1,\
    \ cp.size());\r\n        fw.add(a[r], 1);\r\n    };\r\n    const auto delete_left\
    \ = [&](int l) -> void {\r\n        ret -= fw.prefix_sum(a[l]);\r\n        fw.add(a[l],\
    \ -1);\r\n    };\r\n    const auto delete_right = [&](int r) -> void {\r\n   \
    \     ret -= fw.sum(a[r]+1, cp.size());\r\n        fw.add(a[r], -1);\r\n    };\r\
    \n    const auto out = [&](int i) -> void {\r\n        ans[i] = ret;\r\n    };\r\
    \n    ebi::mo_algorithm(n, l, r, insert_left, insert_right, delete_left, delete_right,\
    \ out);\r\n    for(auto val: ans) {\r\n        std::cout << val << '\\n';\r\n\
    \    }\r\n}"
  dependsOn:
  - algorithm/mo_algorithm.hpp
  - data_structure/FenwickTree.hpp
  - data_structure/compress.hpp
  isVerificationFile: true
  path: test/static_range_inversion_query.test.cpp
  requiredBy: []
  timestamp: '2021-08-18 00:16:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static_range_inversion_query.test.cpp
layout: document
redirect_from:
- /verify/test/static_range_inversion_query.test.cpp
- /verify/test/static_range_inversion_query.test.cpp.html
title: test/static_range_inversion_query.test.cpp
---
