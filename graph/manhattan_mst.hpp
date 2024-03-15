#pragma once

#include <algorithm>
#include <map>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>

#include "../data_structure/unionfind.hpp"
#include "../graph/base.hpp"

namespace ebi {

template <class T>
std::pair<T, std::vector<std::pair<int, int>>> manhattan_mst(
    std::vector<T> &xs, std::vector<T> &ys) {
    const int n = xs.size();
    std::vector<int> ids(n);
    std::iota(ids.begin(), ids.end(), 0);
    std::vector<std::tuple<T, int, int>> edges;
    for (int s = 0; s < 2; s++) {
        for (int t = 0; t < 2; t++) {
            std::sort(ids.begin(), ids.end(), [&](int i, int j) -> bool {
                return xs[i] + ys[i] < xs[j] + ys[j];
            });
            std::map<T, int> sweep;
            for (int i : ids) {
                for (auto itr = sweep.lower_bound(-ys[i]); itr != sweep.end();
                     itr = sweep.erase(itr)) {
                    int j = itr->second;
                    if (xs[i] - xs[j] < ys[i] - ys[j]) break;
                    edges.emplace_back(
                        std::abs(ys[i] - ys[j]) + std::abs(xs[i] - xs[j]), i,
                        j);
                }
                sweep[-ys[i]] = i;
            }
            std::swap(xs, ys);
        }
        for (auto &x : xs) x = -x;
    }
    std::sort(edges.begin(), edges.end(), [&](auto a, auto b) -> bool {
        return std::get<0>(a) < std::get<0>(b);
    });
    unionfind uf(n);
    std::vector<std::pair<int, int>> es;
    T sum = 0;
    for (auto [cost, i, j] : edges) {
        if (uf.same(i, j)) continue;
        uf.merge(i, j);
        sum += cost;
        es.emplace_back(i, j);
    }
    return {sum, es};
}

}  // namespace ebi