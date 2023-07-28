#pragma once

#include <algorithm>
#include <limits>
#include <vector>

namespace ebi {

template <class T> std::vector<T> LIS(const std::vector<T> &a, bool narrowly) {
    std::vector<T> ret = {std::numeric_limits<T>::max()};
    std::vector<int> used;
    used.reserve(a.size());
    for (auto x : a) {
        auto itr = narrowly ? std::lower_bound(ret.begin(), ret.end(), x)
                            : std::upper_bound(ret.begin(), ret.end(), x);
        used.emplace_back(itr - ret.begin());
        if (itr == ret.end())
            ret.emplace_back(x);
        else
            *itr = x;
    }
    int len = ret.size();
    int idx = len - 1;
    T now = std::numeric_limits<T>::max();
    std::vector<int> lis(len);
    for (int i = int(a.size()) - 1; i >= 0; i--) {
        if (used[i] == idx && a[i] + int(narrowly) <= now) {
            now = a[i];
            lis[idx--] = i;
        }
    }
    return lis;
}

}  // namespace ebi