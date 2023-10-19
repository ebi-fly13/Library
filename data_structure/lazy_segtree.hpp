#pragma once

/*
    reference:
   https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html
*/

#include <cassert>
#include <ranges>
#include <vector>

namespace ebi {

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
  private:
    void update(int i) {
        data[i] = op(data[2 * i], data[2 * i + 1]);
    }

    void all_apply(int k, F f) {
        data[k] = mapping(f, data[k]);
        if (k < sz) lazy[k] = composition(f, lazy[k]);
    }

    void push(int i) {
        all_apply(2 * i, lazy[i]);
        all_apply(2 * i + 1, lazy[i]);
        lazy[i] = id();
    }

  public:
    lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n, e())) {}
    lazy_segtree(const std::vector<S> &a)
        : n(a.size()),
          sz(std::bit_ceil(a.size())),
          log(std::countr_zero(u32(sz))) {
        data = std::vector<S>(2 * sz, e());
        lazy = std::vector<F>(sz, id());
        for (int i : std::views::iota(0, n)) {
            data[sz + i] = a[i];
        }
        for (int i : std::views::iota(1, sz) | std::views::reverse) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < n);
        p += sz;
        for (int i = log; i >= 1; i--) push(p >> i);
        data[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < n);
        p += sz;
        for (int i = log; i >= 1; i--) push(p >> i);
        return data[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return e();

        l += sz;
        r += sz;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, data[l++]);
            if (r & 1) smr = op(data[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() const {
        return data[1];
    }

    void apply(int p, F f) {
        assert(0 <= p && p < n);
        p += sz;
        for (int i = log; i >= 1; i--) push(p >> i);
        data[p] = mapping(f, data[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        l += sz;
        r += sz;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int memo_l = l, memo_r = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = memo_l;
            r = memo_r;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

  private:
    int n, sz, log;
    std::vector<S> data;
    std::vector<F> lazy;
};

}  // namespace ebi
