#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235"

#include <array>
#include <iostream>
#include <vector>

#include "../../data_structure/offline_dynamic_connectivity.hpp"

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::array<int, 3>> edge_qs;
    std::vector<std::array<int, 3>> uf_qs;
    for (int i = 0; i < k; i++) {
        int t, u, v;
        std::cin >> t >> u >> v;
        t--;
        std::array<int, 3> q = {t, u, v};
        if (t == 2) {
            q[0] = (int)edge_qs.size();
            uf_qs.emplace_back(q);
        } else {
            edge_qs.emplace_back(q);
        }
    }
    ebi::offline_dynamic_connective uf(n, edge_qs);
    int now = 0;
    auto f = [&](int i) -> void {
        while (1) {
            if (now < (int)uf_qs.size() && uf_qs[now][0] == i) {
                int u = uf_qs[now][1];
                int v = uf_qs[now][2];
                std::cout << (uf.is_same(u, v) ? "YES" : "NO") << '\n';
                now++;
            } else {
                return;
            }
        }
    };
    uf.execute(f);
    assert(now == (int)uf_qs.size());
}