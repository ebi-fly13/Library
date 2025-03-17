#pragma once

#include <vector>

#include "../graph/base.hpp"
#include "../modint/modint61.hpp"
#include "../tree/rerooting.hpp"
#include "../utility/random_number_generator.hpp"

namespace ebi {

template <class T> struct subtree_hash {
  private:
    using V = std::pair<int, modint61>;

    static modint61 hash_base(int k) {
        static std::vector<modint61> r;
        static random_number_generator rng;
        while ((int)r.size() <= k) {
            r.emplace_back(rng.get<std::uint64_t>(0, modint61::mod()));
        }
        return r[k];
    }

    static auto merge() {
        return [&](V a, V b) -> V {
            return {std::max(a.first, b.first), a.second * b.second};
        };
    }

    static auto put_edge() {
        return [&](Graph<T>::edge_type, V a) -> V {
            return {a.first + 1, a.second};
        };
    }

    static auto put_root() {
        return [&](int, V a) -> V {
            return {a.first, a.second + hash_base(a.first)};
        };
    }

  public:
    subtree_hash(const Graph<T> &tree)
        : dp(tree, V{0, 1}, merge(), put_edge(), put_root()) {}

    modint61 get(int v) const {
        return dp.get(v).second;
    }

    modint61 get(int v, int root) {
        return dp.get(v, root).second;
    }

  private:
    rerooting_dp<T, V> dp;
};

}  // namespace ebi