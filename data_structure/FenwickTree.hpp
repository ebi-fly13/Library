#pragma once

#include <vector>
#include <cassert>

namespace ebi {

template<class T>
struct FenwickTree {
private:
    int n;
    std::vector<T> data;

public:
    FenwickTree(int _n) : n(_n), data(std::vector<T>(_n+1, T(0))) { }

    void add(int i, T val) {
        i++;
        for(int x = i; x <= n; x += x & -x) {
            data[x] += val;
        }
    }

    T prefix_sum(int i) {
        assert(0<=i && i<=n);
        T ret = 0;
        for(int x = i; x>0; x -= x & -x) {
            ret += data[x];
        }
        return ret;
    }

    T sum(int l, int r) {
        return prefix_sum(r)-prefix_sum(l);
    }

    // prefix_sum(x) >= key となる最小のxを返す関数 O(log N)
    int lower_bound(T key) {
        if(key<=0) return 0;
        int x = 0;
        int max = 1;
        while((max<<1) <= n) max <<= 1;
        for(int k = max; k>0; k >>= 1) {
            if(x+k<=n && data[x+k]<key) {
                x += k;
                key -= data[x];
            }
        }
        return x+1;
    }
};

} // namespace ebi