#pragma once

#include <cmath>
#include <cassert>

#include "point.hpp"

namespace ebi {

struct line {
    point a,b;

    line(long double x1, long double y1, long double x2, long double y2) : a(x1, y1), b(x2, y2) { }

    line(point &a, point &b) : a(a), b(b) { }

    point proj(const point &p) {
        return a + (b-a)*(dot(b-a,p-a)/norm(b-a));
    }

    point relf(const point &p) {
        return proj(p)*double(2) - p;
    }
};
    
}