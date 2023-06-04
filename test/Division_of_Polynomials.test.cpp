#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "../convolution/ntt.hpp"
#include "../fps/fps.hpp"
#include "../utility/modint.hpp"

using mint = ebi::modint998244353;
using FPS = ebi::FormalPowerSeries<mint, ebi::convolution>;

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