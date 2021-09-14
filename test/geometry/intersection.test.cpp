#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "geometry/point.hpp"
#include "geometry/line.hpp"

namespace ebi {

void main_() {
    int q;
    std::cin >> q;
    while(q--) {
        point p0, p1, p2, p3;
        std::cin >> p0.x >> p0.y >> p1.x >> p1.y;
        std::cin >> p2.x >> p2.y >> p3.x >> p3.y;
        line s1(p0, p1);
        line s2(p2, p3);
        int flag = intersection(s1, s2);
        if(flag == 3) flag = 2;
        std::cout << flag << '\n';
    }
}

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}