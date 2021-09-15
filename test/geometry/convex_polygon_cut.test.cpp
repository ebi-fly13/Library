#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_C"
#define ERROR 0.00000001

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstdint>

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/polygon.hpp"

namespace ebi {

using i64 = std::int64_t;

void main_() {
    int n;
    std::cin >> n;
    std::vector<point> poly(n);
    for(auto &[x, y]: poly) {
        std::cin >> x >> y;
    }
    int q;
    std::cin >> q;
    while(q--) {
        point p1, p2;
        std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
        auto p = convex_polygon_cut(poly, line(p1, p2));
        std::cout << area(p) << '\n';
    }
}

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}