#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"

#include "../../data_structure/range_parallel_dsu.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, q;
    std::cin >> n >> q;
    std::vector<mint> x(n);
    std::cin >> x;
    range_parallel_dsu uf(n);
    mint ans = 0;
    while (q--) {
        int k, a, b;
        std::cin >> k >> a >> b;
        uf.merge(a, b, k, [&](int i, int j) -> void {
            ans += x[i] * x[j];
            x[i] += x[j];
        });
        std::cout << ans << '\n';
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