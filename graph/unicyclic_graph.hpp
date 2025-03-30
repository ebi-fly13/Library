#pragma once

#include <queue>
#include <stack>

#include "../graph/base.hpp"
#include "../tree/heavy_light_decomposition.hpp"

namespace ebi {

template <class T> struct unicyclic_graph {
  private:
    void build() {
        assert(g.node_number() > 2);
        assert(g.node_number() == g.edge_number());
        int n = g.node_number();
        in_cycle.assign(n, true);
        parent.assign(n, -1);
        cycle_root.assign(n, -1);
        // サイクルの検出
        {
            std::vector<int> deg(n);
            std::stack<int> stack;
            for (auto i : std::views::iota(0, n)) {
                deg[i] = g[i].size();
                if (deg[i] == 1) {
                    stack.push(i);
                }
            }
            while (!stack.empty()) {
                int v = stack.top();
                stack.pop();
                in_cycle[v] = false;
                for (auto e : g[v]) {
                    if (deg[e.to] == 1) continue;
                    parent[v] = e.to;
                    deg[e.to]--;
                    if (deg[e.to] == 1) {
                        stack.push(e.to);
                    }
                }
            }
        }
        // サイクルの 1 辺を切って root から順に並べる
        for (auto i : std::views::iota(0, n)) {
            if (in_cycle[i]) {
                root = i;
                for (auto e : g[i]) {
                    if (in_cycle[e.to]) {
                        remove_edge_id = e.id;
                        break;
                    }
                }
                break;
            }
        }
        std::vector<bool> valid(n, false);
        cycle = {root};
        while (!valid[cycle.back()]) {
            int v = cycle.back();
            cycle_root[v] = v;
            valid[v] = true;
            for (auto e : g[v]) {
                if (e.id == remove_edge_id || valid[e.to] || !in_cycle[e.to])
                    continue;
                cycle.emplace_back(e.to);
                parent[e.to] = v;
            }
        }
        std::queue<int> que;
        for (auto v : cycle) que.push(v);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto e : g[v]) {
                if (cycle_root[e.to] != -1) continue;
                cycle_root[e.to] = cycle_root[v];
                que.push(e.to);
            }
        }
    }

  public:
    unicyclic_graph(const Graph<T> &g_) : g(g_) {
        build();
    }

    Graph<T> get_tree() const {
        Graph<T> tree(g.node_number());
        for (auto e : g.get_edges()) {
            if (e.id == remove_edge_id) continue;
            tree.add_undirected_edge(e.from, e.to, e.cost);
        }
        tree.build();
        return tree;
    }

    std::vector<int> get_cycle() const {
        return cycle;
    }

    int get_root() const {
        return root;
    }

    int get_remove_edge_id() const {
        return remove_edge_id;
    }

    int get_cycle_root(int v) const {
        return cycle_root[v];
    }

    T distance(const heavy_light_decomposition<T> &hld, int u, int v) const {
        if (cycle_root[u] == cycle_root[v]) return hld.distance(u, v);
        T loop =
            hld.distance(root, cycle.back()) + g.get_edge(remove_edge_id).cost;
        T d = hld.distance(cycle_root[u], cycle_root[v]);
        d = std::min<T>(d, loop - d);
        return hld.distance(cycle_root[u], u) + hld.distance(cycle_root[v], v) +
               d;
    }

    bool is_in_cycle(int v) const {
        return in_cycle[v];
    }

  private:
    int root;
    int remove_edge_id;

    Graph<T> g, tree;
    std::vector<int> cycle, parent, cycle_root;
    std::vector<bool> in_cycle;
};

}  // namespace ebi