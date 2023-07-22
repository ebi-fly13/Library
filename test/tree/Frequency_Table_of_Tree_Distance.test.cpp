#define PROBLEM \
    "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

#include "../../convolution/convolution_mod_2_64.hpp"
#include "../../graph/template.hpp"
#include "../../tree/centroid_decomposition.hpp"

using u64 = uint64_t;

int main() {
    int n;
    std::cin >> n;
    ebi::graph g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        g.add_edge(a, b);
    }
    ebi::centroid_decomposition cdtree(g);
    auto [root, tree] = cdtree.get_centroid_decomposition_tree();
    std::vector<bool> dead(n, false);
    std::vector<u64> ans(n, 0);
    std::vector<u64> cnts;
    std::vector<u64> depths;
    auto dfs_depth = [&](auto &&self, int v, int par = -1,
                         int depth = 0) -> void {
        while ((int)cnts.size() <= depth) cnts.emplace_back(0);
        while ((int)depths.size() <= depth) depths.emplace_back(0);
        cnts[depth]++;
        depths[depth]++;
        for (auto nv : g[v])
            if (nv != par && !dead[nv]) {
                self(self, nv, v, depth + 1);
            }
    };
    std::queue<int> que;
    que.push(root);
    while (!que.empty()) {
        auto v = que.front();
        que.pop();
        cnts.clear();
        dead[v] = true;
        for (auto nv : tree[v]) que.push(nv);
        for (auto nv : g[v]) {
            if (dead[nv]) continue;
            depths.clear();
            dfs_depth(dfs_depth, nv, v, 1);
            auto self2 = ebi::convolution_mod_2_64(depths, depths);
            for (int i = 0; i < (int)self2.size(); i++) ans[i] -= self2[i];
        }
        if (cnts.empty()) continue;
        cnts[0]++;
        auto cnts2 = ebi::convolution_mod_2_64(cnts, cnts);
        for (int i = 0; i < (int)cnts2.size(); i++) ans[i] += cnts2[i];
    }
    for (int i = 1; i < n; i++) {
        ans[i] >>= 1;
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}