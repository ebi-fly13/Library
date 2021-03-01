#pragma once

/*
    reference: https://noshi91.github.io/Library/other/suspension.cpp
*/

#include <variant>
#include <functional>
#include <memory>
#include <utility>

namespace ebi {

template<class T>
struct suspension : std::shared_ptr<std::variant<T, std::function<T()>>> {
    using value_type = T;
    using func_type = std::function<T()>;
    using node_type = std::variant<T, std::function<T()>>;
    using base_type = std::shared_ptr<node_type>;
private:
    static T get(node_type &x) {
        if(x.index() != 0) {
            x = std::get<1>(x)();
        }
        return std::get<0>(x);
    }
public:
    suspension(T x) : base_type(std::make_shared<node_type>(std::in_place_index<0>, x)) { }
    suspension(std::function<T()> f) : base_type(std::make_shared<node_type>(std::in_place_index<1>, f)) { }

    T force() const { return get(**this); }
};

}
