#pragma once

#include <utility>

#include "../algorithm/golden_section_search.hpp"
#include "../algorithm/monge_shortest_path.hpp"

namespace ebi {

template <class F, class T = decltype(std::declval<F>()(std::declval<int>(),
                                                        std::declval<int>()))>
T monge_d_edge_shortest_path(int n, int d, T upper, F f) {
    auto dp = [&](T x) -> T {
        auto g = [&](int i, int j) -> T { return f(i, j) + x; };
        T c = monge_shortest_path(n, g)[n - 1];
        return c - x * d;
    };
    return golden_section_search(dp, -upper, upper, std::greater<T>());
}

}  // namespace ebi