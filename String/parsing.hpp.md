---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://gist.github.com/draftcode/1357281
  bundledCode: "#line 2 \"String/parsing.hpp\"\n\n#include <cassert>\n#include <cctype>\n\
    #include <iostream>\n#include <string>\n\n/*\n    reference: https://gist.github.com/draftcode/1357281\n\
    */\n\nnamespace ebi {\n\ntypedef std::string::const_iterator State;\nclass ParseError\
    \ {};\n\nbool expect(State &begin, char expected) {\n    if (*begin == expected)\
    \ {\n        return true;\n    } else {\n        return false;\n    }\n}\n\n//\
    \ begin\u304Cexpected\u3092\u6307\u3057\u3066\u3044\u305F\u3089begin\u3092\u4E00\
    \u3064\u9032\u3081\u308B\u3002\nvoid consume(State &begin, char expected) {\n\
    \    if (*begin == expected) {\n        begin++;\n    } else {\n        assert(0);\n\
    \    }\n}\n\nbool isdigit(char c) {\n    return '0' <= c && c <= '9';\n}\n\nbool\
    \ isAlpha(char c) {\n    return 'A' <= c && c <= 'Z';\n}\n\nbool isalpha(char\
    \ c) {\n    return 'a' <= c && c <= 'z';\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cctype>\n#include <iostream>\n\
    #include <string>\n\n/*\n    reference: https://gist.github.com/draftcode/1357281\n\
    */\n\nnamespace ebi {\n\ntypedef std::string::const_iterator State;\nclass ParseError\
    \ {};\n\nbool expect(State &begin, char expected) {\n    if (*begin == expected)\
    \ {\n        return true;\n    } else {\n        return false;\n    }\n}\n\n//\
    \ begin\u304Cexpected\u3092\u6307\u3057\u3066\u3044\u305F\u3089begin\u3092\u4E00\
    \u3064\u9032\u3081\u308B\u3002\nvoid consume(State &begin, char expected) {\n\
    \    if (*begin == expected) {\n        begin++;\n    } else {\n        assert(0);\n\
    \    }\n}\n\nbool isdigit(char c) {\n    return '0' <= c && c <= '9';\n}\n\nbool\
    \ isAlpha(char c) {\n    return 'A' <= c && c <= 'Z';\n}\n\nbool isalpha(char\
    \ c) {\n    return 'a' <= c && c <= 'z';\n}\n\n}  // namespace ebi\n"
  dependsOn: []
  isVerificationFile: false
  path: String/parsing.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/parsing.hpp
layout: document
redirect_from:
- /library/String/parsing.hpp
- /library/String/parsing.hpp.html
title: String/parsing.hpp
---