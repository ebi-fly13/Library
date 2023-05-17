#pragma once

namespace ebi {

namespace internal {

constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

}

}