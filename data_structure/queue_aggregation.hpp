#pragma once

/*
    reference: https://scrapbox.io/data-structures/Sliding_Window_Aggregation
*/

#include <cassert>
#include <stack>

namespace ebi {

template <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>
struct queue_aggregation {
  private:
    struct Node {
        Semigroup val;
        Semigroup fold;
    };

    void move() {
        assert(!_back.empty());
        Node p = _back.top();
        _back.pop();
        _front.push({p.val, p.val});
        while (!_back.empty()) {
            Semigroup x = _back.top().val;
            _back.pop();
            _front.push({x, op(x, _front.top().fold)});
        }
    }

  public:
    queue_aggregation() {}

    int size() {
        return _front.size() + _back.size();
    }

    bool empty() {
        return size() == 0;
    }

    void push(Semigroup x) {
        Node node = {x, x};
        if (!_back.empty()) {
            node.fold = op(_back.top().fold, x);
        }
        _back.push(node);
    }

    Semigroup front() {
        assert(!empty());
        if (_front.empty()) {
            move();
        }
        return _front.top().val;
    }

    void pop() {
        assert(!empty());
        if (_front.empty()) {
            move();
        }
        _front.pop();
    }

    void clear() {
        _front = std::stack<Node>();
        _back = std::stack<Node>();
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