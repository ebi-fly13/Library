#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../graph/base.hpp"
#include "../../graph/dijkstra.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    Graph<i64> g(n);
    g.read_graph(m, 0, true, true);
    dijkstra_path d(s, g);
    auto [x, path] = d.shortest_path(t);
    if (x == std::numeric_limits<i64>::max()) {
        std::cout << "-1\n";
        return;
    }
    int y = (int)path.size() - 1;
    std::cout << x << " " << y << '\n';
    rep(i, 0, y) {
        std::cout << path[i] << " " << path[i + 1] << '\n';
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