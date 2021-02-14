#pragma once

#include "../geometry/template.hpp"

namespace ebi {

int isp(const point &a, const point &b, const point &c) {
    int flag = internal::sgn(det(b-a,c-a));
    if(flag == 0) {
        if(internal::sgn(dot(b-a, c-a))<0) return -2;
        if(internal::sgn(dot(a-b, c-b))<0) return +2;
    }
    return flag;
}

}