#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_C"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/line_segment.hpp"
#include "geometry/polygon.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    Polygon poly(n);
    for(auto &[x, y]: poly) {
        std::cin >> x >> y;
    }
    int q;
    std::cin >> q;
    while(q--) {
        point p;
        std::cin >> p.x >> p.y;
        std::cout << contains(poly, p) << '\n';
    }
}

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}