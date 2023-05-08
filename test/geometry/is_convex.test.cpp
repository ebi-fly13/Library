#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_B"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/line.hpp"
#include "geometry/line_segment.hpp"
#include "geometry/point.hpp"
#include "geometry/polygon.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    std::vector<point> p(n);
    for (auto& [x, y] : p) {
        std::cin >> x >> y;
    }
    if (is_convex(p)) {
        std::cout << "1\n";
    } else {
        std::cout << "0\n";
    }
}

}  // namespace ebi

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}