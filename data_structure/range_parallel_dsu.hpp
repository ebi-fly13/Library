#pragma once

#include <bit>
#include <cassert>
#include <vector>

#include "../data_structure/dsu.hpp"

namespace ebi {

struct range_parallel_dsu {
  private:
    void merge_(int u, int v, int d) {
        if (uf[d].same(u, v)) return;
        uf[d].merge(u, v);
        if (d > 0) {
            merge_(u, v, d - 1);
            merge_(u + (1 << (d - 1)), v + (1 << (d - 1)), d - 1);
        }
    }

  public:
    range_parallel_dsu(int n_)
        : n(n_), uf(std::bit_width((unsigned int)n), dsu(n)) {}

    void merge(int u, int v, int w) {
        if (u > v) std::swap(u, v);
        w = std::min(w, n - v);
        if (w == 0 || u == v) return;
        int lg2 = std::bit_width((unsigned int)w) - 1;
        merge_(u, v, lg2);
        merge_(u + w - (1 << lg2), v + w - (1 << lg2), lg2);
    }

    bool same(int u, int v) {
        return uf[0].same(u, v);
    }

    int size(int u) {
        return uf[0].size(u);
    }

    int leader(int u) {
        return uf[0].leader(u);
    }

    std::vector<std::vector<int>> groups() {
        return uf[0].groups();
    }

    int count_group() {
        return uf[0].count_group();
    }

  private:
    int n;
    std::vector<dsu> uf;
};

}  // namespace ebi