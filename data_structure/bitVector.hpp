#pragma once

/*
    reference: https://misteer.hatenablog.com/entry/bit-vector
*/

#include <vector>

using u8 = unsigned char;
using u16 = unsigned short;

struct bitVector {
    u16 length, cn, bn;
    static int cw, bw; // chunk, block の長さ cw = (lg N)^2, bw = (lg N)/2 とする.
    std::vector<u8> bit;
    std::vector<u16> chunk;
    std::vector<std::vector<u8>> blocks;

    bitVector(int n) : length(n) {
        cn = (length+cw-1)/cw;
        bn = cw/bw;
        bit.assign(cn*bn, 0);
        chunk.assign(cn+1,0);
        blocks.assign(cn, std::vector<u8>(bn, 0));
    }

    void set(int k, int b) {
        int i = k/bw;
        int j = k%bw;
        if(b == 0) {
            bit[i] &= ~(1<<j);
        }
        else if(b == 1) {
            bit[i] |= (1<<j);
        }
    }

    int access(int k) {
        int i = k/bw;
        int j = k%bw;
        return bit[i] >> j & 1;
    }

    void build() {
        chunk[0] = 0;
        for(int i = 0; i<cn; i++) {
            blocks[i][0] = 0;
            for(int j = 0; j<bn-1; j++) {
                blocks[i][j+1] = blocks[i][j] + __builtin_popcount(bit[i*bn + j]);
            }
            chunk[i+1] = chunk[i] + blocks[i][bn-1] + __builtin_popcount(bit[(i+1)*bn -1]);
        }
    }

    // [0, r)に存在する1の数をO(1)で計算する.
    int rank(int r) {
        int i = r/cw;
        int j = (r%cw)/bw;
        int k = r%bw;
        u8 leftover = bit[i*bw + j] & ((1<<k) - 1);
        if(i == cn) return chunk[i];
        return chunk[i] + blocks[i][j] + __builtin_popcount(leftover);
    }

    int select(int k) {
        if(k == 0) return 0;
        if(rank(length) < k) return -1;
        int l = 0;
        int r = length;
        while(r-l>1) {
            int mid = (r+l)/2;
            if(rank(mid) >= k) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }
};

int bitVector::cw = 256;
int bitVector::bw = 8;