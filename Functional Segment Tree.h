class FunctionalSegmentTree
{
    struct Node { unsigned lp, rp; int sum; };

public:
    FunctionalSegmentTree(unsigned size) : n(size), rt(1), tn(1)
    {
        // save a little memory usage and allocating time
        // POJ 2104  38384 K -> 22552 K
        //           2110 MS -> 1766 MS
        // rt.reserve(size); tn.reserve(size << 5);
    }

    void update(unsigned ft, unsigned tt, unsigned p)
    {
        if (tt >= rt.size()) {
            rt.resize(tt + 1);      // be aware of reallocation
        }
        rt[tt] = spawn(rt[ft], p, 1, n);
    }

    int query(unsigned t)
    { return tn[rt[t]].sum; }

    int query(unsigned l, unsigned r)
    { return query(r) - query(l - 1); }

    // range kth element if you
    // update(i - 1, i, a[i]) for i in 1..n sequentially
    unsigned kth_element(unsigned x, unsigned y, int k)
    { return kth_element(rt[x - 1], rt[y], k, 1, n); }

private:
    unsigned spawn(unsigned sp, unsigned k, unsigned l, unsigned r)
    {
        unsigned tp = tn.size();    // memory distrubute
        tn.push_back(tn[sp]);       // new root
        ++tn[tp].sum;               // modify
        if (l != r) {               // recurse child node
            unsigned m = l + ((r - l) >> 1);
            if (m >= k) {
                unsigned lp = spawn(tn[sp].lp, k, l, m);
                tn[tp].lp = lp;     // reallocate happens
            } else {
                unsigned rp = spawn(tn[sp].rp, k, ++m, r);
                tn[tp].rp = rp;     // reallocate happens
            }
        }
        return tp;
    }

    unsigned kth_element(unsigned x, unsigned y, int k, unsigned l, unsigned r)
    {
        if (l == r) {
            return l;
        }
        unsigned m = l + ((r - l) >> 1);
        int s = tn[tn[y].lp].sum - tn[tn[x].lp].sum;
        if (s >= k) {
            return kth_element(tn[x].lp, tn[y].lp, k, l, m);
        } else {
            return kth_element(tn[x].rp, tn[y].rp, k - s, ++m, r);
        }
    }

protected:
    unsigned n;
    vector<unsigned> rt;
    vector<Node> tn;
};
