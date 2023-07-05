#pragma once

#include <cassert>
#include <deque>
#include <utility>

namespace ebi {

template <class T> struct convex_hull_trick {
  private:
    bool check(std::pair<T, T> a, std::pair<T, T> b, std::pair<T, T> c) {
        return (b.first - a.first) * (c.second - b.second) >=
               (c.first - b.first) * (b.second - a.second);
    }

    T f(std::pair<T, T> a, T x) {
        return a.first * x + a.second;
    }

  public:
    convex_hull_trick() = default;

    void add(T a, T b) {
        while (lines.size() >= 2 &&
               check(*(lines.end() - 2), lines.back(), {a, b})) {
            lines.pop_back();
        }
        lines.emplace_back(a, b);
    }

    T min(T x) {
        assert(!lines.empty());
        while (lines.size() >= 2 && f(lines[0], x) >= f(lines[1], x)) {
            lines.pop_front();
        }
        return f(lines[0], x);
    }

  private:
    std::deque<std::pair<T, T>> lines;
};

}  // namespace ebi