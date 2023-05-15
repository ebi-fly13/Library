#pragma once

/*
    refernce: https://www.slideshare.net/wata_orz/ss-12131479
              https://37zigen.com/subset-convolution/
*/

#include <array>
#include <cassert>
#include <vector>

#include "../algorithm/ranked_zeta.hpp"
#include "../utility/bit_operator.hpp"

namespace ebi {

template <class T, int LIM = 20>
std::vector<T> subset_convolution(const std::vector<T> &a,
                                  const std::vector<T> &b) {
    auto ra = ranked_zeta<T, LIM>(a);
    auto rb = ranked_zeta<T, LIM>(b);
    int n = topbit(ra.size());
    for (int s = (1 << n) - 1; s >= 0; s--) {
        auto &f = ra[s];
        const auto &g = rb[s];
        for (int d = n; d >= 0; d--) {
            T x = 0;
            for (int i = 0; i <= d; i++) {
                x += f[i] * g[d - i];
            }
            f[d] = x;
        }
    }
    return ranked_mobius<T, LIM>(ra);
}

}  // namespace ebi