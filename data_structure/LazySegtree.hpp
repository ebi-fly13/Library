#pragma once

/*
    reference: https://beet-aizu.hatenablog.com/entry/2017/12/01/225955
               https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html
*/

#include <vector>
#include <cassert>

namespace ebi {

template<
    class S,
    S (*op)(S, S),
    S (*e)(),
    class F,
    S (*mapping)(F, S),
    F (*merge)(F, F),
    F (*id)()>
struct LazySegtree {
private:
    std::vector<S> data;
    std::vector<F> lazy;
    int n;

    void eval(int index, int l, int r) {
        data[index] = mapping(lazy[index], data[index]);
        if(r-l>1) {
            lazy[2*index+1] = merge(lazy[index] ,lazy[2*index+1]);
            lazy[2*index+2] = merge(lazy[index] ,lazy[2*index+2]);
        }
        lazy[index] = id();
    }

    S _prod(int l, int r, int nl = 0, int nr = -1, int index = 0) {
        if(nr < 0) nr = n;
        if(nr<=l || r<=nl) {
            return e();
        }
        eval(index, nl, nr);
        if(l<=nl && nr<=r) {
            return data[index];
        }
        return op(_prod(l, r, nl, (nl+nr)/2, 2*index+1), _prod(l, r, (nl+nr)/2, nr, 2*index+2));
    }

    void _apply(int l, int r, F f, int nl = 0, int nr = -1, int index = 0) {
        if(nr<0) nr = n;
        eval(index, nl, nr);
        if(nr<=l || r<=nl) return;
        if(l<=nl && nr<=r) {
            lazy[index] = merge(f, lazy[index]);
            eval(index, nl, nr);
            return;
        }
        _apply(l, r, f, nl, (nl+nr)/2, 2*index+1);
        _apply(l, r, f, (nl+nr)/2, nr, 2*index+2);
        data[index] = op(data[2*index+1], data[2*index+2]);
        return;
    }

public:
    LazySegtree(int _n) : n(1) {
        while(n<_n) {
            n <<= 1;
        }
        data.assign(2*n-1, e());
        lazy.assign(2*n-1, id());
    }

    LazySegtree(std::vector<S> v) : n(1) {
        int _n = v.size();
        while(n<_n) {
            n <<= 1;
        }
        data.assign(2*n-1, e());
        lazy.assign(2*n-1, id());
        for(int i = 0; i<_n; i++) {
            data[i+n-1] = v[i];
        }
        for(int i = n-2; i>=0; i--) {
            data[i] = op(data[2*i+1], data[2*i+2]);
        }
    }

    S prod(int l, int r) {
        return _prod(l, r);
    }

    S all_prod() {
        eval(0,0,n);
        return data[0];
    }

    void apply(int l, int r, F f) {
        _apply(l, r, f);
    }

    S get(int i) {
        int l = 0, r = n;
        int k = 0;
        while(r-l>1) {
            eval(k, l, r);
            int mid = (l+r)/2;
            if(i<mid) {
                k = 2*k+1;
                r = mid;
            }
            else {
                k = 2*k+2;
                l = mid;
            }
        }
        eval(k, l, r);
        return data[k];
    }
};

} // namespace ebi