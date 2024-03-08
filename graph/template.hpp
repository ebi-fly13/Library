#pragma once

#include <vector>
#include <iostream>

namespace ebi {

template <class T> struct Edge {
    int to;
    T cost;
    Edge(int _to, T _cost = 1) : to(_to), cost(_cost) {}
};

template <class T> struct Graph : std::vector<std::vector<Edge<T>>> {
    using std::vector<std::vector<Edge<T>>>::vector;
    void add_edge(int u, int v, T w, bool directed = false) {
        (*this)[u].emplace_back(v, w);
        if (directed) return;
        (*this)[v].emplace_back(u, w);
    }
};

struct graph : std::vector<std::vector<int>> {
    using std::vector<std::vector<int>>::vector;
    void add_edge(int u, int v, bool directed = false) {
        (*this)[u].emplace_back(v);
        if (directed) return;
        (*this)[v].emplace_back(u);
    }

    void read_tree(int offset = 1) {
        read_graph((int)size()-1, offset);
    }

    void read_graph(int m, int offset = 1, bool directed = false) {
        for(int i = 0; i < m; i++) {
            int u,v;
            std::cin >> u >> v;
            u -= offset;
            v -= offset;
            add_edge(u, v, directed);
        }
    }
};

}  // namespace ebi