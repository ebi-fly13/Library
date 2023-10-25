#pragma once

#include "../template/int_alias.hpp"

/*
    reference: https://37zigen.com/linear-sieve/
    verify:    https://atcoder.jp/contests/abc162/submissions/25095562
*/

#include <cassert>
#include <vector>

namespace ebi {

struct linear_sieve {
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

    std::vector<int> prime_table() const {
        return prime;
    }

    std::vector<std::pair<int, int>> prime_power_table(int m) const {
        assert(m <= n);
        std::vector<std::pair<int, int>> table(m + 1, {1, 1});
        for (int i = 2; i <= m; i++) {
            int p = sieve[i];
            table[i] = {p, p};
            if (sieve[i / p] == p) {
                table[i] = table[i / p];
                table[i].second *= p;
            }
        }
        return table;
    }

    std::vector<std::pair<int, int>> factorize(int x) {
        assert(x <= n);
        std::vector<std::pair<int, int>> res;
        while (x > 1) {
            int p = sieve[x];
            int exp = 0;
            if (p < 0) {
                res.emplace_back(x, 1);
                break;
            }
            while (sieve[x] == p) {
                x /= p;
                exp++;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    std::vector<int> divisors(int x) {
        assert(x <= n);
        std::vector<int> res;
        res.emplace_back(1);
        auto pf = factorize(x);
        for (auto p : pf) {
            int sz = (int)res.size();
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

    template <class modint> std::vector<modint> pow_table(int k) {
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

    template <class modint> std::vector<modint> inv_table() {
        return pow_table(modint::mod() - 2);
    }
};

}  // namespace ebi
