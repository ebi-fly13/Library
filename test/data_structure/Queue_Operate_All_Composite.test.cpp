#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>

#include "../../data_structure/queue_aggregation.hpp"
#include "../../utility/modint.hpp"

using mint = ebi::modint998244353;

struct F {
    mint a, b;
    F(mint a, mint b) : a(a), b(b) {}
};

F op(F f1, F f2) {
    return F(f2.a * f1.a, f2.a * f1.b + f2.b);
}

int main() {
    ebi::queue_aggregation<F, op> swag;
    int q;
    std::cin >> q;
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int a, b;
            std::cin >> a >> b;
            swag.push(F(a, b));
        } else if (t == 1) {
            swag.pop();
        } else {
            int x;
            std::cin >> x;
            if (swag.empty()) {
                std::cout << x << std::endl;
                continue;
            }
            auto f = swag.fold_all();
            std::cout << (f.a * (mint)x + f.b).val() << std::endl;
        }
    }
}