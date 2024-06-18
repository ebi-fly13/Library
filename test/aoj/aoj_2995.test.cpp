#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995"

#include "../../data_structure/undo_unionfind.hpp"
#include "../../template/template.hpp"
#include "../../tree/dsu_on_tree.hpp"
#include "../../tree/heavy_light_decomposition.hpp"

namespace ebi {

void main_() {
    int n, k;
    std::cin >> n >> k;
    Graph<int> g(n);
    g.read_tree();
    std::vector<std::pair<int, int>> cs(n);
    for (auto &[c, d] : cs) {
        std::cin >> c >> d;
        c--;
        d--;
    }
    std::vector<bool> is_tree(n, true);
    undo_unionfind uf(n);
    std::vector<int> ans(n);
    int res = 0;
    auto val = [&](int v) -> int {
        v = uf.leader(v);
        return is_tree[v] ? uf.size(v) - 1 : uf.size(v);
    };
    auto add = [&](int v) -> void {
        auto [c, d] = cs[v];
        c = uf.leader(c);
        d = uf.leader(d);
        if (c != d) {
            res -= val(c) + val(d);
        }
        if (uf.merge(c, d)) {
            res += val(uf.leader(c));
            is_tree[uf.leader(c)] = is_tree[c] && is_tree[d];
        } else if (is_tree[c]) {
            res++;
            is_tree[c] = false;
        }
    };
    auto query = [&](int v) -> void { ans[v] = res; };
    auto clear = [&](int v) -> void {
        is_tree[v] = true;
        uf.undo();
    };
    auto reset = [&]() -> void { res = 0; };
    heavy_light_decomposition hld(g);
    hld.dsu_on_tree(add, query, clear, reset);
    for (auto x : ans) {
        std::cout << x << '\n';
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