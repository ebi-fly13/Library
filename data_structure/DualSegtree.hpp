#pragma once

#include <cassert>
#include <vector>

namespace ebi {

template <class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
struct DualSegtree {
  public:
    DualSegtree(int n) : n(n) {
        size = 1;
        while (size < n) size <<= 1;
        data.assign(2 * size, e());
    }

    DualSegtree(const std::vector<Monoid> &vec) : n(vec.size()) {
        size = 1;
        while (size < n) size <<= 1;
        data.assign(2 * size, e());
        std::copy(vec.begin(), vec.end(), data.begin() + size);
    }

    Monoid get(int idx) const {
        assert(0 <= idx && idx < n);
        idx += size;
        Monoid val = e();
        while (idx > 0) {
            val = op(val, data[idx]);
            idx >>= 1;
        }
        return val;
    }

    void apply(int l, int r, Monoid x) {
        assert(0 <= l && l <= r && r <= n);
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) {
                data[l] = op(data[l], x);
                l++;
            }
            if (r & 1) {
                r--;
                data[r] = op(data[r], x);
            }
            l >>= 1;
            r >>= 1;
        }
        return;
    }

  private:
    std::vector<Monoid> data;
    int n;
    int size;
};

}  // namespace ebi