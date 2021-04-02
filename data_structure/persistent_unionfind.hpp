#pragma once

#include "../data_structure/persistent_array.hpp"

#include <vector>
#include <memory>
#include <cstdint>

namespace ebi {

struct persistent_unionfind {

private:
    using size_t = std::size_t;
    persistent_array<int, 64> par;

public:
    persistent_unionfind(size_t n) : par(std::vector<int>(n, -1)) { }

    int leader(int x, int time = -1) {
        int val = par.get(x, time);
        if(val < 0) return x;
        else return leader(val, time);
    }

    bool merge(int x, int y, int time = -1) {
        x = leader(x, time);
        y = leader(y, time);
        if(x == y) {
            par.set(0, par.get(0));
            return false;
        }
        int val_x = par.get(x, time);
        int val_y = par.get(y, time);
        if(val_x > val_y) std::swap(x, y);
        par.set(x, val_x + val_y, time);
        par.update(y, x);
        return true;
    }

    bool same(int x, int y, int time = -1) {
        return leader(x, time) == leader(y, time);
    }

    int size(int x, int time = -1) {
        return -par.get(leader(x, time));
    }
    
};

}