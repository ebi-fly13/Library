---
title: $\sqrt{f}$
documentation_of: //fps/fps_sqrt.hpp
---

### sqrt(int d)

形式的べき級数 $f$ について $\sqrt{f}$ が存在するなら求める。存在しない場合は `std::nullopt`を返す。
疎な場合は非負の要素数を $M$ として $O(NM)$。密な場合は $O(N\log N)$