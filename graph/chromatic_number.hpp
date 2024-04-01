#pragma once

#include <cassert>
#include <ranges>
#include <vector>

#include "../convolution/or_convolution.hpp"
#include "../graph/base.hpp"

namespace ebi {

template <class T> int chromatic_number(const Graph<T> &g) {
    int n = g.node_number();
    std::vector<int> es(n, 0);
    for (auto e : g.get_edges()) {
        es[e.from] |= 1 << e.to;
    }
    std::vector<int> dp1(1 << n, 1);
    for (int s : std::views::iota(0, 1 << n)) {
        for (int v : std::views::iota(0, n)) {
            if (((s >> v) & 1) && (s & es[v])) {
                dp1[s] = 0;
            }
        }
    }
    if (dp1.back() == 1) return 1;
    auto now = dp1;
    for (int k : std::views::iota(2, n + 1)) {
        int sz = now.size();
        now = or_convolution(dp1, now);
        if (now.back() > 0) {
            return k;
        }
        for (int i : std::views::iota(0, sz / 2)) {
            now[i] = now[i + sz / 2] > 0;
        }
        now.resize(sz / 2);
        dp1.resize(sz / 2);
    }
    assert(0);
}

}  // namespace ebi