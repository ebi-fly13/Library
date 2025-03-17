---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: matrix/base.hpp
    title: matrix/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/maximum_matching_size.hpp
    title: Maximum Matching Size
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"matrix/gauss_jordan.hpp\"\n\n#line 2 \"matrix/base.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <ranges>\n\
    #include <vector>\n\nnamespace ebi {\n\ntemplate <class T> struct matrix;\n\n\
    template <class T> matrix<T> identify_matrix(int n) {\n    matrix<T> a(n, n);\n\
    \    for (int i = 0; i < n; i++) {\n        a[i][i] = 1;\n    }\n    return a;\n\
    }\n\ntemplate <class T> struct matrix {\n  private:\n    using Self = matrix<T>;\n\
    \n  public:\n    matrix(int n_, int m_, T init_val = 0)\n        : n(n_), m(m_),\
    \ data(n * m, init_val) {}\n\n    matrix(const std::vector<std::vector<T>> &a)\n\
    \        : n((int)a.size()), m((int)a[0].size()) {\n        data = std::vector(n\
    \ * m);\n        for (int i = 0; i < n; i++) {\n            std::copy(a[i].begin(),\
    \ a[i].end(), data.begin() + i * m);\n        }\n    }\n\n    Self operator+(Self\
    \ &rhs) const noexcept {\n        return Self(*this) += rhs;\n    }\n\n    Self\
    \ operator-(Self &rhs) const noexcept {\n        return Self(*this) -= rhs;\n\
    \    }\n\n    Self operator*(Self &rhs) const noexcept {\n        return Self(*this)\
    \ *= rhs;\n    }\n\n    Self operator/(Self &rhs) const noexcept {\n        return\
    \ Self(*this) /= rhs;\n    }\n\n    friend Self operator*(const T &lhs, const\
    \ Self &rhs) {\n        return Self(rhs) *= lhs;\n    }\n\n    friend Self operator*(const\
    \ Self &lhs, const T &rhs) {\n        return Self(lhs) *= rhs;\n    }\n\n    std::vector<T>\
    \ operator*(const std::vector<T> &rhs) noexcept {\n        assert(m == (int)rhs.size());\n\
    \        std::vector<T> res(n, 0);\n        for (int i = 0; i < n; i++) {\n  \
    \          for (int j = 0; j < m; j++) {\n                res[i] += (*this)[i][j]\
    \ * rhs[j];\n            }\n        }\n        return res;\n    }\n\n    Self\
    \ &operator+=(Self &rhs) noexcept {\n        assert(this->size() == rhs.size());\n\
    \        for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j)\
    \ {\n                (*this)[i][j] += rhs[i][j];\n            }\n        }\n \
    \       return *this;\n    }\n\n    Self &operator-=(Self &rhs) noexcept {\n \
    \       assert(this->size() == rhs.size());\n        for (int i = 0; i < n; ++i)\
    \ {\n            for (int j = 0; j < m; ++j) {\n                (*this)[i][j]\
    \ -= rhs[i][j];\n            }\n        }\n        return *this;\n    }\n\n  \
    \  Self &operator*=(Self &rhs) noexcept {\n        int h = n, w = rhs.column_size();\n\
    \        assert(m == rhs.row_size());\n        Self ret(h, w);\n        for (int\
    \ i = 0; i < h; ++i) {\n            for (int k = 0; k < m; ++k) {\n          \
    \      for (int j = 0; j < w; ++j) {\n                    ret[i][j] += (*this)[i][k]\
    \ * rhs[k][j];\n                }\n            }\n        }\n        return *this\
    \ = ret;\n    }\n\n    Self &operator/=(const Self &rhs) noexcept {\n        auto\
    \ ret = rhs.inv();\n        assert(ret);\n        return *this *= ret.value();\n\
    \    }\n\n    Self &operator*=(const T &rhs) noexcept {\n        for (int i =\
    \ 0; i < n; i++) {\n            for (int j = 0; j < m; j++) {\n              \
    \  (*this)[i][j] *= rhs;\n            }\n        }\n        return *this;\n  \
    \  }\n\n    const auto operator[](int i) const {\n        return std::ranges::subrange(data.begin()\
    \ + i * m,\n                                     data.begin() + (i + 1) * m);\n\
    \    }\n\n    auto operator[](int i) {\n        return std::ranges::subrange(data.begin()\
    \ + i * m,\n                                     data.begin() + (i + 1) * m);\n\
    \    }\n\n    void swap(int i, int j) {\n        std::swap_ranges(data.begin()\
    \ + i * m, data.begin() + (i + 1) * m,\n                         data.begin()\
    \ + j * m);\n    }\n\n    int rank() const;\n\n    Self transposition() const\
    \ {\n        Self res(m, n);\n        for (int i = 0; i < n; i++) {\n        \
    \    for (int j = 0; j < m; j++) {\n                res[j][i] = (*this)[i][j];\n\
    \            }\n        }\n        return res;\n    }\n\n    std::optional<Self>\
    \ inv() const {\n        assert(row_size() == column_size());\n        Self a\
    \ = *this;\n        Self b = identify_matrix<T>(n);\n        for (int r = 0; r\
    \ < n; r++) {\n            for (int i = r; i < n; i++) {\n                if (a[i][r]\
    \ != 0) {\n                    a.swap(r, i);\n                    b.swap(r, i);\n\
    \                    break;\n                }\n            }\n            if\
    \ (a[r][r] == 0) return std::nullopt;\n            T x = a[r][r].inv();\n    \
    \        for (int j = 0; j < n; j++) {\n                if (r < j) a[r][j] *=\
    \ x;\n                b[r][j] *= x;\n            }\n            for (int i = 0;\
    \ i < n; i++) {\n                if (i == r) continue;\n                for (int\
    \ j = 0; j < n; j++) {\n                    if (r < j) a[i][j] -= a[i][r] * a[r][j];\n\
    \                    b[i][j] -= a[i][r] * b[r][j];\n                }\n      \
    \      }\n        }\n        return b;\n    }\n\n    Self pow(long long k) const\
    \ {\n        assert(row_size() == column_size() && k >= 0);\n        Self res\
    \ = identify_matrix<T>(row_size());\n        Self x = *this;\n        while (k)\
    \ {\n            if (k & 1) res *= x;\n            x *= x;\n            k >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    int row_size() const {\n  \
    \      return n;\n    }\n\n    int column_size() const {\n        return m;\n\
    \    }\n\n    std::pair<int, int> size() const {\n        return {n, m};\n   \
    \ }\n\n  private:\n    int n, m;\n    std::vector<T> data;\n};\n\ntemplate <class\
    \ T> T det(matrix<T> a) {\n    assert(a.row_size() == a.column_size());\n    T\
    \ d = 1;\n    int n = a.row_size();\n    for (int r = 0; r < n; r++) {\n     \
    \   if (a[r][r] == 0) {\n            for (int i = r + 1; i < n; i++) {\n     \
    \           if (a[i][r] != 0) {\n                    a.swap(r, i);\n         \
    \           d = -d;\n                }\n            }\n        }\n        if (a[r][r]\
    \ == 0) return 0;\n        d *= a[r][r];\n        T inv = a[r][r].inv();\n   \
    \     for (int i = r + 1; i < n; i++) {\n            T x = a[i][r] * inv;\n  \
    \          for (int j = r; j < n; j++) {\n                a[i][j] -= x * a[r][j];\n\
    \            }\n        }\n    }\n    return d;\n}\n\ntemplate <class T> std::istream\
    \ &operator>>(std::istream &os, matrix<T> &a) {\n    for (int i = 0; i < a.row_size();\
    \ i++) {\n        for (int j = 0; j < a.column_size(); j++) {\n            os\
    \ >> a[i][j];\n        }\n    }\n    return os;\n}\n\ntemplate <class T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const matrix<T> &a) {\n    for (int i = 0; i <\
    \ a.row_size(); i++) {\n        for (int j = 0; j < a.column_size(); j++) {\n\
    \            os << a[i][j];\n            if (j < a.column_size() - 1) os << '\
    \ ';\n        }\n        if (i < a.row_size() - 1) os << '\\n';\n    }\n    return\
    \ os;\n}\n\n}  // namespace ebi\n#line 4 \"matrix/gauss_jordan.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T> int find_pivot(const matrix<T> &a, int r, int w)\
    \ {\n    for (int i = r; i < a.row_size(); i++) {\n        if (a[i][w] != 0) return\
    \ i;\n    }\n    return -1;\n}\n\ntemplate <class T> int gauss_jordan(matrix<T>\
    \ &a) {\n    int h = a.row_size(), w = a.column_size();\n    int rank = 0;\n \
    \   for (int j = 0; j < w; j++) {\n        int pivot = find_pivot(a, rank, j);\n\
    \        if (pivot == -1) continue;\n        a.swap(rank, pivot);\n        T inv\
    \ = T(1) / a[rank][j];\n        for (int k = j; k < w; k++) {\n            a[rank][k]\
    \ *= inv;\n        }\n        for (int i = 0; i < h; i++) {\n            if (i\
    \ != rank && a[i][j] != 0) {\n                T x = a[i][j];\n               \
    \ for (int k = j; k < w; k++) {\n                    a[i][k] -= a[rank][k] * x;\n\
    \                }\n            }\n        }\n        rank++;\n    }\n    return\
    \ rank;\n}\n\ntemplate <class T> int matrix<T>::rank() const {\n    matrix<T>\
    \ a = *this;\n    return gauss_jordan(a);\n}\n\ntemplate <class T> int gauss_jordan(matrix<T>\
    \ &a, std::vector<T> &b) {\n    int h = a.row_size(), w = a.column_size();\n \
    \   assert(h == (int)b.size());\n    int rank = 0;\n    for (int j = 0; j < w;\
    \ j++) {\n        int pivot = find_pivot(a, rank, j);\n        if (pivot == -1)\
    \ continue;\n        a.swap(rank, pivot);\n        std::swap(b[rank], b[pivot]);\n\
    \        T inv = T(1) / a[rank][j];\n        for (int k = j; k < w; k++) {\n \
    \           a[rank][k] *= inv;\n        }\n        b[rank] *= inv;\n        for\
    \ (int i = 0; i < h; i++) {\n            if (i != rank && a[i][j] != 0) {\n  \
    \              T x = a[i][j];\n                for (int k = j; k < w; k++) {\n\
    \                    a[i][k] -= a[rank][k] * x;\n                }\n         \
    \       b[i] -= b[rank] * x;\n            }\n        }\n        rank++;\n    }\n\
    \    return rank;\n}\n\ntemplate <class T>\nstd::optional<std::vector<std::vector<T>>>\
    \ solve_linear_equations(\n    matrix<T> a, std::vector<T> b) {\n    assert(a.row_size()\
    \ == (int)b.size());\n    int rank = gauss_jordan(a, b);\n    int h = a.row_size(),\
    \ w = a.column_size();\n    for (int i = rank; i < h; i++) {\n        if (b[i]\
    \ != 0) return std::nullopt;\n    }\n    std::vector res(1, std::vector<T>(w,\
    \ 0));\n    std::vector<int> pivot(w, -1);\n    {\n        int p = 0;\n      \
    \  for (int i = 0; i < rank; i++) {\n            while (a[i][p] == 0) p++;\n \
    \           res[0][p] = b[i];\n            pivot[p] = i;\n        }\n    }\n \
    \   for (int j = 0; j < w; j++) {\n        if (pivot[j] == -1) {\n           \
    \ std::vector<T> x(w, 0);\n            x[j] = -1;\n            for (int i = 0;\
    \ i < j; i++) {\n                if (pivot[i] != -1) x[i] = a[pivot[i]][j];\n\
    \            }\n            res.emplace_back(x);\n        }\n    }\n    return\
    \ res;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include \"../matrix/base.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T> int find_pivot(const matrix<T> &a, int r, int w) {\n    for (int i\
    \ = r; i < a.row_size(); i++) {\n        if (a[i][w] != 0) return i;\n    }\n\
    \    return -1;\n}\n\ntemplate <class T> int gauss_jordan(matrix<T> &a) {\n  \
    \  int h = a.row_size(), w = a.column_size();\n    int rank = 0;\n    for (int\
    \ j = 0; j < w; j++) {\n        int pivot = find_pivot(a, rank, j);\n        if\
    \ (pivot == -1) continue;\n        a.swap(rank, pivot);\n        T inv = T(1)\
    \ / a[rank][j];\n        for (int k = j; k < w; k++) {\n            a[rank][k]\
    \ *= inv;\n        }\n        for (int i = 0; i < h; i++) {\n            if (i\
    \ != rank && a[i][j] != 0) {\n                T x = a[i][j];\n               \
    \ for (int k = j; k < w; k++) {\n                    a[i][k] -= a[rank][k] * x;\n\
    \                }\n            }\n        }\n        rank++;\n    }\n    return\
    \ rank;\n}\n\ntemplate <class T> int matrix<T>::rank() const {\n    matrix<T>\
    \ a = *this;\n    return gauss_jordan(a);\n}\n\ntemplate <class T> int gauss_jordan(matrix<T>\
    \ &a, std::vector<T> &b) {\n    int h = a.row_size(), w = a.column_size();\n \
    \   assert(h == (int)b.size());\n    int rank = 0;\n    for (int j = 0; j < w;\
    \ j++) {\n        int pivot = find_pivot(a, rank, j);\n        if (pivot == -1)\
    \ continue;\n        a.swap(rank, pivot);\n        std::swap(b[rank], b[pivot]);\n\
    \        T inv = T(1) / a[rank][j];\n        for (int k = j; k < w; k++) {\n \
    \           a[rank][k] *= inv;\n        }\n        b[rank] *= inv;\n        for\
    \ (int i = 0; i < h; i++) {\n            if (i != rank && a[i][j] != 0) {\n  \
    \              T x = a[i][j];\n                for (int k = j; k < w; k++) {\n\
    \                    a[i][k] -= a[rank][k] * x;\n                }\n         \
    \       b[i] -= b[rank] * x;\n            }\n        }\n        rank++;\n    }\n\
    \    return rank;\n}\n\ntemplate <class T>\nstd::optional<std::vector<std::vector<T>>>\
    \ solve_linear_equations(\n    matrix<T> a, std::vector<T> b) {\n    assert(a.row_size()\
    \ == (int)b.size());\n    int rank = gauss_jordan(a, b);\n    int h = a.row_size(),\
    \ w = a.column_size();\n    for (int i = rank; i < h; i++) {\n        if (b[i]\
    \ != 0) return std::nullopt;\n    }\n    std::vector res(1, std::vector<T>(w,\
    \ 0));\n    std::vector<int> pivot(w, -1);\n    {\n        int p = 0;\n      \
    \  for (int i = 0; i < rank; i++) {\n            while (a[i][p] == 0) p++;\n \
    \           res[0][p] = b[i];\n            pivot[p] = i;\n        }\n    }\n \
    \   for (int j = 0; j < w; j++) {\n        if (pivot[j] == -1) {\n           \
    \ std::vector<T> x(w, 0);\n            x[j] = -1;\n            for (int i = 0;\
    \ i < j; i++) {\n                if (pivot[i] != -1) x[i] = a[pivot[i]][j];\n\
    \            }\n            res.emplace_back(x);\n        }\n    }\n    return\
    \ res;\n}\n\n}  // namespace ebi"
  dependsOn:
  - matrix/base.hpp
  isVerificationFile: false
  path: matrix/gauss_jordan.hpp
  requiredBy:
  - graph/maximum_matching_size.hpp
  timestamp: '2024-07-18 01:45:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/System_of_Linear_Equations.test.cpp
  - test/matrix/Rank_of_Matrix.test.cpp
documentation_of: matrix/gauss_jordan.hpp
layout: document
redirect_from:
- /library/matrix/gauss_jordan.hpp
- /library/matrix/gauss_jordan.hpp.html
title: matrix/gauss_jordan.hpp
---
