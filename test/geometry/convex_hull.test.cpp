#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdint>

#include "geometry/convex_hull.hpp"

namespace ebi {

using i64 = std::int64_t;

void main_() {
    int n;
    std::cin >> n;
    std::vector<Point<i64>> poly(n);
    for(auto &[x, y]: poly) {
        std::cin >> x >> y;
    }
    auto ch = convex_hull(n, poly, true);
    int m = ch.size();
    int idx = 0;
    for(int i = 0; i < m; i++) {
        if(ch[i].y < ch[idx].y) {
            idx = i;
        }
        else if(ch[i].y == ch[idx].y) {
            if(ch[i].x < ch[idx].x) {
                idx = i;
            }
        }
    }
    std::cout << m << '\n';
    for(int i = 0; i < m; i++) {
        auto [x, y] = ch[(i+idx)%m];
        std::cout << x << " " << y << '\n';
    }
}

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}