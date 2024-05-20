#define PROBLEM \
    "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"

#include "../../convolution/convolution.hpp"
#include "../../fps/shift_of_sampling_points_of_poly.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, m, c;
    std::cin >> n >> m >> c;
    std::vector<mint> f(n);
    std::cin >> f;
    std::cout << shift_of_sampling_points_of_poly<mint, convolution>(f, c, m)
              << '\n';
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