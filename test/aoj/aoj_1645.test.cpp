#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1645"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)
#define all(v) (v).begin(), (v).end()

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
    for (std::size_t i = 0; i < vec.size(); i++)
        os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    return os;
}

#include "../../data_structure/segtree.hpp"
#include "../../data_structure/undo_unionfind.hpp"

namespace ebi {

using ld = long double;

constexpr int sz = 100010;

int op(int a, int b) {
    return a > b ? a : b;
}

int e() {
    return -1;
}

void main_() {
    int n, m;
    while (std::cin >> n >> m, !(n == 0 && m == 0)) {
        std::vector<std::pair<int, int>> ab(m);
        std::vector<int> s(m);
        rep(i, 0, m) {
            auto& [a, b] = ab[i];
            std::cin >> a >> b >> s[i];
            a--;
            b--;
        }
        std::vector<int> idx(m);
        std::iota(all(idx), 0);
        std::sort(all(idx), [&](int i, int j) -> bool { return s[i] > s[j]; });
        undo_unionfind uf(n);
        std::vector table(sz, std::vector<int>());
        for (auto i : idx) {
            auto [a, b] = ab[i];
            uf.merge(a, b);
            table[s[i]].emplace_back(i);
        }
        segtree<int, op, e> seg(n);
        rep(i, 0, n) {
            if (uf.par[i] < 0) {
                seg.set(i, -uf.par[i]);
            }
        }
        std::vector<int> ret(n, 1);
        rep(i, 0, sz) {
            std::vector<int> vs;
            std::reverse(all(table[i]));
            for (auto id : table[i]) {
                auto [a, b] = ab[id];
                if (ret[uf.leader(a)] < 0) {
                    uf.undo();
                    a = uf.leader(a);
                    b = uf.leader(b);
                    ret[a] = -1;
                    ret[b] = -1;
                    continue;
                }
                seg.set(uf.leader(a), -1);
                uf.undo();
                a = uf.leader(a);
                b = uf.leader(b);
                seg.set(a, uf.size(a));
                seg.set(b, uf.size(b));
                vs.emplace_back(a);
                vs.emplace_back(b);
            }
            int max = seg.all_prod();
            for (auto v : vs) {
                v = uf.leader(v);
                if (uf.size(v) < max) {
                    seg.set(v, -1);
                    ret[v] = -1;
                }
            }
        }
        std::vector<int> ans;
        rep(i, 0, n) if (ret[i] > 0) {
            ans.emplace_back(i + 1);
        }
        std::cout << ans << '\n';
    }
}

}  // namespace ebi

int main() {
    ebi::main_();
}
