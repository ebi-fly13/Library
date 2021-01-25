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

struct query {
    int ver;
    int l,r;
};

int main() {
    int n,q;
    std::cin >> n >> q;
    std::vector<S> a(n);
    for(int i = 0; i<n; ++i) {
        std::cin >> a[i];
    }
    ebi::PersistentSegmentTree<S, op, e> seg(a);
    std::vector<query> Q;
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
            query p;
            std::cin >> p.l >> p.r;
            p.ver = seg.latest();
            Q.emplace_back(p);
        }
    }
    for(int i = 0; i<(int)Q.size(); ++i) {
        std::cout << seg.prod(Q[i].ver, Q[i].l, Q[i].r) << std::endl;
    }
}