#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../data_structure/range_parallel_dsu.hpp"

#include "../../data_structure/dsu.hpp"
#include "../../template/template.hpp"
#include "../../utility/random_number_generator.hpp"

namespace ebi {

void main_() {
    random_number_generator rng;
    int n = rng.get(1, 5000);
    int q = rng.get(1, 5000);
    range_parallel_dsu rpd(n);
    dsu uf(n);
    rep(i, 0, q) {
        int u = rng.get(0, n);
        int v = rng.get(0, n);
        int w = rng.get(0, n);
        rpd.merge(u, v, w);
        for (int i = 0; i < w; i++) {
            if (u + i >= n || v + i >= n) break;
            uf.merge(u + i, v + i);
        }
    }
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            assert(rpd.same(i, j) == uf.same(i, j));
        }
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
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}