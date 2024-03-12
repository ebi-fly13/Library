#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include <iostream>

#include "../../graph/base.hpp"
#include "../../tree/heavy_light_decomposition.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::Graph<int> g(n);
    g.read_tree(0);
    ebi::heavy_light_decomposition hld(g);
    while (q--) {
        int s, t, i;
        std::cin >> s >> t >> i;
        std::cout << hld.jump(s, t, i) << '\n';
    }
}