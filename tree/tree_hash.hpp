#pragma once

#include <cassert>

#include "../graph/base.hpp"
#include "../tree/centroid.hpp"
#include "../tree/subtree_hash.hpp"

namespace ebi {

template <class T> std::vector<modint61> tree_hash(const Graph<T> &tree) {
    subtree_hash hash(tree);
    auto centroid = get_centroid(tree);
    if (centroid.size() == 1) centroid.emplace_back(centroid[0]);
    assert(centroid.size() == 2);
    std::vector<modint61> hs;
    for (auto c : centroid) {
        hs.emplace_back(hash.get(c));
    }
    if (hs[0] > hs[1]) std::swap(hs[0], hs[1]);
    return hs;
}

}  // namespace ebi