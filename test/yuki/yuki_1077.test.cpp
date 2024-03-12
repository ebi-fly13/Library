#define PROBLEM "https://yukicoder.me/problems/no/1077"

#include "../../data_structure/slope_trick.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    slope_trick<i64> st;
    rep(i, 0, n) {
        i64 y;
        std::cin >> y;
        st.left_cumulative_min();
        st.add_abs(y);
    }
    std::cout << st.min() << '\n';
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