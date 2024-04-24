#pragma once

#include <algorithm>
#include <utility>
#include <vector>

#include "../data_structure/dsu.hpp"
#include "../graph/base.hpp"

namespace ebi {

template <class T> std::pair<T, std::vector<int>> mst(const Graph<T> &g) {
    dsu uf(g.size());
    std::vector<Edge<T>> edges;
    for (auto v : std::views::iota(0, g.size())) {
        for (auto e : g[v]) {
            edges.emplace_back(e);
        }
    }
    std::sort(edges.begin(), edges.end(),
              [](const Edge<T> &a, const Edge<T> &b) -> bool {
                  return a.cost < b.cost;
              });
    std::vector<int> used;
    T sum = 0;
    for (auto e : edges) {
        if (uf.same(e.from, e.to)) continue;
        uf.merge(e.from, e.to);
        used.emplace_back(e.id);
        sum += e.cost;
    }

    return {sum, used};
}

}  // namespace ebi