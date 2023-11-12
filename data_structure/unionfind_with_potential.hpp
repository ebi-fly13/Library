#pragma once

#include <cassert>
#include <vector>

namespace ebi {

template <class T> struct unionfind_with_potential {
  private:
  public:
    unionfind_with_potential(int n) : data_(n, -1), potential_(n, T()) {}

    bool same(int x, int y) {
        return leader(x) == leader(y);
    }

    // potential(x) = potential(y) + p
    bool merge(int x, int y, T p) {
        p = potential(x) - p - potential(y);
        x = leader(x);
        y = leader(y);
        if (x == y) return p == T();
        if (data_[x] > data_[y]) {
            std::swap(x, y);
            p = -p;
        }
        data_[x] += data_[y];
        data_[y] = x;
        potential_[y] = p;
        return true;
    }

    int leader(int x) {
        if (data_[x] < 0) return x;
        int l = leader(data_[x]);
        potential_[x] = potential_[data_[x]] + potential_[x];
        return data_[x] = l;
    }

    int size(int x) {
        return -data_[leader(x)];
    }

    T potential(int x) {
        leader(x);
        return potential_[x];
    }

    T diff(int x, int y) {
        return potential(x) - potential(y);
    }

  private:
    std::vector<int> data_;
    std::vector<T> potential_;
};

}  // namespace ebi