---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://misteer.hatenablog.com/entry/bit-vector
  bundledCode: "#line 2 \"data_structure/bitVector.hpp\"\n\r\n#line 2 \"utility/int_alias.hpp\"\
    \n\r\n#include <cstddef>\r\n#include <cstdint>\r\n\r\nusing i32 = std::int32_t;\r\
    \nusing i64 = std::int64_t;\r\nusing u32 = std::uint32_t;\r\nusing u64 = std::uint64_t;\r\
    \nusing usize = std::size_t;\n#line 4 \"data_structure/bitVector.hpp\"\n\r\n/*\r\
    \n    reference: https://misteer.hatenablog.com/entry/bit-vector\r\n*/\r\n\r\n\
    #include <vector>\r\n\r\nstruct bitVector {\r\n    u32 length, cn, bn;\r\n   \
    \ static u32 cw, bw; // chunk, block \u306E\u9577\u3055 cw = (lg N)^2, bw = (lg\
    \ N)/2 \u3068\u3059\u308B.\r\n    std::vector<u16> bit;\r\n    std::vector<u32>\
    \ chunk;\r\n    std::vector<std::vector<u16>> blocks;\r\n\r\n    bitVector(int\
    \ n) : length(n) {\r\n        cn = (length+cw-1)/cw;\r\n        bn = cw/bw;\r\n\
    \        bit.assign(cn*bn, 0);\r\n        chunk.assign(cn+1,0);\r\n        blocks.assign(cn,\
    \ std::vector<u16>(bn, 0));\r\n    }\r\n\r\n    void set(int k, int b) {\r\n \
    \       u32 i = k/bw;\r\n        u32 j = k%bw;\r\n        if(b == 0) {\r\n   \
    \         bit[i] &= ~(1<<j);\r\n        }\r\n        else if(b == 1) {\r\n   \
    \         bit[i] |= (1<<j);\r\n        }\r\n    }\r\n\r\n    int access(int k)\
    \ {\r\n        u32 i = k/bw;\r\n        u32 j = k%bw;\r\n        return bit[i]\
    \ >> j & 1;\r\n    }\r\n\r\n    void build() {\r\n        chunk[0] = 0;\r\n  \
    \      for(u32 i = 0; i<cn; i++) {\r\n            blocks[i][0] = 0;\r\n      \
    \      for(u32 j = 0; j<bn-1; j++) {\r\n                blocks[i][j+1] = blocks[i][j]\
    \ + __builtin_popcount(bit[i*bn + j]);\r\n            }\r\n            chunk[i+1]\
    \ = chunk[i] + blocks[i][bn-1] + __builtin_popcount(bit[(i+1)*bn -1]);\r\n   \
    \     }\r\n    }\r\n\r\n    // [0, r)\u306B\u5B58\u5728\u3059\u308B1\u306E\u6570\
    \u3092O(1)\u3067\u8A08\u7B97\u3059\u308B.\r\n    int rank(int r) {\r\n       \
    \ u32 i = r/cw;\r\n        u32 j = (r%cw)/bw;\r\n        u32 k = r%bw;\r\n   \
    \     u32 leftover = bit[i*bn + j] & ((1<<k) - 1);\r\n        if(i == cn) return\
    \ chunk[i];\r\n        return chunk[i] + blocks[i][j] + __builtin_popcount(leftover);\r\
    \n    }\r\n\r\n    int select(int k) {\r\n        if(k == 0) return 0;\r\n   \
    \     if(rank(length) < k) return -1;\r\n        u32 l = 0;\r\n        u32 r =\
    \ length;\r\n        while(r-l>1) {\r\n            u32 mid = (r+l)/2;\r\n    \
    \        if(rank(mid) >= k) {\r\n                r = mid;\r\n            }\r\n\
    \            else {\r\n                l = mid;\r\n            }\r\n        }\r\
    \n        return r;\r\n    }\r\n};\r\n\r\nu32 bitVector::cw = 1024;\r\nu32 bitVector::bw\
    \ = 16;\n"
  code: "#pragma once\r\n\r\n#include \"../utility/int_alias.hpp\"\r\n\r\n/*\r\n \
    \   reference: https://misteer.hatenablog.com/entry/bit-vector\r\n*/\r\n\r\n#include\
    \ <vector>\r\n\r\nstruct bitVector {\r\n    u32 length, cn, bn;\r\n    static\
    \ u32 cw, bw; // chunk, block \u306E\u9577\u3055 cw = (lg N)^2, bw = (lg N)/2\
    \ \u3068\u3059\u308B.\r\n    std::vector<u16> bit;\r\n    std::vector<u32> chunk;\r\
    \n    std::vector<std::vector<u16>> blocks;\r\n\r\n    bitVector(int n) : length(n)\
    \ {\r\n        cn = (length+cw-1)/cw;\r\n        bn = cw/bw;\r\n        bit.assign(cn*bn,\
    \ 0);\r\n        chunk.assign(cn+1,0);\r\n        blocks.assign(cn, std::vector<u16>(bn,\
    \ 0));\r\n    }\r\n\r\n    void set(int k, int b) {\r\n        u32 i = k/bw;\r\
    \n        u32 j = k%bw;\r\n        if(b == 0) {\r\n            bit[i] &= ~(1<<j);\r\
    \n        }\r\n        else if(b == 1) {\r\n            bit[i] |= (1<<j);\r\n\
    \        }\r\n    }\r\n\r\n    int access(int k) {\r\n        u32 i = k/bw;\r\n\
    \        u32 j = k%bw;\r\n        return bit[i] >> j & 1;\r\n    }\r\n\r\n   \
    \ void build() {\r\n        chunk[0] = 0;\r\n        for(u32 i = 0; i<cn; i++)\
    \ {\r\n            blocks[i][0] = 0;\r\n            for(u32 j = 0; j<bn-1; j++)\
    \ {\r\n                blocks[i][j+1] = blocks[i][j] + __builtin_popcount(bit[i*bn\
    \ + j]);\r\n            }\r\n            chunk[i+1] = chunk[i] + blocks[i][bn-1]\
    \ + __builtin_popcount(bit[(i+1)*bn -1]);\r\n        }\r\n    }\r\n\r\n    //\
    \ [0, r)\u306B\u5B58\u5728\u3059\u308B1\u306E\u6570\u3092O(1)\u3067\u8A08\u7B97\
    \u3059\u308B.\r\n    int rank(int r) {\r\n        u32 i = r/cw;\r\n        u32\
    \ j = (r%cw)/bw;\r\n        u32 k = r%bw;\r\n        u32 leftover = bit[i*bn +\
    \ j] & ((1<<k) - 1);\r\n        if(i == cn) return chunk[i];\r\n        return\
    \ chunk[i] + blocks[i][j] + __builtin_popcount(leftover);\r\n    }\r\n\r\n   \
    \ int select(int k) {\r\n        if(k == 0) return 0;\r\n        if(rank(length)\
    \ < k) return -1;\r\n        u32 l = 0;\r\n        u32 r = length;\r\n       \
    \ while(r-l>1) {\r\n            u32 mid = (r+l)/2;\r\n            if(rank(mid)\
    \ >= k) {\r\n                r = mid;\r\n            }\r\n            else {\r\
    \n                l = mid;\r\n            }\r\n        }\r\n        return r;\r\
    \n    }\r\n};\r\n\r\nu32 bitVector::cw = 1024;\r\nu32 bitVector::bw = 16;"
  dependsOn:
  - utility/int_alias.hpp
  isVerificationFile: false
  path: data_structure/bitVector.hpp
  requiredBy: []
  timestamp: '2021-01-12 17:51:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/bitVector.hpp
layout: document
redirect_from:
- /library/data_structure/bitVector.hpp
- /library/data_structure/bitVector.hpp.html
title: data_structure/bitVector.hpp
---
