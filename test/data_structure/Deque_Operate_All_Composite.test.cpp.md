---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/deque_aggregation.hpp
    title: Sliding Window Aggregation (Deque)
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':question:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
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
    \    void move_front() {\n        assert(front.empty());\n        int sz = back.size();\n\
    \        std::stack<Semigroup> buff;\n        for (int i = 0; i < sz / 2; i++)\
    \ {\n            buff.push(back.top().val);\n            back.pop();\n       \
    \ }\n        while (!back.empty()) {\n            Semigroup x = back.top().val;\n\
    \            back.pop();\n            push_front(x);\n        }\n        while\
    \ (!buff.empty()) {\n            Semigroup x = buff.top();\n            buff.pop();\n\
    \            push_back(x);\n        }\n    }\n\n    void move_back() {\n     \
    \   assert(back.empty());\n        int sz = front.size();\n        std::stack<Semigroup>\
    \ buff;\n        for (int i = 0; i < sz / 2; i++) {\n            buff.push(front.top().val);\n\
    \            front.pop();\n        }\n        while (!front.empty()) {\n     \
    \       Semigroup x = front.top().val;\n            front.pop();\n           \
    \ push_back(x);\n        }\n        while (!buff.empty()) {\n            Semigroup\
    \ x = buff.top();\n            buff.pop();\n            push_front(x);\n     \
    \   }\n    }\n\n  public:\n    deque_aggregation() = default;\n\n    int size()\
    \ const {\n        return front.size() + back.size();\n    }\n\n    bool empty()\
    \ const {\n        return size() == 0;\n    }\n\n    void push_front(Semigroup\
    \ x) {\n        Node node = {x, x};\n        if (!front.empty()) {\n         \
    \   node.fold = op(x, front.top().fold);\n        }\n        front.push(node);\n\
    \    }\n\n    void push_back(Semigroup x) {\n        Node node = {x, x};\n   \
    \     if (!back.empty()) {\n            node.fold = op(back.top().fold, x);\n\
    \        }\n        back.push(node);\n    }\n\n    void pop_back() {\n       \
    \ assert(!empty());\n        if (back.empty()) move_back();\n        back.pop();\n\
    \    }\n\n    void pop_front() {\n        assert(!empty());\n        if (front.empty())\
    \ move_front();\n        front.pop();\n    }\n\n    Semigroup fold_all() {\n \
    \       assert(!empty());\n        if (front.empty()) {\n            return back.top().fold;\n\
    \        } else if (back.empty()) {\n            return front.top().fold;\n  \
    \      } else {\n            return op(front.top().fold, back.top().fold);\n \
    \       }\n    }\n\n  private:\n    std::stack<Node> front, back;\n};\n\n}  //\
    \ namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#line 5 \"utility/modint.hpp\"\
    \n#include <type_traits>\r\n\r\n#line 2 \"utility/modint_base.hpp\"\n\n#line 4\
    \ \"utility/modint_base.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\nstruct\
    \ modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \nstruct static_modint_base : modint_base {};\n\ntemplate <class T>\nusing is_static_modint\
    \ = std::is_base_of<internal::static_modint_base, T>;\n\ntemplate <class T>\n\
    using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\n}\
    \  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint : internal::static_modint_base\
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
    \n        return *this;\r\n    }\r\n    constexpr modint &operator+=(const modint\
    \ &rhs) {\r\n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\
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
    \n#include \"../../utility/modint.hpp\"\n\nusing mint = ebi::modint998244353;\n\
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
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: true
  path: test/data_structure/Deque_Operate_All_Composite.test.cpp
  requiredBy: []
  timestamp: '2023-07-17 11:19:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Deque_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Deque_Operate_All_Composite.test.cpp
- /verify/test/data_structure/Deque_Operate_All_Composite.test.cpp.html
title: test/data_structure/Deque_Operate_All_Composite.test.cpp
---
