#pragma once

#include <cassert>
#include <vector>

#include "../modint/modint_func.hpp"

namespace ebi {

template <class mint>
std::vector<mint> mul_sparse(const std::vector<mint> &f,
                             const std::vector<mint> &g) {
    int n = f.size();
    int m = g.size();
    std::vector<std::pair<int, mint>> cf, cg;
    for (int i = 0; i < n; i++) {
        if (f[i] != 0) cf.emplace_back(i, f[i]);
    }
    for (int i = 0; i < m; i++) {
        if (g[i] != 0) cg.emplace_back(i, g[i]);
    }
    std::vector<mint> h(n + m - 1);
    for (auto [i, p] : cf) {
        for (auto [j, q] : cg) {
            h[i + j] += p * q;
        }
    }
    return h;
}

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
std::vector<mint> exp_sparse(const std::vector<mint> &f, int d = -1) {
    int n = f.size();
    if (d < 0) d = n;
    std::vector<std::pair<int, mint>> ret;
    for (int i = 1; i < n; i++) {
        if (f[i] != 0) {
            ret.emplace_back(i - 1, f[i] * i);
        }
    }
    std::vector<mint> g(d);
    g[0] = 1;
    for (int i = 0; i < d - 1; i++) {
        for (auto [k, p] : ret) {
            if (i - k < 0) break;
            g[i + 1] += g[i - k] * p;
        }
        g[i + 1] *= inv<mint>(i + 1);
    }
    return g;
}

template <class mint>
std::vector<mint> log_sparse(const std::vector<mint> &f, int d = -1) {
    int n = f.size();
    if (d < 0) d = n;
    std::vector<mint> df(d);
    for (int i = 0; i < std::min(d, n - 1); i++) {
        df[i] = f[i + 1] * (i + 1);
    }
    auto dg = mul_sparse(df, inv_sparse(f));
    dg.resize(d);
    std::vector<mint> g(d);
    for (int i = 0; i < d - 1; i++) {
        g[i + 1] = dg[i] * inv<mint>(i + 1);
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
        for (const auto &[j, cf] : ret) {
            if (i + 1 - j < 0) break;
            g[i + 1] +=
                (mint(k) * mint(j) - mint(i - j + 1)) * cf * g[i + 1 - j];
        }
        g[i + 1] *= inv<mint>(i + 1);
    }
    return g;
}

template <class mint>
std::vector<mint> pow_sparse(const std::vector<mint> &f, long long k,
                             int d = -1) {
    int n = f.size();
    if (d < 0) d = n;
    assert(k >= 0);
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