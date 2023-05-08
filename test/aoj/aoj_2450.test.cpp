#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2450"

#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

#include "../../data_structure/LazySegtree.hpp"
#include "../../graph/template.hpp"
#include "../../tree/heavy_light_decomposition.hpp"

using i64 = std::int64_t;

struct S {
    i64 sum;
    i64 lhs;
    i64 rhs;
    i64 ans;
    i64 sz;
};

i64 LNF = std::numeric_limits<i64>::max() / 4;

using F = i64;
const F ID = LNF;

S op(S a, S b) {
    if (a.sz == 0) return b;
    if (b.sz == 0) return a;
    return {a.sum + b.sum, std::max(a.lhs, a.sum + b.lhs),
            std::max(a.rhs + b.sum, b.rhs),
            std::max(std::max(a.ans, b.ans), a.rhs + b.lhs), a.sz + b.sz};
}

S op_rev(S a, S b) {
    return op(b, a);
}

S e() {
    return {0, -LNF, -LNF, -LNF, 0};
}

S mapping(F f, S x) {
    if (f != ID) {
        x.sum = f * x.sz;
        if (f < 0) {
            x.lhs = f;
            x.rhs = f;
            x.ans = f;
        } else {
            x.lhs = x.rhs = x.ans = x.sum;
        }
    }
    return x;
}

F composition(F f, F g) {
    return (f == ID) ? g : f;
}

F id() {
    return ID;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> w(n);
    for (int i = 0; i < n; i++) std::cin >> w[i];
    ebi::graph g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        g.add_edge(u, v);
    }
    ebi::heavy_light_decomposition hld(g);
    std::vector<S> vec(n);
    for (int i = 0; i < n; i++) {
        vec[hld.idx(i)] = {w[i], w[i], w[i], w[i], 1};
    }
    ebi::LazySegtree<S, op, e, F, mapping, composition, id> seg1(vec);
    ebi::LazySegtree<S, op_rev, e, F, mapping, composition, id> seg2(vec);
    F c = id();
    S ans = e();
    auto apply = [&](int u, int v) -> void {
        if (u > v) std::swap(u, v);
        seg1.apply(u, v, c);
        seg2.apply(u, v, c);
    };
    auto prod = [&](int l, int r) -> void {
        if (l <= r)
            ans = op(ans, seg1.prod(l, r));
        else
            ans = op(ans, seg2.prod(r, l));
    };
    while (q--) {
        int t, a, b;
        std::cin >> t >> a >> b >> c;
        a--;
        b--;
        if (t == 1) {
            hld.path_noncommutative_query(a, b, true, apply);
        } else {
            ans = e();
            hld.path_noncommutative_query(a, b, true, prod);
            std::cout << ans.ans << '\n';
        }
    }
}