#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"

#include "../../graph/cycle_detection.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read_graph(m, 0);
    auto res = cycle_detection_undirected(g);
    if (res) {
        auto [vs, es] = res.value();
        std::cout << vs.size() << '\n';
        std::cout << vs << '\n';
        std::cout << es << '\n';
    } else {
        std::cout << "-1\n";
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