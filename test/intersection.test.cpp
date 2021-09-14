#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

#include "../geometry/point.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(15);
    int q;
    std::cin >> q;
    while(q--) {
        double x,y;
        std::vector<ebi::point> p(4);
        for(int i = 0; i<4; i++) {
            std::cin >> x >> y;
            p[i] = ebi::point(x,y);
        }
        if(ebi::intersection(p[0],p[1],p[2],p[3])) {
            std::cout << 1 << std::endl;
        }
        else {
            std::cout << 0 << std::endl;
        }
    }
}