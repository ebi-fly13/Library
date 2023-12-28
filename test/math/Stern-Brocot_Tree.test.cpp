#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include "../../math/stern_brocot_tree.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    std::string type;
    std::cin >> type;
    if (type == "ENCODE_PATH") {
        i64 a, b;
        std::cin >> a >> b;
        auto path = stern_brocot_tree::encode_path({a, b});
        stern_brocot_tree::print_path(path);
    } else if (type == "DECODE_PATH") {
        int k;
        std::cin >> k;
        std::vector<std::pair<char, i64>> path(k);
        for (auto &[c, n] : path) {
            std::cin >> c >> n;
        }
        auto lr = stern_brocot_tree::decode_path(path);
        auto f = stern_brocot_tree::val(lr);
        std::cout << f << '\n';
    } else if (type == "LCA") {
        i64 a, b, c, d;
        std::cin >> a >> b >> c >> d;
        std::cout << stern_brocot_tree::lca({a, b}, {c, d}) << '\n';
    } else if (type == "ANCESTOR") {
        i64 k, a, b;
        std::cin >> k >> a >> b;
        auto f = stern_brocot_tree::ancestor(k, {a, b});
        if (f) {
            std::cout << f.value() << '\n';
        } else {
            std::cout << "-1\n";
        }
    } else if (type == "RANGE") {
        i64 a, b;
        std::cin >> a >> b;
        std::cout << stern_brocot_tree::range({a, b}) << '\n';
    }
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