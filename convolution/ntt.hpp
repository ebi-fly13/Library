#pragma once

#include <algorithm>
#include <array>
#include <bit>
#include <cassert>
#include <vector>

#include "../math/internal_math.hpp"
#include "../modint/base.hpp"

namespace ebi {

namespace internal {

template <Modint mint, int g = internal::primitive_root<mint::mod()>>
struct ntt_info {
    static constexpr int rank2 = std::countr_zero(uint(mint::mod() - 1));

    std::array<mint, rank2 + 1> root, inv_root;

    ntt_info() {
        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
        inv_root[rank2] = root[rank2].inv();
        for (int i = rank2 - 1; i >= 0; i--) {
            root[i] = root[i + 1] * root[i + 1];
            inv_root[i] = inv_root[i + 1] * inv_root[i + 1];
        }
    }
};

template <Modint mint> void butterfly(std::vector<mint>& a) {
    static const ntt_info<mint> info;
    int n = int(a.size());
    int bit_size = std::countr_zero(a.size());
    assert(n == (int)std::bit_ceil(a.size()));

    // bit reverse
    for (int i = 0, j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1)
            ;
        if (j < i) {
            std::swap(a[i], a[j]);
        }
    }

    for (int bit = 0; bit < bit_size; bit++) {
        for (int i = 0; i < n / (1 << (bit + 1)); i++) {
            mint zeta1 = 1;
            mint zeta2 = info.root[1];
            for (int j = 0; j < (1 << bit); j++) {
                int idx = i * (1 << (bit + 1)) + j;
                int jdx = idx + (1 << bit);
                mint p1 = a[idx];
                mint p2 = a[jdx];
                a[idx] = p1 + zeta1 * p2;
                a[jdx] = p1 + zeta2 * p2;
                zeta1 *= info.root[bit + 1];
                zeta2 *= info.root[bit + 1];
            }
        }
    }
}

template <Modint mint> void butterfly_inv(std::vector<mint>& a) {
    static const ntt_info<mint> info;
    int n = int(a.size());
    int bit_size = std::countr_zero(a.size());
    assert(n == (int)std::bit_ceil(a.size()));

    // bit reverse
    for (int i = 0, j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1)
            ;
        if (j < i) {
            std::swap(a[i], a[j]);
        }
    }

    for (int bit = 0; bit < bit_size; bit++) {
        for (int i = 0; i < n / (1 << (bit + 1)); i++) {
            mint zeta1 = 1;
            mint zeta2 = info.inv_root[1];
            for (int j = 0; j < (1 << bit); j++) {
                int idx = i * (1 << (bit + 1)) + j;
                int jdx = idx + (1 << bit);
                mint p1 = a[idx];
                mint p2 = a[jdx];
                a[idx] = p1 + zeta1 * p2;
                a[jdx] = p1 + zeta2 * p2;
                zeta1 *= info.inv_root[bit + 1];
                zeta2 *= info.inv_root[bit + 1];
            }
        }
    }
    mint inv_n = mint(n).inv();
    for (int i = 0; i < n; i++) {
        a[i] *= inv_n;
    }
}

}  // namespace internal

template <Modint mint>
std::vector<mint> convolution_naive(const std::vector<mint>& f,
                                    const std::vector<mint>& g) {
    if (f.empty() || g.empty()) return {};
    int n = int(f.size()), m = int(g.size());
    std::vector<mint> c(n + m - 1);
    if (n < m) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                c[i + j] += f[i] * g[j];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i + j] += f[i] * g[j];
            }
        }
    }
    return c;
}

template <Modint mint>
std::vector<mint> convolution(const std::vector<mint>& f,
                              const std::vector<mint>& g) {
    if (f.empty() || g.empty()) return {};
    if (std::min(f.size(), g.size()) < 60) return convolution_naive(f, g);
    int n = std::bit_ceil(f.size() + g.size() - 1);
    std::vector<mint> a(n), b(n);
    std::copy(f.begin(), f.end(), a.begin());
    std::copy(g.begin(), g.end(), b.begin());
    internal::butterfly(a);
    internal::butterfly(b);
    for (int i = 0; i < n; i++) {
        a[i] *= b[i];
    }
    internal::butterfly_inv(a);
    a.resize(f.size() + g.size() - 1);
    return a;
}

}  // namespace ebi