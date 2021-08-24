#pragma once

#include <vector>

namespace ebi {

template<class T>
struct Edge {
    int to;
    T cost;
    Edge(int to, T cost=1) : to(to), cost(cost) { }
};

template<class T>
struct Graph : std::vector<std::vector<Edge<T>>> {
    using std::vector<std::vector<Edge<T>>>::vector;
    void add_edge(int u, int v, T w, bool directed = false) {
        (*this)[u].emplace_back(v, w);
        if(directed) return; 
        (*this)[v].emplace_back(u, w);
    }
};

struct graph : std::vector<std::vector<int>> {
    using std::vector<std::vector<int>>::vector;
    void add_edge(int u, int v, bool directed = false) {
        (*this)[u].emplace_back(v);
        if(directed) return;
        (*this)[v].emplace_back(u);
    }
};

} // namespace ebi