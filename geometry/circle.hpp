#pragma once

#include <vector>
#include <cmath>

#include "point.hpp"
#include "line.hpp"
#include "line_segment.hpp"
#include "polygon.hpp"

namespace ebi {

const long double PI = std::acos(-1);

struct circle {
    point c;
    long double r;
    circle() = default;
    circle(const point &c, long double r) : c(c), r(r) { } 
};

int intersection(const circle &c1, const circle &c2) {
    long double d = abs(c1.c - c2.c);
    long double r1 = c1.r, r2 = c2.r;
    if(r1 < r2) std::swap(r1, r2); 
    if(d > internal::add(r1, r2)) {
        return 4;
    }
    else if(d == internal::add(r1, r2)) {
        return 3;
    }
    else if(d > internal::add(r1, -r2)) {
        return 2;
    }
    else if(d == internal::add(r1, -r2)) {
        return 1;
    }
    else {
        return 0;
    }
}

circle incircle_of_triangle(const point &A, const point &B, const point &C) {
    long double a = abs(B-C), b = abs(C-A), c = abs(A-B);
    point in = A * a + B * b + C * c;
    in /= (a + b + c);
    long double r = distance(line(A, B), in);
    return circle(in, r);
}

circle circumscribed_circle_of_triangle(const point &A, const point &B, const point &C) {
    line p((A+B)/2, (A+B)/2+rot90(B-A));
    line q((B+C)/2, (B+C)/2+rot90(C-B));
    point cross = cross_point(p, q);
    return circle(cross, abs(A-cross));
}

std::vector<point> cross_point(const circle &c, const line &l) {
    std::vector<point> ps;
    long double d = distance(l, c.c);
    if(d == c.r) {
        ps.emplace_back(l.proj(c.c));
    }
    else if(d < c.r) {
        point p = l.proj(c.c);
        point v = l.b - l.a;
        v = v*std::sqrt(std::max(internal::add(c.r * c.r, -d * d) , (long double)0)) / v.abs(); 
        ps.emplace_back(p + v);
        ps.emplace_back(p - v);
    }
    return ps;
}

std::vector<point> cross_point(const circle &c1, const circle &c2) {
    std::vector<point> ps;
    int flag = intersection(c1, c2);
    if(flag == 0 || flag == 4) {
        return ps;
    }
    long double d = (c2.c - c1.c).abs();
    long double x = internal::add(internal::add(d*d, c1.r*c1.r),-c2.r * c2.r) / (2.0*d);
    point p = c1.c + (c2.c - c1.c) * x / d;
    point v = rot90(c2.c - c1.c);
    if(flag == 1 || flag == 3) {
        ps.emplace_back(p);
    }
    else {
        v = v * std::sqrt(std::max(internal::add(c1.r * c1.r, -x * x) , (long double)0)) / v.abs(); 
        ps.emplace_back(p + v);
        ps.emplace_back(p - v);
    }
    return ps;
}

std::vector<point> cross_point(const circle &c, const line_segment &ls) {
    std::vector<point> ps = cross_point(c, line(ls.a, ls.b));
    std::vector<point> ret;
    for(auto p: ps) {
        if(internal::sgn(distance(ls, p)) == 0) {
            ret.emplace_back(p);
        }
    }
    return ret;
}

std::vector<point> tangent_to_circle(const circle &c, const point &p) {
    std::vector<point> ps;
    point v = p - c.c;
    long double d = v.abs();
    long double h = std::sqrt(std::max(internal::add(norm(v), -c.r * c.r), (long double)(0.0)));
    long double cos = c.r / d, sin = h / d;
    point f(internal::add(v.x * cos , - v.y * sin), internal::add(v.x * sin, v.y * cos));
    point g(internal::add(v.x * cos, v.y * sin), internal::add(- v.x * sin, v.y * cos));
    f = f * c.r / f.abs();
    g = g * c.r / g.abs();
    ps.emplace_back(c.c + f);
    ps.emplace_back(c.c + g);
    return ps;
}

std::vector<line> tangent(circle c1, circle c2) {
    std::vector<line> ret;
    int flag = intersection(c1, c2);
    if(flag == 2 || flag == 3 || flag == 4) {
        if(c1.r == c2.r) {
            point v = c2.c - c1.c;
            v = rot90(v * c1.r / abs(v));
            ret.emplace_back(line(c1.c + v, c2.c + v));
            ret.emplace_back(line(c1.c - v, c2.c - v));
        }
        else {
            point v = c1.c * (-c2.r) + c2.c * c1.r;
            v = v / (c1.r - c2.r);
            auto bs = tangent_to_circle(c1, v);
            auto as = tangent_to_circle(c2, v);
            for(int i = 0; i < (int)std::min(bs.size(), as.size()); i++) {
                ret.emplace_back(line(bs[i], as[i]));
            }
        }
    }
    else if(flag == 1) {
        point v = c2.c - c1.c;
        if(c1.r > c2.r) v = v * c1.r / v.abs();
        else v = v * (-c1.r) / v.abs();
        point p = c1.c + v;
        ret.emplace_back(line(p, p + rot90(v)));
    }
    if(flag == 4) {
        point p = c1.c * c2.r + c2.c * c1.r;
        p = p / (c1.r + c2.r);
        auto bs = tangent_to_circle(c1, p);
        auto as = tangent_to_circle(c2, p);
        for(int i = 0; i < (int)std::min(bs.size(), as.size()); i++) {
            ret.emplace_back(line(bs[i], as[i]));
        }
    }
    else if(flag == 3) {
        point v = c2.c - c1.c;
        v = v * c1.r / v.abs();
        point p = c1.c + v;
        ret.emplace_back(p, p + rot90(v));
    }
    return ret;
}

long double calc_common_area(const circle &c, const Polygon &poly) {
    if(int(poly.size()) < 3) return 0.0;
    long double s = 0;
    int n = poly.size();
    auto cross_area = [&](auto &&self, const point &a, const point b) -> long double {
        point va = c.c - a, vb = c.c - b;
        long double f = det(va, vb)/2.0, ret = 0.0;
        if(internal::sgn(f) == 0) return 0.0;
        if(std::max(va.abs(), vb.abs()) < c.r + EPS) return f;
        if(internal::sgn(internal::add(distance(line_segment(a, b), c.c), -c.r)) >= 0) {
            return c.r * c.r * (vb * conj(va)).arg() / 2.0;
        }
        auto ps = cross_point(c, line_segment(a, b));
        if(int(ps.size()) == 1) ps.emplace_back(ps.back());
        std::vector<point> tot = {a, ps[0], ps[1], b};
        std::sort(tot.begin(), tot.end());
        if(b < a) {
            std::reverse(tot.begin(), tot.end());
        }
        int sz = tot.size();
        for(int i = 0; i+1 < sz; i++) {
            ret += self(self, tot[i], tot[i+1]);
        }
        return ret;
    };
    for(int i = 0; i < n; i++) {
        s += cross_area(cross_area, poly[i], poly[(i+1 < n) ? i+1 : 0]);
    }
    return s;
}

long double common_area(const circle &c1, const circle &c2) {
    int flag = intersection(c1, c2);
    if(flag == 3 || flag == 4) return 0.0;
    else if(flag == 0 || flag == 1) {
        long double r = std::min(c1.r, c2.r);
        return PI * r * r;
    }
    else {
        long double d = (c1.c - c2.c).abs();
        long double theta1 = std::acos(internal::add(internal::add(c1.r*c1.r, d*d), -c2.r*c2.r)/(2.0*c1.r*d));
        long double area1 = internal::add(c1.r * c1.r * theta1, - c1.r * c1.r * std::sin(theta1*2)/2.0);
        long double theta2 = std::acos(internal::add(internal::add(c2.r*c2.r, d*d), -c1.r*c1.r)/(2.0*c2.r*d));
        long double area2 = internal::add(c2.r * c2.r * theta2, - c2.r * c2.r * std::sin(theta2*2)/2.0);
        return internal::add(area1, area2);
    }
}

}