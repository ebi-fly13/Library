#pragma once

/*
    reference: https://theory-and-me.hatenablog.com/entry/2020/03/17/180157
    depends on mf_graph in atcoder library(acl).
*/

namespace ebi {

template<class Cap>
struct submodular {
public:
    submodular(int n) : gh(n+2), s(n), t(n+1)  { }

    void add_one_variable_function(int i, Cap f0, Cap f1) {
        if(f0 <= f1) {
            gh.add_edge(s, i, f1-f0);
            R += f0;
        }
        else {
            gh.add_edge(i, t, f0-f1);
            R += f1;
        }
    }

    void add_two_variable_function(int i, int j, Cap a, Cap b, Cap c, Cap d) {
        assert(i < j);
        R += a;
        add_one_variable_function(i, 0, c-a);
        add_one_variable_function(j, 0, d-c);
        gh.add_edge(i, j, b+c-a-d);
    }

    Cap min() {
        return gh.flow(s, t) + R;
    }
private:
    atcoder::mf_graph<Cap> gh;
    int s,t;
    Cap R = 0;
};

}
