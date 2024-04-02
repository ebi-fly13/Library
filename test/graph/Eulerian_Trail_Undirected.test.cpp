#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_undirected"

#include "../../graph/euler_trail.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read_graph(m, 0);
    auto res = euler_trail_undirected(g);
    if (res) {
        auto [vs, es] = res.value();
        std::cout << "Yes\n";
        std::cout << vs << '\n';
        std::cout << es << '\n';
    } else {
        std::cout << "No\n";
    }
}

}  // namespace ebi

int main() {
    ebi::fast_io();
    int t = 1;
    std::cin >> t;
    while (t--) {
        ebi::main_();
    }
    return 0;
}