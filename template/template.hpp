#include <algorithm>
#include <bit>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numbers>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define rep(i, a, n) for (int i : std::views::iota(int(a), int(n)))
#define rrep(i, a, n) \
    for (int i : std::views::iota(int(a), int(n)) | std::views::reverse)
#define Rep(i, a, n) for (i64 i : std::views::iota(i64(a), i64(n)))
#define RRep(i, a, n) \
    for (i64 i : std::views::iota(i64(a), i64(n)) | std::views::reverse)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#include "debug_template.hpp"
#include "int_alias.hpp"
#include "io.hpp"
#include "utility.hpp"