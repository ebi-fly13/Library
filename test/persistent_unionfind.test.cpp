#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../data_structure/persistent_unionfind.hpp"

#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::persistent_unionfind uf(n);
    std::vector<int> query(q + 1, 0);
    int time = 0;
    for (int i = 1; i <= q; i++) {
        int t, k, u, v;
        std::cin >> t >> k >> u >> v;
        k = query[k + 1];
        query[i] = k;
        if (t == 0) {
            uf.merge(u, v, k);
            query[i] = ++time;
        } else {
            if (uf.same(u, v, k)) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
        }
    }
}