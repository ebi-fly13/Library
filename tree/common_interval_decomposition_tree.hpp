#pragma once

#include <cassert>
#include <numeric>
#include <vector>

#include "../data_structure/sparse_table.hpp"

/*
reference: https://www.mathenachia.blog/permutation-tree/
*/

namespace ebi {

struct common_interval_decomposition_tree {
  public:
    enum NodeType {
        Prime,
        Dec,
        Inc,
        One,
    };

    struct Node {
        int parent;
        NodeType type;
        int l, r;
    };

  private:
    static int op(int a, int b) {
        return a < b ? a : b;
    }

    void build(const std::vector<int> &p) {
        int n = (int)p.size();
        std::vector<int> q(n, -1);
        for (int i = 0; i < n; i++) {
            assert(0 <= p[i] && p[i] < n && q[p[i]] == -1);
            q[p[i]] = i;
        }
        sparse_table<int, op> static_range_min(q);
        struct LeftBase {
            int l;
            int vl, vr;
        };
        struct Common {
            int l, r, v;
        };
        std::vector<LeftBase> stack;
        std::vector<Common> commons;
        for (int r = 1; r <= n; r++) {
            int a = p[r - 1];
            LeftBase y = {r - 1, a, a + 1};
            while (!stack.empty()) {
                if (y.vl < stack.back().vl) stack.back().vl = y.vl;
                if (y.vr > stack.back().vr) stack.back().vr = y.vr;
                auto x = stack.back();
                if (static_range_min.fold(x.vl, x.vr) < x.l) {
                    stack.pop_back();
                    auto &new_x = stack.back();
                    if (x.vl < new_x.vl) new_x.vl = x.vl;
                    if (x.vr > new_x.vr) new_x.vr = x.vr;
                } else if (x.vr - x.vl == r - x.l) {
                    y = x;
                    stack.pop_back();
                    commons.emplace_back(x.l, r, x.vl);
                } else {
                    break;
                }
            }
            stack.push_back(y);
        }
        while (stack.size() >= 2) {
            auto x = stack.back();
            stack.pop_back();
            auto &new_x = stack.back();
            if (x.vl < new_x.vl) new_x.vl = x.vl;
            if (x.vr > new_x.vr) new_x.vr = x.vr;
            if (new_x.vr - new_x.vl == n - new_x.l) {
                commons.emplace_back(new_x.l, n, new_x.vl);
            }
        }
        assert(stack.size() == 1);
        for (int i = 0; i < n; i++) tree.emplace_back(-1, One, i, i + 1);
        std::vector<int> id(n);
        std::iota(id.begin(), id.end(), 0);
        std::vector<int> right_list(n);
        std::iota(right_list.begin(), right_list.end(), 1);
        for (auto common : commons) {
            int m = right_list[common.l];
            if (right_list[m] == common.r) {
                int a = id[common.l];
                int b = id[m];
                right_list[common.l] = common.r;
                auto t = p[common.l] < p[common.r - 1] ? Inc : Dec;
                if (tree[a].type == t) {
                    tree[b].parent = a;
                    tree[a].r = common.r;
                } else {
                    int c = (int)tree.size();
                    tree.emplace_back(-1, t, common.l, common.r);
                    tree[a].parent = c;
                    tree[b].parent = c;
                    id[common.l] = c;
                }
            } else {
                int c = (int)tree.size();
                tree.emplace_back(-1, Prime, common.l, common.r);
                for (int i = common.l; i < common.r; i = right_list[i]) {
                    tree[id[i]].parent = c;
                }
                id[common.l] = c;
                right_list[common.l] = common.r;
            }
        }
    }

  public:
    common_interval_decomposition_tree(const std::vector<int> &p) {
        build(p);
    }

    std::vector<Node> get_tree() const {
        return tree;
    }

  private:
    std::vector<Node> tree;
};

}  // namespace ebi