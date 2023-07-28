#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../../math/longest_increasing_subsequence.hpp"

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(auto &x: a) std::cin >> x;
    auto ans = ebi::LIS(a, true);
    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        std::cout << ans[i] << " \n"[i == k-1];
    }
}