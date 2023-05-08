#pragma once

#include "../data_structure/Suspension.hpp"

/*
    reference: https://www.cs.cmu.edu/~rwh/theses/okasaki.pdf
               https://noshi91.github.io/Library/data_structure/stream.cpp
*/

#include <cassert>
#include <optional>

namespace ebi {

template <class T>
struct stream : suspension<std::optional<std::pair<T, stream<T>>>> {
  private:
    using Self = stream<T>;
    using cell_type = std::optional<std::pair<T, Self>>;
    using base_type = suspension<cell_type>;
    using base_type::force;

    stream(T x, Self s) : base_type(cell_type(std::in_place, x, s)) {}

  public:
    stream() : base_type(cell_type(std::nullopt)) {}
    stream(std::function<cell_type()> f) : base_type(f) {}
    bool empty() const {
        return !force().has_value();
    }
    T top() const {
        assert(!empty());
        return force()->first;
    }
    Self push(T x) const {
        return stream(x, *this);
    }
    Self pop() const {
        assert(!empty());
        return (*force()).second;
    }
    Self reverse() {
        return Self([x = *this]() mutable {
            Self ret;
            while (!x.empty()) {
                ret = ret.push(x.top());
                x = x.pop();
            }
            return ret.force();
        });
    }

    friend Self operator+(Self lhs, Self rhs) {
        return Self([lhs, rhs]() {
            if (lhs.empty()) {
                return rhs.force();
            } else {
                return cell_type(std::in_place, lhs.top(), lhs.pop() + rhs);
            }
        });
    }
};

}  // namespace ebi