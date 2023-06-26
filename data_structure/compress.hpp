#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

namespace ebi {

template <class T> struct compress {
  private:
    std::vector<T> cp;

  public:
    compress() = default;

    compress(std::vector<T> cp) : cp(cp) {
        build();
    }

    void build() {
        std::sort(cp.begin(), cp.end());
        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());
    }

    void add(const T &val) {
        cp.emplace_back(val);
    }

    int get(const T &val) const {
        return std::lower_bound(cp.begin(), cp.end(), val) - cp.begin();
    }

    int size() const {
        return cp.size();
    }

    bool find(const T& val) const {
        auto itr = std::lower_bound(cp.begin(), cp.end(), val);
        if(itr == cp.end()) return false;
        else return *itr == val;
    }

    T val(int idx) const {
        assert(0 <= idx && idx < (int)cp.size());
        return cp[idx];
    }
};

}  // namespace ebi