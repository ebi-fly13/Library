#pragma once

#include <cassert>
#include <utility>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class V, class E, class T, class ID, class MERGE, class PUT_EDGE,
          class PUT_ROOT>
std::vector<V> rerooting_dp(Graph<T> g, const ID &e, const MERGE &merge,
                            const PUT_EDGE &put_edge,
                            const PUT_ROOT &put_root) {
    int n = g.node_number();
    std::vector<V> dp(n);
    std::vector outs(n, std::vector<E>());
    auto dfs_sub = [&](auto &&self, int v, int par = -1) -> V {
        E ret = e();
        for (auto &edge : g[v]) {
            if (edge.to == par && g[v].back().to != par) {
                std::swap(edge, g[v].back());
            }
            if (edge.to == par) continue;
            E val = put_edge(edge.id, self(self, edge.to, v));
            outs[v].emplace_back(val);
            ret = merge(ret, val);
        }
        return put_root(v, ret);
    };
    dfs_sub(dfs_sub, 0);
    auto dfs_all = [&](auto &&self, int v, int par, E rev) -> void {
        int sz = outs[v].size();
        std::vector<E> lcum(sz + 1, e()), rcum(sz + 1, e());
        for (int i = 0; i < sz; i++) {
            lcum[i + 1] = merge(lcum[i], outs[v][i]);
            rcum[sz - i - 1] = merge(outs[v][sz - i - 1], rcum[sz - i]);
        }
        for (int i = 0; i < sz; i++) {
            auto edge = g[v][i];
            E ret = put_edge(
                edge.id, put_root(v, merge(merge(lcum[i], rcum[i + 1]), rev)));
            self(self, edge.to, v, ret);
        }
        dp[v] = put_root(v, merge(lcum[sz], rev));
    };
    dfs_all(dfs_all, 0, -1, e());
    return dp;
}

}  // namespace ebi
