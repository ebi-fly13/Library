#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_setad"

#include "../../graph/maximum_independent_set.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read_graph(m, 0);
    auto p = maximum_independent_set(g);
    std::cout << p.size() << '\n';
    std::cout << p << '\n';
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