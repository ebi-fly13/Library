#pragma once

#include "../graph/base.hpp"

namespace ebi {

enum Type { Vertex, Compress, Rake, AddEdge, AddVertex };

template <class T> struct static_top_tree {
  private:
    struct Node {
        int par = -1, lch = -1, rch = -1;
        Type ty = Type::Vertex;
    };

    void dfs_sz(int v) {
        for (auto &e : g[v]) {
            if (e.to == par[v]) continue;
            par[e.to] = v;
            dfs_sz(e.to);
            sz[v] += sz[e.to];
            if (sz[e.to] > sz[g[v][0].to] || g[v][0].to == par[v]) {
                std::swap(e, g[v][0]);
            }
        }
    }

    int new_node(int k, int l, int r, Type t) {
        if (k == -1) {
            k = (int)stt.size();
            stt.emplace_back(-1, l, r, t);
        } else {
            stt[k].lch = l;
            stt[k].rch = r;
            stt[k].ty = t;
        }
        if (l != -1) stt[l].par = k;
        if (r != -1) stt[r].par = k;
        return k;
    }

    std::pair<int, int> merge(const std::vector<std::pair<int, int>> &a,
                              Type t) {
        if (a.size() == 1) {
            return a[0];
        }
        int sum = 0;
        for (auto [v_, s] : a) sum += s;
        std::vector<std::pair<int, int>> b, c;
        for (auto [i, s] : a) {
            if (sum > s)
                b.emplace_back(i, s);
            else
                c.emplace_back(i, s);
            sum -= 2 * s;
        }
        auto [i, si] = merge(b, t);
        auto [j, sj] = merge(c, t);
        return {new_node(-1, i, j, t), si + sj};
    }

    std::pair<int, int> compress(int v) {
        std::vector<std::pair<int, int>> path{add_vertex(v)};
        while (g[v][0].to != par[v]) {
            path.emplace_back(add_vertex(v = g[v][0].to));
        }
        return merge(path, Type::Compress);
    }

    std::pair<int, int> rake(int v) {
        std::vector<std::pair<int, int>> ch;
        for (int i = 1; i < (int)g[v].size(); i++) {
            if (g[v][i].to == par[v]) continue;
            ch.emplace_back(add_edge(g[v][i].to));
        }
        return ch.empty() ? std::pair<int, int>{-1, 0} : merge(ch, Type::Rake);
    }

    std::pair<int, int> add_edge(int v) {
        auto [i, si] = compress(v);
        return {new_node(-1, i, -1, Type::AddEdge), si};
    }

    std::pair<int, int> add_vertex(int v) {
        auto [i, si] = rake(v);
        return {new_node(v, i, -1, i == -1 ? Type::Vertex : Type::AddVertex),
                si + 1};
    }

  public:
    static_top_tree(Graph<T> g_, int root = 0)
        : n(g_.size()), g(g_), par(n, -1), sz(n, 1), stt(n) {
        dfs_sz(root);
        stt_root = compress(root).first;
    }

    int node_num() const {
        return (int)stt.size();
    }

    int parent(int v) const {
        return stt[v].par;
    }

    std::pair<int, int> child(int v) const {
        return {stt[v].lch, stt[v].rch};
    }

    int left_child(int v) const {
        return stt[v].lch;
    }

    int right_child(int v) const {
        return stt[v].rch;
    }

    Type type(int v) const {
        return stt[v].ty;
    }

    int root() const {
        return stt_root;
    }

  private:
    int n;
    Graph<T> g;
    std::vector<int> par, sz;
    std::vector<Node> stt;
    int stt_root;
};

}  // namespace ebi