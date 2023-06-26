#pragma once

#include <algorithm>
#include <vector>

/*
    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937
    verify   : http://codeforces.com/contest/893/submission/125531718
*/

#include "../data_structure/compress.hpp"

namespace ebi {

template <class S, S (*op)(S, S), S (*e)(), class data_structure>
struct offline_segtree_2d {
    offline_segtree_2d() = default;

    void pre_set(std::pair<int, int> p) {
        ps.emplace_back(p);
    }

    void build() {
        for (auto [x, y] : ps) {
            xs.add(x);
        }
        xs.build();
        while (sz < xs.size()) sz <<= 1;
        ys.resize(2 * sz);
        for (auto [x, y] : ps) {
            int i = xs.get(x) + sz;
            ys[i].add(y);
            while (i > 1) {
                i >>= 1;
                ys[i].add(y);
            }
        }
        for (int i = 0; i < 2 * sz; i++) {
            ys[i].build();
            data.emplace_back(data_structure(ys[i].size()));
        }
    }

    void set(int i, int j, S val) {
        i = xs.get(i);
        i += sz;
        data[i].set(ys[i].get(j), val);
        while (i > 1) {
            i >>= 1;
            S res = e();
            if (ys[2 * i].find(j)) {
                res = op(res, data[2 * i].get(ys[2 * i].get(j)));
            }
            if (ys[2 * i + 1].find(j)) {
                res = op(res, data[2 * i + 1].get(ys[2 * i + 1].get(j)));
            }
            data[i].set(ys[i].get(j), res);
        }
    }

    S get(int i, int j) const {
        i = xs.get(i) + sz;
        return data[i].get(ys[i].get(j));
    }

    S prod(int l, int d, int r, int u) const {
        l = xs.get(l) + sz;
        r = xs.get(r) + sz;
        S res = e();
        while (l < r) {
            if (l & 1) {
                res = op(res, data[l].prod(ys[l].get(d), ys[l].get(u)));
                l++;
            }
            if (r & 1) {
                r--;
                res = op(data[r].prod(ys[r].get(d), ys[r].get(u)), res);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

  private:
    int sz = 1;
    std::vector<std::pair<int, int>> ps;
    compress<int> xs;
    std::vector<compress<int>> ys;
    std::vector<data_structure> data;
};

}  // namespace ebi