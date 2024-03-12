#pragma once

#include <vector>

#include "../graph/base.hpp"
#include "../utility/hash.hpp"

namespace ebi {

template <int BASE_NUM = 2> struct rooted_tree_hash {
  private:
    using H = Hash<BASE_NUM>;

    static H get_basis(int d) {
        if (int(_basis.size()) <= d) _basis.emplace_back(H::get_basis());
        return _basis[d];
    }

  public:
    rooted_tree_hash() = default;

    template <class T>
    static std::vector<H> subtree_hash(const Graph<T> &g, int root = 0) {
        int n = g.size();
        std::vector<H> hash(n, H::set(1));
        std::vector<int> depth(n, 0);
        auto dfs = [&](auto &&self, int v, int par = -1) -> void {
            for (auto e : g[v]) {
                if (e.to == par) continue;
                self(self, e.to, v);
                depth[v] = std::max(depth[v], depth[e.to] + 1);
            }
            for (auto e : g[v]) {
                if (e.to == par) continue;
                hash[v] *= hash[e.to];
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