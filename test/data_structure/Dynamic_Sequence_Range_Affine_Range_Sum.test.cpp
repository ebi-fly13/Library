#define PROBLEM \
    "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <iostream>

#include "../../data_structure/ImplicitTreap.hpp"
#include "../../template/int_alias.hpp"
#include "../../utility/modint.hpp"

using mint = ebi::modint998244353;

struct S {
    mint a;
    int size;
};

struct F {
    mint a, b;
    F(mint a, mint b) : a(a), b(b) {}
};

S op(S l, S r) {
    return S{l.a + r.a, l.size + r.size};
}

S e() {
    return S{0, 0};
}

S mapping(F l, S r) {
    return S{r.a * l.a + (mint)r.size * l.b, r.size};
}

F composition(F l, F r) {
    return F{r.a * l.a, r.b * l.a + l.b};
}

F id() {
    return F{1, 0};
}

using ebi::i64;

int main() {
    ebi::ImplicitTreap<S, op, e, F, mapping, composition, id> treap;
    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        i64 a;
        std::cin >> a;
        treap.insert(i, {a, 1});
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int i;
            i64 x;
            std::cin >> i >> x;
            treap.insert(i, {x, 1});
        } else if (t == 1) {
            int i;
            std::cin >> i;
            treap.erase(i);
        } else if (t == 2) {
            int l, r;
            std::cin >> l >> r;
            treap.reverse(l, r);
        } else if (t == 3) {
            int l, r, b, c;
            std::cin >> l >> r >> b >> c;
            treap.apply(l, r, F(b, c));
        } else if (t == 4) {
            int l, r;
            std::cin >> l >> r;
            std::cout << treap.prod(l, r).a.value() << std::endl;
        }
    }
}