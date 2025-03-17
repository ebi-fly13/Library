#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
#include "../../tree/rerooting.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n;
    std::cin >> n;
    Graph<int> g(n);
    std::vector<std::pair<mint, mint>> edges;
    std::vector<mint> a(n);
    std::cin >> a;
    rep(i, 0, n - 1) {
        int u, v;
        mint b, c;
        std::cin >> u >> v >> b >> c;
        g.add_undirected_edge(u, v, 1);
        edges.emplace_back(b, c);
    }
    g.build();
    using V = std::pair<mint, mint>;
    auto merge = [&](V x, V y) -> V {
        return {x.first + y.first, x.second + y.second};
    };
    auto put_edge = [&](Graph<int>::edge_type e, V x) -> V {
        auto [b, c] = edges[e.id];
        return {b * x.first + c * x.second, x.second};
    };
    auto put_root = [&](int v, V x) -> V {
        return {x.first + a[v], x.second + 1};
    };
    rerooting_dp dp(g, V{0, 0}, merge, put_edge, put_root);
    rep(i, 0, n) {
        std::cout << dp.get(i).first << " \n"[i == n - 1];
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