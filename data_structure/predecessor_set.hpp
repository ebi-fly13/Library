#pragma once

#include <set>

namespace ebi {

struct predecessor_set {
  public:
    predecessor_set() = default;

    void insert(int k) {
        set.insert(k);
    }

    void erase(int k) {
        set.erase(k);
    }

    bool find(int k) const {
        return set.find(k) != set.end();
    }

    int find_next(int k) const {
        auto itr = set.lower_bound(k);
        return itr == set.end() ? -1 : *itr;
    }

    int find_prev(int k) const {
        auto itr = set.upper_bound(k);
        return itr == set.begin() ? -1 : *(--itr);
    }

  private:
    std::set<int> set;
};

}  // namespace ebi