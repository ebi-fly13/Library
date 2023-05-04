#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3333"

#include "../../data_structure/range_query_binary_trie.hpp"

#include <iostream>
#include <vector>


int main() {
    int n,q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    ebi::range_query_binary_trie<int, 10> btrie(a);
    while(q--) {
        int t;
        std::cin >> t;
        if(t == 1) {
            int k,x;
            std::cin >> k >> x;
            k--;
            btrie.set(k, btrie.get(k) ^ x);
        }
        else {
            int l,r,x;
            std::cin >> l >> r >> x;
            l--;
            std::cout << btrie.min_element(l, r, x) << '\n';
        }
    }
}