#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H"
#define ERROR 0.00000001

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/circle.hpp"
#include "geometry/point.hpp"

namespace ebi {

using i64 = std::int64_t;

void main_() {
    int n;
    circle c;
    c.c = point(0.0, 0.0);
    std::cin >> n >> c.r;
    std::vector<point> poly(n);
    for (int i = 0; i < n; i++) {
        std::cin >> poly[i];
    }
    std::cout << calc_common_area(c, poly) << '\n';
}

}  // namespace ebi

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}