#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T> struct heavy_light_decomposition {
  private:
    void dfs_sz(int v, Graph<T> &g) {
        for (auto &e : g[v]) {
            if (e.to == par[v]) continue;
            par[e.to] = v;
            depth_[e.to] = depth_[v] + 1;
            dist[e.to] = dist[v] + e.cost;
            dfs_sz(e.to, g);
            sz[v] += sz[e.to];
            if (sz[e.to] > sz[g[v][0].to] || g[v][0].to == par[v])
                std::swap(e, g[v][0]);
        }
    }

    void dfs_hld(int v, const Graph<T> &g) {
        in[v] = num++;
        rev[in[v]] = v;
        for (auto e : g[v]) {
            if (e.to == par[v]) continue;
            nxt[e.to] = (e.to == g[v][0].to ? nxt[v] : e.to);
            dfs_hld(e.to, g);
        }
        out[v] = num;
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
    heavy_light_decomposition(Graph<T> gh, int root = 0)
        : n(gh.size()),
          sz(n, 1),
          in(n),
          out(n),
          nxt(n),
          par(n, -1),
          depth_(n, 0),
          rev(n),
          dist(n, 0) {
        nxt[root] = root;
        dfs_sz(root, gh);
        dfs_hld(root, gh);
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
        return depth_[u] < depth_[v] ? u : v;
    }

    int jump(int s, int t, int i) const {
        if (i == 0) return s;
        int l = lca(s, t);
        int d = depth_[s] + depth_[t] - depth_[l] * 2;
        if (d < i) return -1;
        if (depth_[s] - depth_[l] >= i) return la(s, i);
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

    int root_of_heavy_path(int u) const {
        return nxt[u];
    }

    int parent(int u) const {
        return par[u];
    }

    T distance(int u, int v) const {
        return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }

    T distance_from_root(int v) const {
        return dist[v];
    }

    T depth(int v) const {
        return depth_[v];
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

    template <class F>
    int max_path(int u, int v, bool vertex, F binary_search) const {
        int prev = -1;
        int l = lca(u, v);
        for (auto [a, b] : ascend(u, l)) {
            a++;
            int m = binary_search(a, b);
            if (m == b) {
                prev = rev[b];
            } else {
                return (m == a ? prev : rev[m]);
            }
        }
        if (vertex) {
            int m = binary_search(in[l], in[l] + 1);
            if (m == in[l]) {
                return prev;
            } else {
                prev = l;
            }
        }
        for (auto [a, b] : descend(l, v)) {
            b++;
            int m = binary_search(a, b);
            if (m == b) {
                prev = rev[b - 1];
            } else {
                return m == a ? prev : rev[m - 1];
            }
        }
        return v;
    }

    template <class F> void subtree_query(int u, bool vertex, const F &f) {
        f(in[u] + int(!vertex), out[u]);
    }

    const std::vector<int> &dfs_order() const {
        return rev;
    }

    std::vector<std::pair<int, int>> lca_based_auxiliary_tree_dfs_order(
        std::vector<int> vs) const;

    std::pair<std::vector<int>, Graph<T>> lca_based_auxiliary_tree(
        std::vector<int> vs) const;

  private:
    int n;
    std::vector<int> sz, in, out, nxt, par, depth_, rev;
    std::vector<T> dist;

    int num = 0;
};

}  // namespace ebi
