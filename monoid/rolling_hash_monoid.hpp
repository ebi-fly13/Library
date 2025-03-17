#pragma once

#include <utility>

#include "../modint/modint61.hpp"
#include "../utility/random_number_generator.hpp"

namespace ebi {

struct rolling_hash_monoid : std::pair<modint61, modint61> {
  private:
    using Self = rolling_hash_monoid;
    using std::pair<modint61, modint61>::pair;

  public:
    template <class T> rolling_hash_monoid(T x) {
        this->first = get_base();
        this->second = x;
    }

    modint61 get_hash() {
        return this->second;
    }

    Self &operator+=(const Self &rhs) {
        this->first = this->first * rhs.first;
        this->second = this->second * rhs.first + rhs.second;
        return *this;
    }

    friend Self operator+(const Self &lhs, const Self &rhs) {
        return Self(lhs) += rhs;
    }

    static Self e() {
        return {1, 0};
    }

    static modint61 get_base() {
        static modint61 base = 0;
        static random_number_generator rng;
        while (base == 0) {
            base = rng.get<std::uint64_t>(2, modint61::mod());
        }
        return base;
    }
};

}  // namespace ebi