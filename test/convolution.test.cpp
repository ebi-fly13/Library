#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../algorithm/convolution.hpp"
#include "../utility/modint.hpp"

#include <iostream>

using mint = ebi::modint998244353;

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<mint> a(n),b(m);
    for(int i = 0; i<n; ++i) {
        std::cin >> a[i].a;
    }
    for(int i = 0; i<m; ++i) {
        std::cin >> b[i].a;
    }
    auto c = ebi::convolution(a, b);
    for(int i = 0; i<n+m-1; ++i) {
        std::cout << c[i].val() << " ";
    }
    std::cout << '\n';
}