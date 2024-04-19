#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <vector>

namespace ebi {

template <class T> struct matrix {
  private:
    using Self = matrix<T>;

  public:
    matrix(int n_, int m_, T init_val = 0)
        : n(n_), m(m_), data(n * m, init_val) {}

    matrix(const std::vector<std::vector<T>> &a)
        : n((int)a.size()), m((int)a[0].size()) {
        data = std::vector(n * m);
        for (int i = 0; i < n; i++) {
            std::copy(a[i].begin(), a[i].end(), data.begin() + i * m);
        }
    }

    Self operator+(Self &rhs) const noexcept {
        return Self(*this) += rhs;
    }

    Self operator-(Self &rhs) const noexcept {
        return Self(*this) -= rhs;
    }

    Self operator*(Self &rhs) const noexcept {
        return Self(*this) *= rhs;
    }

    Self &operator+=(Self &rhs) noexcept {
        assert(this->size() == rhs.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                data[i][j] += rhs[i][j];
            }
        }
        return *this;
    }

    Self &operator-=(Self &rhs) noexcept {
        assert(this->size() == rhs.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                data[i][j] -= rhs[i][j];
            }
        }
        return *this;
    }

    Self &operator*=(Self &rhs) noexcept {
        int h = n, w = rhs.column_size();
        assert(m == rhs.row_size());
        Self ret(h, w);
        for (int i = 0; i < h; ++i) {
            for (int k = 0; k < m; ++k) {
                for (int j = 0; j < w; ++j) {
                    ret[i][j] += (*this)[i][k] * rhs[k][j];
                }
            }
        }
        return *this = ret;
    }

    const auto operator[](int i) const {
        return std::ranges::subrange(data.begin() + i * m,
                                     data.begin() + (i + 1) * m);
    }

    auto operator[](int i) {
        return std::ranges::subrange(data.begin() + i * m,
                                     data.begin() + (i + 1) * m);
    }

    void swap(int i, int j) {
        std::swap_ranges(data.begin() + i * m, data.begin() + (i + 1) * m,
                         data.begin() + j * m);
    }

    int row_size() const {
        return n;
    }

    int column_size() const {
        return m;
    }

    std::pair<int, int> size() const {
        return {n, m};
    }

  private:
    int n, m;
    std::vector<T> data;
};

template <class T> std::istream &operator>>(std::istream &os, matrix<T> &a) {
    for (int i = 0; i < a.row_size(); i++) {
        for (int j = 0; j < a.column_size(); j++) {
            os >> a[i][j];
        }
    }
    return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const matrix<T> &a) {
    for (int i = 0; i < a.row_size(); i++) {
        for (int j = 0; j < a.column_size(); j++) {
            os << a[i][j];
            if (j < a.column_size() - 1) os << ' ';
        }
        if (i < a.row_size() - 1) os << '\n';
    }
    return os;
}

}  // namespace ebi