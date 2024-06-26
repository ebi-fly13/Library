#pragma once

#include <cassert>
#include <vector>

#include "../fps/berlekamp_massey.hpp"
#include "../fps/poly_mod_pow.hpp"
#include "../modint/base.hpp"
#include "../utility/random_number_generator.hpp"

namespace ebi {

template <Modint mint, class F>
std::vector<mint> matrix_minimum_poly(int n, F Ax) {
    static random_number_generator rng;
    std::vector<mint> s(2 * n + 10, 0), u(n), b(n);
    for (int i = 0; i < n; i++) {
        u[i] = rng.get(0, mint::mod());
        b[i] = rng.get(0, mint::mod());
    }
    for (int i = 0; i < 2 * n + 10; i++) {
        for (int j = 0; j < n; j++) {
            s[i] += u[j] * b[j];
        }
        b = Ax(b);
    }
    auto c = berlekamp_massey(s);
    std::reverse(c.begin(), c.end());
    return c;
}

template <Modint mint, class F>
std::vector<mint> pow(int n, F Ax, const std::vector<mint> &b, long long k) {
    assert(n == (int)b.size());
    using FPS = FormalPowerSeries<mint>;
    auto g = matrix_minimum_poly<mint>(n, Ax);
    auto c = poly_mod_pow<mint>({0, 1}, k, g);
    FPS res(n, 0), Ab = b;
    for (int i = 0; i < (int)c.size(); i++) {
        res += Ab * c[i];
        Ab = FPS(Ax(Ab));
    }
    return res;
}

template <Modint mint, class F> mint det(int n, F Ax) {
    static random_number_generator rng;
    std::vector<mint> d(n);
    mint r = 1;
    for (int i = 0; i < n; i++) {
        d[i] = rng.get(1, mint::mod());
        r *= d[i];
    }
    auto ADx = [&](std::vector<mint> v) -> std::vector<mint> {
        assert(n == (int)v.size());
        for (int i = 0; i < n; i++) {
            v[i] *= d[i];
        }
        return Ax(v);
    };
    auto f = matrix_minimum_poly<mint>(n, ADx);
    mint res = ((int)f.size() == n + 1 ? f[0] : 0);
    if (n % 2 == 1) res = -res;
    return res / r;
}

}  // namespace ebi