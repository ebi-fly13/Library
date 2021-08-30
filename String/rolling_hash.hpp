#pragma once

#include <vector>
#include <cstdint>

#include "utility/random_number_generator_64.hpp"

/*
    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
*/

namespace ebi {

template<int n>
struct rolling_hash {
private:
    using u64 = std::uint64_t;
    const u64 mod = (1UL<<61) - 1;
    const u64 MASK31 = (1UL<<31) - 1;
    const u64 MASK30 = (1UL<<30) - 1;
    const u64 h = 100;
    const u64 buffer = mod * 4;
    random_number_generator_64 rnd;

    u64 mul(const u64 &a, const u64 &b) const {
        u64 au = a>>31, ad = a&MASK31;
        u64 bu = b>>31, bd = b&MASK31;
        u64 mid = ad*bu + au*bd;
        u64 midu = mid>>30;
        u64 midd = mid&MASK30;
        return (au * bu * 2 + midu + (midd << 31) + ad * bd);
    }

    u64 safe_mod(const u64 &a) const {
        u64 au = a >> 61;
        u64 ad = a & mod;
        u64 res = au + ad;
        if(res >= mod) res -= mod;
        return res;
    }
public:
    rolling_hash(const std::string &_s) : s(_s), sz(_s.size()) {
        base.reserve(n);
        base_pow.resize(n);
        hash.resize(n);
        for(int i = 0; i < n; ++i) {
            base.emplace_back(rnd.get(0, mod));
            base_pow[i].reserve(sz+1);
            base_pow[i].emplace_back(1);
            hash[i].reserve(sz+1);
            hash[i].emplace_back(0);
            for(const auto &c: s) {
                hash[i].emplace_back(safe_mod(mul(hash[i].back(), base[i]) + c + h));
                base_pow[i].emplace_back(safe_mod(mul(base_pow[i].back(), base[i])));
            }
        }
    }

    // [l, r)
    std::vector<u64> get_hash(int l, int r) const {
        std::vector<u64> ret(n);
        for(int i = 0; i < n; ++i) {
            ret[i] = safe_mod(hash[i][r] + buffer - mul(hash[i][l], base_pow[i][r-l]));
        }
        return ret;
    }
private:
    std::string s;
    size_t sz;
    std::vector<u64> base;
    std::vector<std::vector<u64>> base_pow;
    std::vector<std::vector<u64>> hash;
};

}