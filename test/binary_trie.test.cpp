#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../data_structure/binary_trie.hpp"

#include <iostream>

int main() {
    int q;
    std::cin >> q;
    ebi::binary_trie<int> trie;
    while (q--) {
        int t, x;
        std::cin >> t >> x;
        if (t == 0) {
            if (!trie.find(x)) trie.insert(x);
        } else if (t == 1) {
            if (trie.find(x)) trie.erase(x);
        } else {
            std::cout << trie.min_element(x) << '\n';
        }
    }
}