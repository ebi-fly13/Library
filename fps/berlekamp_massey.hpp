#pragma once

#include <algorithm>
#include <vector>

#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
std::vector<mint> berlekamp_massey(const std::vector<mint> &s) {
    std::vector<mint> C = {1}, B = {1};
    int L = 0, m = 1;
    mint b = 1;
    auto proceed = [](std::vector<mint> &C, const std::vector<mint> &B, mint d,
                      mint b, int m) -> void {
        C.resize(std::max(C.size(), B.size() + m));
        mint f = d / b;
        for (int i = 0; i < (int)B.size(); i++) {
            C[i + m] -= f * B[i];
        }
    };
    for (int n = 0; n < (int)s.size(); n++) {
        mint d = s[n];
        for (int i = 1; i <= L; i++) {
            d += s[n - i] * C[i];
        }
        if (d == 0) {
            m++;
        } else if (2 * L <= n) {
            auto T = C;
            proceed(C, B, d, b, m);
            L = n + 1 - L;
            B = T;
            b = d;
            m = 1;
        } else {
            proceed(C, B, d, b, m++);
        }
    }
    return C;
}

}  // namespace ebi