#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"

#include "../../data_structure/offline_dual_segtree_2d.hpp"
#include "../../template/template.hpp"

namespace ebi {

i64 merge(i64 a, i64 b) {
    return a + b;
}

i64 id() {
    return 0;
}

struct Query {
    int t;
    int l, d, r, u;
    i64 w;
    int x, y;
};

void main_() {
    int n, q;
    std::cin >> n >> q;
    offline_dual_segtree_2d<i64, merge, id> seg;
    std::vector<std::tuple<int, int, int, int, i64>> s(n);
    for (auto &[l, d, r, u, w] : s) {
        std::cin >> l >> d >> r >> u >> w;
    }
    std::vector<Query> qs(q);
    for (auto &[t, l, d, r, u, w, x, y] : qs) {
        std::cin >> t;
        if (t == 0) {
            std::cin >> l >> d >> r >> u >> w;
        } else {
            std::cin >> x >> y;
            seg.pre_set({x, y});
        }
    }
    seg.build();
    for (auto [l, d, r, u, w] : s) {
        seg.apply(l, d, r, u, w);
    }
    for (auto &[t, l, d, r, u, w, x, y] : qs) {
        if (t == 0) {
            seg.apply(l, d, r, u, w);
        } else {
            std::cout << seg.get(x, y) << '\n';
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