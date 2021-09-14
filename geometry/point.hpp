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

    point operator-() const noexcept {
        return point(0, 0) - *this;
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

    // arctan(y/x) (単位はラジアン)
    long double arg() const {
        return std::atan2(y, x);
    }

    // x昇順, その後y昇順
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

int isp(const point &a, const point &b, const point &c) {
    int flag = internal::sgn(det(b-a,c-a));
    if(flag == 0) {
        if(internal::sgn(dot(b-a, c-a))<0) return -2;
        if(internal::sgn(dot(a-b, c-b))<0) return +2;
    }
    return flag;
}

bool intersection_line_segment(const point &a, const point &b, const point &c, const point &d) {
    if(isp(a,b,c)*isp(a,b,d) <= 0 && isp(c,d,a)*isp(c,d,b) <= 0) {
        return true;
    }
    return false;
}

}