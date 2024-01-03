#pragma once

#include <algorithm>
#include <cassert>
#include <ranges>
#include <vector>

namespace ebi {

namespace internal {

template <class F>
void centroid_decomposition_dfs_0(const std::vector<int> &par,
                                  const std::vector<int> &origin_vs, F f) {
    const int n = (int)par.size();
    assert(par.size() == origin_vs.size());
    int center = -1;
    std::vector<int> sz(n, 1);
    for (auto v : std::views::iota(0, n) | std::views::reverse) {
        if (sz[v] >= (n + 1) / 2) {
            center = v;
            break;
        }
        sz[par[v]] += sz[v];
    }
    std::vector<int> color(n, -1);
    std::vector<int> vs = {center};
    color[center] = 0;
    int c = 1;
    for (int v : std::views::iota(1, n)) {
        if (par[v] == center) {
            vs.emplace_back(v);
            color[v] = c++;
        }
    }
    if (center > 0) {
        for (int v = par[center]; v != -1; v = par[v]) {
            vs.emplace_back(v);
            color[v] = c;
        }
        c++;
    }
    for (int v : std::views::iota(0, n)) {
        if (color[v] == -1) {
            vs.emplace_back(v);
            color[v] = color[par[v]];
        }
    }
    std::vector<int> index_ptr(c + 1, 0);
    for (int v : std::views::iota(0, n)) {
        index_ptr[color[v] + 1]++;
    }
    for (int i : std::views::iota(0, c)) {
        index_ptr[i + 1] += index_ptr[i];
    }
    auto counter = index_ptr;
    std::vector<int> ord(n);
    for (auto v : vs) {
        ord[counter[color[v]]++] = v;
    }
    std::vector<int> relabel(n);
    for (int v : std::views::iota(0, n)) {
        relabel[ord[v]] = v;
    }
    std::vector<int> origin_vs2(n);
    for (int v : std::views::iota(0, n)) {
        origin_vs2[relabel[v]] = origin_vs[v];
    }
    std::vector<int> relabel_par(n, -1);
    for (int v : std::views::iota(1, n)) {
        int a = relabel[v];
        int b = relabel[par[v]];
        if (a > b) std::swap(a, b);
        relabel_par[b] = a;
    }
    f(relabel_par, origin_vs2, index_ptr);
    for (int i : std::views::iota(1, c)) {
        int l = index_ptr[i], r = index_ptr[i + 1];
        std::vector<int> par1(r - l, -1);
        std::vector<int> origin_vs1(r - l, -1);
        for (int v : std::views::iota(l, r)) {
            par1[v - l] = (relabel_par[v] == 0 ? -1 : relabel_par[v] - l);
            origin_vs1[v - l] = origin_vs2[v];
        }
        centroid_decomposition_dfs_0(par1, origin_vs1, f);
    }
    return;
}

template <class F>
void centroid_decomposition_dfs_1(const std::vector<int> &par,
                                  const std::vector<int> &bfs_order, F f) {}

template <class F>
void one_third_centroid_decomposition(const std::vector<int> &par,
                                      const std::vector<int> &bfs_order, F f) {}

}  // namespace internal

template <int MODE, class F>
void centroid_decomposition(const std::vector<std::vector<int>> &tree, F f) {
    int n = (int)tree.size();
    if (n == 1) return;
    std::vector<int> bfs_order(n), par(n, -1);
    bfs_order[0] = 0;
    int l = 0, r = 1;
    while (l < r) {
        int v = bfs_order[l++];
        for (auto nv : tree[v]) {
            if (nv == par[v]) continue;
            bfs_order[r++] = nv;
            par[nv] = v;
        }
    }
    assert(l == n && r == n);
    {
        std::vector<int> relabel(n);
        for (int i : std::views::iota(0, n)) {
            relabel[bfs_order[i]] = i;
        }
        std::vector<int> relabel_par(n, -1);
        for (int i : std::views::iota(1, n)) {
            relabel_par[relabel[i]] = relabel[par[i]];
        }
        std::swap(par, relabel_par);
    }
    static_assert(MODE == 0 || MODE == 1 || MODE == 2);
    if constexpr (MODE == 0) {
        internal::centroid_decomposition_dfs_0(par, bfs_order, f);
    } else if constexpr (MODE == 1) {
    } else {
        internal::one_third_centroid_decomposition(par, bfs_order, f);
    }
}

}  // namespace ebi