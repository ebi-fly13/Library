#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../graph/dijkstra_fibheap.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m, r;
    std::cin >> n >> m >> r;
    ebi::Graph<i64> g(n);
    g.read_graph(m, 0, true, true);
    auto dist = dijkstra_fibheap(r, n, g);
    for (int i = 0; i < n; i++) {
        if (dist[i] == std::numeric_limits<i64>::max()) {
            std::cout << "INF" << std::endl;
            continue;
        }
        std::cout << dist[i] << std::endl;
    }
}

}  // namespace ebi

int main() {
    ebi::fast_io();
    int t = 1;
    // std::cin >> t;
    while (t--) {
        ebi::main_();
    }
    return 0;
}