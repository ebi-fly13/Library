#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include "../data_structure/bankers_queue.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

int main() {
    std::cout << std::fixed << std::setprecision(15);
    int q;
    std::cin >> q;
    std::vector<ebi::bankers_queue<int>> que(1);
    while(q--) {
        int flag;
        std::cin >> flag;
        if(flag == 0) {
            int t,x;
            std::cin >> t >> x;
            t++;
            que.emplace_back(que[t].push(x));
        }
        else {
            int t;
            std::cin >> t;
            t++;
            std::cout << que[t].top() << '\n';
            que.emplace_back(que[t].pop());
        }
    }
}