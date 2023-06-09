#pragma once

#include <cassert>
#include <cstdint>
#include <vector>

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