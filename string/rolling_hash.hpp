#pragma once

#include <cassert>
#include <vector>

#include "../monoid/rolling_hash_monoid.hpp"

/*
    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
*/

namespace ebi {

struct rolling_hash {
  private:
  public:
    rolling_hash(const std::string &s) {
        prefix_hash.emplace_back(rolling_hash_monoid::e());
        for (auto c : s) {
            prefix_hash.emplace_back(prefix_hash.back() + c);
        }
    }

    template <class T> rolling_hash(const std::vector<T> &a) {
        prefix_hash.emplace_back(rolling_hash_monoid::e());
        for (auto x : a) {
            prefix_hash.emplace_back(prefix_hash.back() + x);
        }
    }

    rolling_hash_monoid get_prefix_hash(int r) const {
        return prefix_hash[r];
    }

    rolling_hash_monoid get_hash(int l, int r) const {
        assert(l <= r && r <= (int)prefix_hash.size());
        modint61 base_pow = prefix_hash[r - l].first;
        return {base_pow,
                prefix_hash[r].second - prefix_hash[l].second * base_pow};
    }

    rolling_hash &operator+=(const rolling_hash &rhs) noexcept {
        rolling_hash_monoid lhs = prefix_hash.back();
        for (int i = 1; i <= (int)rhs.prefix_hash.size(); i++) {
            prefix_hash.emplace_back(lhs + rhs.prefix_hash[i]);
        }
        return *this;
    }

    rolling_hash operator+(const rolling_hash &rhs) noexcept {
        return rolling_hash(*this) += rhs;
    }

  private:
    std::vector<rolling_hash_monoid> prefix_hash;
};

}  // namespace ebi