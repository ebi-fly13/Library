#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444&lang=jp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

#include "../../String/rolling_hash.hpp"
#include "../../utility/modint61.hpp"

using u64 = std::uint64_t;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::map<std::array<ebi::modint61, 2>, int> map;
    ebi::rolling_hash<2>::set_base();
    ebi::rolling_hash<2> rh(s);
    int l = 0;
    int r = 1;
    while (m--) {
        std::string q;
        std::cin >> q;
        if (q == "L++") {
            l++;
        } else if (q == "L--") {
            l--;
        } else if (q == "R++") {
            r++;
        } else if (q == "R--") {
            r--;
        } else {
            assert(0);
        }
        map[rh.get_hash(l, r)] = 1;
    }
    std::cout << int(map.size()) << '\n';
}