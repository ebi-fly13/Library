#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"

#include <iostream>
#include <iomanip>
#include <limits>

#include "../geometry/template.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(15);
    double x1,y1,x2,y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    ebi::line l(x1,y1,x2,y2);
    int q;
    std::cin >> q;
    while(q--) {
        double x,y;
        std::cin >> x >> y;
        ebi::point p(x,y);
        ebi::point ans = l.relf(p);
        std::cout << ans.x << " " << ans.y << std::endl;
    }
}