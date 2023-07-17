#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../algorithm/two_sat.hpp"

#include <iostream>

int main() {
    char p;
    std::string cnf;
    std::cin >> p >> cnf;
    int n, m;
    std::cin >> n >> m;
    ebi::two_sat ts(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        ts.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);
    }
    bool flag = ts.satisfiable();
    std::cout << "s " << (flag ? "SATISFIABLE" : "UNSATISFIABLE") << std::endl;
    if (flag) {
        std::cout << "v";
        auto ans = ts.answer();
        for (int i = 0; i < n; i++) {
            std::cout << " " << (ans[i] ? i + 1 : -(i + 1));
        }
        std::cout << " 0\n";
    }
}