#pragma once

#include <cassert>
#include <string>
#include <vector>

#include "../fps/middle_product_arbitrary.hpp"

namespace ebi {

template <char base = 'a', char wildcard = '*'>
std::vector<bool> wildcard_pattern_matching(const std::string &s,
                                            const std::string &t) {
    int n = s.size(), m = t.size();
    if (n < m) return std::vector<bool>(n, false);
    std::vector<u64> s1(n), s2(n), s3(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == wildcard) continue;
        s1[i] = s[i] - base + 1;
        s2[i] = s1[i] * s1[i];
        s3[i] = s2[i] * s1[i];
    }
    std::vector<u64> t1(m), t2(m), t3(m);
    for (int i = 0; i < m; i++) {
        if (t[i] == wildcard) continue;
        t1[i] = t[i] - base + 1;
        t2[i] = t1[i] * t1[i];
        t3[i] = t2[i] * t1[i];
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

}  // namespace ebi