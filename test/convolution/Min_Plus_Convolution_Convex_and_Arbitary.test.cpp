#define PROBLEM \
    "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"

#include "../../convolution/min_plus_convolution.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    std::cin >> a >> b;
    auto c = min_plus_convolution_convex_and_arbitary(a, b);
    std::cout << c << '\n';
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