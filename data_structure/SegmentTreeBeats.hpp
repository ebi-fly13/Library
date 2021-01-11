#pragma once

#include <algorithm>
#include <vector>

template<class S>
struct SegmentTreeBeats {
private:
    S INF = std::numeric_limits<S>::max()/4;
    std::vector<S> max_v, smax_v, max_c;
    std::vector<S> min_v, smin_v, min_c;
    std::vector<S> data;
    std::vector<S> lazy;
    int n;

    void update(int k) {
        data[k] = data[2*k+1] + data[2*k+2];

        if(max_v[2*k+1] != max_v[2*k+2]) {
            int p = 2*k+1, q = 2*k+2;
            if(max_v[p]<max_v[q]) std::swap(p,q);
            max_v[k] = max_v[p];
            max_c[k] = max_c[p];
            smax_v[k] = std::max(smax_v[p], max_v[q]);
        }
        else {
            max_v[k] = max_v[2*k+1];
            max_c[k] = max_c[2*k+1] + max_c[2*k+2];
            smax_v[k] = std::max(smax_v[2*k+1], smax_v[2*k+2]);
        }

        if(min_v[2*k+1] != min_v[2*k+2]) {
            int p = 2*k+1, q = 2*k+2;
            if(min_v[p]>min_v[q]) std::swap(p,q);
            min_v[k] = min_v[p];
            min_c[k] = min_c[p];
            smin_v[k] = std::min(smin_v[p] ,min_v[q]);
        }
        else {
            min_v[k] = min_v[2*k+1];
            min_c[k] = min_c[2*k+1] + min_c[2*k+2];
            smin_v[k] = std::min(smin_v[2*k+1], smin_v[2*k+2]);
        }
    }

    void update_node_max(int k, S x) {
        data[k] += (x - max_v[k]) * max_c[k];
        if(max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        }
        else if(max_v[k] == smin_v[k]) {
            max_v[k] = smin_v[k] = x;
        }
        else {
            max_v[k] = x;
        }
    }

    void update_node_min(int k, S x) {
        data[k] += (x - min_v[k]) * min_c[k];
        if(min_v[k] == max_v[k]) {
            min_v[k] = max_v[k] = x;
        }
        else if(min_v[k] == smax_v[k]) {
            min_v[k] = smax_v[k] = x;
        }
        else {
            min_v[k] = x;
        }
    }

    void pushdown(int k, int l, int r) {
        if(r-l<=1) return;
        if(lazy[k] != 0) {
            add_all(2*k+1, lazy[k], l, (l+r)/2);
            add_all(2*k+2, lazy[k],(l+r)/2, r);
            lazy[k] = 0;
        }
        if(max_v[k] < max_v[2*k+1]) {
            update_node_max(2*k+1, max_v[k]);
        }
        if(min_v[k] > min_v[2*k+1]) {
            update_node_min(2*k+1, min_v[k]);
        }
        if(max_v[k] < max_v[2*k+2]) {
            update_node_max(2*k+2, max_v[k]);
        }
        if(min_v[k] > min_v[2*k+2]) {
            update_node_min(2*k+2, min_v[k]);
        }
    }

    void add_all(int k, S x, int l, int r) {
        data[k] += x * (r-l);
        max_v[k] += x;
        if(smax_v[k] != -INF) smax_v[k] += x; 
        min_v[k] += x;
        if(smin_v[k] != INF) smin_v[k] += x;
        lazy[k] += x;
    }

public:
    SegmentTreeBeats(std::vector<S> v) : n(1) {
        int _n = v.size();
        while(n<_n) {
            n <<= 1;
        }
        data.assign(2*n-1, 0);
        lazy.assign(2*n-1, 0);
        max_v = smax_v = max_c = min_v = smin_v = min_c = std::vector<S>(2*n-1);
        for(int i = 0; i<n; i++) {
            int k = i+n-1;
            if(i<_n) data[k] = v[i];
            max_v[k] = data[k];
            smax_v[k] = -INF;
            max_c[k] = 1;
            min_v[k] = data[k];
            smin_v[k] = INF;
            min_c[k] = 1;
        }
        for(int i = n-2; i>=0; i--) {
            update(i);
        }
    }

    void apply_chmin(int l, int r, S x, int nl = 0, int nr = -1, int index = 0) {
        if(nr<0) nr = n;
        if(nr<=l || r<=nl || max_v[index]<=x) {
            return;
        }
        if(l<=nl && nr<=r && smax_v[index]<x) {
            update_node_max(index, x);
            return;
        }
        pushdown(index, nl, nr);
        apply_chmin(l, r, x, nl, (nl+nr)/2, 2*index+1);
        apply_chmin(l, r, x, (nl+nr)/2, nr, 2*index+2);
        update(index);
        return;
    }

    void apply_chmax(int l, int r, S x, int nl = 0, int nr = -1, int index = 0) {
        if(nr<0) nr = n;
        if(nr<=l || r<=nl || min_v[index]>=x) {
            return;
        }
        if(l<=nl && nr<=r && smin_v[index]>x) {
            update_node_min(index, x);
            return;
        }
        pushdown(index, nl, nr);
        apply_chmax(l, r, x, nl, (nl+nr)/2, 2*index+1);
        apply_chmax(l, r, x, (nl+nr)/2, nr, 2*index+2);
        update(index);
        return;
    }

    void apply(int l, int r, S x, int nl = 0, int nr = -1, int index = 0) {
        if(nr<0) nr = n;
        if(nr <= l || r <= nl) {
            return;
        }
        if(l <= nl && nr <= r) {
            add_all(index, x, nl, nr);
            return;
        }
        pushdown(index, nl, nr);
        apply(l, r, x, nl, (nl+nr)/2, 2*index+1);
        apply(l, r, x, (nl+nr)/2, nr, 2*index+2);
        update(index);
        return;
    }

    S prod(int l, int r, int nl = 0, int nr = -1, int index = 0) {
        if(nr<0) nr = n;
        if(nr<=l || r<=nl) {
            return 0;
        }
        if(l<=nl && nr<=r) {
            return data[index];
        }
        pushdown(index, nl, nr);
        return prod(l, r, nl, (nl+nr)/2, 2*index+1) + prod(l, r, (nl+nr)/2, nr, 2*index+2);
    }
};