#pragma once

namespace ebi {

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while(!(n & (1<<x))) x++;
    return x;
}

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

int popcnt(int x) {
    return __builtin_popcount(x);
}

int msb(int x) {
    return (x == 0) ? -1 : 31 - __builtin_clz(x);
}

int bsf(int x) {
    return (x == 0) ? -1 : __builtin_ctz(x);
}

}  // namespace ebi