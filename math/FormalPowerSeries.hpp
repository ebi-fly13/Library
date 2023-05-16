#pragma once

#include "../convolution/convolution.hpp"
#include "../utility/modint.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

/*
    reference: https://opt-cp.com/fps-fast-algorithms/
*/

namespace ebi {

using mint = modint998244353;

struct FormalPowerSeries : std::vector<mint> {
  private:
    using std::vector<mint>::vector;
    using std::vector<mint>::vector::operator=;
    using FPS = FormalPowerSeries;

  public:
    FPS operator+(const FPS &rhs) const noexcept {
        return FPS(*this) += rhs;
    }
    FPS operator-(const FPS &rhs) const noexcept {
        return FPS(*this) -= rhs;
    }
    FPS operator*(const FPS &rhs) const noexcept {
        return FPS(*this) *= rhs;
    }
    FPS operator/(const FPS &rhs) const noexcept {
        return FPS(*this) /= rhs;
    }

    FPS &operator+=(const FPS &rhs) noexcept {
        int sz = std::min(deg(), rhs.deg());
        for (int i = 0; i < sz; ++i) {
            (*this)[i] += rhs[i];
        }
        return *this;
    }

    FPS &operator-=(const FPS &rhs) noexcept {
        int sz = std::min(deg(), rhs.deg());
        for (int i = 0; i < sz; ++i) {
            (*this)[i] -= rhs[i];
        }
        return *this;
    }

    FPS &operator*=(const FPS &rhs) noexcept {
        int n = deg();
        *this = convolution(*this, rhs);
        (*this).resize(n);
        return *this;
    }

    FPS &operator/=(const FPS &rhs) noexcept {
        *this *= rhs.inv();
        return *this;
    }

    FPS &operator*=(const mint rhs) noexcept {
        for (int i = 0; i < deg(); ++i) {
            (*this)[i] *= rhs;
        }
        return *this;
    }

    FPS inv() const {
        int n = 1, sz = deg();
        FPS g(n);
        g[0] = (*this)[0].inv();
        while (n < sz) {
            n <<= 1;
            FPS f((*this).begin(), (*this).begin() + std::min(sz, n));
            f.resize(n);
            g.resize(n);
            FPS h = f * g;
            h.erase(h.begin(), h.begin() + n / 2);
            h.resize(n);
            h = h * g;
            for (int i = 0; i < n / 2; i++) {
                g[i + n / 2] -= h[i];
            }
        }
        g.resize(sz);
        return g;
    }

    FPS exp() {
        assert((*this)[0].val() == 0);
        int n = 1, sz = deg();
        FPS g(n);
        g[0] = 1;
        while (n < sz) {
            n <<= 1;
            FPS f((*this).begin(), (*this).begin() + std::min(sz, n));
            f.resize(n);
            g.resize(n);
            g = g * (f - g.log()) + g;
        }
        return g;
    }

    FPS differential() {
        int n = deg();
        FPS g(n);
        for (int i = 0; i < n - 1; i++) {
            g[i] = (*this)[i + 1] * (i + 1);
        }
        g[n - 1] = 0;
        return g;
    }

    FPS integral() {
        int n = deg();
        FPS g(n + 1);
        g[0] = 0;
        for (int i = 0; i < n; i++) {
            g[i + 1] = (*this)[i] / (mint(i + 1));
        }
        return g;
    }

    FPS log() {
        assert((*this)[0].val() == 1);
        FPS g = (*this).differential() / (*this);
        return g.integral();
    }

    int deg() const {
        return (*this).size();
    }
};

}  // namespace ebi