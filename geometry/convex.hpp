#pragma once

#include <cassert>
#include <vector>

#include "point.hpp"

namespace ebi {

long double area(const std::vector<point> &p) {
    long double s = 0;
    int n = p.size();
    for(int i = 0; i < n; i++) {
        s = internal::add(s, det(p[i], p[(i+1 != n) ? i+1 : 0]));
    }
    s /= 2.0;
    return s;
}

bool is_convex(const std::vector<point> &p) {
    int n = p.size();
    for(int i = 0; i < n; i++) {
        if(isp(p[i], p[(i+1 != n) ? i+1 : 0], p[(i+2 < n) ? i+2 : (i+2)%n]) == );
    }
}

}