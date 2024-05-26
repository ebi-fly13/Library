#pragma once

#include <cassert>
#include <string>
#include <vector>

#include "../fps/middle_product.hpp"
#include "../fps/middle_product_arbitrary.hpp"
#include "../modint/modint.hpp"
#include "../utility/random_number_generator.hpp"

namespace ebi {

template <char base = 'a', char wildcard = '*'>
std::vector<bool> wildcard_pattern_matching_determistic(const std::string &s,
                                                        const std::string &t) {
    int n = s.size(), m = t.size();
    if (n < m) return std::vector<bool>(n, false);
    std::vector<u64> s1(n), s2(n), s3(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == wildcard) continue;
        int x = s[i] - base + 1;
        s1[i] = 1;
        s2[i] = x * s1[i];
        s3[i] = x * s2[i];
    }
    std::vector<u64> t1(m), t2(m), t3(m);
    for (int i = 0; i < m; i++) {
        if (t[i] == wildcard) continue;
        int x = t[i] - base + 1;
        t1[i] = 1;
        t2[i] = x * t1[i];
        t3[i] = x * t2[i];
    }
    auto s3t1 = middle_product_mod_2_64(s3, t1),
         s2t2 = middle_product_mod_2_64(s2, t2),
         s1t3 = middle_product_mod_2_64(s1, t3);
    std::vector<bool> res(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        long long val = s3t1[i] - 2 * s2t2[i] + s1t3[i];
        res[i] = (val == 0);
    }
    return res;
}

template <char base = 'a', char wildcard = '*'>
std::vector<bool> wildcard_pattern_matching_998(const std::string &s,
                                                const std::string &t) {
    using mint = modint998244353;
    int n = s.size(), m = t.size();
    if (n < m) return std::vector<bool>(n, false);
    assert(m <= 1'400'000);
    std::vector<mint> s1(n), s2(n), s3(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == wildcard) continue;
        int x = s[i] - base + 1;
        s1[i] = 1;
        s2[i] = x * s1[i];
        s3[i] = x * s2[i];
    }
    std::vector<mint> t1(m), t2(m), t3(m);
    for (int i = 0; i < m; i++) {
        if (t[i] == wildcard) continue;
        int x = t[i] - base + 1;
        t1[i] = 1;
        t2[i] = x * t1[i];
        t3[i] = x * t2[i];
    }
    auto s3t1 = middle_product(s3, t1), s2t2 = middle_product(s2, t2),
         s1t3 = middle_product(s1, t3);
    std::vector<bool> res(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        mint val = s3t1[i] - 2 * s2t2[i] + s1t3[i];
        res[i] = (val == 0);
    }
    return res;
}

template <char base = 'a', char wildcard = '*'>
std::vector<bool> wildcard_pattern_matching_random(const std::string &s,
                                                   const std::string &t) {
    using mint = modint998244353;
    int n = s.size(), m = t.size();
    if (n < m) return std::vector<bool>(n, false);
    std::vector<mint> s1(n), s2(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == wildcard) continue;
        s1[i] = 1;
        s2[i] = s[i] - base + 1;
    }
    random_number_generator rng;
    std::vector<mint> t1(m), t2(m);
    for (int i = 0; i < m; i++) {
        if (t[i] == wildcard) continue;
        int r = rng.get(0, mint::mod());
        t1[i] = r;
        t2[i] = r * (t[i] - base + 1);
    }
    auto s2t1 = middle_product(s2, t1), s1t2 = middle_product(s1, t2);
    std::vector<bool> res(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        mint val = s2t1[i] - s1t2[i];
        res[i] = (val == 0);
    }
    return res;
}

template <char base = 'a', char wildcard = '*'>
std::vector<bool> wildcard_pattern_matching(const std::string &s,
                                            const std::string &t,
                                            bool determistic = false) {
    if (t.size() <= 1'400'000) {
        return wildcard_pattern_matching_998<base, wildcard>(s, t);
    }
    if (determistic)
        return wildcard_pattern_matching_determistic<base, wildcard>(s, t);
    return wildcard_pattern_matching_random<base, wildcard>(s, t);
}

}  // namespace ebi