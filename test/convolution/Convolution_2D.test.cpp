#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../convolution/convolution_2d.hpp"

#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
#include "../../utility/random_number_generator.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    random_number_generator rng;
    int h1 = rng.get(30, 60);
    int w1 = rng.get(30, 60);
    int h2 = rng.get(30, 60);
    int w2 = rng.get(30, 60);
    std::vector a(h1, std::vector<mint>(w1));
    std::vector b(h2, std::vector<mint>(w2));
    rep(i, 0, h1) rep(j, 0, w1) {
        a[i][j] = rng.get(0, mint::mod());
    }
    rep(i, 0, h2) rep(j, 0, w2) {
        b[i][j] = rng.get(0, mint::mod());
    }
    assert(convolution_2d(a, b) == convolution_2d_naive(a, b));
}

}  // namespace ebi

int main() {
    ebi::fast_io();
    int t = 10;
    // std::cin >> t;
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    while (t--) {
        ebi::main_();
    }
    return 0;
}