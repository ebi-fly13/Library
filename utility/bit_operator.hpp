#pragma once

namespace ebi {

int popcnt(int x) {
    return __builtin_popcount(x);
}

int topbit(int x) {
    return (x == 0) ? -1 : 31 - __builtin_clz(x);
}

int lowbit(int x) {
    return (x == 0) ? -1 : __builtin_ctz(x);
}

}  // namespace ebi