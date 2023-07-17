#pragma once

#include <array>
#include <cassert>
#include <type_traits>
#include <vector>

#include "../math/internal_math.hpp"
#include "../utility/bit_operator.hpp"
#include "../utility/modint_base.hpp"

namespace ebi {

namespace internal {

template <class mint, int g = internal::primitive_root<mint::mod()>,
          internal::is_static_modint_t<mint>* = nullptr>
struct ntt_info {
    static constexpr int rank2 = bsf_constexpr(mint::mod() - 1);

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

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly(std::vector<mint>& a) {
    static const ntt_info<mint> info;
    int n = int(a.size());
    int bit_size = bsf(n);
    assert(n == 1 << ceil_pow2(n));
    // bit reverse
    for (int i = 0; i < n; i++) {
        int rev = bit_reverse(i, bit_size);
        if (i < rev) {
            std::swap(a[i], a[rev]);
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

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly_inv(std::vector<mint>& a) {
    static const ntt_info<mint> info;
    int n = int(a.size());
    int bit_size = bsf(n);
    assert(n == 1 << ceil_pow2(n));
    // bit reverse
    for (int i = 0; i < n; i++) {
        int rev = bit_reverse(i, bit_size);
        if (i < rev) std::swap(a[i], a[rev]);
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

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(const std::vector<mint>& f,
                              const std::vector<mint>& g) {
    int n = 1 << ceil_pow2(f.size() + g.size() - 1);
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