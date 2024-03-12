#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../graph/low_link.hpp"
#include "../../graph/base.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    ebi::Graph<int> g(n);
    g.read_graph(m, 0);
    ebi::low_link low(g);
    auto arti = low.articulation();
    std::sort(arti.begin(), arti.end());
    for (auto v : arti) {
        std::cout << v << '\n';
    }
}