#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "../../fps/fps_sqrt.hpp"
#include "../../fps/ntt_friendly_fps.hpp"
#include "../../modint/modint.hpp"

using namespace ebi;

using mint = modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    int n;
    std::cin >> n;
    FPS f(n);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        f[i] = a;
    }
    auto opt = f.sqrt(n);
    if (!opt) {
        std::cout << "-1\n";
        return 0;
    }
    auto g = opt.value();
    for (int i = 0; i < n; i++) {
        std::cout << g[i].val() << " \n"[i == n - 1];
    }
}