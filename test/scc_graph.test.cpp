#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../graph/scc_graph.hpp"

#include <iostream>

#include "../graph/template.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    ebi::scc_graph g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        g.add_edge(a, b);
    }
    auto scc = g.scc();
    int sz = scc.size();
    std::cout << sz << '\n';
    for (int i = 0; i < sz; ++i) {
        std::cout << scc[i].size();
        for (auto v : scc[i]) {
            std::cout << " " << v;
        }
        std::cout << '\n';
    }
}