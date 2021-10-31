#pragma once

#include <iostream>
#include <vector>
#include <cassert>

namespace ebi {

const std::vector<std::vector<int>> alldice = { 
    { 0, 1, 2, 3, 4, 5 },
    { 3, 1, 0, 5, 4, 2 },
    { 5, 1, 3, 2, 4, 0 },
    { 2, 1, 5, 0, 4, 3 },
    { 1, 5, 2, 3, 0, 4 },
    { 3, 5, 1, 4, 0, 2 },
    { 4, 5, 3, 2, 0, 1 },
    { 2, 5, 4, 1, 0, 3 },
    { 4, 0, 2, 3, 5, 1 },
    { 3, 0, 4, 1, 5, 2 },
    { 1, 0, 3, 2, 5, 4 },
    { 2, 0, 1, 4, 5, 3 },
    { 5, 4, 2, 3, 1, 0 },
    { 3, 4, 5, 0, 1, 2 },
    { 0, 4, 3, 2, 1, 5 },
    { 2, 4, 0, 5, 1, 3 },
    { 0, 3, 1, 4, 2, 5 },
    { 4, 3, 0, 5, 2, 1 },
    { 5, 3, 4, 1, 2, 0 },
    { 1, 3, 5, 0, 2, 4 },
    { 0, 2, 4, 1, 3, 5 },
    { 1, 2, 0, 5, 3, 4 },
    { 5, 2, 1, 4, 3, 0 },
    { 4, 2, 5, 0, 3, 1}
};

struct Dice {
private:
    int up = 0, front = 1, right = 2, left = 3, back = 4, down = 5;
public:
    Dice() = default;

    void setval(const std::vector<int> &_val) {
        assert(int(_val.size()) == 6);
        val = _val;
    }

    // y++
    void rollN() {
        int buff = down;
        down = back;
        back = up;
        up = front;
        front = buff;
    }

    // y--
    void rollS() {
        int buff = down;
        down = front;
        front = up;
        up = back;
        back = buff;
    }

    // x++
    void rollE() {
        int buff = down;
        down = right;
        right = up;
        up = left;
        left = buff;
    }

    // x--
    void rollW() {
        int buff = down;
        down = left;
        left = up;
        up = right;
        right = buff;
    }

    // 右回転(時計回り)
    void rollR() {
        int buff = right;
        right = back;
        back = left;
        left = front;
        front = buff;
    }

    // 左回転(反時計回り)
    void rollL() {
        int buff = left;
        left = back;
        back = right;
        right = front;
        front = buff;
    }

    void roll(char c) {
        if(c == 'N') rollN(); 
        else if(c == 'S') rollS();
        else if(c == 'E') rollE();
        else if(c == 'W') rollW();
        else if(c == 'R') rollR();
        else if(c == 'L') rollL();
        else assert(0);
    }

    int get_index(int x) const {
        for(int i = 0; i < 6; i++) {
            if(val[i] == x) return i;
        }
        assert(0);
    }

    void set(int u, int f) {
        for(const auto &v: alldice) {
            if(v[0] == u && v[1] == f) {
                up = v[0]; 
                front = v[1];
                right = v[2];
                left = v[3];
                back = v[4];
                down = v[5];
                return;
            }
        }
        assert(0);
    }

    std::vector<Dice> makeDice() const {
        std::vector<Dice> ret;
        for(int i = 0; i < 6; i++) {
            Dice d(*this);
            if(i == 1) d.rollN();
            if(i == 2) d.rollS();
            if(i == 3) { d.rollS(); d.rollS(); }
            if(i == 4) d.rollL();
            if(i == 5) d.rollR();
            for(int j = 0; j < 4; j++) {
                ret.emplace_back(d);
                d.rollE();
            }
        }
        return ret;
    }

    int top_val() const {
        return val[up];
    }

    int right_val() const {
        return val[right];
    }

    int left_val() const {
        return val[left];
    }

    int front_val() const {
        return val[front];
    }

    int back_val() const {
        return val[back];
    }

    int down_val() const {
        return val[down];
    }

    std::vector<int> now() const {
        std::vector<int> ret(6);
        ret[0] = top_val();
        ret[1] = front_val();
        ret[2] = right_val();
        ret[3] = left_val();
        ret[4] = back_val();
        ret[5] = down_val();
        return ret;
    }

    bool operator==(const Dice &rhs) const noexcept {
        std::vector<int> ret(6);
        for(const auto &idx: alldice) {
            for(int i = 0; i < 6; i++) {
                ret[i] = val[idx[i]];
            }
            if(ret == rhs.val) return true;
        }
        return false;
    }

    std::vector<int> val = {0, 1, 2, 3, 4, 5};
};

std::istream& operator>>(std::istream& os, Dice &d) {
    return os >> d.val[0] >> d.val[1] >> d.val[2] >> d.val[3] >> d.val[4] >> d.val[5];  
}

}