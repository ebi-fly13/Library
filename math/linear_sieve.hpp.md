---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/pow.hpp
    title: math/pow.hpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://37zigen.com/linear-sieve/
  bundledCode: "#line 2 \"math/linear_sieve.hpp\"\n\r\n#line 2 \"math/pow.hpp\"\n\r\
    \n#line 2 \"utility/int_alias.hpp\"\n\r\n#include <cstddef>\r\n#include <cstdint>\r\
    \n\r\nusing i32 = std::int32_t;\r\nusing i64 = std::int64_t;\r\nusing u16 = std::uint16_t;\r\
    \nusing u32 = std::uint32_t;\r\nusing u64 = std::uint64_t;\r\nusing usize = std::size_t;\n\
    #line 4 \"math/pow.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nT pow(T\
    \ x, u64 n, u64 mod = -1) {\r\n    T res = 1;\r\n    if(mod > 0) {\r\n       \
    \ while(n > 0) {\r\n            if(n&1) {\r\n                res *= x;\r\n   \
    \             res %= mod;\r\n            }\r\n            x = x*x;\r\n       \
    \     x %= mod;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\n\
    \    }\r\n    while(n > 0) {\r\n        if(n&1) {\r\n            res *= x;\r\n\
    \        }\r\n        x = x*x;\r\n        n >>= 1;\r\n    }\r\n    return res;\r\
    \n}\r\n\r\n}\n#line 5 \"math/linear_sieve.hpp\"\n\r\n/*\r\n    reference: https://37zigen.com/linear-sieve/\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nstruct linear_sieve\
    \ {\r\nprivate:\r\n    using u64 = std::uint64_t;\r\n    int n;\r\n    std::vector<int>\
    \ sieve;\r\n    std::vector<int> prime;\r\npublic:\r\n    linear_sieve(int _n)\
    \ : n(_n) , sieve(std::vector<int>(_n + 1, -1)){\r\n        for(int i = 2; i <=\
    \ n; i++) {\r\n            if(sieve[i] < 0) {\r\n                sieve[i] = i;\r\
    \n                prime.emplace_back(i);\r\n            }\r\n            for(auto\
    \ p : prime) {\r\n                if(u64(p)*u64(i) > u64(n) || p > sieve[i]) break;\r\
    \n                sieve[p*i] = p;\r\n            }\r\n        }\r\n    }\r\n\r\
    \n    std::vector<int> prime_table() {\r\n        return prime;\r\n    }\r\n\r\
    \n    std::vector<std::pair<int,int>> factorize(int n) {\r\n        std::vector<std::pair<int,int>>\
    \ res;\r\n        while(n > 1) {\r\n            int p = sieve[n];\r\n        \
    \    int exp = 0;\r\n            if(p < 0) {\r\n                res.emplace_back(n,\
    \ 1);\r\n                break;\r\n            }\r\n            while(sieve[n]\
    \ == p) {\r\n                n /= p;\r\n                exp++;\r\n           \
    \ }\r\n            res.emplace_back(p, exp);\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    std::vector<int> divisors(int n) {\r\n        std::vector<int>\
    \ res;\r\n        res.emplace_back(1);\r\n        auto pf = factorize(n);\r\n\
    \        for(auto p: pf) {\r\n            int sz = res.size();\r\n           \
    \ for(int i = 0; i < sz; i++) {\r\n                int ret = 1;\r\n          \
    \      for(int j = 0; j < p.second; j++) {\r\n                    ret *= p.first;\r\
    \n                    res.emplace_back(res[i] * ret);\r\n                }\r\n\
    \            }\r\n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<u64>\
    \ pow_table(int k, u64 mod) {\r\n        std::vector<u64> table(n+1,1);\r\n  \
    \      table[0] = 0;\r\n        for(int i = 2; i<= n; i++) {\r\n            if(sieve[i]\
    \ == i) {\r\n                table[i] = pow(u64(i), k, mod);\r\n             \
    \   continue;\r\n            }\r\n            table[i] = table[sieve[i]]*table[i/sieve[i]]%mod;\r\
    \n        }\r\n        return table;\r\n    }\r\n\r\n    std::vector<u64> inv_table(u64\
    \ mod) {\r\n        return pow_table(mod-2, mod);\r\n    }\r\n};\r\n\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"../math/pow.hpp\"\r\n#include \"../utility/int_alias.hpp\"\
    \r\n\r\n/*\r\n    reference: https://37zigen.com/linear-sieve/\r\n*/\r\n\r\n#include\
    \ <vector>\r\n\r\nnamespace ebi {\r\n\r\nstruct linear_sieve {\r\nprivate:\r\n\
    \    using u64 = std::uint64_t;\r\n    int n;\r\n    std::vector<int> sieve;\r\
    \n    std::vector<int> prime;\r\npublic:\r\n    linear_sieve(int _n) : n(_n) ,\
    \ sieve(std::vector<int>(_n + 1, -1)){\r\n        for(int i = 2; i <= n; i++)\
    \ {\r\n            if(sieve[i] < 0) {\r\n                sieve[i] = i;\r\n   \
    \             prime.emplace_back(i);\r\n            }\r\n            for(auto\
    \ p : prime) {\r\n                if(u64(p)*u64(i) > u64(n) || p > sieve[i]) break;\r\
    \n                sieve[p*i] = p;\r\n            }\r\n        }\r\n    }\r\n\r\
    \n    std::vector<int> prime_table() {\r\n        return prime;\r\n    }\r\n\r\
    \n    std::vector<std::pair<int,int>> factorize(int n) {\r\n        std::vector<std::pair<int,int>>\
    \ res;\r\n        while(n > 1) {\r\n            int p = sieve[n];\r\n        \
    \    int exp = 0;\r\n            if(p < 0) {\r\n                res.emplace_back(n,\
    \ 1);\r\n                break;\r\n            }\r\n            while(sieve[n]\
    \ == p) {\r\n                n /= p;\r\n                exp++;\r\n           \
    \ }\r\n            res.emplace_back(p, exp);\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    std::vector<int> divisors(int n) {\r\n        std::vector<int>\
    \ res;\r\n        res.emplace_back(1);\r\n        auto pf = factorize(n);\r\n\
    \        for(auto p: pf) {\r\n            int sz = res.size();\r\n           \
    \ for(int i = 0; i < sz; i++) {\r\n                int ret = 1;\r\n          \
    \      for(int j = 0; j < p.second; j++) {\r\n                    ret *= p.first;\r\
    \n                    res.emplace_back(res[i] * ret);\r\n                }\r\n\
    \            }\r\n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<u64>\
    \ pow_table(int k, u64 mod) {\r\n        std::vector<u64> table(n+1,1);\r\n  \
    \      table[0] = 0;\r\n        for(int i = 2; i<= n; i++) {\r\n            if(sieve[i]\
    \ == i) {\r\n                table[i] = pow(u64(i), k, mod);\r\n             \
    \   continue;\r\n            }\r\n            table[i] = table[sieve[i]]*table[i/sieve[i]]%mod;\r\
    \n        }\r\n        return table;\r\n    }\r\n\r\n    std::vector<u64> inv_table(u64\
    \ mod) {\r\n        return pow_table(mod-2, mod);\r\n    }\r\n};\r\n\r\n}\r\n"
  dependsOn:
  - math/pow.hpp
  - utility/int_alias.hpp
  isVerificationFile: false
  path: math/linear_sieve.hpp
  requiredBy: []
  timestamp: '2021-08-16 12:55:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear_sieve.hpp
layout: document
redirect_from:
- /library/math/linear_sieve.hpp
- /library/math/linear_sieve.hpp.html
title: math/linear_sieve.hpp
---
