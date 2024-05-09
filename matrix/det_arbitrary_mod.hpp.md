---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix/base.hpp
    title: matrix/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix/Determinant_of_Matrix_Arbitrary_Mod.test.cpp
    title: test/matrix/Determinant_of_Matrix_Arbitrary_Mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/det_arbitrary_mod.hpp\"\n\n#include <cassert>\n\n\
    #line 2 \"matrix/base.hpp\"\n\n#include <algorithm>\n#line 5 \"matrix/base.hpp\"\
    \n#include <iostream>\n#include <ranges>\n#include <vector>\n\nnamespace ebi {\n\
    \ntemplate <class T> struct matrix;\n\ntemplate <class T> matrix<T> identify_matrix(int\
    \ n) {\n    matrix<T> a(n, n);\n    for (int i = 0; i < n; i++) {\n        a[i][i]\
    \ = 1;\n    }\n    return a;\n}\n\ntemplate <class T> struct matrix {\n  private:\n\
    \    using Self = matrix<T>;\n\n  public:\n    matrix(int n_, int m_, T init_val\
    \ = 0)\n        : n(n_), m(m_), data(n * m, init_val) {}\n\n    matrix(const std::vector<std::vector<T>>\
    \ &a)\n        : n((int)a.size()), m((int)a[0].size()) {\n        data = std::vector(n\
    \ * m);\n        for (int i = 0; i < n; i++) {\n            std::copy(a[i].begin(),\
    \ a[i].end(), data.begin() + i * m);\n        }\n    }\n\n    Self operator+(Self\
    \ &rhs) const noexcept {\n        return Self(*this) += rhs;\n    }\n\n    Self\
    \ operator-(Self &rhs) const noexcept {\n        return Self(*this) -= rhs;\n\
    \    }\n\n    Self operator*(Self &rhs) const noexcept {\n        return Self(*this)\
    \ *= rhs;\n    }\n\n    Self operator/(Self &rhs) const noexcept {\n        return\
    \ Self(*this) /= rhs;\n    }\n\n    friend Self operator*(const T &lhs, const\
    \ Self &rhs) {\n        return Self(rhs) *= lhs;\n    }\n\n    friend Self operator*(const\
    \ Self &lhs, const T &rhs) {\n        return Self(lhs) *= rhs;\n    }\n\n    Self\
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
    \ + j * m);\n    }\n\n    Self transposition() const {\n        Self res(m, n);\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                res[j][i] = data[i][j];\n            }\n        }\n     \
    \   return res;\n    }\n\n    std::optional<Self> inv() const {\n        assert(row_size()\
    \ == column_size());\n        Self a = *this;\n        Self b = identify_matrix<T>(n);\n\
    \        for (int r = 0; r < n; r++) {\n            for (int i = r; i < n; i++)\
    \ {\n                if (a[i][r] != 0) {\n                    a.swap(r, i);\n\
    \                    b.swap(r, i);\n                    break;\n             \
    \   }\n            }\n            if (a[r][r] == 0) return std::nullopt;\n   \
    \         T x = a[r][r].inv();\n            for (int j = 0; j < n; j++) {\n  \
    \              if (r < j) a[r][j] *= x;\n                b[r][j] *= x;\n     \
    \       }\n            for (int i = 0; i < n; i++) {\n                if (i ==\
    \ r) continue;\n                for (int j = 0; j < n; j++) {\n              \
    \      if (r < j) a[i][j] -= a[i][r] * a[r][j];\n                    b[i][j] -=\
    \ a[i][r] * b[r][j];\n                }\n            }\n        }\n        return\
    \ b;\n    }\n\n    Self pow(long long k) const {\n        assert(row_size() ==\
    \ column_size() && k >= 0);\n        Self res = identify_matrix<T>(row_size());\n\
    \        Self x = *this;\n        while (k) {\n            if (k & 1) res *= x;\n\
    \            x *= x;\n            k >>= 1;\n        }\n        return res;\n \
    \   }\n\n    int row_size() const {\n        return n;\n    }\n\n    int column_size()\
    \ const {\n        return m;\n    }\n\n    std::pair<int, int> size() const {\n\
    \        return {n, m};\n    }\n\n  private:\n    int n, m;\n    std::vector<T>\
    \ data;\n};\n\ntemplate <class T> T det(matrix<T> a) {\n    assert(a.row_size()\
    \ == a.column_size());\n    T d = 1;\n    int n = a.row_size();\n    for (int\
    \ r = 0; r < n; r++) {\n        if (a[r][r] == 0) {\n            for (int i =\
    \ r + 1; i < n; i++) {\n                if (a[i][r] != 0) {\n                \
    \    a.swap(r, i);\n                    d = -d;\n                }\n         \
    \   }\n        }\n        if (a[r][r] == 0) return 0;\n        d *= a[r][r];\n\
    \        T inv = a[r][r].inv();\n        for (int i = r + 1; i < n; i++) {\n \
    \           T x = a[i][r] * inv;\n            for (int j = r; j < n; j++) {\n\
    \                a[i][j] -= x * a[r][j];\n            }\n        }\n    }\n  \
    \  return d;\n}\n\ntemplate <class T> std::istream &operator>>(std::istream &os,\
    \ matrix<T> &a) {\n    for (int i = 0; i < a.row_size(); i++) {\n        for (int\
    \ j = 0; j < a.column_size(); j++) {\n            os >> a[i][j];\n        }\n\
    \    }\n    return os;\n}\n\ntemplate <class T>\nstd::ostream &operator<<(std::ostream\
    \ &os, const matrix<T> &a) {\n    for (int i = 0; i < a.row_size(); i++) {\n \
    \       for (int j = 0; j < a.column_size(); j++) {\n            os << a[i][j];\n\
    \            if (j < a.column_size() - 1) os << ' ';\n        }\n        if (i\
    \ < a.row_size() - 1) os << '\\n';\n    }\n    return os;\n}\n\n}  // namespace\
    \ ebi\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\
    \n#include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint\
    \ = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n   \
    \ a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n\
    };\n\ntemplate <Modint mint> std::istream &operator>>(std::istream &os, mint &a)\
    \ {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate\
    \ <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const mint &a) {\n\
    \    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"matrix/det_arbitrary_mod.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint> mint det_arbitrary_mod(matrix<mint>\
    \ a) {\n    assert(a.row_size() == a.column_size());\n    bool sgn = true;\n \
    \   int n = a.row_size();\n    for (int r = 0; r < n; r++) {\n        if (a[r][r]\
    \ == 0) {\n            for (int i = r + 1; i < n; i++) {\n                if (a[i][r]\
    \ != 0) {\n                    sgn = !sgn;\n                    a.swap(r, i);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     if (a[r][r] == 0) return 0;\n        for (int i = r + 1; i < n; i++) {\n\
    \            while (a[i][r] != 0) {\n                long long q = a[r][r].val()\
    \ / a[i][r].val();\n                for (int j = r; j < n; j++) {\n          \
    \          a[r][j] -= a[i][j] * q;\n                }\n                a.swap(r,\
    \ i);\n                sgn = !sgn;\n            }\n        }\n    }\n    mint\
    \ d = sgn ? 1 : -1;\n    for (int i = 0; i < n; i++) d *= a[i][i];\n    return\
    \ d;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n\n#include \"../matrix/base.hpp\"\n#include\
    \ \"../modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> mint det_arbitrary_mod(matrix<mint>\
    \ a) {\n    assert(a.row_size() == a.column_size());\n    bool sgn = true;\n \
    \   int n = a.row_size();\n    for (int r = 0; r < n; r++) {\n        if (a[r][r]\
    \ == 0) {\n            for (int i = r + 1; i < n; i++) {\n                if (a[i][r]\
    \ != 0) {\n                    sgn = !sgn;\n                    a.swap(r, i);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     if (a[r][r] == 0) return 0;\n        for (int i = r + 1; i < n; i++) {\n\
    \            while (a[i][r] != 0) {\n                long long q = a[r][r].val()\
    \ / a[i][r].val();\n                for (int j = r; j < n; j++) {\n          \
    \          a[r][j] -= a[i][j] * q;\n                }\n                a.swap(r,\
    \ i);\n                sgn = !sgn;\n            }\n        }\n    }\n    mint\
    \ d = sgn ? 1 : -1;\n    for (int i = 0; i < n; i++) d *= a[i][i];\n    return\
    \ d;\n}\n\n}  // namespace ebi"
  dependsOn:
  - matrix/base.hpp
  - modint/base.hpp
  isVerificationFile: false
  path: matrix/det_arbitrary_mod.hpp
  requiredBy: []
  timestamp: '2024-04-20 12:21:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/Determinant_of_Matrix_Arbitrary_Mod.test.cpp
documentation_of: matrix/det_arbitrary_mod.hpp
layout: document
redirect_from:
- /library/matrix/det_arbitrary_mod.hpp
- /library/matrix/det_arbitrary_mod.hpp.html
title: matrix/det_arbitrary_mod.hpp
---