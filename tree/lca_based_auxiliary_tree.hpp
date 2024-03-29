#pragma once

#include <algorithm>
#include <cassert>
#include <ranges>
#include <stack>
#include <vector>

#include "../tree/heavy_light_decomposition.hpp"

namespace ebi {

template <class T>
std::vector<std::pair<int, int>>
heavy_light_decomposition<T>::lca_based_auxiliary_tree_dfs_order(
    std::vector<int> vs) const {
    if (vs.empty()) return {};
    std::sort(vs.begin(), vs.end(),
              [&](int u, int v) -> bool { return in[u] < in[v]; });
    auto s = vs;
    for (int i = 1; i < int(vs.size()); i++) {
        s.emplace_back(lca(vs[i - 1], vs[i]));
    }
    std::sort(s.begin(), s.end(),
              [&](int u, int v) -> bool { return in[u] < in[v]; });
    s.erase(std::unique(s.begin(), s.end()), s.end());
    std::stack<int> stack;
    stack.push(s[0]);
    int sz = s.size();
    std::vector<std::pair<int, int>> dfs_order(sz);
    dfs_order[0] = {s[0], -1};
    for (int i = 1; i < int(s.size()); i++) {
        int v = s[i];
        while (!stack.empty()) {
            int u = stack.top();
            if (in[u] <= in[v] && in[v] < out[u]) {
                break;
            } else {
                stack.pop();
            }
        }
        assert(!stack.empty());
        int par = stack.top();
        dfs_order[i] = {v, par};
        stack.push(v);
    }
    return dfs_order;
}

template <class T>
std::pair<std::vector<int>, Graph<T>>
heavy_light_decomposition<T>::lca_based_auxiliary_tree(
    std::vector<int> vs) const {
    static std::vector<int> a(1'000'000, -1), p(1'000'000, -1);
    int k = vs.size();
    if (k == 1) {
        return {vs, Graph<T>(1)};
    }
    std::sort(vs.begin(), vs.end(),
              [&](int v, int u) { return in[v] < in[u]; });
    std::stack<int> stack;
    std::vector<int> s;
    stack.push(vs[0]);
    for (int i : std::views::iota(1, k)) {
        int w = lca(vs[i - 1], vs[i]);
        int prev = -1;
        while (!stack.empty() && depth_[w] <= depth_[stack.top()]) {
            if (prev != -1) {
                s.emplace_back(prev);
                p[prev] = stack.top();
            }
            prev = stack.top();
            stack.pop();
        }
        if (prev != w) {
            assert(prev != -1);
            s.emplace_back(prev);
            p[prev] = w;
        }
        stack.push(w);
        stack.push(vs[i]);
    }
    {
        int prev = -1;
        while (!stack.empty()) {
            int v = stack.top();
            s.emplace_back(v);
            if (prev != -1) p[prev] = v;
            prev = v;
            stack.pop();
        }
    }
    std::reverse(s.begin(), s.end());
    int m = s.size();
    for (int i : std::views::iota(0, m)) {
        a[s[i]] = i;
    }
    Graph<T> tree(m);
    for (auto v : s) {
        if (p[v] < 0) continue;
        T cost = distance(p[v], v);
        tree.add_edge(a[p[v]], a[v], cost);
        tree.add_edge(a[v], a[p[v]], cost);
    }
    tree.build();
    for (auto v : s) {
        a[v] = -1;
        p[v] = -1;
    }
    return {s, tree};
}

}  // namespace ebi