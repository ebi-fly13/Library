#pragma once

#include <algorithm>
#include <tuple>
#include <vector>

/*
    reference: https://www.slideshare.net/okuraofvegetable/ss-65377588
*/

namespace ebi {

template <class T, class S> struct range_tree {
  private:
    void build(std::vector<std::tuple<T, T, S>> points) {
        std::sort(points.begin(), points.end());
        for (const auto &[x, y, val] : points) {
            xs.emplace_back(x);
        }
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        n = 1;
        int sz = xs.size();
        while (n < sz) n <<= 1;
        seg.resize(2 * n);
        sum.resize(2 * n);
        int idx = 0;
        for (const auto &[x, y, val] : points) {
            if (xs[idx] < x) idx++;
            seg[idx + n].emplace_back(y);
            sum[idx + n].emplace_back(val);
        }
        for (int i = n - 1; i > 0; i--) {
            int lch = 0, rch = 0;
            int lsz = seg[2 * i].size(), rsz = seg[2 * i + 1].size();
            auto push_leftval = [&]() -> void {
                seg[i].emplace_back(seg[2 * i][lch]);
                sum[i].emplace_back(sum[2 * i][lch]);
                lch++;
            };
            auto push_rightval = [&]() -> void {
                seg[i].emplace_back(seg[2 * i + 1][rch]);
                sum[i].emplace_back(sum[2 * i + 1][rch]);
                rch++;
            };
            while (lch < lsz || rch < rsz) {
                if (lch == lsz)
                    push_rightval();
                else if (rch == rsz)
                    push_leftval();
                else if (seg[2 * i][lch] <= seg[2 * i + 1][rch])
                    push_leftval();
                else
                    push_rightval();
            }
        }
        for (int i = 1; i < 2 * n; i++) {
            std::vector<S> s;
            s.reserve(sum[i].size() + 1);
            s.emplace_back(0);
            for (auto val : sum[i]) s.emplace_back(s.back() + val);
            std::swap(sum[i], s);
        }
    }

    S prod_y(int idx, S yl, S yr) const {
        int l = std::lower_bound(seg[idx].begin(), seg[idx].end(), yl) -
                seg[idx].begin();
        int r = std::lower_bound(seg[idx].begin(), seg[idx].end(), yr) -
                seg[idx].begin();
        return sum[idx][r] - sum[idx][l];
    }

  public:
    range_tree(const std::vector<std::pair<T, T>> &_points) {
        std::vector<std::tuple<T, T, S>> points;
        points.reserve(_points.size());
        for (auto &[x, y] : _points) points.emplace_back(x, y, 1);
        build(points);
    }

    range_tree(const std::vector<std::tuple<T, T, S>> &points) {
        build(points);
    }

    S prod(T xl, T xr, T yl, T yr) const {
        int l = std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin() + n;
        int r = std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin() + n;
        S res = 0;
        while (l < r) {
            if (l & 1) res += prod_y(l++, yl, yr);
            if (r & 1) res += prod_y(--r, yl, yr);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

  private:
    int n;
    std::vector<T> xs;
    std::vector<std::vector<T>> seg;
    std::vector<std::vector<S>> sum;
};

}  // namespace ebi