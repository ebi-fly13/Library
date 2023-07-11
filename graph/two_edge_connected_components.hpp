#pragma once

#include "../graph/low_link.hpp"

namespace ebi {

struct two_edge_connected_components : low_link {
  private:
    void dfs(int v, int par = -1) {
        if (par != -1 && this->ord[par] >= this->low[v])
            _id[v] = _id[par];
        else
            _id[v] = k++;
        for (auto nv : this->g[v]) {
            if (_id[nv] == -1) dfs(nv, v);
        }
    }

  public:
    two_edge_connected_components(const std::vector<std::vector<int>> &_g)
        : low_link(_g), _id(this->n, -1) {
        for (int i = 0; i < this->n; i++) {
            if (_id[i] == -1) dfs(i);
        }
        t.resize(k);
        for (auto [u, v] : this->_bridge) {
            u = _id[u];
            v = _id[v];
            t[u].emplace_back(v);
            t[v].emplace_back(u);
        }
    }

    std::vector<std::vector<int>> tecc() const {
        return t;
    }

    std::vector<std::vector<int>> groups() const {
        std::vector _groups(k, std::vector<int>());
        for (int i = 0; i < n; i++) {
            _groups[_id[i]].emplace_back(i);
        }
        return _groups;
    }

    int id(int v) const {
        return _id[v];
    }

  private:
    int k = 0;
    std::vector<int> _id;
    std::vector<std::vector<int>> t;
};

}  // namespace ebi