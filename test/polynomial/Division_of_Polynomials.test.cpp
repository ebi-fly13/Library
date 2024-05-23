#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "../../fps/ntt_friendly_fps.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;
using FPS = ebi::FormalPowerSeries<mint>;

int main() {
    int n, m;
    std::cin >> n >> m;
    FPS f(n), g(m);
    for (int i = 0; i < n; i++) std::cin >> f[i];
    for (int i = 0; i < m; i++) std::cin >> g[i];
    auto q = f / g;
    auto r = f % g;
    std::cout << q.size() << " " << r.size() << '\n';
    for (int i = 0; i < (int)q.size(); i++) {
        std::cout << q[i] << " ";
    }
    std::cout << '\n';
    for (int i = 0; i < (int)r.size(); i++) {
        std::cout << r[i] << " ";
    }
    std::cout << '\n';
}