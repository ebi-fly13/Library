#pragma once

#include <algorithm>
#include <utility>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T> struct low_link {
  private:
    void dfs(int v, int par = -1) {
        static int k = 0;
        low[v] = ord[v] = k++;
        int cnt = 0;
        bool is_arti = false, is_second = false;
        for (auto e : g[v]) {
            int nv = e.to;
            if (ord[nv] == -1) {
                cnt++;
                dfs(nv, v);
                low[v] = std::min(low[v], low[nv]);
                is_arti |= (par != -1) && (low[nv] >= ord[v]);
                if (ord[v] < low[nv]) {
                    _bridge.emplace_back(std::minmax(v, nv));
                }
            } else if (nv != par || is_second) {
                low[v] = std::min(low[v], ord[nv]);
            } else {
                is_second = true;
            }
        }
        is_arti |= par == -1 && cnt > 1;
        if (is_arti) _articulation.emplace_back(v);
    }

  public:
    low_link(const Graph<T> &g) : n(g.size()), g(g), ord(n, -1), low(n) {
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) dfs(i);
        }
    }

    std::vector<int> articulation() const {
        return _articulation;
    }

    std::vector<std::pair<int, int>> bridge() const {
        return _bridge;
    }

  protected:
    int n;
    Graph<T> g;
    std::vector<int> ord, low, _articulation;
    std::vector<std::pair<int, int>> _bridge;
};

}  // namespace ebi