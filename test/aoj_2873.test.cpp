#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2873"

#include <iostream>
#include <string>
#include <vector>

#include "String/aho_corasick.hpp"

int main() {
    std::string s;
    int n;
    std::cin >> s >> n;
    ebi::aho_corasick<26, 'a'> ac;
    for(int i = 0; i < n; i++) {
        std::string p;
        std::cin >> p;
        ac.add(p);
    }
    ac.build();
    int now = 0;
    int ans = 0;
    for(auto c: s) {
        auto [x, y] = ac.move(c, now);
        if(x > 0) {
            ans++;
            now = 0;
        }
        else {
            now = y;
        }
    }
    std::cout << ans << '\n';
}