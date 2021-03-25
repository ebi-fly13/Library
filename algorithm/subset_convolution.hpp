#pragma once

/*
    refernce: https://www.slideshare.net/wata_orz/ss-12131479
              https://37zigen.com/subset-convolution/
*/

#include <vector>

namespace ebi {

namespace internal {

template<class T>
std::vector<T> mul(const std::vector<T> &a, const std::vector<T> &b) {
    int n = a.size();
    std::vector<T> c(n,0);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(i+j>=n) break;
            c[i+j] += a[i]*b[j];
        }
    }
    return c;
}

} // namespace internal

template<class T>
std::vector<T> subset_convolution(const std::vector<T> &a, const std::vector<T> &b, int n) {
    std::vector f(1<<n, std::vector<T>(n+1,0)), g(1<<n, std::vector<T>(n+1,0));
    for(int S = 0; S < (1<<n); ++S) {
        f[S][0] = a[S];
        g[S][0] = b[S];
    }
    for(int i = n-1; i>=0; --i) {
        int V = 1<<i;
        for(int S = V; S < (1<<n); ++S) {
            S |= V;
            for(int j = n; j>=0; --j) {
                f[S][j] = f[S^V][j] + (j > 0 ? f[S][j-1] : 0);
                g[S][j] = g[S^V][j] + (j > 0 ? g[S][j-1] : 0);
            }
        }
    }
    std::vector fg(1<<n, std::vector<T>());
    for(int S = 0; S < (1<<n); ++S) {
        fg[S] = internal::mul(f[S], g[S]);
    }
    for(int i = 0; i<n; ++i) {
        int V = 1<<i;
        for(int S = V; S < (1<<n); ++S) {
            S |= V;
            for(int j = n; j>=0; --j) {
                fg[S][j] -= fg[S^V][j];
            }
        }
    }
    std::vector<T> h(1<<n);
    for(int S = 0; S < (1<<n); ++S) {
        h[S] = fg[S][__builtin_popcount(S)];
    }
    return h;
}

} // namespace ebi