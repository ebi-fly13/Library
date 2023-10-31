#pragma once

#include <algorithm>
#include <cassert>
#include <ranges>
#include <stack>
#include <vector>

#include "../tree/heavy_light_decomposition.hpp"

namespace ebi {

std::pair<std::vector<int>, std::vector<std::vector<int>>>
heavy_light_decomposition::lca_based_auxiliary_tree(std::vector<int> vs) const {
    static std::vector<int> a(n, -1), p(n, -1);
    int k = vs.size();
    if (k == 1) {
        return {vs, std::vector(1, std::vector<int>())};
    }
    std::sort(vs.begin(), vs.end(),
              [&](int v, int u) { return in[v] < in[u]; });
    std::stack<int> stack;
    std::vector<int> s;
    stack.push(vs[0]);
    for (int i : std::views::iota(1, k)) {
        int w = lca(vs[i - 1], vs[i]);
        int prev = -1;
        while (!stack.empty() && depth[w] <= depth[stack.top()]) {
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
    std::vector tree(m, std::vector<int>());
    for (auto v : s) {
        if (p[v] < 0) continue;
        tree[a[p[v]]].emplace_back(a[v]);
    }
    for (auto v : s) {
        a[v] = -1;
        p[v] = -1;
    }
    return {s, tree};
}

}  // namespace ebi