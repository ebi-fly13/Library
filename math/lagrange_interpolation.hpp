#pragma once

#include <vector>

#include "../utility/modint.hpp"

/*
    reference: https://atcoder.jp/contests/abc208/editorial/2195
    verify: https://atcoder.jp/contests/abc208/tasks/abc208_f
*/

namespace ebi {

using mint = modint1000000007;
using i64 = long long;

mint lagrange_interpolation(const std::vector<mint> &f, i64 n) {
    const int d = int(f.size()) - 1; // Nのd次以下の多項式
    mint fact = 1;
    std::vector<mint> inv_fact(d+1);
    for(int i = 1; i < d+1; ++i) {
        fact *= i;
    }
    inv_fact[d] = fact.inv();
    for(int i = d; i > 0; i--) {
        inv_fact[i-1] = inv_fact[i] * i;
    }
    std::vector<mint> l(d+1), r(d+1);
    l[0] = 1;
    for(int i = 0; i < d; ++i) {
        l[i+1] = l[i] * (n-i);
    }
    r[d] = 1;
    for(int i = d; i > 0; --i) {
        r[i-1] = r[i] * (n-i);
    }
    mint res = 0;
    for(int i = 0; i < d+1; ++i) {
        res += mint((d-i)%2 == 1 ? -1: 1) * f[i] * l[i] * r[i] * inv_fact[i] * inv_fact[d-i];
    }
    return res;
}

}