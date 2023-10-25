#pragma once

#include <cassert>
#include <cstdint>
#include <iostream>

#include "base.hpp"

namespace ebi {

struct modint61 {
  private:
    using mint = modint61;
    using u64 = std::uint64_t;
    constexpr static u64 m = (1ull << 61) - 1;
    constexpr static u64 MASK31 = (1ull << 31) - 1;
    constexpr static u64 MASK30 = (1ull << 30) - 1;

  public:
    constexpr static u64 mod() {
        return m;
    }

    constexpr modint61() : _v(0) {}

    constexpr modint61(long long v) {
        v %= (long long)umod();
        if (v < 0) v += (long long)umod();
        _v = u64(v);
    }

    constexpr u64 val() const {
        return _v;
    }

    constexpr u64 value() const {
        return val();
    }

    constexpr mint &operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }

    constexpr mint &operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }

    constexpr mint &operator+=(const mint &rhs) {
        _v += rhs._v;
        _v = safe_mod(_v);
        return *this;
    }

    constexpr mint &operator-=(const mint &rhs) {
        if (_v < rhs._v) _v += umod();
        assert(_v >= rhs._v);
        _v -= rhs._v;
        return *this;
    }

    constexpr mint &operator*=(const mint &rhs) {
        u64 au = _v >> 31, ad = _v & MASK31;
        u64 bu = rhs._v >> 31, bd = rhs._v & MASK31;
        u64 mid = ad * bu + au * bd;
        u64 midu = mid >> 30;
        u64 midd = mid & MASK30;
        _v = (au * bu * 2 + midu + (midd << 31) + ad * bd);
        _v = safe_mod(_v);
        return *this;
    }

    constexpr mint &operator/=(const mint &rhs) {
        return *this *= rhs.inv();
    }

    constexpr mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    constexpr mint inv() const {
        assert(_v);
        return pow(umod() - 2);
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint &lhs, const mint &rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint &lhs, const mint &rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint &lhs, const mint &rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint &lhs, const mint &rhs) {
        return lhs.val() == rhs.val();
    }
    friend bool operator!=(const mint &lhs, const mint &rhs) {
        return !(lhs == rhs);
    }
    friend bool operator<(const mint &lhs, const mint &rhs) {
        return lhs._v < rhs._v;
    }
    friend bool operator>(const mint &lhs, const mint &rhs) {
        return rhs < lhs;
    }

  private:
    u64 _v = 0;

    constexpr static u64 umod() {
        return m;
    }

    constexpr u64 safe_mod(const u64 &a) {
        u64 au = a >> 61;
        u64 ad = a & umod();
        u64 res = au + ad;
        if (res >= umod()) res -= umod();
        return res;
    }
};

}  // namespace ebi