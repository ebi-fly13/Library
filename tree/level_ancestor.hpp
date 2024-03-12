#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T> struct level_ancestor {
  private:
    int n;
    std::vector<int> in;
    std::vector<int> inv_in;
    std::vector<int> depths;
    std::vector<std::vector<int>> s;

  public:
    level_ancestor(const Graph<T> &gh, int root = 0)
        : n(gh.size()), in(n), inv_in(n), depths(n) {
        int cnt = 0;
        int max = 0;
        auto dfs = [&](auto &&self, int v, int par = -1) -> void {
            inv_in[cnt] = v;
            in[v] = cnt++;
            max = std::max(max, depths[v]);
            for (auto e : gh[v])
                if (e.to != par) {
                    depths[e.to] = depths[v] + 1;
                    self(self, e.to, v);
                }
        };
        dfs(dfs, root);
        s.resize(max + 1);
        for (int i = 0; i < n; i++) {
            int u = inv_in[i];
            s[depths[u]].emplace_back(i);
        }
    }

    int query(int u, int k) const {
        int m = depths[u] - k;
        assert(m >= 0);
        return inv_in[*std::prev(
            std::upper_bound(s[m].begin(), s[m].end(), in[u]))];
    }

    int depth(int u) const {
        return depths[u];
    }
};

}  // namespace ebi