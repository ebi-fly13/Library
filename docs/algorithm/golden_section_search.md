---
title: Golden section search
documentation_of: //algorithm/golden_section_search.hpp
---

## 説明

整数範囲で、黄金分割探索を行う。

### golden_section_search(f, min, max, compare)

凸な関数 $f$ に対して、 $[min, max]$ で黄金分割探索をして最小値を求める。compareに比較関数を与えることで最大値を求めることもできる。 $O(\log (\max - \min))$