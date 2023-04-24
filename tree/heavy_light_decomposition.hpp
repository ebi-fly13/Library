#pragma once

#include <iostream>
#include <vector>

namespace ebi {

struct heavy_light_decomposition {
   private:
    void dfs_sz(int v) {
        for (auto &nv : g[v]) {
            if (nv == par[v]) continue;
            par[nv] = v;
            depth[nv] = depth[v] + 1;
            dfs_sz(nv);
            sz[v] += sz[nv];
            if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v])
                std::swap(nv, g[v][0]);
        }
    }

    void dfs_hld(int v) {
        static int t = 0;
        in[v] = t++;
        for (auto nv : g[v]) {
            if (nv == par[v]) continue;
            nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);
            dfs_hld(nv);
        }
        out[v] = t;
    }

    // [u, v) パスの取得 (v は u の祖先)
    std::vector<std::pair<int, int>> ascend(int u, int v) const {
        std::vector<std::pair<int, int>> res;
        while (nxt[u] != nxt[v]) {
            res.emplace_back(in[u], in[nxt[u]]);
            u = par[nxt[u]];
        }
        if (u != v) res.emplace_back(in[u], in[v] + 1);
        return res;
    }

    // (u, v] パスの取得 (u は v の祖先)
    std::vector<std::pair<int, int>> descend(int u, int v) const {
        if (u == v) return {};
        if (nxt[u] == nxt[v]) return {{in[u] + 1, in[v]}};
        auto res = descend(u, par[nxt[v]]);
        res.emplace_back(in[nxt[v]], in[v]);
        return res;
    }

   public:
    heavy_light_decomposition(const std::vector<std::vector<int>> &gh,
                              int root = 0)
        : n(gh.size()),
          g(gh),
          sz(n, 1),
          in(n),
          out(n),
          nxt(n),
          par(n, -1),
          depth(n, 0) {
        dfs_sz(root);
        dfs_hld(root);
    }

    int idx(int u) const { return in[u]; }

    int lca(int u, int v) const {
        while (nxt[u] != nxt[v]) {
            if (in[u] < in[v]) std::swap(u, v);
            u = par[nxt[u]];
        }
        return depth[u] < depth[v] ? u : v;
    }

    int distance(int u, int v) const {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    template <class F>
    void path_noncommutative_query(int u, int v, bool vertex, const F &f) const {
        int l = lca(u, v);
        for (auto [a, b] : ascend(u, l)) f(a + 1, b);
        if(vertex) f(in[l], in[l] + 1);
        for (auto [a, b] : descend(l, v)) f(a, b + 1);
    }

    template <class F>
    void subtree_query(int u, bool vertex, const F &f) {
        f(in[u] + int(!vertex), out[u]);
    }

   private:
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> sz, in, out, nxt, par, depth;
};

}  // namespace ebi