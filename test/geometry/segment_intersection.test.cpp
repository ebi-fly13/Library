#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_6_A"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

#include "data_structure/fenwick_tree.hpp"
#include "data_structure/compress.hpp"

namespace ebi {

using i64 = std::int64_t;

void main_() {
    int n;
    std::cin >> n;
    std::map<i64, std::vector<std::pair<i64, i64>>> xmap, ymap;
    compress<i64> cp;
    std::vector<i64> ret;
    for (int i = 0; i < n; i++) {
        i64 x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        ret.emplace_back(x1);
        ret.emplace_back(x2 + 1);
        cp.add(y1);
        cp.add(y2);
        if (x1 == x2) {
            if (y1 > y2) std::swap(y1, y2);
            xmap[x1].emplace_back(y1, y2);
        } else {
            assert(y1 == y2);
            if (x1 > x2) std::swap(x1, x2);
            ymap[x1].emplace_back(y1, 1);
            ymap[x2 + 1].emplace_back(y1, -1);
        }
    }
    cp.build();
    std::sort(ret.begin(), ret.end());
    ret.erase(std::unique(ret.begin(), ret.end()), ret.end());
    fenwick_tree<i64> fw(cp.size());
    i64 ans = 0;
    for (auto x : ret) {
        for (auto [y, val] : ymap[x]) {
            fw.add(cp.get(y), val);
        }
        for (auto [low, high] : xmap[x]) {
            ans += fw.sum(cp.get(low), cp.get(high + 1));
        }
    }
    std::cout << ans << '\n';
}

}  // namespace ebi

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}