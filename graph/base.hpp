#pragma once

#include <cassert>
#include <iostream>
#include <ranges>
#include <vector>

#include "../data_structure/simple_csr.hpp"

namespace ebi {

template <class T> struct Edge {
    int from, to;
    T cost;
    int id;
};

template <class E> struct Graph {
  private:
    using cost_type = E;
    using edge_type = Edge<cost_type>;

  public:
    Graph(int n_) : n(n_) {}

    Graph() = default;

    void add_edge(int u, int v, cost_type c) {
        edges.emplace_back(u, edge_type{u, v, c, m++});
    }

    void add_undirected_edge(int u, int v, cost_type c) {
        edges.emplace_back(u, edge_type{u, v, c, m});
        edges.emplace_back(v, edge_type{v, u, c, m});
        m++;
    }

    void read_tree(int offset = 1, bool is_weighted = false) {
        read_graph(n - 1, offset, false, is_weighted);
    }

    void read_parents(int offset = 1) {
        for (auto i : std::views::iota(1, n)) {
            int p;
            std::cin >> p;
            p -= offset;
            add_undirected_edge(p, i, 1);
        }
        build();
    }

    void read_graph(int e, int offset = 1, bool is_directed = false,
                    bool is_weighted = false) {
        for (int i = 0; i < e; i++) {
            int u, v;
            std::cin >> u >> v;
            u -= offset;
            v -= offset;
            if (is_weighted) {
                cost_type c;
                std::cin >> c;
                if (is_directed) {
                    add_edge(u, v, c);
                } else {
                    add_undirected_edge(u, v, c);
                }
            } else {
                if (is_directed) {
                    add_edge(u, v, 1);
                } else {
                    add_undirected_edge(u, v, 1);
                }
            }
        }
        build();
    }

    void build() {
        assert(!prepared);
        csr = simple_csr<edge_type>(n, edges);
        edges.clear();
        prepared = true;
    }

    int size() const {
        return n;
    }

    const auto operator[](int i) const {
        return csr[i];
    }
    auto operator[](int i) {
        return csr[i];
    }

  private:
    int n, m = 0;

    std::vector<std::pair<int, edge_type>> edges;
    simple_csr<edge_type> csr;
    bool prepared = false;
};

}  // namespace ebi