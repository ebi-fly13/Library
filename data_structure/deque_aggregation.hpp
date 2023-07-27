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
        assert(_front.empty());
        int sz = _back.size();
        std::stack<Semigroup> buff;
        for (int i = 0; i < sz / 2; i++) {
            buff.push(_back.top().val);
            _back.pop();
        }
        while (!_back.empty()) {
            Semigroup x = _back.top().val;
            _back.pop();
            push_front(x);
        }
        while (!buff.empty()) {
            Semigroup x = buff.top();
            buff.pop();
            push_back(x);
        }
    }

    void move_back() {
        assert(_back.empty());
        int sz = _front.size();
        std::stack<Semigroup> buff;
        for (int i = 0; i < sz / 2; i++) {
            buff.push(_front.top().val);
            _front.pop();
        }
        while (!_front.empty()) {
            Semigroup x = _front.top().val;
            _front.pop();
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
        return _front.size() + _back.size();
    }

    bool empty() const {
        return size() == 0;
    }

    Semigroup front() {
        assert(!empty());
        if (_front.empty()) move_front();
        return _front.top().val;
    }

    Semigroup back() {
        assert(!empty());
        if (_back.empty()) move_back();
        return _back.top().val;
    }

    void push_front(Semigroup x) {
        Node node = {x, x};
        if (!_front.empty()) {
            node.fold = op(x, _front.top().fold);
        }
        _front.push(node);
    }

    void push_back(Semigroup x) {
        Node node = {x, x};
        if (!_back.empty()) {
            node.fold = op(_back.top().fold, x);
        }
        _back.push(node);
    }

    void pop_back() {
        assert(!empty());
        if (_back.empty()) move_back();
        _back.pop();
    }

    void pop_front() {
        assert(!empty());
        if (_front.empty()) move_front();
        _front.pop();
    }

    Semigroup fold_all() {
        assert(!empty());
        if (_front.empty()) {
            return _back.top().fold;
        } else if (_back.empty()) {
            return _front.top().fold;
        } else {
            return op(_front.top().fold, _back.top().fold);
        }
    }

  private:
    std::stack<Node> _front, _back;
};

}  // namespace ebi