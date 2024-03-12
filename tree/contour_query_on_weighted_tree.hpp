#pragma once

#include <cassert>
#include <ranges>
#include <tuple>
#include <vector>

#include "../graph/base.hpp"
#include "../tree/centroid_decomposition.hpp"

namespace ebi {

template <class T> struct contour_query_on_weighted_tree {
    contour_query_on_weighted_tree(const Graph<T> &tree) : n(int(tree.size())) {
        int t = 0;
        labels.resize(n);
        range = {0};
        std::vector<int> rev(n, -1);
        auto f = [&](const std::vector<int> &par, const std::vector<int> &vs,
                     const std::vector<int> &color) -> void {
            int sz = (int)par.size();
            std::vector<T> depth(sz, -1);
            depth[0] = 0;
            for (int i : std::views::iota(0, sz)) {
                rev[vs[i]] = i;
            }
            for (int i : std::views::iota(0, sz)) {
                int v = vs[i];
                for (auto e : tree[v]) {
                    if (rev[e.to] == -1) continue;
                    depth[rev[e.to]] = depth[rev[v]] + e.cost;
                }
                rev[v] = -1;
            }
            std::vector<int> red, blue;
            for (const int v : std::views::iota(0, sz)) {
                if (color[v] == 0) {
                    red.emplace_back(v);
                } else if (color[v] == 1) {
                    blue.emplace_back(v);
                } else {
                    assert(color[v] == -1);
                }
            }
            if (red.empty() || blue.empty()) return;

            auto update = [&](std::vector<int> &s) -> void {
                std::sort(s.begin(), s.end(), [&](int i, int j) -> bool {
                    return depth[i] < depth[j];
                });
                for (int i = 0; const int v : s) {
                    dist.emplace_back(depth[v]);
                    labels[vs[v]].emplace_back(t, i, depth[v]);
                    i++;
                }
                range.emplace_back(dist.size());
                t++;
            };
            update(red);
            update(blue);
        };
        centroid_decomposition<2>(tree, f);
    }

    std::size_t size() {
        return dist.size();
    }

    // [0, k)
    std::vector<std::pair<std::size_t, std::size_t>>
    get_range_less_than_k_from_v(int v, T k) const {
        std::vector<std::pair<std::size_t, std::size_t>> res;
        for (auto [t, i, d] : labels[v]) {
            t ^= 1;
            std::size_t id_l = range[t];
            std::size_t id_r =
                std::lower_bound(dist.begin() + range[t],
                                 dist.begin() + range[t + 1], k - d) -
                dist.begin();
            res.emplace_back(id_l, id_r);
        }
        return res;
    }

    // [k, infty)
    std::vector<std::pair<std::size_t, std::size_t>> get_range_k_or_more_from_v(
        int v, T k) const {
        std::vector<std::pair<std::size_t, std::size_t>> res;
        for (auto [t, i, d] : labels[v]) {
            t ^= 1;
            std::size_t id_l =
                std::lower_bound(dist.begin() + range[t],
                                 dist.begin() + range[t + 1], k - d) -
                dist.begin();
            std::size_t id_r = range[t + 1];
            res.emplace_back(id_l, id_r);
        }
        return res;
    }

    // [l, r)
    std::vector<std::pair<std::size_t, std::size_t>> get_contour_from_vertex(
        int v, T l, T r) const {
        std::vector<std::pair<std::size_t, std::size_t>> res;
        for (auto [t, i, d] : labels[v]) {
            t ^= 1;
            std::size_t id_l =
                std::lower_bound(dist.begin() + range[t],
                                 dist.begin() + range[t + 1], l - d) -
                dist.begin();
            std::size_t id_r =
                std::lower_bound(dist.begin() + range[t],
                                 dist.begin() + range[t + 1], r - d) -
                dist.begin();
            res.emplace_back(id_l, id_r);
        }
        return res;
    }

    std::vector<std::size_t> get_vertex(int v) const {
        assert(0 <= v && v < n);
        std::vector<std::size_t> res;
        for (auto [t, i, _] : labels[v]) {
            res.emplace_back(range[t] + i);
        }
        return res;
    }

    std::pair<int, int> sub_range(int i) const {
        return {range[i], range[i + 1]};
    }

  private:
    int n;
    std::vector<T> dist;
    std::vector<int> range;
    std::vector<std::vector<std::tuple<int, int, T>>> labels;
};

}  // namespace ebi