#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_5_A"
#define ERROR 0.00000001

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cstdint>

#include "geometry/point.hpp"

namespace ebi {

using i64 = std::int64_t;

void main_() {
    int n;
    std::cin >> n;
    std::vector<point> p(n);
    for(auto &[x, y]: p) {
        std::cin >> x >> y;
    }
    std::cout << closest_pair(p) << '\n';
}

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}