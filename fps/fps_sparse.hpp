#pragma once

#include <cassert>
#include <vector>

namespace ebi {

template <class mint>
std::vector<mint> inv_sparse(const std::vector<mint> &f, int d = -1) {
    assert(f[0] != 0);
    if (d < 0) {
        d = f.size();
    }
    std::vector<std::pair<int, mint>> ret;
    for (int i = 1; i < int(f.size()); i++) {
        if (f[i] != 0) {
            ret.emplace_back(i, f[i]);
        }
    }
    std::vector<mint> g(d);
    g[0] = f[0].inv();
    for (int i = 1; i < d; i++) {
        for (auto [k, p] : ret) {
            if (i - k < 0) break;
            g[i] -= g[i - k] * p;
        }
        g[i] *= g[0];
    }
    return g;
}

template <class mint>
std::vector<mint> pow_sparse_1(const std::vector<mint> &f, long long k,
                               int d = -1) {
    int n = f.size();
    assert(n == 0 || f[0] == 1);
    std::vector<std::pair<int, mint>> ret;
    for (int i = 1; i < n; i++) {
        if (f[i] != 0) ret.emplace_back(i, f[i]);
    }
    std::vector<mint> g(d);
    g[0] = 1;
    for (int i = 0; i < d - 1; i++) {
        for (auto [d, cf] : ret) {
            if (i + 1 - d < 0) break;
            g[i + 1] +=
                (mint(k) * mint(d) - mint(i - d + 1)) * cf * g[i + 1 - d];
        }
        g[i + 1] /= i + 1;
    }
    return g;
}

template <class mint>
std::vector<mint> pow_sparse(const std::vector<mint> &f, long long k,
                             int d = -1) {
    int n = f.size();
    if (d < 0) d = n;
    if (k == 0) {
        std::vector<mint> g(d);
        if (d > 0) g[0] = 1;
        return g;
    }
    for (int i = 0; i < n; i++) {
        if (f[i] != 0) {
            mint rev = f[i].inv();
            std::vector<mint> f2(n - i);
            for (int j = i; j < n; j++) {
                f2[j - i] = f[j] * rev;
            }
            f2 = pow_sparse_1(f2, k, d);
            mint fk = f[i].pow(k);
            std::vector<mint> g(d);
            for (int j = 0; j < int(f2.size()); j++) {
                if (j + i * k >= d) break;
                g[j + i * k] = f2[j] * fk;
            }
            return g;
        }
        if (i >= (d + k - 1) / k) break;
    }
    return std::vector<mint>(d);
}

}  // namespace ebi