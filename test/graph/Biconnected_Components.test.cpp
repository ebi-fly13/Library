#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include <iostream>
#include <vector>

#include "../../graph/base.hpp"
#include "../../tree/block_cut_tree.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    ebi::Graph<int> g(n);
    g.read_graph(m, 0);
    ebi::block_cut_tree bct(g);
    auto bc = bct.bcc();
    int k = bc.size();
    std::cout << k << '\n';
    for (auto vs : bc) {
        std::cout << vs.size();
        for (auto v : vs) {
            std::cout << " " << v;
        }
        std::cout << '\n';
    }
}