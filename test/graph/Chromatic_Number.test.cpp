#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include "../../graph/chromatic_number.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read_graph(m, 0);
    std::cout << chromatic_number(g) << '\n';
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