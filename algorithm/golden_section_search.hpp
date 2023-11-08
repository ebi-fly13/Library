#pragma once

#include <cassert>
#include <concepts>
#include <functional>
#include <utility>

#include "../template/int_alias.hpp"

namespace ebi {

// ref: https://x.com/noshi91/status/1399003086362865673
template <std::integral S, class F,
          class T = decltype(std::declval<F>()(std::declval<S>())),
          class Compare = std::less<T>>
std::pair<i64, T> golden_section_search(F f, S min, S max,
                                        const Compare &compare = Compare()) {
    assert(min <= max);
    S a = min - 1, x, b;
    {
        S s = 1, t = 2;
        while (t < max - min + 2) {
            std::swap(s += t, t);
        }
        x = a + t - s;
        b = a + t;
    }
    T fx = f(x), fy;
    while (a + b != 2 * x) {
        S y = a + b - x;
        if (max < y || compare(fx, (fy = f(y)))) {
            b = a;
            a = y;
        } else {
            a = x;
            x = y;
            fx = fy;
        }
    }
    return {x, fx};
}

}  // namespace ebi