---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/persistent_array.hpp
    title: data_structure/persistent_array.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/persistent_unionfind.hpp
    title: data_structure/persistent_unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/data_structure/Persistent_Unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\n\r\n#line\
    \ 2 \"data_structure/persistent_unionfind.hpp\"\n\r\n#include <cstdint>\r\n#include\
    \ <memory>\r\n#include <vector>\r\n\r\n#line 2 \"data_structure/persistent_array.hpp\"\
    \n\r\n#include <cassert>\r\n#line 7 \"data_structure/persistent_array.hpp\"\n\r\
    \n/*\r\n    reference: https://37zigen.com/persistent-array/\r\n*/\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class T, std::size_t m> struct persistent_array {\r\n\
    \  private:\r\n    struct Node;\r\n    using node_ptr = std::shared_ptr<Node>;\r\
    \n    using size_t = std::size_t;\r\n    struct Node {\r\n        T val;\r\n \
    \       std::vector<node_ptr> chr;\r\n        Node(T val, std::vector<node_ptr>\
    \ chr = std::vector<node_ptr>(m))\r\n            : val(val), chr(chr) {}\r\n \
    \       node_ptr get_chr(int i) {\r\n            return chr[i];\r\n        }\r\
    \n        void update_chr(int i, node_ptr node) {\r\n            chr[i] = node;\r\
    \n        }\r\n    };\r\n\r\n    std::vector<node_ptr> root;\r\n    int now;\r\
    \n\r\n  public:\r\n    persistent_array(std::size_t n, T val) : now(0) {\r\n \
    \       root.emplace_back(std::make_shared<Node>(val));\r\n        for (size_t\
    \ i = 1; i < n; i++) {\r\n            node_ptr node = root[0];\r\n           \
    \ size_t ret = i;\r\n            while (ret > 0) {\r\n                if (node->chr[ret\
    \ % m] == nullptr) {\r\n                    node->chr[ret % m] = std::make_shared<Node>(val);\r\
    \n                }\r\n                node = node->chr[ret % m];\r\n        \
    \        ret /= m;\r\n            }\r\n            if (node == nullptr) {\r\n\
    \                node = std::make_shared<Node>(val);\r\n            }\r\n    \
    \    }\r\n    }\r\n\r\n    persistent_array(std::vector<T> a) : now(0) {\r\n \
    \       size_t n = a.size();\r\n        root.emplace_back(std::make_shared<Node>(a[0]));\r\
    \n        for (size_t i = 1; i < n; i++) {\r\n            node_ptr node = root[0];\r\
    \n            size_t ret = i;\r\n            while (ret > 0) {\r\n           \
    \     if (node->chr[ret % m] == nullptr) {\r\n                    node->chr[ret\
    \ % m] = std::make_shared<Node>(a[i]);\r\n                }\r\n              \
    \  node = node->chr[ret % m];\r\n                ret /= m;\r\n            }\r\n\
    \            if (node == nullptr) {\r\n                node = std::make_shared<Node>(a[i]);\r\
    \n            }\r\n        }\r\n    }\r\n\r\n    T get(size_t i, int time = -1)\
    \ {\r\n        assert(time <= now);\r\n        if (time < 0) time = now;\r\n \
    \       node_ptr node = root[time];\r\n        while (i > 0) {\r\n           \
    \ node = node->chr[i % m];\r\n            i /= m;\r\n        }\r\n        return\
    \ node->val;\r\n    }\r\n\r\n    void set(size_t i, T val, int time = -1) {\r\n\
    \        if (time < 0) time = now;\r\n        assert(time <= now);\r\n       \
    \ node_ptr p = root[time];\r\n        node_ptr node = std::make_shared<Node>(p->val,\
    \ p->chr);\r\n        root.emplace_back(node);\r\n        while (i > 0) {\r\n\
    \            p = p->chr[i % m];\r\n            node->chr[i % m] = std::make_shared<Node>(p->val,\
    \ p->chr);\r\n            node = node->chr[i % m];\r\n            i /= m;\r\n\
    \        }\r\n        node->val = val;\r\n        now++;\r\n    }\r\n\r\n    void\
    \ add(size_t i, T rhs, int time = -1) {\r\n        if (time < 0) time = now;\r\
    \n        assert(time <= now);\r\n        node_ptr p = root[time];\r\n       \
    \ node_ptr node = std::make_shared<Node>(p->val, p->chr);\r\n        root.emplace_back(node);\r\
    \n        while (i > 0) {\r\n            p = p->chr[i % m];\r\n            node->chr[i\
    \ % m] = std::make_shared<Node>(p->val, p->chr);\r\n            node = node->chr[i\
    \ % m];\r\n            i /= m;\r\n        }\r\n        node->val += rhs;\r\n \
    \       now++;\r\n    }\r\n\r\n    void update(size_t i, T rhs, int time = -1)\
    \ {\r\n        if (time < 0) time = now;\r\n        assert(time <= now);\r\n \
    \       node_ptr node = root[time];\r\n        node_ptr p = root[time];\r\n  \
    \      while (i > 0) {\r\n            p = p->chr[i % m];\r\n            node->chr[i\
    \ % m] = std::make_shared<Node>(p->val, p->chr);\r\n            node = node->chr[i\
    \ % m];\r\n            i /= m;\r\n        }\r\n        node->val = rhs;\r\n  \
    \  }\r\n};\r\n\r\n}  // namespace ebi\n#line 8 \"data_structure/persistent_unionfind.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nstruct persistent_unionfind {\r\n  private:\r\n \
    \   using size_t = std::size_t;\r\n    persistent_array<int, 64> par;\r\n\r\n\
    \  public:\r\n    persistent_unionfind(size_t n) : par(std::vector<int>(n, -1))\
    \ {}\r\n\r\n    int leader(int x, int time = -1) {\r\n        int val = par.get(x,\
    \ time);\r\n        if (val < 0)\r\n            return x;\r\n        else\r\n\
    \            return leader(val, time);\r\n    }\r\n\r\n    bool merge(int x, int\
    \ y, int time = -1) {\r\n        x = leader(x, time);\r\n        y = leader(y,\
    \ time);\r\n        if (x == y) {\r\n            par.set(0, par.get(0));\r\n \
    \           return false;\r\n        }\r\n        int val_x = par.get(x, time);\r\
    \n        int val_y = par.get(y, time);\r\n        if (val_x > val_y) std::swap(x,\
    \ y);\r\n        par.set(x, val_x + val_y, time);\r\n        par.update(y, x);\r\
    \n        return true;\r\n    }\r\n\r\n    bool same(int x, int y, int time =\
    \ -1) {\r\n        return leader(x, time) == leader(y, time);\r\n    }\r\n\r\n\
    \    int size(int x, int time = -1) {\r\n        return -par.get(leader(x, time));\r\
    \n    }\r\n};\r\n\r\n}  // namespace ebi\n#line 4 \"test/data_structure/Persistent_Unionfind.test.cpp\"\
    \n\r\n#include <iostream>\r\n#line 7 \"test/data_structure/Persistent_Unionfind.test.cpp\"\
    \n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    ebi::persistent_unionfind\
    \ uf(n);\r\n    std::vector<int> query(q + 1, 0);\r\n    int time = 0;\r\n   \
    \ for (int i = 1; i <= q; i++) {\r\n        int t, k, u, v;\r\n        std::cin\
    \ >> t >> k >> u >> v;\r\n        k = query[k + 1];\r\n        query[i] = k;\r\
    \n        if (t == 0) {\r\n            uf.merge(u, v, k);\r\n            query[i]\
    \ = ++time;\r\n        } else {\r\n            if (uf.same(u, v, k)) {\r\n   \
    \             std::cout << \"1\\n\";\r\n            } else {\r\n             \
    \   std::cout << \"0\\n\";\r\n            }\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\
    \n\r\n#include \"../../data_structure/persistent_unionfind.hpp\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n\r\nint main() {\r\n    int n, q;\r\n   \
    \ std::cin >> n >> q;\r\n    ebi::persistent_unionfind uf(n);\r\n    std::vector<int>\
    \ query(q + 1, 0);\r\n    int time = 0;\r\n    for (int i = 1; i <= q; i++) {\r\
    \n        int t, k, u, v;\r\n        std::cin >> t >> k >> u >> v;\r\n       \
    \ k = query[k + 1];\r\n        query[i] = k;\r\n        if (t == 0) {\r\n    \
    \        uf.merge(u, v, k);\r\n            query[i] = ++time;\r\n        } else\
    \ {\r\n            if (uf.same(u, v, k)) {\r\n                std::cout << \"\
    1\\n\";\r\n            } else {\r\n                std::cout << \"0\\n\";\r\n\
    \            }\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/persistent_unionfind.hpp
  - data_structure/persistent_array.hpp
  isVerificationFile: true
  path: test/data_structure/Persistent_Unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Persistent_Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Persistent_Unionfind.test.cpp
- /verify/test/data_structure/Persistent_Unionfind.test.cpp.html
title: test/data_structure/Persistent_Unionfind.test.cpp
---
