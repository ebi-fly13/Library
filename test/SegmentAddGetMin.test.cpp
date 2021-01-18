#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../data_structure/LiChaoSegmentTree.hpp"
#include "../utility/int_alias.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n,q; std::cin >> n >> q;
    std::vector<std::pair<i64, i64>> lr(n);
    std::vector<ebi::line<i64>> y(n);
    std::vector<i64> x;
    for(int i = 0; i<n; i++){
        std::cin >> lr[i].first >> lr[i].second;
        std::cin >> y[i].a >> y[i].b;
    }
    std::vector<std::vector<i64>> query(q);
    for(int i = 0; i<q; i++) {
        i64 t; std::cin >> t;
        query[i].emplace_back(t);
        if(t==0) {
            i64 l,r,a,b; std::cin >> l >> r >> a >> b;
            query[i].emplace_back(l);
            query[i].emplace_back(r);
            query[i].emplace_back(a);
            query[i].emplace_back(b);
        }
        else {
            i64 p; std::cin >> p;
            query[i].emplace_back(p);
            x.emplace_back(p);
        }
    }
    if(x.size()==0) return 0;
    std::sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    x.emplace_back(1e9+10);
    ebi::LiChaoSegmentTree<i64> seg(x);
    for(int i = 0; i<n; i++) {
        int l = std::lower_bound(x.begin(), x.end(), lr[i].first) - x.begin();
        int r = std::lower_bound(x.begin(), x.end(), lr[i].second) - x.begin();
        seg.add_segment(y[i], l, r);
    }
    for(int i = 0; i<q; i++) {
        if(query[i][0]==0) {
            int l = std::lower_bound(x.begin(), x.end(), query[i][1]) - x.begin();
            int r = std::lower_bound(x.begin(), x.end(), query[i][2]) - x.begin();
            ebi::line<i64> ya(query[i][3], query[i][4]);
            seg.add_segment(ya, l, r);
        }
        else {
            int index = std::lower_bound(x.begin(), x.end(), query[i][1]) - x.begin();
            i64 ret = seg.get(index);
            if(ret == std::numeric_limits<i64>::max()) {
                std::cout << "INFINITY" << std::endl;
            }
            else{
                std::cout << ret << std::endl;
            }
        }
    }
}