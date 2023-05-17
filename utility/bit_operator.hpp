#pragma once

namespace ebi {

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bit_reverse(int n, int bit_size) {
    int rev_n = 0;
    for (int i = 0; i < bit_size; i++) {
        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);
    }
    return rev_n;
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