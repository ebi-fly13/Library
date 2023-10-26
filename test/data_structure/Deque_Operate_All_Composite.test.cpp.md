---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/deque_aggregation.hpp
    title: Sliding Window Aggregation (Deque)
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"test/data_structure/Deque_Operate_All_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include <iostream>\n\n#line 2 \"data_structure/deque_aggregation.hpp\"\n\n\
    #include <cassert>\n#include <stack>\n\nnamespace ebi {\n\ntemplate <class Semigroup,\
    \ Semigroup (*op)(Semigroup, Semigroup)>\nstruct deque_aggregation {\n  private:\n\
    \    struct Node {\n        Semigroup val;\n        Semigroup fold;\n    };\n\n\
    \    void move_front() {\n        assert(_front.empty());\n        int sz = _back.size();\n\
    \        std::stack<Semigroup> buff;\n        for (int i = 0; i < sz / 2; i++)\
    \ {\n            buff.push(_back.top().val);\n            _back.pop();\n     \
    \   }\n        while (!_back.empty()) {\n            Semigroup x = _back.top().val;\n\
    \            _back.pop();\n            push_front(x);\n        }\n        while\
    \ (!buff.empty()) {\n            Semigroup x = buff.top();\n            buff.pop();\n\
    \            push_back(x);\n        }\n    }\n\n    void move_back() {\n     \
    \   assert(_back.empty());\n        int sz = _front.size();\n        std::stack<Semigroup>\
    \ buff;\n        for (int i = 0; i < sz / 2; i++) {\n            buff.push(_front.top().val);\n\
    \            _front.pop();\n        }\n        while (!_front.empty()) {\n   \
    \         Semigroup x = _front.top().val;\n            _front.pop();\n       \
    \     push_back(x);\n        }\n        while (!buff.empty()) {\n            Semigroup\
    \ x = buff.top();\n            buff.pop();\n            push_front(x);\n     \
    \   }\n    }\n\n  public:\n    deque_aggregation() = default;\n\n    int size()\
    \ const {\n        return _front.size() + _back.size();\n    }\n\n    bool empty()\
    \ const {\n        return size() == 0;\n    }\n\n    Semigroup front() {\n   \
    \     assert(!empty());\n        if (_front.empty()) move_front();\n        return\
    \ _front.top().val;\n    }\n\n    Semigroup back() {\n        assert(!empty());\n\
    \        if (_back.empty()) move_back();\n        return _back.top().val;\n  \
    \  }\n\n    void push_front(Semigroup x) {\n        Node node = {x, x};\n    \
    \    if (!_front.empty()) {\n            node.fold = op(x, _front.top().fold);\n\
    \        }\n        _front.push(node);\n    }\n\n    void push_back(Semigroup\
    \ x) {\n        Node node = {x, x};\n        if (!_back.empty()) {\n         \
    \   node.fold = op(_back.top().fold, x);\n        }\n        _back.push(node);\n\
    \    }\n\n    void pop_back() {\n        assert(!empty());\n        if (_back.empty())\
    \ move_back();\n        _back.pop();\n    }\n\n    void pop_front() {\n      \
    \  assert(!empty());\n        if (_front.empty()) move_front();\n        _front.pop();\n\
    \    }\n\n    Semigroup fold_all() {\n        assert(!empty());\n        if (_front.empty())\
    \ {\n            return _back.top().fold;\n        } else if (_back.empty()) {\n\
    \            return _front.top().fold;\n        } else {\n            return op(_front.top().fold,\
    \ _back.top().fold);\n        }\n    }\n\n  private:\n    std::stack<Node> _front,\
    \ _back;\n};\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#line\
    \ 5 \"modint/modint.hpp\"\n\r\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n\
    #line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n \
    \   a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint\
    \ {\r\n  private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n  \
    \  static constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static\
    \ constexpr modint raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n\
    \        return x;\r\n    }\r\n\r\n    constexpr static_modint() : _v(0) {}\r\n\
    \r\n    constexpr static_modint(long long v) {\r\n        v %= (long long)umod();\r\
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
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 7 \"test/data_structure/Deque_Operate_All_Composite.test.cpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nstruct F {\n    mint a;\n    mint b;\n\
    };\n\nF op(F f, F g) {\n    return {g.a * f.a, g.a * f.b + g.b};\n}\n\nint main()\
    \ {\n    int q;\n    std::cin >> q;\n    ebi::deque_aggregation<F, op> swag;\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            mint a, b;\n            std::cin >> a >> b;\n            swag.push_front({a,\
    \ b});\n        } else if (t == 1) {\n            mint a, b;\n            std::cin\
    \ >> a >> b;\n            swag.push_back({a, b});\n        } else if (t == 2)\
    \ {\n            swag.pop_front();\n        } else if (t == 3) {\n           \
    \ swag.pop_back();\n        } else {\n            mint x;\n            std::cin\
    \ >> x;\n            if (swag.empty()) {\n                std::cout << x << '\\\
    n';\n                continue;\n            }\n            auto f = swag.fold_all();\n\
    \            mint ans = f.a * x + f.b;\n            std::cout << ans << '\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include <iostream>\n\n#include \"../../data_structure/deque_aggregation.hpp\"\
    \n#include \"../../modint/modint.hpp\"\n\nusing mint = ebi::modint998244353;\n\
    \nstruct F {\n    mint a;\n    mint b;\n};\n\nF op(F f, F g) {\n    return {g.a\
    \ * f.a, g.a * f.b + g.b};\n}\n\nint main() {\n    int q;\n    std::cin >> q;\n\
    \    ebi::deque_aggregation<F, op> swag;\n    while (q--) {\n        int t;\n\
    \        std::cin >> t;\n        if (t == 0) {\n            mint a, b;\n     \
    \       std::cin >> a >> b;\n            swag.push_front({a, b});\n        } else\
    \ if (t == 1) {\n            mint a, b;\n            std::cin >> a >> b;\n   \
    \         swag.push_back({a, b});\n        } else if (t == 2) {\n            swag.pop_front();\n\
    \        } else if (t == 3) {\n            swag.pop_back();\n        } else {\n\
    \            mint x;\n            std::cin >> x;\n            if (swag.empty())\
    \ {\n                std::cout << x << '\\n';\n                continue;\n   \
    \         }\n            auto f = swag.fold_all();\n            mint ans = f.a\
    \ * x + f.b;\n            std::cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/deque_aggregation.hpp
  - modint/modint.hpp
  - modint/base.hpp
  isVerificationFile: true
  path: test/data_structure/Deque_Operate_All_Composite.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Deque_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Deque_Operate_All_Composite.test.cpp
- /verify/test/data_structure/Deque_Operate_All_Composite.test.cpp.html
title: test/data_structure/Deque_Operate_All_Composite.test.cpp
---
