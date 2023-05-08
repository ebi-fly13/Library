#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A"

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
    circle c1, c2;
    std::cin >> c1.c.x >> c1.c.y >> c1.r;
    std::cin >> c2.c.x >> c2.c.y >> c2.r;
    std::cout << intersection(c1, c2) << '\n';
}

}  // namespace ebi

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}