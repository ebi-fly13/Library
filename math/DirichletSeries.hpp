#pragma once

/*
    verify: https://atcoder.jp/contests/arc116/submissions/21477123
    refernce: https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c#toc4
*/

#include <vector>
#include <cstdint>
#include <cmath>

namespace ebi {

template<class T>
struct DirichletSeries {
private:
    using Self = DirichletSeries<T>;
    using size_t = std::size_t;
    using u64 = std::uint_fast64_t;

    static size_t N,K,L;
    std::vector<T> a,A;
public:
    DirichletSeries() : a(K+1), A(L+1) { }

    Self operator*(const Self &rhs) const noexcept {
        return Self(*this) *= rhs;
    }

    Self operator*=(const Self &rhs) noexcept {
        Self ret;
        for(size_t i = 1; i < K+1; ++i) {
            for(size_t j = 1; j < K/i + 1; ++j) {
                ret.a[i*j] += a[i]*rhs.a[j];
            }
        }
        std::vector<T> sum_a = a, sum_b = rhs.a;
        for(size_t i = 1; i < K; ++i) {
            sum_a[i+1] += sum_a[i];
            sum_b[i+1] += sum_b[i];
        }
        auto get_A = [&](size_t x) -> T {
            if(x <= K) {
                return sum_a[x];
            }
            else {
                return A[N/x];
            }
        };
        auto get_B = [&](size_t x) -> T {
            if(x <= K) {
                return sum_b[x];
            }
            else {
                return rhs.A[N/x];
            }
        };
        for(size_t l = 1; l < L+1; ++l) {
            size_t n = N/l;
            size_t m = std::floor(std::sqrt(n));
            for(size_t i = 1; i < m + 1; ++i) {
                ret.A[l] += a[i] * get_B(n/i) + rhs.a[i] * (get_A(n/i) - get_A(m));
            }
        }
        return *this = ret;
    }

    Self pow(u64 n) const {
        Self res;
        res.a[1] = 1;
        res.A.assign(L+1, 1);
        Self x = *this;
        while(n>0){
            if(n&1) res = res * x;
            x = x*x;
            n>>=1;
        }
        return res;
    }

    T get_sum() {
        return A[1];
    }

    static Self zeta() {
        Self ret;
        ret.a.assign(K+1, 1);
        for(size_t i = 1; i < L + 1; ++i) {
            ret.A[i] = N/i;
        }
        return ret;
    }

    static void set_size(size_t n) {
        N = n;
        K = std::ceil(std::cbrt(n*n));
        L = std::ceil(std::cbrt(n));
    }
};

template<class T>
size_t DirichletSeries<T>::N = 1000000;
template<class T>
size_t DirichletSeries<T>::K = 10000;
template<class T>
size_t DirichletSeries<T>::L = 100;

}