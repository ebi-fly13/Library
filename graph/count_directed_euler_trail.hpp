#pragma once

#include "../graph/base.hpp"
#include "../graph/count_spanning_tree.hpp"
#include "../math/binomial.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
mint count_directed_euler_circuit(const std::vector<std::vector<int>> &g) {
    int n = (int)g.size();
    std::vector<int> indeg(n, 0);
    std::vector<int> outdeg(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            indeg[j] += g[i][j];
            outdeg[i] += g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (indeg[i] != outdeg[i]) return 0;
    }

    mint res = count_directed_spanning_tree<mint>(g, 0, true);
    for (int i = 0; i < n; i++) {
        res *= Binomial<mint>::f(outdeg[i] - 1);
    }
    return res;
}

template <Modint mint, class T>
mint count_directed_euler_circuit(const Graph<T> &g) {
    int n = g.node_number();
    std::vector a(n, std::vector<int>(n, 0));
    for (auto e : g.get_edges()) {
        a[e.from][e.to]++;
    }
    return count_directed_euler_circuit<mint>(a);
}

template <Modint mint>
mint count_directed_euler_trail(std::vector<std::vector<int>> g) {
    int n = (int)g.size();
    std::vector<int> indeg(n, 0);
    std::vector<int> outdeg(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            indeg[j] += g[i][j];
            outdeg[i] += g[i][j];
        }
    }
    int s = -1, t = -1;
    mint m = 0;
    for (int v = 0; v < n; v++) {
        m += indeg[v];
        if (indeg[v] + 1 == outdeg[v]) {
            if (s != -1) return 0;
            s = v;
        } else if (indeg[v] == outdeg[v] + 1) {
            if (t != -1) return 0;
            t = v;
        } else if (indeg[v] == outdeg[v])
            continue;
        else
            return 0;
    }
    if (s == -1 && t == -1) {
        return m * count_directed_euler_circuit<mint>(g);
    } else if (s != -1 && t != -1) {
        g[t][s]++;
        return count_directed_euler_circuit<mint>(g);
    } else {
        return 0;
    }
}

template <Modint mint, class T>
mint count_directed_euler_trail(const Graph<T> &g) {
    int n = g.node_number();
    std::vector a(n, std::vector<int>(n, 0));
    for (auto e : g.get_edges()) {
        a[e.from][e.to]++;
    }
    return count_directed_euler_trail<mint>(a);
}

}  // namespace ebi