#pragma once

#include "../algorithm/convolution.hpp"
#include "../utility/modint.hpp"

#include <vector>
#include <algorithm>

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

    FPS &operator+=(const FPS &rhs) noexcept {
        int sz = std::min(deg(), rhs.deg());
        for(int i = 0; i< sz; ++i) {
            (*this)[i] += rhs[i];
        }
        return *this;
    }

    FPS &operator-=(const FPS &rhs) noexcept {
        int sz = std::min(deg(), rhs.deg());
        for(int i = 0; i< sz; ++i) {
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

    FPS &operator*=(const mint rhs) noexcept {
        for(int i = 0; i<deg(); ++i) {
            (*this)[i] *= rhs;
        }
        return *this;
    }

    FPS inv() const {
        int n = 1, sz = deg();
        FPS g(n);
        g[0] = (*this)[0].inv();
        while(n < sz) {
            n <<= 1;
            FPS f((*this).begin(), (*this).begin()+std::min(sz, n));
            f.resize(n);
            g.resize(n);
            FPS h = f*g;
            h.erase(h.begin(), h.begin()+n/2);
            h.resize(n);
            h = h*g;
            for(int i = 0; i<n/2; i++) {
                g[i+n/2] -= h[i];
            }
        }
        g.resize(sz);
        return g;
    }

    int deg() const {
        return (*this).size();
    }
};

} // namespace ebi