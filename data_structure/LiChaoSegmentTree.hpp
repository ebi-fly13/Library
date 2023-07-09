#pragma once

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

namespace ebi {

template <class T> struct LiChaoSegmentTree {
  private:
    std::vector<std::pair<T, T>> data;
    std::vector<T> x;
    int n;

    T f(std::pair<T, T> y, int i) {
        return y.first * x[i] + y.second;
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
        data.assign(2 * n, {0, std::numeric_limits<T>::max()});
    }

    void add_line(std::pair<T, T> y, int l = 0, int r = -1, int index = 1) {
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
            std::swap(y, data[index]);
            left = !left;
            right = !right;
        }
        if (left) {
            add_line(y, l, (l + r) / 2, 2 * index);
        } else {
            add_line(y, (l + r) / 2, r, 2 * index + 1);
        }
    }

    void add_segment(std::pair<T, T> y, int lx, int rx, int l = 0, int r = -1,
                     int index = 1) {
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
        add_segment(y, lx, rx, l, (l + r) / 2, 2 * index);
        add_segment(y, lx, rx, (l + r) / 2, r, 2 * index + 1);
    }

    T get(int i) {
        int k = i + n;
        T val = std::numeric_limits<T>::max();
        while (k > 0) {
            val = std::min(val, f(data[k], i));
            k >>= 1;
        }
        return val;
    }
};

}  // namespace ebi