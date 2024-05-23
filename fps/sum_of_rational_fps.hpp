#pragma once

#include <algorithm>
#include <vector>

#include "../fps/fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
std::pair<FormalPowerSeries<mint>, FormalPowerSeries<mint>> sum_of_rational_fps(
    std::vector<std::pair<FormalPowerSeries<mint>, FormalPowerSeries<mint>>>
        fs) {
    if (fs.empty()) {
        return {{0}, {1}};
    }
    using FPS = FormalPowerSeries<mint>;
    using P = std::pair<FPS, FPS>;
    auto add = [&](const P &a, const P &b) -> P {
        return {a.first * b.second + a.second * b.first, a.second * b.second};
    };
    int i = 0;
    while (i + 1 < (int)fs.size()) {
        fs.emplace_back(add(fs[i], fs[i + 1]));
        i += 2;
    }
    return fs.back();
}

}  // namespace ebi