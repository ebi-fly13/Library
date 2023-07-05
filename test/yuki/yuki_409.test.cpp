#define PROBLEM "https://yukicoder.me/problems/no/409"

#include <algorithm>
#include <cstdint>
#include <iostream>

#include "../../algorithm/convex_hull_trick.hpp"

using i64 = std::int64_t;

int main() {
    int n;
    i64 a, b, w;
    std::cin >> n >> a >> b >> w;
    ebi::convex_hull_trick<i64> cht;
    cht.add(-2 * a - b, 2 * w + 2 * a);
    auto f = [&](i64 r) -> i64 { return -a * r + b * r * (r + 1) / 2; };
    i64 ans = w + f(n);
    for (int i = 1; i <= n; i++) {
        i64 d;
        std::cin >> d;
        i64 val = cht.min(i);
        i64 res = b * i * i + 2 * d + val;
        res /= 2;
        cht.add(-2 * a - 2 * b * i - b,
                b * i * i + b * i + 2 * a * (i + 1) + 2 * res);
        ans = std::min(ans, res + f(n - i));
    }
    std::cout << ans << '\n';
}