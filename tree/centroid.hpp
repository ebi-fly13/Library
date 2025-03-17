#pragma once

#include "../graph/base.hpp"

namespace ebi {

template <class T> std::vector<int> get_centroid(const Graph<T> &tree) {
    int n = tree.node_number();
    std::vector<int> sz(n, 1);
    std::vector<int> centroid;
    auto dfs = [&](auto &&self, int v, int par = -1) -> void {
        bool is_centroid = true;
        for (auto e : tree[v]) {
            if (e.to == par) continue;
            self(self, e.to, v);
            if (sz[e.to] > n / 2) is_centroid = false;
            sz[v] += sz[e.to];
        }
        if (n - sz[v] > n / 2) is_centroid = false;
        if (is_centroid) centroid.emplace_back(v);
    };
    dfs(dfs, 0);
    return centroid;
}

}  // namespace ebi