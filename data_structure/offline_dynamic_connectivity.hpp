#pragma once

#include <array>
#include <bit>
#include <cassert>
#include <map>
#include <ranges>
#include <utility>
#include <vector>

#include "../data_structure/undo_unionfind.hpp"

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

    void add_block(int i) {
        for (auto [u, v] : seg[i]) {
            uf.merge(u, v);
        }
    }

    void del_block(int i) {
        int cnt = seg[i].size();
        while (cnt--) {
            uf.undo();
        }
    }

  public:
    offline_dynamic_connective(int n_, std::vector<std::array<int, 3>> queries)
        : n(n_),
          m(queries.size() + 1),
          sz(std::bit_ceil(uint(m))),
          lg2(std::countr_zero(uint(sz))) {
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

        uf = undo_unionfind(n);
        for (int i : std::views::iota(0, lg2)) {
            add_block(1 << i);
        }
        now = sz;
    }

    void set(int t) {
        assert(0 <= t && t < m);
        t += sz;
        if (now == t) return;
        int k = 32 - std::countl_zero(uint(now ^ t));
        for (int i = 0; i < k; i++) {
            del_block(now);
            now >>= 1;
        }
        for (int i : std::views::iota(0, k) | std::views::reverse) {
            now <<= 1;
            if ((t >> i) & 1) now++;
            add_block(now);
        }
        assert(now == t);
    }

    bool same(int u, int v) const {
        return uf.same(u, v);
    }

    int leader(int u) const {
        return uf.leader(u);
    }

    int size(int u) const {
        return uf.size(u);
    }

    int count_group() const {
        return uf.count_group();
    }

  private:
    int n, m;
    int sz, lg2;
    std::vector<std::vector<std::pair<int, int>>> seg;
    int now;
    undo_unionfind uf;
};

}  // namespace ebi