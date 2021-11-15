#pragma once

#include <vector>

namespace ebi {

template<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
struct segtree {
private:
    int n;
    int size;
    std::vector<Monoid> data;
public:
    segtree(int _n) : n(_n), size(1) {
        while(size < _n) {
            size <<= 1;
        }
        data.assign(2*size, e());
        return;
    }

    segtree(const std::vector<Monoid> &v) : size(1) {
        n = (int)v.size();
        while(size < n) {
            size <<= 1;
        }
        data.assign(2*size, e());
        std::copy(v.begin(), v.end(), data.begin() + size);
        for(int i = size-1; i > 0; i--) {
            data[i] = op(data[i<<1|0], data[i<<1|1]);
        }
        return;
    }

    void set(int p, Monoid x) {
        assert(0 <= p && p < n);
        p += size;
        data[p] = x;
        while(p > 1) {
            p >>= 1;
            data[p] = op(data[p<<1|0], data[p<<1|1]);
        }
        return;
    }

    Monoid get(int p) const {
        assert(0 <= p && p < n);
        return data[p+size];
    }

    Monoid prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        Monoid left = e(), right = e();
        l += size;
        r += size;
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

    Monoid operator [] (int p) const { return data[size+p]; }
};

} // namespace ebi
