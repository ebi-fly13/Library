#pragma once

#include <cassert>
#include <vector>

namespace ebi {

template <class S, S (*op)(S, S), S (*e)(), class data_structure>
struct segtree_2d {
  private:
  public:
    segtree_2d(int h, int w) : h(h), w(w), sz(1) {
        while (sz < h) sz <<= 1;
        data = std::vector<data_structure>(2 * sz, data_structure(w));
    }

    void set(int i, int j, S x) {
        assert(0 <= i && i < h && 0 <= j && j < w);
        i += sz;
        data[i].set(j, x);
        while (i > 1) {
            i >>= 1;
            S val = op(data[2 * i].get(j), data[2 * i + 1].get(j));
            data[i].set(j, val);
        }
    }

    S get(int i, int j) const {
        assert(0 <= i && i < h && 0 <= j && j < w);
        return data[i + sz].get(j);
    }

    S prod(int l, int d, int r, int u) const {
        assert(0 <= l && l <= r && r <= h);
        assert(0 <= d && d <= u && u <= w);
        l += sz;
        r += sz;
        S res = e();
        while (l < r) {
            if (l & 1) res = op(res, data[l++].prod(d, u));
            if (r & 1) res = op(data[--r].prod(d, u), res);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

  private:
    int h, w;
    int sz;
    std::vector<data_structure> data;
};

}  // namespace ebi