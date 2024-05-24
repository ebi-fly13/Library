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
    std::vector P(n, std::vector<mint>(1, 0)), Q(n, std::vector<mint>(1, 0));
    for (int i = 0; i < (int)f.size(); i++) {
        P[n - 1 - i][0] = w[i];
        Q[i][0] = -f[i];
    }
    int k = 1;
    while (n > 1) {
        auto R = Q;
        for (int i = 1; i < n; i += 2) {
            for (int j = 0; j < k; j++) {
                R[i][j] = -R[i][j];
            }
        }
        auto conv_2d = [&](std::vector<std::vector<mint>> &a,
                           std::vector<std::vector<mint>> &b)
            -> std::vector<std::vector<mint>> {
            FormalPowerSeries<mint> f(2 * n * k, 0), g(2 * n * k, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    f[2 * i * k + j] = a[i][j];
                    g[2 * i * k + j] = b[i][j];
                }
            }
            f = f * g;
            f.resize(4 * n * k);
            std::vector c(2 * n, std::vector<mint>(2 * k, 0));
            for (int i = 0; i < 2 * n; i++) {
                for (int j = 0; j < 2 * k; j++) {
                    c[i][j] = f[i * 2 * k + j];
                }
            }
            return c;
        };
        auto PQ = conv_2d(P, R), QQ = conv_2d(Q, R);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                PQ[i][j + k] += P[i][j];
                QQ[i][j + k] += Q[i][j] + R[i][j];
            }
        }
        for (int i = 0; i < n / 2; i++) {
            P[i] = PQ[2 * i + 1];
            Q[i] = QQ[2 * i];
        }
        P.resize(n / 2);
        Q.resize(n / 2);
        n /= 2;
        k *= 2;
    }
    auto p = P[0];
    std::reverse(p.begin(), p.end());
    p.resize(m + 1);
    return p;
}

}  // namespace ebi