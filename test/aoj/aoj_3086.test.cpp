#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3086"

#include "../../algorithm/monge_shortest_path.hpp"
#include "../../data_structure/segtree.hpp"
#include "../../template/template.hpp"

namespace ebi {

i64 op(i64 a, i64 b) {
    return a < b ? a : b;
}

i64 e() {
    return LNF;
}

void main_() {
    int n, l;
    std::cin >> n >> l;
    std::vector<i64> a(n);
    std::cin >> a;
    rep(i, 0, n) a[i] = -a[i];
    segtree<i64, op, e> seg(a);
    auto f = [&](int i, int j) -> i64 {
        if (j - i < l) return std::numeric_limits<i64>::max();
        return seg.prod(i, j);
    };
    auto dp = monge_shortest_path(n + 1, f);
    std::cout << -dp[n] << '\n';
}

}  // namespace ebi

int main() {
    ebi::fast_io();
    int t = 1;
    // std::cin >> t;
    while (t--) {
        ebi::main_();
    }
    return 0;
}