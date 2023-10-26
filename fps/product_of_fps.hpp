#pragma once

#include <deque>
#include <vector>

#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
std::vector<mint> product_of_fps(const std::vector<std::vector<mint>> &fs) {
    if (fs.empty()) return {1};
    std::deque<std::vector<mint>> deque;
    for (auto &f : fs) deque.push_back(f);
    while (deque.size() > 1) {
        auto f = deque.front();
        deque.pop_front();
        auto g = deque.front();
        deque.pop_front();
        deque.push_back(convolution(f, g));
    }
    return deque.front();
}

}  // namespace ebi