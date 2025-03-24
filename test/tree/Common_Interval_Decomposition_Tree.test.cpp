#include "../../tree/common_interval_decomposition_tree.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    std::cin >> p;
    common_interval_decomposition_tree permutation_tree(p);
    auto tree = permutation_tree.get_tree();
    std::cout << tree.size() << '\n';
    for (auto node : tree) {
        std::cout << node.parent << " " << node.l << " " << node.r - 1 << " "
                  << (node.type == common_interval_decomposition_tree::Prime
                          ? "prime"
                          : "linear")
                  << '\n';
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