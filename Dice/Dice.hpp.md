---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Dice/dice1.test.cpp
    title: test/Dice/dice1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dice/dice2.test.cpp
    title: test/Dice/dice2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dice/dice3.test.cpp
    title: test/Dice/dice3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dice/dice4.test.cpp
    title: test/Dice/dice4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Dice/Dice.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    #include <cassert>\n\nnamespace ebi {\n\nconst std::vector<std::vector<int>> alldice\
    \ = { \n    { 0, 1, 2, 3, 4, 5 },\n    { 3, 1, 0, 5, 4, 2 },\n    { 5, 1, 3, 2,\
    \ 4, 0 },\n    { 2, 1, 5, 0, 4, 3 },\n    { 1, 5, 2, 3, 0, 4 },\n    { 3, 5, 1,\
    \ 4, 0, 2 },\n    { 4, 5, 3, 2, 0, 1 },\n    { 2, 5, 4, 1, 0, 3 },\n    { 4, 0,\
    \ 2, 3, 5, 1 },\n    { 3, 0, 4, 1, 5, 2 },\n    { 1, 0, 3, 2, 5, 4 },\n    { 2,\
    \ 0, 1, 4, 5, 3 },\n    { 5, 4, 2, 3, 1, 0 },\n    { 3, 4, 5, 0, 1, 2 },\n   \
    \ { 0, 4, 3, 2, 1, 5 },\n    { 2, 4, 0, 5, 1, 3 },\n    { 0, 3, 1, 4, 2, 5 },\n\
    \    { 4, 3, 0, 5, 2, 1 },\n    { 5, 3, 4, 1, 2, 0 },\n    { 1, 3, 5, 0, 2, 4\
    \ },\n    { 0, 2, 4, 1, 3, 5 },\n    { 1, 2, 0, 5, 3, 4 },\n    { 5, 2, 1, 4,\
    \ 3, 0 },\n    { 4, 2, 5, 0, 3, 1}\n};\n\nstruct Dice {\nprivate:\n    int up\
    \ = 0, front = 1, right = 2, left = 3, back = 4, down = 5;\npublic:\n    Dice()\
    \ = default;\n\n    void setval(const std::vector<int> &_val) {\n        assert(int(_val.size())\
    \ == 6);\n        val = _val;\n    }\n\n    // y++\n    void rollN() {\n     \
    \   int buff = down;\n        down = back;\n        back = up;\n        up = front;\n\
    \        front = buff;\n    }\n\n    // y--\n    void rollS() {\n        int buff\
    \ = down;\n        down = front;\n        front = up;\n        up = back;\n  \
    \      back = buff;\n    }\n\n    // x++\n    void rollE() {\n        int buff\
    \ = down;\n        down = right;\n        right = up;\n        up = left;\n  \
    \      left = buff;\n    }\n\n    // x--\n    void rollW() {\n        int buff\
    \ = down;\n        down = left;\n        left = up;\n        up = right;\n   \
    \     right = buff;\n    }\n\n    // \u53F3\u56DE\u8EE2(\u6642\u8A08\u56DE\u308A\
    )\n    void rollR() {\n        int buff = right;\n        right = back;\n    \
    \    back = left;\n        left = front;\n        front = buff;\n    }\n\n   \
    \ // \u5DE6\u56DE\u8EE2(\u53CD\u6642\u8A08\u56DE\u308A)\n    void rollL() {\n\
    \        int buff = left;\n        left = back;\n        back = right;\n     \
    \   right = front;\n        front = buff;\n    }\n\n    void roll(char c) {\n\
    \        if(c == 'N') rollN(); \n        else if(c == 'S') rollS();\n        else\
    \ if(c == 'E') rollE();\n        else if(c == 'W') rollW();\n        else if(c\
    \ == 'R') rollR();\n        else if(c == 'L') rollL();\n        else assert(0);\n\
    \    }\n\n    int get_index(int x) const {\n        for(int i = 0; i < 6; i++)\
    \ {\n            if(val[i] == x) return i;\n        }\n        assert(0);\n  \
    \  }\n\n    void set(int u, int f) {\n        for(const auto &v: alldice) {\n\
    \            if(v[0] == u && v[1] == f) {\n                up = v[0]; \n     \
    \           front = v[1];\n                right = v[2];\n                left\
    \ = v[3];\n                back = v[4];\n                down = v[5];\n      \
    \          return;\n            }\n        }\n        assert(0);\n    }\n\n  \
    \  std::vector<Dice> makeDice() const {\n        std::vector<Dice> ret;\n    \
    \    for(int i = 0; i < 6; i++) {\n            Dice d(*this);\n            if(i\
    \ == 1) d.rollN();\n            if(i == 2) d.rollS();\n            if(i == 3)\
    \ { d.rollS(); d.rollS(); }\n            if(i == 4) d.rollL();\n            if(i\
    \ == 5) d.rollR();\n            for(int j = 0; j < 4; j++) {\n               \
    \ ret.emplace_back(d);\n                d.rollE();\n            }\n        }\n\
    \        return ret;\n    }\n\n    int top_val() const {\n        return val[up];\n\
    \    }\n\n    int right_val() const {\n        return val[right];\n    }\n\n \
    \   int left_val() const {\n        return val[left];\n    }\n\n    int front_val()\
    \ const {\n        return val[front];\n    }\n\n    int back_val() const {\n \
    \       return val[back];\n    }\n\n    int down_val() const {\n        return\
    \ val[down];\n    }\n\n    std::vector<int> now() const {\n        std::vector<int>\
    \ ret(6);\n        ret[0] = top_val();\n        ret[1] = front_val();\n      \
    \  ret[2] = right_val();\n        ret[3] = left_val();\n        ret[4] = back_val();\n\
    \        ret[5] = down_val();\n        return ret;\n    }\n\n    bool operator==(const\
    \ Dice &rhs) const noexcept {\n        std::vector<int> ret(6);\n        for(const\
    \ auto &idx: alldice) {\n            for(int i = 0; i < 6; i++) {\n          \
    \      ret[i] = val[idx[i]];\n            }\n            if(ret == rhs.val) return\
    \ true;\n        }\n        return false;\n    }\n\n    std::vector<int> val =\
    \ {0, 1, 2, 3, 4, 5};\n};\n\nstd::istream& operator>>(std::istream& os, Dice &d)\
    \ {\n    return os >> d.val[0] >> d.val[1] >> d.val[2] >> d.val[3] >> d.val[4]\
    \ >> d.val[5];  \n}\n\n}\n"
  code: "#pragma once\n\n#include <iostream>\n#include <vector>\n#include <cassert>\n\
    \nnamespace ebi {\n\nconst std::vector<std::vector<int>> alldice = { \n    { 0,\
    \ 1, 2, 3, 4, 5 },\n    { 3, 1, 0, 5, 4, 2 },\n    { 5, 1, 3, 2, 4, 0 },\n   \
    \ { 2, 1, 5, 0, 4, 3 },\n    { 1, 5, 2, 3, 0, 4 },\n    { 3, 5, 1, 4, 0, 2 },\n\
    \    { 4, 5, 3, 2, 0, 1 },\n    { 2, 5, 4, 1, 0, 3 },\n    { 4, 0, 2, 3, 5, 1\
    \ },\n    { 3, 0, 4, 1, 5, 2 },\n    { 1, 0, 3, 2, 5, 4 },\n    { 2, 0, 1, 4,\
    \ 5, 3 },\n    { 5, 4, 2, 3, 1, 0 },\n    { 3, 4, 5, 0, 1, 2 },\n    { 0, 4, 3,\
    \ 2, 1, 5 },\n    { 2, 4, 0, 5, 1, 3 },\n    { 0, 3, 1, 4, 2, 5 },\n    { 4, 3,\
    \ 0, 5, 2, 1 },\n    { 5, 3, 4, 1, 2, 0 },\n    { 1, 3, 5, 0, 2, 4 },\n    { 0,\
    \ 2, 4, 1, 3, 5 },\n    { 1, 2, 0, 5, 3, 4 },\n    { 5, 2, 1, 4, 3, 0 },\n   \
    \ { 4, 2, 5, 0, 3, 1}\n};\n\nstruct Dice {\nprivate:\n    int up = 0, front =\
    \ 1, right = 2, left = 3, back = 4, down = 5;\npublic:\n    Dice() = default;\n\
    \n    void setval(const std::vector<int> &_val) {\n        assert(int(_val.size())\
    \ == 6);\n        val = _val;\n    }\n\n    // y++\n    void rollN() {\n     \
    \   int buff = down;\n        down = back;\n        back = up;\n        up = front;\n\
    \        front = buff;\n    }\n\n    // y--\n    void rollS() {\n        int buff\
    \ = down;\n        down = front;\n        front = up;\n        up = back;\n  \
    \      back = buff;\n    }\n\n    // x++\n    void rollE() {\n        int buff\
    \ = down;\n        down = right;\n        right = up;\n        up = left;\n  \
    \      left = buff;\n    }\n\n    // x--\n    void rollW() {\n        int buff\
    \ = down;\n        down = left;\n        left = up;\n        up = right;\n   \
    \     right = buff;\n    }\n\n    // \u53F3\u56DE\u8EE2(\u6642\u8A08\u56DE\u308A\
    )\n    void rollR() {\n        int buff = right;\n        right = back;\n    \
    \    back = left;\n        left = front;\n        front = buff;\n    }\n\n   \
    \ // \u5DE6\u56DE\u8EE2(\u53CD\u6642\u8A08\u56DE\u308A)\n    void rollL() {\n\
    \        int buff = left;\n        left = back;\n        back = right;\n     \
    \   right = front;\n        front = buff;\n    }\n\n    void roll(char c) {\n\
    \        if(c == 'N') rollN(); \n        else if(c == 'S') rollS();\n        else\
    \ if(c == 'E') rollE();\n        else if(c == 'W') rollW();\n        else if(c\
    \ == 'R') rollR();\n        else if(c == 'L') rollL();\n        else assert(0);\n\
    \    }\n\n    int get_index(int x) const {\n        for(int i = 0; i < 6; i++)\
    \ {\n            if(val[i] == x) return i;\n        }\n        assert(0);\n  \
    \  }\n\n    void set(int u, int f) {\n        for(const auto &v: alldice) {\n\
    \            if(v[0] == u && v[1] == f) {\n                up = v[0]; \n     \
    \           front = v[1];\n                right = v[2];\n                left\
    \ = v[3];\n                back = v[4];\n                down = v[5];\n      \
    \          return;\n            }\n        }\n        assert(0);\n    }\n\n  \
    \  std::vector<Dice> makeDice() const {\n        std::vector<Dice> ret;\n    \
    \    for(int i = 0; i < 6; i++) {\n            Dice d(*this);\n            if(i\
    \ == 1) d.rollN();\n            if(i == 2) d.rollS();\n            if(i == 3)\
    \ { d.rollS(); d.rollS(); }\n            if(i == 4) d.rollL();\n            if(i\
    \ == 5) d.rollR();\n            for(int j = 0; j < 4; j++) {\n               \
    \ ret.emplace_back(d);\n                d.rollE();\n            }\n        }\n\
    \        return ret;\n    }\n\n    int top_val() const {\n        return val[up];\n\
    \    }\n\n    int right_val() const {\n        return val[right];\n    }\n\n \
    \   int left_val() const {\n        return val[left];\n    }\n\n    int front_val()\
    \ const {\n        return val[front];\n    }\n\n    int back_val() const {\n \
    \       return val[back];\n    }\n\n    int down_val() const {\n        return\
    \ val[down];\n    }\n\n    std::vector<int> now() const {\n        std::vector<int>\
    \ ret(6);\n        ret[0] = top_val();\n        ret[1] = front_val();\n      \
    \  ret[2] = right_val();\n        ret[3] = left_val();\n        ret[4] = back_val();\n\
    \        ret[5] = down_val();\n        return ret;\n    }\n\n    bool operator==(const\
    \ Dice &rhs) const noexcept {\n        std::vector<int> ret(6);\n        for(const\
    \ auto &idx: alldice) {\n            for(int i = 0; i < 6; i++) {\n          \
    \      ret[i] = val[idx[i]];\n            }\n            if(ret == rhs.val) return\
    \ true;\n        }\n        return false;\n    }\n\n    std::vector<int> val =\
    \ {0, 1, 2, 3, 4, 5};\n};\n\nstd::istream& operator>>(std::istream& os, Dice &d)\
    \ {\n    return os >> d.val[0] >> d.val[1] >> d.val[2] >> d.val[3] >> d.val[4]\
    \ >> d.val[5];  \n}\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: Dice/Dice.hpp
  requiredBy: []
  timestamp: '2023-05-08 14:32:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Dice/dice3.test.cpp
  - test/Dice/dice2.test.cpp
  - test/Dice/dice4.test.cpp
  - test/Dice/dice1.test.cpp
documentation_of: Dice/Dice.hpp
layout: document
redirect_from:
- /library/Dice/Dice.hpp
- /library/Dice/Dice.hpp.html
title: Dice/Dice.hpp
---
