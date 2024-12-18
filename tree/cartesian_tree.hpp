#pragma once

#include <ranges>
#include <vector>

namespace ebi {

template <class T, class Compare = std::less<T>>
std::vector<int> cartesian_tree(const std::vector<T> &a) {
    int n = a.size();
    std::vector<int> par(n, -1);
    std::vector<int> stack;
    stack.reserve(n);
    for (int i : std::views::iota(0, n)) {
        int prev = -1;
        while (!stack.empty() && Compare()(a[i], a[stack.back()])) {
            prev = stack.back();
            stack.pop_back();
        }
        if (prev != -1) {
            par[prev] = i;
        }
        if (!stack.empty()) {
            par[i] = stack.back();
        }
        stack.push_back(i);
    }
    return par;
}

}  // namespace ebi