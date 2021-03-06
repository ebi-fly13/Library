#pragma once

/*
    author: noshi91
    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006
    noshi91のブログで公開されているmodintを元にinv(), pow()を追加したものです
*/

#include <cstdint>
#include <iostream>

namespace ebi {

template<std::uint_fast64_t Modulus>
class modint {
  using u64 = std::uint_fast64_t;

public:
    u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr u64 &val() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
        a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
        if (exp % 2) {
            *this *= rhs;
        }
        rhs *= rhs;
        exp /= 2;
        }
        return *this;
    }
    constexpr modint operator-() const { return modint() - *this; }
    bool operator==(const u64 rhs) {
        return a == rhs;
    }
    bool operator!=(const u64 rhs) {
        return a != rhs;
    }
    constexpr modint& operator++() {
        a++;
        if( a == mod() ) a = 0;
        return *this;
    }
    constexpr modint& operator--() {
        if( a == 0 ) a = mod();
        a--;
        return *this;
    }

    modint pow(u64 n) const noexcept {
        modint res = 1;
        modint x = a;
        while(n>0){
            if(n&1) res *= x;
            x *= x;
            n >>=1;
        }
        return res;
    }
    modint inv() const {
        return pow(Modulus-2);
    }

    static u64 mod() {
        return Modulus;
    }
};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1000000007>;

template<std::uint_fast64_t Modulus>
std::ostream& operator<<(std::ostream& os, modint<Modulus> a){
    return os << a.val();
}

} // namespace ebi