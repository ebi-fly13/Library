#define PROBLEM \
    "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include <cstdint>
#include <iostream>
#include <vector>

#include "../../data_structure/link_cut_tree.hpp"

using i64 = std::int64_t;

struct S {
    i64 value;
    int size;
};

using F = i64;

S op(S a, S b) {
    return {a.value + b.value, a.size + b.size};
}
S e() {
    return {0, 0};
}
S mapping(F f, S x) {
    return {x.value + f * x.size, x.size};
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<S> a(n);
    for (auto &s : a) {
        std::cin >> s.value;
        s.size = 1;
    }
    ebi::link_cut_tree<S, op, e, F, mapping, composition, id> lct(a);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        lct.add_edge(u, v);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int u, v, w, x;
            std::cin >> u >> v >> w >> x;
            lct.erase_edge(u, v);
            lct.add_edge(w, x);
        } else if (t == 1) {
            int p;
            F x;
            std::cin >> p >> x;
            lct.set(p, {lct.get(p).value + x, 1});
        } else {
            int u, v;
            std::cin >> u >> v;
            std::cout << lct.prod(u, v).value << '\n';
        }
    }
}