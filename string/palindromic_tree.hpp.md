---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/palindromic_tree.hpp\"\n#include <cstdint>\n#include\
    \ <map>\n#include <string>\n#include <vector>\n\nnamespace ebi {\n\nstruct palindromic_tree\
    \ {\n  private:\n    using i64 = std::int64_t;\n    struct Node {\n        std::map<char,\
    \ int> edges;\n        int len;  // \u56DE\u6587\u306E\u9577\u3055\n        i64\
    \ num = 0;\n        int suffix_link = 0;\n    };\n\n  public:\n    palindromic_tree(const\
    \ std::string &str) {\n        tree.resize(2);\n        tree[0].len = -1;\n  \
    \      tree[1].len = 0;\n        for (auto c : str) {\n            add_char(c);\n\
    \        }\n        for (int i = (int)tree.size() - 1; i >= 2; i--) {\n      \
    \      sum += tree[i].num;\n            tree[tree[i].suffix_link].num += tree[i].num;\n\
    \        }\n    }\n\n    // \u672B\u5C3E\u306B x \u3092\u8FFD\u52A0\u3057\u3001\
    \u672B\u5C3E\u3092\u4F7F\u3063\u305F\u6700\u5927\u306E\u9577\u3055\u3092\u8FD4\
    \u3059\u3002\n    int add_char(char x) {\n        s.push_back(x);\n        int\
    \ pos = s.size() - 1;\n        int now = last_idx;\n        while (true) {\n \
    \           int len = tree[now].len;\n            if (0 <= pos - len - 1 && s[pos\
    \ - len - 1] == x) {\n                break;\n            }\n            now =\
    \ tree[now].suffix_link;\n        }\n        if (tree[now].edges.find(x) != tree[now].edges.end())\
    \ {\n            last_idx = tree[now].edges[x];\n            tree[last_idx].num++;\n\
    \            return tree[last_idx].len;\n        }\n        last_idx = tree.size();\n\
    \        tree[now].edges[x] = last_idx;\n        Node node;\n        node.len\
    \ = tree[now].len + 2;\n        node.num = 1;\n        if (node.len == 1) {\n\
    \            node.suffix_link = 1;\n            tree.emplace_back(node);\n   \
    \         return node.len;\n        }\n        while (true) {\n            now\
    \ = tree[now].suffix_link;\n            int len = tree[now].len;\n           \
    \ if (0 <= pos - 1 - len && s[pos - 1 - len] == x) break;\n        }\n       \
    \ node.suffix_link = tree[now].edges[x];\n        tree.emplace_back(node);\n \
    \       return node.len;\n    }\n\n    int count_types() {\n        return (int)tree.size()\
    \ - 2;\n    }\n\n    i64 count_num() {\n        return sum;\n    }\n\n  private:\n\
    \    std::string s;\n    std::vector<Node> tree;\n    int last_idx = 1;\n    i64\
    \ sum = 0;\n};\n\n}  // namespace ebi\n"
  code: "#include <cstdint>\n#include <map>\n#include <string>\n#include <vector>\n\
    \nnamespace ebi {\n\nstruct palindromic_tree {\n  private:\n    using i64 = std::int64_t;\n\
    \    struct Node {\n        std::map<char, int> edges;\n        int len;  // \u56DE\
    \u6587\u306E\u9577\u3055\n        i64 num = 0;\n        int suffix_link = 0;\n\
    \    };\n\n  public:\n    palindromic_tree(const std::string &str) {\n       \
    \ tree.resize(2);\n        tree[0].len = -1;\n        tree[1].len = 0;\n     \
    \   for (auto c : str) {\n            add_char(c);\n        }\n        for (int\
    \ i = (int)tree.size() - 1; i >= 2; i--) {\n            sum += tree[i].num;\n\
    \            tree[tree[i].suffix_link].num += tree[i].num;\n        }\n    }\n\
    \n    // \u672B\u5C3E\u306B x \u3092\u8FFD\u52A0\u3057\u3001\u672B\u5C3E\u3092\
    \u4F7F\u3063\u305F\u6700\u5927\u306E\u9577\u3055\u3092\u8FD4\u3059\u3002\n   \
    \ int add_char(char x) {\n        s.push_back(x);\n        int pos = s.size()\
    \ - 1;\n        int now = last_idx;\n        while (true) {\n            int len\
    \ = tree[now].len;\n            if (0 <= pos - len - 1 && s[pos - len - 1] ==\
    \ x) {\n                break;\n            }\n            now = tree[now].suffix_link;\n\
    \        }\n        if (tree[now].edges.find(x) != tree[now].edges.end()) {\n\
    \            last_idx = tree[now].edges[x];\n            tree[last_idx].num++;\n\
    \            return tree[last_idx].len;\n        }\n        last_idx = tree.size();\n\
    \        tree[now].edges[x] = last_idx;\n        Node node;\n        node.len\
    \ = tree[now].len + 2;\n        node.num = 1;\n        if (node.len == 1) {\n\
    \            node.suffix_link = 1;\n            tree.emplace_back(node);\n   \
    \         return node.len;\n        }\n        while (true) {\n            now\
    \ = tree[now].suffix_link;\n            int len = tree[now].len;\n           \
    \ if (0 <= pos - 1 - len && s[pos - 1 - len] == x) break;\n        }\n       \
    \ node.suffix_link = tree[now].edges[x];\n        tree.emplace_back(node);\n \
    \       return node.len;\n    }\n\n    int count_types() {\n        return (int)tree.size()\
    \ - 2;\n    }\n\n    i64 count_num() {\n        return sum;\n    }\n\n  private:\n\
    \    std::string s;\n    std::vector<Node> tree;\n    int last_idx = 1;\n    i64\
    \ sum = 0;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: string/palindromic_tree.hpp
  requiredBy: []
  timestamp: '2023-06-06 01:19:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/palindromic_tree.hpp
layout: document
redirect_from:
- /library/string/palindromic_tree.hpp
- /library/string/palindromic_tree.hpp.html
title: string/palindromic_tree.hpp
---
