#pragma once

#include <vector>
#include <utility>
#include <cassert>

namespace ebi {

template <class V, class E, E (*e)(), E (*merge)(E, E), E (*put_edge)(int, V),
          V (*put_root)(int, E)>
struct rerooting {
  private:
    V dfs_sub(int v, int par = -1) {
        E ret = e();
        for (auto &edge : g[v]) {
            if (edge.first == par && g[v].back().first != par)
                std::swap(g[v].back(), edge);
            auto [nv, index] = edge;
            if (nv == par) continue;
            E val = put_edge(index, dfs_sub(nv, v));
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
            auto [nv, index] = g[v][i];
            E ret = put_edge(
                index, put_root(v, merge(merge(lcum[i], rcum[i + 1]), rev)));
            dfs_all(nv, v, ret);
        }
        dp[v] = put_root(v, merge(lcum[sz], rev));
    }

  public:
    rerooting(int n, const std::vector<std::pair<int, int>> &edges)
        : n(n), g(n), sub(n), dp(n), outs(n) {
        for (int i = 0; i < (int)edges.size(); i++) {
            auto [u, v] = edges[i];
            g[u].emplace_back(v, i);
            if ((int)edges.size() == n - 1) g[v].emplace_back(u, i);
        }
        assert((int)edges.size() == n - 1 || (int)edges.size() == 2 * (n - 1));

        dfs_sub(0);
        dfs_all(0);
    }

    V get(int v) const {
        return dp[v];
    }

  private:
    int n;
    std::vector<std::vector<std::pair<int, int>>> g;
    std::vector<V> sub;
    std::vector<V> dp;
    std::vector<std::vector<E>> outs;
};

}  // namespace ebi
