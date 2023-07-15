#pragma once

#include <array>
#include <map>
#include <vector>

#include "../data_structure/undo_unionfind.hpp"
#include "../utility/bit_operator.hpp"

namespace ebi {

struct offline_dynamic_connective {
  private:
    void add_query(int l, int r, std::pair<int, int> edge) {
        assert(0 <= l && l <= r && r <= m);
        l += sz;
        r += sz;
        while (l < r) {
            if (l & 1) seg[l++].emplace_back(edge);
            if (r & 1) seg[--r].emplace_back(edge);
            l >>= 1;
            r >>= 1;
        }
    }

  public:
    offline_dynamic_connective(int n, std::vector<std::array<int, 3>> queries)
        : n(n) {
        m = queries.size() + 1;
        log2 = ceil_pow2(m);
        sz = 1 << log2;
        seg.resize(2 * sz);
        std::map<std::pair<int, int>, int> cnt, appear;
        for (int i = 0; i < (int)queries.size(); i++) {
            auto [t, u, v] = queries[i];
            if (u > v) std::swap(u, v);
            if (t == 0) {
                if (cnt[{u, v}]++ == 0) {
                    appear[{u, v}] = i + 1;
                }
            } else if (t == 1) {
                int c = --cnt[{u, v}];
                assert(c >= 0);
                if (c == 0) {
                    add_query(appear[{u, v}], i + 1, {u, v});
                }
            } else
                assert(0);
        }
        for (auto [edge, c] : cnt) {
            if (c == 0) continue;
            add_query(appear[edge], m, edge);
        }
    }

    template <class F> void execute(F f) {
        uf = undo_unionfind(n);
        auto dfs = [&](auto &&self, int now) -> void {
            for (auto edge : seg[now]) uf.merge(edge.first, edge.second);
            if (sz <= now) {
                if (now - sz < m) f(now - sz);
            } else {
                self(self, 2 * now);
                self(self, 2 * now + 1);
            }
            for (int i = 0; i < (int)seg[now].size(); i++) uf.undo();
        };
        dfs(dfs, 1);
    }

    bool is_same(int u, int v) {
        return uf.same(u, v);
    }

    int leader(int x) {
        return uf.leader(x);
    }

  private:
    int n, m;
    int log2, sz;
    std::vector<std::vector<std::pair<int, int>>> seg;
    undo_unionfind uf;
};

}  // namespace ebi