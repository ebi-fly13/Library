#pragma once

#include <vector>

namespace ebi {

template<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
struct Segtree {
private:
    std::vector<Monoid> data;
    int n;
public:
    Segtree(int _n) : n(1) {
        while(n<_n){
            n <<= 1;
        }
        data.assign(2*n-1, e());
    }

    Segtree(std::vector<Monoid> v) : n(1) {
        int _n = v.size();
        while(n<_n){
            n <<= 1;
        }
        data.assign(2*n-1, e());
        for(int i = 0; i<_n; i++){
            data[n+i-1] = v[i];
        }
        for(int i = n-2; i>=0; i--){
            data[i] = op(data[2*i+1], data[2*i+2]);
        }
    }

    void set(int p, Monoid x){
        int k = n+p-1;
        data[k] = x;
        while(k>0){
            k = (k-1)/2;
            data[k] = op(data[2*k+1], data[2*k+2]);
        }
    }

    Monoid prod(int tl, int tr, int l=0, int r=-1, int index=0){
        if(r<0) r = n;
        if(tr<=l || r<=tl){
            return e();
        }
        if(tl<=l && r<=tr){
            return data[index];
        }
        return op(prod(tl, tr, l, (l+r)/2, 2*index+1), prod(tl, tr, (l+r)/2, r, 2*index+2));
    }

    Monoid all_prod() { return data[0]; }

    Monoid get(int p) { return data[n+p-1]; }

    Monoid operator [] (int p) { return data[n+p-1]; }
};

} // namespace ebi