#pragma once

#include <vector>
#include <queue>
#include <cassert>

namespace ebi {

template<class T>
struct slope_trick {
private:
    using Self = slope_trick<T>;

    void pop_L() {
        if(L.empty()) return;
        L.pop(); 
        return;
    }

    T top_L() const {
        if(L.empty()) return -INF;
        return L.top() + add_L;
    }

    void push_L(const T &a) {
        L.push(a-add_L);
        return;
    }

    void pop_R() {
        if(R.empty()) return;
        R.pop();
        return;
    }

    T top_R() const {
        if(R.empty()) return INF;
        return R.top() + add_R;
    }

    void push_R(const T &a) {
        R.push(a-add_R);
        return;
    }

    int size() {
        return L.size() + R.size();
    }

    void swap(Self &a, Self &b) {
        std::swap(a.min_f, b.min_f);
        std::swap(a.L, b.L);
        std::swap(a.R, b.R);
        std::swap(a.add_L, b.add_L);
        std::swap(a.add_R, b.add_R);
        return;
    }
public:
    slope_trick() : min_f(0), add_L(0), add_R(0) { }

    T min() const {
        return min_f;
    }

    std::pair<T, T> argmin() const {
        return {top_L(), top_R()};
    }

    void add_all(const T &a) {
        min_f += a;
        return;
    }

    // add (x-a)_+
    void add_x_minus_a(const T &a) {
        min_f += std::max(T(0), top_L() - a);
        if(top_L() <= a) {
            push_R(a);
        }
        else {
            push_L(a);
            push_R(top_L());
            pop_L();
        }
        return;
    }

    // add (a-x)_+
    void add_a_minus_x(const T &a) {
        min_f += std::max(T(0), a - top_R());
        if(top_R() >= a) {
            push_L(a);
        }
        else {
            push_R(a);
            push_L(top_R());
            pop_R();
        }
        return;
    }

    // add |x-a|
    void add_abs(const T &a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
        return;
    }

    void sliding_window_minimum(const T &a, const T &b) {
        assert(a <= b);
        add_L += a;
        add_R += b;
        return;
    }

    void shift(const T &a) {
        sliding_window_minimum(a, a);
    }

    void merge(Self &st) {
        if(st.size() > size()) {
            swap((*this), st);
        }
        min_f += st.min_f;
        while(!st.L.empty()) {
            add_a_minus_x(st.top_L());
            st.pop_L();
        }
        while(!st.R.empty()) {
            add_x_minus_a(st.top_R());
            st.pop_R();
        }
        return;
    }

    // __/
    void right_cumulative_min() {
        L = std::priority_queue<T>();
    }

    // \__
    void left_cumulative_min() {
        R = std::priority_queue<T, std::vector<T>, std::greater<T>>();
    }

private:
    T min_f;
    std::priority_queue<T> L;
    std::priority_queue<T, std::vector<T>, std::greater<T>> R;
    T add_L, add_R;
    const T INF = std::numeric_limits<T>::max()/4;
};

}