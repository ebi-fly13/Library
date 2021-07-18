#pragma once

#include <cassert>

#include "../graph/scc_graph.hpp"

namespace ebi {

struct two_sat {
public:
    two_sat(int _n) : n(_n), scc(2*n) { }

    void add_clause(int p, bool _p, int q, bool _q) {
        assert(0 <= p && p < n);
        assert(0 <= q && q < n);
        scc.add_edge(2*p + (_p ? 1 : 0), 2*q + (_q ? 0 : 1));
        scc.add_edge(2*q + (_q ? 1 : 0), 2*p + (_p ? 0 : 1));
    }

    bool satisfiable() {
        scc.scc();
        std::vector<int> id = scc.scc_id();
        _answer.resize(n);
        for(int i = 0; i < n; i++) {
            if(id[2*i] == id[2*i + 1]) {
                return false;
            }
            _answer[i] = id[2*i] > id[2*i + 1];
        }
        return true;
    }

    std::vector<bool> answer() {
        return _answer;
    }
private:
    int n;
    scc_graph scc;
    std::vector<bool> _answer;
};

}