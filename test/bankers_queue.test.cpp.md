---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/Stream.hpp
    title: data_structure/Stream.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/Suspension.hpp
    title: data_structure/Suspension.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/bankers_queue.hpp
    title: data_structure/bankers_queue.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/bankers_queue.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\
    \r\n\r\n#line 2 \"data_structure/bankers_queue.hpp\"\n\r\n#line 2 \"data_structure/Stream.hpp\"\
    \n\r\n#line 2 \"data_structure/Suspension.hpp\"\n\r\n/*\r\n    reference: https://noshi91.github.io/Library/other/suspension.cpp\r\
    \n*/\r\n\r\n#include <variant>\r\n#include <functional>\r\n#include <memory>\r\
    \n#include <utility>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct\
    \ suspension : std::shared_ptr<std::variant<T, std::function<T()>>> {\r\n    using\
    \ value_type = T;\r\n    using func_type = std::function<T()>;\r\n    using node_type\
    \ = std::variant<T, std::function<T()>>;\r\n    using base_type = std::shared_ptr<node_type>;\r\
    \nprivate:\r\n    static T get(node_type &x) {\r\n        if(x.index() != 0) {\r\
    \n            x = std::get<1>(x)();\r\n        }\r\n        return std::get<0>(x);\r\
    \n    }\r\npublic:\r\n    suspension(T x) : base_type(std::make_shared<node_type>(std::in_place_index<0>,\
    \ x)) { }\r\n    suspension(std::function<T()> f) : base_type(std::make_shared<node_type>(std::in_place_index<1>,\
    \ f)) { }\r\n\r\n    T force() const { return get(**this); }\r\n};\r\n\r\n}\r\n\
    #line 4 \"data_structure/Stream.hpp\"\n\r\n/*\r\n    reference: https://www.cs.cmu.edu/~rwh/theses/okasaki.pdf\r\
    \n               https://noshi91.github.io/Library/data_structure/stream.cpp\r\
    \n*/\r\n\r\n#include <optional>\r\n#include <cassert>\r\n\r\nnamespace ebi {\r\
    \n\r\ntemplate<class T>\r\nstruct stream : suspension<std::optional<std::pair<T,\
    \ stream<T>>>> {\r\nprivate:\r\n    using Self = stream<T>;\r\n    using cell_type\
    \ = std::optional<std::pair<T, Self>>;\r\n    using base_type = suspension<cell_type>;\r\
    \n    using base_type::force;\r\n\r\n    stream(T x, Self s) : base_type(cell_type(std::in_place,\
    \ x, s)) { }\r\npublic:\r\n    stream() : base_type(cell_type(std::nullopt)) {\
    \ }\r\n    stream(std::function<cell_type()> f) : base_type(f) { }\r\n    bool\
    \ empty() const {\r\n        return !force().has_value();\r\n    }\r\n    T top()\
    \ const {\r\n        assert(!empty());\r\n        return force()->first;\r\n \
    \   }\r\n    Self push(T x) const {\r\n        return stream(x, *this);\r\n  \
    \  }\r\n    Self pop() const {\r\n        assert(!empty());\r\n        return\
    \ (*force()).second;\r\n    }\r\n    Self reverse() {\r\n        return Self([x\
    \ = *this]() mutable {\r\n            Self ret;\r\n            while(!x.empty())\
    \ {\r\n                ret = ret.push(x.top());\r\n                x = x.pop();\r\
    \n            }\r\n            return ret.force();\r\n        });\r\n    }\r\n\
    \r\n    friend Self operator+(Self lhs, Self rhs) {\r\n        return Self([lhs,\
    \ rhs]() {\r\n            if(lhs.empty()) {\r\n                return rhs.force();\r\
    \n            }\r\n            else {\r\n                return cell_type(std::in_place,\
    \ lhs.top(), lhs.pop() + rhs);\r\n            }\r\n        });\r\n    }\r\n\r\n\
    };\r\n\r\n}\n#line 4 \"data_structure/bankers_queue.hpp\"\n\r\n/*\r\n    reference:\
    \ https://37zigen.com/bankers-queue/\r\n               http://www.kmonos.net/pub/Presen/PFDS.pdf\r\
    \n*/\r\n\r\n#line 11 \"data_structure/bankers_queue.hpp\"\n\r\nnamespace ebi {\r\
    \n\r\ntemplate<class T>\r\nstruct bankers_queue {\r\nprivate:\r\n    using size_t\
    \ = std::size_t;\r\n    using Self = bankers_queue<T>;\r\n    stream<T> f;\r\n\
    \    size_t fsize;\r\n    stream<T> r;\r\n    size_t rsize;\r\n\r\n    bankers_queue(stream<T>\
    \ _f, size_t _fsize, stream<T> _r, size_t _rsize) : f(_f), fsize(_fsize), r(_r),\
    \ rsize(_rsize) { }\r\n\r\n    Self normalize() {\r\n        if(fsize>=rsize)\
    \ return *this;\r\n        else {\r\n            return Self(f+r.reverse(), fsize+rsize,\
    \ stream<T>(), 0);\r\n        }\r\n    }\r\npublic:\r\n    bankers_queue() : f(),\
    \ fsize(0), r(), rsize(0) { }\r\n\r\n    bool empty() {\r\n        return f.empty();\r\
    \n    }\r\n\r\n    T top() {\r\n        assert(!empty());\r\n        return f.top();\r\
    \n    }\r\n\r\n    T front() {\r\n        return top();\r\n    }\r\n\r\n    Self\
    \ push(T x) {\r\n        return Self(f, fsize, r.push(x), rsize+1).normalize();\r\
    \n    }\r\n\r\n    Self pop() {\r\n        assert(!empty());\r\n        return\
    \ Self(f.pop(), fsize-1, r, rsize).normalize();\r\n    }\r\n};\r\n\r\n}\n#line\
    \ 4 \"test/bankers_queue.test.cpp\"\n\r\n#include <iomanip>\r\n#include <iostream>\r\
    \n#include <limits>\r\n#include <vector>\r\n\r\nint main() {\r\n    std::cout\
    \ << std::fixed << std::setprecision(15);\r\n    int q;\r\n    std::cin >> q;\r\
    \n    std::vector<ebi::bankers_queue<int>> que(1);\r\n    while (q--) {\r\n  \
    \      int flag;\r\n        std::cin >> flag;\r\n        if (flag == 0) {\r\n\
    \            int t, x;\r\n            std::cin >> t >> x;\r\n            t++;\r\
    \n            que.emplace_back(que[t].push(x));\r\n        } else {\r\n      \
    \      int t;\r\n            std::cin >> t;\r\n            t++;\r\n          \
    \  std::cout << que[t].top() << '\\n';\r\n            que.emplace_back(que[t].pop());\r\
    \n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\r\n\r\
    \n#include \"../data_structure/bankers_queue.hpp\"\r\n\r\n#include <iomanip>\r\
    \n#include <iostream>\r\n#include <limits>\r\n#include <vector>\r\n\r\nint main()\
    \ {\r\n    std::cout << std::fixed << std::setprecision(15);\r\n    int q;\r\n\
    \    std::cin >> q;\r\n    std::vector<ebi::bankers_queue<int>> que(1);\r\n  \
    \  while (q--) {\r\n        int flag;\r\n        std::cin >> flag;\r\n       \
    \ if (flag == 0) {\r\n            int t, x;\r\n            std::cin >> t >> x;\r\
    \n            t++;\r\n            que.emplace_back(que[t].push(x));\r\n      \
    \  } else {\r\n            int t;\r\n            std::cin >> t;\r\n          \
    \  t++;\r\n            std::cout << que[t].top() << '\\n';\r\n            que.emplace_back(que[t].pop());\r\
    \n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/bankers_queue.hpp
  - data_structure/Stream.hpp
  - data_structure/Suspension.hpp
  isVerificationFile: true
  path: test/bankers_queue.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 05:33:08+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/bankers_queue.test.cpp
layout: document
redirect_from:
- /verify/test/bankers_queue.test.cpp
- /verify/test/bankers_queue.test.cpp.html
title: test/bankers_queue.test.cpp
---
