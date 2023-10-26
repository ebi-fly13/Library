#pragma once

#include <concepts>
#include <iostream>
#include <utility>

namespace ebi {

template <class T>
concept Modint = requires(T a, T b) {
    a + b;
    a - b;
    a * b;
    a / b;
    a.inv();
    a.val();
    a.pow(std::declval<long long>());
    T::mod();
};

template <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {
    long long x;
    os >> x;
    a = x;
    return os;
}

template <Modint mint>
std::ostream &operator<<(std::ostream &os, const mint &a) {
    return os << a.val();
}

}  // namespace ebi