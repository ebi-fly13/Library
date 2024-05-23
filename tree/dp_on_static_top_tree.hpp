#pragma once

#include "../tree/static_top_tree.hpp"

namespace ebi {

template <class T, class Path, class Point, class Compress, class Rake,
          class Add_edge, class Add_vertex>
struct dp_on_static_top_tree {
  private:
    void dfs(int v) {
        auto [lch, rch] = stt.child(v);
        if (lch != -1) dfs(lch);
        if (rch != -1) dfs(rch);
        update_(v);
    }

    void update_(int v) {
        if (stt.type(v) == Type::Vertex) {
            path[v] = vertex[v];
        } else if (stt.type(v) == Type::Compress) {
            path[v] =
                compress(path[stt.left_child(v)], path[stt.right_child(v)]);
        } else if (stt.type(v) == Type::Rake) {
            point[v] =
                rake(point[stt.left_child(v)], point[stt.right_child(v)]);
        } else if (stt.type(v) == Type::AddEdge) {
            point[v] = add_edge(path[stt.left_child(v)]);
        } else if (stt.type(v) == Type::AddVertex) {
            path[v] = add_vertex(point[stt.left_child(v)], vertex[v]);
        }
    }

    void update(int v) {
        while (v != -1) {
            update_(v);
            v = stt.parent(v);
        }
    }

  public:
    dp_on_static_top_tree(const Graph<T> &g, int root,
                          const std::vector<Path> &vertex_,
                          const Compress &compress_, const Rake &rake_,
                          const Add_edge &add_edge_,
                          const Add_vertex &add_vertex_)
        : stt(g, root),
          n(stt.node_num()),
          path(n),
          point(n),
          vertex(vertex_),
          compress(compress_),
          rake(rake_),
          add_edge(add_edge_),
          add_vertex(add_vertex_) {
        dfs(stt.root());
    }

    Path get() const {
        return path[stt.root()];
    }

    void set(int v, Path x) {
        vertex[v] = x;
        update(v);
    }

  private:
    static_top_tree<T> stt;

    int n;
    std::vector<Path> path;
    std::vector<Point> point;
    std::vector<Path> vertex;
    const Compress compress;
    const Rake rake;
    const Add_edge add_edge;
    const Add_vertex add_vertex;
};

}  // namespace ebi