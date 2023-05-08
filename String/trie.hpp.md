---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: String/aho_corasick.hpp
    title: String/aho_corasick.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/aoj_2863.test.cpp
    title: test/aoj/aoj_2863.test.cpp
  - icon: ':x:'
    path: test/aoj/aoj_2873.test.cpp
    title: test/aoj/aoj_2873.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/trie.hpp\"\n\r\n#include <cassert>\r\n#include <string>\r\
    \n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\n\
    template <int char_size> struct trie_node {\r\n    int common;\r\n    int nxt[char_size];\r\
    \n    std::vector<int> accept;\r\n    trie_node() : common(0) {\r\n        memset(nxt,\
    \ -1, sizeof(nxt));\r\n    }\r\n};\r\n\r\n}  // namespace internal\r\n\r\ntemplate\
    \ <int char_size, int margin> struct trie {\r\n  public:\r\n    trie() {\r\n \
    \       nodes.emplace_back(Node());\r\n    }\r\n\r\n    void add(const std::string\
    \ &str) {\r\n        int idx = 0;\r\n        for (const auto &c : str) {\r\n \
    \           int val = c - margin;\r\n            assert(0 <= val && val < char_size);\r\
    \n            if (nodes[idx].nxt[val] < 0) {\r\n                nodes[idx].nxt[val]\
    \ = int(nodes.size());\r\n                nodes.emplace_back(Node());\r\n    \
    \        }\r\n            idx = nodes[idx].nxt[val];\r\n            nodes[idx].common++;\r\
    \n        }\r\n        nodes[idx].accept.emplace_back(nodes[0].common++);\r\n\
    \    }\r\n\r\n    template <class F>\r\n    void query(const std::string &str,\
    \ int start, F func) const {\r\n        int idx = 0;\r\n        for (int i = start;\
    \ i < int(str.size()); ++i) {\r\n            int val = str[i] - margin;\r\n  \
    \          assert(0 <= val && val < char_size);\r\n            int nxt = nodes[idx].nxt[val];\r\
    \n            if (nxt < 0) {\r\n                return;\r\n            }\r\n \
    \           idx = nxt;\r\n            for (const auto id : nodes[idx].accept)\
    \ {\r\n                func(id);\r\n            }\r\n        }\r\n        return;\r\
    \n    }\r\n\r\n    bool search(const std::string &str, int start, bool prefix\
    \ = false) const {\r\n        int idx = 0;\r\n        for (int i = start; i <\
    \ int(str.size()); ++i) {\r\n            int val = str[i] - margin;\r\n      \
    \      assert(0 <= val && val < char_size);\r\n            int nxt = nodes[idx].nxt[val];\r\
    \n            if (nxt < 0) {\r\n                return -1;\r\n            }\r\n\
    \            idx = nxt;\r\n        }\r\n        return prefix ? true : (nodes[idx].accept.size()\
    \ > 0);\r\n    }\r\n\r\n    int size() const {\r\n        return int(nodes.size());\r\
    \n    }\r\n\r\n  private:\r\n    using Node = internal::trie_node<char_size>;\r\
    \n\r\n  protected:\r\n    std::vector<Node> nodes;\r\n};\r\n\r\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <string>\r\n#include <vector>\r\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\ntemplate <int char_size>\
    \ struct trie_node {\r\n    int common;\r\n    int nxt[char_size];\r\n    std::vector<int>\
    \ accept;\r\n    trie_node() : common(0) {\r\n        memset(nxt, -1, sizeof(nxt));\r\
    \n    }\r\n};\r\n\r\n}  // namespace internal\r\n\r\ntemplate <int char_size,\
    \ int margin> struct trie {\r\n  public:\r\n    trie() {\r\n        nodes.emplace_back(Node());\r\
    \n    }\r\n\r\n    void add(const std::string &str) {\r\n        int idx = 0;\r\
    \n        for (const auto &c : str) {\r\n            int val = c - margin;\r\n\
    \            assert(0 <= val && val < char_size);\r\n            if (nodes[idx].nxt[val]\
    \ < 0) {\r\n                nodes[idx].nxt[val] = int(nodes.size());\r\n     \
    \           nodes.emplace_back(Node());\r\n            }\r\n            idx =\
    \ nodes[idx].nxt[val];\r\n            nodes[idx].common++;\r\n        }\r\n  \
    \      nodes[idx].accept.emplace_back(nodes[0].common++);\r\n    }\r\n\r\n   \
    \ template <class F>\r\n    void query(const std::string &str, int start, F func)\
    \ const {\r\n        int idx = 0;\r\n        for (int i = start; i < int(str.size());\
    \ ++i) {\r\n            int val = str[i] - margin;\r\n            assert(0 <=\
    \ val && val < char_size);\r\n            int nxt = nodes[idx].nxt[val];\r\n \
    \           if (nxt < 0) {\r\n                return;\r\n            }\r\n   \
    \         idx = nxt;\r\n            for (const auto id : nodes[idx].accept) {\r\
    \n                func(id);\r\n            }\r\n        }\r\n        return;\r\
    \n    }\r\n\r\n    bool search(const std::string &str, int start, bool prefix\
    \ = false) const {\r\n        int idx = 0;\r\n        for (int i = start; i <\
    \ int(str.size()); ++i) {\r\n            int val = str[i] - margin;\r\n      \
    \      assert(0 <= val && val < char_size);\r\n            int nxt = nodes[idx].nxt[val];\r\
    \n            if (nxt < 0) {\r\n                return -1;\r\n            }\r\n\
    \            idx = nxt;\r\n        }\r\n        return prefix ? true : (nodes[idx].accept.size()\
    \ > 0);\r\n    }\r\n\r\n    int size() const {\r\n        return int(nodes.size());\r\
    \n    }\r\n\r\n  private:\r\n    using Node = internal::trie_node<char_size>;\r\
    \n\r\n  protected:\r\n    std::vector<Node> nodes;\r\n};\r\n\r\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: String/trie.hpp
  requiredBy:
  - String/aho_corasick.hpp
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/aoj_2863.test.cpp
  - test/aoj/aoj_2873.test.cpp
documentation_of: String/trie.hpp
layout: document
redirect_from:
- /library/String/trie.hpp
- /library/String/trie.hpp.html
title: String/trie.hpp
---
