#pragma once

#include <algorithm>
#include <cstdint>
#include <memory>
#include <vector>

namespace ebi {

template <class T, int D> struct kd_tree {
  private:
    using node_ptr = std::shared_ptr<kd_tree<T, D>>;

    T dist(std::array<T, D> point) {
        T res = 0;
        for (auto val : point) {
            res += val * val;
        }
        return res;
    }

  public:
    kd_tree(const std::vector<int> &_index,
            const std::vector<std::array<T, D>> &points)
        : index(_index) {
        const int n = index.size();
        std::fill(min.begin(), min.end(), std::numeric_limits<T>::max());
        std::fill(max.begin(), max.end(), std::numeric_limits<T>::min());
        for (auto i : index) {
            for (int j = 0; j < D; j++) {
                min[j] = std::min(min[j], points[i][j]);
                max[j] = std::max(max[j], points[i][j]);
            }
        }
        if (n == 1) return;
        int index_div = 0;
        for (int i = 0; i < D; i++) {
            if (max[i] - min[i] > max[index_div] - min[index_div]) {
                index_div = i;
            }
        }
        auto begin = index.begin();
        auto center = begin + n / 2;
        auto end = index.end();
        std::nth_element(begin, center, end,
                         [&index_div, &points](int i, int j) {
                             return points[i][index_div] < points[j][index_div];
                         });
        lch = std::make_shared<kd_tree<T, D>>(std::vector<int>(begin, center),
                                              points);
        rch = std::make_shared<kd_tree<T, D>>(std::vector<int>(center, end),
                                              points);
    }

    template <class F>
    void circle_search(const std::array<T, D> &center, T k, F f) {
        std::array<T, D> p;
        for (int i = 0; i < D; i++) {
            p[i] = std::max(std::abs(center[i] - min[i]),
                            std::abs(center[i] - max[i]));
        }
        if (dist(p) <= k * k) {
            for (auto i : index) {
                f(i);
            }
            return;
        }
        for (int i = 0; i < D; i++) {
            p[i] = center[i] - std::clamp(center[i], min[i], max[i]);
        }
        if (dist(p) > k * k) return;
        assert(lch && rch);
        lch->circle_search(center, k, f);
        rch->circle_search(center, k, f);
    }

  private:
    std::vector<int> index;
    std::array<T, D> min, max;
    node_ptr lch = nullptr;
    node_ptr rch = nullptr;
};

}  // namespace ebi