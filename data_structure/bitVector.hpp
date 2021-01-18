#pragma once

#include "../utility/int_alias.hpp"

/*
    reference: https://misteer.hatenablog.com/entry/bit-vector
*/

#include <vector>

namespace ebi {

struct bitVector {
    u32 length, cn, bn;
    static u32 cw, bw; // chunk, block の長さ cw = (lg N)^2, bw = (lg N)/2 とする.
    std::vector<u16> bit;
    std::vector<u32> chunk;
    std::vector<std::vector<u16>> blocks;

    bitVector(int n) : length(n) {
        cn = (length+cw-1)/cw;
        bn = cw/bw;
        bit.assign(cn*bn, 0);
        chunk.assign(cn+1,0);
        blocks.assign(cn, std::vector<u16>(bn, 0));
    }

    void set(int k, int b) {
        u32 i = k/bw;
        u32 j = k%bw;
        if(b == 0) {
            bit[i] &= ~(1<<j);
        }
        else if(b == 1) {
            bit[i] |= (1<<j);
        }
    }

    int access(int k) {
        u32 i = k/bw;
        u32 j = k%bw;
        return bit[i] >> j & 1;
    }

    void build() {
        chunk[0] = 0;
        for(u32 i = 0; i<cn; i++) {
            blocks[i][0] = 0;
            for(u32 j = 0; j<bn-1; j++) {
                blocks[i][j+1] = blocks[i][j] + __builtin_popcount(bit[i*bn + j]);
            }
            chunk[i+1] = chunk[i] + blocks[i][bn-1] + __builtin_popcount(bit[(i+1)*bn -1]);
        }
    }

    // [0, r)に存在する1の数をO(1)で計算する.
    int rank(int r) {
        u32 i = r/cw;
        u32 j = (r%cw)/bw;
        u32 k = r%bw;
        u32 leftover = bit[i*bn + j] & ((1<<k) - 1);
        if(i == cn) return chunk[i];
        return chunk[i] + blocks[i][j] + __builtin_popcount(leftover);
    }

    int select(int k) {
        if(k == 0) return 0;
        if(rank(length) < k) return -1;
        u32 l = 0;
        u32 r = length;
        while(r-l>1) {
            u32 mid = (r+l)/2;
            if(rank(mid) >= k) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }

    int select0(int k) {
        if(k==0) return 0;
        if(length-rank(length)< (u32)k) return -1;
        u32 l = 0;
        u32 r = length;
        while(r-l>1) {
            u32 mid = (r+l)/2;
            if(mid-rank(mid) >= (u32)k) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};

u32 bitVector::cw = 1024;
u32 bitVector::bw = 16;

} // namespace ebi