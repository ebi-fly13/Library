#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include <iostream>
#include <vector>

#include "../../graph/base.hpp"
#include "../../modint/modint.hpp"
#include "../../tree/rerooting.hpp"

using mint = ebi::modint998244353;

std::vector<mint> a;

struct S {
    mint sum;
    mint sz;
};

S e() {
    return {0, 0};
}

S merge(S lhs, S rhs) {
    return {lhs.sum + rhs.sum, lhs.sz + rhs.sz};
}

S put_edge(std::pair<mint, mint> e, S x) {
    auto [b, c] = e;
    return {b * x.sum + c * x.sz, x.sz};
}

S put_root(int idx, S x) {
    return {a[idx] + x.sum, x.sz + 1};
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        a.emplace_back(val);
    }
    ebi::Graph<std::pair<mint, mint>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, b, c;
        std::cin >> u >> v >> b >> c;
        g.add_edge(u, v, {b, c});
        g.add_edge(v, u, {b, c});
    }
    g.build();
    ebi::rerooting<std::pair<mint, mint>, S, S, e, merge, put_edge, put_root>
        dp(n, g);
    for (int i = 0; i < n; i++) {
        std::cout << dp.get(i).sum.val() << " \n"[i == n - 1];
    }
}