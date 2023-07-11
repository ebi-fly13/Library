#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../graph/two_edge_connected_components.hpp"

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
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