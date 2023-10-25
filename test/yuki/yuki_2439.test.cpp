#define PROBLEM "https://yukicoder.me/problems/no/2439"

#include "../../data_structure/lazy_segtree.hpp"
#include "../../graph/template.hpp"
#include "../../template/template.hpp"
#include "../../tree/heavy_light_decomposition.hpp"

namespace ebi {

i64 op(i64 a, i64 b) {
    return a < b ? a : b;
}

i64 e() {
    return LNF;
}

i64 mapping(i64 f, i64 x) {
    return f + x;
}

i64 composition(i64 f, i64 g) {
    return f + g;
}

i64 id() {
    return 0;
}

void main_() {
    int n, q;
    std::cin >> n >> q;
    Graph<i64> G(n);
    graph g(n);
    rep(i, 0, n - 1) {
        int a, b;
        i64 c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        g.add_edge(a, b);
        G.add_edge(a, b, c);
    }
    std::vector<int> par(n, -1);
    std::vector<i64> c(n, 0);
    auto dfs = [&](auto &&self, int v) -> void {
        for (auto e : G[v]) {
            if (e.to == par[v]) continue;
            par[e.to] = v;
            c[e.to] = e.cost;
            self(self, e.to);
        }
    };
    dfs(dfs, 0);
    heavy_light_decomposition hld(g);
    {
        std::vector<i64> cs(n, e());
        rep(i, 1, n) {
            cs[hld.idx(i)] = c[i];
        }
        c = cs;
    }
    lazy_segtree<i64, op, e, i64, mapping, composition, id> seg(c);
    auto add_path = [&](int u, int v, i64 val) -> void {
        auto f = [&](int l, int r) -> void {
            if (l < r)
                seg.apply(l, r, val);
            else
                seg.apply(r, l, val);
        };
        hld.path_noncommutative_query(u, v, false, f);
    };
    auto path_min = [&](int u, int v) -> i64 {
        i64 ret = e();
        auto f = [&](int l, int r) -> void {
            if (l < r)
                ret = op(ret, seg.prod(l, r));
            else
                ret = op(ret, seg.prod(r, l));
        };
        hld.path_noncommutative_query(u, v, false, f);
        return ret;
    };
    std::vector<int> broken(n, 1);
    std::vector<i64> apples(n, 0);
    int ans = n;
    auto dfs_break = [&](auto &&self, int v) -> i64 {
        broken[v] = 0;
        ans--;
        i64 sum = apples[v];
        for (auto nv : g[v]) {
            if (nv == par[v]) continue;
            if (broken[nv] == 0) continue;
            sum += self(self, nv);
        }
        return sum;
    };
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int v;
            i64 x;
            std::cin >> v >> x;
            v--;
            add_path(v, 0, -x);
            apples[v] += x;
            if (path_min(v, 0) > 0) continue;
            i64 ret = e();
            auto f = [&](i64 x) { return op(ret, x) > 0; };
            auto binary_search = [&](int a, int b) -> int {
                if (a > b) {
                    i64 x = seg.prod(b, a);
                    if (f(x)) {
                        ret = op(ret, x);
                        return b;
                    }
                    return seg.min_left(a, f);
                } else {
                    i64 x = seg.prod(a, b);
                    if (f(x)) {
                        ret = op(ret, x);
                        return b;
                    }
                    return seg.max_right(a, f);
                }
            };
            int nv = hld.max_path(v, 0, false, binary_search);
            if (nv == -1)
                nv = v;
            else
                nv = hld.jump(nv, 0, 1);
            assert(nv != -1 && broken[nv] > 0);
            i64 rem = dfs_break(dfs_break, nv);
            add_path(hld.jump(nv, 0, 1), 0, rem);
        } else {
            std::cout << ans << '\n';
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