#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821"

#include "../../graph/base.hpp"
#include "../../template/template.hpp"
#include "../../tree/tree_hash.hpp"

namespace ebi {

void main_() {
    int n1, m1;
    std::cin >> n1 >> m1;
    Graph<int> g1(n1);
    g1.read_graph(m1);
    int n2;
    std::cin >> n2;
    Graph<int> g2(n2);
    g2.read_tree();
    auto g2_hash = tree_hash(g2);
    int id = 0;
    std::unordered_map<int, int> map;
    std::vector<std::pair<int, int>> edges;
    auto dfs = [&](auto &&self, int v, int par = -1) -> void {
        map[v] = id++;
        for (auto e : g1[v]) {
            if (e.to == par) continue;
            self(self, e.to, v);
            edges.emplace_back(map[v], map[e.to]);
        }
    };
    int ans = 0;
    rep(i, 0, n1) {
        if (map.contains(i)) continue;
        id = 0;
        edges.clear();
        dfs(dfs, i);
        Graph<int> tree((int)edges.size() + 1);
        for (auto [u, v] : edges) {
            tree.add_undirected_edge(u, v, 1);
        }
        tree.build();
        auto hash = tree_hash(tree);
        if (hash == g2_hash) ans++;
    }
    std::cout << ans << '\n';
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