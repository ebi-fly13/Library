#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"
#define ERROR 0.00000001

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstdint>

#include "geometry/point.hpp"
#include "geometry/circle.hpp"

namespace ebi {

using i64 = std::int64_t;

void main_() {
    circle c;
    std::cin >> c.c.x >> c.c.y >> c.r;
    int q;
    std::cin >> q;
    while(q--) {
        long double x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        auto ps = cross_point(c, line(point(x1, y1), point(x2, y2)));
        if(int(ps.size()) == 1) {
            ps.emplace_back(ps.back());
        }
        std::sort(ps.begin(), ps.end());
        for(auto p: ps) {
            std::cout << p << " ";
        }
        std::cout << '\n';
    }
}

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}