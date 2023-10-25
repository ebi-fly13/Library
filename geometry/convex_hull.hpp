#pragma once

#include <algorithm>
#include <vector>

/*
    reference: プログラミングコンテストチャレンジブック 第2版 p234
    verify:    https://atcoder.jp/contests/typical90/submissions/24974484
*/

namespace ebi {

template <class T> struct Point {
    T x, y;

    Point &operator+=(const Point &rhs) noexcept {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Point &operator-=(const Point &rhs) noexcept {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Point operator-(const Point &rhs) const noexcept {
        return Point(*this) -= rhs;
    }

    T det(const Point &rhs) const noexcept {
        return x * rhs.y - y * rhs.x;
    }
};

template <class T>
std::vector<Point<T>> convex_hull(int n, std::vector<Point<T>> p,
                                  bool on = false) {
    std::sort(p.begin(), p.end(), [](const Point<T> &a, const Point<T> &b) {
        return a.x != b.x ? a.x < b.x : a.y < b.y;
    });
    std::vector<Point<T>> g1, g2;
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n; i++) {
        while (k1 > 1 &&
               (g1[k1 - 1] - g1[k1 - 2]).det(p[i] - g1[k1 - 1]) <= 0) {
            if (on && (g1[k1 - 1] - g1[k1 - 2]).det(p[i] - g1[k1 - 1]) == 0)
                break;
            g1.pop_back();
            k1--;
        }
        while (k2 > 1 &&
               (g2[k2 - 1] - g2[k2 - 2]).det(p[i] - g2[k2 - 1]) >= 0) {
            if (on && (g2[k2 - 1] - g2[k2 - 2]).det(p[i] - g2[k2 - 1]) == 0)
                break;
            g2.pop_back();
            k2--;
        }
        g1.push_back(p[i]);
        k1++;
        g2.push_back(p[i]);
        k2++;
    }
    std::vector<Point<T>> ch(k1 + k2 - 2);
    for (int i = 0; i < k1; i++) {
        ch[i] = g1[i];
    }
    for (int i = k2 - 2; i > 0; i--) {
        ch[k1 + k2 - i - 2] = g2[i];
    }
    return ch;
}

}  // namespace ebi