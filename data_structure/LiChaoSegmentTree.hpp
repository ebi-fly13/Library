#pragma once

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

namespace ebi {

template <class T> struct line {
    T a, b;
    line(T a = 0, T b = 0) : a(a), b(b) {}
};

template <class T> struct LiChaoSegmentTree {
  private:
    std::vector<line<T>> data;
    std::vector<T> x;
    int n;

    T f(line<T> y, int i) {
        return y.a * x[i] + y.b;
    }

    void swap(line<T> &a, line<T> &b) {
        line<T> c = a;
        a = b;
        b = c;
    }

  public:
    LiChaoSegmentTree(std::vector<T> _x) : n(1) {
        int _n = _x.size();
        while (n < _n) {
            n <<= 1;
        }
        x.assign(n, _x[_n - 1]);
        for (int i = 0; i < _n; i++) {
            x[i] = _x[i];
        }
        T tmax = std::numeric_limits<T>::max();
        data.assign(2 * n - 1, line<T>(0, tmax));
    }

    void add_line(line<T> y, int l = 0, int r = -1, int index = 0) {
        if (r < 0) r = n;
        bool left = (f(y, l) < f(data[index], l));
        bool mid = (f(y, (l + r) / 2) < f(data[index], (l + r) / 2));
        bool right = (f(y, r - 1) < f(data[index], r - 1));
        if (left && right) {
            data[index] = y;
            return;
        }
        if (!(left || right)) {
            return;
        }
        if (mid) {
            swap(y, data[index]);
            left = !left;
            right = !right;
        }
        if (left) {
            add_line(y, l, (l + r) / 2, 2 * index + 1);
        } else {
            add_line(y, (l + r) / 2, r, 2 * index + 2);
        }
    }

    void add_segment(line<T> y, int lx, int rx, int l = 0, int r = -1,
                     int index = 0) {
        assert(lx <= rx);
        assert(0 <= lx);
        assert(rx <= n);
        if (r < 0) r = n;
        if (r <= lx || rx <= l) {
            return;
        }
        if (lx <= l && r <= rx) {
            add_line(y, l, r, index);
            return;
        }
        add_segment(y, lx, rx, l, (l + r) / 2, 2 * index + 1);
        add_segment(y, lx, rx, (l + r) / 2, r, 2 * index + 2);
    }

    T get(int i) {
        int k = i + n - 1;
        T val = f(data[k], i);
        while (k > 0) {
            k = (k - 1) / 2;
            val = std::min(val, f(data[k], i));
        }
        return val;
    }
};

}  // namespace ebi