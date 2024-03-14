#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"

#include "../../graph/directed_mst.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m, s;
    std::cin >> n >> m >> s;
    Graph<i64> g(n);
    g.read_graph(m, 0, true, true);
    auto res = directed_mst(s, g);
    if (res) {
        auto [x, p] = res.value();
        std::cout << x << '\n';
        std::cout << p << '\n';
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