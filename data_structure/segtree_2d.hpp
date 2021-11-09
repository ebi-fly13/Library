#include <vector>
#include <algorithm>

/*
    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937
    verify   : http://codeforces.com/contest/893/submission/125531718
*/

#include "../data_structure/segtree.hpp"

namespace ebi {

template<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
struct segtree_2d {
private:
    Monoid prod(int l, int r, int x, int y, int nl, int nr, int k) {
        if(r <= nl || nr <= l) {
            return e();
        }
        if(l <= nl && nr <= r) {
            int tx = std::lower_bound(data[k].begin(), data[k].end(), x) - data[k].begin();
            int ty = std::lower_bound(data[k].begin(), data[k].end(), y) - data[k].begin();
            return seg[k].prod(tx, ty);
        }
        return op(prod(l, r, x, y, nl, (nl+nr)/2, 2*k + 1), prod(l, r, x, y, (nl+nr)/2, nr, 2*k + 2));
    }

    void pre_prod(int l, int r, int x, int y, int nl, int nr, int k) {
        if(r <= nl || nr <= l) {
            return;
        }
        if(l<=nl && nr <= r) {
            data[k].emplace_back(x);
            data[k].emplace_back(y);
            return;
        }
        pre_prod(l, r, x, y, nl, (nl+nr)/2, 2*k + 1);
        pre_prod(l, r, x, y, (nl+nr)/2, nr, 2*k + 2);
    }
public:
    segtree_2d(int _n) : n(1) {
        while(n < _n) {
            n <<= 1;
        }
        data.resize(2*n-1);
    }

    void set(int x, int y, Monoid val) {
        int k = n+x-1;
        int ty = std::lower_bound(data[k].begin(), data[k].end(), y) - data[k].begin();
        seg[k].set(ty, op(seg[k].get(ty), val));
        while(k > 0) {
            k = (k-1)/2;
            ty = std::lower_bound(data[k].begin(), data[k].end(), y) - data[k].begin();
            seg[k].set(ty, op(seg[k].get(ty), val));
        }
    }

    Monoid prod(int l, int r, int x, int y) {
        return prod(l, r, x, y, 0, n, 0);
    }

    void build() {
        for(int i = 0; i < 2*n - 1; ++i) {
            std::sort(data[i].begin(), data[i].end());
            data[i].erase(std::unique(data[i].begin(), data[i].end()), data[i].end());
            seg.emplace_back(segtree<Monoid, op, e>(int(data[i].size())));
        }
    }

    void pre_set(int x, int y) {
        int k = n+x-1;
        data[k].emplace_back(y);
        while(k > 0) {
            k = (k-1)/2;
            data[k].emplace_back(y);
        }
    }

    void pre_prod(int l, int r, int x, int y) {
        pre_prod(l, r, x, y, 0, n, 0);
    }
private:
    std::vector< std::vector< Monoid > > data;
    std::vector< segtree< Monoid, op, e> > seg;
    int n;
};

}