#pragma once

#include <vector>
#include <queue>
#include <functional>

/*
    reference: https://twitter.com/maspy_stars/status/1436690222465486848
    verify: https://atcoder.jp/contests/abc218/submissions/25800862
*/

namespace ebi {

template<class T,
        class Container = std::vector<T>,
        class Compare = std::less<typename Container::value_type>>
struct removable_priority_queue {
private:
    void update() {
        while(!rm_que.empty() && que.top() == rm_que.top()) {
            que.pop();
            rm_que.pop();
        }
        return;
    }
public:
    removable_priority_queue() = default;

    bool empty() const {
        return (size() == 0);
    }

    int size() const {
        return int(que.size() - rm_que.size());
    }

    T top() {
        assert(!empty());
        update();
        return que.top();
    }

    void pop() {
        assert(!empty());
        update();
        que.pop();
        return;
    }

    void push(const T &x) {
        que.push(x);
        return;
    }

    template<class... Args>
    void emplace(Args&&... args) {
        que.emplace(std::forward<Args>(args)...);
        return;
    }

    void remove(const T &x) {
        rm_que.push(x);
        assert(que.size() >= rm_que.size());
        return;
    }

    template<class... Args>
    void emplace_remove(Args&&... args) {
        rm_que.emplace(std::forward<Args>(args)...);
        assert(que.size() >= rm_que.size());
        return;
    }
private:
    std::priority_queue<T, Container, Compare> que, rm_que;
};

}