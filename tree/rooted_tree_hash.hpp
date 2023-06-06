#pragma once

#include <vector>

#include "../utility/hash.hpp"

namespace ebi {

template <int BASE_NUM> struct rooted_tree_hash {
  private:
    using H = Hash<BASE_NUM>;

    static H get_basis(int d) {
        if (int(_basis.size()) <= d) _basis.emplace_back(H::get_basis());
        return _basis[d];
    }

  public:
    rooted_tree_hash() = default;

    static std::vector<H> subtree_hash(const std::vector<std::vector<int>> &g,
                                       int root = 0) {
        int n = g.size();
        std::vector<H> hash(n, H::set(1));
        std::vector<int> depth(n, 0);
        auto dfs = [&](auto &&self, int v, int par = -1) -> void {
            for (auto nv : g[v]) {
                if (nv == par) continue;
                self(self, nv, v);
                depth[v] = std::max(depth[v], depth[nv] + 1);
            }
            for (auto nv : g[v]) {
                if (nv == par) continue;
                hash[v] *= hash[nv];
            }
            if (hash[v] == H::set(1)) hash[v] = H::set(0);
            hash[v] += get_basis(depth[v]);
            return;
        };
        dfs(dfs, root);
        return hash;
    }

    static std::vector<H> basis() {
        return _basis;
    }

  private:
    static std::vector<H> _basis;
};

template <int BASE_NUM>
std::vector<Hash<BASE_NUM>> rooted_tree_hash<BASE_NUM>::_basis = {};

}  // namespace ebi