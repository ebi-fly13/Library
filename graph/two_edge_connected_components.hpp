#pragma once

#include "../graph/low_link.hpp"

namespace ebi {

template <class T> struct two_edge_connected_components : low_link<T> {
  private:
    void dfs(int v, int par = -1) {
        if (par != -1 && this->ord[par] >= this->low[v])
            _id[v] = _id[par];
        else
            _id[v] = k++;
        for (auto e : this->g[v]) {
            if (_id[e.to] == -1) dfs(e.to, v);
        }
    }

  public:
    two_edge_connected_components(const Graph<T> &_g)
        : low_link<T>(_g), _id(this->n, -1) {
        for (int i = 0; i < this->n; i++) {
            if (_id[i] == -1) dfs(i);
        }
    }

    Graph<int> tecc() const {
        Graph<int> t(k);
        for (auto [u, v] : this->_bridge) {
            u = _id[u];
            v = _id[v];
            t.add_edge(u, v, 1);
            t.add_edge(v, u, 1);
        }
        t.build();
        return t;
    }

    std::vector<std::vector<int>> groups() const {
        std::vector _groups(k, std::vector<int>());
        for (int i = 0; i < this->n; i++) {
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
};

}  // namespace ebi