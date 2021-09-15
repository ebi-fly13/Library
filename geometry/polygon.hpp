#pragma once

#include <cassert>
#include <vector>

#include "point.hpp"
#include "line.hpp"

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

int contains(const Polygon &poly, const point &p) {
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

long double convex_diameter(const Polygon &convex_poly) {
    int n = convex_poly.size();
    int is = 0, js = 0;
    for(int i = 1; i < n; i++) {
        if(convex_poly[i].y > convex_poly[is].y) is = i;
        if(convex_poly[i].y < convex_poly[js].y) js = i;
    }
    long double max = (convex_poly[is]-convex_poly[js]).abs();
    int i, max_i, j, max_j;
    i = max_i = is;
    j = max_j = js;
    do {
        if(det(convex_poly[(i+1 < n) ? i+1 : 0] - convex_poly[i], convex_poly[(j+1 < n) ? j+1 : 0] - convex_poly[j]) >= 0) {
            j = (j+1 < n) ? j+1 : 0;
        }
        else {
            i = (i+1 < n) ? i+1 : 0;
        }
        if((convex_poly[i] - convex_poly[j]).abs() > max) {
            max = (convex_poly[i] - convex_poly[j]).abs();
            max_i = i;
            max_j = j;
        }
    } while(i != is || j != js);
    return max;
}

Polygon convex_polygon_cut(const Polygon &poly, const line &l) {
    Polygon ret;
    int n = poly.size();
    for(int i = 0; i < n; i++) {
        const point &now = poly[i];
        const point &nxt = poly[(i+1 < n) ? i+1 : 0];
        long double cf = det(l.a - now, l.b - now);
        long double cs = det(l.a - nxt, l.b - nxt);
        if(internal::sgn(cf) >= 0) {
            ret.emplace_back(now);
        }
        if(internal::sgn(cf) * internal::sgn(cs) < 0) {
            ret.emplace_back(cross_point(line(now, nxt), l));
        }
    }
    return ret;
}

}