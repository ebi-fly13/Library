#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I"
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
    circle c1, c2;
    std::cin >> c1.c >> c1.r;
    std::cin >> c2.c >> c2.r;
    std::cout << common_area(c1, c2) << '\n';
}

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}