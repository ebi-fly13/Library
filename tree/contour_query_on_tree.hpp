#pragma once

#include <cassert>
#include <ranges>
#include <vector>

#include "../tree/centroid_decomposition.hpp"

namespace ebi {

struct contour_query_on_tree {
    contour_query_on_tree(const std::vector<std::vector<int>> &tree)
        : n(int(tree.size())) {
        int t = 0;
        range = {0};
        auto f = [&](const std::vector<int> &par, const std::vector<int> &vs,
                     const std::vector<int> &color) -> void {
            int sz = (int)par.size();
            std::vector<int> depth(sz, 0);
            for (const int v : std::views::iota(1, sz)) {
                depth[v] += depth[par[v]] + 1;
            }
            std::vector<int> red, blue;
            for (const int v : std::views::iota(0, sz)) {
                if (color[v] == 0) {
                    red.emplace_back(v);
                } else if (color[v] == 1) {
                    blue.emplace_back(v);
                } else
                    assert(color[v] == -1);
            }
            if (red.empty() || blue.empty()) return;
            int max_red = -1;
            for (const int v : red) {
                vertexs.emplace_back(vs[v]);
                number.emplace_back(t);
                dep.emplace_back(depth[v]);
                max_red = max_red < depth[v] ? depth[v] : max_red;
            }
            range.emplace_back(range.back() + max_red + 1);
            t++;
            int max_blue = -1;
            for (const int v : blue) {
                vertexs.emplace_back(vs[v]);
                number.emplace_back(t);
                dep.emplace_back(depth[v]);
                max_blue = max_blue < depth[v] ? depth[v] : max_blue;
            }
            range.emplace_back(range.back() + max_blue + 1);
            t++;
        };
        centroid_decomposition<2>(tree, f);
        index_ptr.assign(n + 1, 0);
        for (const int v : vertexs) {
            index_ptr[v + 1]++;
        }
        for (const int v : std::views::iota(0, n)) {
            index_ptr[v + 1] += index_ptr[v];
        }
        index.resize(index_ptr.back());
        auto counter = index_ptr;
        for (int i = 0; const int v : vertexs) {
            index[counter[v]++] = i;
            i++;
        }
    }

    std::vector<std::pair<int, int>> get_contour_from_vertex(int v, int l,
                                                             int r) const {
        assert(0 <= v && v < n);
        std::vector<std::pair<int, int>> res;
        for (const int idx :
             std::ranges::subrange(index.begin() + index_ptr[v],
                                   index.begin() + index_ptr[v + 1])) {
            int label = number[idx] ^ 1;
            int left = l - dep[idx], right = r - dep[idx];
            int max = range[label + 1] - range[label];
            if (left < 0) left = 0;
            if (right > max) right = max;
            if (left < right) {
                res.emplace_back(range[label] + left, range[label] + right);
            }
        }
        return res;
    }

    std::vector<int> get_vertex(int v) const {
        assert(0 <= v && v < n);
        std::vector<int> res;
        for (const int idx :
             std::ranges::subrange(index.begin() + index_ptr[v],
                                   index.begin() + index_ptr[v + 1])) {
            int label = number[idx];
            assert(range[label] + dep[idx] < range[label + 1]);
            res.emplace_back(range[label] + dep[idx]);
        }
        return res;
    }

    int size() const {
        return range.back();
    }

  private:
    int n;
    std::vector<int> vertexs, number, dep;
    std::vector<int> index, index_ptr;
    std::vector<int> range;
};

}  // namespace ebi