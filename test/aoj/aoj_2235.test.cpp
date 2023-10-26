#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235"

#include "data_structure/offline_dynamic_connectivity.hpp"
#include "template/template.hpp"

namespace ebi {

void main_() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 3>> qs;
    std::vector<std::array<int, 3>> q3;
    rep(i, 0, m) {
        int t, u, v;
        std::cin >> t >> u >> v;
        t--;
        if (t < 2) {
            qs.push_back({t, u, v});
        } else {
            q3.push_back({int(qs.size()), u, v});
        }
    }
    offline_dynamic_connective uf(n, qs);
    for (auto [t, u, v] : q3) {
        uf.set(t);
        std::cout << (uf.same(u, v) ? "YES" : "NO") << '\n';
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