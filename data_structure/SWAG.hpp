#pragma once

#include <stack>
#include <cassert>

template<class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>
struct SWAG {
private:
    struct Node {
        Semigroup value;
        Semigroup fold_back;
        Node(Semigroup value, Semigroup fold_back) : value(value), fold_back(fold_back) { }
    };

    void move() {
        assert(!back.empty());
        Node p = back.top();
        back.pop();
        front.push(Node(p.value, p.value));
        while(!back.empty()) {
            Node p = back.top();
            back.pop();
            p.fold_back = op(p.value, front.top().fold_back);
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
            node.fold_back = op(p.fold_back, node.fold_back);
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
            return back.top().fold_back;
        }
        else if(back.empty()){
            return front.top().fold_back;
        }
        else{
            return op(front.top().fold_back, back.top().fold_back);
        }
    }
};