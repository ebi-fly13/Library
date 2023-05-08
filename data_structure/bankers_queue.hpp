#pragma once

#include "../data_structure/Stream.hpp"

/*
    reference: https://37zigen.com/bankers-queue/
               http://www.kmonos.net/pub/Presen/PFDS.pdf
*/

#include <cassert>

namespace ebi {

template <class T> struct bankers_queue {
  private:
    using size_t = std::size_t;
    using Self = bankers_queue<T>;
    stream<T> f;
    size_t fsize;
    stream<T> r;
    size_t rsize;

    bankers_queue(stream<T> _f, size_t _fsize, stream<T> _r, size_t _rsize)
        : f(_f), fsize(_fsize), r(_r), rsize(_rsize) {}

    Self normalize() {
        if (fsize >= rsize)
            return *this;
        else {
            return Self(f + r.reverse(), fsize + rsize, stream<T>(), 0);
        }
    }

  public:
    bankers_queue() : f(), fsize(0), r(), rsize(0) {}

    bool empty() {
        return f.empty();
    }

    T top() {
        assert(!empty());
        return f.top();
    }

    T front() {
        return top();
    }

    Self push(T x) {
        return Self(f, fsize, r.push(x), rsize + 1).normalize();
    }

    Self pop() {
        assert(!empty());
        return Self(f.pop(), fsize - 1, r, rsize).normalize();
    }
};

}  // namespace ebi