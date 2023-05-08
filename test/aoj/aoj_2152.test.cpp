#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2152&lang=jp"

#include <iostream>
#include <map>
#include <vector>

#include "data_structure/section_set.hpp"

using i64 = std::int64_t;

int main() {
    int n;
    while (std::cin >> n, !(n == 0)) {
        ebi::section_set<i64> used, noused;
        noused.insert(0, 1e9 + 7);
        std::map<i64, std::vector<std::pair<i64, i64>>> map;
        std::map<i64, i64> vmap;
        vmap[std::numeric_limits<i64>::max()] = -1;
        while (n--) {
            char c;
            i64 idx;
            std::cin >> c >> idx;
            if (c == 'W') {
                i64 s;
                std::cin >> s;
                while (s > 0) {
                    auto [l, r] = noused.lower_bound(0);
                    i64 w = std::min(r - l, s);
                    used.insert(l, l + w);
                    map[idx].emplace_back(l, l + w);
                    vmap[l] = idx;
                    noused.erase(l, r);
                    if (w != r - l) {
                        noused.insert(l + w, r);
                    }
                    s -= w;
                }
            } else if (c == 'D') {
                for (auto [l, r] : map[idx]) {
                    assert(used.find(l, r));
                    used.erase(l, r);
                    vmap.erase(l);
                    noused.insert(l, r);
                }
                map.erase(idx);
            } else {
                if (!used.find(idx)) {
                    std::cout << "-1\n";
                    continue;
                }
                auto itr = std::prev(vmap.upper_bound(idx));
                std::cout << itr->second << '\n';
            }
        }
        std::cout << '\n';
    }
}