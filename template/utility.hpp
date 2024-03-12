#pragma once

#include <limits>
#include <vector>

#include "../graph/base.hpp"
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

template <class T> T safe_ceil(T a, T b) {
    if (a % b == 0)
        return a / b;
    else if (a >= 0)
        return (a / b) + 1;
    else
        return -((-a) / b);
}

template <class T> T safe_floor(T a, T b) {
    if (a % b == 0)
        return a / b;
    else if (a >= 0)
        return a / b;
    else
        return -((-a) / b) - 1;
}

constexpr i64 LNF = std::numeric_limits<i64>::max() / 4;

constexpr int INF = std::numeric_limits<int>::max() / 2;

const std::vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
const std::vector<int> dx = {0, 1, 0, -1, 1, -1, 1, -1};

}  // namespace ebi