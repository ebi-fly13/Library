---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/Suspension.hpp
    title: data_structure/Suspension.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/bankers_queue.hpp
    title: data_structure/bankers_queue.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/bankers_queue.test.cpp
    title: test/bankers_queue.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://noshi91.github.io/Library/data_structure/stream.cpp
    - https://www.cs.cmu.edu/~rwh/theses/okasaki.pdf
  bundledCode: "#line 2 \"data_structure/Stream.hpp\"\n\r\n#line 2 \"data_structure/Suspension.hpp\"\
    \n\r\n/*\r\n    reference: https://noshi91.github.io/Library/other/suspension.cpp\r\
    \n*/\r\n\r\n#include <functional>\r\n#include <memory>\r\n#include <utility>\r\
    \n#include <variant>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class T>\r\nstruct\
    \ suspension : std::shared_ptr<std::variant<T, std::function<T()>>> {\r\n    using\
    \ value_type = T;\r\n    using func_type = std::function<T()>;\r\n    using node_type\
    \ = std::variant<T, std::function<T()>>;\r\n    using base_type = std::shared_ptr<node_type>;\r\
    \n\r\n  private:\r\n    static T get(node_type &x) {\r\n        if (x.index()\
    \ != 0) {\r\n            x = std::get<1>(x)();\r\n        }\r\n        return\
    \ std::get<0>(x);\r\n    }\r\n\r\n  public:\r\n    suspension(T x)\r\n       \
    \ : base_type(std::make_shared<node_type>(std::in_place_index<0>, x)) {}\r\n \
    \   suspension(std::function<T()> f)\r\n        : base_type(std::make_shared<node_type>(std::in_place_index<1>,\
    \ f)) {}\r\n\r\n    T force() const {\r\n        return get(**this);\r\n    }\r\
    \n};\r\n\r\n}  // namespace ebi\r\n#line 4 \"data_structure/Stream.hpp\"\n\r\n\
    /*\r\n    reference: https://www.cs.cmu.edu/~rwh/theses/okasaki.pdf\r\n      \
    \         https://noshi91.github.io/Library/data_structure/stream.cpp\r\n*/\r\n\
    \r\n#include <cassert>\r\n#include <optional>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class T>\r\nstruct stream : suspension<std::optional<std::pair<T, stream<T>>>>\
    \ {\r\n  private:\r\n    using Self = stream<T>;\r\n    using cell_type = std::optional<std::pair<T,\
    \ Self>>;\r\n    using base_type = suspension<cell_type>;\r\n    using base_type::force;\r\
    \n\r\n    stream(T x, Self s) : base_type(cell_type(std::in_place, x, s)) {}\r\
    \n\r\n  public:\r\n    stream() : base_type(cell_type(std::nullopt)) {}\r\n  \
    \  stream(std::function<cell_type()> f) : base_type(f) {}\r\n    bool empty()\
    \ const {\r\n        return !force().has_value();\r\n    }\r\n    T top() const\
    \ {\r\n        assert(!empty());\r\n        return force()->first;\r\n    }\r\n\
    \    Self push(T x) const {\r\n        return stream(x, *this);\r\n    }\r\n \
    \   Self pop() const {\r\n        assert(!empty());\r\n        return (*force()).second;\r\
    \n    }\r\n    Self reverse() {\r\n        return Self([x = *this]() mutable {\r\
    \n            Self ret;\r\n            while (!x.empty()) {\r\n              \
    \  ret = ret.push(x.top());\r\n                x = x.pop();\r\n            }\r\
    \n            return ret.force();\r\n        });\r\n    }\r\n\r\n    friend Self\
    \ operator+(Self lhs, Self rhs) {\r\n        return Self([lhs, rhs]() {\r\n  \
    \          if (lhs.empty()) {\r\n                return rhs.force();\r\n     \
    \       } else {\r\n                return cell_type(std::in_place, lhs.top(),\
    \ lhs.pop() + rhs);\r\n            }\r\n        });\r\n    }\r\n};\r\n\r\n}  //\
    \ namespace ebi\n"
  code: "#pragma once\r\n\r\n#include \"../data_structure/Suspension.hpp\"\r\n\r\n\
    /*\r\n    reference: https://www.cs.cmu.edu/~rwh/theses/okasaki.pdf\r\n      \
    \         https://noshi91.github.io/Library/data_structure/stream.cpp\r\n*/\r\n\
    \r\n#include <cassert>\r\n#include <optional>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class T>\r\nstruct stream : suspension<std::optional<std::pair<T, stream<T>>>>\
    \ {\r\n  private:\r\n    using Self = stream<T>;\r\n    using cell_type = std::optional<std::pair<T,\
    \ Self>>;\r\n    using base_type = suspension<cell_type>;\r\n    using base_type::force;\r\
    \n\r\n    stream(T x, Self s) : base_type(cell_type(std::in_place, x, s)) {}\r\
    \n\r\n  public:\r\n    stream() : base_type(cell_type(std::nullopt)) {}\r\n  \
    \  stream(std::function<cell_type()> f) : base_type(f) {}\r\n    bool empty()\
    \ const {\r\n        return !force().has_value();\r\n    }\r\n    T top() const\
    \ {\r\n        assert(!empty());\r\n        return force()->first;\r\n    }\r\n\
    \    Self push(T x) const {\r\n        return stream(x, *this);\r\n    }\r\n \
    \   Self pop() const {\r\n        assert(!empty());\r\n        return (*force()).second;\r\
    \n    }\r\n    Self reverse() {\r\n        return Self([x = *this]() mutable {\r\
    \n            Self ret;\r\n            while (!x.empty()) {\r\n              \
    \  ret = ret.push(x.top());\r\n                x = x.pop();\r\n            }\r\
    \n            return ret.force();\r\n        });\r\n    }\r\n\r\n    friend Self\
    \ operator+(Self lhs, Self rhs) {\r\n        return Self([lhs, rhs]() {\r\n  \
    \          if (lhs.empty()) {\r\n                return rhs.force();\r\n     \
    \       } else {\r\n                return cell_type(std::in_place, lhs.top(),\
    \ lhs.pop() + rhs);\r\n            }\r\n        });\r\n    }\r\n};\r\n\r\n}  //\
    \ namespace ebi"
  dependsOn:
  - data_structure/Suspension.hpp
  isVerificationFile: false
  path: data_structure/Stream.hpp
  requiredBy:
  - data_structure/bankers_queue.hpp
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/bankers_queue.test.cpp
documentation_of: data_structure/Stream.hpp
layout: document
redirect_from:
- /library/data_structure/Stream.hpp
- /library/data_structure/Stream.hpp.html
title: data_structure/Stream.hpp
---
