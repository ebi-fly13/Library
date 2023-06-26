#pragma once

#include <cassert>
#include <vector>

namespace ebi {

template <class S, S (*op)(S, S)> struct sparse_table_2d {
    sparse_table_2d(const std::vector<std::vector<S>> &table) {
        h = table.size();
        w = h > 0 ? table[0].size() : 0;
        lg_table.resize(std::max(h, w) + 1);
        lg_table[0] = lg_table[1] = 0;
        for (int i = 2; i <= std::max(h, w); i++)
            lg_table[i] = lg_table[i >> 1] + 1;
        lg_h = lg_table[h];
        lg_w = lg_table[w];
        st = std::vector(
            lg_h + 1, std::vector(lg_w + 1, std::vector(h, std::vector<S>(w))));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                st[0][0][i][j] = table[i][j];
            }
        }
        for (int k = 0; (1 << k) <= h; k++) {
            for (int l = 0; (1 << l) <= w; l++) {
                if (k == 0 && l == 0) continue;
                for (int i = 0; i + (1 << k) <= h; i++) {
                    for (int j = 0; j + (1 << l) <= w; j++) {
                        if (k > 0)
                            st[k][l][i][j] =
                                op(st[k - 1][l][i][j],
                                   st[k - 1][l][i + (1 << (k - 1))][j]);
                        else
                            st[k][l][i][j] =
                                op(st[k][l - 1][i][j],
                                   st[k][l - 1][i][j + (1 << (l - 1))]);
                    }
                }
            }
        }
    }

    S prod(int l, int d, int r, int u) const {
        assert(l < r && d < u);
        int lg_lr = lg_table[r - l];
        int lg_du = lg_table[u - d];
        return op(
            op(st[lg_lr][lg_du][l][d], st[lg_lr][lg_du][r - (1 << lg_lr)][d]),
            op(st[lg_lr][lg_du][l][u - (1 << lg_du)],
               st[lg_lr][lg_du][r - (1 << lg_lr)][u - (1 << lg_du)]));
    }

  private:
    int h, w;
    int lg_h, lg_w;
    std::vector<int> lg_table;
    std::vector<std::vector<std::vector<std::vector<S>>>> st;
};

}  // namespace ebi