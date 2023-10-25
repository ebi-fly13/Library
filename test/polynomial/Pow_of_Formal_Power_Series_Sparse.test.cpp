#define PROBLEM \
    "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include <iostream>
#include <vector>

#include "../../fps/fps_sparse.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n, k;
    long long m;
    std::cin >> n >> k >> m;
    std::vector<mint> f(n);
    for (int i = 0; i < k; i++) {
        int idx, a;
        std::cin >> idx >> a;
        f[idx] = a;
    }
    auto g = ebi::pow_sparse(f, m, n);
    for (int i = 0; i < n; i++) {
        std::cout << g[i].val() << " \n"[i == n - 1];
    }
}