#pragma once

#include <cassert>
#include <numeric>
#include <optional>
#include <ranges>
#include <utility>
#include <vector>

#include "../data_structure/skew_heap.hpp"
#include "../graph/base.hpp"

namespace ebi {

namespace internal {

struct union_find_not_merge_tech {
  public:
    union_find_not_merge_tech(int n_) : n(n_), data(n, -1) {}

    int leader(int u) {
        if (data[u] < 0) return u;
        return data[u] = leader(data[u]);
    }

    bool merge(int u, int v) {
        u = leader(u);
        v = leader(v);
        if (u == v) return false;
        data[u] += data[v];
        data[v] = u;
        return true;
    }

    bool same(int u, int v) {
        return leader(u) == leader(v);
    }

    int size(int u) {
        u = leader(u);
        return -data[u];
    }

  private:
    int n;
    std::vector<int> data;
};

}  // namespace internal

template <class T>
std::optional<std::pair<T, std::vector<int>>> directed_mst(int root,
                                                           const Graph<T> &g) {
    using Heap = skew_heap<T, Edge<T>, std::greater<T>>;
    int n = g.node_number();
    std::vector<int> used(2 * n, 0);
    std::vector<int> par_node(2 * n, -1);
    std::vector<int> best_id(2 * n, -1);
    std::vector<T> best_cost(2 * n);
    internal::union_find_not_merge_tech uf(2 * n);
    std::vector<Heap> heap(2 * n);
    int nxt = n;
    used[root] = 2;
    for (auto e : g.get_edges()) {
        heap[e.to].push(e.cost, e);
    }
    T sum = 0;
    for (auto s : std::views::iota(0, n)) {
        if (used[s]) continue;
        std::vector<int> path = {s};
        while (1) {
            int a = path.back();
            if (heap[a].empty()) return std::nullopt;
            auto [c, e] = heap[a].top();
            heap[a].pop();
            int v = uf.leader(e.from);
            if (a == v) continue;
            used[a] = 1;
            best_id[a] = e.id;
            best_cost[a] = c;
            sum += c;
            if (!used[v]) {
                path.emplace_back(v);
                continue;
            } else if (used[v] == 1) {
                int w = -1;
                int u = nxt++;
                while (w != v) {
                    w = path.back();
                    path.pop_back();
                    T sub = best_cost[w];
                    heap[w].add(-sub);
                    heap[u].meld(heap[w]);
                    par_node[w] = u;
                    uf.merge(u, w);
                    used[w] = 2;
                }
                path.emplace_back(u);
            } else
                break;
        }
        for (auto v : path) used[v] = 2;
    }
    std::vector<int> par(n, -1);
    std::vector<bool> done(nxt, false);
    done[root] = true;
    par[root] = root;
    T ret = 0;
    for (auto i : std::views::iota(0, nxt) | std::views::reverse) {
        if (done[i]) continue;
        int id = best_id[i];
        auto e = g.get_edge(id);
        par[e.to] = e.from;
        ret += e.cost;
        int x = e.to;
        while (x != -1 && !done[x]) {
            done[x] = true;
            x = par_node[x];
        }
    }
    assert(sum == ret);
    return std::pair<T, std::vector<int>>{sum, par};
}

}  // namespace ebi