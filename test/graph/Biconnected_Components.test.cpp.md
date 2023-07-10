---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.hpp
    title: graph/biconnected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: Low Link
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/block_cut_tree.hpp
    title: tree/block_cut_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"test/graph/Biconnected_Components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/biconnected_components\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct Edge {\r\n    int to;\r\
    \n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to), cost(_cost) {}\r\n\
    };\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 2 \"tree/block_cut_tree.hpp\"\n\n#include <cassert>\n\n#line 2 \"\
    graph/biconnected_components.hpp\"\n\n#line 2 \"graph/low_link.hpp\"\n\n#include\
    \ <algorithm>\n#include <utility>\n#line 6 \"graph/low_link.hpp\"\n\nnamespace\
    \ ebi {\n\nstruct low_link {\n  private:\n    void dfs(int v, int par = -1) {\n\
    \        static int k = 0;\n        low[v] = ord[v] = k++;\n        int cnt =\
    \ 0;\n        bool is_arti = false, is_second = false;\n        for (auto nv :\
    \ g[v]) {\n            if (ord[nv] == -1) {\n                cnt++;\n        \
    \        dfs(nv, v);\n                low[v] = std::min(low[v], low[nv]);\n  \
    \              is_arti |= (par != -1) && (low[nv] >= ord[v]);\n              \
    \  if (ord[v] < low[nv]) {\n                    _bridge.emplace_back(std::minmax(v,\
    \ nv));\n                }\n            } else if (nv != par || is_second) {\n\
    \                low[v] = std::min(low[v], ord[nv]);\n            } else {\n \
    \               is_second = true;\n            }\n        }\n        is_arti |=\
    \ par == -1 && cnt > 1;\n        if (is_arti) _articulation.emplace_back(v);\n\
    \    }\n\n  public:\n    low_link(const std::vector<std::vector<int>> &g)\n  \
    \      : n(g.size()), g(g), ord(n, -1), low(n) {\n        for (int i = 0; i <\
    \ n; i++) {\n            if (ord[i] == -1) dfs(i);\n        }\n    }\n\n    std::vector<int>\
    \ articulation() const {\n        return _articulation;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> bridge() const {\n        return _bridge;\n    }\n\n  protected:\n   \
    \ int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> ord, low,\
    \ _articulation;\n    std::vector<std::pair<int, int>> _bridge;\n};\n\n}  // namespace\
    \ ebi\n#line 4 \"graph/biconnected_components.hpp\"\n\nnamespace ebi {\n\nstruct\
    \ biconnected_components : low_link {\n  private:\n    void dfs(int v, int par\
    \ = -1) {\n        used[v] = true;\n        for (auto nv : this->g[v]) {\n   \
    \         if (nv == par) continue;\n            if (!used[nv] || this->ord[nv]\
    \ < this->ord[v]) {\n                tmp.emplace_back(std::minmax(v, nv));\n \
    \           }\n            if (!used[nv]) {\n                dfs(nv, v);\n   \
    \             if (this->low[nv] >= this->ord[v]) {\n                    bc.emplace_back();\n\
    \                    while (true) {\n                        auto e = tmp.back();\n\
    \                        bc.back().emplace_back(e);\n                        tmp.pop_back();\n\
    \                        if (e.first == std::min(v, nv) &&\n                 \
    \           e.second == std::max(v, nv)) {\n                            break;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n        }\n    }\n\n  public:\n    biconnected_components(const std::vector<std::vector<int>>\
    \ &g)\n        : low_link(g), used(this->n, false) {\n        for (int i = 0;\
    \ i < this->n; i++) {\n            if (!used[i]) dfs(i);\n        }\n    }\n\n\
    \  protected:\n    std::vector<bool> used;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> bc;\n    std::vector<std::pair<int, int>> tmp;\n};\n\n}  // namespace\
    \ ebi\n#line 6 \"tree/block_cut_tree.hpp\"\n\nnamespace ebi {\n\nstruct block_cut_tree\
    \ : biconnected_components {\n  public:\n    block_cut_tree(const std::vector<std::vector<int>>\
    \ &g)\n        : biconnected_components(g), rev(this->n, -1) {\n        int cnt\
    \ = 0;\n        for (auto v : this->_articulation) {\n            rev[v] = cnt++;\n\
    \        }\n        int sz = cnt + this->bc.size();\n        tree.resize(sz);\n\
    \        std::vector<int> last(this->n, -1);\n        for (int i = cnt; i < sz;\
    \ i++) {\n            for (auto e : this->bc[i - cnt]) {\n                for\
    \ (auto v : {e.first, e.second}) {\n                    if (rev[v] != -1 && rev[v]\
    \ < cnt) {\n                        if (std::exchange(last[v], i) != i) {\n  \
    \                          tree[i].emplace_back(rev[v]);\n                   \
    \         tree[rev[v]].emplace_back(i);\n                        }\n         \
    \           } else {\n                        rev[v] = i;\n                  \
    \  }\n                }\n            }\n        }\n        groups.resize(sz);\n\
    \        for (int i = 0; i < this->n; i++) {\n            if (rev[i] < 0) {\n\
    \                rev[i] = sz++;\n                groups.emplace_back();\n    \
    \            tree.emplace_back();\n            }\n            groups[rev[i]].emplace_back(i);\n\
    \        }\n    }\n\n    std::vector<std::vector<int>> bcc() {\n        int cnt\
    \ = this->_articulation.size();\n        int sz = groups.size() - cnt;\n     \
    \   std::vector _bcc(sz, std::vector<int>());\n        for (int i = 0; i < sz;\
    \ i++) {\n            _bcc[i] = groups[cnt + i];\n            for (auto nv : tree[cnt\
    \ + i]) {\n                assert(0 <= nv && nv < cnt);\n                assert(groups[nv].size()\
    \ == 1);\n                _bcc[i].emplace_back(groups[nv][0]);\n            }\n\
    \        }\n        return _bcc;\n    }\n\n  private:\n    std::vector<int> rev;\n\
    \    std::vector<std::vector<int>> tree;\n    std::vector<std::vector<int>> groups;\n\
    };\n\n}  // namespace ebi\n#line 8 \"test/graph/Biconnected_Components.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    ebi::graph g(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        g.add_edge(a, b);\n    }\n    ebi::block_cut_tree bct(g);\n    auto\
    \ bc = bct.bcc();\n    int k = bc.size();\n    std::cout << k << '\\n';\n    for\
    \ (auto vs : bc) {\n        std::cout << vs.size();\n        for (auto v : vs)\
    \ {\n            std::cout << \" \" << v;\n        }\n        std::cout << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../graph/template.hpp\"\
    \n#include \"../../tree/block_cut_tree.hpp\"\n\nint main() {\n    int n, m;\n\
    \    std::cin >> n >> m;\n    ebi::graph g(n);\n    for (int i = 0; i < m; i++)\
    \ {\n        int a, b;\n        std::cin >> a >> b;\n        g.add_edge(a, b);\n\
    \    }\n    ebi::block_cut_tree bct(g);\n    auto bc = bct.bcc();\n    int k =\
    \ bc.size();\n    std::cout << k << '\\n';\n    for (auto vs : bc) {\n       \
    \ std::cout << vs.size();\n        for (auto v : vs) {\n            std::cout\
    \ << \" \" << v;\n        }\n        std::cout << '\\n';\n    }\n}"
  dependsOn:
  - graph/template.hpp
  - tree/block_cut_tree.hpp
  - graph/biconnected_components.hpp
  - graph/low_link.hpp
  isVerificationFile: true
  path: test/graph/Biconnected_Components.test.cpp
  requiredBy: []
  timestamp: '2023-07-10 11:25:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Biconnected_Components.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Biconnected_Components.test.cpp
- /verify/test/graph/Biconnected_Components.test.cpp.html
title: test/graph/Biconnected_Components.test.cpp
---
