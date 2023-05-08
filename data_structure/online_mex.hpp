#pragma once

/*
    reference: https://twitter.com/noshi91/status/1283759174791372809

    Query
    add(int x) : amortized O(1)
    mex : amortized O(1)
*/

#include <vector>

namespace ebi {

struct online_mex {
  private:
    int mex_ = 0;
    int q = 0;
    int k = 1;
    std::vector<int> ret;
    std::vector<int> p;

    void update_mex() {
        while (ret[mex_] > 0) {
            mex_++;
        }
    }

    void increment() {
        q++;
        if (q < k) return;
        k *= 2;
        ret.assign(k, 0);
        for (const auto &val : p) {
            if (val < k) ret[val]++;
        }
    }

  public:
    online_mex() : ret(1, 0) {}

    void add(int x) {
        p.emplace_back(x);
        if (x < k) {
            ret[x]++;
        }
        increment();
    }

    int mex() {
        update_mex();
        return mex_;
    }
};

}  // namespace ebi