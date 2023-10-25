#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../../fps/multipoint_evaluation.hpp"

#include "../../convolution/ntt.hpp"
#include "../../fps/fps.hpp"
#include "../../template/template.hpp"
#include "../../modint/modint.hpp"

namespace ebi {

using mint = modint998244353;
using FPS = FormalPowerSeries<mint, convolution>;

void main_() {
    int n, m;
    std::cin >> n >> m;
    FPS f(n);
    std::cin >> f;
    std::vector<mint> p(m);
    std::cin >> p;
    auto fp = multipoint_evaluation<mint, convolution>(f, p);
    std::cout << fp << '\n';
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