---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data_structure/queue_aggregation.hpp
    title: Sliding Window Aggregation (Queue)
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/data_structure/Queue_Operate_All_Composite.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"data_structure/queue_aggregation.hpp\"\
    \n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sliding_Window_Aggregation\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <stack>\r\n\r\nnamespace ebi {\r\n\r\
    \ntemplate <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\r\nstruct\
    \ queue_aggregation {\r\n  private:\r\n    struct Node {\r\n        Semigroup\
    \ val;\r\n        Semigroup fold;\r\n    };\r\n\r\n    void move() {\r\n     \
    \   assert(!back.empty());\r\n        Node p = back.top();\r\n        back.pop();\r\
    \n        front.push({p.val, p.val});\r\n        while (!back.empty()) {\r\n \
    \           Semigroup x = back.top().val;\r\n            back.pop();\r\n     \
    \       front.push({x, op(x, front.top().fold)});\r\n        }\r\n    }\r\n\r\n\
    \  public:\r\n    queue_aggregation() {}\r\n\r\n    int size() {\r\n        return\
    \ front.size() + back.size();\r\n    }\r\n\r\n    bool empty() {\r\n        return\
    \ size() == 0;\r\n    }\r\n\r\n    void push(Semigroup x) {\r\n        Node node\
    \ = {x, x};\r\n        if (!back.empty()) {\r\n            node.fold = op(back.top().fold,\
    \ x);\r\n        }\r\n        back.push(node);\r\n    }\r\n\r\n    void pop()\
    \ {\r\n        assert(!empty());\r\n        if (front.empty()) {\r\n         \
    \   move();\r\n        }\r\n        front.pop();\r\n    }\r\n\r\n    Semigroup\
    \ fold_all() {\r\n        assert(!empty());\r\n        if (front.empty()) {\r\n\
    \            return back.top().fold;\r\n        } else if (back.empty()) {\r\n\
    \            return front.top().fold;\r\n        } else {\r\n            return\
    \ op(front.top().fold, back.top().fold);\r\n        }\r\n    }\r\n\r\n  private:\r\
    \n    std::stack<Node> front, back;\r\n};\r\n\r\n}  // namespace ebi\n#line 2\
    \ \"utility/modint.hpp\"\n\r\n#line 5 \"utility/modint.hpp\"\n#include <type_traits>\r\
    \n\r\n#line 2 \"utility/modint_base.hpp\"\n\n#line 4 \"utility/modint_base.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\nstruct modint_base {};\n\ntemplate\
    \ <class T> using is_modint = std::is_base_of<modint_base, T>;\ntemplate <class\
    \ T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\n}  // namespace\
    \ internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\nnamespace internal {\r\n\r\nstruct static_modint_base : modint_base\
    \ {};\r\n\r\ntemplate <class T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\ntemplate <int m> struct static_modint :\
    \ internal::static_modint_base {\r\n  private:\r\n    using modint = static_modint;\r\
    \n\r\n  public:\r\n    static constexpr int mod() {\r\n        return m;\r\n \
    \   }\r\n\r\n    static constexpr modint raw(int v) {\r\n        modint x;\r\n\
    \        x._v = v;\r\n        return x;\r\n    }\r\n\r\n    constexpr static_modint()\
    \ : _v(0) {}\r\n\r\n    constexpr static_modint(long long v) {\r\n        v %=\
    \ (long long)umod();\r\n        if (v < 0) v += (long long)umod();\r\n       \
    \ _v = (unsigned int)v;\r\n    }\r\n\r\n    constexpr unsigned int val() const\
    \ {\r\n        return _v;\r\n    }\r\n\r\n    constexpr unsigned int value() const\
    \ {\r\n        return val();\r\n    }\r\n\r\n    constexpr modint &operator++()\
    \ {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\
    \n        _v--;\r\n        return *this;\r\n    }\r\n    constexpr modint &operator+=(const\
    \ modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator-=(const modint\
    \ &rhs) {\r\n        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ &rhs) {\r\n        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n  \
    \      _v = (unsigned int)(x % (unsigned long long)umod());\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator/=(const modint &rhs) {\r\n\
    \        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr modint\
    \ operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr modint\
    \ operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\n   \
    \ constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n   \
    \     modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n &\
    \ 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\n\
    \        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n      \
    \  assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint\
    \ operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
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
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 7 \"test/data_structure/Queue_Operate_All_Composite.cpp\"\
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
    \r\n#include \"../../utility/modint.hpp\"\r\n\r\nusing mint = ebi::modint998244353;\r\
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
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: false
  path: test/data_structure/Queue_Operate_All_Composite.cpp
  requiredBy: []
  timestamp: '2023-07-01 16:57:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/data_structure/Queue_Operate_All_Composite.cpp
layout: document
redirect_from:
- /library/test/data_structure/Queue_Operate_All_Composite.cpp
- /library/test/data_structure/Queue_Operate_All_Composite.cpp.html
title: test/data_structure/Queue_Operate_All_Composite.cpp
---