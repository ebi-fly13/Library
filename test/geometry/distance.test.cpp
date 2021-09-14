#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D"
#define ERROR 0.00000001

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/line_segment.hpp"

namespace ebi {

void main_() {
    int q;
    std::cin >> q;
    while(q--) {
        point p0, p1, p2, p3;
        std::cin >> p0.x >> p0.y >> p1.x >> p1.y;
        std::cin >> p2.x >> p2.y >> p3.x >> p3.y;
        std::cout << distance(line_segment(p0, p1), line_segment(p2, p3)) << '\n';
    }
}

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}