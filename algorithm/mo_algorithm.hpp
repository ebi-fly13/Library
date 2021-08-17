#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

namespace ebi {

template<class IL, class IR, class DL, class DR, class O>
void mo_algorithm(const int &n, const std::vector<int> &l, const std::vector<int> &r, const IL &insert_left, const IR &insert_right, const DL &delete_left, const DR &delete_right, const O &out) {
    const int q = l.size();
    const int block =  n/std::max<int>(1, std::sqrt(n));
    std::vector<int> order(q, 0);
    iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](int i, int j) {
        int bi = l[i]/block;
        int bj = l[j]/block;
        return bi != bj ? bi < bj : bi & 1 ? r[i] > r[j] : r[i] < r[j];
    });
    int nl = 0, nr = 0;
    for(auto i: order) {
        while(l[i] < nl) insert_left(--nl);
        while(nr < r[i]) insert_right(nr++);
        while(nl < l[i]) delete_left(nl++);
        while(r[i] < nr) delete_right(--nr);
        out(i);
    }
    return;
}

}