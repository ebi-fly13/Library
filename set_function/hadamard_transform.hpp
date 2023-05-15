#pragma once

#include <vector>

namespace ebi {

template <class T>
std::vector<T> hadamard_transform(std::vector<T> f, bool inverse = false) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) == 0) {
                T x = f[j], y = f[j | i];
                f[j] = x + y;
                f[j | i] = x - y;
            }
        }
    }
    if (inverse) {
        for (auto& x : f) {
            x /= T(n);
        }
    }
    return f;
}

}  // namespace ebi