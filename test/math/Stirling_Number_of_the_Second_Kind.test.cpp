#define PROBLEM \
    "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include <iostream>
#include <numeric>
#include <vector>

#include "../../fps/ntt_friendly_fps.hpp"
#include "../../math/stirling_number_2nd.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    auto ans = ebi::stirling_number_2nd<mint>(n);
    for (int i = 0; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
    }
}