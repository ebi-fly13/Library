#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2863"

#include <iostream>
#include <string>
#include <vector>

#include "String/aho_corasick.hpp"
#include "utility/modint.hpp"

using mint = ebi::modint1000000007;

int main() {
    int n;
    std::cin >> n;
    ebi::aho_corasick<26, 'a'> aho;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        aho.add(s[i]);
    }
    aho.build();
    std::string t;
    std::cin >> t;
    int m = t.size();
    std::vector<mint> dp(m + 1, 0);
    dp[0] = 1;
    aho.query(t, [&](int i, int idx) -> void {
        dp[idx + 1] += dp[idx + 1 - int(s[i].size())];
    });
    std::cout << dp[m].val() << '\n';
}