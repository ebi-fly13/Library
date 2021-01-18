#pragma once

#include "../graph/template.hpp"

#include <vector>
#include <algorithm>

namespace ebi {

struct scc_graph {
private:
    graph g,rg;
    int n,k;

    std::vector<int> vs, cmp;
    std::vector<bool> seen;

    void dfs(int v) {
        seen[v] = true;
        for(auto &nv: g[v]) {
            if(!seen[nv]) dfs(nv);
        }
        vs.emplace_back(v);
    }

    void rdfs(int v) {
        cmp[v] = k;
        for(auto nv: rg[v]) {
            if(cmp[nv]<0) {
                rdfs(nv);
            }
        }
    }


public:
    scc_graph(int n) : n(n) {
        g.resize(n);
        rg.resize(n);
    }

    void add_edge(int from, int to) {
        g[from].emplace_back(to);
        rg[to].emplace_back(from);
    }

    std::vector<std::vector<int>> scc() {
        seen.assign(n, false);
        for(int i = 0; i<n; i++) {
            if(!seen[i]) {
                dfs(i);
            }
        }
        std::reverse(vs.begin(), vs.end());
        cmp.assign(n, -1);
        k = 0;
        for(auto &v: vs) {
            if(cmp[v]<0) {
                rdfs(v);
                k++;
            }
        }
        std::vector<std::vector<int>> res(k);
        for(int i = 0; i<n; i++) {
            res[cmp[i]].emplace_back(i);
        }
        return res;
    }

    bool same(int u, int v) {
        return cmp[u]==cmp[v];
    }
};

} // namespace ebi