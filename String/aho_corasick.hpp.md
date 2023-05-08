---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/trie.hpp
    title: String/trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2863.test.cpp
    title: test/aoj/aoj_2863.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2873.test.cpp
    title: test/aoj/aoj_2873.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/aho_corasick.hpp\"\n\r\n#include <vector>\r\n#include\
    \ <string.h>\r\n#include <queue>\r\n#include <algorithm>\r\n#include <map>\r\n\
    #include <cassert>\r\n\r\n#line 2 \"String/trie.hpp\"\n\r\n#line 4 \"String/trie.hpp\"\
    \n#include <string>\r\n#line 6 \"String/trie.hpp\"\n\r\nnamespace ebi {\r\n\r\n\
    namespace internal {\r\n\r\ntemplate<int char_size>\r\nstruct trie_node {\r\n\
    \    int common;\r\n    int nxt[char_size];\r\n    std::vector<int> accept;\r\n\
    \    trie_node() : common(0) {\r\n        memset(nxt, -1, sizeof(nxt));\r\n  \
    \  }\r\n};\r\n\r\n}\r\n\r\ntemplate<int char_size, int margin>\r\nstruct trie\
    \ {\r\npublic:\r\n    trie() {\r\n        nodes.emplace_back(Node());\r\n    }\r\
    \n\r\n    void add(const std::string &str) {\r\n        int idx = 0;\r\n     \
    \   for(const auto &c: str) {\r\n            int val = c - margin;\r\n       \
    \     assert(0 <= val && val < char_size);\r\n            if(nodes[idx].nxt[val]\
    \ < 0) {\r\n                nodes[idx].nxt[val] = int(nodes.size());\r\n     \
    \           nodes.emplace_back(Node());\r\n            }\r\n            idx =\
    \ nodes[idx].nxt[val];\r\n            nodes[idx].common++;\r\n        }\r\n  \
    \      nodes[idx].accept.emplace_back(nodes[0].common++);\r\n    }\r\n\r\n   \
    \ template<class F>\r\n    void query(const std::string &str, int start, F func)\
    \ const {\r\n        int idx = 0;\r\n        for(int i = start; i < int(str.size());\
    \ ++i) {\r\n            int val = str[i] - margin;\r\n            assert(0 <=\
    \ val && val < char_size);\r\n            int nxt = nodes[idx].nxt[val];\r\n \
    \           if(nxt < 0) {\r\n                return;\r\n            }\r\n    \
    \        idx = nxt;\r\n            for(const auto id: nodes[idx].accept) {\r\n\
    \                func(id);\r\n            }\r\n        }\r\n        return;\r\n\
    \    }\r\n\r\n    bool search(const std::string &str, int start, bool prefix =\
    \ false) const {\r\n        int idx = 0;\r\n        for(int i = start; i < int(str.size());\
    \ ++i) {\r\n            int val = str[i] - margin;\r\n            assert(0 <=\
    \ val && val < char_size);\r\n            int nxt = nodes[idx].nxt[val];\r\n \
    \           if(nxt < 0) {\r\n                return -1;\r\n            }\r\n \
    \           idx = nxt;\r\n        }\r\n        return prefix ? true : (nodes[idx].accept.size()\
    \ > 0);\r\n    }\r\n\r\n    int size() const {\r\n        return int(nodes.size());\r\
    \n    }\r\nprivate:\r\n    using Node = internal::trie_node<char_size>;\r\nprotected:\r\
    \n    std::vector<Node> nodes;\r\n};\r\n\r\n}\n#line 11 \"String/aho_corasick.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<int char_size, int margin>\r\nstruct aho_corasick\
    \ : trie<char_size+1, margin> {\r\nprivate:\r\n    void move_nxt(int &now, int\
    \ val) {\r\n        assert(0 <= val && val < char_size);\r\n        while(this->nodes[now].nxt[val]\
    \ == -1) now = this->nodes[now].nxt[FAIL];\r\n        now = this->nodes[now].nxt[val];\r\
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
    \     }\r\n        }\r\n        return map;\r\n    }\r\n\r\n    template<class\
    \ F>\r\n    void query(const std::string &str, F func, int now = 0) {\r\n    \
    \    for(int i = 0; i < int(str.size()); ++i) {\r\n            move_nxt(now, str[i]\
    \ - margin);\r\n            for(const auto &a: this->nodes[now].accept) {\r\n\
    \                func(a, i);\r\n            }\r\n        }\r\n        return;\r\
    \n    }\r\n\r\n    std::pair<int,int> move(const char &c, int now) {\r\n     \
    \   int sum = 0;\r\n        move_nxt(now, c - margin);\r\n        sum += correct[now];\r\
    \n        return {sum, now};\r\n    }\r\nprivate:\r\n    const int FAIL = char_size;\r\
    \n    std::vector<int> correct;\r\n};\r\n\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <string.h>\r\n#include\
    \ <queue>\r\n#include <algorithm>\r\n#include <map>\r\n#include <cassert>\r\n\r\
    \n#include \"trie.hpp\"\r\n\r\nnamespace ebi {\r\n\r\ntemplate<int char_size,\
    \ int margin>\r\nstruct aho_corasick : trie<char_size+1, margin> {\r\nprivate:\r\
    \n    void move_nxt(int &now, int val) {\r\n        assert(0 <= val && val < char_size);\r\
    \n        while(this->nodes[now].nxt[val] == -1) now = this->nodes[now].nxt[FAIL];\r\
    \n        now = this->nodes[now].nxt[val];\r\n        return;\r\n    }\r\n   \
    \ using trie<char_size + 1, margin>::trie;\r\n    using trie<char_size + 1, margin>::nodes;\r\
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
    \     }\r\n        }\r\n        return map;\r\n    }\r\n\r\n    template<class\
    \ F>\r\n    void query(const std::string &str, F func, int now = 0) {\r\n    \
    \    for(int i = 0; i < int(str.size()); ++i) {\r\n            move_nxt(now, str[i]\
    \ - margin);\r\n            for(const auto &a: this->nodes[now].accept) {\r\n\
    \                func(a, i);\r\n            }\r\n        }\r\n        return;\r\
    \n    }\r\n\r\n    std::pair<int,int> move(const char &c, int now) {\r\n     \
    \   int sum = 0;\r\n        move_nxt(now, c - margin);\r\n        sum += correct[now];\r\
    \n        return {sum, now};\r\n    }\r\nprivate:\r\n    const int FAIL = char_size;\r\
    \n    std::vector<int> correct;\r\n};\r\n\r\n}\r\n"
  dependsOn:
  - String/trie.hpp
  isVerificationFile: false
  path: String/aho_corasick.hpp
  requiredBy: []
  timestamp: '2021-08-25 17:31:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2863.test.cpp
  - test/aoj/aoj_2873.test.cpp
documentation_of: String/aho_corasick.hpp
layout: document
redirect_from:
- /library/String/aho_corasick.hpp
- /library/String/aho_corasick.hpp.html
title: String/aho_corasick.hpp
---
