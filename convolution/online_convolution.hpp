#pragma once

#include <atcoder/convolution>
#include <atcoder/modint>
#include <bit>
#include <vector>

#include "../template/int_alias.hpp"

namespace ebi {

struct online_convolution {
  private:
    using mint = atcoder::modint998244353;

  public:
    online_convolution() = default;

    mint add(int idx, mint ai, mint bi) {
        assert(p == idx);
        a.emplace_back(ai);
        b.emplace_back(bi);
        int z = std::countr_zero(u32(p + 2)), w = 1 << z;
        if (p + 2 == w) {
            auto a0 = a;
            a0.resize(2 * w);
            atcoder::internal::butterfly(a0);
            fa.emplace_back(a0.begin(), a0.begin() + w);
            auto b0 = b;
            b0.resize(2 * w);
            atcoder::internal::butterfly(b0);
            fb.emplace_back(b0.begin(), b0.begin() + w);
            for (int i = 0; i < 2 * w; i++) a0[i] *= b0[i];
            atcoder::internal::butterfly_inv(a0);
            mint inv_len = mint(2 * w).inv();
            c.resize(2 * p + 2);
            for (int i = 0; i < p + 1; i++) c[p + i] += a0[p + i] * inv_len;
        } else {
            std::vector<mint> a0 = {a.end() - w, a.end()};
            a0.resize(2 * w);
            atcoder::internal::butterfly(a0);
            std::vector<mint> b0 = {b.end() - w, b.end()};
            b0.resize(2 * w);
            atcoder::internal::butterfly(b0);
            for (int i = 0; i < 2 * w; i++) {
                a0[i] = a0[i] * fb[z][i] + fa[z][i] * b0[i];
            }
            atcoder::internal::butterfly_inv(a0);
            mint inv_len = mint(2 * w).inv();
            for (int i = 0; i < w; i++) c[p + i] += a0[w - 1 + i] * inv_len;
        }
        return c[p++];
    }

    mint operator[](int i) const {
      assert(0 <= i && i < p);
      return c[i];
    }

  private:
    int p = 0;
    std::vector<mint> a, b, c;
    std::vector<std::vector<mint>> fa, fb;
};

}  // namespace ebi