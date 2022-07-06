#pragma once

#include <cmath>
#include <cassert>

#include "point.hpp"
#include "line.hpp"

namespace ebi {

struct line_segment {
    point a, b;

    line_segment() = default;

    line_segment(long double x1, long double y1, long double x2, long double y2) : a(x1, y1), b(x2, y2) { }

    line_segment(const point &a, const point &b) : a(a), b(b) { }
};

// 線分ab, cd が交わるか判定
bool intersection_line_segment(const point &a, const point &b, const point &c, const point &d) {
    if(internal::sgn(isp(a,b,c)*isp(a,b,d)) <= 0 && internal::sgn(isp(c,d,a)*isp(c,d,b)) <= 0) {
        return true;
    }
    return false;
}

// 線分ab, cd が交わるか判定
bool intersection(const line_segment &a, const line_segment &b) {
    return intersection_line_segment(a.a, a.b, b.a, b.b);
}

bool intersection(const line &a, const line_segment &b) {
    if(internal::sgn(det(a.b - a.a, b.a - a.a)) * internal::sgn(det(a.b - a.a, b.b - a.a)) < 0) {
        return true;
    }
    else {
        return false;
    }
}

point cross_point(const line_segment &s, const line_segment &t) {
    assert(intersection(s, t));
    return s.a + (s.b - s.a) * det(t.a - s.a, t.b - t.a) / det(s.b - s.a, t.b - t.a);
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