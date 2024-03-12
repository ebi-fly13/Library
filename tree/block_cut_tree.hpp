#pragma once

#include <cassert>

#include "../graph/biconnected_components.hpp"

namespace ebi {

template<class T>
struct block_cut_tree : biconnected_components<T> {
  public:
    block_cut_tree(const Graph<T> &g)
        : biconnected_components<T>(g), rev(this->n, -1) {
        int cnt = 0;
        for (auto v : this->_articulation) {
            rev[v] = cnt++;
        }
        int sz = cnt + this->bc.size();
        tree.resize(sz);
        std::vector<int> last(this->n, -1);
        for (int i = cnt; i < sz; i++) {
            for (auto e : this->bc[i - cnt]) {
                for (auto v : {e.first, e.second}) {
                    if (rev[v] != -1 && rev[v] < cnt) {
                        if (std::exchange(last[v], i) != i) {
                            tree[i].emplace_back(rev[v]);
                            tree[rev[v]].emplace_back(i);
                        }
                    } else {
                        rev[v] = i;
                    }
                }
            }
        }
        groups.resize(sz);
        for (int i = 0; i < this->n; i++) {
            if (rev[i] < 0) {
                rev[i] = sz++;
                groups.emplace_back();
                tree.emplace_back();
            }
            groups[rev[i]].emplace_back(i);
        }
    }

    std::vector<std::vector<int>> bcc() {
        int cnt = this->_articulation.size();
        int sz = groups.size() - cnt;
        std::vector _bcc(sz, std::vector<int>());
        for (int i = 0; i < sz; i++) {
            _bcc[i] = groups[cnt + i];
            for (auto nv : tree[cnt + i]) {
                assert(0 <= nv && nv < cnt);
                assert(groups[nv].size() == 1);
                _bcc[i].emplace_back(groups[nv][0]);
            }
        }
        return _bcc;
    }

  private:
    std::vector<int> rev;
    std::vector<std::vector<int>> tree;
    std::vector<std::vector<int>> groups;
};

}  // namespace ebi