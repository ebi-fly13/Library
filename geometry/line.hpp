#pragma once

#include <cassert>
#include <cmath>

#include "point.hpp"

namespace ebi {

struct line {
    point a, b;

    line(long double x1, long double y1, long double x2, long double y2)
        : a(x1, y1), b(x2, y2) {}

    line(const point &a, const point &b) : a(a), b(b) {}

    point proj(const point &p) const {
        return a + (b - a) * (dot(b - a, p - a) / norm(b - a));
    }

    point relf(const point &p) const {
        return proj(p) * double(2) - p;
    }

    long double distance(const point &c) const {
        return std::abs(det(c - a, b - a) / abs(b - a));
    }
};

int intersection(const line &a, const line &b) {
    if (internal::sgn(det(a.b - a.a, b.a - b.b)) != 0) {
        if (internal::sgn(dot(a.b - a.a, b.b - b.a)) == 0) {  // 垂直
            return 1;
        }
        return 0;                                                // 交差
    } else if (internal::sgn(det(a.b - a.a, b.a - a.a)) != 0) {  // 平行
        return 2;
    } else {  // 同一直線
        return 3;
    }
}

point cross_point(const point &a, const point &b, const point &c,
                  const point &d) {
    return a + (b - a) * det(c - a, d - c) / det(b - a, d - c);
}

// 交点があるか確認する！
point cross_point(const line &s, const line &t) {
    assert(intersection(s, t) < 2);
    return s.a +
           (s.b - s.a) * det(t.a - s.a, t.b - t.a) / det(s.b - s.a, t.b - t.a);
}

// 直線aと点cの距離
long double distance(const line &a, const point &c) {
    return std::abs(det(c - a.a, a.b - a.a) / abs(a.b - a.a));
}

long double distance(const line &a, const line &b) {
    if (intersection(a, b) < 2) {
        return 0;
    } else {
        return distance(a, b.a);
    }
}

}  // namespace ebi