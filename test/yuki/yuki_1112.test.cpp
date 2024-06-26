#define PROBLEM "https://yukicoder.me/problems/no/1112"

#include "../../convolution/convolution.hpp"
#include "../../fps/arbitrary_mod_fps.hpp"
#include "../../fps/fps.hpp"
#include "../../matrix/black_box_linear_algebra.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint1000000007;

void main_() {
    int k, m;
    i64 n;
    std::cin >> k >> m >> n;
    const int sz = k * k;
    std::vector<std::pair<int, int>> a;
    rep(i, 0, m) {
        int p, q, r;
        std::cin >> p >> q >> r;
        p--;
        q--;
        r--;
        a.emplace_back(q + r * k, p + q * k);
    }
    std::sort(all(a));
    a.erase(std::unique(all(a)), a.end());
    auto Ax = [&](const std::vector<mint> &b) -> std::vector<mint> {
        std::vector<mint> res(sz, 0);
        for (auto [i, j] : a) {
            res[i] += b[j];
        }
        return res;
    };
    std::vector<mint> b(sz, 0);
    rep(i, 0, k) {
        b[i * k] = 1;
    }
    auto res = pow<mint>(sz, Ax, b, n - 2);
    mint ans = 0;
    rep(i, 0, k) {
        ans += res[i];
    }
    std::cout << ans << '\n';
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