#pragma once

#include <algorithm>
#include <vector>

#include "../data_structure/simple_csr.hpp"
#include "../graph/base.hpp"

namespace ebi {

struct scc_graph {
  private:
    std::vector<std::pair<int, int>> edges, redges;
    simple_csr<int> g, rg;
    int n, k;

    std::vector<int> vs, cmp;
    std::vector<bool> seen;

    void dfs(int v) {
        seen[v] = true;
        for (auto &nv : g[v]) {
            if (!seen[nv]) dfs(nv);
        }
        vs.emplace_back(v);
    }

    void rdfs(int v) {
        cmp[v] = k;
        for (auto nv : rg[v]) {
            if (cmp[nv] < 0) {
                rdfs(nv);
            }
        }
    }

  public:
    scc_graph(int n_) : n(n_) {}

    void add_edge(int from, int to) {
        edges.emplace_back(from, to);
        redges.emplace_back(to, from);
    }

    std::vector<std::vector<int>> scc() {
        g = simple_csr<int>(n, edges);
        rg = simple_csr<int>(n, redges);
        edges.clear();
        redges.clear();
        seen.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                dfs(i);
            }
        }
        std::reverse(vs.begin(), vs.end());
        cmp.assign(n, -1);
        k = 0;
        for (auto &v : vs) {
            if (cmp[v] < 0) {
                rdfs(v);
                k++;
            }
        }
        std::vector<std::vector<int>> res(k);
        for (int i = 0; i < n; i++) {
            res[cmp[i]].emplace_back(i);
        }
        return res;
    }

    std::vector<int> scc_id() {
        return cmp;
    }

    bool same(int u, int v) {
        return cmp[u] == cmp[v];
    }

    Graph<int> create_graph() {
        std::vector<std::pair<int, int>> es;
        for (int i = 0; i < n; i++) {
            int v = cmp[i];
            for (auto to : g[i]) {
                int nv = cmp[to];
                if (v == nv) continue;
                es.emplace_back(v, nv);
            }
        }
        std::sort(es.begin(), es.end());
        es.erase(std::unique(es.begin(), es.end()), es.end());
        Graph<int> t(k);
        for (auto [v, nv] : es) {
            t.add_edge(v, nv, 1);
        }
        t.build();
        return t;
    }
};

}  // namespace ebi