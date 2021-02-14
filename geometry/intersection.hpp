#pragma once

#include "../geometry/isp.hpp"
#include "../geometry/template.hpp"

namespace ebi {

bool intersection(const point &a, const point &b, const point &c, const point &d) {
    if(isp(a,b,c)*isp(a,b,d) <= 0 && isp(c,d,a)*isp(c,d,b) <= 0) {
        return true;
    }
    return false;
}

}