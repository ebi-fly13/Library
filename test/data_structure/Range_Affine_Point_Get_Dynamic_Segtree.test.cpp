#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../../data_structure/dynamic_dual_segtree.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

struct F {
    mint a, b;
};

F merge(F a, F b) {
    return {a.a * b.a, a.b + a.a * b.b};
}

F id() {
    return {1, 0};
}

void main_() {
    int n, q;
    std::cin >> n >> q;
    dynamice_dual_segtree<F, merge, id> seg(1'000'000'000);
    rep(i, 0, n) {
        int a;
        std::cin >> a;
        seg.set(i, {0, a});
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, b, c;
            std::cin >> l >> r >> b >> c;
            seg.apply(l, r, {b, c});
        } else {
            int i;
            std::cin >> i;
            std::cout << seg.get(i).b << '\n';
        }
    }
}

}  // namespace ebi

int main() {
    ebi::fast_io();
    int t = 1;
    // std::cin >> t;
    while (t--) {
        ebi::main_();
    }
    return 0;
}