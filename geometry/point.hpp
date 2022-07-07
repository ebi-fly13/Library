#pragma once

#include <cstdint>
#include <cmath>
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

namespace ebi {

constexpr long double EPS = 1e-10;

const long double PI = std::acos(-1);

namespace internal {

int sgn(long double a) {
    return (a<-EPS) ? -1 : (a>EPS) ? 1 : 0;
}

long double add(long double a, long double b) {
    if(std::abs(a+b) < EPS*(std::abs(a) + std::abs(b))) return 0;
    return a+b;
}

} // namespace internal

long double arg_to_radian(long double arg) {
    return PI * arg / (long double)(180);
}

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

    point &operator*=(const point rhs) noexcept {
        long double _x = internal::add(x*rhs.x, -y*rhs.y);
        long double _y = internal::add(x*rhs.y, y*rhs.x);
        x = _x;
        y = _y;
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

    point operator*(const point &rhs) const noexcept {
        return point(*this) *= rhs;
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

    bool operator==(const point &rhs) const noexcept {
        if (internal::sgn(x - rhs.x) == 0 && internal::sgn(y - rhs.y) == 0)
            return true;
        else
            return false;
    }

    bool operator!=(const point &rhs) const noexcept {
        return !((*this) == rhs);
    }
};

std::ostream& operator<<(std::ostream& os, const point &a) {
    return os << a.x << " " << a.y;
}

std::istream& operator>>(std::istream& os, point &a) {
    return os >> a.x >> a.y;
}

point conj(const point &a) {
    return point(a.x, -a.y);
}

// 点a をang(ラジアン)回転する
point rot(const point &a, long double ang) {
    return point(std::cos(ang) * a.x - std::sin(ang) * a.y, std::sin(ang) * a.x + std::cos(ang) * a.y);
} 

point rot90(const point &a) {
    return point(-a.y, a.x);
}

long double dot(const point &a, const point &b) {
    return a.dot(b);
}

long double det(const point &a, const point &b) {
    return a.det(b);
}

long double abs(const point &a) {
    return a.abs();
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

// 分割統治で最近点対を求める O(N log N)
long double closest_pair(std::vector<point> p) {
    std::sort(p.begin(), p.end());
    int n = p.size();
    auto f = [&](auto &&self, int l, int r) -> long double {
        if(r-l == 1) {
            return 1e9;
        }
        int mid = (l+r)/2;
        long double x = p[mid].x;
        long double d = std::min(self(self, l, mid), self(self, mid, r));
        std::vector<point> b;
        b.reserve(r-l);
        int j = mid;
        for(int i = l; i < mid; i++) {
            while(j < r && p[j].y <= p[i].y) {
                b.emplace_back(p[j++]);
            }
            b.emplace_back(p[i]);
        }
        while(j < r) {
            b.emplace_back(p[j++]);
        }
        for(int i = 0; i < r-l; i++) {
            p[l+i] = b[i];
        }
        b.clear();
        for(int i = l; i < r; i++) {
            if(std::abs(p[i].x - x) >= d) continue;
            for(int j = int(b.size())-1; j >= 0; j--) {
                if(p[i].y - b[j].y >= d) break;
                d = std::min(d, abs(p[i]-b[j]));
            }
            b.emplace_back(p[i]);
        }
        return d;
    };
    return f(f, 0, n);
}

// ∠ABCを求める(ラジアン)
long double angle(const point &A, const point &B, const point &C) {
    long double a = (B - C).abs(), b = (C - A).abs(), c = (A - B).abs();
    long double cos = internal::add(internal::add(a*a, c*c), -b*b)/(2.0*c*a);
    return std::acos(cos);
}

// 符号付き
long double calc_ang(point a, point b, point c) {
    long double cos = dot((a-b), (c-b)) / (abs(a-b) * abs(c-b));
    long double sin = det((a-b), (c-b)) / (abs(a-b) * abs(c-b));
    return std::atan2(sin, cos);
}

void arg_sort(std::vector<point> &a) {
    int n = a.size();
    std::vector ps(4, std::vector<point>());
    auto idx = [](point v) -> int {
        if(v.y >= 0) return (v.x >= 0) ? 0 : 1;
        else return (v.x >= 0) ? 3 : 2;
    };
    for(auto p: a) {
        assert(!(p.x == 0 && p.y == 0));
        ps[idx(p)].emplace_back(p);
    }
    a.clear();
    a.reserve(n);
    for(int i = 0; i < 4; i++) {
        std::sort(ps[i].begin(), ps[i].end(), 
            [](point &p1, point &p2) -> bool {
                int flag = internal::sgn(internal::add(p1.x * p2.y, - p2.x * p1.y));
                return flag == 0 ? (norm(p1) < norm(p2)) : flag > 0;
            });
        for(auto &p: ps[i]) a.emplace_back(p);
    }
    return;
}

template<class T>
void arg_sort_ll(std::vector<std::pair<T , T>> &a) {
    using Point = std::pair<T, T>;
    int n = a.size();
    std::vector ps(4, std::vector<Point>());
    auto idx = [](Point v) -> int {
        if(v.second >= 0) return (v.first >= 0) ? 0 : 1;
        else return (v.first >= 0) ? 3 : 2;
    };
    for(auto p: a) {
        assert(!(p.first == 0 && p.second == 0));
        ps[idx(p)].emplace_back(p);
    }
    a.clear();
    a.reserve(n);
    for(int i = 0; i < 4; i++) {
        std::sort(ps[i].begin(), ps[i].end(), 
            [](Point &p1, Point &p2) -> bool { 
                T flag = p1.first * p2.second - p2.first * p1.second;
                return flag == 0 ? (p1.first * p1.first + p1.second * p1.second < p2.first * p2.first + p2.second * p2.second) : flag > 0;
            });
        for(auto &p: ps[i]) a.emplace_back(p);
    }
    return;
}

}