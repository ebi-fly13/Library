#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include <iostream>

#include "../../data_structure/deque_aggregation.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

struct F {
    mint a;
    mint b;
};

F op(F f, F g) {
    return {g.a * f.a, g.a * f.b + g.b};
}

int main() {
    int q;
    std::cin >> q;
    ebi::deque_aggregation<F, op> swag;
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            mint a, b;
            std::cin >> a >> b;
            swag.push_front({a, b});
        } else if (t == 1) {
            mint a, b;
            std::cin >> a >> b;
            swag.push_back({a, b});
        } else if (t == 2) {
            swag.pop_front();
        } else if (t == 3) {
            swag.pop_back();
        } else {
            mint x;
            std::cin >> x;
            if (swag.empty()) {
                std::cout << x << '\n';
                continue;
            }
            auto f = swag.fold_all();
            mint ans = f.a * x + f.b;
            std::cout << ans << '\n';
        }
    }
}