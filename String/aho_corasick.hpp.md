---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/aho_corasick.hpp\"\n\r\n#include <vector>\r\n#include\
    \ <cassert>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<int char_size, int margin>\r\
    \nstruct aho_corasick : trie<char_size+1, margin> {\r\nprivate:\r\n    void move_nxt(int\
    \ &now, int val) {\r\n        assert(0 <= val && val < char_size);\r\n       \
    \ while(this->nodes[now].nxt[val] == -1) now = this->nodes[now].nxt[FAIL];\r\n\
    \        now = this->nodes[now].nxt[val];\r\n        return;\r\n    }\r\n    using\
    \ trie<char_size + 1, margin>::trie;\r\n    using trie<char_size + 1, margin>::nodes;\r\
    \n\r\npublic:\r\n\r\n    void build() {\r\n        correct.resize(this->size());\r\
    \n        for(int i = 0; i < this->size(); ++i) {\r\n            correct[i] =\
    \ int(this->nodes[i].accept.size());\r\n        }\r\n        std::queue<int> que;\r\
    \n        for(int i = 0; i <= char_size; ++i) {\r\n            if(this->nodes[0].nxt[i]\
    \ != -1) {\r\n                this->nodes[this->nodes[0].nxt[i]].nxt[FAIL] = 0;\r\
    \n                que.push(this->nodes[0].nxt[i]);\r\n            } else {\r\n\
    \                this->nodes[0].nxt[i] = 0;\r\n            }\r\n        }\r\n\
    \        while(!que.empty()) {\r\n            int idx = que.front();\r\n     \
    \       que.pop();\r\n            auto &now = this->nodes[idx];\r\n          \
    \  correct[idx] += correct[now.nxt[FAIL]];\r\n            for(int i = 0; i < char_size;\
    \ ++i) {\r\n                if(now.nxt[i] == -1) continue;\r\n               \
    \ int fail = now.nxt[FAIL];\r\n                while(this->nodes[fail].nxt[i]\
    \ == -1) fail = this->nodes[fail].nxt[FAIL];\r\n                this->nodes[now.nxt[i]].nxt[FAIL]\
    \ = this->nodes[fail].nxt[i];\r\n                std::vector<int> &u = this->nodes[now.nxt[i]].accept;\r\
    \n                std::vector<int> &v = this->nodes[this->nodes[fail].nxt[i]].accept;\r\
    \n                std::vector<int> accept;\r\n                std::set_union(u.begin(),\
    \ u.end(), v.begin(), v.end(), std::back_inserter(accept));\r\n              \
    \  u = accept;\r\n                que.push(now.nxt[i]);\r\n            }\r\n \
    \       }\r\n    }\r\n\r\n    std::map<int, int> match(const std::string &str,\
    \ int now = 0) {\r\n        std::map<int, int> map;\r\n        for(const auto\
    \ &c: str) {\r\n            move_nxt(now, c - margin);\r\n            for(const\
    \ auto &a: this->nodes[now].accept) {\r\n                map[a]++;\r\n       \
    \     }\r\n        }\r\n        return map;\r\n    }\r\n\r\n    std::pair<int,int>\
    \ move(const char &c, int now) {\r\n        int sum = 0;\r\n        move_nxt(now,\
    \ c - margin);\r\n        sum += correct[now];\r\n        return {sum, now};\r\
    \n    }\r\nprivate:\r\n    const int FAIL = char_size;\r\n    std::vector<int>\
    \ correct;\r\n};\r\n\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <cassert>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<int char_size, int margin>\r\nstruct aho_corasick : trie<char_size+1,\
    \ margin> {\r\nprivate:\r\n    void move_nxt(int &now, int val) {\r\n        assert(0\
    \ <= val && val < char_size);\r\n        while(this->nodes[now].nxt[val] == -1)\
    \ now = this->nodes[now].nxt[FAIL];\r\n        now = this->nodes[now].nxt[val];\r\
    \n        return;\r\n    }\r\n    using trie<char_size + 1, margin>::trie;\r\n\
    \    using trie<char_size + 1, margin>::nodes;\r\n\r\npublic:\r\n\r\n    void\
    \ build() {\r\n        correct.resize(this->size());\r\n        for(int i = 0;\
    \ i < this->size(); ++i) {\r\n            correct[i] = int(this->nodes[i].accept.size());\r\
    \n        }\r\n        std::queue<int> que;\r\n        for(int i = 0; i <= char_size;\
    \ ++i) {\r\n            if(this->nodes[0].nxt[i] != -1) {\r\n                this->nodes[this->nodes[0].nxt[i]].nxt[FAIL]\
    \ = 0;\r\n                que.push(this->nodes[0].nxt[i]);\r\n            } else\
    \ {\r\n                this->nodes[0].nxt[i] = 0;\r\n            }\r\n       \
    \ }\r\n        while(!que.empty()) {\r\n            int idx = que.front();\r\n\
    \            que.pop();\r\n            auto &now = this->nodes[idx];\r\n     \
    \       correct[idx] += correct[now.nxt[FAIL]];\r\n            for(int i = 0;\
    \ i < char_size; ++i) {\r\n                if(now.nxt[i] == -1) continue;\r\n\
    \                int fail = now.nxt[FAIL];\r\n                while(this->nodes[fail].nxt[i]\
    \ == -1) fail = this->nodes[fail].nxt[FAIL];\r\n                this->nodes[now.nxt[i]].nxt[FAIL]\
    \ = this->nodes[fail].nxt[i];\r\n                std::vector<int> &u = this->nodes[now.nxt[i]].accept;\r\
    \n                std::vector<int> &v = this->nodes[this->nodes[fail].nxt[i]].accept;\r\
    \n                std::vector<int> accept;\r\n                std::set_union(u.begin(),\
    \ u.end(), v.begin(), v.end(), std::back_inserter(accept));\r\n              \
    \  u = accept;\r\n                que.push(now.nxt[i]);\r\n            }\r\n \
    \       }\r\n    }\r\n\r\n    std::map<int, int> match(const std::string &str,\
    \ int now = 0) {\r\n        std::map<int, int> map;\r\n        for(const auto\
    \ &c: str) {\r\n            move_nxt(now, c - margin);\r\n            for(const\
    \ auto &a: this->nodes[now].accept) {\r\n                map[a]++;\r\n       \
    \     }\r\n        }\r\n        return map;\r\n    }\r\n\r\n    std::pair<int,int>\
    \ move(const char &c, int now) {\r\n        int sum = 0;\r\n        move_nxt(now,\
    \ c - margin);\r\n        sum += correct[now];\r\n        return {sum, now};\r\
    \n    }\r\nprivate:\r\n    const int FAIL = char_size;\r\n    std::vector<int>\
    \ correct;\r\n};\r\n\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: String/aho_corasick.hpp
  requiredBy: []
  timestamp: '2021-08-24 18:32:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/aho_corasick.hpp
layout: document
redirect_from:
- /library/String/aho_corasick.hpp
- /library/String/aho_corasick.hpp.html
title: String/aho_corasick.hpp
---
