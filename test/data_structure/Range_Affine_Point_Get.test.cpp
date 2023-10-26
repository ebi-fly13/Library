#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../../data_structure/dual_segtree.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

struct F {
    mint a, b;
};

F merge(F f, F g) {
    return {f.a * g.a, f.b + f.a * g.b};
}

F id() {
    return {1, 0};
}

void main_() {
    int n, q;
    std::cin >> n >> q;
    std::vector<F> a(n);
    rep(i, 0, n) {
        std::cin >> a[i].b;
    }
    dual_segtree<F, merge, id> seg(a);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r;
            mint b, c;
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