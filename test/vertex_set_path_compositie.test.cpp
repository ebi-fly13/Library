#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../data_structure/heavy_light_decomposition.hpp"
#include "../utility/modint.hpp"

#include <iostream>
#include <vector>

using mint = ebi::modint998244353;

using i64 = std::int64_t;

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

int main() {
    int n,q;
    std::cin >> n >> q;
    std::vector<F> f(n, F(1,0));
    for(int i = 0; i < n; ++i) {
        int a,b;
        std::cin >> a >> b;
        f[i] = F(a,b);
    }
    ebi::heavy_light_decomposition<F, op, e> hld(n);
    for(int i = 0; i < n-1; ++i) {
        int u,v;
        std::cin >> u >> v;
        hld.add_edge(u,v);
    }
    hld.build();
    hld.set(f);
    while(q--) {
        int flag;
        std::cin >> flag;
        if(flag == 0) {
            int p;
            int c, d;
            std::cin >> p >> c >> d;
            hld.set(p, F(c,d));
        }
        else {
            int u,v;
            i64 x;
            std::cin >> u >> v >> x;
            F f_px = hld.path_prod(u, v);
            std::cout << (f_px.a * x + f_px.b).val() << std::endl;
        }
    }
}