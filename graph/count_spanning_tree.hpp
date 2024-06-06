#pragma once

#include <cassert>
#include <vector>

#include "../graph/base.hpp"
#include "../matrix/base.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
mint count_spanning_tree(const std::vector<std::vector<int>> &g) {
    const int n = (int)g.size();
    if (n == 1) return 1;
    std::vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            assert(g[i][j] == g[j][i]);
            deg[i] += g[i][j];
        }
    }
    matrix<mint> L(n - 1, n - 1, 0);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i == j)
                L[i - 1][j - 1] = deg[i];
            else
                L[i - 1][j - 1] -= g[i][j];
        }
    }
    return det(L);
}

template <Modint mint, class T> mint count_spanning_tree(const Graph<T> &g) {
    int n = g.node_number();
    if (n == 1) return 1;
    std::vector a(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (auto e : g[i]) {
            a[i][e.to]++;
        }
    }
    return count_spanning_tree<mint>(a);
}

template <Modint mint>
mint count_directed_spanning_tree(const std::vector<std::vector<int>> &g,
                                  int root, bool in = false) {
    const int n = (int)g.size();
    if (n == 1) return 1;
    std::vector<int> d(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) d[i] += in ? g[i][j] : g[j][i];
        }
    }
    matrix<mint> L(n - 1, n - 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = i, b = j;
            if (a == root || b == root) continue;
            if (root < a) a--;
            if (root < b) b--;
            if (a == b)
                L[a][b] = d[i];
            else
                L[a][b] = in ? -g[i][j] : -g[j][i];
        }
    }
    return det(L);
}

template <Modint mint, class T>
mint count_directed_spanning_tree(const Graph<T> &g, int root, bool in = false) {
    const int n = g.node_number();
    if (n == 1) return 1;
    std::vector d(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (auto e : g[i]) {
            d[i][e.to]++;
        }
    }
    return count_directed_spanning_tree<mint>(d, root, in);
}

}  // namespace ebi