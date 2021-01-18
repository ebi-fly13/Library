#pragma once

/*
    reference: https://scrapbox.io/data-structures/Sliding_Window_Aggregation
*/

#include <stack>
#include <cassert>

namespace ebi {

template<class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>
struct SWAG {
private:
    struct Node {
        Semigroup value;
        Semigroup fold;
        Node(Semigroup value, Semigroup fold) : value(value), fold(fold) { }
    };

    void move() {
        assert(!back.empty());
        Node p = back.top();
        back.pop();
        front.push(Node(p.value, p.value));
        while(!back.empty()) {
            Node p = back.top();
            back.pop();
            p.fold = op(p.value, front.top().fold);
            front.push(p);
        }
    }

    std::stack<Node> front, back;

public:

    SWAG() { }

    int size() {
        return front.size() + back.size();
    }

    bool empty() {
        if(size()==0) return true;
        return false;
    }

    void push(Semigroup x) {
        Node node(x,x);
        if(back.size()!=0) {
            Node p = back.top();
            node.fold = op(p.fold, node.fold);
        }
        back.push(node);
    }

    void pop() {
        assert(!empty());
        if(front.empty()) {
            move();
        }
        front.pop();
    }

    Semigroup fold_all() {
        assert(!empty());
        if(front.empty()) {
            return back.top().fold;
        }
        else if(back.empty()){
            return front.top().fold;
        }
        else{
            return op(front.top().fold, back.top().fold);
        }
    }
};

} // namespace ebi