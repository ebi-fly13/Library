#pragma once

#include <cmath>
#include <cassert>

namespace ebi {

constexpr long double EPS = 1e-10;

namespace internal {

int sgn(long double a) {
    return (a<-EPS) ? -1 : (a>EPS) ? 1 : 0;
}

double add(long double a, long double b) {
    if(std::abs(a+b) < EPS*(std::abs(a) + std::abs(b))) return 0;
    return a+b;
}

} // namespace internal

struct point {
    long double x,y;

    point() = default;

    point(long double x, long double y) : x(x), y(y) { }

    point &operator+=(const point rhs) noexcept {
        x = internal::add(x, rhs.x);
        y = internal::add(y, rhs.y);
        return *this;
    }

    point &operator-=(const point rhs) noexcept {
        x = internal::add(x, -rhs.x);
        y = internal::add(y, -rhs.y);
        return *this;
    }

    point &operator*=(const long double k) noexcept {
        x *= k;
        y *= k;
        return *this;
    }

    point &operator/=(const long double k) {
        assert(internal::sgn(k)!=0);
        x /= k;
        y /= k;
        return *this;
    }

    point operator+(const point &rhs) const noexcept {
        return point(*this) += rhs;
    }

    point operator-(const point &rhs) const noexcept {
        return point(*this) -= rhs;
    }

    point operator*(const long double rhs) const noexcept {
        return point(*this) *= rhs;
    }

    point operator/(const long double rhs) const {
        return point(*this) /= rhs;
    }

    long double abs() const noexcept {
        return std::sqrt(internal::add(x*x, y*y));
    }

    long double dot(const point rhs) const noexcept {
        return internal::add(x*rhs.x, y*rhs.y);
    }

    long double det(const point rhs) const noexcept {
        return internal::add(x*rhs.y, -y*rhs.x);
    }

    bool operator<(const point &rhs) const noexcept {
        if(internal::sgn(x-rhs.x)) return internal::sgn(x-rhs.x)<0;
        return internal::sgn(y-rhs.y)<0;
    }
};

long double dot(const point &a, const point &b) {
    return a.dot(b);
}

long double det(const point &a, const point &b) {
    return a.det(b);
}

long double norm(const point &a) {
    return internal::add(a.x*a.x, a.y*a.y);
}

struct line {
    point a,b;

    line(long double x1, long double y1, long double x2, long double y2) : a(x1, y1), b(x2, y2) { }

    point proj(const point &p) {
        return a + (b-a)*(dot(b-a,p-a)/norm(b-a));
    }

    point relf(const point &p) {
        return proj(p)*double(2) - p;
    }
};

}