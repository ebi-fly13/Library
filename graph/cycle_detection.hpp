#pragma once

#include <optional>
#include <utility>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T>
std::optional<std::pair<std::vector<int>, std::vector<int>>>
cycle_detection_undirected(const Graph<T> &g) {
    int n = g.node_number();
    int m = g.edge_number();
    std::vector<bool> used_edge(m, false);
    std::vector<int> depth(n, -1);
    std::vector<int> par_idx(n, -1);

    auto dfs = [&](auto &&self, int v) -> int {
        for (auto e : g[v]) {
            if (used_edge[e.id]) continue;
            if (depth[e.to] != -1) return e.id;
            used_edge[e.id] = true;
            par_idx[e.to] = e.id;
            depth[e.to] = depth[v] + 1;
            int x = self(self, e.to);
            if (x != -1) return x;
        }
        return -1;
    };

    for (auto v : std::views::iota(0, n)) {
        if (depth[v] != -1) continue;
        depth[v] = 0;
        int id = dfs(dfs, v);
        if (id == -1) continue;
        int s = -1;
        {
            auto e = g.get_edge(id);
            if (depth[e.to] < depth[e.from])
                s = e.to;
            else
                s = e.from;
        }
        std::vector<int> vs, es;
        vs.emplace_back(s), es.emplace_back(id);
        while (1) {
            auto e = g.get_edge(es.back());
            int u = e.from ^ e.to ^ vs.back();
            if (u == s) break;
            vs.emplace_back(u), es.emplace_back(par_idx[u]);
        }
        return std::pair<std::vector<int>, std::vector<int>>{vs, es};
    }
    return std::nullopt;
}

}  // namespace ebi