#pragma once

#include <atcoder/convolution>
#include <cassert>
#include <string>
#include <vector>

namespace ebi {

template <char base = 'a', char wildcard = '*'>
std::vector<bool> wildcard_pattern_matching(const std::string &s,
                                            const std::string &t) {
    int n = s.size(), m = t.size();
    if (n < m) return std::vector<bool>(n, false);
    std::vector<long long> s1(n), s2(n), s3(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == wildcard) continue;
        s1[i] = s[i] - base + 1;
        s2[i] = s1[i] * s1[i];
        s3[i] = s2[i] * s1[i];
    }
    std::vector<long long> t1(m), t2(m), t3(m);
    for (int i = 0; i < m; i++) {
        if (t[m - 1 - i] == wildcard) continue;
        t1[i] = t[m - 1 - i] - base + 1;
        t2[i] = t1[i] * t1[i];
        t3[i] = t2[i] * t1[i];
    }
    auto s3t1 = atcoder::convolution_ll(s3, t1),
         s2t2 = atcoder::convolution_ll(s2, t2),
         s1t3 = atcoder::convolution_ll(s1, t3);
    std::vector<bool> res(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        long long val = s3t1[i + m - 1] - 2 * s2t2[i + m - 1] + s1t3[i + m - 1];
        res[i] = (val == 0);
    }
    return res;
}

}  // namespace ebi