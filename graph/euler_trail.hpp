#pragma once

#include <algorithm>
#include <cassert>
#include <optional>
#include <ranges>
#include <utility>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T>
std::optional<std::pair<std::vector<int>, std::vector<int>>>
euler_trail_undirected(const Graph<T> &g, bool circuit = false) {
    int n = g.node_number();
    int m = g.edge_number();
    int s = -1, t = -1;
    for (int v : std::views::iota(0, n)) {
        if (g[v].size() & 1) {
            if (s < 0)
                s = v;
            else if (t < 0)
                t = v;
            else
                return std::nullopt;
        }
    }
    if (circuit && s != -1) return std::nullopt;
    if (!circuit && (s != -1 && t == -1)) return std::nullopt;
    if (m == 0) return std::pair<std::vector<int>, std::vector<int>>({0}, {});
    if (s < 0) s = g.get_edge(0).from;
    std::vector<int> ids(n, 0);
    std::vector<bool> used(m, false);
    std::vector<int> vs, es;
    auto dfs = [&](auto &&self, int v) -> void {
        while (ids[v] < (int)g[v].size()) {
            auto e = g[v][ids[v]++];
            if (used[e.id]) continue;
            used[e.id] = true;
            self(self, e.to);
            es.emplace_back(e.id);
        }
        vs.emplace_back(v);
    };
    dfs(dfs, s);
    if ((int)es.size() != m) return std::nullopt;
    return std::pair<std::vector<int>, std::vector<int>>(vs, es);
}

template <class T>
std::optional<std::pair<std::vector<int>, std::vector<int>>>
euler_trail_directed(const Graph<T> &g, bool circuit = false) {
    int n = g.node_number();
    int m = g.edge_number();
    std::vector<int> in(n, 0), out(n, 0);
    for (auto e : g.get_edges()) {
        in[e.to]++;
        out[e.from]++;
    }
    int s = -1, t = -1;
    for (auto v : std::views::iota(0, n)) {
        if (in[v] + 1 == out[v]) {
            if (s != -1) return std::nullopt;
            s = v;
        } else if (in[v] == out[v] + 1) {
            if (t != -1) return std::nullopt;
            t = v;
        } else if (in[v] == out[v])
            continue;
        else
            return std::nullopt;
    }
    if (circuit && (s != -1 || t != -1)) return std::nullopt;
    if (!circuit && ((s == -1 && t != -1) || (s != -1 && t == -1)))
        return std::nullopt;
    if (m == 0) return std::pair<std::vector<int>, std::vector<int>>({0}, {});
    if (s == -1) s = g.get_edge(0).from;
    std::vector<int> vs, es;
    std::vector<int> ids(n, 0);
    auto dfs = [&](auto &&self, int v) -> void {
        while (ids[v] < (int)g[v].size()) {
            auto e = g[v][ids[v]++];
            self(self, e.to);
            es.emplace_back(e.id);
        }
        vs.emplace_back(v);
    };
    dfs(dfs, s);
    if ((int)es.size() != m) return std::nullopt;
    std::reverse(vs.begin(), vs.end());
    std::reverse(es.begin(), es.end());
    return std::pair<std::vector<int>, std::vector<int>>(vs, es);
}

}  // namespace ebi