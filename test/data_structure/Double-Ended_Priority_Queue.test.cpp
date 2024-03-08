#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../data_structure/double_ended_priority_queue.hpp"
#include "../../template/template.hpp"

namespace ebi {

void main_() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> s(n);
    std::cin >> s;
    double_ended_priority_queue<int> que(s.begin(), s.end());
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int x;
            std::cin >> x;
            que.push(x);
        } else if (t == 1) {
            std::cout << que.get_min() << '\n';
            que.pop_min();
        } else {
            std::cout << que.get_max() << '\n';
            que.pop_max();
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