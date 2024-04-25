#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "../../data_structure/area_of_union_of_rectangles.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    area_of_union_of_rectangles solver;
    rep(i, 0, n) {
        i64 l, d, r, u;
        std::cin >> l >> d >> r >> u;
        solver.add_rectangle(l, d, r, u);
    }
    std::cout << solver.run() << '\n';
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