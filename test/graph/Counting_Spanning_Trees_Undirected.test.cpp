#define PROBLEM \
    "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"

#include "../../graph/count_spanning_tree.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read_graph(m, 0);
    std::cout << count_spanning_tree<mint>(g) << '\n';
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