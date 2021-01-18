#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../data_structure/SegmentTreeBeats.hpp"
#include "../utility/int_alias.hpp"

#include <iostream>
#include <vector>

using S = i64;

int main() {
    int n,q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    for(int i = 0; i<n; i++) {
        std::cin >> a[i];
    }
    ebi::SegmentTreeBeats<S> seg(a);
    while(q--) {
        int t;
        std::cin >> t;
        if(t==0) {
            int l,r;
            i64 b;
            std::cin >> l >> r >> b;
            seg.apply_chmin(l,r,b);
        }
        else if(t==1) {
            int l,r;
            i64 b;
            std::cin >> l >> r >> b;
            seg.apply_chmax(l,r,b);
        }
        else if(t==2) {
            int l,r;
            i64 b;
            std::cin >> l >> r >> b;
            seg.apply(l,r,b);
        }
        else {
            int l,r;
            std::cin >> l >> r;
            std::cout << seg.prod(l,r) << std::endl;
        }
    }
}