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

    u64 safe_mul(const u64 &a, const u64 &b) const {
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
        base_pow.resize(n);
        hash.resize(n);
        for(int i = 0; i < n; ++i) {
            base_pow[i].reserve(sz+1);
            base_pow[i].emplace_back(1);
            hash[i].reserve(sz+1);
            hash[i].emplace_back(0);
            for(const auto &c: s) {
                hash[i].emplace_back(safe_mod(safe_mul(hash[i].back(), base[i]) + c + h));
                base_pow[i].emplace_back(safe_mod(safe_mul(base_pow[i].back(), base[i])));
            }
        }
    }

    // [l, r)
    std::vector<u64> get_hash(int l, int r) const {
        std::vector<u64> ret(n);
        for(int i = 0; i < n; ++i) {
            ret[i] = safe_mod(hash[i][r] + buffer - safe_mul(hash[i][l], base_pow[i][r-l]));
        }
        return ret;
    }

    std::vector<u64> get_hash(const std::string &str, int l = 0, int r = -1) const {
        if(r < 0) r = int(str.size());
        std::vector<u64> res(n, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = l; j < r; ++j) {
                res[i] = safe_mod(safe_mul(res[i], base[i]) + s[i] + h);
            }
        }
        return res;
    }

    static void set_base() {
        random_number_generator_64 rnd;
        base.resize(n);
        for(int i = 0; i < n; ++i) {
            base[i] = rnd.get(0, (1UL<<61) - 1);
        }
    }
private:
    std::string s;
    size_t sz;
    std::vector<std::vector<u64>> base_pow;
    std::vector<std::vector<u64>> hash;
public:
    static std::vector<u64> base;
};

template<int n>
std::vector<std::uint64_t> rolling_hash<n>::base = {12345, 10000000};

}