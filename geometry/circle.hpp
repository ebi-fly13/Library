#pragma once

#include <vector>
#include <cmath>

#include "point.hpp"
#include "line.hpp"

namespace ebi {

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

}