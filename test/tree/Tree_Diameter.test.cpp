#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../tree/tree_diameter.hpp"

#include <iostream>

#include "../../graph/base.hpp"
#include "../../template/int_alias.hpp"

using ebi::i64;

int main() {
    int n;
    std::cin >> n;
    ebi::Graph<i64> g(n);
    g.read_tree(0, true);
    auto [x, path] = ebi::tree_diameter(g);
    std::cout << x << " " << path.size() << '\n';
    for (auto v : path) {
        std::cout << v << " ";
    }
    std::cout << '\n';
}