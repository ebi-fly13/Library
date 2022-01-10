---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/kd_tree.hpp\"\n\n#include <algorithm>\n#include\
    \ <cstdint>\n#include <memory>\n#include <vector>\n\nnamespace ebi {\n\ntemplate\
    \ <class T, int D>\nstruct kd_tree {\n   private:\n    using node_ptr = std::shared_ptr<kd_tree<T,\
    \ D>>;\n\n    T dist(std::array<T, D> point) {\n        T res = 0;\n        for\
    \ (auto val : point) {\n            res += val * val;\n        }\n        return\
    \ res;\n    }\n\n   public:\n    kd_tree(const std::vector<int> &_index,\n   \
    \         const std::vector<std::array<T, D>> &points)\n        : index(_index)\
    \ {\n        const int n = index.size();\n        std::fill(min.begin(), min.end(),\
    \ std::numeric_limits<T>::max());\n        std::fill(max.begin(), max.end(), std::numeric_limits<T>::min());\n\
    \        for (auto i : index) {\n            for (int j = 0; j < D; j++) {\n \
    \               min[j] = std::min(min[j], points[i][j]);\n                max[j]\
    \ = std::max(max[j], points[i][j]);\n            }\n        }\n        if (n ==\
    \ 1) return;\n        int index_div = 0;\n        for (int i = 0; i < D; i++)\
    \ {\n            if (max[i] - min[i] > max[index_div] - min[index_div]) {\n  \
    \              index_div = i;\n            }\n        }\n        auto begin =\
    \ index.begin();\n        auto center = begin + n / 2;\n        auto end = index.end();\n\
    \        std::nth_element(begin, center, end,\n                         [&index_div,\
    \ &points](int i, int j) {\n                             return points[i][index_div]\
    \ < points[j][index_div];\n                         });\n        lch = std::make_shared<kd_tree<T,\
    \ D>>(std::vector<int>(begin, center),\n                                     \
    \         points);\n        rch = std::make_shared<kd_tree<T, D>>(std::vector<int>(center,\
    \ end),\n                                              points);\n    }\n\n   \
    \ template <class F>\n    void circle_search(const std::array<T, D> &center, T\
    \ k, F f) {\n        std::array<T, D> p;\n        for (int i = 0; i < D; i++)\
    \ {\n            p[i] = std::max(std::abs(center[i] - min[i]),\n             \
    \               std::abs(center[i] - max[i]));\n        }\n        if (dist(p)\
    \ <= k * k) {\n            for (auto i : index) {\n                f(i);\n   \
    \         }\n            return;\n        }\n        for (int i = 0; i < D; i++)\
    \ {\n            p[i] = center[i] - std::clamp(center[i], min[i], max[i]);\n \
    \       }\n        if (dist(p) > k * k) return;\n        assert(lch && rch);\n\
    \        lch->circle_search(center, k, f);\n        rch->circle_search(center,\
    \ k, f);\n    }\n\n   private:\n    std::vector<int> index;\n    std::array<T,\
    \ D> min, max;\n    node_ptr lch = nullptr;\n    node_ptr rch = nullptr;\n};\n\
    \n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cstdint>\n#include <memory>\n\
    #include <vector>\n\nnamespace ebi {\n\ntemplate <class T, int D>\nstruct kd_tree\
    \ {\n   private:\n    using node_ptr = std::shared_ptr<kd_tree<T, D>>;\n\n   \
    \ T dist(std::array<T, D> point) {\n        T res = 0;\n        for (auto val\
    \ : point) {\n            res += val * val;\n        }\n        return res;\n\
    \    }\n\n   public:\n    kd_tree(const std::vector<int> &_index,\n          \
    \  const std::vector<std::array<T, D>> &points)\n        : index(_index) {\n \
    \       const int n = index.size();\n        std::fill(min.begin(), min.end(),\
    \ std::numeric_limits<T>::max());\n        std::fill(max.begin(), max.end(), std::numeric_limits<T>::min());\n\
    \        for (auto i : index) {\n            for (int j = 0; j < D; j++) {\n \
    \               min[j] = std::min(min[j], points[i][j]);\n                max[j]\
    \ = std::max(max[j], points[i][j]);\n            }\n        }\n        if (n ==\
    \ 1) return;\n        int index_div = 0;\n        for (int i = 0; i < D; i++)\
    \ {\n            if (max[i] - min[i] > max[index_div] - min[index_div]) {\n  \
    \              index_div = i;\n            }\n        }\n        auto begin =\
    \ index.begin();\n        auto center = begin + n / 2;\n        auto end = index.end();\n\
    \        std::nth_element(begin, center, end,\n                         [&index_div,\
    \ &points](int i, int j) {\n                             return points[i][index_div]\
    \ < points[j][index_div];\n                         });\n        lch = std::make_shared<kd_tree<T,\
    \ D>>(std::vector<int>(begin, center),\n                                     \
    \         points);\n        rch = std::make_shared<kd_tree<T, D>>(std::vector<int>(center,\
    \ end),\n                                              points);\n    }\n\n   \
    \ template <class F>\n    void circle_search(const std::array<T, D> &center, T\
    \ k, F f) {\n        std::array<T, D> p;\n        for (int i = 0; i < D; i++)\
    \ {\n            p[i] = std::max(std::abs(center[i] - min[i]),\n             \
    \               std::abs(center[i] - max[i]));\n        }\n        if (dist(p)\
    \ <= k * k) {\n            for (auto i : index) {\n                f(i);\n   \
    \         }\n            return;\n        }\n        for (int i = 0; i < D; i++)\
    \ {\n            p[i] = center[i] - std::clamp(center[i], min[i], max[i]);\n \
    \       }\n        if (dist(p) > k * k) return;\n        assert(lch && rch);\n\
    \        lch->circle_search(center, k, f);\n        rch->circle_search(center,\
    \ k, f);\n    }\n\n   private:\n    std::vector<int> index;\n    std::array<T,\
    \ D> min, max;\n    node_ptr lch = nullptr;\n    node_ptr rch = nullptr;\n};\n\
    \n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/kd_tree.hpp
  requiredBy: []
  timestamp: '2022-01-10 06:38:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/kd_tree.hpp
layout: document
redirect_from:
- /library/data_structure/kd_tree.hpp
- /library/data_structure/kd_tree.hpp.html
title: data_structure/kd_tree.hpp
---
