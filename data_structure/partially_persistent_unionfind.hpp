#pragma once

#include <algorithm>
#include <vector>

/*
    refernce: https://noshi91.hatenablog.com/entry/2018/02/18/161529
    verify:
   https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/21131946
*/

namespace ebi {

struct partially_persistent_unionfind {
  private:
    int now = 0;
    std::vector<int> par, time;
    std::vector<std::vector<std::pair<int, int>>> data;

  public:
    partially_persistent_unionfind(int n) : par(n, 1), time(n, 1e9), data(n) {
        for (auto &v : data) {
            v.emplace_back(0, 1);
        }
    }

    int find(int t, int v) {
        if (time[v] > t)
            return v;
        else
            return find(t, par[v]);
    }

    bool merge(int a, int b) {
        ++now;
        a = find(now, a);
        b = find(now, b);
        if (a == b) return false;
        if (par[a] < par[b]) std::swap(a, b);
        par[a] += par[b];
        data[a].emplace_back(now, par[a]);
        par[b] = a;
        time[b] = now;
        return true;
    }

    bool same(int t, int a, int b) {
        return find(t, a) == find(t, b);
    }

    int size(int t, int v) {
        v = find(t, v);
        return std::prev(std::upper_bound(data[v].begin(), data[v].end(),
                                          std::pair<int, int>(t, 0)))
            ->second;
    }
};

}  // namespace ebi