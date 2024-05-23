#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include <iostream>
#include <vector>

#include "../../fps/ntt_friendly_fps.hpp"
#include "../../fps/product_of_one_plus_xn.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    auto p = ebi::product_of_one_plus_xn<mint>(s, t + 1);
    for (int i = 1; i <= t; i++) {
        std::cout << p[i] << " \n"[i == t];
    }
}