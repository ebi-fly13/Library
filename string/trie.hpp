#pragma once

#include <array>
#include <cassert>
#include <string>
#include <vector>

namespace ebi {

template <int char_size, int margin> struct trie {
  private:
    struct trie_node {
        int common;
        std::array<int, char_size> nxt;
        std::vector<int> accept;
        trie_node() : common(0) {
            nxt.fill(-1);
        }
    };

  public:
    trie() {
        nodes.emplace_back(trie_node());
    }

    void add(const std::string &str) {
        int idx = 0;
        for (const auto &c : str) {
            int val = c - margin;
            assert(0 <= val && val < char_size);
            if (nodes[idx].nxt[val] < 0) {
                nodes[idx].nxt[val] = int(nodes.size());
                nodes.emplace_back(trie_node());
            }
            idx = nodes[idx].nxt[val];
            nodes[idx].common++;
        }
        nodes[idx].accept.emplace_back(nodes[0].common++);
    }

    template <class F>
    void query(const std::string &str, int start, F func) const {
        int idx = 0;
        for (int i = start; i < int(str.size()); ++i) {
            int val = str[i] - margin;
            assert(0 <= val && val < char_size);
            int nxt = nodes[idx].nxt[val];
            if (nxt < 0) {
                return;
            }
            idx = nxt;
            for (const auto id : nodes[idx].accept) {
                func(id);
            }
        }
        return;
    }

    bool search(const std::string &str, int start, bool prefix = false) const {
        int idx = 0;
        for (int i = start; i < int(str.size()); ++i) {
            int val = str[i] - margin;
            assert(0 <= val && val < char_size);
            int nxt = nodes[idx].nxt[val];
            if (nxt < 0) {
                return -1;
            }
            idx = nxt;
        }
        return prefix ? true : (nodes[idx].accept.size() > 0);
    }

    int size() const {
        return int(nodes.size());
    }

  protected:
    std::vector<trie_node> nodes;
};

}  // namespace ebi