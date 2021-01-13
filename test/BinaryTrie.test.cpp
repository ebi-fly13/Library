#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../data_structure/BinaryTrie.hpp"

#include <iostream>

int main(){
    int q;
    std::cin >> q;
    BinaryTrie<int> set(31);
    while(q--) {
        int t, x;
        std::cin >> t >> x;
        if(t==0) {
            if(!set.find(x)) {
                set.insert(x);
            }
        }
        else if(t==1) {
            set.erase(x);
        }
        else {
            std::cout << set.min_element(x) << std::endl;
        }
    }
}