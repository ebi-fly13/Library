#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_2_64"

#include <cstdint>
#include <iostream>
#include <vector>

#include "../../convolution/convolution_mod_2_64.hpp"

using u64 = std::uint64_t;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<u64> a(n), b(m);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];
    auto c = ebi::convolution_mod_2_64(a, b);
    for (int i = 0; i < n + m - 1; i++)
        std::cout << c[i] << " \n"[i == n + m - 2];
}