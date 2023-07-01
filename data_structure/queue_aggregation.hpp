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
        assert(!back.empty());
        Node p = back.top();
        back.pop();
        front.push({p.val, p.val});
        while (!back.empty()) {
            Semigroup x = back.top().val;
            back.pop();
            front.push({x, op(x, front.top().fold)});
        }
    }

  public:
    queue_aggregation() {}

    int size() {
        return front.size() + back.size();
    }

    bool empty() {
        return size() == 0;
    }

    void push(Semigroup x) {
        Node node = {x, x};
        if (!back.empty()) {
            node.fold = op(back.top().fold, x);
        }
        back.push(node);
    }

    void pop() {
        assert(!empty());
        if (front.empty()) {
            move();
        }
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