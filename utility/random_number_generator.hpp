#pragma once

#include <algorithm>
#include <cstdint>
#include <numeric>
#include <random>
#include <vector>

namespace ebi {

struct random_number_generator {
    random_number_generator(int seed = -1) {
        if (seed < 0) seed = rnd();
        mt.seed(seed);
    }

    void set_seed(int seed) {
        mt.seed(seed);
    }

    template <class T> T get(T a, T b) {
        std::uniform_int_distribution<T> dist(a, b - 1);
        return dist(mt);
    }

    std::vector<int> get_permutation(int n) {
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::shuffle(p.begin(), p.end(), mt);
        return p;
    }

  private:
    std::mt19937_64 mt;
    std::random_device rnd;
};

}  // namespace ebi