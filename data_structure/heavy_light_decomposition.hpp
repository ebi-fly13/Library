#pragma once

#include "../data_structure/Segtree.hpp"
#include "../graph/template.hpp"

#include <vector>

namespace ebi {

template<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
struct heavy_light_decomposition {
private:
    int n, t = 0;
    std::vector<int> sz, in, out, nxt, up;
    graph g;
    Segtree<Monoid, op, e> seg;

    void dfs_sz(int v = 0) {
        sz[v] = 1;
        for(auto &u : g[v]) if(u != up[v]) {
            up[u] = v;
            dfs_sz(u);
            sz[v] += sz[u];
            if(sz[u] > sz[g[v][0]]) std::swap(g[v][0], u);
        }
    }

    void dfs_hld(int v = 0) {
        in[v] = t++;
        for(const auto &u: g[v]) if(u != up[v]) {
            nxt[u] = (u == g[v][0]) ? nxt[v] : u;
            sz[u] = (u == g[v][0]) ? sz[v] : sz[v]+1;
            dfs_hld(u);
        }
        out[v] = t;
    }
public:
    heavy_light_decomposition(int _n) : n(_n), sz(_n, 0), in(_n, 0), out(_n, 0), nxt(_n, 0), up(_n, -1), g(_n), seg(_n) { }

    void add_edge(int v, int u) {
        g[v].emplace_back(u);
        g[u].emplace_back(v);
    }

    void build(int root = 0) {
        dfs_sz(root);
        sz.assign(n, 0);
        dfs_hld(root);
    }

    int lca(int u, int v) {
        while(nxt[u] != nxt[v]) {
            if(sz[u] > sz[v]) {
                u = up[nxt[u]];
            }
            else {
                v = up[nxt[v]];
            }
        }
        return (in[u] < in[v]) ? u : v;
    }

    void set(const std::vector<Monoid> &a) {
        for(int i = 0; i < n; ++i) {
            seg.set(in[i], a[i]);
        }
    }

    void set(int i, Monoid x) {
        seg.set(in[i], x);
    }

    Monoid get(int i) {
        return seg.get(in[i]);
    }

    Monoid path_prod(int u, int v) {
        Monoid sum_l = e(), sum_r = e();
        while(nxt[u] != nxt[v]) {
            if(sz[u] > sz[v]) {
                sum_l = op(sum_l, seg.prod(in[nxt[u]], in[u]+1));
                u = up[nxt[u]];
            }
            else {
                sum_r = op(seg.prod(in[nxt[v]], in[v]+1), sum_r);
                v = up[nxt[v]];
            }
        }
        if(in[u] < in[v]) {
            sum_r = op(seg.prod(in[u], in[v]+1), sum_r);
        }
        else {
            sum_l = op(sum_l, seg.prod(in[v], in[u]+1));
        }
        return op(sum_l, sum_r);
    }
};

}
