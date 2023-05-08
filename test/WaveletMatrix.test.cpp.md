---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/WaveletMatrix.hpp
    title: WaveletMatrix
  - icon: ':x:'
    path: data_structure/bitVector.hpp
    title: data_structure/bitVector.hpp
  - icon: ':question:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/WaveletMatrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\
    \r\n\r\n#line 2 \"data_structure/WaveletMatrix.hpp\"\n\r\n#line 2 \"data_structure/bitVector.hpp\"\
    \n\r\n#line 2 \"utility/int_alias.hpp\"\n\r\n#include <cstddef>\r\n#include <cstdint>\r\
    \n\r\nusing i32 = std::int32_t;\r\nusing i64 = std::int64_t;\r\nusing u16 = std::uint16_t;\r\
    \nusing u32 = std::uint32_t;\r\nusing u64 = std::uint64_t;\r\nusing usize = std::size_t;\n\
    #line 4 \"data_structure/bitVector.hpp\"\n\r\n/*\r\n    reference: https://misteer.hatenablog.com/entry/bit-vector\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nstruct bitVector {\r\
    \n    u32 length, cn, bn;\r\n    static u32 cw,\r\n        bw;  // chunk, block\
    \ \u306E\u9577\u3055 cw = (lg N)^2, bw = (lg N)/2 \u3068\u3059\u308B.\r\n    std::vector<u16>\
    \ bit;\r\n    std::vector<u32> chunk;\r\n    std::vector<std::vector<u16>> blocks;\r\
    \n\r\n    bitVector(int n) : length(n) {\r\n        cn = (length + cw - 1) / cw;\r\
    \n        bn = cw / bw;\r\n        bit.assign(cn * bn, 0);\r\n        chunk.assign(cn\
    \ + 1, 0);\r\n        blocks.assign(cn, std::vector<u16>(bn, 0));\r\n    }\r\n\
    \r\n    void set(int k, int b) {\r\n        u32 i = k / bw;\r\n        u32 j =\
    \ k % bw;\r\n        if (b == 0) {\r\n            bit[i] &= ~(1 << j);\r\n   \
    \     } else if (b == 1) {\r\n            bit[i] |= (1 << j);\r\n        }\r\n\
    \    }\r\n\r\n    int access(int k) {\r\n        u32 i = k / bw;\r\n        u32\
    \ j = k % bw;\r\n        return bit[i] >> j & 1;\r\n    }\r\n\r\n    void build()\
    \ {\r\n        chunk[0] = 0;\r\n        for (u32 i = 0; i < cn; i++) {\r\n   \
    \         blocks[i][0] = 0;\r\n            for (u32 j = 0; j < bn - 1; j++) {\r\
    \n                blocks[i][j + 1] =\r\n                    blocks[i][j] + __builtin_popcount(bit[i\
    \ * bn + j]);\r\n            }\r\n            chunk[i + 1] = chunk[i] + blocks[i][bn\
    \ - 1] +\r\n                           __builtin_popcount(bit[(i + 1) * bn - 1]);\r\
    \n        }\r\n    }\r\n\r\n    // [0, r)\u306B\u5B58\u5728\u3059\u308B1\u306E\
    \u6570\u3092O(1)\u3067\u8A08\u7B97\u3059\u308B.\r\n    int rank(int r) {\r\n \
    \       u32 i = r / cw;\r\n        u32 j = (r % cw) / bw;\r\n        u32 k = r\
    \ % bw;\r\n        u32 leftover = bit[i * bn + j] & ((1 << k) - 1);\r\n      \
    \  if (i == cn) return chunk[i];\r\n        return chunk[i] + blocks[i][j] + __builtin_popcount(leftover);\r\
    \n    }\r\n\r\n    int select(int k) {\r\n        if (k == 0) return 0;\r\n  \
    \      if (rank(length) < k) return -1;\r\n        u32 l = 0;\r\n        u32 r\
    \ = length;\r\n        while (r - l > 1) {\r\n            u32 mid = (r + l) /\
    \ 2;\r\n            if (rank(mid) >= k) {\r\n                r = mid;\r\n    \
    \        } else {\r\n                l = mid;\r\n            }\r\n        }\r\n\
    \        return r;\r\n    }\r\n\r\n    int select0(int k) {\r\n        if (k ==\
    \ 0) return 0;\r\n        if (length - rank(length) < (u32)k) return -1;\r\n \
    \       u32 l = 0;\r\n        u32 r = length;\r\n        while (r - l > 1) {\r\
    \n            u32 mid = (r + l) / 2;\r\n            if (mid - rank(mid) >= (u32)k)\
    \ {\r\n                r = mid;\r\n            } else {\r\n                l =\
    \ mid;\r\n            }\r\n        }\r\n        return r;\r\n    }\r\n};\r\n\r\
    \nu32 bitVector::cw = 1024;\r\nu32 bitVector::bw = 16;\r\n\r\n}  // namespace\
    \ ebi\n#line 4 \"data_structure/WaveletMatrix.hpp\"\n\r\n/*\r\n    reference:\
    \ https://miti-7.hatenablog.com/entry/2018/04/28/152259\r\n*/\r\n\r\n#include\
    \ <limits>\r\n#include <map>\r\n#line 12 \"data_structure/WaveletMatrix.hpp\"\n\
    \r\nnamespace ebi {\r\n\r\ntemplate <class T> struct WaveletMatrix {\r\n  private:\r\
    \n    int wordsize = std::numeric_limits<T>::digits;\r\n    int n;\r\n    std::vector<bitVector>\
    \ mat;\r\n    std::vector<int> border;\r\n    std::map<T, int> map;\r\n\r\n  public:\r\
    \n    WaveletMatrix(std::vector<T> v)\r\n        : n(v.size()), mat(wordsize,\
    \ bitVector(n)), border(wordsize) {\r\n        for (int bit = wordsize - 1; bit\
    \ >= 0; --bit) {\r\n            std::vector<T> one, zero;\r\n            zero.reserve(n);\r\
    \n            for (int i = 0; i < n; ++i) {\r\n                if (v[i] & ((T)1\
    \ << bit)) {\r\n                    one.emplace_back(v[i]);\r\n              \
    \      mat[bit].set(i, 1);\r\n                } else {\r\n                   \
    \ zero.emplace_back(v[i]);\r\n                }\r\n            }\r\n         \
    \   border[bit] = zero.size();\r\n            mat[bit].build();\r\n          \
    \  std::copy(one.begin(), one.end(), std::back_inserter(zero));\r\n          \
    \  v = zero;\r\n        }\r\n        for (int i = 0; i < n; i++) {\r\n       \
    \     if (map[v[i]] == 0) {\r\n                map[v[i]] = i;\r\n            }\r\
    \n        }\r\n    }\r\n\r\n    T access(int i) {\r\n        T val = 0;\r\n  \
    \      int k = i;\r\n        for (int bit = wordsize - 1; bit >= 0; --bit) {\r\
    \n            if (mat[bit].access(k) == 1) {\r\n                val |= ((T)1 <<\
    \ bit);\r\n                k = border[bit] + mat[bit].rank(k);\r\n           \
    \ } else {\r\n                k = k - mat[bit].rank(k);\r\n            }\r\n \
    \       }\r\n        return val;\r\n    }\r\n\r\n    int rank(int r, T x) {\r\n\
    \        int k = r;\r\n        for (int bit = wordsize - 1; bit >= 0; --bit) {\r\
    \n            if (x & ((T)1 << bit)) {\r\n                k = border[bit] + mat[bit].rank(k);\r\
    \n            } else {\r\n                k = k - mat[bit].rank(k);\r\n      \
    \      }\r\n        }\r\n        return k - map[x];\r\n    }\r\n\r\n    int select(T\
    \ x, int k) {\r\n        k = map[x] + k;\r\n        for (int bit = 0; bit < wordsize;\
    \ ++bit) {\r\n            if (x & ((T)1 << bit)) {\r\n                k = mat[bit].select(k\
    \ - border[bit]);\r\n            } else {\r\n                k = mat[bit].select0(k);\r\
    \n            }\r\n        }\r\n        return k - 1;\r\n    }\r\n\r\n    T quantile(int\
    \ l, int r, int k) {\r\n        T val = 0;\r\n        for (int bit = wordsize\
    \ - 1; bit >= 0; --bit) {\r\n            int rank_l = mat[bit].rank(l);\r\n  \
    \          int rank_r = mat[bit].rank(r);\r\n            int one = rank_r - rank_l;\r\
    \n            int zero = r - l - one;\r\n            if (k <= zero) {\r\n    \
    \            l -= rank_l;\r\n                r -= rank_r;\r\n            } else\
    \ {\r\n                val |= (T)1 << bit;\r\n                l = border[bit]\
    \ + rank_l;\r\n                r = border[bit] + rank_r;\r\n                k\
    \ -= zero;\r\n            }\r\n        }\r\n        return val;\r\n    }\r\n};\r\
    \n\r\n}  // namespace ebi\n#line 4 \"test/WaveletMatrix.test.cpp\"\n\r\n#include\
    \ <iostream>\r\n#line 7 \"test/WaveletMatrix.test.cpp\"\n\r\n#line 9 \"test/WaveletMatrix.test.cpp\"\
    \n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<i64>\
    \ a(n);\r\n    for (int i = 0; i < n; i++) {\r\n        std::cin >> a[i];\r\n\
    \    }\r\n    ebi::WaveletMatrix<i64> wm(a);\r\n    while (q--) {\r\n        int\
    \ l, r, k;\r\n        std::cin >> l >> r >> k;\r\n        std::cout << wm.quantile(l,\
    \ r, k + 1) << std::endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\r\n\
    \r\n#include \"../data_structure/WaveletMatrix.hpp\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n\r\n#include \"../utility/int_alias.hpp\"\r\n\r\nint main()\
    \ {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        std::cin >> a[i];\r\n    }\r\n\
    \    ebi::WaveletMatrix<i64> wm(a);\r\n    while (q--) {\r\n        int l, r,\
    \ k;\r\n        std::cin >> l >> r >> k;\r\n        std::cout << wm.quantile(l,\
    \ r, k + 1) << std::endl;\r\n    }\r\n}"
  dependsOn:
  - data_structure/WaveletMatrix.hpp
  - data_structure/bitVector.hpp
  - utility/int_alias.hpp
  isVerificationFile: true
  path: test/WaveletMatrix.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/WaveletMatrix.test.cpp
layout: document
redirect_from:
- /verify/test/WaveletMatrix.test.cpp
- /verify/test/WaveletMatrix.test.cpp.html
title: test/WaveletMatrix.test.cpp
---
