---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/queue_aggregation.hpp
    title: Sliding Window Aggregation (Queue)
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/data_structure/Queue_Operate_All_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"data_structure/queue_aggregation.hpp\"\
    \n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sliding_Window_Aggregation\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <stack>\r\n\r\nnamespace ebi {\r\n\r\
    \ntemplate <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\r\nstruct\
    \ queue_aggregation {\r\n  private:\r\n    struct Node {\r\n        Semigroup\
    \ val;\r\n        Semigroup fold;\r\n    };\r\n\r\n    void move() {\r\n     \
    \   assert(!_back.empty());\r\n        Node p = _back.top();\r\n        _back.pop();\r\
    \n        _front.push({p.val, p.val});\r\n        while (!_back.empty()) {\r\n\
    \            Semigroup x = _back.top().val;\r\n            _back.pop();\r\n  \
    \          _front.push({x, op(x, _front.top().fold)});\r\n        }\r\n    }\r\
    \n\r\n  public:\r\n    queue_aggregation() {}\r\n\r\n    int size() {\r\n    \
    \    return _front.size() + _back.size();\r\n    }\r\n\r\n    bool empty() {\r\
    \n        return size() == 0;\r\n    }\r\n\r\n    void push(Semigroup x) {\r\n\
    \        Node node = {x, x};\r\n        if (!_back.empty()) {\r\n            node.fold\
    \ = op(_back.top().fold, x);\r\n        }\r\n        _back.push(node);\r\n   \
    \ }\r\n\r\n    Semigroup front() {\r\n        assert(!empty());\r\n        if\
    \ (_front.empty()) {\r\n            move();\r\n        }\r\n        return _front.top().val;\r\
    \n    }\r\n\r\n    void pop() {\r\n        assert(!empty());\r\n        if (_front.empty())\
    \ {\r\n            move();\r\n        }\r\n        _front.pop();\r\n    }\r\n\r\
    \n    void clear() {\r\n        _front = std::stack<Node>();\r\n        _back\
    \ = std::stack<Node>();\r\n    }\r\n\r\n    Semigroup fold_all() {\r\n       \
    \ assert(!empty());\r\n        if (_front.empty()) {\r\n            return _back.top().fold;\r\
    \n        } else if (_back.empty()) {\r\n            return _front.top().fold;\r\
    \n        } else {\r\n            return op(_front.top().fold, _back.top().fold);\r\
    \n        }\r\n    }\r\n\r\n  private:\r\n    std::stack<Node> _front, _back;\r\
    \n};\r\n\r\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#line 5 \"\
    modint/modint.hpp\"\n\r\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n\
    #line 5 \"modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\nconcept\
    \ modint = requires(T a, T b) {\n    a + b;\n    a - b;\n    a *b;\n    a / b;\n\
    \    a.inv();\n    a.val();\n    a.mod();\n};\n\ntemplate <modint mint> std::istream\
    \ &operator>>(std::istream &os, mint &a) {\n    long long x;\n    os >> x;\n \
    \   a = x;\n    return os;\n}\n\ntemplate <modint mint>\nstd::ostream &operator<<(std::ostream\
    \ &os, const mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n\
    #line 7 \"modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct\
    \ static_modint {\r\n  private:\r\n    using modint = static_modint;\r\n\r\n \
    \ public:\r\n    static constexpr int mod() {\r\n        return m;\r\n    }\r\n\
    \r\n    static constexpr modint raw(int v) {\r\n        modint x;\r\n        x._v\
    \ = v;\r\n        return x;\r\n    }\r\n\r\n    constexpr static_modint() : _v(0)\
    \ {}\r\n\r\n    constexpr static_modint(long long v) {\r\n        v %= (long long)umod();\r\
    \n        if (v < 0) v += (long long)umod();\r\n        _v = (unsigned int)v;\r\
    \n    }\r\n\r\n    constexpr unsigned int val() const {\r\n        return _v;\r\
    \n    }\r\n\r\n    constexpr unsigned int value() const {\r\n        return val();\r\
    \n    }\r\n\r\n    constexpr modint &operator++() {\r\n        _v++;\r\n     \
    \   if (_v == umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\
    \n        return *this;\r\n    }\r\n\r\n    constexpr modint operator++(int) {\r\
    \n        modint res = *this;\r\n        ++*this;\r\n        return res;\r\n \
    \   }\r\n    constexpr modint operator--(int) {\r\n        modint res = *this;\r\
    \n        --*this;\r\n        return res;\r\n    }\r\n\r\n    constexpr modint\
    \ &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v\
    \ >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\n       \
    \ if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator*=(const modint &rhs) {\r\n        unsigned long long x = _v;\r\
    \n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned long long)umod());\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator/=(const modint\
    \ &rhs) {\r\n        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr\
    \ modint operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\
    \n    constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n\
    \        modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n\
    \ & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\
    \n        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n     \
    \   assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend\
    \ modint operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ += rhs;\r\n    }\r\n    friend modint operator-(const modint &lhs, const modint\
    \ &rhs) {\r\n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const modint &lhs, const\
    \ modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend\
    \ bool operator==(const modint &lhs, const modint &rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\
    \n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\
    \n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 7 \"test/data_structure/Queue_Operate_All_Composite.test.cpp\"\
    \n\r\nusing mint = ebi::modint998244353;\r\n\r\nstruct F {\r\n    mint a, b;\r\
    \n    F(mint a, mint b) : a(a), b(b) {}\r\n};\r\n\r\nF op(F f1, F f2) {\r\n  \
    \  return F(f2.a * f1.a, f2.a * f1.b + f2.b);\r\n}\r\n\r\nint main() {\r\n   \
    \ ebi::queue_aggregation<F, op> swag;\r\n    int q;\r\n    std::cin >> q;\r\n\
    \    while (q--) {\r\n        int t;\r\n        std::cin >> t;\r\n        if (t\
    \ == 0) {\r\n            int a, b;\r\n            std::cin >> a >> b;\r\n    \
    \        swag.push(F(a, b));\r\n        } else if (t == 1) {\r\n            swag.pop();\r\
    \n        } else {\r\n            int x;\r\n            std::cin >> x;\r\n   \
    \         if (swag.empty()) {\r\n                std::cout << x << std::endl;\r\
    \n                continue;\r\n            }\r\n            auto f = swag.fold_all();\r\
    \n            std::cout << (f.a * (mint)x + f.b).val() << std::endl;\r\n     \
    \   }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../../data_structure/queue_aggregation.hpp\"\
    \r\n#include \"../../modint/modint.hpp\"\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint b) : a(a), b(b) {}\r\n\
    };\r\n\r\nF op(F f1, F f2) {\r\n    return F(f2.a * f1.a, f2.a * f1.b + f2.b);\r\
    \n}\r\n\r\nint main() {\r\n    ebi::queue_aggregation<F, op> swag;\r\n    int\
    \ q;\r\n    std::cin >> q;\r\n    while (q--) {\r\n        int t;\r\n        std::cin\
    \ >> t;\r\n        if (t == 0) {\r\n            int a, b;\r\n            std::cin\
    \ >> a >> b;\r\n            swag.push(F(a, b));\r\n        } else if (t == 1)\
    \ {\r\n            swag.pop();\r\n        } else {\r\n            int x;\r\n \
    \           std::cin >> x;\r\n            if (swag.empty()) {\r\n            \
    \    std::cout << x << std::endl;\r\n                continue;\r\n           \
    \ }\r\n            auto f = swag.fold_all();\r\n            std::cout << (f.a\
    \ * (mint)x + f.b).val() << std::endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/queue_aggregation.hpp
  - modint/modint.hpp
  - modint/base.hpp
  isVerificationFile: true
  path: test/data_structure/Queue_Operate_All_Composite.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/Queue_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Queue_Operate_All_Composite.test.cpp
- /verify/test/data_structure/Queue_Operate_All_Composite.test.cpp.html
title: test/data_structure/Queue_Operate_All_Composite.test.cpp
---
