#pragma once

#include <cstdint>
#include <random>

namespace ebi {

struct random_number_generator_64 {
  private:
    using u64 = std::uint64_t;
    std::random_device rnd;
    std::mt19937_64 mt;

  public:
    random_number_generator_64() : mt(rnd()) {}

    u64 get(u64 a, u64 b) {
        std::uniform_int_distribution<u64> dist(a, b - 1);
        return dist(mt);
    }
};

}  // namespace ebi