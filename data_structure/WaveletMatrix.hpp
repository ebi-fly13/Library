#pragma once

#include "../data_structure/bitVector.hpp"

/*
    reference: https://miti-7.hatenablog.com/entry/2018/04/28/152259
*/

#include <vector>
#include <limits>
#include <map>

template<class T>
struct WaveletMatrix {
private:
    int wordsize = std::numeric_limits<T>::digits;
    int n;
    std::vector<bitVector> mat;
    std::vector<int> border;
    std::map<T,int> map;

public:
    WaveletMatrix(std::vector<T> v) : n(v.size()), mat(wordsize, bitVector(n)), border(wordsize) {
        for(int bit = wordsize-1; bit>=0; --bit) {
            std::vector<T> one, zero;
            zero.reserve(n);
            for(int i = 0; i<n; ++i) {
                if(v[i] & ((T)1 << bit)) {
                    one.emplace_back(v[i]);
                    mat[bit].set(i, 1);
                }
                else {
                    zero.emplace_back(v[i]);
                }
            }
            border[bit] = zero.size();
            mat[bit].build();
            std::copy(one.begin(), one.end(), std::back_inserter(zero));
            v = zero;
        }
        for(int i = 0; i<n; i++) {
            if(map[v[i]]==0) {
                map[v[i]] = i;
            }
        }
    }

    T access(int i) {
        T val = 0;
        int k = i;
        for(int bit = wordsize-1; bit>=0; --bit) {
            if(mat[bit].access(k) == 1) {
                val |= ((T)1 << bit);
                k = border[bit] + mat[bit].rank(k);
            }
            else {
                k = k-mat[bit].rank(k);
            }
        }
        return val;
    }

    int rank(int r, T x) {
        int k = r;
        for(int bit = wordsize-1; bit>=0; --bit) {
            if(x & ((T)1 << bit)) {
                k = border[bit] + mat[bit].rank(k);
            }
            else {
                k = k-mat[bit].rank(k);
            }
        }
        return k-map[x];
    }

    int select(T x, int k) {
        k = map[x] + k;
        for(int bit = 0; bit<wordsize; ++bit) {
            if(x & ((T)1 << bit)) {
                k = mat[bit].select(k-border[bit]);
            }
            else {
                k = mat[bit].select0(k);
            }
        }
        return k-1;
    }

    T quantile(int l, int r, int k) {
        T val = 0;
        for(int bit = wordsize-1; bit>=0; --bit) {
            int rank_l = mat[bit].rank(l);
            int rank_r = mat[bit].rank(r);
            int one = rank_r - rank_l;
            int zero = r-l-one;
            if(k<=zero) {
                l -= rank_l;
                r -= rank_r;
            }
            else {
                val |= (T)1 << bit;
                l = border[bit] + rank_l;
                r = border[bit] + rank_r;
                k -= zero;
            }
        }
        return val;
    }
};