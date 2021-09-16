#pragma once

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

}