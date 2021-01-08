#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../data_structure/DynamicSegmentTree.hpp"
#include "../utility/modint.hpp"

#include <iostream>

using mint = modint998244353;

struct F {
    mint a,b;
    F(mint a, mint b) : a(a), b(b) { }
};

F op(F f1, F f2) {
    return F(f2.a*f1.a, f2.a*f1.b+f2.b);
}

F e() {
    return F(1,0);
}

int main(){
    int n,q; std::cin >> n >> q;
    DynamicSegmentTree<F, op, e> seg(n);
    for(int i = 0; i<n; i++) {
        int a,b; std::cin >> a >> b;
        seg.set(i, F(a,b));
    }
    while(q--) {
        int t; std::cin >> t;
        if(t==0) {
            int p, c, d;
            std::cin >> p >> c >> d;
            seg.set(p, F(c,d));
        }
        else {
            int l,r,x; std::cin >> l >> r >> x;
            auto f = seg.prod(l,r);
            std::cout << (f.a*x + f.b).value() << std::endl;
        }
    }
}