#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../data_structure/Segtree.hpp"

#include <iostream>
#include <cstdint>

using i64 = std::int64_t;

i64 op(i64 a, i64 b) { return a+b; }
i64 e() { return (i64)0; }

int main(){
    int n,q; std::cin >> n >> q;
    std::vector<i64> a(n);
    for(int i = 0; i<n; i++){
        std::cin >> a[i];
    }
    ebi::Segtree<i64, op, e> seg(a);
    while(q--){
        int t;
        std::cin >> t;
        if(t==0){
            int p; i64 x; std::cin >> p >> x;
            seg.set(p,seg[p]+x);
        }
        else{
            int l,r; std::cin >> l >> r;
            std::cout << seg.prod(l,r) << std::endl;
        }
    }
    return 0;
}