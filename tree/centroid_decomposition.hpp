#pragma once

#include <algorithm>
#include <cassert>
#include <ranges>
#include <vector>

namespace ebi {

namespace internal {

template <class F>
void centroid_decomposition_dfs_naive(const std::vector<int> &par,
                                      const std::vector<int> &original_vs,
                                      F f) {
    const int n = (int)par.size();
    assert(par.size() == original_vs.size());
    int center = -1;
    std::vector<int> sz(n, 1);
    for (const int v : std::views::iota(0, n) | std::views::reverse) {
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
    for (const int v : std::views::iota(1, n)) {
        if (par[v] == center) {
            vs.emplace_back(v);
            color[v] = c++;
        }
    }
    if (center > 0) {
        for (const int v = par[center]; v != -1; v = par[v]) {
            vs.emplace_back(v);
            color[v] = c;
        }
        c++;
    }
    for (const int v : std::views::iota(0, n)) {
        if (color[v] == -1) {
            vs.emplace_back(v);
            color[v] = color[par[v]];
        }
    }
    std::vector<int> index_ptr(c + 1, 0);
    for (const int v : std::views::iota(0, n)) {
        index_ptr[color[v] + 1]++;
    }
    for (const int i : std::views::iota(0, c)) {
        index_ptr[i + 1] += index_ptr[i];
    }
    auto counter = index_ptr;
    std::vector<int> ord(n);
    for (auto v : vs) {
        ord[counter[color[v]]++] = v;
    }
    std::vector<int> relabel(n);
    for (const int v : std::views::iota(0, n)) {
        relabel[ord[v]] = v;
    }
    std::vector<int> original_vs2(n);
    for (const int v : std::views::iota(0, n)) {
        original_vs2[relabel[v]] = original_vs[v];
    }
    std::vector<int> relabel_par(n, -1);
    for (int v : std::views::iota(1, n)) {
        int a = relabel[v];
        int b = relabel[par[v]];
        if (a > b) std::swap(a, b);
        relabel_par[b] = a;
    }
    f(relabel_par, original_vs2, index_ptr);
    for (const int i : std::views::iota(1, c)) {
        int l = index_ptr[i], r = index_ptr[i + 1];
        std::vector<int> par1(r - l, -1);
        std::vector<int> original_vs1(r - l, -1);
        for (int v : std::views::iota(l, r)) {
            par1[v - l] = (relabel_par[v] == 0 ? -1 : relabel_par[v] - l);
            original_vs1[v - l] = original_vs2[v];
        }
        centroid_decomposition_dfs_naive(par1, original_vs1, f);
    }
    return;
}

template <class F>
void one_third_centroid_decomposition(const std::vector<int> &par,
                                      const std::vector<int> &original_vs,
                                      F f) {
    const int n = (int)par.size();
    assert(n > 1);
    if (n == 2) return;
    int center = -1;
    std::vector<int> sz(n, 1);

    for (const int v : std::views::iota(0, n) | std::views::reverse) {
        if (sz[v] >= (n + 1) / 2) {
            center = v;
            break;
        }
        sz[par[v]] += sz[v];
    }

    std::vector<int> color(n, -1);
    std::vector<int> ord(n, -1);
    ord[center] = 0;
    int t = 1;
    int red = n - sz[center];
    for (int v = par[center]; v != -1; v = par[v]) {
        ord[v] = t++;
        color[v] = 0;
    }
    for (const int v : std::views::iota(1, n)) {
        if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {
            red += sz[v];
            ord[v] = t++;
            color[v] = 0;
        }
    }
    for (const int v : std::views::iota(1, n)) {
        if (v != center && color[v] == -1 && color[par[v]] == 0) {
            ord[v] = t++;
            color[v] = 0;
        }
    }
    const int n0 = t - 1;
    for (const int v : std::views::iota(1, n)) {
        if (v != center && color[v] == -1) {
            ord[v] = t++;
            color[v] = 1;
        }
    }
    assert(t == n);
    const int n1 = n - 1 - n0;
    std::vector<int> par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);
    std::vector<int> original_vs0(n0 + 1), original_vs1(n1 + 1),
        original_vs2(n);
    for (const int i : std::views::iota(0, n)) {
        int v = ord[i];
        original_vs2[v] = original_vs[i];
        if (color[i] != 1) {
            original_vs0[v] = original_vs[i];
        }
        if (color[i] != 0) {
            int idx = std::max(v - n0, 0);
            original_vs1[idx] = original_vs[i];
        }
    }
    for (const int v : std::views::iota(1, n)) {
        int a = ord[v], b = ord[par[v]];
        if (a > b) std::swap(a, b);
        par2[b] = a;
        if (color[v] != 1 && color[par[v]] != 1) {
            par0[b] = a;
        }
        if (color[v] != 0 && color[par[v]] != 0) {
            par1[b - n0] = std::max(a - n0, 0);
        }
    }
    f(par2, original_vs2, n0, n1);
    one_third_centroid_decomposition(par0, original_vs0, f);
    one_third_centroid_decomposition(par1, original_vs1, f);
    return;
}

template <class F>
void one_third_centroid_decomposition_virtual_real(
    const std::vector<int> &par, const std::vector<int> &original_vs,
    const std::vector<int> &is_real, F f) {
    const int n = (int)par.size();
    assert(n > 1);
    if (n == 2) {
        if (is_real[0] && is_real[1]) {
            f(par, original_vs, {0, 1});
        }
        return;
    }
    int center = -1;
    std::vector<int> sz(n, 1);

    for (const int v : std::views::iota(0, n) | std::views::reverse) {
        if (sz[v] >= (n + 1) / 2) {
            center = v;
            break;
        }
        sz[par[v]] += sz[v];
    }

    std::vector<int> color(n, -1);
    std::vector<int> ord(n, -1);
    ord[center] = 0;
    int t = 1;
    int red = n - sz[center];
    for (int v = par[center]; v != -1; v = par[v]) {
        ord[v] = t++;
        color[v] = 0;
    }
    for (const int v : std::views::iota(1, n)) {
        if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {
            red += sz[v];
            ord[v] = t++;
            color[v] = 0;
        }
    }
    for (const int v : std::views::iota(1, n)) {
        if (v != center && color[v] == -1 && color[par[v]] == 0) {
            ord[v] = t++;
            color[v] = 0;
        }
    }
    const int n0 = t - 1;
    for (const int v : std::views::iota(1, n)) {
        if (v != center && color[v] == -1) {
            ord[v] = t++;
            color[v] = 1;
        }
    }
    assert(t == n);
    const int n1 = n - 1 - n0;
    std::vector<int> par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);
    std::vector<int> original_vs0(n0 + 1), original_vs1(n1 + 1),
        original_vs2(n);
    std::vector<int> is_real0(n0 + 1), is_real1(n1 + 1), is_real2(n);
    for (const int i : std::views::iota(0, n)) {
        int v = ord[i];
        original_vs2[v] = original_vs[i];
        is_real2[v] = is_real[i];
        if (color[i] != 1) {
            original_vs0[v] = original_vs[i];
            is_real0[v] = is_real[i];
        }
        if (color[i] != 0) {
            int idx = std::max(v - n0, 0);
            original_vs1[idx] = original_vs[i];
            is_real1[idx] = is_real[i];
        }
    }
    for (const int v : std::views::iota(1, n)) {
        int a = ord[v], b = ord[par[v]];
        if (a > b) std::swap(a, b);
        par2[b] = a;
        if (color[v] != 1 && color[par[v]] != 1) {
            par0[b] = a;
        }
        if (color[v] != 0 && color[par[v]] != 0) {
            par1[b - n0] = std::max(a - n0, 0);
        }
    }
    if (is_real[center]) {
        color.assign(n, -1);
        color[0] = 0;
        for (const int v : std::views::iota(1, n)) {
            if (is_real2[v]) color[v] = 1;
        }
        f(par2, original_vs2, color);
        is_real0[0] = is_real1[0] = is_real2[0] = 0;
    }
    color.assign(n, -1);
    for (const int v : std::views::iota(1, n)) {
        if (is_real2[v]) {
            color[v] = int(v > n0);
        }
    }
    f(par2, original_vs2, color);
    one_third_centroid_decomposition_virtual_real(par0, original_vs0, is_real0,
                                                  f);
    one_third_centroid_decomposition_virtual_real(par1, original_vs1, is_real1,
                                                  f);
    return;
}

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
        internal::centroid_decomposition_dfs_naive(par, bfs_order, f);
    } else if constexpr (MODE == 1) {
        internal::one_third_centroid_decomposition(par, bfs_order, f);
    } else {
        internal::one_third_centroid_decomposition_virtual_real(
            par, bfs_order, std::vector<int>(n, 1), f);
    }
}

}  // namespace ebi