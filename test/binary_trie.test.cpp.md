---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_trie.hpp
    title: data_structure/binary_trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/binary_trie.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \r\n\r\n#line 2 \"data_structure/binary_trie.hpp\"\n\r\n/*\r\n    reference: https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\r\
    \n*/\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <cassert>\r\n\
    #include <climits>\r\n#include <memory>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class T>\r\nstruct binary_trie {\r\n   private:\r\n    struct Node;\r\n   \
    \ using node_ptr = std::shared_ptr<Node>;\r\n    struct Node {\r\n        int\
    \ count = 0;\r\n        std::array<node_ptr, 2> childs;\r\n        Node() = default;\r\
    \n    };\r\n\r\n   public:\r\n    binary_trie() = default;\r\n\r\n    void insert(const\
    \ T x) {\r\n        node_ptr now = root;\r\n        now->count++;\r\n        for\
    \ (int i = bit_size - 1; i >= 0; i--) {\r\n            int index = (x >> i) &\
    \ 1;\r\n            if (now->childs[index] == nullptr) {\r\n                now->childs[index]\
    \ = std::make_shared<Node>();\r\n            }\r\n            now = now->childs[index];\r\
    \n            now->count++;\r\n        }\r\n        return;\r\n    }\r\n\r\n \
    \   void erase(const T x) {\r\n        if (find(x) == false) return;\r\n     \
    \   node_ptr now = root;\r\n        now->count--;\r\n        for (int i = bit_size\
    \ - 1; i >= 0; i--) {\r\n            int index = (x >> i) & 1;\r\n           \
    \ assert(now->childs[index]);\r\n            now = now->childs[index];\r\n   \
    \         now->count--;\r\n        }\r\n        return;\r\n    }\r\n\r\n    bool\
    \ find(const T x) const {\r\n        node_ptr now = root;\r\n        for (int\
    \ i = bit_size - 1; i >= 0; i--) {\r\n            int index = (x >> i) & 1;\r\n\
    \            if (now->childs[index] == nullptr) {\r\n                return false;\r\
    \n            }\r\n            now = now->childs[index];\r\n            if (now->count\
    \ == 0) {\r\n                return false;\r\n            }\r\n        }\r\n \
    \       return true;\r\n    }\r\n\r\n    T min_element(const T x) const {\r\n\
    \        T val = 0;\r\n        node_ptr now = root;\r\n        for (int i = bit_size\
    \ - 1; i >= 0; i--) {\r\n            int index = ((x >> i) & 1);\r\n         \
    \   if (now->childs[index] && now->childs[index]->count > 0) {\r\n           \
    \     now = now->childs[index];\r\n            } else if (now->childs[index ^\
    \ 1] &&\r\n                       now->childs[index ^ 1]->count > 0) {\r\n   \
    \             val |= T(1) << i;\r\n                now = now->childs[index ^ 1];\r\
    \n            } else {\r\n                assert(0);\r\n            }\r\n    \
    \    }\r\n        return val;\r\n    }\r\n\r\n    T max_element(const T x) const\
    \ {\r\n        T val = 0;\r\n        node_ptr now = root;\r\n        for (int\
    \ i = bit_size - 1; i >= 0; i--) {\r\n            int index = ((x >> i) & 1) ^\
    \ 1;\r\n            if (now->childs[index] && now->childs[index]->count > 0) {\r\
    \n                val |= T(1) << i;\r\n                now = now->childs[index];\r\
    \n            } else if (now->childs[index ^ 1] &&\r\n                       now->childs[index\
    \ ^ 1]->count > 0) {\r\n                now = now->childs[index ^ 1];\r\n    \
    \        } else {\r\n                assert(0);\r\n            }\r\n        }\r\
    \n    }\r\n\r\n    int size() const { return root->count; }\r\n\r\n   private:\r\
    \n    const size_t bit_size = sizeof(T) * CHAR_BIT;\r\n    node_ptr root = std::make_shared<Node>();\r\
    \n};\r\n\r\n}  // namespace ebi\n#line 4 \"test/binary_trie.test.cpp\"\n\r\n#include\
    \ <iostream>\r\n\r\nint main(){\r\n    int q;\r\n    std::cin >> q;\r\n    ebi::binary_trie<int>\
    \ trie;\r\n    while (q--) {\r\n        int t, x;\r\n        std::cin >> t >>\
    \ x;\r\n        if (t == 0) {\r\n            if (!trie.find(x)) trie.insert(x);\r\
    \n        } else if (t == 1) {\r\n            if (trie.find(x)) trie.erase(x);\r\
    \n        } else {\r\n            std::cout << trie.min_element(x) << '\\n';\r\
    \n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\r\n\r\n#include\
    \ \"../data_structure/binary_trie.hpp\"\r\n\r\n#include <iostream>\r\n\r\nint\
    \ main(){\r\n    int q;\r\n    std::cin >> q;\r\n    ebi::binary_trie<int> trie;\r\
    \n    while (q--) {\r\n        int t, x;\r\n        std::cin >> t >> x;\r\n  \
    \      if (t == 0) {\r\n            if (!trie.find(x)) trie.insert(x);\r\n   \
    \     } else if (t == 1) {\r\n            if (trie.find(x)) trie.erase(x);\r\n\
    \        } else {\r\n            std::cout << trie.min_element(x) << '\\n';\r\n\
    \        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/binary_trie.hpp
  isVerificationFile: true
  path: test/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2022-05-19 19:15:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/test/binary_trie.test.cpp
- /verify/test/binary_trie.test.cpp.html
title: test/binary_trie.test.cpp
---
