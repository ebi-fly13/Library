#pragma once

#include <iostream>

namespace ebi {

#ifdef LOCAL
#define debug(...)                                                      \
    std::cerr << "LINE: " << __LINE__ << "  [" << #__VA_ARGS__ << "]:", \
        debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() {
    std::cerr << std::endl;
}

template <typename Head, typename... Tail> void debug_out(Head h, Tail... t) {
    std::cerr << " " << h;
    if (sizeof...(t) > 0) std::cerr << " :";
    debug_out(t...);
}

}