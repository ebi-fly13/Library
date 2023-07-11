#pragma once

#include "../graph/low_link.hpp"

namespace ebi {

struct two_edge_connected_components : low_link {
  private:
    void dfs(int v, int par = -1) {
        if (par != -1 && this->ord[par] >= this->low[v])
            id[v] = id[par];
        else
            id[v] = k++;
        for (auto nv : this->g[v]) {
            if (id[nv] == -1) dfs(nv, v);
        }
    }

  public:
    two_edge_connected_components(const std::vector<std::vector<int>> &_g)
        : low_link(_g), id(this->n, -1) {
        for (int i = 0; i < this->n; i++) {
            if (id[i] == -1) dfs(i);
        }
        t.resize(k);
        for (auto [u, v] : this->_bridge) {
            u = id[u];
            v = id[v];
            t[u].emplace_back(v);
            t[v].emplace_back(u);
        }
    }

    std::vector<std::vector<int>> groups() const {
        std::vector _groups(k, std::vector<int>());
        for (int i = 0; i < n; i++) {
            _groups[id[i]].emplace_back(i);
        }
        return _groups;
    }

  private:
    int k = 0;
    std::vector<int> id;
    std::vector<std::vector<int>> t;
};

}  // namespace ebi