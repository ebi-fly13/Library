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
using Graph = std::vector<std::vector<Edge<T>>>;

using graph = std::vector<std::vector<int>>;

} // namespace ebi