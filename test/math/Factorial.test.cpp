#define PROBLEM "https://judge.yosupo.jp/problem/factorial"

#include "../../math/factorial_mod_998.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    std::cout << factorial_mod_998(n) << '\n';
}

}  // namespace ebi

int main() {
    ebi::fast_io();
    int t = 1;
    std::cin >> t;
    while (t--) {
        ebi::main_();
    }
    return 0;
}