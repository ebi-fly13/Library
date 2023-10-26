#pragma once

#include <array>
#include <cassert>
#include <vector>
#include <bit>

namespace ebi {

template <class T, int LIM = 20>
std::vector<std::array<T, LIM + 1>> ranked_zeta(const std::vector<T> &f) {
    int n = std::bit_width(f.size()) - 1;
    assert(n <= LIM);
    assert((int)f.size() == (1 << n));
    std::vector<std::array<T, LIM + 1>> rf(1 << n);
    for (int s = 0; s < (1 << n); s++) rf[s][std::popcount(uint(s))] = f[s];
    for (int i = 0; i < n; i++) {
        int w = 1 << i;
        for (int p = 0; p < (1 << n); p += 2 * w) {
            for (int s = p; s < p + w; s++) {
                int t = s | (1 << i);
                for (int d = 0; d <= n; d++) rf[t][d] += rf[s][d];
            }
        }
    }
    return rf;
}

template <class T, int LIM = 20>
std::vector<T> ranked_mobius(std::vector<std::array<T, LIM + 1>> rf) {
    int n = std::bit_width(rf.size()) - 1;
    assert((int)rf.size() == (1 << n));
    for (int i = 0; i < n; i++) {
        int w = 1 << i;
        for (int p = 0; p < (1 << n); p += 2 * w) {
            for (int s = p; s < p + w; s++) {
                int t = s | (1 << i);
                for (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];
            }
        }
    }
    std::vector<T> f(1 << n);
    for (int s = 0; s < (1 << n); s++) {
        f[s] = rf[s][std::popcount(uint(s))];
    }
    return f;
}

}  // namespace ebi
