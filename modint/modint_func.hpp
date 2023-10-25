#pragma once

#include <vector>
#include <cassert>

#include "base.hpp"

namespace ebi {

template <modint mint> mint inv(int n) {
    static const int mod = mint::mod();
    static std::vector<mint> dat = {0, 1};
    assert(0 <= n);
    if (n >= mod) n -= mod;
    while (int(dat.size()) <= n) {
        int num = dat.size();
        int q = (mod + num - 1) / num;
        dat.emplace_back(dat[num * q - mod] * mint(q));
    }
    return dat[n];
}

}  // namespace ebi