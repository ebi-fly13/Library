#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "../../tree/cartesian_tree.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::cin >> a;
    auto p = cartesian_tree(a);
    rep(i, 0, n) if (p[i] < 0) p[i] = i;
    std::cout << p << '\n';
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