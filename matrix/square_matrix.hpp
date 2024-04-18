#pragma once

#include <iostream>
#include <vector>

namespace ebi {

template <class Field, int id> struct square_matrix {
  private:
    using Self = square_matrix<Field, id>;

  public:
    square_matrix(Field val = 0)
        : mat(std::vector(N, std::vector<Field>(N, val))) {}

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
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                mat[i][j] += rhs[i][j];
            }
        }
        return *this;
    }

    Self &operator-=(Self &rhs) noexcept {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                mat[i][j] -= rhs[i][j];
            }
        }
        return *this;
    }

    Self &operator*=(Self &rhs) noexcept {
        Self ret;
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < N; ++k) {
                for (int j = 0; j < N; ++j) {
                    ret[i][j] += mat[i][k] * rhs[k][j];
                }
            }
        }
        return *this = ret;
    }

    Self pow(long long n) const {
        Self res;
        for (int i = 0; i < N; ++i) {
            res[i][i] = 1;
        }
        Self x = *this;
        while (n > 0) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    Field det() const {
        Self res = *this;
        Field d = 1;
        for (int i = 0; i < N; ++i) {
            if (res[i][i] == 0) {
                int flag = -1;
                for (int j = i + 1; j < N; ++j) {
                    if (res[j][i] != 0) {
                        flag = j;
                        break;
                    }
                }
                if (flag < 0) {
                    return 0;
                }
                std::swap(res[i], res[flag]);
                d = -d;
            }
            Field inv = res[i][i].inv();
            for (int j = i + 1; j < N; ++j) {
                Field fac = res[j][i] * inv;
                for (int k = i; k < N; ++k) {
                    res[j][k] -= fac * res[i][k];
                }
            }
            d *= res[i][i];
        }
        return d;
    }

    static Self identity() {
        Self res;
        for (int i = 0; i < N; ++i) {
            res[i][i] = 1;
        }
        return res;
    }

    std::vector<Field> &operator[](int i) {
        return mat[i];
    }

    const std::vector<Field> &operator[](int i) const {
        return mat[i];
    }

    static void set_size(int n) {
        N = n;
    }

    int size() const {
        return N;
    }

  private:
    std::vector<std::vector<Field>> mat;
    static int N;
};

template <class Field, int id> int square_matrix<Field, id>::N = 0;

template <class Field, int id>
std::istream &operator>>(std::istream &os, square_matrix<Field, id> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            os >> a[i][j];
        }
    }
    return os;
}

template <class Field, int id>
std::ostream &operator<<(std::ostream &os, const square_matrix<Field, id> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            os << a[i][j];
            if (j < n - 1) os << ' ';
        }
        if (i < n - 1) os << '\n';
    }
    return os;
}

}  // namespace ebi