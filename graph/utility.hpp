#pragma once

#include "graph/base.hpp"

namespace ebi {

template <class T> Graph<T> remove_isolated_vertex(const Graph<T> &g) {
    const int n = g.node_number();
    std::vector<int> seen(n, -1);
    for (auto e : g.get_edges()) {
        seen[e.from] = seen[e.to] = 1;
    }
    int sz = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i] != -1) seen[i] = sz++;
    }
    Graph<T> gh(sz);
    for (auto e : g.get_edges()) {
        gh.add_undirected_edge(seen[e.from], seen[e.to], e.cost);
    }
    gh.build();
    return gh;
}

template <class T>
std::vector<std::vector<T>> remove_isolated_vertex(
    const std::vector<std::vector<T>> &g) {
    const int n = (int)g.size();
    std::vector<int> seen(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] != 0) seen[i] = seen[j] = 1;
        }
    }
    int sz = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i] != -1) seen[i] = sz++;
    }
    std::vector gh(sz, std::vector<int>(sz, 0));
    for (int i = 0; i < n; i++) {
        if (seen[i] == -1) continue;
        for (int j = 0; j < n; j++) {
            if (seen[j] == -1) continue;
            gh[seen[i]][seen[j]] += g[i][j];
        }
    }
    return gh;
}

}  // namespace ebi