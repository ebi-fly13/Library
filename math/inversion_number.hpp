#pragma once

#include <cassert>
#include <limits>
#include <vector>

#include "../data_structure/compress.hpp"
#include "../data_structure/fenwick_tree.hpp"
#include "../utility/int_alias.hpp"

namespace ebi {

i64 inversion_number_max_n(const std::vector<int> &a, int n = 200000) {
    fenwick_tree<i64> fw(n);
    i64 res = 0;
    for (auto x : a) {
        assert(0 <= x && x < n);
        res += fw.sum(x + 1, n);
        fw.add(x, 1);
    }
    return res;
}

template <class T> i64 inversion_number(const std::vector<T> &a) {
    compress<T> cp;
    for (const auto &x : a) {
        cp.add(x);
    }
    cp.build();
    std::vector<int> ca;
    ca.reserve(a.size());
    for (const auto &x : a) {
        ca.emplace_back(cp.get(x));
    }
    return inversion_number_max_n(ca, cp.size());
}

}  // namespace ebi