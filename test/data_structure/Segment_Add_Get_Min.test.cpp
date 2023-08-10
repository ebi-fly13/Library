#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <iostream>
#include <utility>
#include <vector>

#include "../../data_structure/li_chao_tree.hpp"
#include "../../template/int_alias.hpp"

using ebi::i64;

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::pair<i64, i64>> lr(n);
    std::vector<std::pair<i64, i64>> y(n);
    std::vector<i64> x;
    for (int i = 0; i < n; i++) {
        std::cin >> lr[i].first >> lr[i].second;
        std::cin >> y[i].first >> y[i].second;
    }
    std::vector<std::vector<i64>> query(q);
    for (int i = 0; i < q; i++) {
        i64 t;
        std::cin >> t;
        query[i].emplace_back(t);
        if (t == 0) {
            i64 l, r, a, b;
            std::cin >> l >> r >> a >> b;
            query[i].emplace_back(l);
            query[i].emplace_back(r);
            query[i].emplace_back(a);
            query[i].emplace_back(b);
        } else {
            i64 p;
            std::cin >> p;
            query[i].emplace_back(p);
            x.emplace_back(p);
        }
    }
    if (x.size() == 0) return 0;
    std::sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    x.emplace_back(1e9 + 10);
    ebi::li_chao_tree<i64> seg(x);
    for (int i = 0; i < n; i++) {
        auto [l, r] = lr[i];
        auto [a, b] = y[i];
        seg.add_segment(a, b, l, r);
    }
    for (int i = 0; i < q; i++) {
        if (query[i][0] == 0) {
            i64 l = query[i][1];
            i64 r = query[i][2];
            i64 a = query[i][3];
            i64 b = query[i][4];
            seg.add_segment(a, b, l, r);
        } else {
            i64 ret = seg.min(query[i][1]);
            if (ret == std::numeric_limits<i64>::max()) {
                std::cout << "INFINITY" << std::endl;
            } else {
                std::cout << ret << std::endl;
            }
        }
    }
}