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

    template <class F> void merge_(int u, int v, int d, F f) {
        if (d == 0) {
            u = uf[0].leader(u);
            v = uf[0].leader(v);
            if (u == v) return;
            uf[0].merge(u, v);
            int leader = uf[0].leader(u);
            f(leader, u ^ v ^ leader);
            return;
        } else if (d > 0) {
            if (!uf[d].merge(u, v)) return;
            merge_(u, v, d - 1, f);
            merge_(u + (1 << (d - 1)), v + (1 << (d - 1)), d - 1, f);
        } else
            assert(0);
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

    template <class F> void merge(int u, int v, int w, F f) {
        if (u > v) std::swap(u, v);
        w = std::min(w, n - v);
        if (w == 0 || u == v) return;
        int lg2 = std::bit_width((unsigned int)w) - 1;
        merge_(u, v, lg2, f);
        merge_(u + w - (1 << lg2), v + w - (1 << lg2), lg2, f);
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