#pragma once

#include <vector>

template<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
struct DuelSegtree {
private:
    std::vector<Monoid> data;
    int n;
public:
    DuelSegtree(int _n) : n(1) {
        while(n<_n){
            n <<= 1;
        }
        data.assign(2*n-1, e());
    }

    DuelSegtree(std::vector<Monoid> v) : n(1) {
        int _n = v.size();
        while(n<_n){
            n <<= 1;
        }
        data.assign(2*n-1, e());
        for(int i = 0; i<_n; i++){
            data[i+n-1] = v[i];
        }
    }

    Monoid get(int p) {
        int k = p+n-1;
        Monoid val = data[k];
        while(k>0){
            k = (k-1)/2;
            val = op(val, data[k]);
        }
        return val;
    }

    void apply(int tl, int tr, Monoid x,int l = 0, int r = -1, int index = 0) {
        if(r<0) r = n;
        if(tr<=l || r<=tl) {
            return;
        }
        if(tl<=l && r<=tr) {
            data[index] = op(data[index], x);
            return;
        }
        apply(tl, tr, x, l, (l+r)/2, 2*index+1);
        apply(tl, tr, x,(l+r)/2, r, 2*index+2);
        return;
    }
};