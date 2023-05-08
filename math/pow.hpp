#pragma once

#include "../utility/int_alias.hpp"

namespace ebi {

template <class T> T pow(T x, u64 n, u64 mod = -1) {
    T res = 1;
    if (mod > 0) {
        while (n > 0) {
            if (n & 1) {
                res *= x;
                res %= mod;
            }
            x = x * x;
            x %= mod;
            n >>= 1;
        }
        return res;
    }
    while (n > 0) {
        if (n & 1) {
            res *= x;
        }
        x = x * x;
        n >>= 1;
    }
    return res;
}

}  // namespace ebi