#pragma once

#include <bit>
#include <utility>
#include <vector>

#include "../data_structure/compress.hpp"
#include "../data_structure/dual_segtree.hpp"

namespace ebi {

template <class F, F (*merge)(F, F), F (*id)()> struct offline_dual_segtree_2d {
    offline_dual_segtree_2d() = default;

    void pre_set(std::pair<int, int> p) {
        ps.emplace_back(p);
    }

    void build() {
        for (auto [x, y] : ps) {
            xs.add(x);
        }
        xs.build();
        sz = std::bit_ceil((unsigned int)xs.size());
        ys.resize(2 * sz);
        for (auto [x, y] : ps) {
            int i = xs.get(x) + sz;
            ys[i].add(y);
            while (i > 1) {
                i >>= 1;
                ys[i].add(y);
            }
        }
        for (auto i : std::views::iota(0, 2 * sz)) {
            ys[i].build();
            seg.emplace_back(dual_segtree<F, merge, id>(ys[i].size()));
        }
    }

    F get(int i, int j) {
        i = xs.get(i) + sz;
        F x = seg[i].get(ys[i].get(j));
        while (i > 1) {
            i >>= 1;
            x = merge(x, seg[i].get(ys[i].get(j)));
        }
        return x;
    }

    void apply(int l, int d, int r, int u, F f) {
        l = xs.get(l) + sz;
        r = xs.get(r) + sz;
        while (l < r) {
            if (l & 1) {
                seg[l].apply(ys[l].get(d), ys[l].get(u), f);
                l++;
            }
            if (r & 1) {
                r--;
                seg[r].apply(ys[r].get(d), ys[r].get(u), f);
            }
            l >>= 1;
            r >>= 1;
        }
    }

  private:
    int sz = 1;
    std::vector<std::pair<int, int>> ps;
    compress<int> xs;
    std::vector<compress<int>> ys;
    std::vector<dual_segtree<F, merge, id>> seg;
};

}  // namespace ebi