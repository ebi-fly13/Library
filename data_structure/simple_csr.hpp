#pragma once

#include <ranges>
#include <utility>
#include <vector>

namespace ebi {

template <class E> struct simple_csr {
    simple_csr() = default;

    simple_csr(int n, const std::vector<std::pair<int, E>>& elements)
        : start(n + 1, 0), elist(elements.size()) {
        for (auto e : elements) {
            start[e.first + 1]++;
        }
        for (auto i : std::views::iota(0, n)) {
            start[i + 1] += start[i];
        }
        auto counter = start;
        for (auto [i, e] : elements) {
            elist[counter[i]++] = e;
        }
    }

    simple_csr(const std::vector<std::vector<E>>& es)
        : start(es.size() + 1, 0) {
        int n = es.size();
        for (auto i : std::views::iota(0, n)) {
            start[i + 1] = (int)es[i].size() + start[i];
        }
        elist.resize(start.back());
        for (auto i : std::views::iota(0, n)) {
            std::copy(es[i].begin(), es[i].end(), elist.begin() + start[i]);
        }
    }

    int size() const {
        return (int)start.size() - 1;
    }

    const auto operator[](int i) const {
        return std::ranges::subrange(elist.begin() + start[i],
                                     elist.begin() + start[i + 1]);
    }
    auto operator[](int i) {
        return std::ranges::subrange(elist.begin() + start[i],
                                     elist.begin() + start[i + 1]);
    }

    const auto operator()(int i, int l, int r) const {
        return std::ranges::subrange(elist.begin() + start[i] + l,
                                     elist.begin() + start[i + 1] + r);
    }
    auto operator()(int i, int l, int r) {
        return std::ranges::subrange(elist.begin() + start[i] + l,
                                     elist.begin() + start[i + 1] + r);
    }

  private:
    std::vector<int> start;
    std::vector<E> elist;
};

}  // namespace ebi