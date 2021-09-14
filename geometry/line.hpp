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

int intersection(const line &a, const line &b) {
    if(det(a.b-a.a, b.a-b.b) != 0) {
        if(dot(a.b-a.a, b.b-b.a) == 0) { // 垂直
            return 1;
        }
        return 0; // 交差
    }
    else if(det(a.b-a.a, b.a-a.a) != 0) { // 平行
        return 2;
    }
    else { // 同一直線
        return 3;
    }
}

// 交点があるか確認する！
point cross_point(const line &s, const line &t) {
    assert(intersection(s, t) < 2);
    return s.a + (s.b - s.a) * det(t.a - s.a, t.b - t.a) / det(s.b - s.a, t.b - t.a);
}

}