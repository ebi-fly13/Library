
#include <cstdint>

namespace ebi {

using u64 = std::uint64_t;
const u64 mod = (1ull << 61) - 1;
const u64 MASK31 = (1ull << 31) - 1;
const u64 MASK30 = (1ull << 30) - 1;

u64 safe_mul(const u64 &a, const u64 &b) {
    u64 au = a >> 31, ad = a & MASK31;
    u64 bu = b >> 31, bd = b & MASK31;
    u64 mid = ad * bu + au * bd;
    u64 midu = mid >> 30;
    u64 midd = mid & MASK30;
    return (au * bu * 2 + midu + (midd << 31) + ad * bd);
}

u64 safe_mod(const u64 &a) {
    u64 au = a >> 61;
    u64 ad = a & mod;
    u64 res = au + ad;
    if (res >= mod) res -= mod;
    return res;
}

}  // namespace ebi