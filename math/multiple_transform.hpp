#pragma once

#include <vector>

#include "../math/eratosthenes_sieve.hpp"

namespace ebi {

struct multiple_transform {
    multiple_transform() = default;

    template <class mint>
    static std::vector<mint> zeta_transform(const std::vector<mint> &f) {
        int n = f.size() - 1;
        auto F = f;
        if (m < n) {
            while (m < n) m <<= 1;
            eratosthenes_sieve sieve(m);
            primes = sieve.prime_table();
        }
        for (const auto &p : primes) {
            if (n < p) break;
            for (int i = n / p; i > 0; i--) F[i] += F[i * p];
        }
        return F;
    }

    template <class mint>
    static std::vector<mint> mobius_transform(const std::vector<mint> &F) {
        int n = F.size() - 1;
        auto f = F;
        if (m < n) {
            while (m < n) m <<= 1;
            eratosthenes_sieve sieve(m);
            primes = sieve.prime_table();
        }
        for (const auto &p : primes) {
            if (n < p) break;
            for (int i = 1; i * p <= n; i++) f[i] -= f[i * p];
        }
        return f;
    }

  private:
    static int m;
    static std::vector<int> primes;
};

int multiple_transform::m = 4;
std::vector<int> multiple_transform::primes = {2, 3};

}  // namespace ebi