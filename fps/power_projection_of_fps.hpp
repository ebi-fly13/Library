#pragma once

#include <algorithm>
#include <bit>
#include <cassert>

#include "../fps/fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

// sum_j w_j [x^j] f^i, for i = 0,1,...,m
template <Modint mint>
std::vector<mint> power_projection(const FormalPowerSeries<mint> &f,
                                   const std::vector<mint> &w, int m) {
    assert(f.size() == w.size());
    if (f.empty()) {
        return std::vector<mint>(m + 1, 0);
    }
    assert(f[0] == 0);
    int n = (int)std::bit_ceil(f.size());
    std::vector<mint> P(2 * n, 0), Q(2 * n, 0);
    for (int i = 0; i < (int)f.size(); i++) {
        P[n - 1 - i] = w[i];
        Q[i] = -f[i];
    }
    int k = 1;
    while (n > 1) {
        auto R = Q;
        for (int i = 1; i < 2 * n * k; i += 2) {
            R[i] = -R[i];
        }
        auto PQ = convolution(P, R), QQ = convolution(Q, R);
        PQ.resize(4 * n * k);
        QQ.resize(4 * n * k);
        for (int i = 0; i < 2 * n * k; i++) {
            PQ[2 * n * k + i] += P[i];
            QQ[2 * n * k + i] += Q[i] + R[i];
        }
        std::fill(P.begin(), P.end(), 0);
        std::fill(Q.begin(), Q.end(), 0);
        for (int j = 0; j < 2 * k; j++) {
            for (int i = 0; i < n / 2; i++) {
                P[j * n + i] = PQ[2 * j * n + 2 * i + 1];
                Q[j * n + i] = QQ[2 * j * n + 2 * i];
            }
        }
        n /= 2;
        k *= 2;
    }
    std::vector<mint> p(k);
    for (int i = 0; i < k; i++) p[i] = P[2 * i];
    std::reverse(p.begin(), p.end());
    p.resize(m + 1);
    return p;
}

}  // namespace ebi