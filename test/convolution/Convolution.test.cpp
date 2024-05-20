#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../convolution/convolution.hpp"

#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, m;
    std::cin >> n >> m;
    std::vector<mint> a(n), b(m);
    std::cin >> a >> b;
    std::cout << convolution(a, b) << '\n';
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