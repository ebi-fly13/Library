#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../data_structure/LiChaoSegmentTree.hpp"
#include "../utility/int_alias.hpp"

#include <iostream>

int main(){
    int n,q; std::cin >> n >> q;
    std::vector<line<i64>> p(n);
    for(int i = 0; i<n; i++) {
        std::cin >> p[i].a >> p[i].b;
    }
    std::vector<i64> x;
    std::vector<std::vector<i64>> query(q);
    for(int i = 0; i<q; i++) {
        int t; std::cin >> t;
        query[i].emplace_back(t);
        if(t==0) {
            i64 a,b; std::cin >> a >> b;
            query[i].emplace_back(a);
            query[i].emplace_back(b);
        }
        else {
            i64 p; std::cin >> p;
            query[i].emplace_back(p);
            x.emplace_back(p);
        }
    }
    std::sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    LiChaoSegmentTree<i64> seg(x);
    for(auto y: p) {
        seg.add_line(y);
    }
    for(int i = 0; i<q; i++) {
        if(query[i][0]==0){
            line<i64> y(query[i][1], query[i][2]);
            seg.add_line(y);
        }
        else{
            int index = std::lower_bound(x.begin(), x.end(), query[i][1])-x.begin();
            std::cout << seg.get(index) << std::endl;
        }
    }
}