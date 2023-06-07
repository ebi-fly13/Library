#pragma once

#include <cassert>
#include <vector>

namespace ebi {

template <class mint>
std::vector<mint> inv_sparse(const std::vector<mint> &f, int d = -1) {
    assert(f[0] != 0);
    if (d < 0) {
        d = f.size();
    }
    std::vector<std::pair<int, mint>> ret;
    for (int i = 1; i < int(f.size()); i++) {
        if (f[i] != 0) {
            ret.emplace_back(i, f[i]);
        }
    }
    std::vector<mint> g(d);
    g[0] = f[0].inv();
    for (int i = 1; i < d; i++) {
        for (auto [k, p] : ret) {
            if (i - k < 0) break;
            g[i] -= g[i - k] * p;
        }
        g[i] *= g[0];
    }
    return g;
}

}  // namespace ebi