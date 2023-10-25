#pragma once

#include <concepts>
#include <iostream>

namespace ebi {

template <class T>
concept modint = requires(T a, T b) {
    a + b;
    a - b;
    a *b;
    a / b;
    a.inv();
    a.val();
    a.mod();
};

template <modint mint> std::istream &operator>>(std::istream &os, mint &a) {
    long long x;
    os >> x;
    a = x;
    return os;
}

template <modint mint>
std::ostream &operator<<(std::ostream &os, const mint &a) {
    return os << a.val();
}

}  // namespace ebi