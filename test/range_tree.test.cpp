#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <cstdint>
#include <tuple>

#include "data_structure/range_tree.hpp"

using i64 = std::int64_t;

int main() {
    int n,q;
    std::cin >> n >> q;
    std::vector<std::tuple<int,int,i64>> points(n);
    for(auto &[x, y, w]: points) {
        std::cin >> x >> y >> w;
    }
    ebi::range_tree tree(points);
    while(q--) {
        int l,d,r,u;
        std::cin >> l >> d >> r >> u;
        std::cout << tree.prod(l, r, d, u) << '\n';
    }
}