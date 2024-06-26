#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include "../../graph/base.hpp"
#include "../../graph/mst.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m;
    std::cin >> n >> m;
    Graph<i64> g(n);
    g.read_graph(m, 0, false, true);
    auto [x, e] = mst(g);
    std::cout << x << '\n';
    std::cout << e << '\n';
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