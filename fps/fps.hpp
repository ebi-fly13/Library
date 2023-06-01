#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include <optional>

namespace ebi {

template <class mint, std::vector<mint> (*convolution)(
                          const std::vector<mint> &, const std::vector<mint> &)>
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
    FPS operator%(const FPS &rhs) const noexcept {
        return FPS(*this) %= rhs;
    }

    FPS operator+(const mint &rhs) const noexcept {
        return FPS(*this) += rhs;
    }
    FPS operator-(const mint &rhs) const noexcept {
        return FPS(*this) -= rhs;
    }
    FPS operator*(const mint &rhs) const noexcept {
        return FPS(*this) *= rhs;
    }

    FPS &operator+=(const FPS &rhs) noexcept {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int)rhs.size(); ++i) {
            (*this)[i] += rhs[i];
        }
        return *this;
    }

    FPS &operator-=(const FPS &rhs) noexcept {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        for (int i = 0; i < (int)rhs.size(); ++i) {
            (*this)[i] -= rhs[i];
        }
        return *this;
    }

    FPS &operator*=(const FPS &rhs) noexcept {
        *this = convolution(*this, rhs);
        return *this;
    }

    FPS &operator/=(const FPS &rhs) noexcept {
        int n = deg() - 1;
        int m = rhs.deg() - 1;
        if (n < m) {
            *this = {};
            return *this;
        }
        *this = (*this).rev() * rhs.rev().inv(n - m + 1);
        (*this).resize(n - m + 1);
        std::reverse((*this).begin(), (*this).end());
        return *this;
    }

    FPS &operator%=(const FPS &rhs) noexcept {
        *this -= *this / rhs * rhs;
        shrink();
        return *this;
    }

    FPS &operator+=(const mint &rhs) noexcept {
        if (this->empty()) this->resize(1);
        (*this)[0] += rhs;
        return *this;
    }

    FPS &operator-=(const mint &rhs) noexcept {
        if (this->empty()) this->resize(1);
        (*this)[0] -= rhs;
        return *this;
    }

    FPS &operator*=(const mint &rhs) noexcept {
        for (int i = 0; i < deg(); ++i) {
            (*this)[i] *= rhs;
        }
        return *this;
    }

    FPS operator>>(int d) const {
        if (deg() <= d) return {};
        FPS f = *this;
        f.erase(f.begin(), f.begin() + d);
        return f;
    }

    FPS operator<<(int d) const {
        FPS f = *this;
        f.insert(f.begin(), d, 0);
        return f;
    }

    FPS operator-() const {
        FPS g(this->size());
        for (int i = 0; i < (int)this->size(); i++) g[i] = -(*this)[i];
        return g;
    }

    FPS pre(int sz) const {
        return FPS(this->begin(), this->begin() + std::min(deg(), sz));
    }

    FPS rev() const {
        auto f = *this;
        std::reverse(f.begin(), f.end());
        return f;
    }

    FPS differential() const {
        int n = deg();
        FPS g(std::max(0, n - 1));
        for (int i = 0; i < n - 1; i++) {
            g[i] = (*this)[i + 1] * (i + 1);
        }
        return g;
    }

    FPS integral() const {
        int n = deg();
        FPS g(n + 1);
        g[0] = 0;
        if (n > 0) g[1] = 1;
        auto mod = mint::mod();
        for (int i = 2; i <= n; i++) g[i] = (-g[mod % i]) * (mod / i);
        for (int i = 0; i < n; i++) g[i + 1] *= (*this)[i];
        return g;
    }

    FPS inv(int d = -1) const {
        int n = 1;
        if (d < 0) d = deg();
        FPS g(n);
        g[0] = (*this)[0].inv();
        while (n < d) {
            n <<= 1;
            g = (g * 2 - g * g * this->pre(n)).pre(n);
        }
        g.resize(d);
        return g;
    }

    FPS log(int d = -1) const {
        assert((*this)[0].val() == 1);
        if (d < 0) d = deg();
        return ((*this).differential() * (*this).inv(d)).pre(d - 1).integral();
    }

    FPS exp(int d = -1) const {
        assert((*this)[0].val() == 0);
        int n = 1;
        if (d < 0) d = deg();
        FPS g(n);
        g[0] = 1;
        while (n < d) {
            n <<= 1;
            g = (g * (this->pre(n) - g.log(n) + 1)).pre(n);
        }
        g.resize(d);
        return g;
    }

    FPS pow(int64_t k, int d = -1) const {
        const int n = deg();
        if (d < 0) d = n;
        if (k == 0) {
            FPS f(d);
            if (d > 0) f[0] = 1;
            return f;
        }
        for (int i = 0; i < n; i++) {
            if ((*this)[i] != 0) {
                mint rev = (*this)[i].inv();
                FPS f = (((*this * rev) >> i).log(d) * k).exp(d);
                f *= (*this)[i].pow(k);
                f = (f << (i * k)).pre(d);
                if (f.deg() < d) f.resize(d);
                return f;
            }
            if (i + 1 >= (d + k - 1) / k) break;
        }
        return FPS(d);
    }

    int deg() const {
        return (*this).size();
    }

    void shrink() {
        while ((!this->empty()) && this->back() == 0) this->pop_back();
    }

    std::optional<FPS> sqrt(int d = -1) const;
};

}  // namespace ebi