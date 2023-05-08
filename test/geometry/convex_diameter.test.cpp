#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_B"
#define ERROR 0.00000001

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/point.hpp"
#include "geometry/polygon.hpp"

namespace ebi {

using i64 = std::int64_t;

void main_() {
    int n;
    std::cin >> n;
    std::vector<point> poly(n);
    for (auto &[x, y] : poly) {
        std::cin >> x >> y;
    }
    std::cout << convex_diameter(poly) << '\n';
}

}  // namespace ebi

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}