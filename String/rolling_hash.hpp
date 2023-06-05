#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <vector>

#include "../utility/hash.hpp"
#include "../utility/modint61.hpp"

/*
    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
*/

namespace ebi {

template <int n> struct rolling_hash {
  private:
    using mint = modint61;
    static constexpr mint h = 100;

  public:
    rolling_hash(const std::string &s) : sz(s.size()) {
        assert(n >= 0);
        base_pow.reserve(sz + 1);
        base_pow.emplace_back(Hash<n>::set(1));
        hash.reserve(sz + 1);
        hash.emplace_back(Hash<n>::set(0));
        for (const auto &c : s) {
            hash.emplace_back(hash.back() * base + c + h);
            base_pow.emplace_back(base_pow.back() * base);
        }
    }

    // [l, r)
    Hash<n> get_hash(int l, int r) const {
        assert(0 <= l && l <= r && r <= sz);
        return hash[r] - hash[l] * base_pow[r - l];
    }

    static Hash<n> get_hash(const std::string &str, int l = 0, int r = -1) {
        if (r < 0) r = int(str.size());
        Hash<n> res = Hash<n>::set(0);
        for (int i = l; i < r; i++) {
            res = res * base + str[i] + h;
        }
        return res;
    }

    Hash<n> concat(const Hash<n> &hash1, const Hash<n> &hash2, int len2) {
        return hash1 * base.pow(len2) + hash2;
    }

    static void set_base() {
        base = Hash<n>::get_basis();
    }

  private:
    int sz;
    std::vector<Hash<n>> base_pow;
    std::vector<Hash<n>> hash;

  public:
    static Hash<n> base;
};

template <int n> Hash<n> rolling_hash<n>::base = {};

}  // namespace ebi
