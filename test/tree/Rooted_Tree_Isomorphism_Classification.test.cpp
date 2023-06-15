#define PROBLEM \
    "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include <iostream>
#include <map>
#include <vector>

#include "../../tree/rooted_tree_hash.hpp"
#include "../../utility/hash.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        g[p].emplace_back(i);
    }
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