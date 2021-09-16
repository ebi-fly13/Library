#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H"
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
    int n;
    circle c;
    c.c = point(0.0, 0.0);
    std::cin >> n >> c.r;
    std::vector<point> poly(n);
    for(int i = 0; i < n; i++) {
        std::cin >> poly[i];
    }
    std::cout << calc_common_area(c, poly) << '\n';
}

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}