#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444&lang=jp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

#include "../../string/rolling_hash.hpp"
#include "../../utility/hash.hpp"

using u64 = std::uint64_t;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::set<ebi::Hash<2>> set;
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
        set.insert(rh.get_hash(l, r));
    }
    std::cout << int(set.size()) << '\n';
}