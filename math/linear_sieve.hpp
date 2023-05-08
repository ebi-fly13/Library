#pragma once

#include "../math/pow.hpp"
#include "../utility/int_alias.hpp"

/*
    reference: https://37zigen.com/linear-sieve/
    verify:    https://atcoder.jp/contests/abc162/submissions/25095562
*/

#include <vector>

namespace ebi {

template <class modint> struct linear_sieve {
  private:
    using u64 = std::uint64_t;
    int n;
    std::vector<int> sieve;
    std::vector<int> prime;

  public:
    linear_sieve(int _n) : n(_n), sieve(std::vector<int>(_n + 1, -1)) {
        for (int i = 2; i <= n; i++) {
            if (sieve[i] < 0) {
                sieve[i] = i;
                prime.emplace_back(i);
            }
            for (auto p : prime) {
                if (u64(p) * u64(i) > u64(n) || p > sieve[i]) break;
                sieve[p * i] = p;
            }
        }
    }

    std::vector<int> prime_table() {
        return prime;
    }

    std::vector<std::pair<int, int>> factorize(int n) {
        std::vector<std::pair<int, int>> res;
        while (n > 1) {
            int p = sieve[n];
            int exp = 0;
            if (p < 0) {
                res.emplace_back(n, 1);
                break;
            }
            while (sieve[n] == p) {
                n /= p;
                exp++;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    std::vector<int> divisors(int n) {
        std::vector<int> res;
        res.emplace_back(1);
        auto pf = factorize(n);
        for (auto p : pf) {
            int sz = res.size();
            for (int i = 0; i < sz; i++) {
                int ret = 1;
                for (int j = 0; j < p.second; j++) {
                    ret *= p.first;
                    res.emplace_back(res[i] * ret);
                }
            }
        }
        return res;
    }

    template <class T> std::vector<T> fast_zeta(const std::vector<T> &f) {
        std::vector<T> F = f;
        int sz = f.size();
        assert(sz <= n + 1);
        for (int i = 2; i < sz; i++) {
            if (sieve[i] != i) continue;
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
            if (sieve[i] != i) continue;
            for (int j = 1; j * i < sz; j++) {
                f[j] -= f[j * i];
            }
        }
        return f;
    }

    std::vector<modint> pow_table(int k) {
        std::vector<modint> table(n + 1, 1);
        table[0] = 0;
        for (int i = 2; i <= n; i++) {
            if (sieve[i] == i) {
                table[i] = modint(i).pow(k);
                continue;
            }
            table[i] = table[sieve[i]] * table[i / sieve[i]];
        }
        return table;
    }

    std::vector<modint> inv_table() {
        return pow_table(modint::mod() - 2);
    }
};

}  // namespace ebi
