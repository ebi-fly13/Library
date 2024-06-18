#pragma once

#include "../tree/heavy_light_decomposition.hpp"

namespace ebi {

template <class T>
template <class ADD, class QUERY, class CLEAR, class RESET>
void heavy_light_decomposition<T>::dsu_on_tree(const ADD &add,
                                               const QUERY &query,
                                               const CLEAR &clear,
                                               const RESET &reset) const {
    auto dfs = [&](auto &&self, int v) -> void {
        for (auto e : g[v].next()) {
            if (e.to == parent(v)) continue;
            self(self, e.to);
        }
        if (sz[v] != 1) {
            self(self, g[v][0].to);
            for (int i = out[g[v][0].to]; i < out[v]; i++) {
                add(rev[i]);
            }
        }
        add(v);
        query(v);
        if (nxt[v] == v) {
            for (int i = in[v]; i < out[v]; i++) {
                clear(rev[i]);
            }
            reset();
        }
        return;
    };
    dfs(dfs, root);
    return;
}

}  // namespace ebi