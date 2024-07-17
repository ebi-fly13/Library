#pragma once

#include "../matrix/base.hpp"

namespace ebi {

template <class T> int find_pivot(const matrix<T> &a, int r, int w) {
    for (int i = r; i < a.row_size(); i++) {
        if (a[i][w] != 0) return i;
    }
    return -1;
}

template <class T> int gauss_jordan(matrix<T> &a) {
    int h = a.row_size(), w = a.column_size();
    int rank = 0;
    for (int j = 0; j < w; j++) {
        int pivot = find_pivot(a, rank, j);
        if (pivot == -1) continue;
        a.swap(rank, pivot);
        T inv = T(1) / a[rank][j];
        for (int k = j; k < w; k++) {
            a[rank][k] *= inv;
        }
        for (int i = 0; i < h; i++) {
            if (i != rank && a[i][j] != 0) {
                T x = a[i][j];
                for (int k = j; k < w; k++) {
                    a[i][k] -= a[rank][k] * x;
                }
            }
        }
        rank++;
    }
    return rank;
}

template <class T> int matrix<T>::rank() const {
    matrix<T> a = *this;
    return gauss_jordan(a);
}

template <class T> int gauss_jordan(matrix<T> &a, std::vector<T> &b) {
    int h = a.row_size(), w = a.column_size();
    assert(h == (int)b.size());
    int rank = 0;
    for (int j = 0; j < w; j++) {
        int pivot = find_pivot(a, rank, j);
        if (pivot == -1) continue;
        a.swap(rank, pivot);
        std::swap(b[rank], b[pivot]);
        T inv = T(1) / a[rank][j];
        for (int k = j; k < w; k++) {
            a[rank][k] *= inv;
        }
        b[rank] *= inv;
        for (int i = 0; i < h; i++) {
            if (i != rank && a[i][j] != 0) {
                T x = a[i][j];
                for (int k = j; k < w; k++) {
                    a[i][k] -= a[rank][k] * x;
                }
                b[i] -= b[rank] * x;
            }
        }
        rank++;
    }
    return rank;
}

template <class T>
std::optional<std::vector<std::vector<T>>> solve_linear_equations(
    matrix<T> a, std::vector<T> b) {
    assert(a.row_size() == (int)b.size());
    int rank = gauss_jordan(a, b);
    int h = a.row_size(), w = a.column_size();
    for (int i = rank; i < h; i++) {
        if (b[i] != 0) return std::nullopt;
    }
    std::vector res(1, std::vector<T>(w, 0));
    std::vector<int> pivot(w, -1);
    {
        int p = 0;
        for (int i = 0; i < rank; i++) {
            while (a[i][p] == 0) p++;
            res[0][p] = b[i];
            pivot[p] = i;
        }
    }
    for (int j = 0; j < w; j++) {
        if (pivot[j] == -1) {
            std::vector<T> x(w, 0);
            x[j] = -1;
            for (int i = 0; i < j; i++) {
                if (pivot[i] != -1) x[i] = a[pivot[i]][j];
            }
            res.emplace_back(x);
        }
    }
    return res;
}

}  // namespace ebi