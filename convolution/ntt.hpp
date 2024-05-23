#pragma once

#include <algorithm>
#include <array>
#include <bit>
#include <cassert>
#include <vector>

#include "../math/internal_math.hpp"
#include "../modint/base.hpp"
#include "../template/int_alias.hpp"

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

template <Modint mint> void fft2(std::vector<mint>& a) {
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

template <Modint mint> void ifft2(std::vector<mint>& a) {
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
                mint p2 = w * a[jdx];
                a[idx] = p1 + p2;
                a[jdx] = p1 - p2;
                w *= info.inv_root[bit + 1];
            }
        }
    }
}

template <Modint mint> void fft4(std::vector<mint>& a) {
    static const ntt_info<mint> info;
    const u32 mod = mint::mod();
    const u64 iw = info.root[2].val();
    int n = int(a.size());
    int bit_size = std::countr_zero(a.size());
    assert(n == 1 << bit_size);
    int len = bit_size;
    while (len > 0) {
        if (len == 1) {
            for (int i = 0; i < n; i += 2) {
                mint p0 = a[i];
                mint p1 = a[i + 1];
                a[i] = p0 + p1;
                a[i + 1] = p0 - p1;
            }
            len--;
        } else {
            int m = 1 << (len - 2);
            u64 w1 = 1, w2 = 1, w3 = 1, iw1 = iw, iw3 = iw;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j += 4 * m) {
                    int i0 = i + j, i1 = i0 + m, i2 = i1 + m, i3 = i2 + m;
                    u32 a0 = a[i0].val();
                    u32 a1 = a[i1].val();
                    u32 a2 = a[i2].val();
                    u32 a3 = a[i3].val();
                    u32 a0_plus_a2 = a0 + a2;
                    u32 a1_plus_a3 = a1 + a3;
                    u32 a0_minus_a2 = a0 + mod - a2;
                    u32 a1_minus_a3 = a1 + mod - a3;
                    a[i0] = a0_plus_a2 + a1_plus_a3;
                    a[i1] = a0_minus_a2 * w1 + a1_minus_a3 * iw1;
                    a[i2] = (a0_plus_a2 + 2 * mod - a1_plus_a3) * w2;
                    a[i3] = a0_minus_a2 * w3 + (2 * mod - a1_minus_a3) * iw3;
                }
                w1 = w1 * info.root[len].val() % mod;
                w2 = w1 * w1 % mod;
                w3 = w2 * w1 % mod;
                iw1 = iw * w1 % mod;
                iw3 = iw * w3 % mod;
            }
            len -= 2;
        }
    }
}

template <Modint mint> void ifft4(std::vector<mint>& a) {
    static const ntt_info<mint> info;
    const u32 mod = mint::mod();
    const u64 mod2 = u64(mod) * mod;
    const u64 iw = info.inv_root[2].val();
    int n = int(a.size());
    int bit_size = std::countr_zero(a.size());
    assert(n == 1 << bit_size);
    int len = (bit_size & 1 ? 1 : 2);
    while (len <= bit_size) {
        if (len == 1) {
            for (int i = 0; i < n; i += 2) {
                mint a0 = a[i];
                mint a1 = a[i + 1];
                a[i] = a0 + a1;
                a[i + 1] = a0 - a1;
            }
        } else {
            int m = 1 << (len - 2);
            u64 w1 = 1, w2 = 1, w3 = 1, iw1 = iw, iw3 = iw;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j += 4 * m) {
                    int i0 = i + j, i1 = i0 + m, i2 = i1 + m, i3 = i2 + m;
                    u64 a0 = a[i0].val();
                    u64 a1 = w1 * a[i1].val();
                    u64 a2 = w2 * a[i2].val();
                    u64 a3 = w3 * a[i3].val();
                    u64 b1 = iw1 * a[i1].val();
                    u64 b3 = iw3 * a[i3].val();
                    u64 a0_plus_a2 = a0 + a2;
                    u64 a1_plus_a3 = a1 + a3;
                    u64 a0_minus_a2 = a0 + mod2 - a2;
                    u64 b1_minus_b3 = b1 + mod2 - b3;
                    a[i0] = a0_plus_a2 + a1_plus_a3;
                    a[i1] = a0_minus_a2 + b1_minus_b3;
                    a[i2] = a0_plus_a2 + mod2 * 2 - a1_plus_a3;
                    a[i3] = a0_minus_a2 + mod2 * 2 - b1_minus_b3;
                }
                w1 = w1 * info.inv_root[len].val() % mod;
                w2 = w1 * w1 % mod;
                w3 = w2 * w1 % mod;
                iw1 = iw * w1 % mod;
                iw3 = iw * w3 % mod;
            }
        }
        len += 2;
    }
}

}  // namespace internal

}  // namespace ebi