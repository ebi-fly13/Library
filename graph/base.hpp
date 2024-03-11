#pragma once

#include <cassert>
#include <iostream>
#include <vector>
#include <ranges>

#include "../data_structure/simple_csr.hpp"

namespace ebi {

template <class T> struct Edge {
    int to;
    T cost;
    int id;
};

template <class E, bool is_directed = false> struct Graph {
  private:
    using cost_type = E;
    using edge_type = Edge<cost_type>;

  public:
    Graph(int n_) : n(n_) {}

    void add_edge(int u, int v, cost_type c) {
        edges.emplace_back(u, edge_type{v, c, m++});
    }

    void read_tree(int offset = 1) {
        read_graph(n-1, offset);
    }

    void read_graph(int e, int offset = 1, bool is_weighted = false) {
        for(int i = 0; i < e; i++) {
            int u, v;
            std::cin >> u >> v;
            u -= offset;
            v -= offset;
            if (is_weighted) {
                cost_type c;
                std::cin >> c;
                add_edge(u, v, c);
                if constexpr (!is_directed) {
                    add_edge(v, u, c);
                }
            }
            else {
                add_edge(u, v, 1);
                if constexpr (!is_directed) {
                    add_edge(v, u, 1);
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