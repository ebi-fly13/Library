#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/line_segment.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    std::vector<point> p(n);
    for(auto &[x, y]: p) {
        std::cin >> x >> y;
    }
    std::cout << area(p) << '\n';
}

}

int main() {
    std::cout << std::fixed << std::setprecision(1);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}