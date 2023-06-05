#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <vector>

#include "../utility/modint61.hpp"
#include "../utility/random_number_generator_64.hpp"

/*
    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
*/

namespace ebi {

template <int n> struct rolling_hash {
  private:
    using mint = modint61;
    const mint h = 100;

  public:
    rolling_hash(const std::string &s) : sz(s.size()) {
        assert(n >= 0);
        for (int i = 0; i < n; ++i) {
            base_pow[i].reserve(sz + 1);
            base_pow[i].emplace_back(1);
            hash[i].reserve(sz + 1);
            hash[i].emplace_back(0);
            for (const auto &c : s) {
                hash[i].emplace_back(hash[i].back() * base[i] + c + h);
                base_pow[i].emplace_back(base_pow[i].back() * base[i]);
            }
        }
    }

    // [l, r)
    std::array<mint, n> get_hash(int l, int r) const {
        std::array<mint, n> ret;
        for (int i = 0; i < n; ++i) {
            ret[i] = hash[i][r] - hash[i][l] * base_pow[i][r - l];
        }
        return ret;
    }

    std::array<mint, n> get_hash(const std::string &str, int l = 0,
                                 int r = -1) const {
        if (r < 0) r = int(str.size());
        std::array<mint, n> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = l; j < r; ++j) {
                res[i] = res[i] * base[i] + str[i] + h;
            }
        }
        return res;
    }

    std::array<mint, n> concat(const std::array<mint, n> &hash1,
                               const std::array<mint, n> &hash2, int len2) {
        std::array<mint, n> hash;
        for (int i = 0; i < n; i++) {
            hash[i] = hash1[i] * base[i].pow(len2) + hash2[i];
        }
        return hash;
    }

    static void set_base() {
        static random_number_generator_64 rnd;
        for (int i = 0; i < n; ++i) {
            base[i] = (1ull << 31) | rnd.get(1, (1ull << 31));
        }
    }

  private:
    size_t sz;
    std::array<std::vector<mint>, n> base_pow;
    std::array<std::vector<mint>, n> hash;

  public:
    static std::array<mint, n> base;
};

template <int n> std::array<modint61, n> rolling_hash<n>::base = {};

}  // namespace ebi
