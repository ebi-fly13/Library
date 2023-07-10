#pragma once

#include "../graph/low_link.hpp"

namespace ebi {

struct biconnected_components : low_link {
  private:
    void dfs(int v, int par = -1) {
        used[v] = true;
        for (auto nv : this->g[v]) {
            if (nv == par) continue;
            if (!used[nv] || this->ord[nv] < this->ord[v]) {
                tmp.emplace_back(std::minmax(v, nv));
            }
            if (!used[nv]) {
                dfs(nv, v);
                if (this->low[nv] >= this->ord[v]) {
                    bc.emplace_back();
                    while (true) {
                        auto e = tmp.back();
                        bc.back().emplace_back(e);
                        tmp.pop_back();
                        if (e.first == std::min(v, nv) &&
                            e.second == std::max(v, nv)) {
                            break;
                        }
                    }
                }
            }
        }
    }

  public:
    biconnected_components(const std::vector<std::vector<int>> &g)
        : low_link(g), used(this->n, false) {
        for (int i = 0; i < this->n; i++) {
            if (!used[i]) dfs(i);
        }
    }

  protected:
    std::vector<bool> used;
    std::vector<std::vector<std::pair<int, int>>> bc;
    std::vector<std::pair<int, int>> tmp;
};

}  // namespace ebi