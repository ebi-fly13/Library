#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"
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
    circle c1, c2;
    std::cin >> c1.c >> c1.r;
    std::cin >> c2.c >> c2.r;
    auto ps = cross_point(c1, c2);
    if (int(ps.size()) == 1) {
        ps.emplace_back(ps.back());
    }
    std::sort(ps.begin(), ps.end());
    for (auto p : ps) {
        std::cout << p << " ";
    }
    std::cout << '\n';
}

}  // namespace ebi

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}
