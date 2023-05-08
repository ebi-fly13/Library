#pragma once

#include <cassert>
#include <cstdint>
#include <vector>

#include "../utility/random_number_generator_64.hpp"
#include "../utility/safe_mod.hpp"

/*
    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
*/

namespace ebi {

template <int n> struct rolling_hash {
  private:
    using u64 = std::uint64_t;
    const u64 h = 100;
    const u64 buffer = mod * 4;

  public:
    rolling_hash(const std::string &s) : sz(s.size()) {
        assert(int(base.size()) == n && n > 0);
        base_pow.resize(n);
        hash.resize(n);
        for (int i = 0; i < n; ++i) {
            base_pow[i].reserve(sz + 1);
            base_pow[i].emplace_back(1);
            hash[i].reserve(sz + 1);
            hash[i].emplace_back(0);
            for (const auto &c : s) {
                hash[i].emplace_back(
                    safe_mod(safe_mul(hash[i].back(), base[i]) + c + h));
                base_pow[i].emplace_back(
                    safe_mod(safe_mul(base_pow[i].back(), base[i])));
            }
        }
    }

    // [l, r)
    std::vector<u64> get_hash(int l, int r) const {
        std::vector<u64> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = safe_mod(hash[i][r] + buffer -
                              safe_mul(hash[i][l], base_pow[i][r - l]));
        }
        return ret;
    }

    std::vector<u64> get_hash(const std::string &str, int l = 0,
                              int r = -1) const {
        if (r < 0) r = int(str.size());
        std::vector<u64> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = l; j < r; ++j) {
                res[i] = safe_mod(safe_mul(res[i], base[i]) + str[i] + h);
            }
        }
        return res;
    }

    static void set_base() {
        random_number_generator_64 rnd;
        base.resize(n);
        for (int i = 0; i < n; ++i) {
            base[i] = rnd.get(0, (1UL << 61) - 1);
        }
    }

  private:
    size_t sz;
    std::vector<std::vector<u64>> base_pow;
    std::vector<std::vector<u64>> hash;

  public:
    static std::vector<u64> base;
};

template <int n>
std::vector<std::uint64_t> rolling_hash<n>::base{12345, 10000000};

}  // namespace ebi
