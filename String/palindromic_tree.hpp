#include <vector>
#include <cstdint>
#include <string>
#include <map>

namespace ebi {

struct palindromic_tree {
private:
    using i64 = std::int64_t;
    struct Node {
        std::map<char, int> edges;
        int len; // 回文の長さ
        i64 num = 0;
        int suffix_link = 0;
    };
public:
    palindromic_tree(const std::string &str) {
        tree.resize(2);
        tree[0].len = -1;
        tree[1].len = 0;
        for(auto c: str) {
            add_char(c);
        }
        for(int i = (int)tree.size() - 1; i >= 2; i--) {
            sum += tree[i].num;
            tree[tree[i].suffix_link].num += tree[i].num;
        }
    }

    // 末尾に x を追加し、末尾を使った最大の長さを返す。
    int add_char(char x) {
        s.push_back(x);
        int pos = s.size() - 1;
        int now = last_idx;
        while(true) {
            int len = tree[now].len;
            if(0 <= pos - len - 1 && s[pos - len - 1] == x) {
                break;
            }
            now = tree[now].suffix_link;
        }
        if(tree[now].edges.find(x) != tree[now].edges.end()) {
            last_idx = tree[now].edges[x];
            tree[last_idx].num++;
            return tree[last_idx].len;
        }
        last_idx = tree.size();
        tree[now].edges[x] = last_idx;
        Node node;
        node.len = tree[now].len + 2;
        node.num = 1;
        if(node.len == 1) {
            node.suffix_link = 1;
            tree.emplace_back(node);
            return node.len;
        }
        while(true) {
            now = tree[now].suffix_link;
            int len = tree[now].len;
            if(0 <= pos - 1 - len && s[pos - 1 - len] == x) break;
        }
        node.suffix_link = tree[now].edges[x];
        tree.emplace_back(node);
        return node.len;
    }

    int count_types() {
        return (int)tree.size() - 2;
    }

    i64 count_num() {
        return sum;
    }
private:
    std::string s;
    std::vector<Node> tree;
    int last_idx = 1;
    i64 sum = 0;
};

}