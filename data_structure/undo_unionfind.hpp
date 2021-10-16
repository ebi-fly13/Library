#pragma once

#include <vector>
#include <stack>
#include <cassert>

namespace ebi {

struct undo_unionfind {
private:
    std::stack< std::pair<int,int> > stack;
public:
    std::vector<int> par;

    undo_unionfind(int n = 0) : par(n, -1) { }

    bool same(int x,int y){
        return leader(x)==leader(y);
    }

    bool merge(int x, int y){
        x = leader(x); y = leader(y);
        stack.push({x, par[x]});
        stack.push({y, par[y]});
        if(x==y) return false;
        if(par[x]>par[y]) std::swap(x,y);
        par[x]+=par[y];
        par[y] = x;
        return true;
    }

    int leader(int x){
        if(par[x]<0) return x;
        else return leader(par[x]);
    }

    int size(int x){
        return -par[leader(x)];
    }

    int count_group(){
        int c = 0;
        for(int i = 0; i<int(par.size()); i++){
            if(par[i]<0) c++; 
        }
        return c;
    }

    void undo() {
        assert(!stack.empty());
        par[stack.top().first] = stack.top().second;
        stack.pop();
        par[stack.top().first] = stack.top().second;
        stack.pop();
        return;
    }
};

}