#pragma once

#include <vector>

#include "../data_structure/sparse_table.hpp"
#include "../graph/template.hpp"

namespace ebi {

namespace internal_lca {
    std::pair<int,int> op(std::pair<int,int> a, std::pair<int,int> b) {
        return a.second < b.second ? a : b;
    }
}

struct lowest_common_ancestor {
public:
    lowest_common_ancestor(int _n) : n(_n), id(_n), depth(_n), g(_n) { }

    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    void build(int root = 0) {
        auto dfs = [&](auto &&self, int v, int par = -1, int d = 0) -> void {
            id[v] = int(vs.size());
            depth[v] = d;
            vs.emplace_back(v, d);
            for(const auto &nv: g[v]) if(nv != par) {
                self(self, nv, v, d+1);
                vs.emplace_back(v, d);
            }
        };
        dfs(dfs, root);
        st.build(vs);
    }

    int lca(int u, int v) {
        int l = id[u], r = id[v];
        if(r < l) std::swap(l, r);
        return st.fold(l, r+1).first;
    }

    int distance(int u, int v) {
        int w = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }

private:
    int n;
    std::vector<int> id, depth;
    std::vector<std::pair<int,int>> vs;
    graph g;
    sparse_table<std::pair<int,int>, internal_lca::op> st;
};

}