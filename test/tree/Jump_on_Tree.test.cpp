#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include <iostream>

#include "../../graph/base.hpp"
#include "../../tree/level_ancestor.hpp"
#include "../../tree/lowest_common_ancestor.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::Graph<int> g(n);
    g.read_tree(0);
    ebi::level_ancestor la(g);
    ebi::lowest_common_ancestor lca(g);
    while (q--) {
        int s, t, i;
        std::cin >> s >> t >> i;
        int d = lca.distance(s, t);
        if (i > d) {
            std::cout << "-1\n";
            continue;
        }
        int m = lca.lca(s, t);
        int ans;
        if (i <= lca.distance(m, s)) {
            ans = la.query(s, i);
        } else {
            i = d - i;
            assert(i <= lca.distance(m, t));
            ans = la.query(t, i);
        }
        std::cout << ans << std::endl;
    }
}