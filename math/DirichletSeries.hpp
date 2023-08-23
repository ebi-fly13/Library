#pragma once

#include <functional>
#include <numeric>
#include <vector>

#include "../template/int_alias.hpp"
#include "../convolution/dirichlet_convolution.hpp"

namespace ebi {

template <class T, int id> struct DirichletSeries {
  private:
    using Self = DirichletSeries<T, id>;

    void set(std::function<T(i64)> f, std::function<T(i64)> F) {
        for (int i = 1; i <= K; i++) {
            a[i] = f(i);
        }
        for (int i = 1; i <= L; i++) {
            A[i] = F(N / i);
        }
    }

  public:
    DirichletSeries() : a(K + 1), A(L + 1) {}

    DirichletSeries(std::function<T(i64)> f, std::function<T(i64)> F, bool _is_multiplicative = false)
        : a(K + 1), A(L + 1), is_multiplicative(_is_multiplicative)  {
        set(f, F);
    }

    Self operator+(const Self &rhs) const noexcept {
        return Self(*this) += rhs;
    }
    Self operator-(const Self &rhs) const noexcept {
        return Self(*this) -= rhs;
    }
    Self operator*(const Self &rhs) const noexcept {
        return Self(*this) *= rhs;
    }
    Self operator/(const Self &rhs) const noexcept {
        return Self(*this) /= rhs;
    }

    Self operator+=(const Self &rhs) noexcept {
        for (int i = 1; i <= K; i++) {
            a[i] += rhs.a[i];
        }
        for (int i = 1; i <= L; i++) {
            A[i] += rhs.A[i];
        }
        return *this;
    }

    Self operator-=(const Self &rhs) noexcept {
        for (int i = 1; i <= K; i++) {
            a[i] -= rhs.a[i];
        }
        for (int i = 1; i <= L; i++) {
            A[i] -= rhs.A[i];
        }
        return *this;
    }

    Self operator*=(const Self &rhs) noexcept {
        Self ret;
        if(is_multiplicative && rhs.is_multiplicative) {
            ret.a = dirichlet_convolution_multiplicative_function(a, rhs.a);
            ret.is_multiplicative = true;
        }
        else if(is_multiplicative) {
            ret.a = dirichlet_convolution_left_is_multiplicative_function(a, rhs.a);
        }
        else if(rhs.is_multiplicative) {
            ret.a = dirichlet_convolution_left_is_multiplicative_function(rhs.a, a);
        }
        else {
            ret.a = dirichlet_convolution(a, rhs.a);
        }
        std::vector<T> sum_a = a, sum_b = rhs.a;
        for (int i = 1; i < K; i++) {
            sum_a[i + 1] += sum_a[i];
            sum_b[i + 1] += sum_b[i];
        }
        auto get_A = [&](i64 x) -> T {
            if (x <= K) {
                return sum_a[x];
            } else {
                return A[N / x];
            }
        };
        auto get_B = [&](i64 x) -> T {
            if (x <= K) {
                return sum_b[x];
            } else {
                return rhs.A[N / x];
            }
        };
        for (i64 l = L, m = 1; l >= 1; l--) {
            i64 n = N / l;
            while (m * m <= n) m++;
            m--;
            for (int i = 1; i <= m; i++) {
                ret.A[l] +=
                    a[i] * get_B(n / i) + (get_A(n / i) - get_A(m)) * rhs.a[i];
            }
        }
        return ret;
    }

    // c = a / b
    Self operator/=(const Self &b) noexcept {
        Self c = *this;
        T inv_a = b.a[1].inv();
        for (int i = 1; i <= K; i++) {
            c.a[i] *= inv_a;
            for (int j = 2; i * j <= K; j++) {
                c.a[i * j] -= c.a[i] * b.a[j];
            }
        }
        std::vector<T> sum_b = b.a, sum_c = c.a;
        for (int i = 1; i < K; ++i) {
            sum_b[i + 1] += sum_b[i];
            sum_c[i + 1] += sum_c[i];
        }
        auto get_B = [&](i64 x) -> T {
            if (x <= K) {
                return sum_b[x];
            } else {
                return b.A[N / x];
            }
        };
        auto get_C = [&](i64 x) -> T {
            if (x <= K) {
                return sum_c[x];
            } else {
                return c.A[N / x];
            }
        };
        for (i64 l = L, m = 1; l >= 1; l--) {
            i64 n = N / l;
            while (m * m <= n) m++;
            m--;
            for (int i = 2; i <= m; i++) {
                c.A[l] -= b.a[i] * get_C(n / i);
            }

            for (int i = 1; i <= m; i++) {
                c.A[l] -= c.a[i] * (get_B(n / i) - get_B(m));
            }
            c.A[l] *= inv_a;
        }
        return *this = c;
    }

    Self pow(u64 n) const {
        Self res;
        res.a[1] = 1;
        res.is_multiplicative = is_multiplicative;
        std::fill(res.A.begin(), res.A.end(), 1);
        Self x = *this;
        while (n > 0) {
            if (n & 1) res = res * x;
            x = x * x;
            n >>= 1;
        }
        return res;
    }

    T get_sum() {
        return A[1];
    }

    static Self zeta() {
        Self ret;
        std::fill(ret.a.begin(), ret.a.end(), 1);
        for (int i = 1; i <= L; i++) {
            ret.A[i] = N / i;
        }
        ret.is_multiplicative = true;
        return ret;
    }

    static Self zeta1() {
        Self ret;
        ret.is_multiplicative = true;
        std::iota(ret.a.begin(), ret.a.end(), 0);
        T inv2 = T(2).inv();
        for (int i = 1; i <= L; i++) {
            i64 n = N / i;
            ret.A[i] = T(n) * T(n + 1) * inv2;
        }
        return ret;
    }

    static Self zeta2() {
        Self ret;
        ret.is_multiplicative = true;
        for(int i = 1; i <= K; i++) {
            ret.a[i] = i * i;
        }
        T inv6 = T(6).inv();
        for(int i = 1; i <= L; i++) {
            i64 n = N / i;
            ret.A[i] = T(n) * T(n + 1) * T(2 * n + 1) * inv6;
        }
    }

    static void set_size(i64 n) {
        N = n;
        if (N <= 10) {
            K = N;
            L = 1;
        } else if (N <= 5000) {
            K = 1;
            while (K * K < N) K++;
            L = (N + K - 1) / K;
        } else {
            L = 1;
            while (L * L * L / 50 < N) L++;
            K = (N + L - 1) / L;
        }
    }

    static void set_size_multiplicative(i64 n) {
        N = n;
        L = 1;
        while(L * L * L < N) L++;
        K = L * L;
    }

  private:
    static i64 N, K, L;
    static std::vector<std::pair<int,int>> prime_pow_table;
    std::vector<T> a, A;
    bool is_multiplicative= false;
};

template <class T, int id> i64 DirichletSeries<T, id>::N = 1000000;
template <class T, int id> i64 DirichletSeries<T, id>::K = 10000;
template <class T, int id> i64 DirichletSeries<T, id>::L = 100;
template <class T, int id> std::vector<std::pair<int,int>> DirichletSeries<T, id>::prime_pow_table = {};

}  // namespace ebi