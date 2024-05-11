#pragma once

#include <vector>

#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
std::vector<mint> product_of_fps(std::vector<std::vector<mint>> fs) {
    if (fs.empty()) return {1};
    int i = 0;
    while (i + 1 < (int)fs.size()) {
        fs.emplace_back(convolution(fs[i], fs[i+1]));
        i += 2;
    }
    return fs.back();
}

}  // namespace ebi