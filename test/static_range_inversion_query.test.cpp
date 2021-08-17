#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>

#include "../algorithm/mo_algorithm.hpp"
#include "../data_structure/FenwickTree.hpp"
#include "../data_structure/compress.hpp"

using u64 = std::uint64_t;

int main() {
    int n,q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    std::vector<int> l(q), r(q);
    ebi::compress<int> cp;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        cp.add(a[i]);
    }
    cp.build();
    for(int i = 0; i < n; i++) {
        a[i] = cp.get(a[i]);
    }
    for(int i = 0; i < q; i++) {
        std::cin >> l[i] >> r[i];
    }
    ebi::FenwickTree<u64> fw(cp.size());
    std::vector<u64> ans(q);
    u64 ret = 0;
    const auto insert_left = [&](int l) -> void {
        ret += fw.prefix_sum(a[l]);
        fw.add(a[l], 1);
    };
    const auto insert_right = [&](int r) -> void {
        ret += fw.sum(a[r]+1, cp.size());
        fw.add(a[r], 1);
    };
    const auto delete_left = [&](int l) -> void {
        ret -= fw.prefix_sum(a[l]);
        fw.add(a[l], -1);
    };
    const auto delete_right = [&](int r) -> void {
        ret -= fw.sum(a[r]+1, cp.size());
        fw.add(a[r], -1);
    };
    const auto out = [&](int i) -> void {
        ans[i] = ret;
    };
    ebi::mo_algorithm(n, l, r, insert_left, insert_right, delete_left, delete_right, out);
    for(auto val: ans) {
        std::cout << val << '\n';
    }
}