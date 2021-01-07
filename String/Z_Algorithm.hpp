#pragma once

#include <string>
#include <vector>

/*
    reference: https://snuke.hatenablog.com/entry/2014/12/03/214243
*/

std::vector<int> Z_Algorithm(const std::string &s) {
    int n = s.size();
    std::vector<int> prefix(n);
    prefix[0] = n;
    int i = 1;
    int j = 0; // s[0,j], s[i,i+j] がすでに一致していることが保証されている.
    while(i<n) {
        while(i+j<n && s[j]==s[i+j]) ++j;
        prefix[i] = j;
        if(j == 0){
            ++i;
            continue;
        }
        int k = 1;
        while(i+k<n && k+prefix[k]<j) {
            prefix[i+k] = prefix[k];
            ++k;
        }
        i += k;
        j -= k;
    }
    return prefix;
}