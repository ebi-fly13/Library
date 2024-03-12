#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../graph/two_edge_connected_components.hpp"

#include <iostream>
#include <vector>

#include "../../graph/base.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    ebi::Graph<int> g(n);
    g.read_graph(m, 0);
    ebi::two_edge_connected_components tecc(g);
    auto groups = tecc.groups();
    std::cout << groups.size() << '\n';
    for (auto group : groups) {
        std::cout << group.size();
        for (auto v : group) {
            std::cout << " " << v;
        }
        std::cout << '\n';
    }
}