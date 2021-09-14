#pragma once

#include <cmath>
#include <cassert>

#include "point.hpp"
#include "line.hpp"

namespace ebi {

struct line_segment {
    point a, b;

    line_segment(long double x1, long double y1, long double x2, long double y2) : a(x1, y1), b(x2, y2) { }

    line_segment(point &a, point &b) : a(a), b(b) { }
};

// 線分ab, cd が交わるか判定
bool intersection(const line_segment &a, const line_segment &b) {
    return intersection_line_segment(a.a, a.b, b.a, b.b);
}

bool intersection(const line &a, const line_segment &b) {
    if(internal::sgn(det(b.a - a.a, a.b)) * internal::sgn(det(b.b - a.a, a.b)) < 0) {
        return true;
    }
    else {
        return false;
    }
}

long double distance(const line_segment &a, const point &c) {
    if(internal::sgn(dot(a.b - a.a, c - a.a)) < 0) {
        return abs(c-a.a);
    }
    else if(internal::sgn(dot(a.a - a.b, c - a.b)) < 0) {
        return abs(c-a.b);
    }
    else {
        return std::abs(det(c - a.a, a.b - a.a)/abs(a.b-a.a));
    }
}

long double distance(const line_segment &a, const line_segment &b) {
    if(intersection(a, b)) {
        return 0;
    }
    else {
        return std::min(std::min(distance(a, b.a), distance(a, b.b)), std::min(distance(b, a.a), distance(b, a.b)));
    }
}

long double distance(const line &a, const line_segment &b) {
    if(intersection(a, b)) {
        return 0;
    }
    else {
        return std::min(distance(a, b.a), distance(a, b.b));
    }
}

}