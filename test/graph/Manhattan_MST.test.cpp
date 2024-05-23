#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"

#include "../../graph/manhattan_mst.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    std::vector<i64> xs(n), ys(n);
    rep(i, 0, n) {
        std::cin >> xs[i] >> ys[i];
    }
    auto [x, es] = manhattan_mst(xs, ys);
    std::cout << x << '\n';
    for (auto [i, j] : es) {
        std::cout << i << " " << j << '\n';
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