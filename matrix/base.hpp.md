---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: matrix/gauss_jordan.hpp
    title: matrix/gauss_jordan.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix/Matrix_Product.test.cpp
    title: test/matrix/Matrix_Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Rank_of_Matrix.test.cpp
    title: test/matrix/Rank_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/System_of_Linear_Equations.test.cpp
    title: test/matrix/System_of_Linear_Equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/base.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <ranges>\n#include <vector>\n\nnamespace ebi {\n\
    \ntemplate <class T> struct matrix {\n  private:\n    using Self = matrix<T>;\n\
    \n  public:\n    matrix(int n_, int m_, T init_val = 0)\n        : n(n_), m(m_),\
    \ data(n * m, init_val) {}\n\n    matrix(const std::vector<std::vector<T>> &a)\n\
    \        : n((int)a.size()), m((int)a[0].size()) {\n        data = std::vector(n\
    \ * m);\n        for (int i = 0; i < n; i++) {\n            std::copy(a[i].begin(),\
    \ a[i].end(), data.begin() + i * m);\n        }\n    }\n\n    Self operator+(Self\
    \ &rhs) const noexcept {\n        return Self(*this) += rhs;\n    }\n\n    Self\
    \ operator-(Self &rhs) const noexcept {\n        return Self(*this) -= rhs;\n\
    \    }\n\n    Self operator*(Self &rhs) const noexcept {\n        return Self(*this)\
    \ *= rhs;\n    }\n\n    Self &operator+=(Self &rhs) noexcept {\n        assert(this->size()\
    \ == rhs.size());\n        for (int i = 0; i < n; ++i) {\n            for (int\
    \ j = 0; j < m; ++j) {\n                data[i][j] += rhs[i][j];\n           \
    \ }\n        }\n        return *this;\n    }\n\n    Self &operator-=(Self &rhs)\
    \ noexcept {\n        assert(this->size() == rhs.size());\n        for (int i\
    \ = 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j) {\n            \
    \    data[i][j] -= rhs[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n\n    Self &operator*=(Self &rhs) noexcept {\n        int h = n, w = rhs.column_size();\n\
    \        assert(m == rhs.row_size());\n        Self ret(h, w);\n        for (int\
    \ i = 0; i < h; ++i) {\n            for (int k = 0; k < m; ++k) {\n          \
    \      for (int j = 0; j < w; ++j) {\n                    ret[i][j] += (*this)[i][k]\
    \ * rhs[k][j];\n                }\n            }\n        }\n        return *this\
    \ = ret;\n    }\n\n    const auto operator[](int i) const {\n        return std::ranges::subrange(data.begin()\
    \ + i * m,\n                                     data.begin() + (i + 1) * m);\n\
    \    }\n\n    auto operator[](int i) {\n        return std::ranges::subrange(data.begin()\
    \ + i * m,\n                                     data.begin() + (i + 1) * m);\n\
    \    }\n\n    void swap(int i, int j) {\n        std::swap_ranges(data.begin()\
    \ + i * m, data.begin() + (i + 1) * m,\n                         data.begin()\
    \ + j * m);\n    }\n\n    int row_size() const {\n        return n;\n    }\n\n\
    \    int column_size() const {\n        return m;\n    }\n\n    std::pair<int,\
    \ int> size() const {\n        return {n, m};\n    }\n\n  private:\n    int n,\
    \ m;\n    std::vector<T> data;\n};\n\ntemplate <class T> std::istream &operator>>(std::istream\
    \ &os, matrix<T> &a) {\n    for (int i = 0; i < a.row_size(); i++) {\n       \
    \ for (int j = 0; j < a.column_size(); j++) {\n            os >> a[i][j];\n  \
    \      }\n    }\n    return os;\n}\n\ntemplate <class T>\nstd::ostream &operator<<(std::ostream\
    \ &os, const matrix<T> &a) {\n    for (int i = 0; i < a.row_size(); i++) {\n \
    \       for (int j = 0; j < a.column_size(); j++) {\n            os << a[i][j];\n\
    \            if (j < a.column_size() - 1) os << ' ';\n        }\n        if (i\
    \ < a.row_size() - 1) os << '\\n';\n    }\n    return os;\n}\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n\
    #include <ranges>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T>\
    \ struct matrix {\n  private:\n    using Self = matrix<T>;\n\n  public:\n    matrix(int\
    \ n_, int m_, T init_val = 0)\n        : n(n_), m(m_), data(n * m, init_val) {}\n\
    \n    matrix(const std::vector<std::vector<T>> &a)\n        : n((int)a.size()),\
    \ m((int)a[0].size()) {\n        data = std::vector(n * m);\n        for (int\
    \ i = 0; i < n; i++) {\n            std::copy(a[i].begin(), a[i].end(), data.begin()\
    \ + i * m);\n        }\n    }\n\n    Self operator+(Self &rhs) const noexcept\
    \ {\n        return Self(*this) += rhs;\n    }\n\n    Self operator-(Self &rhs)\
    \ const noexcept {\n        return Self(*this) -= rhs;\n    }\n\n    Self operator*(Self\
    \ &rhs) const noexcept {\n        return Self(*this) *= rhs;\n    }\n\n    Self\
    \ &operator+=(Self &rhs) noexcept {\n        assert(this->size() == rhs.size());\n\
    \        for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j)\
    \ {\n                data[i][j] += rhs[i][j];\n            }\n        }\n    \
    \    return *this;\n    }\n\n    Self &operator-=(Self &rhs) noexcept {\n    \
    \    assert(this->size() == rhs.size());\n        for (int i = 0; i < n; ++i)\
    \ {\n            for (int j = 0; j < m; ++j) {\n                data[i][j] -=\
    \ rhs[i][j];\n            }\n        }\n        return *this;\n    }\n\n    Self\
    \ &operator*=(Self &rhs) noexcept {\n        int h = n, w = rhs.column_size();\n\
    \        assert(m == rhs.row_size());\n        Self ret(h, w);\n        for (int\
    \ i = 0; i < h; ++i) {\n            for (int k = 0; k < m; ++k) {\n          \
    \      for (int j = 0; j < w; ++j) {\n                    ret[i][j] += (*this)[i][k]\
    \ * rhs[k][j];\n                }\n            }\n        }\n        return *this\
    \ = ret;\n    }\n\n    const auto operator[](int i) const {\n        return std::ranges::subrange(data.begin()\
    \ + i * m,\n                                     data.begin() + (i + 1) * m);\n\
    \    }\n\n    auto operator[](int i) {\n        return std::ranges::subrange(data.begin()\
    \ + i * m,\n                                     data.begin() + (i + 1) * m);\n\
    \    }\n\n    void swap(int i, int j) {\n        std::swap_ranges(data.begin()\
    \ + i * m, data.begin() + (i + 1) * m,\n                         data.begin()\
    \ + j * m);\n    }\n\n    int row_size() const {\n        return n;\n    }\n\n\
    \    int column_size() const {\n        return m;\n    }\n\n    std::pair<int,\
    \ int> size() const {\n        return {n, m};\n    }\n\n  private:\n    int n,\
    \ m;\n    std::vector<T> data;\n};\n\ntemplate <class T> std::istream &operator>>(std::istream\
    \ &os, matrix<T> &a) {\n    for (int i = 0; i < a.row_size(); i++) {\n       \
    \ for (int j = 0; j < a.column_size(); j++) {\n            os >> a[i][j];\n  \
    \      }\n    }\n    return os;\n}\n\ntemplate <class T>\nstd::ostream &operator<<(std::ostream\
    \ &os, const matrix<T> &a) {\n    for (int i = 0; i < a.row_size(); i++) {\n \
    \       for (int j = 0; j < a.column_size(); j++) {\n            os << a[i][j];\n\
    \            if (j < a.column_size() - 1) os << ' ';\n        }\n        if (i\
    \ < a.row_size() - 1) os << '\\n';\n    }\n    return os;\n}\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: matrix/base.hpp
  requiredBy:
  - matrix/gauss_jordan.hpp
  timestamp: '2024-04-19 15:44:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/System_of_Linear_Equations.test.cpp
  - test/matrix/Matrix_Product.test.cpp
  - test/matrix/Rank_of_Matrix.test.cpp
documentation_of: matrix/base.hpp
layout: document
redirect_from:
- /library/matrix/base.hpp
- /library/matrix/base.hpp.html
title: matrix/base.hpp
---
