#pragma once

#include <cassert>
#include <vector>
#include <cstdint>

/*
    reference: https://37zigen.com/sieve-eratosthenes/
*/

namespace ebi {

struct eratosthenes_sieve {
  private:
    using i64 = std::int_fast64_t;
    int n;
    std::vector<bool> table;

  public:
    eratosthenes_sieve(int n) : n(n), table(std::vector<bool>(n + 1, true)) {
        table[1] = false;
        for (i64 i = 2; i * i <= n; i++) {
            if (!table[i]) continue;
            for (i64 j = i; i * j <= n; j++) {
                table[i * j] = false;
            }
        }
    }

    bool is_prime(int p) {
        return table[p];
    }

    template <class T> std::vector<T> fast_zeta(const std::vector<T> &f) {
        std::vector<T> F = f;
        int sz = f.size();
        assert(sz <= n + 1);
        for (int i = 2; i < sz; i++) {
            if (!table[i]) continue;
            for (int j = (sz - 1) / i; j >= 1; j--) {
                F[j] += F[j * i];
            }
        }
        return F;
    }

    template <class T> std::vector<T> fast_mobius(const std::vector<T> &F) {
        std::vector<T> f = F;
        int sz = F.size();
        assert(sz <= n + 1);
        for (int i = 2; i < sz; i++) {
            if (!table[i]) continue;
            for (int j = 1; j * i < sz; j++) {
                f[j] -= f[j * i];
            }
        }
        return f;
    }

    std::vector<int> prime_table(int m = -1) {
        if (m < 0) m = n;
        std::vector<int> prime;
        for (int i = 2; i <= m; i++) {
            if (table[i]) prime.emplace_back(i);
        }
        return prime;
    }
};

}  // namespace ebi