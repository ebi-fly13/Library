#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C"
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
    point a, b, c;
    std::cin >> a.x >> a.y;
    std::cin >> b.x >> b.y;
    std::cin >> c.x >> c.y;
    circle in = circumscribed_circle_of_triangle(a, b, c);
    std::cout << in.c << " " << in.r << '\n';
}

}  // namespace ebi

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}