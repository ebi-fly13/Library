#pragma once

#include <vector>

#include "../math/eratosthenes_sieve.hpp"
#include "../math/linear_sieve.hpp"

namespace ebi {

template <class T>
std::vector<T> dirichlet_convolution(const std::vector<T> &a,
                                     const std::vector<T> &b) {
    assert(a.size() == b.size());
    int n = a.size() - 1;
    std::vector<T> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            c[i * j] += a[i] * b[j];
        }
    }
    return c;
}

template <class T>
std::vector<T> dirichlet_convolution_left_is_multiplicative_function(
    const std::vector<T> &a, const std::vector<T> &b) {
    assert(a.size() == b.size());
    int n = a.size() - 1;
    static int m = 1;
    static std::vector<int> primes;
    if (m < n) {
        while (m < n) m <<= 1;
        eratosthenes_sieve sieve(m);
        primes = sieve.prime_table();
    }
    std::vector<T> c = b;
    for (auto p : primes) {
        if (p > n) break;
        for (int i = n / p; i >= 1; i--) {
            int m = p * i;
            int pk = p, j = i;
            while (1) {
                c[m] += a[pk] * c[j];
                if (j % p != 0) break;
                pk *= p;
                j /= p;
            }
        }
    }
    return c;
}

template <class T>
std::vector<T> dirichlet_convolution_multiplicative_function(
    const std::vector<T> &a, const std::vector<T> &b) {
    assert(a.size() == b.size());
    int n = a.size() - 1;
    static int m = 1;
    static std::vector<std::pair<int, int>> prime_pow_table;
    if (m < n) {
        while (m < n) m <<= 1;
        linear_sieve sieve(m);
        prime_pow_table = sieve.prime_power_table(m);
    }
    std::vector<T> c(n + 1, 0);
    c[1] = a[1] * b[1];
    for (int i = 2; i <= n; i++) {
        auto [p, pk] = prime_pow_table[i];
        if (pk == i) {
            for (int j = 1; j <= i; j *= p) {
                c[i] += a[j] * b[i / j];
            }
        } else {
            c[i] = c[i / pk] * c[pk];
        }
    }
    return c;
}

}  // namespace ebi