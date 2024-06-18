#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../data_structure/fenwick_tree.hpp"
#include "../../template/template.hpp"
#include "../../tree/dsu_on_tree.hpp"
#include "../../tree/heavy_light_decomposition.hpp"

namespace ebi {

void main_() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    std::cin >> a;
    Graph<int> g(n);
    g.read_parents(0);
    std::vector<std::tuple<int, int, i64>> qs(q);
    std::vector q1(n, std::vector<int>()), q2(n, std::vector<int>());
    for (int i = 0; auto &[t, u, x] : qs) {
        std::cin >> t >> u;
        if (t == 0) {
            q1[u].emplace_back(i);
            std::cin >> x;
        } else {
            q2[u].emplace_back(i);
        }
        i++;
    }
    i64 sum = 0;
    std::vector<i64> ans(q, -1);
    fenwick_tree<i64> fw(q);
    auto add = [&](int v) -> void {
        sum += a[v];
        for (auto i : q1[v]) {
            i64 x = std::get<2>(qs[i]);
            fw.add(i, x);
        }
    };
    auto query = [&](int v) -> void {
        for (auto i : q2[v]) {
            ans[i] = sum + fw.prefix_sum(i);
        }
    };
    auto clear = [&](int v) -> void {
        sum -= a[v];
        for (auto i : q1[v]) {
            i64 x = std::get<2>(qs[i]);
            fw.add(i, -x);
        }
    };
    auto reset = [&]() -> void {

    };
    heavy_light_decomposition hld(g);
    hld.dsu_on_tree(add, query, clear, reset);
    rep(i, 0, q) {
        if (ans[i] == -1) continue;
        std::cout << ans[i] << '\n';
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