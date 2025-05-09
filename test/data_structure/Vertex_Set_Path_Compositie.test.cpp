#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <cstdint>
#include <iostream>
#include <vector>

#include "../../data_structure/segtree.hpp"
#include "../../graph/base.hpp"
#include "../../modint/modint.hpp"
#include "../../tree/heavy_light_decomposition.hpp"

using mint = ebi::modint998244353;

using i64 = std::int64_t;

struct S {
    mint c, d;
};

S op(S a, S b) {
    return {b.c * a.c, b.c * a.d + b.d};
}

S e() {
    return {1, 0};
}

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::Graph<int> g(n);
    std::vector<S> fx(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        fx[i] = {a, b};
    }
    g.read_tree(0);
    ebi::heavy_light_decomposition hld(g);
    ebi::segtree<S, op, e> seg1(n);
    ebi::segtree<S, op, e> seg2(n);
    for (int i = 0; i < n; i++) {
        int idx = hld.idx(i);
        seg1.set(idx, fx[i]);
        seg2.set(n - 1 - idx, fx[i]);
    }
    S ans = e();
    auto f = [&](int l, int r) -> void {
        if (l <= r) {
            ans = op(ans, seg1.prod(l, r));
        } else {
            ans = op(ans, seg2.prod(n - l, n - r));
        }
    };
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p, c, d;
            std::cin >> p >> c >> d;
            int idx = hld.idx(p);
            seg1.set(idx, {c, d});
            seg2.set(n - 1 - idx, {c, d});
        } else {
            int u, v, x;
            std::cin >> u >> v >> x;
            ans = e();
            hld.path_noncommutative_query(u, v, true, f);
            std::cout << (ans.c * x + ans.d).val() << '\n';
        }
    }
}