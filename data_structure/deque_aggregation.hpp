#pragma once

#include <cassert>
#include <stack>

namespace ebi {

template <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>
struct deque_aggregation {
  private:
    struct Node {
        Semigroup val;
        Semigroup fold;
    };

    void move_front() {
        assert(front.empty());
        int sz = back.size();
        std::stack<Semigroup> buff;
        for (int i = 0; i < sz / 2; i++) {
            buff.push(back.top().val);
            back.pop();
        }
        while (!back.empty()) {
            Semigroup x = back.top().val;
            back.pop();
            push_front(x);
        }
        while (!buff.empty()) {
            Semigroup x = buff.top();
            buff.pop();
            push_back(x);
        }
    }

    void move_back() {
        assert(back.empty());
        int sz = front.size();
        std::stack<Semigroup> buff;
        for (int i = 0; i < sz / 2; i++) {
            buff.push(front.top().val);
            front.pop();
        }
        while (!front.empty()) {
            Semigroup x = front.top().val;
            front.pop();
            push_back(x);
        }
        while (!buff.empty()) {
            Semigroup x = buff.top();
            buff.pop();
            push_front(x);
        }
    }

  public:
    deque_aggregation() = default;

    int size() const {
        return front.size() + back.size();
    }

    bool empty() const {
        return size() == 0;
    }

    void push_front(Semigroup x) {
        Node node = {x, x};
        if (!front.empty()) {
            node.fold = op(x, front.top().fold);
        }
        front.push(node);
    }

    void push_back(Semigroup x) {
        Node node = {x, x};
        if (!back.empty()) {
            node.fold = op(back.top().fold, x);
        }
        back.push(node);
    }

    void pop_back() {
        assert(!empty());
        if (back.empty()) move_back();
        back.pop();
    }

    void pop_front() {
        assert(!empty());
        if (front.empty()) move_front();
        front.pop();
    }

    Semigroup fold_all() {
        assert(!empty());
        if (front.empty()) {
            return back.top().fold;
        } else if (back.empty()) {
            return front.top().fold;
        } else {
            return op(front.top().fold, back.top().fold);
        }
    }

  private:
    std::stack<Node> front, back;
};

}  // namespace ebi