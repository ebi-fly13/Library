#pragma once

#include <cassert>
#include <iostream>
#include <type_traits>

#include "../utility/modint_base.hpp"

namespace ebi {

template <int m> struct static_modint : internal::static_modint_base {
  private:
    using modint = static_modint;

  public:
    static constexpr int mod() {
        return m;
    }

    static constexpr modint raw(int v) {
        modint x;
        x._v = v;
        return x;
    }

    constexpr static_modint() : _v(0) {}

    constexpr static_modint(long long v) {
        v %= (long long)umod();
        if (v < 0) v += (long long)umod();
        _v = (unsigned int)v;
    }

    constexpr unsigned int val() const {
        return _v;
    }

    constexpr unsigned int value() const {
        return val();
    }

    constexpr modint &operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    constexpr modint &operator--() {
        if (_v == 0) _v = umod();
        _v--;
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

    constexpr modint &operator+=(const modint &rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    constexpr modint &operator-=(const modint &rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    constexpr modint &operator*=(const modint &rhs) {
        unsigned long long x = _v;
        x *= rhs._v;
        _v = (unsigned int)(x % (unsigned long long)umod());
        return *this;
    }
    constexpr modint &operator/=(const modint &rhs) {
        return *this = *this * rhs.inv();
    }

    constexpr modint operator+() const {
        return *this;
    }
    constexpr modint operator-() const {
        return modint() - *this;
    }

    constexpr modint pow(long long n) const {
        assert(0 <= n);
        modint x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    constexpr modint inv() const {
        assert(_v);
        return pow(umod() - 2);
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
        return lhs.val() == rhs.val();
    }
    friend bool operator!=(const modint &lhs, const modint &rhs) {
        return !(lhs == rhs);
    }

  private:
    unsigned int _v = 0;

    static constexpr unsigned int umod() {
        return m;
    }
};

template <int m>
std::istream &operator>>(std::istream &os, static_modint<m> &a) {
    long long x;
    os >> x;
    a = x;
    return os;
}
template <int m>
std::ostream &operator<<(std::ostream &os, const static_modint<m> &a) {
    return os << a.val();
}

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;

}  // namespace ebi