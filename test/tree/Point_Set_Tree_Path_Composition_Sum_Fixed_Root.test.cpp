#define PROBLEM                        \
    "https://judge.yosupo.jp/problem/" \
    "point_set_tree_path_composite_sum_fixed_root"

#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
#include "../../tree/dp_on_static_top_tree.hpp"

namespace ebi {

using mint = modint998244353;

struct Path {
    mint a, b, s, c;
};

struct Point {
    mint s, c;
};

void main_() {
    int n, q;
    std::cin >> n >> q;
    Graph<int> g(2 * n - 1);
    std::vector<Path> a(2 * n - 1);
    rep(i, 0, n) {
        int x;
        std::cin >> x;
        a[i] = {1, 0, x, 1};
    }
    rep(i, 0, n - 1) {
        int u, v, b, c;
        std::cin >> u >> v >> b >> c;
        g.add_undirected_edge(u, i + n, 1);
        g.add_undirected_edge(v, i + n, 1);
        a[i + n] = {b, c, 0, 0};
    }
    g.build();
    auto compress = [&](Path p, Path c) -> Path {
        return {p.a * c.a, p.b + p.a * c.b, p.s + p.a * c.s + p.b * c.c,
                p.c + c.c};
    };
    auto rake = [&](Point a, Point b) -> Point {
        return {a.s + b.s, a.c + b.c};
    };
    auto add_edge = [&](Path a) -> Point { return {a.s, a.c}; };
    auto add_vertex = [&](Point a, Path v) -> Path {
        return {v.a, v.b, v.s + v.a * a.s + v.b * a.c, a.c + v.c};
    };
    dp_on_static_top_tree<int, Path, Point, decltype(compress), decltype(rake),
                          decltype(add_edge), decltype(add_vertex)>
        dp(g, 0, a, compress, rake, add_edge, add_vertex);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int w, x;
            std::cin >> w >> x;
            dp.set(w, {1, 0, x, 1});
        } else {
            int e, y, z;
            std::cin >> e >> y >> z;
            dp.set(e + n, {y, z, 0, 0});
        }
        std::cout << dp.get().s << '\n';
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