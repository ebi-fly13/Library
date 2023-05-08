#pragma once

#include <vector>

/*
    reference: https://scrapbox.io/data-structures/Sparse_Table
*/

namespace ebi {

template <class Band, Band (*op)(Band, Band)> struct sparse_table {
  public:
    sparse_table() = default;

    sparse_table(const std::vector<Band> &a) : n(a.size()) {
        table = std::vector(std::__lg(n) + 1, std::vector<Band>(n));
        for (int i = 0; i < n; i++) {
            table[0][i] = a[i];
        }
        for (int k = 1; (1 << k) <= n; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                table[k][i] =
                    op(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    void build(const std::vector<Band> &a) {
        n = (int)a.size();
        table = std::vector(std::__lg(n) + 1, std::vector<Band>(n));
        for (int i = 0; i < n; i++) {
            table[0][i] = a[i];
        }
        for (int k = 1; (1 << k) <= n; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                table[k][i] =
                    op(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    // [l, r)
    Band fold(int l, int r) {
        int k = std::__lg(r - l);
        return op(table[k][l], table[k][r - (1 << k)]);
    }

  private:
    int n;
    std::vector<std::vector<Band>> table;
};

}  // namespace ebi