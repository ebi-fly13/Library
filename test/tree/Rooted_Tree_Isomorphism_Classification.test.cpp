#define PROBLEM \
    "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include <iostream>
#include <map>
#include <vector>

#include "../../tree/rooted_tree_hash.hpp"
#include "../../utility/hash.hpp"
#include "../../graph/base.hpp"

int main() {
    int n;
    std::cin >> n;
    ebi::Graph<int> g(n);
    g.read_parents(0);
    auto hash = ebi::rooted_tree_hash<2>::subtree_hash(g, 0);
    int k = 0;
    std::map<ebi::Hash<2>, int> map;
    for (auto h : hash) {
        if (map.find(h) == map.end()) map[h] = k++;
    }
    std::cout << k << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << map[hash[i]] << " \n"[i == n - 1];
    }
}