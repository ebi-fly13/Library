#pragma once

#include <vector>

struct UnionFind {
private:
    std::vector<int> par;

public:
    UnionFind(int n=0): par(n,-1){ }

    bool same(int x,int y){
        return leader(x)==leader(y);
    }

    bool merge(int x, int y){
        x = leader(x); y = leader(y);
        if(x==y) return false;
        if(par[x]>par[y]) std::swap(x,y);
        par[x]+=par[y];
        par[y] = x;
        return true;
    }

    int leader(int x){
        if(par[x]<0) return x;
        else return par[x] = leader(par[x]);
    }

    int size(int x){
        return -par[leader(x)];
    }

    int count_group(){
        int c = 0;
        for(int i = 0; i<par.size(); i++){
            if(par[i]<0) c++; 
        }
        return c;
    }
};