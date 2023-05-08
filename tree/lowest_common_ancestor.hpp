#pragma once

#include <vector>

#include "../data_structure/sparse_table.hpp"

namespace ebi {

namespace internal_lca {
std::pair<int, int> op(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second ? a : b;
}
}  // namespace internal_lca

struct lowest_common_ancestor {
  public:
    lowest_common_ancestor(const std::vector<std::vector<int>> &gh,
                           int root = 0)
        : n(gh.size()), id(n), depth(n) {
        auto dfs = [&](auto &&self, int v, int par = -1, int d = 0) -> void {
            id[v] = int(vs.size());
            depth[v] = d;
            vs.emplace_back(v, d);
            for (const auto &nv : gh[v])
                if (nv != par) {
                    self(self, nv, v, d + 1);
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

    int distance(int u, int v) {
        int w = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }

  private:
    int n;
    std::vector<int> id, depth;
    std::vector<std::pair<int, int>> vs;
    sparse_table<std::pair<int, int>, internal_lca::op> st;
};

}  // namespace ebi