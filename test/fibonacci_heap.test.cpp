#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>

#include "../graph/dijkstra_fibheap.hpp"
#include "../graph/template.hpp"
#include "../utility/int_alias.hpp"

int main() {
    int n, m, r;
    std::cin >> n >> m >> r;
    ebi::Graph<i64> g(n);
    while (m--) {
        int s, t;
        i64 d;
        std::cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }
    auto dist = ebi::dijkstra(r, n, g);
    for (int i = 0; i < n; i++) {
        if (dist[i] == std::numeric_limits<i64>::max()) {
            std::cout << "INF" << std::endl;
            continue;
        }
        std::cout << dist[i] << std::endl;
    }
}