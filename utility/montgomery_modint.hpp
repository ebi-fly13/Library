#pragma once

#include <cstdint>
#include <iostream>

#include "../utility/modint_base.hpp"

namespace ebi {

template <int m> struct montgomery_modint : internal::static_modint_base {
  private:
    using modint = montgomery_modint;
    using i32 = std::int32_t;
    using u32 = std::uint32_t;
    using i64 = std::int64_t;
    using u64 = std::uint64_t;

    static constexpr u32 umod() {
        return m;
    }

    static constexpr u32 get_r() {
        u32 ret = umod();
        for (i32 i = 0; i < 4; i++) ret *= 2 - umod() * ret;
        return ret;
    }

    static constexpr u32 r = get_r();
    static constexpr u32 n2 = -u64(umod()) % umod();

    static constexpr u32 reduce(const u64 &b) {
        return u32(b >> 32) + umod() - u32((u64(u32(b) * r) * umod()) >> 32);
    }

    static constexpr u32 one = reduce(i64(1 + umod()) * n2);

    static_assert(r * umod() == 1, "invalid, r * mod != 1");
    static_assert(umod() < (1 << 30), "invalid, mod >= 2 ^ 30");
    static_assert((umod() & 1) == 1, "invalid, mod % 2 == 0");

  public:
    static constexpr int mod() {
        return m;
    }

    constexpr montgomery_modint() : _v(0) {}

    constexpr montgomery_modint(i64 v)
        : _v(reduce((v % i64(umod()) + i64(umod())) * n2)) {}

    constexpr modint &operator+=(const modint &rhs) {
        if (i32(_v += rhs._v - 2 * umod()) < 0) _v += 2 * umod();
        return *this;
    }

    constexpr modint &operator-=(const modint &rhs) {
        if (i32(_v -= rhs._v) < 0) _v += 2 * umod();
        return *this;
    }

    constexpr modint &operator*=(const modint &rhs) {
        _v = reduce(u64(_v) * rhs._v);
        return *this;
    }

    constexpr modint &operator/=(const modint &rhs) {
        *this *= rhs.inv();
        return *this;
    }

    constexpr modint &operator++() {
        if (i32(_v += one - 2 * umod()) < 0) _v += 2 * umod();
        return *this;
    }

    constexpr modint &operator--() {
        if (i32(_v -= one) < 0) _v += 2 * umod();
        return *this;
    }

    constexpr modint operator++(int) {
        modint res = *this;
        ++*this;
        return res;
    }

    constexpr modint operator--(int) {
        modint res = *this;
        --*this;
        return res;
    }

    constexpr modint operator+() const {
        return *this;
    }

    constexpr modint operator-() const {
        return modint() - *this;
    }

    friend modint operator+(const modint &lhs, const modint &rhs) {
        return modint(lhs) += rhs;
    }
    friend modint operator-(const modint &lhs, const modint &rhs) {
        return modint(lhs) -= rhs;
    }
    friend modint operator*(const modint &lhs, const modint &rhs) {
        return modint(lhs) *= rhs;
    }
    friend modint operator/(const modint &lhs, const modint &rhs) {
        return modint(lhs) /= rhs;
    }
    friend bool operator==(const modint &lhs, const modint &rhs) {
        return (lhs._v >= umod() ? lhs._v - umod() : lhs._v) ==
               (rhs._v >= umod() ? rhs._v - umod() : rhs._v);
    }
    friend bool operator!=(const modint &lhs, const modint &rhs) {
        return !(lhs == rhs);
    }

    constexpr modint pow(u64 n) const {
        modint x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    constexpr modint inv() const {
        return pow(umod() - 2);
    }

    constexpr u32 val() const {
        u32 ret = reduce(i64(_v));
        return ret >= umod() ? ret - umod() : ret;
    }

  private:
    u32 _v = 0;
};

template <int m>
std::istream &operator>>(std::istream &os, montgomery_modint<m> &a) {
    long long x;
    os >> x;
    a = x;
    return os;
}
template <int m>
std::ostream &operator<<(std::ostream &os, const montgomery_modint<m> &a) {
    return os << a.val();
}

using montgomery_modint998244353 = montgomery_modint<998244353>;
using montgomery_modint1000000007 = montgomery_modint<1'000'000'007>;

}  // namespace ebi