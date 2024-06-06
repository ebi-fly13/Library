#define PROBLEM \
    "https://judge.yosupo.jp/problem/counting_spanning_tree_directed"

#include "../../graph/count_spanning_tree.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, m, r;
    std::cin >> n >> m >> r;
    Graph<int> g(n);
    g.read_graph(m, 0, true);
    std::cout << count_directed_spanning_tree<mint>(g, r) << '\n';
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