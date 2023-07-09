#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../graph/low_link.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    ebi::low_link low(g);
    auto arti = low.articulation();
    std::sort(arti.begin(), arti.end());
    for (auto v : arti) {
        std::cout << v << '\n';
    }
}