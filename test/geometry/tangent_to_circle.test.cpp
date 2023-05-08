#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F"
#define ERROR 0.00000001

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

#include "geometry/circle.hpp"

namespace ebi {

using i64 = std::int64_t;

void main_() {
    circle c;
    point p;
    std::cin >> p;
    std::cin >> c.c >> c.r;
    auto ps = tangent_to_circle(c, p);
    std::sort(ps.begin(), ps.end());
    for (auto p : ps) {
        std::cout << p << '\n';
    }
}

}  // namespace ebi

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}