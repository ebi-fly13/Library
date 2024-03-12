#pragma once

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

#include "../graph/base.hpp"

namespace ebi {

template <class T> std::vector<T> dijkstra(int s, int n, const Graph<T> &g) {
    typedef std::pair<T, int> P;
    std::vector<T> d(n, std::numeric_limits<T>::max());
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    que.push(P(0, s));
    d[s] = 0;
    while (!que.empty()) {
        auto [ret, v] = que.top();
        que.pop();
        if (d[v] < ret) continue;
        for (auto e : g[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d;
}

template <class T> struct dijkstra_path {
  public:
    dijkstra_path(int s_, const Graph<T> &g)
        : s(s_),
          dist(g.size(), std::numeric_limits<T>::max()),
          prev(g.size(), -1) {
        dist[s] = 0;
        using P = std::pair<T, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> que;
        que.push(P(0, s));
        while (!que.empty()) {
            auto [ret, v] = que.top();
            que.pop();
            if (dist[v] < ret) continue;
            for (auto e : g[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    prev[e.to] = v;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
    }

    std::pair<T, std::vector<int>> shortest_path(int v) const {
        if (dist[v] == std::numeric_limits<T>::max()) return {dist[v], {}};
        std::vector<int> path;
        int u = v;
        while (u != s) {
            path.emplace_back(u);
            u = prev[u];
        }
        path.emplace_back(u);
        std::reverse(path.begin(), path.end());
        return {dist[v], path};
    }

  private:
    int s;
    std::vector<T> dist;
    std::vector<int> prev;
};

}  // namespace ebi