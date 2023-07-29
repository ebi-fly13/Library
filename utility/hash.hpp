#pragma once

#include <array>

#include "../utility/modint61.hpp"
#include "../utility/random_number_generator_64.hpp"

namespace ebi {

template <int BASE_NUM> struct Hash : std::array<modint61, BASE_NUM> {
  private:
    using std::array<modint61, BASE_NUM>::array;
    using std::array<modint61, BASE_NUM>::operator=;

  public:
    Hash() : std::array<modint61, BASE_NUM>() {}

    constexpr static Hash set(const modint61 &a) {
        Hash res;
        std::fill(res.begin(), res.end(), a);
        return res;
    }

    constexpr Hash &operator+=(const Hash &rhs) {
        for (int i = 0; i < BASE_NUM; i++) {
            (*this)[i] += rhs[i];
        }
        return *this;
    }
    constexpr Hash &operator-=(const Hash &rhs) {
        for (int i = 0; i < BASE_NUM; i++) {
            (*this)[i] -= rhs[i];
        }
        return *this;
    }
    constexpr Hash &operator*=(const Hash &rhs) {
        for (int i = 0; i < BASE_NUM; i++) {
            (*this)[i] *= rhs[i];
        }
        return *this;
    }

    constexpr Hash &operator+=(const modint61 &rhs) {
        for (int i = 0; i < BASE_NUM; i++) {
            (*this)[i] += rhs;
        }
        return *this;
    }
    constexpr Hash &operator-=(const modint61 &rhs) {
        for (int i = 0; i < BASE_NUM; i++) {
            (*this)[i] -= rhs;
        }
        return *this;
    }
    constexpr Hash &operator*=(const modint61 &rhs) {
        for (int i = 0; i < BASE_NUM; i++) {
            (*this)[i] *= rhs;
        }
        return *this;
    }

    Hash operator+(const Hash &rhs) const {
        return Hash(*this) += rhs;
    }
    Hash operator-(const Hash &rhs) const {
        return Hash(*this) -= rhs;
    }
    Hash operator*(const Hash &rhs) const {
        return Hash(*this) *= rhs;
    }

    Hash operator+(const modint61 &rhs) const {
        return Hash(*this) += rhs;
    }
    Hash operator-(const modint61 &rhs) const {
        return Hash(*this) -= rhs;
    }
    Hash operator*(const modint61 &rhs) const {
        return Hash(*this) *= rhs;
    }

    Hash pow(long long n) const {
        Hash a = *this, res = set(1);
        while (n) {
            if (n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }

    static Hash get_basis() {
        static random_number_generator_64 rng;
        Hash h;
        for (int i = 0; i < BASE_NUM; i++) {
            h[i] = rng.get(0, modint61::mod() - 1) + 1;
        }
        return h;
    }

    Hash inv() const {
        Hash h;
        for(int i = 0; i < BASE_NUM; i++) {
            h[i] = (*this)[i].inv();
        }
        return h;
    }

    static Hash get_basis_primitive() {
        static random_number_generator_64 rng;
        Hash h;
        for (int i = 0; i < BASE_NUM; i++) {
            while (!is_primitive(
                (h[i] = rng.get(0, modint61::mod() - 1) + 1).val()))
                ;
        }
        return h;
    }

  private:
    static bool is_primitive(long long x) {
        for (long long d : {2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321}) {
            if (modint61(x).pow((modint61::mod() - 1) / d).val() <= 1)
                return false;
        }
        return true;
    }
};

}  // namespace ebi