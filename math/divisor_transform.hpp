#pragma once

#include <vector>

#include "../math/eratosthenes_sieve.hpp"

namespace ebi {

struct divisor_transform {
    divisor_transform() = default;

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
            for (int i = 1; i * p <= n; i++) F[p * i] += F[i];
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
            for (int i = n / p; i > 0; i--) f[p * i] -= f[i];
        }
        return f;
    }

  private:
    static int m;
    static std::vector<int> primes;
};

int divisor_transform::m = 4;
std::vector<int> divisor_transform::primes = {2, 3};

}  // namespace ebi