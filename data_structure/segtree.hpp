#pragma once

#include <vector>

namespace ebi {

template<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
struct segtree {
private:
    int n;
    std::vector<Monoid> data;
public:
    segtree(int _n) : n(1) {
        while(n < _n) {
            n <<= 1;
        }
        data.assign(2*n, e());
        return;
    }

    segtree(const std::vector<Monoid> &v) : n(1) {
        while(n < (int)v.size()) {
            n <<= 1;
        }
        data.assign(2*n, e());
        std::copy(v.begin(), v.end(), data.begin() + n);
        for(int i = n-1; i > 0; i--) {
            data[i] = op(data[i<<1|0], data[i<<1|1]);
        }
        return;
    }

    void set(int p, Monoid x) {
        p += n;
        data[p] = x;
        while(p > 1) {
            p >>= 1;
            data[p] = op(data[p<<1|0], data[p<<1|1]);
        }
        return;
    }

    Monoid get(int p) const {
        return data[p+n];
    }

    Monoid prod(int l, int r) const {
        Monoid left = e(), right = e();
        l += n;
        r += n;
        while(l < r) {
            if(l & 1) left = op(left, data[l++]);
            if(r & 1) right = op(data[--r], right);
            l >>= 1;
            r >>= 1;
        }
        return op(left, right);
    }

    Monoid all_prod() const {
        return data[1];
    }

    Monoid operator [] (int p) const { return data[n+p]; }
};

} // namespace ebi
