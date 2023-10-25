#pragma once

#include <concepts>

namespace ebi {

template<class T>
concept modint = requires (T a, T b) {
    a + b;
    a - b;
    a * b;
    a / b;
    a.inv();
    a.val();
    a.mod();
};

}  // namespace ebi