#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../convolution/online_convolution.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + m - 1, 0), b(n + m - 1, 0);
    rep(i, 0, n) std::cin >> a[i];
    rep(i, 0, m) std::cin >> b[i];
    online_convolution oc;
    rep(i, 0, n + m - 1) {
        oc.add(i, a[i], b[i]);
        std::cout << oc[i].val() << " \n"[i == n - m - 2];
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