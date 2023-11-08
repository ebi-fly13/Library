#define PROBLEM "https://yukicoder.me/problems/no/952"

#include "../../algorithm/enumerate_monge_d_edge_shortest_path.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::cin >> a;
    a.insert(a.begin(), 0);
    n++;
    std::vector<i64> sum(n + 1, 0);
    rep(i, 0, n) sum[i + 1] = sum[i] + a[i];
    auto f = [&](int i, int j) -> i64 {
        return (sum[j] - sum[i + 1]) * (sum[j] - sum[i + 1]);
    };
    auto ans = enumerate_monge_d_edge_shortest_path(n + 1, f);
    rep(i, 1, n) {
        std::cout << ans[n - i] << '\n';
    }
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