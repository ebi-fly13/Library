#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../data_structure/FenwickTree.hpp"
#include "../utility/int_alias.hpp"

#include <iostream>

int main(){
    int n,q;
    std::cin >> n >> q;
    ebi::FenwickTree<i64> fw(n);
    for(int i = 0; i<n; i++) {
        i64 a;
        std::cin >> a;
        fw.add(i, a);
    }
    for(int i = 0; i<q; i++) {
        int flag;
        std::cin >> flag;
        if(flag == 0) {
            int p;
            i64 x;
            std::cin >> p >> x;
            fw.add(p, x);
        }
        else {
            int l,r;
            std::cin >> l >> r;
            std::cout << fw.sum(l,r) << std::endl;
        }
    }
}