#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <utility>
#include <vector>

#include "../../data_structure/li_chao_tree.hpp"
#include "../../utility/int_alias.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::pair<i64, i64>> p(n);
    for (auto &[a, b] : p) {
        std::cin >> a >> b;
    }
    std::vector<i64> x;
    std::vector<std::vector<i64>> query(q);
    for (int i = 0; i < q; i++) {
        int t;
        std::cin >> t;
        query[i].emplace_back(t);
        if (t == 0) {
            i64 a, b;
            std::cin >> a >> b;
            query[i].emplace_back(a);
            query[i].emplace_back(b);
        } else {
            i64 p;
            std::cin >> p;
            query[i].emplace_back(p);
            x.emplace_back(p);
        }
    }
    ebi::li_chao_tree<i64> seg(x);
    for (auto [a, b] : p) {
        seg.add_line(a, b);
    }
    for (int i = 0; i < q; i++) {
        if (query[i][0] == 0) {
            seg.add_line(query[i][1], query[i][2]);
        } else {
            std::cout << seg.min(query[i][1]) << '\n';
        }
    }
}