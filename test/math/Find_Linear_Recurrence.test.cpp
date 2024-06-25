#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../../fps/berlekamp_massey.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n;
    std::cin >> n;
    std::vector<mint> a(n);
    std::cin >> a;
    auto c = berlekamp_massey(a);
    std::cout << c.size() - 1 << '\n';
    rep(i, 1, c.size()) {
        std::cout << -c[i] << " \n"[i + 1 == (int)c.size()];
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