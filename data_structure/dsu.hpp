#pragma once

#include <algorithm>
#include <vector>

namespace ebi {

struct dsu {
  private:
    std::vector<int> par;

  public:
    dsu(int n = 0) : par(n, -1) {}

    bool same(int x, int y) {
        return leader(x) == leader(y);
    }

    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        if (par[x] > par[y]) std::swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int leader(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = leader(par[x]);
    }

    int size(int x) {
        return -par[leader(x)];
    }

    int count_group() {
        int c = 0;
        for (int i = 0; i < int(par.size()); i++) {
            if (par[i] < 0) c++;
        }
        return c;
    }

    std::vector<std::vector<int>> groups() {
        int n = par.size();
        std::vector result(n, std::vector<int>());
        for (int i = 0; i < n; i++) {
            result[leader(i)].emplace_back(i);
        }
        result.erase(std::remove_if(result.begin(), result.end(),
                                    [](const std::vector<int> &v) -> bool {
                                        return v.empty();
                                    }),
                     result.end());
        return result;
    }

    void clear() {
        for (int i = 0; i < int(par.size()); i++) {
            par[i] = -1;
        }
    }
};

}  // namespace ebi