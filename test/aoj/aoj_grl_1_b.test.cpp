#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include "../../graph/bellman_ford.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int v, e, r;
    std::cin >> v >> e >> r;
    Graph<i64> g(v);
    g.read_graph(e, 0, true);
    auto d = bellman_ford(r, g);
    if (d.empty()) {
        std::cout << "NEGATIVE CYCLE\n";
    } else {
        for (auto c : d) {
            if (c == std::numeric_limits<i64>::max()) {
                std::cout << "INF\n";
            } else {
                std::cout << c << '\n';
            }
        }
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