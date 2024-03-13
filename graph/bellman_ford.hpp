#pragma once

#include <cassert>
#include <limits>
#include <optional>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T>
std::optional<std::vector<T>> bellman_ford(int s, const Graph<T> &g) {
    int n = g.size();
    assert(0 <= s && s < n);
    std::vector<T> dist(n, std::numeric_limits<T>::max());
    dist[s] = 0;
    std::vector<std::tuple<int, int, T>> edges;
    for (auto from : std::views::iota(0, n)) {
        for (auto e : g[from]) {
            edges.emplace_back(from, e.to, e.cost);
        }
    }
    for (auto i : std::views::iota(0, n)) {
        for (auto [from, to, cost] : edges) {
            if (dist[from] == std::numeric_limits<T>::max()) continue;
            if (dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
                if (i == n - 1) {
                    return std::nullopt;
                }
            }
        }
    }
    return dist;
}

}  // namespace ebi