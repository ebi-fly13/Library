#pragma once

#include <cassert>
#include <utility>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T, class V, class E, E (*e)(), E (*merge)(E, E),
          E (*put_edge)(T, V), V (*put_root)(int, E)>
struct rerooting {
  private:
    V dfs_sub(int v, int par = -1) {
        E ret = e();
        for (auto &edge : g[v]) {
            if (edge.to == par && g[v].back().to != par)
                std::swap(g[v].back(), edge);
            if (edge.to == par) continue;
            E val = put_edge(edge.cost, dfs_sub(edge.to, v));
            outs[v].emplace_back(val);
            ret = merge(ret, val);
        }
        sub[v] = put_root(v, ret);
        return sub[v];
    }

    void dfs_all(int v, int par = -1, E rev = e()) {
        int sz = outs[v].size();
        std::vector<E> lcum(sz + 1, e()), rcum(sz + 1, e());
        for (int i = 0; i < sz; i++) {
            lcum[i + 1] = merge(lcum[i], outs[v][i]);
            rcum[sz - i - 1] = merge(rcum[sz - i], outs[v][sz - i - 1]);
        }
        for (int i = 0; i < sz; i++) {
            auto edge = g[v][i];
            E ret =
                put_edge(edge.cost,
                         put_root(v, merge(merge(lcum[i], rcum[i + 1]), rev)));
            dfs_all(edge.to, v, ret);
        }
        dp[v] = put_root(v, merge(lcum[sz], rev));
    }

  public:
    rerooting(const Graph<T> &g_)
        : n((int)g_.size()), g(g_), sub(n), dp(n), outs(n) {
        dfs_sub(0);
        dfs_all(0);
    }

    V get(int v) const {
        return dp[v];
    }

  private:
    int n;
    Graph<T> g;
    std::vector<V> sub;
    std::vector<V> dp;
    std::vector<std::vector<E>> outs;
};

}  // namespace ebi
