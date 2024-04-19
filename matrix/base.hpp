#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <vector>

namespace ebi {

template <class T> struct matrix;

template <class T> matrix<T> identify_matrix(int n) {
    matrix<T> a(n, n);
    for (int i = 0; i < n; i++) {
        a[i][i] = 1;
    }
    return a;
}

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

    Self operator/(Self &rhs) const noexcept {
        return Self(*this) /= rhs;
    }

    friend Self operator*(const T &lhs, const Self &rhs) {
        return Self(rhs) *= lhs;
    }

    friend Self operator*(const Self &lhs, const T &rhs) {
        return Self(lhs) *= rhs;
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

    Self &operator/=(const Self &rhs) noexcept {
        auto ret = rhs.inv();
        assert(ret);
        return *this *= ret.value();
    }

    Self &operator*=(const T &rhs) noexcept {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (*this)[i][j] *= rhs;
            }
        }
        return *this;
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

    Self transposition() const {
        Self res(m, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][i] = data[i][j];
            }
        }
        return res;
    }

    std::optional<Self> inv() const {
        assert(row_size() == column_size());
        Self a = *this;
        Self b = identify_matrix<T>(n);
        for (int r = 0; r < n; r++) {
            for (int i = r; i < n; i++) {
                if (a[i][r] != 0) {
                    a.swap(r, i);
                    b.swap(r, i);
                    break;
                }
            }
            if (a[r][r] == 0) return std::nullopt;
            T x = a[r][r].inv();
            for (int j = 0; j < n; j++) {
                if (r < j) a[r][j] *= x;
                b[r][j] *= x;
            }
            for (int i = 0; i < n; i++) {
                if (i == r) continue;
                for (int j = 0; j < n; j++) {
                    if (r < j) a[i][j] -= a[i][r] * a[r][j];
                    b[i][j] -= a[i][r] * b[r][j];
                }
            }
        }
        return b;
    }

    Self pow(long long k) const {
        assert(row_size() == column_size() && k >= 0);
        Self res = identify_matrix<T>(row_size());
        Self x = *this;
        while (k) {
            if (k & 1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
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

template <class T> T det(matrix<T> a) {
    assert(a.row_size() == a.column_size());
    T d = 1;
    int n = a.row_size();
    for (int r = 0; r < n; r++) {
        if (a[r][r] == 0) {
            for (int i = r + 1; i < n; i++) {
                if (a[i][r] != 0) {
                    a.swap(r, i);
                    d = -d;
                }
            }
        }
        if (a[r][r] == 0) return 0;
        d *= a[r][r];
        T inv = a[r][r].inv();
        for (int i = r + 1; i < n; i++) {
            T x = a[i][r] * inv;
            for (int j = r; j < n; j++) {
                a[i][j] -= x * a[r][j];
            }
        }
    }
    return d;
}

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