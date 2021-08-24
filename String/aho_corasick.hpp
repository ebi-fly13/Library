#pragma once

#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <map>
#include <cassert>

#include "trie.hpp"

namespace ebi {

template<int char_size, int margin>
struct aho_corasick : trie<char_size+1, margin> {
private:
    void move_nxt(int &now, int val) {
        assert(0 <= val && val < char_size);
        while(this->nodes[now].nxt[val] == -1) now = this->nodes[now].nxt[FAIL];
        now = this->nodes[now].nxt[val];
        return;
    }
    using trie<char_size + 1, margin>::trie;
    using trie<char_size + 1, margin>::nodes;

public:

    void build() {
        correct.resize(this->size());
        for(int i = 0; i < this->size(); ++i) {
            correct[i] = int(this->nodes[i].accept.size());
        }
        std::queue<int> que;
        for(int i = 0; i <= char_size; ++i) {
            if(this->nodes[0].nxt[i] != -1) {
                this->nodes[this->nodes[0].nxt[i]].nxt[FAIL] = 0;
                que.push(this->nodes[0].nxt[i]);
            } else {
                this->nodes[0].nxt[i] = 0;
            }
        }
        while(!que.empty()) {
            int idx = que.front();
            que.pop();
            auto &now = this->nodes[idx];
            correct[idx] += correct[now.nxt[FAIL]];
            for(int i = 0; i < char_size; ++i) {
                if(now.nxt[i] == -1) continue;
                int fail = now.nxt[FAIL];
                while(this->nodes[fail].nxt[i] == -1) fail = this->nodes[fail].nxt[FAIL];
                this->nodes[now.nxt[i]].nxt[FAIL] = this->nodes[fail].nxt[i];
                std::vector<int> &u = this->nodes[now.nxt[i]].accept;
                std::vector<int> &v = this->nodes[this->nodes[fail].nxt[i]].accept;
                std::vector<int> accept;
                std::set_union(u.begin(), u.end(), v.begin(), v.end(), std::back_inserter(accept));
                u = accept;
                que.push(now.nxt[i]);
            }
        }
    }

    std::map<int, int> match(const std::string &str, int now = 0) {
        std::map<int, int> map;
        for(const auto &c: str) {
            move_nxt(now, c - margin);
            for(const auto &a: this->nodes[now].accept) {
                map[a]++;
            }
        }
        return map;
    }

    std::pair<int,int> move(const char &c, int now) {
        int sum = 0;
        move_nxt(now, c - margin);
        sum += correct[now];
        return {sum, now};
    }
private:
    const int FAIL = char_size;
    std::vector<int> correct;
};

}
