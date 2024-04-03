#pragma once

#include <cassert>
#include <ranges>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T> std::vector<int> maximum_independent_set(const Graph<T> &g) {
    int n = g.node_number();
    std::vector<int> deg(n);
    for (auto v : std::views::iota(0, n)) {
        deg[v] = g[v].size();
    }
    std::vector<int> max_set;
    std::vector<int> used;
    std::vector<int> dead(n, 0);
    int alive = n;
    auto dfs = [&](auto &&self) -> void {
        if ((int)used.size() + alive <= (int)max_set.size()) return;
        int v = -1;
        for (auto u : std::views::iota(0, n)) {
            if (dead[u]) continue;
            if (deg[u] <= 1) {
                v = u;
                break;
            }
            if (v == -1 || deg[v] < deg[u]) v = u;
        }
        if (v < 0) return;

        if (deg[v] > 1) {
            dead[v] = 1;
            alive--;
            for (auto e : g[v]) deg[e.to]--;

            self(self);

            dead[v] = 0;
            alive++;
            for (auto e : g[v]) deg[e.to]++;
        }
        {
            used.emplace_back(v);
            dead[v] = 1;
            alive--;
            for (auto e : g[v]) {
                if (dead[e.to]++ == 0) {
                    alive--;
                }
            }
            if (max_set.size() < used.size()) max_set = used;

            self(self);

            used.pop_back();
            dead[v] = 0;
            alive++;
            for (auto e : g[v]) {
                if (--dead[e.to] == 0) {
                    alive++;
                }
            }
        }
    };
    dfs(dfs);
    return max_set;
}

}  // namespace ebi