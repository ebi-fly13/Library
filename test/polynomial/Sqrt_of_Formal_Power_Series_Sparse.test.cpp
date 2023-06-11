#define PROBLEM \
    "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse"

#include "../../convolution/ntt.hpp"
#include "../../fps/fps.hpp"
#include "../../fps/fps_sqrt.hpp"
#include "../../utility/modint.hpp"

using namespace ebi;

using mint = modint998244353;
using FPS = FormalPowerSeries<mint, convolution>;

int main() {
    int n, k;
    std::cin >> n >> k;
    FPS f(n);
    for (int i = 0; i < k; i++) {
        int idx, a;
        std::cin >> idx >> a;
        f[idx] = a;
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