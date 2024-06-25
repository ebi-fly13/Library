#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"

#include "../../matrix/black_box_linear_algebra.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::tuple<int, int, mint>> a(k);
    for (auto &[i, j, c] : a) {
        std::cin >> i >> j >> c;
    }
    auto Ax = [&](const std::vector<mint> &v) -> std::vector<mint> {
        std::vector<mint> res(n, 0);
        for (auto [i, j, c] : a) {
            res[i] += c * v[j];
        }
        return res;
    };
    std::cout << det<mint>(n, Ax) << '\n';
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