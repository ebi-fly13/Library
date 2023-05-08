#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C"
#define ERROR 0.00000001

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/line.hpp"
#include "geometry/point.hpp"

namespace ebi {

void main_() {
    int q;
    std::cin >> q;
    while (q--) {
        point p0, p1, p2, p3;
        std::cin >> p0.x >> p0.y >> p1.x >> p1.y;
        std::cin >> p2.x >> p2.y >> p3.x >> p3.y;
        point cross = cross_point(p0, p1, p2, p3);
        std::cout << cross.x << " " << cross.y << '\n';
    }
}

}  // namespace ebi

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}