#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include <iostream>
#include <vector>

#include "../tree/rerooting.hpp"
#include "../utility/modint.hpp"

using mint = ebi::modint998244353;

std::vector<mint> a, b, c;

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

S put_edge(int idx, S x) {
    return {b[idx] * x.sum + c[idx] * x.sz, x.sz};
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
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        std::cin >> u >> v >> x >> y;
        edges.emplace_back(u, v);
        b.emplace_back(x);
        c.emplace_back(y);
    }
    ebi::rerooting<S, S, e, merge, put_edge, put_root> dp(n, edges);
    for (int i = 0; i < n; i++) {
        std::cout << dp.get(i).sum.val() << " \n"[i == n - 1];
    }
}