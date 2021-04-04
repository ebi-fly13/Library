#pragma once

#include <vector>

namespace ebi {

template<class Field>
struct SquareMatrix {
private:
    using Self = SquareMatrix<Field>;
    using size_t = std::size_t;
    using u64 = std::uint_fast64_t;
public:
    SquareMatrix(Field val = 0) : mat(std::vector(N, std::vector<Field>(N, val))) { }

    Self operator+(const Self &rhs) const noexcept {
        return Self(*this) += rhs;
    }

    Self operator-(const Self &rhs) const noexcept {
        return Self(*this) -= rhs;
    }

    Self operator*(const Self &rhs) const noexcept {
        return Self(*this) *= rhs;
    }

    Self &operator+=(const Self &rhs) noexcept {
        for(size_t i =  0; i < N; ++i) {
            for(size_t j = 0; j < N; ++j) {
                mat[i][j] += rhs[i][j];
            }
        }
        return *this;
    }

    Self &operator-=(const Self &rhs) noexcept {
        for(size_t i =  0; i < N; ++i) {
            for(size_t j = 0; j < N; ++j) {
                mat[i][j] -= rhs[i][j];
            }
        }
        return *this;
    }

    Self &operator*=(const Self &rhs) noexcept {
        Self ret;
        for(size_t i = 0; i < N; ++i) {
            for(size_t j = 0; j < N; ++j) {
                for(size_t k = 0; k < N; ++k) {
                    ret[i][j] += mat[i][k]*rhs[k][j];
                }
            }
        }
        return *this = ret;
    }

    Self pow(u64 n) {
        Self res;
        for(size_t i = 0; i < N;  ++i) {
            res[i][i] = 1;
        }
        Self x = *this;
        while(n > 0) {
            if(n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    Field det() {
        Self res = *this;
        Field d = 1;
        for(size_t i = 0; i < N; ++i) {
            if(res[i][i] == 0) {
                int flag = -1;
                for(size_t j = i+1; j < N; ++j) {
                    if(res[j][i] != 0) {
                        flag = j;
                        break;
                    }
                }
                if(flag < 0) {
                    return 0;
                }
                std::swap(res[i], res[flag]);
                d = -d;
            }
            Field inv = res[i][i].inv();
            for(size_t j = i+1; j < N; ++j) {
                Field fac = res[j][i]*inv;
                for(size_t k = i; k < N; ++k) {
                    res[j][k] -= fac * res[i][k];
                }
            }
            d *= res[i][i];
        }
        return d;
    }

    static Self identity(size_t N) {
        Self res;
        for(size_t i = 0; i < N; ++i) {
            res[i][i] = 1;
        }
        return res;
    }

    std::vector<Field> &operator [] (size_t i) { return mat[i]; }

    static void set_size(size_t n) {
        N = n;
    }

private:
    std::vector<std::vector<Field>> mat;
    static size_t N;
};

template<class Field>
size_t SquareMatrix<Field>::N = 0;

}