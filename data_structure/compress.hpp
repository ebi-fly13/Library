#pragma once

#include <vector>
#include <algorithm>

namespace ebi {

template<class T>
struct compress {
private:
    std::vector<T> cp;
    bool flag = false;
public:
    compress() = default;

    compress(std::vector<T> cp) : cp(cp) {
        build();
    }

    void build() {
        std::sort(cp.begin(), cp.end());
        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());
        flag = true;
    }

    void add(const T &val) {
        cp.emplace_back(val);
        flag = false;
    }

    int get(const T &val) {
        if(flag == false) build();
        return std::lower_bound(cp.begin(), cp.end(), val) - cp.begin();
    }

    int size() const {
        return cp.size();
    }

    T val(int idx) const {
        assert(0 <= idx && idx < (int)cp.size());
        return cp[idx];
    }
};

}