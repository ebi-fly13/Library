#pragma once

#include <vector>

#include "graph/template.hpp"

/*
    reference: https://qiita.com/drken/items/4b4c3f1824339b090202
               https://ferin-tech.hatenablog.com/entry/2020/03/06/162311
*/

namespace ebi {

struct centroid_decomposition {
private:
    int find_centrioid(int _root) {
        auto get_size = [&](auto &&self, int v, int p = -1) -> int {
            sz[v] = 1;
            for(auto nv: g[v]) if(nv != p && !dead[nv]) {
                sz[v] += self(self, nv, v);
            }
            return sz[v];
        };
        get_size(get_size, _root);
        auto dfs_centrioid = [&](auto &&self, int v, int p = -1) -> int {
            for(auto nv: g[v]) if(nv != p && !dead[nv]) {
                if(sz[nv] > sz[_root]/2) return self(self, nv, v);
            }
            return v;
        };
        return dfs_centrioid(dfs_centrioid, _root);
    }
public:
    centroid_decomposition(int _n) : n(_n), g(_n), dead(_n, false), sz(_n, -1), par(_n, -1), belong(_n) { }

    centroid_decomposition(const graph &_g) : n(int(_g.size())), g(_g), dead(n, false), sz(n, -1), par(n, -1), belong(n) { }

    int build(int v = 0, int depth = 0) {
        int c = find_centrioid(v);
        dead[c] = true;
        for(auto nv: g[c]) if(!dead[nv]) {
            int ch = build(nv, depth + 1);
            belong[c].emplace_back(ch);
            par[ch] = c;
        }
        dead[c] = false;
        return root = c;
    }

    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int parent(int v) {
        return par[v];
    }
private:
    int n;
    int root;
    graph g;
    std::vector<bool> dead;
    std::vector<int> sz;
    std::vector<int> par;
    std::vector<std::vector<int>> belong;
};

}