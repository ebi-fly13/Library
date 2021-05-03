#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../data_structure/heavy_light_decomposition.hpp"

#include <iostream>
#include <vector>

using i64 = std::int64_t;
i64 op(i64 a, i64 b) { return a+b; }
i64 e() { return 0; }

int main() {
    int n,q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    ebi::heavy_light_decomposition<i64, op, e> hld(n);
    for(int i = 0; i < n-1; ++i) {
        int u,v;
        std::cin >> u >> v;
        hld.add_edge(u,v);
    }
    hld.build();
    hld.set(a);
    while(q--) {
        int flag;
        std::cin >> flag;
        if(flag == 0) {
            int p;
            i64 x;
            std::cin >> p >> x;
            hld.set(p, hld.get(p) + x);
        }
        else {
            int u,v;
            std::cin >> u >> v;
            std::cout << hld.path_prod(u, v) << std::endl;
        }   
    }
}