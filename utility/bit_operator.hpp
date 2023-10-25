#pragma once

#include <bit>
#include <cstdint>

namespace ebi {

int bit_reverse(int n, int bit_size) {
    int rev_n = 0;
    for (int i = 0; i < bit_size; i++) {
        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);
    }
    return rev_n;
}

int msb(int x) {
    return (x == 0) ? -1 : 31 - std::countl_zero(std::uint32_t(x));
}

}  // namespace ebi