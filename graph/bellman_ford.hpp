#pragma once

#include <cassert>
#include <limits>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>

#include "../graph/template.hpp"

namespace ebi {

template <class T> std::vector<T> bellman_ford(int s, const Graph<T> &g) {
    int n = (int)g.size();
    assert(0 <= s && s < n);
    std::vector<T> dist(n, std::numeric_limits<T>::max());
    dist[s] = 0;
    std::vector<std::tuple<int, int, T>> edges;
    for (auto from : std::views::iota(0, n)) {
        for (auto [to, cost] : g[from]) {
            edges.emplace_back(from, to, cost);
        }
    }
    for (auto i : std::views::iota(0, n)) {
        for (auto [from, to, cost] : edges) {
            if (dist[from] == std::numeric_limits<T>::max()) continue;
            if (dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
                if (i == n - 1) {
                    return {};
                }
            }
        }
    }
    return dist;
}

}  // namespace ebi