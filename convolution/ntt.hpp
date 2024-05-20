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
    static constexpr int rank2 =
        std::countr_zero((unsigned int)(mint::mod() - 1));

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
    assert(n == 1 << bit_size);
    for (int bit = bit_size - 1; bit >= 0; bit--) {
        int m = 1 << bit;
        for (int i = 0; i < n; i += 2 * m) {
            mint w = 1;
            for (int j = 0; j < m; j++) {
                mint p1 = a[i + j];
                mint p2 = a[i + j + m];
                a[i + j] = p1 + p2;
                a[i + j + m] = (p1 - p2) * w;
                w *= info.root[bit + 1];
            }
        }
    }
}

template <Modint mint> void butterfly_inv(std::vector<mint>& a) {
    static const ntt_info<mint> info;
    int n = int(a.size());
    int bit_size = std::countr_zero(a.size());
    assert(n == 1 << bit_size);

    for (int bit = 0; bit < bit_size; bit++) {
        for (int i = 0; i < n / (1 << (bit + 1)); i++) {
            mint w = 1;
            for (int j = 0; j < (1 << bit); j++) {
                int idx = i * (1 << (bit + 1)) + j;
                int jdx = idx + (1 << bit);
                mint p1 = a[idx];
                mint p2 = a[jdx];
                a[idx] = p1 + w * p2;
                a[jdx] = p1 - w * p2;
                w *= info.inv_root[bit + 1];
            }
        }
    }
    mint inv_n = mint(n).inv();
    for (int i = 0; i < n; i++) {
        a[i] *= inv_n;
    }
}

}  // namespace internal

}  // namespace ebi