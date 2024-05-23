#pragma once

#include <vector>

#include "../convolution/convolution.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
std::vector<std::vector<mint>> convolution_2d(
    const std::vector<std::vector<mint>> &a,
    const std::vector<std::vector<mint>> &b) {
    if (a.empty() || b.empty()) return {};
    int h1 = (int)a.size(), w1 = (int)a[0].size();
    int h2 = (int)b.size(), w2 = (int)b[0].size();
    int h = h1 + h2 - 1, w = w1 + w2 - 1;
    std::vector<mint> f(h1 * w, 0), g(h2 * w, 0);
    for (int i = 0; i < h1; i++) {
        std::copy(a[i].begin(), a[i].end(), f.begin() + i * w);
    }
    for (int i = 0; i < h2; i++) {
        std::copy(b[i].begin(), b[i].end(), g.begin() + i * w);
    }
    auto fg = convolution(f, g);
    std::vector c(h, std::vector<mint>(w, 0));
    for (int i = 0; i < h; i++) {
        std::copy(fg.begin() + i * w, fg.begin() + (i + 1) * w, c[i].begin());
    }
    return c;
}

template <Modint mint>
std::vector<std::vector<mint>> convolution_2d_naive(
    const std::vector<std::vector<mint>> &a,
    const std::vector<std::vector<mint>> &b) {
    int h1 = (int)a.size(), w1 = (int)a[0].size();
    int h2 = (int)b.size(), w2 = (int)b[0].size();
    int h = h1 + h2 - 1, w = w1 + w2 - 1;
    std::vector c(h, std::vector<mint>(w, 0));
    for (int i = 0; i < h1; i++) {
        for (int j = 0; j < w1; j++) {
            for (int k = 0; k < h2; k++) {
                for (int l = 0; l < w2; l++) {
                    c[i + k][j + l] += a[i][j] * b[k][l];
                }
            }
        }
    }
    return c;
}

}  // namespace ebi