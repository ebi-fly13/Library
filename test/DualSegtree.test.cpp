#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../data_structure/DualSegtree.hpp"

#include <iostream>
#include <vector>

int op(int a, int b) {
    return a+b;
}

int e(){
    return 0;
}

int main() {
    int n,q; std::cin >> n >> q;
    ebi::DualSegtree<int, op, e> dseg(n);
    while(q--){
        int flag;
        std::cin >> flag;
        if(flag==0){
            int s,t,x; std::cin >> s >> t >> x;
            s--;
            dseg.apply(s,t,x);
        }
        else{
            int t; std::cin >> t;
            t--;
            std::cout << dseg.get(t) << std::endl;
        }
    }
}