#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../../matrix/base.hpp"
#include "../../matrix/gauss_jordan.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, m;
    std::cin >> n >> m;
    matrix<mint> a(n, m);
    std::cin >> a;
    std::vector<mint> b(n);
    std::cin >> b;
    auto ans = solve_linear_equations(a, b);
    if (ans) {
        auto res = ans.value();
        int r = res.size() - 1;
        std::cout << r << '\n';
        for (auto c : res) {
            std::cout << c << '\n';
        }
    } else {
        std::cout << "-1\n";
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