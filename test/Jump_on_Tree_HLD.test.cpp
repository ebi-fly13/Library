#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include <iostream>

#include "../graph/template.hpp"
#include "../tree/heavy_light_decomposition.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::graph g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        g.add_edge(a, b);
    }
    ebi::heavy_light_decomposition hld(g);
    while (q--) {
        int s, t, i;
        std::cin >> s >> t >> i;
        std::cout << hld.jump(s, t, i) << '\n';
    }
}