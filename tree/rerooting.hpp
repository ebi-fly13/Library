#pragma once

#include <cassert>
#include <utility>
#include <vector>

#include "../graph/base.hpp"
#include "../tree/heavy_light_decomposition.hpp"

namespace ebi {

template <class T, class V> struct rerooting_dp {
    template <class MERGE, class PUT_EDGE, class PUT_ROOT>
    rerooting_dp(const Graph<T> &tree, const V e, const MERGE &merge,
                 const PUT_EDGE &put_edge, const PUT_ROOT &put_root)
        : n(tree.node_number()),
          hld(tree),
          full_tree_dp(n, e),
          child_dp(n, e),
          parent_dp(n, e) {
        auto dfs_sub = [&](auto &&self, int v, int par = -1) -> void {
            for (const auto &edge : tree[v]) {
                if (edge.to == par) continue;
                self(self, edge.to, v);
                child_dp[v] =
                    merge(child_dp[v], put_edge(edge, child_dp[edge.to]));
            }
            child_dp[v] = put_root(v, child_dp[v]);
        };
        dfs_sub(dfs_sub, 0);
        auto dfs_all = [&](auto &&self, int v, int par = -1) -> void {
            std::vector<int> ch;
            std::vector<V> dp;
            V ret = e;
            for (const auto &edge : tree[v]) {
                if (edge.to == par) {
                    ret = put_edge(edge, parent_dp[v]);
                } else {
                    ch.emplace_back(edge.to);
                    dp.emplace_back(put_edge(edge, child_dp[edge.to]));
                }
            }
            int sz = (int)ch.size();
            if (ch.empty()) {
                full_tree_dp[v] = put_root(v, ret);
                return;
            }
            std::vector<V> lcum(sz, ret);
            for (int i = 0; i < sz - 1; i++) {
                lcum[i + 1] = merge(lcum[i], dp[i]);
            }
            V rcum = e;
            for (int i = sz - 1; i >= 0; i--) {
                parent_dp[ch[i]] = put_root(v, merge(lcum[i], rcum));
                rcum = merge(rcum, dp[i]);
            }
            for (int i = 0; i < sz; i++) {
                self(self, ch[i], v);
            }
            full_tree_dp[v] = put_root(v, merge(rcum, ret));
        };
        dfs_all(dfs_all, 0);
    }

    V get(int v) const {
        return get(v, v);
    }

    V get(int v, int root) const {
        if (root == v) return full_tree_dp[v];
        if (!hld.is_subtree(v, root)) {
            return child_dp[v];
        }
        return parent_dp[hld.jump(v, root, 1)];
    }

    std::vector<V> get_full_dp() const {
        return full_tree_dp;
    }

  private:
    int n;
    heavy_light_decomposition<T> hld;
    std::vector<V> full_tree_dp;
    std::vector<V> child_dp;
    std::vector<V> parent_dp;
};

}  // namespace ebi
