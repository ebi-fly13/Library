#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../data_structure/static_rectangle_sum.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, q;
    std::cin >> n >> q;
    static_rectangle_sum<int, i64> srs;
    rep(i, 0, n) {
        int x, y;
        i64 w;
        std::cin >> x >> y >> w;
        srs.add_point(x, y, w);
    }
    rep(i, 0, q) {
        int l, d, r, u;
        std::cin >> l >> d >> r >> u;
        srs.add_query(l, d, r, u);
    }
    std::cout << srs.run() << '\n';
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