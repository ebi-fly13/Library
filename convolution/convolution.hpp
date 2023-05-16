#pragma once

/*
    reference: https://hcpc-hokudai.github.io/archive/math_fft_002.pdf
    mod 998244353 上での畳み込みを O(N log N) で求める.
*/

#include "../utility/modint.hpp"

#include <vector>

namespace ebi {

using mint = ebi::modint998244353;

namespace internal {

const mint primitive_root = 3;

void dft(std::vector<mint> &f) {
    int n = f.size();
    if (n == 1) return;
    std::vector<mint> a(n / 2), b(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        a[i] = f[2 * i];
        b[i] = f[2 * i + 1];
    }
    dft(a);
    dft(b);
    const mint zeta = primitive_root.pow((mint::mod() - 1) / n);
    mint x = 1;
    for (int i = 0; i < n; ++i) {
        f[i] = a[i % (n / 2)] + x * b[i % (n / 2)];
        x *= zeta;
    }
}

void inv_dft(std::vector<mint> &f) {
    int n = f.size();
    if (n == 1) return;
    std::vector<mint> a(n / 2), b(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        a[i] = f[2 * i];
        b[i] = f[2 * i + 1];
    }
    inv_dft(a);
    inv_dft(b);
    const mint inv_zeta = primitive_root.pow((mint::mod() - 1) / n).inv();
    mint x = 1;
    for (int i = 0; i < n; ++i) {
        f[i] = a[i % (n / 2)] + x * b[i % (n / 2)];
        x *= inv_zeta;
    }
}

}  // namespace internal

std::vector<mint> convolution(const std::vector<mint> &f,
                              const std::vector<mint> &g) {
    int n = 1;
    while (n < (int)f.size() + (int)g.size() - 1) n <<= 1;
    std::vector<mint> a(n, 0), b(n, 0), fg(n, 0);
    std::copy(f.begin(), f.end(), a.begin());
    std::copy(g.begin(), g.end(), b.begin());
    internal::dft(a);
    internal::dft(b);
    for (int i = 0; i < n; ++i) {
        fg[i] = a[i] * b[i];
    }
    internal::inv_dft(fg);
    mint in = mint(n).inv();
    for (int i = 0; i < n; ++i) {
        fg[i] *= in;
    }
    return fg;
}

}  // namespace ebi