#pragma once

/*
    reference: https://theory-and-me.hatenablog.com/entry/2020/03/17/180157
    depends on mf_graph in atcoder library(acl).
*/

namespace ebi {

template <class Cap> struct submodular {
  public:
    submodular(int n, int add_vertex = 0)
        : gh(n + add_vertex + 2),
          s(n),
          t(n + 1),
          max(n + add_vertex + 2),
          u(n + 2) {}

    void add_one_variable_function(int i, Cap f0, Cap f1) {
        if (f0 <= f1) {
            gh.add_edge(s, i, f1 - f0);
            R += f0;
        } else {
            gh.add_edge(i, t, f0 - f1);
            R += f1;
        }
    }

    void add_two_variable_function(int i, int j, Cap a, Cap b, Cap c, Cap d) {
        assert(i < j);
        R += a;
        add_one_variable_function(i, 0, c - a);
        add_one_variable_function(j, 0, d - c);
        gh.add_edge(i, j, b + c - a - d);
    }

    void add_three_variable_function(int i, int j, int k, Cap a, Cap b, Cap c,
                                     Cap d, Cap e, Cap f, Cap g, Cap h) {
        assert(u < max);
        Cap p = (a + d + f + g) - (b + c + e + h);
        if (p >= 0) {
            Cap p1 = f - b, p2 = g - e, p3 = d - c;
            Cap p23 = (b + c) - (a + d), p31 = (b + e) - (a + f),
                p12 = (c + e) - (a + g);
            R += a;
            add_one_variable_function(i, 0, p1);
            add_one_variable_function(j, 0, p2);
            add_one_variable_function(k, 0, p3);
            add_two_variable_function(j, k, 0, p23, 0, 0);
            add_two_variable_function(i, k, 0, 0, p31, 0);
            add_two_variable_function(i, j, 0, p12, 0, 0);
            gh.add_edge(i, u, p);
            gh.add_edge(j, u, p);
            gh.add_edge(k, u, p);
            gh.add_edge(u++, t, p);
            R -= p;
        } else {
            Cap p1 = c - g, p2 = b - d, p3 = e - f;
            Cap p32 = (f + g) - (e + h), p13 = (d + g) - (c + h),
                p21 = (d + f) - (b + h);
            R += h;
            add_one_variable_function(i, p1, 0);
            add_one_variable_function(j, p2, 0);
            add_one_variable_function(k, p3, 0);
            add_two_variable_function(j, k, 0, 0, p32, 0);
            add_two_variable_function(i, k, 0, p13, 0, 0);
            add_two_variable_function(i, j, 0, 0, p21, 0);
            gh.add_edge(s, u, -p);
            gh.add_edge(u, i, -p);
            gh.add_edge(u, j, -p);
            gh.add_edge(u, k, -p);
            u++;
            R += p;
        }
    }

    Cap min() {
        return gh.flow(s, t) + R;
    }

  private:
    atcoder::mf_graph<Cap> gh;
    int s, t;
    int max;
    int u;
    Cap R = 0;
};

}  // namespace ebi