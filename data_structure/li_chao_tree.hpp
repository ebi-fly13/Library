#pragma once

#include <algorithm>
#include <cassert>
#include <limits>
#include <utility>
#include <vector>

namespace ebi {

template <class T> struct li_chao_tree {
  private:
    T f(std::pair<T, T> y, T x) const {
        return y.first * x + y.second;
    }

    void add(std::pair<T, T> y, int l, int r, int index) {
        bool left = f(y, xs[l]) < f(data[index], xs[l]);
        bool mid = f(y, xs[(l + r) / 2]) < f(data[index], xs[(l + r) / 2]);
        bool right = f(y, xs[r - 1]) < f(data[index], xs[r - 1]);
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
            add(y, l, (l + r) / 2, 2 * index);
        } else {
            add(y, (l + r) / 2, r, 2 * index + 1);
        }
    }

    int get_index(T x) const {
        auto itr = std::lower_bound(xs.begin(), xs.end(), x);
        // assert(*itr == x);
        return itr - xs.begin();
    }

  public:
    li_chao_tree(std::vector<T> &_x) : xs(_x), sz(1) {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        while (sz < int(xs.size())) sz <<= 1;
        while (int(xs.size()) < sz) xs.emplace_back(xs.back() + 1);
        data.assign(2 * sz, {0, std::numeric_limits<T>::max()});
    }

    void add_line(T a, T b) {
        add({a, b}, 0, sz, 1);
    }

    void add_segment(T a, T b, T lx, T rx) {
        int l = get_index(lx);
        int r = get_index(rx);
        assert(0 <= l && l <= r && r <= sz);
        int il = l + sz;
        int ir = r + sz;
        int rank = 0;
        while (il < ir) {
            if (il & 1) {
                add({a, b}, l, l + (1 << rank), il++);
                l += (1 << rank);
            }
            if (ir & 1) {
                add({a, b}, r - (1 << rank), r, --ir);
                r -= (1 << rank);
            }
            rank++;
            il >>= 1;
            ir >>= 1;
        }
    }

    T min(T x) {
        int k = get_index(x) + sz;
        T val = std::numeric_limits<T>::max();
        while (k > 0) {
            val = std::min(val, f(data[k], x));
            k >>= 1;
        }
        return val;
    }

  private:
    std::vector<std::pair<T, T>> data;
    std::vector<T> xs;
    int sz;
};

}  // namespace ebi