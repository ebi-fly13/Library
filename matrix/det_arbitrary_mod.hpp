#pragma once

#include <cassert>

#include "../matrix/base.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint> mint det_arbitrary_mod(matrix<mint> a) {
    assert(a.row_size() == a.column_size());
    bool sgn = true;
    int n = a.row_size();
    for (int r = 0; r < n; r++) {
        if (a[r][r] == 0) {
            for (int i = r + 1; i < n; i++) {
                if (a[i][r] != 0) {
                    sgn = !sgn;
                    a.swap(r, i);
                    break;
                }
            }
        }
        if (a[r][r] == 0) return 0;
        for (int i = r + 1; i < n; i++) {
            while (a[i][r] != 0) {
                long long q = a[r][r].val() / a[i][r].val();
                for (int j = r; j < n; j++) {
                    a[r][j] -= a[i][j] * q;
                }
                a.swap(r, i);
                sgn = !sgn;
            }
        }
    }
    mint d = sgn ? 1 : -1;
    for (int i = 0; i < n; i++) d *= a[i][i];
    return d;
}

}  // namespace ebi