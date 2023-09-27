#pragma once

#include <algorithm>
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
        in[v] = t++;
        rev[in[v]] = v;
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
          depth(n, 0),
          rev(n) {
        dfs_sz(root);
        dfs_hld(root);
    }

    int idx(int u) const {
        return in[u];
    }

    int rev_idx(int i) const {
        return rev[i];
    }

    int la(int v, int k) const {
        while (1) {
            int u = nxt[v];
            if (in[u] <= in[v] - k) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }

    int lca(int u, int v) const {
        while (nxt[u] != nxt[v]) {
            if (in[u] < in[v]) std::swap(u, v);
            u = par[nxt[u]];
        }
        return depth[u] < depth[v] ? u : v;
    }

    int jump(int s, int t, int i) const {
        if (i == 0) return s;
        int l = lca(s, t);
        int d = depth[s] + depth[t] - depth[l] * 2;
        if (d < i) return -1;
        if (depth[s] - depth[l] >= i) return la(s, i);
        i = d - i;
        return la(t, i);
    }

    std::vector<int> path(int s, int t) const {
        int l = lca(s, t);
        std::vector<int> a, b;
        for (; s != l; s = par[s]) a.emplace_back(s);
        for (; t != l; t = par[t]) b.emplace_back(t);
        a.emplace_back(l);
        std::reverse(b.begin(), b.end());
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }

    int distance(int u, int v) const {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    int distance_from_root(int v) const {
        return depth[v];
    }

    bool at_path(int u, int v, int s) const {
        return distance(u, v) == distance(u, s) + distance(s, v);
    }

    template <class F>
    void path_noncommutative_query(int u, int v, bool vertex,
                                   const F &f) const {
        int l = lca(u, v);
        for (auto [a, b] : ascend(u, l)) f(a + 1, b);
        if (vertex) f(in[l], in[l] + 1);
        for (auto [a, b] : descend(l, v)) f(a, b + 1);
    }

    std::vector<std::pair<int, int>> path_sections(int u, int v,
                                                   bool vertex) const {
        int l = lca(u, v);
        std::vector<std::pair<int, int>> sections;
        for (auto [a, b] : ascend(u, l)) sections.emplace_back(a + 1, b);
        if (vertex) sections.emplace_back(in[l], in[l] + 1);
        for (auto [a, b] : descend(l, v)) sections.emplace_back(a, b + 1);
        return sections;
    }

    template <class S, class F, class Op, class DS>
    int max_path(int u, int v, bool vertex, S e, F f, Op op, DS &ds) const {
        if (!f(ds.get(in[u]))) return -1;
        int l = lca(u, v);
        S now = e;
        auto check = [&](S x) -> bool { return f(op(now, x)); };
        for (auto [a, b] : ascend(u, l)) {
            a++;
            S ret = ds.prod(b, a);
            if (check(ret)) {
                u = rev[b];
                now = op(now, ret);
            } else {
                int m = ds.min_left(a, check);
                return (m == a ? u : rev[m]);
            }
        }
        if (vertex) {
            S ret = ds.get(in[l]);
            if (check(ret)) {
                u = l;
                now = op(now, ret);
            } else {
                return u;
            }
        }
        for (auto [a, b] : descend(l, v)) {
            b++;
            S ret = ds.prod(a, b);
            if (check(ret)) {
                u = rev[b - 1];
                now = op(now, ret);
            } else {
                int m = ds.max_right(a, check);
                return a == m ? u : rev[m - 1];
            }
        }
        return v;
    }

    template <class F> void subtree_query(int u, bool vertex, const F &f) {
        f(in[u] + int(!vertex), out[u]);
    }

  private:
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> sz, in, out, nxt, par, depth, rev;

    int t = 0;
};

}  // namespace ebi