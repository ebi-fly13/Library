#pragma once

#include <array>
#include <tuple>
#include <vector>

#include "../data_structure/compress.hpp"
#include "../data_structure/fenwick_tree.hpp"

namespace ebi {

template <class S, class T> struct static_rectangle_sum {
  private:
  public:
    static_rectangle_sum() = default;

    void add_point(S x, S y, T val) {
        p.emplace_back(x, y, val);
        cp_x.add(x);
        cp_y.add(y);
    }

    void add_query(S l, S d, S r, S u) {
        q.push_back({l, d, r, u});
        cp_x.add(l);
        cp_x.add(r);
        cp_y.add(d);
        cp_y.add(u);
    }

    std::vector<T> run() {
        assert(is_first);
        is_first = false;
        cp_x.build();
        cp_y.build();
        std::vector ptable(cp_x.size(), std::vector<int>());
        std::vector qtable(cp_x.size(), std::vector(2, std::vector<int>()));
        for (int i = 0; auto [x, y, val] : p) {
            ptable[cp_x.get(x)].emplace_back(i);
            i++;
        }
        for (int i = 0; auto [l, d, r, u] : q) {
            qtable[cp_x.get(l)][0].emplace_back(i);
            qtable[cp_x.get(r)][1].emplace_back(i);
            i++;
        }
        std::vector<T> res(q.size(), 0);
        fenwick_tree<T> ftree(cp_y.size());
        for (int i = 0; i < cp_x.size(); i++) {
            for (int j = 0; j < 2; j++) {
                for (auto idx : qtable[i][j]) {
                    int d = q[idx][1], u = q[idx][3];
                    res[idx] +=
                        (j == 0 ? -1 : 1) * ftree.sum(cp_y.get(d), cp_y.get(u));
                }
            }
            for (auto idx : ptable[i]) {
                auto [x, y, val] = p[idx];
                ftree.add(cp_y.get(y), val);
            }
        }
        return res;
    }

  private:
    bool is_first = true;
    std::vector<std::tuple<S, S, T>> p;
    std::vector<std::array<S, 4>> q;
    compress<S> cp_x, cp_y;
};

}  // namespace ebi