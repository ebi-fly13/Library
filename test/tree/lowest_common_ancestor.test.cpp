#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../tree/lowest_common_ancestor.hpp"

#include <iostream>

#include "../../graph/template.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::graph g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        g.add_edge(p, i);
    }
    ebi::lowest_common_ancestor lca(g);
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << lca.lca(u, v) << '\n';
    }
}