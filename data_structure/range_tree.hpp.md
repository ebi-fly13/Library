---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/range_tree.test.cpp
    title: test/range_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.slideshare.net/okuraofvegetable/ss-65377588
  bundledCode: "#line 2 \"data_structure/range_tree.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n#include <utility>\n#include <tuple>\n\n/*\n    reference:\
    \ https://www.slideshare.net/okuraofvegetable/ss-65377588\n*/\n\nnamespace ebi\
    \ {\n\ntemplate <class T, class S>\nstruct range_tree {\n   private:\n    void\
    \ build(std::vector<std::tuple<T, T, S>> points) {\n        std::sort(points.begin(),\
    \ points.end());\n        for (const auto &[x, y, val] : points) {\n         \
    \   xs.emplace_back(x);\n        }\n        xs.erase(std::unique(xs.begin(), xs.end()),\
    \ xs.end());\n        n = 1;\n        int sz = xs.size();\n        while (n <\
    \ sz) n <<= 1;\n        seg.resize(2 * n);\n        sum.resize(2 * n);\n     \
    \   int idx = 0;\n        for (const auto &[x, y, val] : points) {\n         \
    \   if (xs[idx] < x) idx++;\n            seg[idx + n].emplace_back(y);\n     \
    \       sum[idx + n].emplace_back(val);\n        }\n        for (int i = n - 1;\
    \ i > 0; i--) {\n            int lch = 0, rch = 0;\n            int lsz = seg[2\
    \ * i].size(), rsz = seg[2 * i + 1].size();\n            auto push_leftval = [&]()\
    \ -> void {\n                seg[i].emplace_back(seg[2 * i][lch]);\n         \
    \       sum[i].emplace_back(sum[2 * i][lch]);\n                lch++;\n      \
    \      };\n            auto push_rightval = [&]() -> void {\n                seg[i].emplace_back(seg[2\
    \ * i + 1][rch]);\n                sum[i].emplace_back(sum[2 * i + 1][rch]);\n\
    \                rch++;\n            };\n            while (lch < lsz || rch <\
    \ rsz) {\n                if (lch == lsz)\n                    push_rightval();\n\
    \                else if (rch == rsz)\n                    push_leftval();\n \
    \               else if (seg[2 * i][lch] <= seg[2 * i + 1][rch])\n           \
    \         push_leftval();\n                else\n                    push_rightval();\n\
    \            }\n        }\n        for (int i = 1; i < 2 * n; i++) {\n       \
    \     std::vector<S> s;\n            s.reserve(sum[i].size() + 1);\n         \
    \   s.emplace_back(0);\n            for(auto val: sum[i]) s.emplace_back(s.back()\
    \ + val);\n            std::swap(sum[i], s);\n        }\n    }\n\n    S prod_y(int\
    \ idx, S yl, S yr) const {\n        int l = std::lower_bound(seg[idx].begin(),\
    \ seg[idx].end(), yl) - seg[idx].begin();\n        int r = std::lower_bound(seg[idx].begin(),\
    \ seg[idx].end(), yr) - seg[idx].begin();\n        return sum[idx][r] - sum[idx][l];\n\
    \    }\n\n   public:\n    range_tree(const std::vector<std::pair<T, T>> &_points)\
    \ {\n        std::vector<std::tuple<T, T, S>> points;\n        points.reserve(_points.size());\n\
    \        for (auto &[x, y] : _points) points.emplace_back(x, y, 1);\n        build(points);\n\
    \    }\n\n    range_tree(const std::vector<std::tuple<T, T, S>> &points) {\n \
    \       build(points);\n    }\n\n    S prod(T xl, T xr, T yl, T yr) const {\n\
    \        int l = std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin() + n;\n\
    \        int r = std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin() + n;\n\
    \        S res = 0;\n        while (l < r) {\n            if(l & 1) res += prod_y(l++,\
    \ yl, yr);\n            if(r & 1) res += prod_y(--r, yl, yr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return res;\n    }\n\n   private:\n\
    \    int n;\n    std::vector<T> xs;\n    std::vector<std::vector<T>> seg;\n  \
    \  std::vector<std::vector<S>> sum;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n#include <utility>\n\
    #include <tuple>\n\n/*\n    reference: https://www.slideshare.net/okuraofvegetable/ss-65377588\n\
    */\n\nnamespace ebi {\n\ntemplate <class T, class S>\nstruct range_tree {\n  \
    \ private:\n    void build(std::vector<std::tuple<T, T, S>> points) {\n      \
    \  std::sort(points.begin(), points.end());\n        for (const auto &[x, y, val]\
    \ : points) {\n            xs.emplace_back(x);\n        }\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        n = 1;\n        int sz = xs.size();\n       \
    \ while (n < sz) n <<= 1;\n        seg.resize(2 * n);\n        sum.resize(2 *\
    \ n);\n        int idx = 0;\n        for (const auto &[x, y, val] : points) {\n\
    \            if (xs[idx] < x) idx++;\n            seg[idx + n].emplace_back(y);\n\
    \            sum[idx + n].emplace_back(val);\n        }\n        for (int i =\
    \ n - 1; i > 0; i--) {\n            int lch = 0, rch = 0;\n            int lsz\
    \ = seg[2 * i].size(), rsz = seg[2 * i + 1].size();\n            auto push_leftval\
    \ = [&]() -> void {\n                seg[i].emplace_back(seg[2 * i][lch]);\n \
    \               sum[i].emplace_back(sum[2 * i][lch]);\n                lch++;\n\
    \            };\n            auto push_rightval = [&]() -> void {\n          \
    \      seg[i].emplace_back(seg[2 * i + 1][rch]);\n                sum[i].emplace_back(sum[2\
    \ * i + 1][rch]);\n                rch++;\n            };\n            while (lch\
    \ < lsz || rch < rsz) {\n                if (lch == lsz)\n                   \
    \ push_rightval();\n                else if (rch == rsz)\n                   \
    \ push_leftval();\n                else if (seg[2 * i][lch] <= seg[2 * i + 1][rch])\n\
    \                    push_leftval();\n                else\n                 \
    \   push_rightval();\n            }\n        }\n        for (int i = 1; i < 2\
    \ * n; i++) {\n            std::vector<S> s;\n            s.reserve(sum[i].size()\
    \ + 1);\n            s.emplace_back(0);\n            for(auto val: sum[i]) s.emplace_back(s.back()\
    \ + val);\n            std::swap(sum[i], s);\n        }\n    }\n\n    S prod_y(int\
    \ idx, S yl, S yr) const {\n        int l = std::lower_bound(seg[idx].begin(),\
    \ seg[idx].end(), yl) - seg[idx].begin();\n        int r = std::lower_bound(seg[idx].begin(),\
    \ seg[idx].end(), yr) - seg[idx].begin();\n        return sum[idx][r] - sum[idx][l];\n\
    \    }\n\n   public:\n    range_tree(const std::vector<std::pair<T, T>> &_points)\
    \ {\n        std::vector<std::tuple<T, T, S>> points;\n        points.reserve(_points.size());\n\
    \        for (auto &[x, y] : _points) points.emplace_back(x, y, 1);\n        build(points);\n\
    \    }\n\n    range_tree(const std::vector<std::tuple<T, T, S>> &points) {\n \
    \       build(points);\n    }\n\n    S prod(T xl, T xr, T yl, T yr) const {\n\
    \        int l = std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin() + n;\n\
    \        int r = std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin() + n;\n\
    \        S res = 0;\n        while (l < r) {\n            if(l & 1) res += prod_y(l++,\
    \ yl, yr);\n            if(r & 1) res += prod_y(--r, yl, yr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return res;\n    }\n\n   private:\n\
    \    int n;\n    std::vector<T> xs;\n    std::vector<std::vector<T>> seg;\n  \
    \  std::vector<std::vector<S>> sum;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/range_tree.hpp
  requiredBy: []
  timestamp: '2022-03-29 17:09:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/range_tree.test.cpp
documentation_of: data_structure/range_tree.hpp
layout: document
redirect_from:
- /library/data_structure/range_tree.hpp
- /library/data_structure/range_tree.hpp.html
title: data_structure/range_tree.hpp
---
