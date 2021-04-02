#pragma once

#include <memory>

namespace ebi {

template<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>
struct DynamicSegmentTree {
private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;
    struct Node {
        Monoid val;
        node_ptr left, right, par;
        Node(node_ptr _par = nullptr) : val(e()), left(nullptr), right(nullptr), par(_par) { }
    };

    node_ptr root;
    int n;

public:
    DynamicSegmentTree(int _n = 0) : n(1) {
        while(n<_n) {
            n <<= 1;
        }
        root = std::make_shared<Node>();
    }

    void set(int i, Monoid x) {
        int l = 0, r = n;
        node_ptr now = root;
        while(r-l>1) {
            int mid = (l+r)/2;
            if(i<mid) {
                if(!now->left) {
                    now->left = std::make_shared<Node>(now);
                }
                now = now->left;
                r = mid;
            }
            else {
                if(!now->right) {
                    now->right = std::make_shared<Node>(now);
                }
                now = now->right;
                l = mid;
            }
        }
        now->val = x;
        while(now->par) {
            now = now->par;
            now->val = e();
            if(now->left) now->val = now->left->val;
            if(now->right) now->val = op(now->val, now->right->val);
        }
    }

    Monoid prod(int tl, int tr, int l = 0, int r = -1, node_ptr now = nullptr) {
        if(!now) now = root;
        if(r<0) r = n;
        if(tr<=l || r<=tl) {
            return e();
        }
        if(tl<=l && r<=tr) {
            return now->val;
        }
        Monoid val = e();
        if(now->left) {
            val = prod(tl, tr, l, (l+r)/2, now->left);
        }
        if(now->right) {
            val = op(val, prod(tl, tr, (l+r)/2, r, now->right));
        }
        return val;
    }

    Monoid all_prod() {
        return root->val;
    }

    Monoid get(int i) {
        int l = 0;
        int r = n;
        node_ptr now = root;
        while(r-l>1) {
            int mid = (l+r)/2;
            if(i<mid) {
                if(!now->left) return e();
                now = now->left;
                r = mid;
            }
            else{
                if(!now->right) return e();
                now = now->right;
                l = mid;
            }
        }
        return now->val;
    }
};

} // namespace ebi