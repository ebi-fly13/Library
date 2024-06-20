---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/Stream.hpp
    title: data_structure/Stream.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/bankers_queue.hpp
    title: data_structure/bankers_queue.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Persistent_Queue.test.cpp
    title: test/data_structure/Persistent_Queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://noshi91.github.io/Library/other/suspension.cpp
  bundledCode: "#line 2 \"data_structure/Suspension.hpp\"\n\r\n/*\r\n    reference:\
    \ https://noshi91.github.io/Library/other/suspension.cpp\r\n*/\r\n\r\n#include\
    \ <functional>\r\n#include <memory>\r\n#include <utility>\r\n#include <variant>\r\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T>\r\nstruct suspension : std::shared_ptr<std::variant<T,\
    \ std::function<T()>>> {\r\n    using value_type = T;\r\n    using func_type =\
    \ std::function<T()>;\r\n    using node_type = std::variant<T, std::function<T()>>;\r\
    \n    using base_type = std::shared_ptr<node_type>;\r\n\r\n  private:\r\n    static\
    \ T get(node_type &x) {\r\n        if (x.index() != 0) {\r\n            x = std::get<1>(x)();\r\
    \n        }\r\n        return std::get<0>(x);\r\n    }\r\n\r\n  public:\r\n  \
    \  suspension(T x)\r\n        : base_type(std::make_shared<node_type>(std::in_place_index<0>,\
    \ x)) {}\r\n    suspension(std::function<T()> f)\r\n        : base_type(std::make_shared<node_type>(std::in_place_index<1>,\
    \ f)) {}\r\n\r\n    T force() const {\r\n        return get(**this);\r\n    }\r\
    \n};\r\n\r\n}  // namespace ebi\r\n"
  code: "#pragma once\r\n\r\n/*\r\n    reference: https://noshi91.github.io/Library/other/suspension.cpp\r\
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
    \n};\r\n\r\n}  // namespace ebi\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Suspension.hpp
  requiredBy:
  - data_structure/bankers_queue.hpp
  - data_structure/Stream.hpp
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Persistent_Queue.test.cpp
documentation_of: data_structure/Suspension.hpp
layout: document
redirect_from:
- /library/data_structure/Suspension.hpp
- /library/data_structure/Suspension.hpp.html
title: data_structure/Suspension.hpp
---
