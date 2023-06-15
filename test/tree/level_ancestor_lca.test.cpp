#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>

#include "../../graph/template.hpp"
#include "../../tree/level_ancestor.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::graph g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        g.add_edge(p, i);
    }
    ebi::level_ancestor la(g);
    auto lca = [&](int u, int v) -> int {
        if (la.depth(u) > la.depth(v)) std::swap(u, v);
        v = la.query(v, la.depth(v) - la.depth(u));
        int ng = -1, ok = la.depth(u);
        while (std::abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (la.query(u, mid) == la.query(v, mid))
                ok = mid;
            else
                ng = mid;
        }
        return la.query(u, ok);
    };
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << lca(u, v) << '\n';
    }
}