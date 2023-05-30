#pragma once

#include <cassert>

#include "../utility/modint_base.hpp"

namespace ebi {

template <int id> struct dynamic_modint : internal::modint_base {
  private:
    using modint = dynamic_modint;

  public:
    static void set_mod(int p) {
        assert(1 <= p);
        m = p;
    }

    static int mod() {
        return m;
    }

    modint raw(int v) {
        modint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}

    dynamic_modint(long long v) {
        v %= (long long)umod();
        if (v < 0) v += (long long)umod();
        _v = (unsigned int)v;
    }

    unsigned int val() const {
        return _v;
    }

    unsigned int value() const {
        return val();
    }

    modint &operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    modint &operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    modint &operator+=(const modint &rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    modint &operator-=(const modint &rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    modint &operator*=(const modint &rhs) {
        unsigned long long x = _v;
        x *= rhs._v;
        _v = (unsigned int)(x % (unsigned long long)umod());
        return *this;
    }
    modint &operator/=(const modint &rhs) {
        return *this = *this * rhs.inv();
    }

    modint operator+() const {
        return *this;
    }
    modint operator-() const {
        return modint() - *this;
    }

    modint pow(long long n) const {
        assert(0 <= n);
        modint x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    modint inv() const {
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
    static int m;

    static unsigned int umod() {
        return m;
    }
};

template <int id> int dynamic_modint<id>::m = 998244353;

}  // namespace ebi