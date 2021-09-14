#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include <iostream>
#include <iomanip>
#include <limits>

#include "geometry/point.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(15);
    double x1,y1,x2,y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    ebi::point p0(x1, y1), p1(x2, y2);
    int q;
    std::cin >> q;
    while(q--) {
        double x,y;
        std::cin >> x >> y;
        int flag = ebi::isp(p0, p1, ebi::point(x,y));
        std::string ans;
        if(flag == 1) {
            ans = "COUNTER_CLOCKWISE";
        }
        else if(flag == -1) {
            ans = "CLOCKWISE";
        }
        else if(flag == -2) {
            ans = "ONLINE_BACK";
        }
        else if(flag == 2) {
            ans = "ONLINE_FRONT";
        }
        else {
            ans = "ON_SEGMENT";
        }
        std::cout << ans << std::endl;
    }
}