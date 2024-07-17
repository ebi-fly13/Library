#pragma once

#include "../graph/base.hpp"
#include "../matrix/base.hpp"
#include "../matrix/gauss_jordan.hpp"
#include "../modint/modint61.hpp"
#include "../utility/random_number_generator.hpp"

namespace ebi {

template <class T> int maximum_matching_size(const Graph<T> &g) {
    static random_number_generator rng;
    using mint = modint61;
    int n = g.node_number();
    matrix<mint> tutte(n, n, 0);
    for (auto e : g.get_edges()) {
        mint x = rng.get<std::uint64_t>(0, mint::mod());
        tutte[e.from][e.to] += x;
        tutte[e.to][e.from] -= x;
    }
    return tutte.rank() / 2;
}

}  // namespace ebi