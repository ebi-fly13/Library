#pragma once

#include <bit>

#include "../fps/fps.hpp"
#include "../fps/middle_product.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
FormalPowerSeries<mint> composition_of_fps(FormalPowerSeries<mint> f,
                                           FormalPowerSeries<mint> g) {
    auto rec = [&](auto &&self, int n, int k,
                   std::vector<mint> Q) -> std::vector<mint> {
        if (n == 1) {
            std::vector<mint> p(2 * k);
            f.resize(k);
            std::reverse(f.begin(), f.end());
            for (int i = 0; i < k; i++) {
                p[2 * i] = f[i];
            }
            return p;
        }
        auto R = Q;
        for (int i = 1; i < 2 * n * k; i += 2) {
            R[i] = -R[i];
        }
        auto QQ = convolution(Q, R);
        for (int i = 0; i < 2 * n * k; i++) {
            QQ[2 * n * k + i] += Q[i] + R[i];
        }
        std::vector<mint> nxt_Q(2 * n * k, 0);
        for (int j = 0; j < 2 * k; j++) {
            for (int i = 0; i < n / 2; i++) {
                nxt_Q[j * n + i] = QQ[2 * j * n + 2 * i];
            }
        }
        auto nxt_p = self(self, n / 2, k * 2, nxt_Q);

        std::vector<mint> pq(4 * n * k, 0);
        for (int j = 0; j < 2 * k; j++) {
            for (int i = 0; i < n / 2; i++) {
                pq[2 * n * j + 2 * i + 1] = nxt_p[n * j + i];
            }
        }
        std::vector<mint> p(2 * n * k, 0);
        for (int i = 0; i < 2 * n * k; i++) {
            p[i] = pq[2 * n * k + i];
        }
        pq.pop_back();
        auto x = middle_product(pq, R);
        for (int i = 0; i < 2 * n * k; i++) {
            p[i] += x[i];
        }
        return p;
    };
    int n = (int)std::bit_ceil(g.size());
    std::vector<mint> Q(2 * n, 0);
    for (int i = 0; i < (int)g.size(); i++) {
        Q[i] = -g[i];
    }
    auto p = rec(rec, n, 1, Q);
    p.resize(n);
    std::reverse(p.begin(), p.end());
    p.resize(g.size());
    return p;
}

}  // namespace ebi
