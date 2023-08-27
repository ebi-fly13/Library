#pragma once

#include <iomanip>
#include <iostream>
#include <optional>
#include <vector>

namespace ebi {

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa) {
    return os << pa.first << " " << pa.second;
}

template <typename T1, typename T2>
std::istream &operator>>(std::istream &os, std::pair<T1, T2> &pa) {
    return os >> pa.first >> pa.second;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    for (std::size_t i = 0; i < vec.size(); i++)
        os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &os, std::vector<T> &vec) {
    for (T &e : vec) std::cin >> e;
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::optional<T> &opt) {
    if (opt) {
        os << opt.value();
    } else {
        os << "invalid value";
    }
    return os;
}

void fast_io() {
    std::cout << std::fixed << std::setprecision(15);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
}

}  // namespace ebi