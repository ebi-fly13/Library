#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../tree/tree_diameter.hpp"

#include <iostream>

#include "../../graph/template.hpp"
#include "../../template/int_alias.hpp"

using ebi::i64;

int main() {
    int n;
    std::cin >> n;
    ebi::Graph<i64> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        i64 c;
        std::cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    auto [x, path] = ebi::tree_diameter(g);
    std::cout << x << " " << path.size() << '\n';
    for (auto v : path) {
        std::cout << v << " ";
    }
    std::cout << '\n';
}