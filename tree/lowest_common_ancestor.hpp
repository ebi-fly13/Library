#pragma once

#include <vector>

#include "../data_structure/sparse_table.hpp"
#include "../graph/base.hpp"

namespace ebi {

namespace internal_lca {
std::pair<int, int> op(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second ? a : b;
}
}  // namespace internal_lca

template <class T> struct lowest_common_ancestor {
  public:
    lowest_common_ancestor(const Graph<T> &gh, int root = 0)
        : n(gh.size()), id(n), dist(n, 0) {
        auto dfs = [&](auto &&self, int v, int par = -1, T d = 0) -> void {
            id[v] = int(vs.size());
            vs.emplace_back(v, d);
            for (const auto &e : gh[v])
                if (e.to != par) {
                    dist[e.to] = dist[v] + e.cost;
                    self(self, e.to, v, d + 1);
                    vs.emplace_back(v, d);
                }
        };
        dfs(dfs, root);
        st.build(vs);
    }

    int lca(int u, int v) {
        int l = id[u], r = id[v];
        if (r < l) std::swap(l, r);
        return st.fold(l, r + 1).first;
    }

    T distance(int u, int v) {
        int w = lca(u, v);
        return dist[u] + dist[v] - 2 * dist[w];
    }

  private:
    int n;
    std::vector<int> id;
    std::vector<T> dist;
    std::vector<std::pair<int, int>> vs;
    sparse_table<std::pair<int, int>, internal_lca::op> st;
};

}  // namespace ebi