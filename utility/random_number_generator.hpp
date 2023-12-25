#pragma once

#include <cstdint>
#include <random>

namespace ebi {

struct random_number_generator {
    random_number_generator(int seed = -1) {
        if (seed < 0) seed = rnd();
        mt.seed(seed);
    }

    template <class T> T get(T a, T b) {
        std::uniform_int_distribution<T> dist(a, b - 1);
        return dist(mt);
    }

  private:
    std::mt19937_64 mt;
    std::random_device rnd;
};

}  // namespace ebi