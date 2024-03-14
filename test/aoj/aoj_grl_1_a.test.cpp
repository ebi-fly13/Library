#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../data_structure/skew_heap.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m, r;
    std::cin >> n >> m >> r;
    Graph<i64> g(n);
    g.read_graph(m, 0, true, true);
    skew_heap<i64, int, std::greater<i64>> heap;
    std::vector<i64> dp(n, LNF);
    dp[r] = 0;
    heap.push(0, r);
    while (!heap.empty()) {
        auto [ret, v] = heap.top();
        heap.pop();
        if (dp[v] < ret) continue;
        for (auto e : g[v]) {
            if (chmin(dp[e.to], dp[v] + e.cost)) {
                heap.push(dp[e.to], e.to);
            }
        }
    }
    for (auto ans : dp) {
        if (ans == LNF) {
            std::cout << "INF\n";
        } else {
            std::cout << ans << '\n';
        }
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