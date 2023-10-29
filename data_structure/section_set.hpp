#pragma once

#include <cassert>
#include <limits>
#include <set>

namespace ebi {

template <class T> struct section_set {
  private:
    std::set<std::pair<T, T>> set;

  public:
    section_set() {
        set.insert(
            {std::numeric_limits<T>::min(), std::numeric_limits<T>::min()});
        set.insert(
            {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()});
    }

    std::set<std::pair<T, T>> sections() const {
        return set;
    }

    // [l, r)を追加
    void insert(T l, T r) {
        auto itr =
            std::prev(set.lower_bound({l, std::numeric_limits<T>::min()}));
        if (l <= itr->second) {
            assert(itr->first <= l);
            l = itr->first;
            r = std::max(r, itr->second);
            set.erase(itr);
        }
        itr = set.lower_bound({l, std::numeric_limits<T>::min()});
        while (itr->first <= r) {
            assert(l <= itr->first);
            r = std::max(r, itr->second);
            itr = set.erase(itr);
        }
        set.insert({l, r});
        return;
    }

    // 集合内の[l, r)に含まれている要素を削除
    void erase(T l, T r) {
        auto itr =
            std::prev(set.lower_bound({l, std::numeric_limits<T>::min()}));
        if (l < itr->second) {
            assert(itr->first < l);
            set.insert({itr->first, l});
            if (r < itr->second) {
                set.insert({r, itr->second});
            }
            set.erase(itr);
        }
        itr = set.lower_bound({l, std::numeric_limits<T>::min()});
        while (itr->first < r) {
            if (itr->second <= r) {
                itr = set.erase(itr);
            } else {
                set.insert({r, itr->second});
                set.erase(itr);
                break;
            }
        }
        return;
    }

    bool find(T x) const {
        auto itr =
            std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));
        if (x < itr->second) {
            assert(itr->first <= x);
            return true;
        } else {
            return false;
        }
    }

    bool find(T l, T r) const {
        auto itr =
            std::prev(set.upper_bound({l, std::numeric_limits<T>::max()}));
        if (r <= itr->second) {
            assert(itr->first <= l);
            return true;
        } else {
            return false;
        }
    }

    std::pair<T, T> belong(T x) const {
        auto itr =
            std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));
        if (x <= itr->second) {
            assert(itr->first <= x);
            return *itr;
        } else {
            return {0, 0};
        }
    }

    std::pair<T, T> lower_bound(T l) const {
        return *set.lower_bound({l, std::numeric_limits<T>::min()});
    }
};

}  // namespace ebi