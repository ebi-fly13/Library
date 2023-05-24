#include <vector>

#include "../fps/fps.hpp"

namespace ebi {

template <class mint, std::vector<mint> (*convolution)(
                          const std::vector<mint> &, const std::vector<mint> &)>
FPS<mint, convolution> taylor_shift(FPS<mint, convolution> f, mint a) {
    int d = f.deg();
    std::vector<mint> fact(d + 1, 1), inv_fact(d + 1, 1);
    for (int i = 1; i <= d; i++) fact[i] = fact[i - 1] * i;
    inv_fact[d] = fact[d].inv();
    for (int i = d; i > 0; i--) inv_fact[i - 1] = inv_fact[i] * i;
    for (int i = 0; i < d; i++) f[i] *= fact[i];
    std::reverse(f.begin(), f.end());
    FPS<mint, convolution> g(d, 1);
    mint pow_a = a;
    for (int i = 1; i < d; i++) {
        g[i] = pow_a * inv_fact[i];
        pow_a *= a;
    }
    f = (f * g).pre(d);
    std::reverse(f.begin(), f.end());
    for (int i = 0; i < d; i++) f[i] *= inv_fact[i];
    return f;
}

}  // namespace ebi