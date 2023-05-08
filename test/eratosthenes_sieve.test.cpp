#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include "../math/eratosthenes_sieve.hpp"

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    ebi::eratosthenes_sieve sieve(1e8);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p;
        std::cin >> p;
        if (sieve.is_prime(p)) ans++;
    }
    std::cout << ans << '\n';
}