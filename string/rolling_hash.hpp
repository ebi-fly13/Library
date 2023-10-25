#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <vector>

#include "../modint/modint61.hpp"
#include "../utility/hash.hpp"

/*
    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
*/

namespace ebi {

template <int n> struct rolling_hash {
  private:
    static constexpr int h = 100;

    using Self = rolling_hash<n>;

    static void expand(int m) {
        int now = base_pow.size();
        while (now <= m) {
            now <<= 1;
        }
        if (int(base_pow.size()) == now) return;
        base_pow.reserve(now);
        while (int(base_pow.size()) < now) {
            base_pow.emplace_back(base_pow.back() * base);
        }
    }

  public:
    rolling_hash(const std::string &s) : sz(s.size()) {
        assert(n >= 0);
        hash.reserve(sz + 1);
        hash.emplace_back(Hash<n>::set(0));
        expand(sz);
        for (const auto &c : s) {
            hash.emplace_back(hash.back() * base + c + h);
        }
    }

    template <class T> rolling_hash(const std::vector<T> &a) : sz(a.size()) {
        assert(n >= 0);
        hash.reserve(sz + 1);
        hash.emplace_back(Hash<n>::set(0));
        expand(sz);
        for (const auto &c : a) {
            hash.emplace_back(hash.back() * base + c + h);
        }
    }

    inline Hash<n> prefix_hash(int r) const {
        return hash[r];
    }

    // [l, r)
    Hash<n> get_hash(int l, int r) const {
        assert(0 <= l && l <= r && r <= sz);
        return prefix_hash(r) - prefix_hash(l) * base_pow[r - l];
    }

    static Hash<n> get_hash(const std::string &str, int l = 0, int r = -1) {
        if (r < 0) r = int(str.size());
        Hash<n> res = Hash<n>::set(0);
        for (int i = l; i < r; i++) {
            res = res * base + str[i] + h;
        }
        return res;
    }

    template <class T>
    static Hash<n> get_hash(const std::vector<T> &a, int l = 0, int r = -1) {
        if (r < 0) r = int(a.size());
        Hash<n> res = Hash<n>::set(0);
        for (int i = l; i < r; i++) {
            res = res * base + a[i] + h;
        }
        return res;
    }

    static Hash<n> concat(Self lhs, Self rhs) {
        return lhs.hash.back() * base_pow[rhs.size()] + rhs.hash.back();
    }

    static Hash<n> concat(Hash<n> lhs, Hash<n> rhs, int len) {
        return lhs * base_pow[len] + rhs;
    }

    int size() const {
        return sz;
    }

    Self operator+(const Self &rhs) noexcept {
        return Self(*this) += rhs;
    }

    Self &operator+=(const Self &rhs) noexcept {
        Hash<n> a = hash.back();
        for (int i = 1; i <= rhs.size(); i++) {
            a *= base;
            hash.emplace_back(a + rhs.hash[i]);
        }
        sz += rhs.size();
        expand(sz);
        return *this;
    }

    static void set_base() {
        base = Hash<n>::get_basis_primitive();
        base_pow = std::vector<Hash<n>>(1, Hash<n>::set(1));
    }

    static Hash<n> get_base() {
        return base;
    }

  private:
    int sz;
    std::vector<Hash<n>> hash;
    static Hash<n> base;
    static std::vector<Hash<n>> base_pow;
};

template <int n> Hash<n> rolling_hash<n>::base = {};
template <int n> std::vector<Hash<n>> rolling_hash<n>::base_pow = {};

}  // namespace ebi
