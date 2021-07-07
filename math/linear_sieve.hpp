#pragma once

#include "../math/pow.hpp"
#include "../utility/int_alias.hpp"

/*
    reference: https://37zigen.com/linear-sieve/
*/

#include <vector>

namespace ebi {

struct linear_sieve {
private:
    using u64 = std::uint64_t;
    int n;
    std::vector<int> sieve;
    std::vector<int> prime;
public:
    linear_sieve(int _n) : n(_n) , sieve(std::vector<int>(_n + 1, -1)){
        for(int i = 2; i <= n; i++) {
            if(sieve[i] < 0) {
                sieve[i] = i;
                prime.emplace_back(i);
            }
            for(auto p : prime) {
                if(u64(p)*u64(i) > u64(n) || p > sieve[i]) break;
                sieve[p*i] = p;
            }
        }
    }

    std::vector<int> prime_table() {
        return prime;
    }

    std::vector<u64> pow_table(int k, u64 mod) {
        std::vector<u64> table(n+1,1);
        table[0] = 0;
        for(int i = 2; i<= n; i++) {
            if(sieve[i] == i) {
                table[i] = pow(u64(i), k, mod);
                continue;
            }
            table[i] = table[sieve[i]]*table[i/sieve[i]]%mod;
        }
        return table;
    }

    std::vector<u64> inv_table(u64 mod) {
        return pow_table(mod-2, mod);
    }
};

}
