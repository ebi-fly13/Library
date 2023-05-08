#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../graph/dijkstra.hpp"

#include <iostream>
#include <limits>
#include <vector>

#include "../graph/template.hpp"
#include "../utility/int_alias.hpp"

int main() {
    int v, e, r;
    std::cin >> v >> e >> r;
    ebi::Graph<i64> g(v);
    while (e--) {
        int s, t;
        i64 d;
        std::cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }
    std::vector<i64> dest = ebi::dijkstra(r, v, g);
    for (auto di : dest) {
        if (di == std::numeric_limits<i64>::max()) {
            std::cout << "INF" << std::endl;
            continue;
        }
        std::cout << di << std::endl;
    }
}