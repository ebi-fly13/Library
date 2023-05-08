#pragma once

#include <cstdint>
#include <vector>

namespace ebi {

template <class T, std::vector<T> (*convolution)(const std::vector<T> &,
                                                 const std::vector<T> &)>
T bostan_mori_algorithm(std::int64_t n, std::vector<T> p, std::vector<T> q) {
    while (n > 0) {
        auto q_neg = q;
        for (int i = 1; i < (int)q_neg.size(); i += 2) q_neg[i] = -q_neg[i];
        p = convolution(p, q_neg);
        q = convolution(q, q_neg);
        for (int i = (n & 1LL); i < (int)p.size(); i += 2) p[i >> 1] = p[i];
        p.resize(((int)p.size() + 1 - (n & 1LL)) / 2);
        for (int i = 0; i < (int)q.size(); i += 2) q[i >> 1] = q[i];
        q.resize(((int)q.size() + 1) / 2);
        n >>= 1;
    }
    return p[0] / q[0];
}

template <class T, std::vector<T> (*convolution)(const std::vector<T> &,
                                                 const std::vector<T> &)>
T kitamasa(std::int64_t n, std::vector<T> a, std::vector<T> c) {
    if (n < (int)a.size()) return a[n];
    const int d = c.size();
    for (auto &val : c) val = -val;
    c.insert(c.begin(), 1);
    auto p = convolution(a, c);
    p.resize(d);
    return bostan_mori_algorithm<T, convolution>(n, p, c);
}

}  // namespace ebi
