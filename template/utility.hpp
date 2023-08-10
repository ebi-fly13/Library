#pragma once

#include <limits>
#include <vector>

#include "int_alias.hpp"

namespace ebi {

template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

constexpr i64 LNF = std::numeric_limits<i64>::max() / 4;

constexpr int INF = std::numeric_limits<int>::max() / 2;

const std::vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
const std::vector<int> dx = {0, 1, 0, -1, 1, -1, 1, -1};

}  // namespace ebi