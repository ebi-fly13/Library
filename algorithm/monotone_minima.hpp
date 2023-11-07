#pragma once

#include <functional>
#include <utility>
#include <vector>

namespace ebi {

template <class T, class F, class Compare = std::less<T>>
std::pair<std::vector<int>, std::vector<T>> monotone_minima(
    int n, int m, F f, const Compare &compare = Compare()) {
    std::vector<int> argmin(n);
    std::vector<T> min_val(n);
    auto dfs = [&](auto &&self, int top, int bottom, int left,
                   int right) -> void {
        if (top > bottom) return;
        int mid = (top + bottom) >> 1;
        argmin[mid] = left;
        min_val[mid] = f(mid, left);
        for (int i = left + 1; i <= right; i++) {
            T val = f(mid, i);
            if (min_val[mid] == val || compare(val, min_val[mid])) {
                argmin[mid] = i;
                min_val[mid] = val;
            }
        }
        self(self, top, mid - 1, left, argmin[mid]);
        self(self, mid + 1, bottom, argmin[mid], right);
    };
    dfs(dfs, 0, n - 1, 0, m - 1);
    return {argmin, min_val};
}

template <class T, class F, class Compare = std::less<T>>
std::pair<std::vector<int>, std::vector<T>> slide_monotone_minima(
    int n, int m, F f, const Compare &compare = Compare()) {
    std::vector<int> argmin(n);
    std::vector<T> min_val(n);
    auto dfs = [&](auto &&self, int top, int bottom, int left, int right,
                   int depth) -> void {
        if (top > bottom) return;
        int mid = (top + bottom) >> 1;
        argmin[mid] = left;
        min_val[mid] = f(mid, left, depth);
        for (int i = left + 1; i <= right; i++) {
            T val = f(mid, i, depth);
            if (min_val[mid] == val || compare(val, min_val[mid])) {
                argmin[mid] = i;
                min_val[mid] = val;
            }
        }
        self(self, top, mid - 1, left, argmin[mid], depth + 1);
        self(self, mid + 1, bottom, argmin[mid], right, depth + 1);
    };
    dfs(dfs, 0, n - 1, 0, m - 1, 0);
    return {argmin, min_val};
}

}  // namespace ebi