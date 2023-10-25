#pragma once

#include <cstdint>
#include <optional>

#include "../modint/dynamic_modint.hpp"

namespace ebi {

std::optional<std::int64_t> mod_sqrt(const std::int64_t &a,
                                     const std::int64_t &p) {
    if (a == 0 || a == 1) return a;
    using mint = dynamic_modint<100>;
    mint::set_mod(p);
    if (mint(a).pow((p - 1) >> 1) != 1) return std::nullopt;
    mint b = 1;
    while (b.pow((p - 1) >> 1) == 1) b += 1;
    std::int64_t m = p - 1, e = 0;
    while (m % 2 == 0) m >>= 1, e++;
    mint x = mint(a).pow((m - 1) >> 1);
    mint y = mint(a) * x * x;
    x *= a;
    mint z = b.pow(m);
    while (y != 1) {
        std::int64_t j = 0;
        mint t = y;
        while (t != 1) {
            j++;
            t *= t;
        }
        z = z.pow(1ll << (e - j - 1));
        x *= z;
        z *= z;
        y *= z;
        e = j;
    }
    return x.val();
}

}  // namespace ebi