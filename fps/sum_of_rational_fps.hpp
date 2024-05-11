#pragma once

#include <algorithm>
#include <vector>

#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
std::pair<std::vector<mint>, std::vector<mint>> sum_of_rational_fps(
    std::vector<std::pair<std::vector<mint>, std::vector<mint>>> fs) {
    if (fs.empty()) {
        return {{0}, {1}};
    }
    using P = std::pair<std::vector<mint>, std::vector<mint>>;
    auto add = [&](const P &a, const P &b) -> P {
        int na = a.first.size() - 1, ma = a.second.size() - 1;
        int nb = b.first.size() - 1, mb = b.second.size() - 1;
        int n = std::max(na + mb, nb + ma);
        std::vector<mint> p(n + 1, 0);
        {
            auto f = convolution(a.first, b.second);
            for (int i = 0; i < na + mb + 1; i++) {
                p[i] += f[i];
            }
        }
        {
            auto f = convolution(a.second, b.first);
            for (int i = 0; i < nb + ma + 1; i++) {
                p[i] += f[i];
            }
        }
        return {p, convolution(a.second, b.second)};
    };
    int i = 0;
    while (i + 1 < (int)fs.size()) {
        fs.emplace_back(add(fs[i], fs[i + 1]));
        i += 2;
    }
    return fs.back();
}

}  // namespace ebi