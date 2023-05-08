#pragma once

#include "../graph/template.hpp"

#include <algorithm>
#include <vector>

namespace ebi {

struct scc_graph {
  private:
    graph g, rg;
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

    graph create_graph() {
        graph t(k);
        for (int i = 0; i < n; i++) {
            int v = cmp[i];
            for (auto to : g[i]) {
                int nv = cmp[to];
                if (v == nv) continue;
                t[v].emplace_back(nv);
            }
        }
        for (int i = 0; i < k; i++) {
            std::sort(t[i].begin(), t[i].end());
            t[i].erase(std::unique(t[i].begin(), t[i].end()), t[i].end());
        }
        return t;
    }
};

}  // namespace ebi