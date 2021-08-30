#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444&lang=jp"

#include <iostream>
#include <vector>
#include <map>
#include <cstdint>
#include <cassert>

#include "String/rolling_hash.hpp"

using u64 = std::uint64_t;

int main() {
    int n,m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::map<std::vector<u64>, int> map;
    ebi::rolling_hash<2> rh(s);
    int l = 0;
    int r = 1;
    while(m--) {
        std::string q;
        std::cin >> q;
        if(q == "L++") {
            l++;
        }
        else if(q == "L--") {
            l--;
        }
        else if(q == "R++") {
            r++;
        }
        else if(q == "R--") {
            r--;
        }
        else {
            assert(0);
        }
        auto p = rh.get_hash(l, r);
        map[p] = 1;
    }
    std::cout << int(map.size()) << '\n';
}