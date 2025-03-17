#define PROBLEM \
    "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include <iostream>
#include <map>
#include <vector>

#include "../../graph/base.hpp"
#include "../../tree/subtree_hash.hpp"
#include "../../utility/hash.hpp"

int main() {
    int n;
    std::cin >> n;
    ebi::Graph<int> g(n);
    g.read_parents(0);
    ebi::subtree_hash hash(g);
    int k = 0;
    std::map<ebi::modint61, int> map;
    for(int i = 0; i < n; i++) {
        if(!map.contains(hash.get(i, 0))) {
            map[hash.get(i, 0)] = k++;
        }
    }
    std::cout << k << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << map[hash.get(i, 0)] << " \n"[i == n - 1];
    }
}