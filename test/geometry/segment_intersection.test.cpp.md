---
data:
  _extendedDependsOn:
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_6_A
  bundledCode: "#line 1 \"test/geometry/segment_intersection.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_6_A\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <algorithm>\n#include <cassert>\n#include\
    \ <iomanip>\n#include <cstdint>\n#include <map>\n\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#line 6 \"data_structure/compress.hpp\"\n\nnamespace ebi {\n\ntemplate<class\
    \ T>\nstruct compress {\nprivate:\n    std::vector<T> cp;\n    bool flag = false;\n\
    public:\n    compress() = default;\n\n    compress(std::vector<T> cp) : cp(cp)\
    \ {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \        flag = true;\n    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n\
    \        flag = false;\n    }\n\n    int get(const T &val) {\n        if(flag\
    \ == false) build();\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}\n#line 2 \"data_structure/FenwickTree.hpp\"\
    \n\r\n#line 5 \"data_structure/FenwickTree.hpp\"\n\r\nnamespace ebi {\r\n\r\n\
    template<class T>\r\nstruct FenwickTree {\r\nprivate:\r\n    int n;\r\n    std::vector<T>\
    \ data;\r\n\r\npublic:\r\n    FenwickTree(int _n) : n(_n), data(std::vector<T>(_n+1,\
    \ T(0))) { }\r\n\r\n    void add(int i, T val) {\r\n        i++;\r\n        for(int\
    \ x = i; x <= n; x += x & -x) {\r\n            data[x] += val;\r\n        }\r\n\
    \    }\r\n\r\n    T prefix_sum(int i) {\r\n        assert(0<=i && i<=n);\r\n \
    \       T ret = 0;\r\n        for(int x = i; x>0; x -= x & -x) {\r\n         \
    \   ret += data[x];\r\n        }\r\n        return ret;\r\n    }\r\n\r\n    T\
    \ sum(int l, int r) {\r\n        return prefix_sum(r)-prefix_sum(l);\r\n    }\r\
    \n\r\n    // prefix_sum(x) >= key \u3068\u306A\u308B\u6700\u5C0F\u306Ex\u3092\u8FD4\
    \u3059\u95A2\u6570 O(log N)\r\n    int lower_bound(T key) {\r\n        if(key<=0)\
    \ return 0;\r\n        int x = 0;\r\n        int max = 1;\r\n        while((max<<1)\
    \ <= n) max <<= 1;\r\n        for(int k = max; k>0; k >>= 1) {\r\n           \
    \ if(x+k<=n && data[x+k]<key) {\r\n                x += k;\r\n               \
    \ key -= data[x];\r\n            }\r\n        }\r\n        return x+1;\r\n   \
    \ }\r\n};\r\n\r\n} // namespace ebi\n#line 13 \"test/geometry/segment_intersection.test.cpp\"\
    \n\nnamespace ebi {\n\nusing i64 = std::int64_t;\n\nvoid main_() {\n    int n;\n\
    \    std::cin >> n;\n    std::map<i64, std::vector<std::pair<i64,i64>>> xmap,\
    \ ymap;\n    compress<i64> cp;\n    std::vector<i64> ret;\n    for(int i = 0;\
    \ i < n; i++) {\n        i64 x1, y1, x2, y2;\n        std::cin >> x1 >> y1 >>\
    \ x2 >> y2;\n        ret.emplace_back(x1);\n        ret.emplace_back(x2+1);\n\
    \        cp.add(y1);\n        cp.add(y2);\n        if(x1 == x2) {\n          \
    \  if(y1 > y2) std::swap(y1, y2);\n            xmap[x1].emplace_back(y1, y2);\n\
    \        }\n        else {\n            assert(y1 == y2);\n            if(x1 >\
    \ x2) std::swap(x1, x2);\n            ymap[x1].emplace_back(y1, 1);\n        \
    \    ymap[x2+1].emplace_back(y1, -1);\n        }\n    }\n    cp.build();\n   \
    \ std::sort(ret.begin(), ret.end());\n    ret.erase(std::unique(ret.begin(), ret.end()),\
    \ ret.end());\n    FenwickTree<i64> fw(cp.size());\n    i64 ans = 0;\n    for(auto\
    \ x: ret) {\n        for(auto [y, val]: ymap[x]) {\n            fw.add(cp.get(y),\
    \ val);\n        }\n        for(auto [low, high]: xmap[x]) {\n            ans\
    \ += fw.sum(cp.get(low), cp.get(high+1));\n        }\n    }\n    std::cout <<\
    \ ans << '\\n';\n}\n\n}\n\nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    ebi::main_();\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_6_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include <iomanip>\n#include <cstdint>\n#include <map>\n\n#include \"data_structure/compress.hpp\"\
    \n#include \"data_structure/FenwickTree.hpp\"\n\nnamespace ebi {\n\nusing i64\
    \ = std::int64_t;\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::map<i64,\
    \ std::vector<std::pair<i64,i64>>> xmap, ymap;\n    compress<i64> cp;\n    std::vector<i64>\
    \ ret;\n    for(int i = 0; i < n; i++) {\n        i64 x1, y1, x2, y2;\n      \
    \  std::cin >> x1 >> y1 >> x2 >> y2;\n        ret.emplace_back(x1);\n        ret.emplace_back(x2+1);\n\
    \        cp.add(y1);\n        cp.add(y2);\n        if(x1 == x2) {\n          \
    \  if(y1 > y2) std::swap(y1, y2);\n            xmap[x1].emplace_back(y1, y2);\n\
    \        }\n        else {\n            assert(y1 == y2);\n            if(x1 >\
    \ x2) std::swap(x1, x2);\n            ymap[x1].emplace_back(y1, 1);\n        \
    \    ymap[x2+1].emplace_back(y1, -1);\n        }\n    }\n    cp.build();\n   \
    \ std::sort(ret.begin(), ret.end());\n    ret.erase(std::unique(ret.begin(), ret.end()),\
    \ ret.end());\n    FenwickTree<i64> fw(cp.size());\n    i64 ans = 0;\n    for(auto\
    \ x: ret) {\n        for(auto [y, val]: ymap[x]) {\n            fw.add(cp.get(y),\
    \ val);\n        }\n        for(auto [low, high]: xmap[x]) {\n            ans\
    \ += fw.sum(cp.get(low), cp.get(high+1));\n        }\n    }\n    std::cout <<\
    \ ans << '\\n';\n}\n\n}\n\nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    ebi::main_();\n\
    }"
  dependsOn:
  - data_structure/compress.hpp
  - data_structure/FenwickTree.hpp
  isVerificationFile: true
  path: test/geometry/segment_intersection.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 15:56:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/segment_intersection.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/segment_intersection.test.cpp
- /verify/test/geometry/segment_intersection.test.cpp.html
title: test/geometry/segment_intersection.test.cpp
---