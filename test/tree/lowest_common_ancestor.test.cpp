#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../tree/lowest_common_ancestor.hpp"

#include <iostream>

#include "../../graph/base.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::Graph<int> g(n);
    g.read_parents(0);
    ebi::lowest_common_ancestor lca(g);
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << lca.lca(u, v) << '\n';
    }
}