#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "../../graph/cycle_detection.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read_graph(m, 0, true);
    auto res = cycle_detection_directed(g);
    if (res) {
        auto [vs, es] = res.value();
        std::cout << es.size() << '\n';
        for (auto e : es) {
            std::cout << e << '\n';
        }
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