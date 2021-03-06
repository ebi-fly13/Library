#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../data_structure/UnionFind.hpp"

#include <iostream>

int main(){
    int n,q; std::cin >> n >> q;
    ebi::UnionFind uf(n);
    while(q--){
        int t,u,v; std::cin >> t >> u >> v;
        if(t==0){
            uf.merge(u,v);
        }
        else{
            if(uf.same(u,v)){
                std::cout << "1\n";
            }
            else{
                std::cout << "0\n";
            }
        }
    }
    return 0;
}