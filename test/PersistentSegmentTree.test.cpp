#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../data_structure/PersistentSegmentTree.hpp"

#include <iostream>
#include <cstdint>
#include <vector>

using S = std::int64_t;
S op(S a, S b) {
    return a+b;
}
S e() {
    return 0;
}

int main() {
    int n,q;
    std::cin >> n >> q;
    std::vector<S> a(n);
    for(int i = 0; i<n; ++i) {
        std::cin >> a[i];
    }
    ebi::PersistentSegmentTree<S, op, e> seg(a);
    std::vector<int> Q,L,R;
    while(q--) {
        int flag;
        std::cin >> flag;
        if(flag == 0) {
            int p;
            S x;
            std::cin >> p >> x;
            seg.set(seg.latest(), p, seg.get(seg.latest(), p)+x);
        }
        else {
            int l,r;
            std::cin >> l >> r;
            Q.emplace_back(seg.latest());
            L.emplace_back(l);
            R.emplace_back(r);
        }
    }
    for(int i = 0; i<(int)Q.size(); ++i) {
        std::cout << seg.prod(Q[i], L[i], R[i]) << std::endl;
    }
}