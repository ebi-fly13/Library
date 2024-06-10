#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
#include "../../tree/rerooting.hpp"

namespace ebi {

using mint = modint998244353;

struct V {
    mint a;
    int cnt;
};

using E = V;

void main_() {
    int n;
    std::cin >> n;
    Graph<std::pair<mint, mint>> g(n);
    std::vector<mint> a(n);
    std::cin >> a;
    rep(i, 0, n - 1) {
        int u, v;
        mint b, c;
        std::cin >> u >> v >> b >> c;
        g.add_undirected_edge(u, v, {b, c});
    }
    g.build();
    auto e = [&]() -> E { return {0, 0}; };
    auto merge = [&](E s, E t) -> E { return {s.a + t.a, s.cnt + t.cnt}; };
    auto put_edge = [&](int id, V s) -> E {
        auto [b, c] = g.get_edge(id).cost;
        return {b * s.a + c * s.cnt, s.cnt};
    };
    auto put_root = [&](int v, E s) -> V { return {s.a + a[v], s.cnt + 1}; };
    auto dp = rerooting_dp<V, E>(g, e, merge, put_edge, put_root);
    rep(i, 0, n) {
        std::cout << dp[i].a << " \n"[i == n - 1];
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