#pragma once

#include <cassert>
#include <vector>

#include "point.hpp"

namespace ebi {

using Polygon = std::vector<point>;

long double area(const Polygon &poly) {
    long double s = 0;
    int n = poly.size();
    for(int i = 0; i < n; i++) {
        s = internal::add(s, det(poly[i], poly[(i+1 != n) ? i+1 : 0]));
    }
    s /= 2.0;
    return s;
}

// 凸多角形か判定. pに反時計回りで点が入っていると仮定
bool is_convex(const Polygon &poly) {
    int n = poly.size();
    for(int i = 0; i < n; i++) {
        if(isp(poly[i], poly[(i+1 != n) ? i+1 : 0], poly[(i+2 < n) ? i+2 : (i+2)%n]) == -1) {
            return false;
        }
    }
    return true;
}

enum {
    OUT, ON, IN
};

int contains(const std::vector<point> &poly, const point &p) {
    bool in = false;
    int n = poly.size();
    for(int i = 0; i < n; i++) {
        point a = poly[i] - p;
        point b = poly[(i+1 < n) ? i+1 : 0] - p;
        if(a.y > b.y) std::swap(a, b);
        if(a.y <= 0 && 0 < b.y && det(a, b) < 0) in = !in;
        if(det(a, b) == 0 && dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}

}