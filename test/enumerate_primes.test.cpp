#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <iostream>

#include "../math/eratosthenes_sieve.hpp"

int main() {
    int n,a,b;
    std::cin >> n >> a >> b;
    ebi::eratosthenes_sieve sieve(n);
    auto p = sieve.prime_table();
    int sz = p.size();
    int x = (sz-b+a-1)/a;
    std::cout << sz << " " << x << '\n';
    for(int i = b; i<sz; i += a) {
        std::cout << p[i] << " ";
    }
    std::cout << "\n";
}