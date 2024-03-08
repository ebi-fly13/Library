#pragma once

#include <cassert>
#include <vector>

#include "../data_structure/removable_priority_queue.hpp"

namespace ebi {

template <class T> struct double_ended_priority_queue {
  public:
    double_ended_priority_queue() = default;

    template <class InputIterator>
    double_ended_priority_queue(InputIterator first, InputIterator last) {
        min = removable_priority_queue<T, std::vector<T>, std::greater<T>>(
            first, last);
        max = removable_priority_queue<T>(first, last);
    }

    bool empty() const {
        return min.empty() && max.empty();
    }

    int size() const {
        assert(min.size() == max.size());
        return min.size();
    }

    void push(T x) {
        min.push(x);
        max.push(x);
    }

    template <class... Args> void emplace(Args &&...args) {
        min.emplace(std::forward<Args>(args)...);
        max.emplace(std::forward<Args>(args)...);
        return;
    }

    void pop_min() {
        T x = min.top();
        min.pop();
        max.remove(x);
    }

    void pop_max() {
        T x = max.top();
        max.pop();
        min.remove(x);
    }

    T get_min() {
        assert(!min.empty());
        return min.top();
    }

    T get_max() {
        assert(!max.empty());
        return max.top();
    }

  private:
    removable_priority_queue<T, std::vector<T>, std::greater<T>> min;
    removable_priority_queue<T> max;
};

}  // namespace ebi